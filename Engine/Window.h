#pragma once

#include "WindowsInclude.h"

namespace GraphicsEngine
{
	class Window
	{
	public:
		Window();
		~Window();

		bool Create(int aWidth, int aHeigth);
		HWND& GetWindowHandle();

		int GetWidth() const;
		int GetHeight() const;
	private:
		HWND myWindow;

		int myWidth;
		int myHeight;
	};
}

namespace GE = GraphicsEngine;