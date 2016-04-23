#pragma once


namespace GraphicsEngine
{
	struct ViewPort
	{
		float myMinDepth = 0.f;
		float myMaxDepth = 1.f;
		float myTopLeftX = 0.f;
		float myTopLeftY = 0.f;

		float myWidth;
		float myHeight;
	};
}