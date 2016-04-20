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
	private:
		HWND myWindow;
	};
}

namespace GE = GraphicsEngine;