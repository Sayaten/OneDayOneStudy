// 01-2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
void swap(int* num1, int* num2);
void swap(char* num1, char* num2);
void swap(double* num1, double* num2);
int main()
{
	int num1 = 20, num2 = 30;
	swap(&num1, &num2);
	cout << num1 << ' ' << num2 << endl;
	char char1 = 'A', char2 = 'Z';
	swap(&char1, &char2);
	cout << char1 << ' ' << char2 << endl;
	double db1 = 1.111, db2 = 5.555;
	swap(&db1, &db2);
	cout << db1 << ' ' << db2 << endl;
    return 0;
}

void swap(int * num1, int * num2)
{
	int temp;
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void swap(char * num1, char * num2)
{
	char temp;
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void swap(double * num1, double * num2)
{
	double temp;
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
