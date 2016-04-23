#pragma once
#include "TextureInterface.h"
#include "DirectXIncludes.h"

namespace GraphicsEngine
{
	struct ViewPort;

	class WindowInterface;
	class Window;

	class DirectX
	{
	public:
		DirectX();
		~DirectX();

		bool Init(WindowInterface& aWindow);

		void SetViewPort(const ViewPort& aViewPort);
		void GetViewPort(ViewPort& aViewPort);

		bool Create2DTexture(ID3D11Texture2D*& aTexture, D3D11_TEXTURE2D_DESC& aTextureDesc);
		bool CreateDepthStencil(ID3D11Texture2D*& aTexture, ID3D11DepthStencilView* aDepthStencil, D3D11_DEPTH_STENCIL_VIEW_DESC& aDepthStencilDesc);

		void SetRenderTarget(TextureInterface* aRenderTarget, TextureInterface* aDepthStencil, int aNumberOfRenderTargets);

		bool CreateRenderTargetView(ID3D11Texture2D* myTexture, ID3D11RenderTargetView*& myRenderTargetView);

		void ClearRenderTarget(TextureInterface& aTexture);
		void ClearDepthStencil(TextureInterface& aTexture);

		void BeginScene();
		void EndScene();

	private:
		bool D3DDeviceSetup();
		void ViewPortSetup();
		bool DepthStencilSetup();
		bool SwapChainSetup();

		TextureInterface myRenderTargetView;
		TextureInterface myDepthBuffer;

		Window* myWindow;

		ID3D11Device* myDevice;
		ID3D11DeviceContext* myContext;

		IDXGISwapChain* mySwapChain;
	};
}

namespace GE = GraphicsEngine;