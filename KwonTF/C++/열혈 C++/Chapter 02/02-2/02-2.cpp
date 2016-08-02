// 02-2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
void SwapPointer(int *(&num1), int*(&num2));
int main()
{
	int num1 = 5;
	int *ptr1 = &num1;
	int num2 = 10;
	int *ptr2 = &num2;
	SwapPointer(ptr1, ptr2);
	cout << *ptr1 << ", "<<*ptr2 << endl;
    return 0;
}

void SwapPointer(int *(&num1), int*(&num2)) {
	int *temp = num2;
	num2 = num1;
	num1 = temp;
}
