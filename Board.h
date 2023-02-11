#ifndef __BOARD_H_
#define __BOARD_H_
#include <iostream>
#include "Utils.h"
#include "Shape.h"
class Shape;

class Board {
	enum { ROWSIZE = 20, COLSIZE = 27, MIDDLE = 13, START = 0, SHAPEARRSIZE = 4 };
	char theBoardMatrix[ROWSIZE][COLSIZE];
public:
	void matrixInit();//The board initialization
	void printBoard();
	void updateBoard(Point p1[][4]);
	void updatePointInBoard(int x, int y, char pointChar);//The function update the board matrix in the x.y coordinate with the point char
	bool isEmptyPlace(int pointX, int pointY);//The function returns true if in the matrix board where the (x,y) there is whitespace(=empty place),else false 
	bool isFullRow(int row, int col);//The function returns true if the player has a full row with part of a Tetris shape
	void deleteRow(int row, int col, bool isWithoutColor);//The function updates the matrix board according to the row with whitespaces, the function gets col in order to recognize the player
};
#endif