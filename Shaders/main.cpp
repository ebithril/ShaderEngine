#include <Engine.h>

int main()
{
	if (GE::Engine::GetInstance()->Init(1600, 900) == false)
	{
		return -1;
	}

	GE::Engine::GetInstance()->Destroy();

	return 0;
}