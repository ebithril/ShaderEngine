#pragma once

#include "WindowInterface.h"

namespace GraphicsEngine
{
	class Engine
	{
	public:
		static Engine* GetInstance();

		bool Init(int aWidth, int aHeigth);
		void Destroy();

	private:
		Engine();
		~Engine();

		static Engine* ourInstance;
		
		WindowInterface myWindow;
	};
}

namespace GE = GraphicsEngine;