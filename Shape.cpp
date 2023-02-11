#include "Shape.h"
#include "Point.h"
#include "Board.h"


void Shape::initShapeMatrix()
{
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			shapeMatrix[i][j].setPoint(i, j, ' ');

		}
	}
}

void Shape::printMatrix()
{

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (shapeMatrix[i][j].getPointChar() == TAV)
			{
				setTextColor(color);
				shapeMatrix[i][j].draw(TAV);

			}
		}
	}
	setTextColor(WHITE);
	theGameBoard->updateBoard(shapeMatrix);
}

void Shape::deleteMatrix()
{

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (shapeMatrix[i][j].getPointChar() == TAV)
			{
				shapeMatrix[i][j].draw(' ');
				theGameBoard->updatePointInBoard(shapeMatrix[i][j].getx(), shapeMatrix[i][j].gety(), ' ');

			}
		}
	}
}

Point Shape::getMostRightPoint()
{
	for (int i = 3; i >= 0; i--)
	{
		for (int j = 0; j < 4; j++)
		{
			if (shapeMatrix[i][j].getPointChar() == TAV)
			{
				return shapeMatrix[i][j];
			}
		}
	}
	return shapeMatrix[0][0];
}

Point Shape::getMostLeftPoint()
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++) {
			if (shapeMatrix[i][j].getPointChar() == TAV)
			{
				return shapeMatrix[i][j];
			}
		}
	}
	return shapeMatrix[0][0];
}

Point Shape::getBottomPoint()
{
	Point CurrBottomPoint = shapeMatrix[1][0];
	int lastJ = 0;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if ((shapeMatrix[i][j].getPointChar() == TAV) && j >= lastJ)
			{
				CurrBottomPoint = shapeMatrix[i][j];
			}
		}
	}
	return CurrBottomPoint;
}

Point* Shape::getBottomArrPoint()
{
	static Point CurrBottomPoint[4];
	int k = 0;
	int lastJ = 0;
	bool isFullRowInBoard = false;
	CurrBottomPoint[0] = {};
	CurrBottomPoint[1] = {};
	CurrBottomPoint[2] = {};
	CurrBottomPoint[3] = {};
	for (int i = 3; i >= 0; i--)
	{
		for (int j = 3; j >= 0; j--)
		{
			if ((shapeMatrix[i][j].getPointChar() == TAV))
			{
				CurrBottomPoint[k] = shapeMatrix[i][j];
				j = -1;
				k++;
				if (k == 4) {
					break;
				}

			}

		}
	}
	return CurrBottomPoint;
}

bool Shape::UpdateShape(bool& isRowDeleted, bool isWithoutColor)
{
	bool isReachedTheBottom = false;

	if (isValidMoveForShape(-1)) {
		deleteMatrix();
		setShapeMatrix(0, 1);
		theGameBoard->updateBoard(shapeMatrix);
	}
	else {


		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				if (shapeMatrix[i][j].getPointChar() == TAV) {
					if (theGameBoard->isFullRow(shapeMatrix[i][j].gety(), shapeMatrix[i][j].getx()))
					{

						theGameBoard->deleteRow(shapeMatrix[i][j].gety(), shapeMatrix[i][j].getx(), isWithoutColor);
						isRowDeleted = true;
					}
				}
			}
		}
		isReachedTheBottom = true;
		return isReachedTheBottom;


	}
	if ((direction == 0 || direction == 1) && isValidMoveForShape(direction)) // LEFT
	{
		deleteMatrix();
		setShapeMatrix(-1, 0);
		printMatrix();
	}

	else if ((direction == R_CAPITAL || direction == R_LOWER) && isValidMoveForShape(direction)) // Right
	{
		deleteMatrix();
		setShapeMatrix(1, 0);
		printMatrix();

	}
	else if ((direction == 4 || direction == 5) && shapeCode != 5 && isValidRotateClockWise()) {
		deleteMatrix();
		rotateClockwise();
	}
	else if ((direction == 6 || direction == 7) && (shapeCode != 5) && (isValidCounterRotateClockWise())) {

		deleteMatrix();
		CounterRotateClockWise();

	}

	if (((direction == 8 || direction == 9)) && (isValidMoveForShape(-1)))
	{
		drop(isWithoutColor);
	}



	if (!isRowDeleted)
	{
		printMatrix();
		theGameBoard->updateBoard(shapeMatrix);
	}
	return isReachedTheBottom;

}

