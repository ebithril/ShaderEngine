#include "Engine_Precompiled.h"
#include "DirectX.h"

#include "WindowInterface.h"
#include "Window.h"
#include "Structs.h"
#include "Texture.h"

#include <cmath>

#pragma comment(lib, "d3d11.lib")

namespace GraphicsEngine
{
	DirectX::DirectX() :
		myWindow(nullptr),
		myDevice(nullptr),
		myContext(nullptr),
		mySwapChain(nullptr)
	{
	}

	DirectX::~DirectX()
	{
	}

	bool DirectX::Init(WindowInterface& aWindow)
	{
		myWindow = aWindow.GetWindow();

		if (D3DDeviceSetup() == false)
		{
			return false;
		}

		ViewPortSetup();

		if (DepthStencilSetup() == false)
		{
			return false;
		}

		if (SwapChainSetup() == false)
		{
			return false;
		}

		return true;
	}

	void DirectX::SetViewPort(const ViewPort& aViewPort)
	{
		D3D11_VIEWPORT viewPort;
		viewPort.Height = aViewPort.myHeight;
		viewPort.Width = aViewPort.myWidth;
		viewPort.MaxDepth = aViewPort.myMaxDepth;
		viewPort.MinDepth = aViewPort.myMinDepth;
		viewPort.TopLeftX = aViewPort.myTopLeftX;
		viewPort.TopLeftY = aViewPort.myTopLeftY;

		myContext->RSSetViewports(1, &viewPort);
	}

	void DirectX::GetViewPort(ViewPort& aViewPort)
	{
		D3D11_VIEWPORT viewPort;
		unsigned int numberOfViewPorts;
		myContext->RSGetViewports(&numberOfViewPorts, &viewPort);

		aViewPort.myHeight = viewPort.Height;
		aViewPort.myWidth = viewPort.Width;
		aViewPort.myMaxDepth = viewPort.MaxDepth;
		aViewPort.myMinDepth = viewPort.MinDepth;
		aViewPort.myTopLeftX = viewPort.TopLeftX;
		aViewPort.myTopLeftY = viewPort.TopLeftY;
	}

	bool DirectX::Create2DTexture(ID3D11Texture2D*& aTexture, D3D11_TEXTURE2D_DESC& aTextureDesc)
	{
		HRESULT result = myDevice->CreateTexture2D(&aTextureDesc, NULL, &aTexture);

		if (result != S_OK)
		{
			return false;
		}

		return true;
	}

	bool DirectX::CreateDepthStencil(ID3D11Texture2D*& aTexture, ID3D11DepthStencilView* aDepthStencil, D3D11_DEPTH_STENCIL_VIEW_DESC& aDepthStencilDesc)
	{
		HRESULT result = myDevice->CreateDepthStencilView(aTexture, &aDepthStencilDesc, &aDepthStencil);

		if (result != S_OK)
		{
			return false;
		}

		return true;
	}

	void DirectX::SetRenderTarget(TextureInterface* aRenderTarget, TextureInterface* aDepthStencil, int aNumberOfRenderTargets)
	{
		ID3D11RenderTargetView* renderTarget = aRenderTarget->GetTexture()->GetRenderTargetView();

		myContext->OMSetRenderTargets(unsigned int(aNumberOfRenderTargets), &renderTarget, aDepthStencil->GetTexture()->GetDepthStencil());
	}

	bool DirectX::CreateRenderTargetView(ID3D11Texture2D* myTexture, ID3D11RenderTargetView*& myRenderTargetView)
	{
		HRESULT result = myDevice->CreateRenderTargetView(myTexture, NULL, &myRenderTargetView);

		if (result != S_OK)
		{
			return false;
		}

		return true;
	}

	void DirectX::ClearRenderTarget(TextureInterface& aTexture)
	{
		static int number = 0;
		number++;
		float color[4] = { sin(number / 1010), sin(number / 1000), sin(number / 1100), 1.0f };
		myContext->ClearRenderTargetView(aTexture.GetTexture()->GetRenderTargetView(), color);
	}

	void DirectX::ClearDepthStencil(TextureInterface& aTexture)
	{
		myContext->ClearDepthStencilView(aTexture.GetTexture()->GetDepthStencil(), D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0.0f);
	}

	void DirectX::BeginScene()
	{
		ClearRenderTarget(myRenderTargetView);
		ClearDepthStencil(myDepthBuffer);
	}

	void DirectX::EndScene()
	{
		mySwapChain->Present(0, 0);
	}

	bool DirectX::D3DDeviceSetup()
	{
		DXGI_SWAP_CHAIN_DESC swapChainDesc;

		ZeroMemory(&swapChainDesc, sizeof(swapChainDesc));

		swapChainDesc.BufferCount = 1;
		swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		swapChainDesc.OutputWindow = myWindow->GetWindowHandle();
		swapChainDesc.SampleDesc.Count = 4;
		swapChainDesc.Windowed = TRUE;

		HRESULT result = D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, NULL, NULL, NULL, D3D11_SDK_VERSION, &swapChainDesc, &mySwapChain, &myDevice, NULL, &myContext);

		if (result != S_OK)
		{
			return false;
		}

		return true;
	}

	void DirectX::ViewPortSetup()
{
		ViewPort viewPort;

		viewPort.myHeight = float(myWindow->GetHeight());
		viewPort.myWidth = float(myWindow->GetWidth());

		SetViewPort(viewPort);
	}

	bool DirectX::DepthStencilSetup()
	{
		if (myDepthBuffer.CreateDepthStencil(myWindow->GetWidth() ,myWindow->GetHeight(), *this) == false)
		{
			return false;
		}

		return true;
	}

	bool DirectX::SwapChainSetup()
	{
		ID3D11Texture2D* backBuffer;

		HRESULT result = mySwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&backBuffer);

		if (result != S_OK)
		{
			return false;
		}

		if (myRenderTargetView.GetTexture()->CreateBackBuffer(backBuffer, *this) == false)
		{
			return false;
		}

		SetRenderTarget(&myRenderTargetView, &myDepthBuffer, 1);

		return true;
	}
}