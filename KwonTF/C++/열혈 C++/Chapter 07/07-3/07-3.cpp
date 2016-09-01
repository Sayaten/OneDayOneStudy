// 07-3.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include<iostream>

using std::cout;
using std::endl;

class Rectangle
{
public:
	Rectangle(int a, int b);
	void ShowAreaInfo();
private:
	int weight;
	int height;
};

Rectangle::Rectangle(int a, int b): weight(a), height(b)
{
}

void Rectangle::ShowAreaInfo()
{
	cout << "Area: " << weight*height << endl;
}

class Square : public Rectangle
{
public:
	Square(int a);

private:

};

Square::Square(int a): Rectangle(a,a)
{
}
int main()
{
	Rectangle rect(4, 3);
	rect.ShowAreaInfo();
	Square sqr(7);
	sqr.ShowAreaInfo();
    return 0;
}

