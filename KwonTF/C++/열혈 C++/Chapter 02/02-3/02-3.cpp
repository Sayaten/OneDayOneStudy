// 02-3.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	const int num = 12;
	const int *ptr = &num;
	const int *(&refer) = ptr;
	cout << *ptr << ", " << *refer << endl;
    return 0;
}