void Shape::createShapePlayer(int x, int y, int numShape, bool& isWithoutColor)

{
	if (isWithoutColor)
	{
		setColor(WHITE);
	}
	else
	{
		Color randColor = static_cast<Color>((rand() % YELLOW) + 1);
		setColor(randColor);
	}
	initShapeMatrix();
	int z = 18;
	if (x == 1)
		z = 5;//The center of the first player board.
	else {
		z = 18;//The center of the second player board.
	}
	switch (numShape)
	{
	case (1):
		shapeMatrix[2][0].setPoint(z + 3, 0, TAV);
		shapeMatrix[2][1].setPoint(z + 3, 1, TAV);
		shapeMatrix[1][1].setPoint(z + 2, 1, TAV);
		shapeMatrix[0][1].setPoint(z + 1, 1, TAV);
		setshapeCode(1);
		break;
	case (2):
		shapeMatrix[0][0].setPoint(z, 0, TAV);
		shapeMatrix[1][0].setPoint(z + 1, 0, TAV);
		shapeMatrix[2][0].setPoint(z + 2, 0, TAV);
		shapeMatrix[3][0].setPoint(z + 3, 0, TAV);
		setshapeCode(2);
		break;
	case (3):
		shapeMatrix[0][0].setPoint(z, 0, TAV);
		shapeMatrix[0][1].setPoint(z, 1, TAV);
		shapeMatrix[1][1].setPoint(z + 1, 1, TAV);
		shapeMatrix[2][1].setPoint(z + 2, 1, TAV);
		setshapeCode(3);
		break;

	case (4):
		shapeMatrix[1][0].setPoint(z + 1, 0, TAV);
		shapeMatrix[2][0].setPoint(z + 2, 0, TAV);
		shapeMatrix[2][1].setPoint(z + 2, 1, TAV);
		shapeMatrix[3][1].setPoint(z + 3, 1, TAV);
		setshapeCode(4);
		break;

	case (5):

		shapeMatrix[0][1].setPoint(z + 1, 1, TAV);
		shapeMatrix[0][2].setPoint(z + 1, 2, TAV);
		shapeMatrix[1][1].setPoint(z + 2, 1, TAV);
		shapeMatrix[1][2].setPoint(z + 2, 2, TAV);
		setshapeCode(5);
		break;

	case (6):

		shapeMatrix[2][0].setPoint(z + 2, 0, TAV);
		shapeMatrix[1][1].setPoint(z + 1, 1, TAV);
		shapeMatrix[2][1].setPoint(z + 2, 1, TAV);
		shapeMatrix[3][1].setPoint(z + 3, 1, TAV);
		setshapeCode(6);
		break;

	case (7):

		shapeMatrix[2][0].setPoint(z + 2, 0, TAV);
		shapeMatrix[3][0].setPoint(z + 3, 0, TAV);
		shapeMatrix[1][1].setPoint(z + 1, 1, TAV);
		shapeMatrix[2][1].setPoint(z + 2, 1, TAV);
		setshapeCode(7);
		break;
	}

}

bool Shape::isValidMoveForShape(int keyCode)
{
	bool isvalidMove = true;
	if ((keyCode == 0) || (keyCode == 1))//LEFT
	{
		Point Lpoint = getMostLeftPoint();
		if (theGameBoard->isEmptyPlace(Lpoint.getx() - 1, Lpoint.gety()))
		{
			return true;

		}
		else
		{
			return false;
		}

	}
	if ((keyCode == 2) || (keyCode == 3)) //RIGHT
	{
		Point Rpoint = getMostRightPoint();
		for (int i = 0; i < SIZE; i++) {
			if (theGameBoard->isEmptyPlace(Rpoint.getx() + 1, Rpoint.gety()))
			{
				return true;
			}
			else {
				return false;
			}
		}
	}
	if ((keyCode == -1))//Defult move(down).
	{
		Point* BpointArr = getBottomArrPoint();
		for (int i = 0; i < SIZE; i++)
		{

			if ((!(theGameBoard->isEmptyPlace(BpointArr[i].getx(), BpointArr[i].gety() + 1))) && (BpointArr[i].getx() != 0)) {
				isvalidMove = false;
				return isvalidMove;
			}
		}

	}
	return isvalidMove;
}

