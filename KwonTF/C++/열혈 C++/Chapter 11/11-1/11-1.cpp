// 11-1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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

Point::Point(int x = 0, int y = 0):xpos(x),ypos(y){}


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
typedef Point * POINT_PTR;

class BoundaryCheckPointArray
{
public:
	BoundaryCheckPointArray(int len);
	~BoundaryCheckPointArray();
	POINT_PTR& operator[](int idx);
	POINT_PTR operator[](int idx) const;
	int GetArrLen()const;
private:
	int arrlen;
	POINT_PTR * arr;
	BoundaryCheckPointArray(const BoundaryCheckPointArray& arr) {};
	BoundaryCheckPointArray& operator=(const BoundaryCheckPointArray& arr) {};
};

BoundaryCheckPointArray::BoundaryCheckPointArray(int len):arrlen(len)
{
	arr = new POINT_PTR[len];
}

BoundaryCheckPointArray::~BoundaryCheckPointArray()
{
	delete[]arr;
}

POINT_PTR & BoundaryCheckPointArray::operator[](int idx){
	if (idx < 0 || idx >= arrlen) {
		cout << "Out Of Bound" << endl;
		exit(1);
	}
	return arr[idx];
}

POINT_PTR BoundaryCheckPointArray::operator[](int idx) const
{
	if (idx < 0 || idx >= arrlen) {
		cout << "Out Of Bound" << endl;
		exit(1);
	}
	return arr[idx];
}

int BoundaryCheckPointArray::GetArrLen() const
{
	return arrlen;
}

int main() {
	BoundaryCheckPointArray arr(3);
	arr[0] = new Point(3, 4);
	arr[1] = new Point(5, 6);
	arr[2] = new Point(7, 8);
	for (int i = 0; i < arr.GetArrLen(); i++) {
		cout << arr[i];
	}
	delete arr[0];
	delete arr[1];
	delete arr[2];
	return 0;
}