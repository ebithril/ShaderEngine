#pragma once

namespace GraphicsEngine
{
	class DirectX;

	class DirectXInterface
	{
	public:
		DirectXInterface();
		~DirectXInterface();

	private:
		DirectX* myDirectXEngine;
	};
}

namespace GE = GraphicsEngine;