#pragma once

namespace GraphicsEngine
{
	class Texture;

	class TextureInterface
	{
	public:
		TextureInterface();
		~TextureInterface();

	private:
		Texture* myTexture;
	};
}

namespace GE = GraphicsEngine;