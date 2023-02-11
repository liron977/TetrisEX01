#include "Board.h"
#include "Shape.h"

void Board::updateBoard(Point p1[][4]) {
	int y = 0, x = 0;
	for (int i = 0; i < SHAPEARRSIZE; i++) {
		for (int j = 0; j < SHAPEARRSIZE; j++) {
			x = p1[i][j].getx();
			y = p1[i][j].gety();
			if (x != 0) {
				theBoardMatrix[y][x] = p1[i][j].getPointChar();
			}
		}
	}
}
void Board::updatePointInBoard(int y, int x, char pointChar) {
	theBoardMatrix[x][y] = pointChar;
}
void Board::matrixInit() {
	for (int i = 0; i < ROWSIZE; i++)
	{
		for (int j = 0; j < COLSIZE; j++)
		{
			if (j == START || j == MIDDLE || j == COLSIZE - 1)
				theBoardMatrix[i][j] = '|';
			else if (i == ROWSIZE - 1)
			{
				(theBoardMatrix[i][j]) = '*';
			}
			else
			{
				(theBoardMatrix[i][j]) = ' ';
			}
		}
	}
}
void Board::printBoard() {
	for (int i = 0; i < ROWSIZE; i++)
	{
		for (int j = 0; j < COLSIZE; j++)
		{

			cout << theBoardMatrix[i][j];
		}
		cout << endl;
	}
}
bool Board::isEmptyPlace(int pointX, int pointY) {
	if (theBoardMatrix[pointY][pointX] == ' ')
		return true;
	return false;
}
bool Board::isFullRow(int row, int col) {
	if ((0 <= col) && (col <= 13))//Player 1
	{
		for (int i = 0; i < COLSIZE / 2; i++)
		{
			if (theBoardMatrix[row][i] == ' ')
				return false;
		}
		return true;
	}


	else//Player 2
	{
		for (int i = COLSIZE / 2; i < COLSIZE; i++)
		{
			if (theBoardMatrix[row][i] == ' ')
				return false;
		}
		return true;
	}

}
void Board::deleteRow(int row, int col, bool isWithoutColor) {
	for (int i = row; i - 1 > 1; i--)
	{
		if (!isWithoutColor) {
			setTextColor(RED);
		}
		if ((0 <= col) && (col <= 13))//Player 1
		{

			for (int j = 1; j < COLSIZE / 2; j++)
			{
				gotoxy(j, i);
				cout << theBoardMatrix[i][j];
			}
			Sleep(10);
			setTextColor(WHITE);
			for (int j = 1; j < COLSIZE / 2; j++)
			{

				updatePointInBoard(j, i, theBoardMatrix[i - 1][j]);
				gotoxy(j, i);
				cout << theBoardMatrix[i - 1][j];

			}
		}
		else//Player 2
		{
			for (int j = (COLSIZE / 2) + 1; j < COLSIZE - 1; j++)
			{
				gotoxy(j, i);
				cout << theBoardMatrix[i][j];
			}
			Sleep(10);
			setTextColor(WHITE);
			for (int j = (COLSIZE / 2) + 1; j < COLSIZE - 1; j++)
			{
				updatePointInBoard(j, i, theBoardMatrix[i - 1][j]);
				gotoxy(j, i);
				cout << theBoardMatrix[i - 1][j];
			}

		}
	}
}