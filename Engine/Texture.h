#pragma once

#include "DirectXIncludes.h"

namespace GraphicsEngine
{
	class DirectXInterface;
	class DirectX;

	class Texture
	{
	public:
		Texture();
		~Texture();

		bool CreateDepthStencil(int aWidth, int aHeight, DirectXInterface& aDirectInterface);
		bool CreateDepthStencil(int aWidth, int aHeight, DirectX& aDirectInterface);

		bool CreateBackBuffer(ID3D11Texture2D* aTexture, DirectX& aDirectXEngine);
		ID3D11RenderTargetView* GetRenderTargetView();
		ID3D11DepthStencilView* GetDepthStencil();

	private:
		int myWidth;
		int myHeight;

		ID3D11Texture2D* myTexture;
		ID3D11RenderTargetView* myRenderTargetView;
		ID3D11DepthStencilView* myDepthStencilView;
		ID3D11ShaderResourceView* myShaderResourceView;
	};
}