void Shape::rotateClockwise()
{
	for (int x = 0; x < 2; x++) {
		// Consider elements in group
		// of 4 in current square
		for (int y = x; y < 3 - x; y++) {
			// Store current cell in
			// temp variable
			Point temp;
			temp = shapeMatrix[x][y];

			// Move values from right to top
			shapeMatrix[x][y].setPoint(x - y + shapeMatrix[y][3 - x].getx(), y - (3 - x) + shapeMatrix[y][3 - x].gety(), shapeMatrix[y][3 - x].getPointChar());

			// Move values from bottom to right
			shapeMatrix[y][3 - x].setPoint(y - (3 - x) + shapeMatrix[3 - x][3 - y].getx(), 3 - x - (3 - y) + shapeMatrix[3 - x][3 - y].gety(), shapeMatrix[3 - x][3 - y].getPointChar());

			// Move values from left to bottom
			shapeMatrix[3 - x][3 - y].setPoint((3 - x) - (3 - y) + shapeMatrix[3 - y][x].getx(), 3 - y - x + shapeMatrix[3 - y][x].gety(), shapeMatrix[3 - y][x].getPointChar());

			// Assign temp to left
			shapeMatrix[3 - y][x].setPoint((3 - y) - x + temp.getx(), x - y + temp.gety(), temp.getPointChar());


		}
	}
	theGameBoard->updateBoard(shapeMatrix);
}

void Shape::CounterRotateClockWise()
{

	// Traverse each cycle
	for (int x = 0; x < 2; x++) {
		for (int y = x; y < 3 - x; y++) {

			// Swap elements of each cycle
			// in clockwise direction
			Point temp;
			temp = shapeMatrix[x][y];

			shapeMatrix[x][y].setPoint(x - (3 - y) + shapeMatrix[3 - y][x].getx(), y - x + shapeMatrix[3 - y][x].gety(), shapeMatrix[3 - y][x].getPointChar());
			shapeMatrix[3 - y][x].setPoint(3 - y - (3 - x) + shapeMatrix[3 - x][3 - y].getx(), x - (3 - y) + shapeMatrix[3 - x][3 - y].gety(), shapeMatrix[3 - x][3 - y].getPointChar());
			shapeMatrix[3 - x][3 - y].setPoint(3 - x - y + shapeMatrix[y][3 - x].getx(), 3 - y - (3 - x) + shapeMatrix[y][3 - x].gety(), shapeMatrix[y][3 - x].getPointChar());
			shapeMatrix[y][3 - x].setPoint(y - x + temp.getx(), 3 - x - y + temp.gety(), temp.getPointChar());
		}
	}
	theGameBoard->updateBoard(shapeMatrix);
}

bool  Shape::isValidRotateClockWise()
{
	for (int x = 0; x < 2; x++) {
		// Consider elements in group
		// of 4 in current square
		for (int y = x; y < 3 - x; y++) {
			Point temp;
			temp = shapeMatrix[x][y];
			if (!(theGameBoard->isEmptyPlace(x - y + shapeMatrix[y][3 - x].getx(), y - (3 - x) + shapeMatrix[y][3 - x].gety())) && !(isPartOfTheShape(x - y + shapeMatrix[y][3 - x].getx(), y - (3 - x) + shapeMatrix[y][3 - x].gety())) && shapeMatrix[y][3 - x].getPointChar() == TAV) {
				return false;
			}
			if (!(theGameBoard->isEmptyPlace(y - (3 - x) + shapeMatrix[3 - x][3 - y].getx(), 3 - x - (3 - y) + shapeMatrix[3 - x][3 - y].gety())) && !(isPartOfTheShape(y - (3 - x) + shapeMatrix[3 - x][3 - y].getx(), 3 - x - (3 - y) + shapeMatrix[3 - x][3 - y].gety())) && shapeMatrix[3 - x][3 - y].getPointChar() == TAV) {
				return false;
			}
			if (!(theGameBoard->isEmptyPlace((3 - x) - (3 - y) + shapeMatrix[3 - y][x].getx(), 3 - y - x + shapeMatrix[3 - y][x].gety())) && !(isPartOfTheShape((3 - x) - (3 - y) + shapeMatrix[3 - y][x].getx(), 3 - y - x + shapeMatrix[3 - y][x].gety())) && shapeMatrix[3 - y][x].getPointChar() == TAV) {
				return false;
			}
			if (!(theGameBoard->isEmptyPlace((3 - y) - x + temp.getx(), x - y + temp.gety())) && !(isPartOfTheShape((3 - y) - x + temp.getx(), x - y + temp.gety())) && temp.getPointChar() == TAV) {

				return false;

			}
		}
	}
	return true;

}


