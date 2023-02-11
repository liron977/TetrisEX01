#ifndef __PLAYER1_H_
#define __PLAYER1_H_
#include <iostream>
#include "Utils.h"
class Player
{
	enum { ARROW_KEYS_SIZE = 10, NAME_SIZE = 9, PLAYER_1_KOD = 1 };
	int playerCode;
	char playerName[NAME_SIZE];
	char arrowKeys[ARROW_KEYS_SIZE];
	int playerScore;

public:
	void setArrowKeys(const char* keys);
	int getDirection(char key);//The function gets the select diraction char and return the key code from the arrowKeys, if the key didn`t find return -1
	void setPlayerCode(int _code);
	void setPlayerScore(int _score);
	int getPlayerScore();
	void setPlayerName();
	void printPlayerName();
	void printPlayerScore();
	void printWinner();
	void printTie();

};

#endif