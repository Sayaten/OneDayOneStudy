// 02-1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
void intIncrease(int &num);
void reverseSign(int &num);
int main()
{
	int a = 10;
	intIncrease(a);
	cout << a << endl;
	reverseSign(a);
	cout << a << endl;
    return 0;
}

void intIncrease(int &num) {
	num++;
}

void reverseSign(int &num) {
	num = 0 - num;
}