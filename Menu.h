#ifndef __MENU_H_
#define __MENU_H_
#include <iostream>
#include "Shape.h"
#include "TheTetrisGame.h"
class Menu {
	enum { SIZE = 2 };
	enum { NEWGAME = '1', PAUSEDGAME = '2', INSTRUCTIONS = '8', EXIT = '9', WITHOUT_COLOR = '4' };
	bool isPausedGame = false;
	char playerChoice = '0';
	Board TheBoardGame;
	TheTetrisGame newGame;
	Shape playersShapes[SIZE] = {};
	Player playersArr[SIZE] = {};
	bool isWithoutColor = false;
	bool ExitGame = false;
	void setPlayerChoise(int _playerChoice) {
		playerChoice = _playerChoice;
	}
	void getPlayerChoise();
	void selectedAction(char playerChoice, bool& ExitGame);//The function gets the number of the action that the player selected from the menu 
	void printInstructions(bool& ExitGame);

	bool getIsWithoutColor() {
		return isWithoutColor;
	}

public:

	void setIsPausedGameFromGame(bool _isPausedGame) {
		isPausedGame = _isPausedGame;
	}
	void setBoardGameForMenu(Board _TheBoardGame) {
		TheBoardGame = _TheBoardGame;
	}
	void setPlayersShapes(Shape _playersShapes[]);
	void setPlayersArr(Player _playersArr[]);
	void printMenu(bool& ExitGame);
	void setIsWithoutColor(bool _isWithoutColor)
	{
		isWithoutColor = _isWithoutColor;
	}



};
#endif