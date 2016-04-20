#include "Engine_Precompiled.h"
#include "Window.h"

#include "GlobalFunctions.h"

namespace GraphicsEngine
{
	Window::Window()
	{
		myWindow = NULL;
	}

	Window::~Window()
	{
		if (myWindow != NULL)
		{
			DestroyWindow(myWindow);
			myWindow = NULL;
		}
	}

	bool Window::Create(int aWidth, int aHeigth)
	{
		HINSTANCE Hinstance = GetModuleHandle(NULL);

		WNDCLASSEX wcex;
		wcex.cbSize = sizeof(WNDCLASSEX);
		wcex.style = CS_HREDRAW | CS_VREDRAW;
		wcex.lpfnWndProc = WndProc;
		wcex.cbClsExtra = 0;
		wcex.cbWndExtra = 0;
		wcex.hInstance = Hinstance;
		wcex.hIcon = LoadIcon(Hinstance, (LPCTSTR)IDI_APPLICATION);
		wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
		wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
		wcex.lpszMenuName = NULL;
		wcex.lpszClassName = "Shaders Patrik & Micke";
		wcex.hIconSm = LoadIcon(wcex.hInstance, (LPCTSTR)IDI_APPLICATION);
		
		if (!RegisterClassEx(&wcex))
		{
			return false;
		}

		RECT rc = { 0, 0, aWidth, aHeigth };
		AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);

		myWindow = CreateWindow("Shaders Patrik & Micke", "Shaders Patrik & Micke", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, rc.right - rc.left, rc.bottom - rc.top, NULL, NULL, GetModuleHandle(NULL), NULL);

		ShowWindow(myWindow, 1);

		if (!myWindow)
		{
			return false;
		}

		return true;
	}
}