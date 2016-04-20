#pragma once

namespace GraphicsEngine
{
	class Window;

	class WindowInterface
	{
	public:
		WindowInterface();
		~WindowInterface();

		bool Create(int aWidth, int aHeigth);

	private:
		Window* myWindow;
	};
}

namespace GE = GraphicsEngine;