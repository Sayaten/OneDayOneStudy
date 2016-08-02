// 02-6.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
	srand(time(NULL));
	for (int i = 0; i < 5; i++) {
		cout << rand() % 100 << endl;
	}
    return 0;
}

