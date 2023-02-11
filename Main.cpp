#include <windows.h>
#include <iostream>
#include "TheTetrisGame.h"
#include "Menu.h"

int main()
{
	bool ExitGame = false;
	TheTetrisGame G;
	Menu m;
	removeCursor();
	m.printMenu(ExitGame);
	G.GameOver();
}