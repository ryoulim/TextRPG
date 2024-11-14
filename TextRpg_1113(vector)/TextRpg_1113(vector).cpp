#include "pch.h"
#include "MainGame.h"
#include <ctime>

int main()
{
	srand((unsigned)time(NULL));

	MainGame mMainGame;
	mMainGame.Initialize();
	mMainGame.Update();
	return 0;
}
