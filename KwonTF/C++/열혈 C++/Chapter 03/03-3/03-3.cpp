// 03-3.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
using std::cout;
using std::endl;
class Printer
{
public:
	void SetString(char *input);
	void ShowString();
private:
	char data[100];
};

int main()
{
	Printer pnt;
	pnt.SetString("Hello World!");
	pnt.ShowString();
	pnt.SetString("I love C++");
	pnt.ShowString();
    return 0;
}

void Printer::SetString(char *input)
{
	strcpy_s(data, input);
}

void Printer::ShowString()
{
	cout << data << endl;
}
