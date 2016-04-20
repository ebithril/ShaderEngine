#include "Engine_Precompiled.h"
#include "DirectX.h"

#include "WindowInterface.h"
#include "Window.h"

namespace GraphicsEngine
{
	DirectX::DirectX()
	{
		myWindow = nullptr;

		myDevice = nullptr;
		myContext = nullptr;
		mySwapChain = nullptr;
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

		return true;
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

}