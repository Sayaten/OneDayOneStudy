// 04-2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class Point
{
public:
	void Init(int x, int y) {
		xpos = x;
		ypos = y;
	}
	void ShowPointInfo() const {
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
private:
	int xpos, ypos;
};
class Circle
{
public:
	Circle() = default;
	Circle(Point inputPoint, int inputBan);
	void showCircleInfo() const;
private:
	Point AncorPoint;
	int BanGiRum;
};


Circle::Circle(Point inputPoint, int inputBan)
{
	AncorPoint = inputPoint;
	BanGiRum = inputBan;
}

void Circle::showCircleInfo() const
{
	cout << "Radius: " << BanGiRum << endl;
	AncorPoint.ShowPointInfo();
}

class Ring
{
public:
	Ring(int a, int b, int c, int d, int e, int f);
	void showAllCir() const;
private:
	Circle innerCircle;
	Circle OuterCircle;
};

Ring::Ring(int a, int b, int c, int d, int e, int f)
{
	Point tempPoint;
	tempPoint.Init(a, b);
	innerCircle = Circle(tempPoint, c);
	tempPoint.Init(d, e);
	OuterCircle = Circle(tempPoint, f);
}

void Ring::showAllCir() const
{
	cout << "Inner Circle Info..." << endl;
	innerCircle.showCircleInfo();
	cout << "Outter Circle Info..." << endl;
	OuterCircle.showCircleInfo();
	return;
}

int main()
{
	Ring ring(1, 1, 4, 2, 2, 9);
	ring.showAllCir();
    return 0;
}