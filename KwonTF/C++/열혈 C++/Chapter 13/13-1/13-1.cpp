// 13-1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
template<class T1>
void SwapData(T1& temp1, T1& temp2) {
	T1 temp = temp1;
	temp1 = temp2;
	temp2 = temp;
}
class Point
{
public:
	Point(int x, int y);
	void ShowPosition();
private:
	int xpos, ypos;
};

Point::Point(int x, int y)
{
	xpos = x;
	ypos = y;
}
void Point::ShowPosition()
{
	cout << "[ " << xpos << ", " << ypos << " ]" << endl;
}
int main()
{
	int a = 1;
	int b = 2;
	SwapData<int>(a, b);
	cout << "[ " << a << ", " << b << " ]" << endl;
	Point p1(10, 20);
	Point p2(100, 200);
	SwapData<Point>(p1, p2);
	p1.ShowPosition();
	p2.ShowPosition();
    return 0;
}

