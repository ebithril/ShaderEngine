#include "Engine_Precompiled.h"
#include "Texture.h"

#include "DirectXInterface.h"
#include "DirectX.h"

namespace GraphicsEngine
{
	Texture::Texture() : 
		myHeight(-1), 
		myWidth(-1), 
		myTexture(nullptr), 
		myDepthStencilView(nullptr), 
		myShaderResourceView(nullptr),
		myRenderTargetView(nullptr)
	{
	}

	Texture::~Texture()
	{
	}

	bool Texture::CreateDepthStencil(int aWidth, int aHeight, DirectX& aDirectInterface)
{
		D3D11_TEXTURE2D_DESC textureDesc;
		ZeroMemory(&textureDesc, sizeof(textureDesc));

		textureDesc.Width = aWidth;
		textureDesc.Height = aHeight;
		textureDesc.ArraySize = 1;
		textureDesc.MipLevels = 1;
		textureDesc.SampleDesc.Count = 4;
		textureDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
		textureDesc.BindFlags = D3D11_BIND_DEPTH_STENCIL;

		if (aDirectInterface.Create2DTexture(myTexture, textureDesc) == false)
		{
			return false;
		}

		D3D11_DEPTH_STENCIL_VIEW_DESC depthStencilState;
		ZeroMemory(&depthStencilState, sizeof(depthStencilState));

		depthStencilState.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
		depthStencilState.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2DMS;

		return aDirectInterface.CreateDepthStencil(myTexture, myDepthStencilView, depthStencilState);
	}

	bool Texture::CreateDepthStencil(int aWidth, int aHeight, DirectXInterface& aDirectInterface)
	{
		return CreateDepthStencil(aWidth, aHeight, aDirectInterface.GetDirectX());
	}

	bool Texture::CreateBackBuffer(ID3D11Texture2D* aTexture, DirectX& aDirectXEngine)
	{
		myTexture = aTexture;
		return aDirectXEngine.CreateRenderTargetView(myTexture, myRenderTargetView);
	}

	ID3D11RenderTargetView* Texture::GetRenderTargetView()
	{
		return myRenderTargetView;
	}

	ID3D11DepthStencilView* Texture::GetDepthStencil()
	{
		return myDepthStencilView;
	}
}