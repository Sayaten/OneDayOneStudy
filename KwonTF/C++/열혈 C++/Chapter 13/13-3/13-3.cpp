// 13-3.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
template<class T>
class SmartPtr
{
public:
	SmartPtr(T* ptr);
	T& operator*() const;
	T* operator->() const;
	~SmartPtr();
private:
	T* posptr;
};
class Point
{
public:
	Point(int x, int y);
	void SetPos(int x, int y);
	void ShowPos();
private:
	int xpos, ypos;
};
int main()
{
	SmartPtr<Point> sptr1(new Point(1, 2));
	SmartPtr<Point> sptr2(new Point(3, 4));
	sptr1->ShowPos();
	sptr2->ShowPos();
	sptr1->SetPos(10, 20);
	sptr2->SetPos(30, 40);
	sptr1->ShowPos();
	sptr2->ShowPos();
    return 0;
}

template<class T>
SmartPtr<T>::SmartPtr(T * ptr):posptr(ptr){}

template<class T>
T & SmartPtr<T>::operator*() const{
	return *posptr;
}

template<class T>
T * SmartPtr<T>::operator->() const
{
	return posptr;
}

template<class T>
SmartPtr<T>::~SmartPtr()
{
	cout << "Deleted" << endl;
	delete posptr;
}

Point::Point(int x = 0, int y = 0):xpos(x),ypos(y){}

void Point::SetPos(int x, int y)
{
	xpos = x;
	ypos = y;
}

void Point::ShowPos()
{
	cout << "[ " << xpos << ", " << ypos << " ]" << endl;
}
