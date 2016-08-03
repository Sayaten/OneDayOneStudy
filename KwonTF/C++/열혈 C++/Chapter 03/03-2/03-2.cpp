// 03-2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using std::cout;
using std::endl;
class Calculator
{
public:
	void Init();
	double Add(double a, double b);
	double Div(double a, double b);
	double Min(double a, double b);
	double Mul(double a, double b);
	void ShowOpCount();
private:
	int AddTime, DivTime, MinTime, MulTime;
};
int main()
{
	Calculator cal;
	cal.Init();
	cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << endl;
	cout << "3.5 / 1.7 = " << cal.Div(3.5, 1.7) << endl;
	cout << "2.2 - 1.5 = " << cal.Min(2.2, 1.5) << endl;
	cout << "4.9 / 1.2 = " << cal.Div(4.9, 1.2) << endl;
	cal.ShowOpCount();
    return 0;
}

void Calculator::Init()
{
	AddTime = 0;
	DivTime = 0;
	MulTime = 0;
	MinTime = 0;
}

double Calculator::Add(double a, double b)
{
	AddTime++;
	return a+b;
}

double Calculator::Div(double a, double b)
{
	DivTime++;
	return a/b;
}

double Calculator::Min(double a, double b)
{
	MinTime++;
	return a-b;
}

double Calculator::Mul(double a, double b)
{
	MulTime++;
	return a*b;
}

void Calculator::ShowOpCount()
{
	cout << "Add: " << AddTime << ", Min: " << MinTime << ", Mul: " << MulTime << ", Div: " << DivTime << endl;
}
