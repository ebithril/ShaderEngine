#include "Engine_Precompiled.h"
#include "Engine.h"

namespace GraphicsEngine
{
	Engine* Engine::ourInstance = nullptr;

	Engine* Engine::GetInstance()
	{
		if (ourInstance == nullptr)
		{
			ourInstance = new Engine();
		}

		return ourInstance;
	}

	bool Engine::Init(int aWidth, int aHeigth)
	{
		if (myWindow.Create(aWidth, aHeigth) == false)
		{
			return false;
		}

		return true;
	}

	void Engine::Destroy()
	{
		delete ourInstance;
		ourInstance = nullptr;
	}

	Engine::Engine()
	{
	}

	Engine::~Engine()
	{
	}
}