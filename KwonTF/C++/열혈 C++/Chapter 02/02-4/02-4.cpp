// 02-4.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
typedef struct __Point {
	int xpos;
	int ypos;
}Point;
Point& PntAdder(const Point &p1, const Point &p2);
int main()
{
	Point *point1 = new Point;
	point1->xpos = 10;
	point1->ypos = 20;
	Point *point2 = new Point;
	point2->xpos = 100;
	point2->ypos = 200;
	Point &AddedPoint = PntAdder(*point1, *point2);
	delete point1;
	delete point2;
	cout << "Xpos : " << AddedPoint.xpos << endl;
	cout << "Ypos : " << AddedPoint.ypos << endl;
	delete &AddedPoint;
    return 0;
}

Point& PntAdder(const Point &p1, const Point &p2)
{
	Point *tempPnt = new Point;
	tempPnt->xpos = p1.xpos + p2.xpos;
	tempPnt->ypos = p1.ypos + p2.ypos;
	return *tempPnt;
}
