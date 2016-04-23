#include <Engine.h>

#include <Windows.h>

int main()
{
	if (GE::Engine::GetInstance()->Init(1600, 900) == false)
	{
		return -1;
	}

	while (true)
	{
		MSG msg;
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			// handle or dispatch messages
			if (msg.message == WM_QUIT)
			{
				break;
			}
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			GE::Engine::GetInstance()->Render();
		}
	}

	GE::Engine::GetInstance()->Destroy();

	return 0;
}