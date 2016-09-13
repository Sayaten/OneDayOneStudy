// 11-OOPProject08.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "AccountHandler.h"
int main()
{
	AccountHandler KookminAccountHandler;
	while (KookminAccountHandler.ISBooting()) {
		KookminAccountHandler.MainMenu();
	}
	return 0;
}