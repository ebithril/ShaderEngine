#pragma once

namespace GraphicsEngine
{
	class Texture;
	class DirectX;
	class DirectXInterface;

	class TextureInterface
	{
	public:
		TextureInterface();
		~TextureInterface();

		Texture* GetTexture();

		bool CreateDepthStencil(int aWidth, int aHeight, DirectXInterface& aDirectXinterface);
		bool CreateDepthStencil(int aWidth, int aHeight, DirectX& aDirectXEngine);
	private:
		Texture* myTexture;
	};
}

namespace GE = GraphicsEngine;