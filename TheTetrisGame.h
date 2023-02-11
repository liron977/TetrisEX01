#ifndef __THETETRISGAME_H_
#define __THETETRISGAME_H_
#include "Shape.h"
#include "Utils.h"
#include "Board.h"
#include "Player.h"
class TheTetrisGame {
	enum { CENTER_PLAYER_1 = 10, CENTER_PLAYER_2 = 19,ARR_SIZE=2 };
	enum { ESC = 27 };
	static constexpr int INPUT_ITERATIONS = 20;
	Shape playersShapes[ARR_SIZE] = {};
	Board theGameBoard;
	Player playersArr[ARR_SIZE] = {};
	bool isPausedGame = false;
	void getInput(bool isWithoutColor, bool& ExitGame);
	void updateMenu(bool isWithoutColor, bool& ExitGame);
	void winners(bool player1won, bool player2won, bool& ExitGame);
public:

	void init();
	void GameOver();
	void run(bool isWithoutColor, bool& ExitGame);
	void setIsPausedGame(bool _isPausedGame) {
		isPausedGame = _isPausedGame;
	}
	void setBoardGame(Board _TheBoardGame) {
		theGameBoard = _TheBoardGame;
	}
	void setPlayersShapes(Shape _playersShapes[]);
	void setPlayersArr(Player _playersArr[]);

};

#endif