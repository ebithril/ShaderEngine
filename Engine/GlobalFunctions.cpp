#include "Engine_Precompiled.h"
#include "GlobalFunctions.h"

namespace GraphicsEngine
{
	LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

}