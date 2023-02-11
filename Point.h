#ifndef __POINT_H_
#define __POINT_H_
#include <iostream>
#include <Windows.h>
#include "Utils.h"


class Point
{
	int x;
	int y;
	char Pointchar;
public:
	void setPoint(int _x, int _y, char _ch) {
		x = _x;
		y = _y;
		Pointchar = _ch;

	}
	void setPointChar(char ch) {
		Pointchar = ch;
	}
	void draw(char ch);

	// get data members of the class
	int getx() { return x; }
	int gety() { return y; }
	char getPointChar() {
		return Pointchar;
	}
};
#endif