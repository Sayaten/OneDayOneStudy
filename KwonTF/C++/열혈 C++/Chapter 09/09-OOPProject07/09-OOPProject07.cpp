// 09-OOPProject07.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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