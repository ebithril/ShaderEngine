#include "Engine_Precompiled.h"
#include "TextureInterface.h"

#include "Texture.h"

namespace GraphicsEngine
{
	TextureInterface::TextureInterface()
	{
		myTexture = new Texture();
	}

	TextureInterface::~TextureInterface()
	{
		delete myTexture;
	}

	GraphicsEngine::Texture* TextureInterface::GetTexture()
	{
		return myTexture;
	}

	bool TextureInterface::CreateDepthStencil(int aWidth, int aHeight, DirectXInterface& aDirectXInterface)
	{
		return myTexture->CreateDepthStencil(aWidth, aHeight, aDirectXInterface);
	}

	bool TextureInterface::CreateDepthStencil(int aWidth, int aHeight, DirectX& aDirectXEngine)
	{
		return myTexture->CreateDepthStencil(aWidth, aHeight, aDirectXEngine);
	}
}