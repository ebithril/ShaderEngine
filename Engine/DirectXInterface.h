#pragma once

namespace GraphicsEngine
{
	class DirectX;
	class WindowInterface;

	class DirectXInterface
	{
	public:
		DirectXInterface();
		~DirectXInterface();

		DirectX& GetDirectX();

		bool Init(WindowInterface& aWindowInterface);
		void BeginScene();
		void EndScene();



	private:
		DirectX* myDirectXEngine;
	};
}

namespace GE = GraphicsEngine;