bool  Shape::isValidCounterRotateClockWise()
{

	for (int x = 0; x < 2; x++) {
		// Consider elements in group
		// of 4 in current square
		for (int y = x; y < 3 - x; y++) {
			Point temp;
			temp = shapeMatrix[x][y];
			if (!(theGameBoard->isEmptyPlace(x - (3 - y) + shapeMatrix[3 - y][x].getx(), y - x + shapeMatrix[3 - y][x].gety())) && !(isPartOfTheShape(x - (3 - y) + shapeMatrix[3 - y][x].getx(), y - x + shapeMatrix[3 - y][x].gety())) && shapeMatrix[3 - y][x].getPointChar() == TAV) {
				return false;
			}
			if (!(theGameBoard->isEmptyPlace(3 - y - (3 - x) + shapeMatrix[3 - x][3 - y].getx(), x - (3 - y) + shapeMatrix[3 - x][3 - y].gety())) && !(isPartOfTheShape(3 - y - (3 - x) + shapeMatrix[3 - x][3 - y].getx(), x - (3 - y) + shapeMatrix[3 - x][3 - y].gety())) && shapeMatrix[3 - x][3 - y].getPointChar() == TAV) {
				return false;
			}
			if (!(theGameBoard->isEmptyPlace(3 - x - y + shapeMatrix[y][3 - x].getx(), 3 - y - (3 - x) + shapeMatrix[y][3 - x].gety())) && !(isPartOfTheShape(3 - x - y + shapeMatrix[y][3 - x].getx(), 3 - y - (3 - x) + shapeMatrix[y][3 - x].gety())) && shapeMatrix[y][3 - x].getPointChar() == TAV) {
				return false;
			}
			if (!(theGameBoard->isEmptyPlace(y - x + temp.getx(), 3 - x - y + temp.gety())) && !(isPartOfTheShape(y - x + temp.getx(), 3 - x - y + temp.gety())) && temp.getPointChar() == TAV) {

				return false;

			}
		}
	}
	return true;

}
bool Shape::isPartOfTheShape(int x, int y) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (shapeMatrix[i][j].getx() == x && shapeMatrix[i][j].gety() == y && shapeMatrix[i][j].getPointChar() == TAV) {
				{
					return true;
				}
			}
		}
	}
	return false;
}


void Shape::drop(bool  isWithoutColor)
{
	while (getBottomPoint().gety() < 17 && isValidMoveForShape(-1))
	{
		deleteMatrix();
		setShapeMatrix(0, 1);
		printMatrix();
		theGameBoard->updateBoard(shapeMatrix);
	}
}
bool Shape::isAplayerLost(bool isReachedTheBottom)
{
	Point* BpointArr = getBottomArrPoint();
	for (int i = 0; i < SIZE; i++)
	{
		if ((BpointArr[i].gety() == 2 || BpointArr[i].gety() == 1) && isReachedTheBottom)
		{
			return true;
		}
	}
	return false;
}
void  Shape::setShapeMatrix(int valueX, int valueY) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (shapeMatrix[i][j].getPointChar() == TAV) {
				shapeMatrix[i][j].setPoint(shapeMatrix[i][j].getx() + valueX, shapeMatrix[i][j].gety() + valueY, TAV);
			}
		}
	}
}