#ifndef __SHAPE_H_
#define __SHAPE_H_
#include <iostream>
#include "Point.h"
#include "Board.h"
#include "Color.h"

class Board;

class Shape
{
	enum { SIZE = 4 };
	enum { R_CAPITAL = 2, R_LOWER = 3 };
	Point shapeMatrix[SIZE][SIZE];
	int shapeCode;
	int direction;
	Board* theGameBoard;
	Color color;
	char TAV = (char)178;
	void setShapeMatrix(int valueX, int valueY);
	Point getMostRightPoint();
	Point getMostLeftPoint();
	void printMatrix();
	void deleteMatrix();
	void setshapeCode(int _shapeCode) {
		shapeCode = _shapeCode;
	}
	Point getBottomPoint();
	Point* getBottomArrPoint();
	bool isValidMoveForShape(int keyCode);
	bool isPartOfTheShape(int x, int y);
	void rotateClockwise();
	void CounterRotateClockWise();
	bool isValidCounterRotateClockWise();
	void drop(bool isWithoutColor);
	bool  isValidRotateClockWise();
	void setColor(Color c) {
		color = c;
	}
public:

	void setBoard(Board* _theGameBoard) {
		theGameBoard = _theGameBoard;
	}
	void initShapeMatrix();
	bool UpdateShape(bool& isRowDeleted, bool isWithoutColor);
	void setDirection(int dir) {
		direction = dir;
	}
	void createShapePlayer(int x, int y, int numShape, bool& isWithoutColor);
	bool isAplayerLost(bool isReachedTheBottom);
};
#endif