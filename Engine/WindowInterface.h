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
		Window* GetWindow();

	private:
		Window* myWindow;
	};
}

namespace GE = GraphicsEngine;