// 11-2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
using namespace std;
class Point
{
public:
	Point(int x, int y);
	friend ostream& operator<<(ostream& os, const Point& pos);
	friend ostream& operator<<(ostream& os, const Point* pos);
private:
	int xpos, ypos;
};

Point::Point(int x = 0, int y = 0) :xpos(x), ypos(y) {}


ostream & operator<<(ostream & os, const Point & pos)
{
	os << "[ " << pos.xpos << ", " << pos.ypos << " ]" << endl;
	return os;
}
ostream & operator<<(ostream & os, const Point* pos)
{
	os << "[ " << pos->xpos << ", " << pos->ypos << " ]" << endl;
	return os;
}

class BoundaryCheck2DINTArray
{
public:
	BoundaryCheck2DINTArray(int x, int y);
	Point* operator[](int idx);
	int getX() const;
	int getY() const;
private:
	Point** arr;
	int arr_x, arr_y;
};
int main() {
	BoundaryCheck2DINTArray arr(3, 4);
	for (int i = 0; i < arr.getX(); i++) {
		for (int j = 0; j < arr.getY(); j++) {
			arr[i][j] = Point(i + j, i - j);
		}
	}
	for (int i = 0; i < arr.getX(); i++) {
		for (int j = 0; j < arr.getY(); j++) {
			cout << arr[i][j] << " ";
		}
	}
	return 0;
}

BoundaryCheck2DINTArray::BoundaryCheck2DINTArray(int x, int y) :arr_x(x), arr_y(y)
{
	arr = new Point*[x];
	for (int i = 0; i < x;i++) {
		arr[i] = new Point[y];
		for (int j = 0; j < y; j++) {
			arr[i][j] = 0;
		}
	}
}

Point* BoundaryCheck2DINTArray::operator[](int idx)
{
	if (idx < 0 || idx >= arr_x) {
		cout << "Out Of Bounce" << endl;
		exit(1);
	}
	return arr[idx];
}

int BoundaryCheck2DINTArray::getX() const
{
	return arr_x;
}

int BoundaryCheck2DINTArray::getY() const
{
	return arr_y;
}
