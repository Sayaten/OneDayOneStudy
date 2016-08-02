// 02-5.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <cstring>
using namespace std;


int main()
{
	char Name[100] = "Kwon";
	cout << "strlen : " << strlen(Name) << endl;
	strcat(Name, "TF");
	cout << "strcat : " << Name << endl;
	char CopiedName[100];
	strcpy(CopiedName, Name);
	cout << "strcpy : " << CopiedName << endl;
	int isSame = strcmp(Name, CopiedName);
	if (isSame == 0) {
		cout << "Both are Same" << endl;
	}
	else {
		cout << "Diffrent String" << endl;
	}
    return 0;
}

