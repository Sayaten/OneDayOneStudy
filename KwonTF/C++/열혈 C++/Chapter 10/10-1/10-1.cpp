// 10-1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class Point
{
public:
	Point(int a, int b);
	void ShowPosition();
	friend Point operator+(const Point &pos1, const Point &pos2);
	friend Point operator-(const Point &pos1, const Point &pos2);
	friend bool operator==(const Point &pos1, const Point &pos2);
	friend bool operator!=(const Point &pos1, const Point &pos2);
	friend istream& operator>> (istream&, Point&);
	Point& operator+=(const Point &pos2);
	Point& operator-=(const Point &pos2);
	Point operator-();
	Point operator~();
	int GetXpos() const;
	int GetYpos() const;
	void SetXpos(int a);
	void SetYpos(int a);
private:
	int xpos, ypos;
};

Point::Point(int a = 0, int b = 0) : xpos(a), ypos(b){}
void Point::ShowPosition()
{
	cout << "[ " << xpos << ", " << ypos << " ]" << endl;
}
Point& Point::operator+=(const Point & pos2)
{
	this->SetXpos(this->GetXpos() + pos2.GetXpos());
	this->SetYpos(this->GetYpos() + pos2.GetYpos());
	return *this;
}
Point& Point::operator-=(const Point & pos2)
{
	this->SetXpos(this->GetXpos() - pos2.GetXpos());
	this->SetYpos(this->GetYpos() - pos2.GetYpos());
	return *this;
}
Point Point::operator-()
{
	Point pos(-this->GetXpos(), -this->GetYpos());
	return pos;
}
Point Point::operator~()
{
	Point pos(this->GetYpos(), this->GetXpos());
	return pos;
}
int Point::GetYpos() const
{
	return ypos;
}
void Point::SetXpos(int a)
{
	xpos = a;
}
void Point::SetYpos(int a)
{
	ypos = a;
}
int Point::GetXpos() const
{
	return xpos;
}
int main()
{
	Point pos1(3, 4);
	Point pos2(10, 20);
	Point pos3 = pos1 + pos2;
	Point pos4 = pos3 - pos1;
	bool temp;
	pos1.ShowPosition();
	pos2.ShowPosition();
	pos3.ShowPosition();
	pos4.ShowPosition();
	pos2 += pos4;
	pos2.ShowPosition();
	pos2 -= pos1;
	pos2.ShowPosition();
	temp = pos1 != pos2;
	cout << temp << endl;
	temp = pos2 != pos2;
	cout << temp << endl;
	temp = pos1 == pos1;
	cout << temp << endl;
	temp = pos3 == pos4;
	cout << temp << endl;
	pos1 = -pos2;
	pos2 = ~pos3;
	pos1.ShowPosition();
	pos2.ShowPosition();
	cout << "x.y Insert" << endl;
	cin >> pos1;
	cout << "x.y Insert" << endl;
	cin >> pos2;
	pos1.ShowPosition();
	pos2.ShowPosition();

    return 0;
}

Point operator+(const Point & pos1, const Point & pos2)
{
	return Point(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
}

Point operator-(const Point & pos1, const Point & pos2)
{
	return Point(pos1.xpos - pos2.xpos, pos1.ypos - pos2.ypos);
}

bool operator==(const Point & pos1, const Point & pos2)
{
	if (pos1.GetXpos() == pos2.GetXpos() && pos1.GetYpos() == pos2.GetYpos())
		return true;
	return false;
}

bool operator!=(const Point & pos1, const Point & pos2)
{
	if (pos1.GetXpos() != pos2.GetXpos() || pos1.GetYpos() != pos2.GetYpos())
		return true;
	return false;
}

istream & operator >> (istream & os, Point & pos)
{
	int x, y;
	os >> x;
	os >> y;
	pos.SetXpos(x);
	pos.SetYpos(y);
	return os;
}
