// 13-2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
template<class T1>
T1 SumArray(T1 arr[], int len) {
	T1 sum = 0;
	for (int i = 0; i < len;i++ ) {
		sum += arr[i];
	}
	return sum;
}
int main()
{
	int intarr[5] = { 1, 2, 3, 4, 5 };
	double doubarrr[10] = { 1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9,10.01 };
	cout << "Int Sum: " << SumArray<int>(intarr, 5) << endl;
	cout << "Double Sum: " << SumArray<double>(doubarrr, 10) << endl;
    return 0;
}

