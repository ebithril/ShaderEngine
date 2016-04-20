#pragma once
#include "TextureInterface.h"
#include "DirectXIncludes.h"

namespace GraphicsEngine
{
	class WindowInterface;
	class Window;

	class DirectX
	{
	public:
		DirectX();
		~DirectX();

		bool Init(WindowInterface& aWindow);

	private:
		bool D3DDeviceSetup();

		TextureInterface myRenderTargetView;
		TextureInterface myDepthBuffer;

		Window* myWindow;

		ID3D11Device* myDevice;
		ID3D11DeviceContext* myContext;

		IDXGISwapChain* mySwapChain;
	};
}

namespace GE = GraphicsEngine;