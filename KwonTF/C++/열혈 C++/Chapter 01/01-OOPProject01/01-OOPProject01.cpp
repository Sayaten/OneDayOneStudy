// 01-OOPProject01.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
//Structure//
struct Account
{
	int ID;
	char name[20];
	int balance;
};
//Function//
void MakeAcc();
void WithAcc();
void DepoAcc();
void AllAcc();
//Global Variable//
struct Account Accountlist[100];
int accountNum;
bool Booting;
int main()
{

	int Operation;
	Booting = true;
	accountNum = 0;
	while (Booting) {
		cout << "--------------Menu--------------" << endl << "1. 계좌 개설" << endl << "2. 입금" << endl << "3. 출금" << endl << "4. 계좌정보 전체 출력" << endl << "5, 프로그램 종료" << endl << "선택: ";
		cin >> Operation;
		switch (Operation)
		{
		case 1:
			accountNum++;
			MakeAcc();
			break;
		case 2:
			DepoAcc();
			break;
		case 3:
			WithAcc();
			break;
		case 4:
			AllAcc();
			break;
		case 5:
			Booting = false;
			break;
		default:
			break;
		}
	}
    return 0;
}

void MakeAcc()
{
	char TName[20];
	int TID;
	cout << "Input your name: ";
	cin >> TName;
	cout << "Input account ID you want: ";
	cin >> TID;
	struct Account tempAcc;
	tempAcc.ID = TID;
	tempAcc.balance = 0;
	Accountlist[accountNum - 1] = tempAcc;
	strcpy_s(Accountlist[accountNum - 1].name, TName);
}

void DepoAcc()
{
	int Fid, input = 0;
	cout << "Account ID: ";
	cin >> Fid;
	cout << "Deposit cash: ";
	cin >> input;
	for (int i = 0; i < accountNum; i++) {
		if (Accountlist[i].ID == Fid) {
			Accountlist[i].balance += input;
			cout << "Deposit Complete" << endl;
			return;
		}
	}
	cout << "Can't find your account's ID" << endl;
}

void AllAcc()
{
	for (int i = 0; i < accountNum; i++) {
		cout << "-------------------------" << endl << "Accout ID: " << Accountlist[i].ID << endl << "Name: " << Accountlist[i].name << endl << "Balance: " << Accountlist[i].balance << endl <<"-------------------------"<< endl;
	}
}

void WithAcc()
{
	int Fid, input = 0;
	cout << "Account ID: ";
	cin >> Fid;
	cout << "Withdraw cash: ";
	cin >> input;
	for (int i = 0; i < accountNum; i++) {
		if (Accountlist[i].ID == Fid) {
			if (Accountlist[i].balance >= input) {
				Accountlist[i].balance -= input;
				cout << "Withdraw Complete" << endl;
			}
			else {
				cout << "Withdraw Failed.... Check out your current balance" << endl;
			}
			return;
		}
	}
	cout << "Can't find your account's ID" << endl;
}
