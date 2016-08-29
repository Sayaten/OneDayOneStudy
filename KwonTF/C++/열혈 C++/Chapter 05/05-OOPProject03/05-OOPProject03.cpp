// 05-OOPProject03.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
#include "stdafx.h"
#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
//Structure//
class Account
{
public:
	Account(int inputID, string inputName);
	~Account();
	int getID() const;
	int getBalance() const;
	void Deposit(int money);
	void Withdraw(int money);
	void ShwoAccoutInfo();
	Account(const Account &copy);
private:
	int ID;
	string name;
	int balance;
};
//Function//
void MakeAcc();
void WithAcc();
void DepoAcc();
void AllAcc();
//Global Variable//
vector<Account*> Accountlist;
bool Booting;
int main()
{

	int Operation;
	Booting = true;
	while (Booting) {
		cout << "--------------Menu--------------" << endl << "1. 계좌 개설" << endl << "2. 입금" << endl << "3. 출금" << endl << "4. 계좌정보 전체 출력" << endl << "5, 프로그램 종료" << endl << "선택: ";
		cin >> Operation;
		switch (Operation)
		{
		case 1:
			MakeAcc();
			cout << "Total Services: " << Accountlist.size() << endl;
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
			while (Accountlist.size() != 0) {
				delete Accountlist.at(Accountlist.size()-1);
				Accountlist.pop_back();
			}
			break;
		default:
			break;
		}
	}
	return 0;
}

void MakeAcc()
{
	string TName;
	int TID;
	cout << "Input your name: ";
	cin >> TName;
	cout << "Input account ID you want: ";
	cin >> TID;
	Accountlist.push_back(new Account(TID, TName));
}

void DepoAcc()
{
	int Fid, input = 0;
	cout << "Account ID: ";
	cin >> Fid;
	cout << "Deposit cash: ";
	cin >> input;
	if (input < 0) {
		cout << "Sorry. Please use withdraw function" << endl;
		return;
	}
	for (int i = 0; i < Accountlist.size(); i++) {
		if (Accountlist.at(i)->getID() == Fid) {
			Accountlist.at(i)->Deposit(input);
			cout << "Deposit Complete" << endl;
			return;
		}
	}
	cout << "Can't find your account's ID" << endl;
	return;
}

void AllAcc()
{
	for (int i = 0; i < Accountlist.size(); i++) {
		Accountlist[i]->ShwoAccoutInfo();
	}
}

void WithAcc()
{
	int Fid, input = 0;
	cout << "Account ID: ";
	cin >> Fid;
	cout << "Withdraw cash: ";
	cin >> input;
	for (int i = 0; i < Accountlist.size(); i++) {
		if (Accountlist[i]->getID() == Fid) {
			if (Accountlist[i]->getBalance() >= input) {
				Accountlist[i]->Withdraw(input);
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

Account::Account(int inputID, string inputName)
	:ID(inputID), name(inputName), balance(0)
{
	cout << "New Account" << endl;
}

Account::~Account()
{
	cout << "Destroy" << endl;
}

int Account::getID() const
{
	return this->ID;
}

int Account::getBalance() const
{
	return this->balance;
}

void Account::Deposit(int money)
{
	this->balance += money;
}

void Account::Withdraw(int money)
{
	this->balance -= money;
}

void Account::ShwoAccoutInfo()
{
	cout << "-------------------------" << endl << "Accout ID: " << this->ID << endl << "Name: " << this->name << endl << "Balance: " << this->balance << endl << "-------------------------" << endl;
}

Account::Account(const Account & copy) :ID(copy.ID), name(copy.name), balance(copy.balance)
{
}