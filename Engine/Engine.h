#pragma once

#include "WindowInterface.h"
#include "DirectXInterface.h"

namespace GraphicsEngine
{
	class Engine
	{
	public:
		static Engine* GetInstance();

		bool Init(int aWidth, int aHeigth);
		void Destroy();
		void Render();

	private:
		Engine();
		~Engine();

		static Engine* ourInstance;
		
		WindowInterface myWindow;
		DirectXInterface myDirectXInterface;
	};
}

namespace GE = GraphicsEngine;