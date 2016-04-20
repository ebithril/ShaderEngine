#include "Engine_Precompiled.h"
#include "WindowInterface.h"

#include "Window.h"

namespace GraphicsEngine
{
	WindowInterface::WindowInterface()
	{
		myWindow = new Window();
	}

	WindowInterface::~WindowInterface()
	{
		delete myWindow;
	}

	bool WindowInterface::Create(int aWidth, int aHeigth)
	{
		return myWindow->Create(aWidth, aHeigth);
	}

	Window* WindowInterface::GetWindow()
	{
		return myWindow;
	}
}