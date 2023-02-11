#include "TheTetrisGame.h"
#include <cstdlib> 
#include <iostream>
#include <ctime> 
#include <windows.h>
#include "Utils.h"
#include "Point.h"
#include "Shape.h"
#include "Board.h"
#include "Player.h"
#include "Menu.h"

void TheTetrisGame::init()
{

	theGameBoard.matrixInit();
	for (int i = 0; i < ARR_SIZE; i++) {
		playersArr[i].setPlayerCode(i + 1);
		playersArr[i].setPlayerName();
		playersShapes[i].initShapeMatrix();
	}
	system("cls");
	theGameBoard.printBoard();
	playersArr[0].printPlayerName();
	playersArr[1].printPlayerName();
	playersArr[0].setPlayerScore(0);
	playersArr[1].setPlayerScore(0);
	playersArr[0].setArrowKeys("AaDdsSwWxX");
	playersArr[1].setArrowKeys("JjLlkKiImM");

}



void TheTetrisGame::run(bool isWithoutColor, bool& ExitGame)
{
	int randShape;
	bool isReachedTheBottom1 = false;
	bool isReachedTheBottom2 = false;
	bool player1won = false;
	bool player2won = false;
	bool isRowDeleted = false;

	playersShapes[0].setBoard(&theGameBoard);
	playersShapes[1].setBoard(&theGameBoard);
	if (!isPausedGame) {
		randShape = (rand() % 7) + 1;
		playersShapes[0].createShapePlayer(1, 0, randShape, isWithoutColor);
		randShape = (rand() % 7) + 1;
		playersShapes[1].createShapePlayer(3, 0, randShape, isWithoutColor);
	}

	do {
		playersShapes[0].setDirection(CENTER_PLAYER_1);
		playersShapes[1].setDirection(CENTER_PLAYER_2);
		cout.flush();
		getInput(isWithoutColor, ExitGame);
		if (ExitGame) {
			break;
		}
		srand((unsigned)time(0));
		if ((isReachedTheBottom1))//if shape reached to the bottom we need to create a new shape
		{
			randShape = (rand() % 7) + 1;
			playersShapes[0].createShapePlayer(1, 0, randShape, isWithoutColor);
		}
		if ((isReachedTheBottom2)) {
			randShape = (rand() % 7) + 1;
			playersShapes[1].createShapePlayer(3, 0, randShape, isWithoutColor);
		}

		isReachedTheBottom1 = playersShapes[0].UpdateShape(isRowDeleted, isWithoutColor);
		if (isRowDeleted)
			playersArr[0].setPlayerScore(playersArr[0].getPlayerScore() + 1000);
		isRowDeleted = false;
		isReachedTheBottom2 = playersShapes[1].UpdateShape(isRowDeleted, isWithoutColor);
		if (isReachedTheBottom1) {
			playersArr[0].setPlayerScore(playersArr[0].getPlayerScore() + 50);

		}
		if (isRowDeleted)
			playersArr[1].setPlayerScore(playersArr[1].getPlayerScore() + 1000);
		if (isReachedTheBottom2) {
			playersArr[1].setPlayerScore(playersArr[1].getPlayerScore() + 50);

		}
		isRowDeleted = false;
		player1won = playersShapes[1].isAplayerLost(isReachedTheBottom2);
		player2won = playersShapes[0].isAplayerLost(isReachedTheBottom1);
		playersArr[0].printPlayerScore();
		playersArr[1].printPlayerScore();
		Sleep(300);

	} while (!player1won && !player2won);
	if (!ExitGame) {
		winners(player1won, player2won, ExitGame);
	}
	else {
		GameOver();
	}
}
void TheTetrisGame::setPlayersShapes(Shape _playersShapes[]) {
	for (int i = 0; i < 2; i++)
	{
		playersShapes[i] = _playersShapes[i];
	}
}
void TheTetrisGame::setPlayersArr(Player _playersArr[]) {
	for (int i = 0; i < 2; i++)
	{
		playersArr[i] = _playersArr[i];
	}
}
void TheTetrisGame::getInput(bool isWithoutColor, bool& ExitGame)
{
	char key = 0;
	int dir = 0;
	for (int i = 0; i < INPUT_ITERATIONS; i++) {
		if (_kbhit()) {
			key = _getch();

			if ((dir = playersArr[0].getDirection(key)) != -1) {
				playersShapes[0].setDirection(dir);
				if (dir == 8 || dir == 9)
					playersArr[0].setPlayerScore(playersArr[0].getPlayerScore() + 500);
			}
			if ((dir = playersArr[1].getDirection(key)) != -1) {
				playersShapes[1].setDirection(dir);
				if (dir == 8 || dir == 9)
					playersArr[1].setPlayerScore(playersArr[1].getPlayerScore() + 500);
			}
		}
		if (key == ESC) {
			updateMenu(isWithoutColor, ExitGame);
			break;

		}
	}
}
void TheTetrisGame::updateMenu(bool isWithoutColor, bool& ExitGame) {

	Menu m;
	m.setPlayersShapes(playersShapes);
	m.setPlayersArr(playersArr);
	m.setIsPausedGameFromGame(true);
	setIsPausedGame(true);
	m.setIsWithoutColor(isWithoutColor);
	m.setBoardGameForMenu(theGameBoard);
	m.printMenu(ExitGame);
}
void TheTetrisGame::winners(bool player1won, bool player2won, bool& ExitGame)
{
	char input=' ';
	while (!player1won && !player2won);
	Menu menu;
	menu.setIsPausedGameFromGame(false);
	setIsPausedGame(false);
	if (player1won && player2won)
	{
		if (playersArr[0].getPlayerScore() > playersArr[1].getPlayerScore())
			playersArr[0].printWinner();
		if (playersArr[0].getPlayerScore() < playersArr[1].getPlayerScore())
			playersArr[1].printWinner();
		else
		{
			playersArr[1].printTie();
		}
	}
	else if (player1won) {
		playersArr[0].printWinner();
	}
	else {
		playersArr[1].printWinner();
	}
	do {

		if (_kbhit())
		{
			input = _getch();
		}
	} while (input != ESC);
	menu.printMenu(ExitGame);
		

	

}
void TheTetrisGame::GameOver() {
	system("cls");
	gotoxy(30, 9);
	cout << "GAME OVER!!";
	gotoxy(20, 10);
	cout << "@LIRON KOTEV AND CHEN PAKMAN,2021,MTA";
	Sleep(200);
	gotoxy(0, 20);

}