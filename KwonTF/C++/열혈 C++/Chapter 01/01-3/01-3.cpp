// 01-3.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
int BoxVolume(int argv1, int argv2, int argv3);
int BoxVolume(int argv1, int argv2);
int BoxVolume(int argv1);
int BoxVolume();
int main()
{
	cout << "[3, 3, 3] : " << BoxVolume(3, 3, 3) << endl;
	cout << "[5, 5, D] : " << BoxVolume(5, 5) << endl;
	cout << "[7, D, D] : " << BoxVolume(7) << endl;
	cout << "[D, D, D] : " << BoxVolume() << endl;
    return 0;
}

int BoxVolume(int argv1, int argv2, int argv3)
{
	return argv1*argv2*argv3*1;
}

int BoxVolume(int argv1, int argv2)
{
	return argv1*argv2*1;
}

int BoxVolume(int argv1)
{
	return argv1*1;
}

int BoxVolume()
{
	return 1;
}
