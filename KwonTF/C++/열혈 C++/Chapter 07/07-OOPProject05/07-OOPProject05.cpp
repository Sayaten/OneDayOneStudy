// 07-OOPProject05.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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
	void ShwoAccoutInfo() const;
	Account(const Account &copy);
private:
	int ID;
	string name;
	int balance;
};
class ATM
{
public:
	//Function//
	ATM();
	void MainMenu();
	bool ISBooting();
private:
	//Variable//
	vector<Account*> Accountlist;
	bool Booting;
	int Operation;
	void CallMenu() const;
	void ChooseFunction();
	void MakeAcc();
	void WithAcc();
	void DepoAcc();
	void AllAcc() const;
};
ATM::ATM() : Booting(true)
{
}
void ATM::CallMenu() const
{
	cout << "--------------Menu--------------" << endl << "1. ���� ����" << endl << "2. �Ա�" << endl << "3. ���" << endl << "4. �������� ��ü ���" << endl << "5, ���α׷� ����" << endl << "����: ";
}
void ATM::ChooseFunction()
{
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
			delete Accountlist.at(Accountlist.size() - 1);
			Accountlist.pop_back();
		}
		break;
	default:
		break;
	}
}
void ATM::MainMenu()
{
	CallMenu();
	ChooseFunction();
}
int main()
{
	ATM KookminATM;
	while (KookminATM.ISBooting()) {
		KookminATM.MainMenu();
	}
	return 0;
}

void ATM::MakeAcc()
{
	string TName;
	int TID;
	cout << "Input your name: ";
	cin >> TName;
	cout << "Input account ID you want: ";
	cin >> TID;
	Accountlist.push_back(new Account(TID, TName));
}

void ATM::DepoAcc()
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
	for (auto &&ForAccount : Accountlist) {
		if (ForAccount->getID() == Fid) {
			ForAccount->Deposit(input);
			cout << "Deposit Complete" << endl;
			return;
		}
	}
	cout << "Can't find your account's ID" << endl;
	return;
}

void ATM::AllAcc() const
{
	for (auto &&account : Accountlist) {
		account->ShwoAccoutInfo();
	}
}

bool ATM::ISBooting()
{
	return Booting;
}

void ATM::WithAcc()
{
	int Fid, input = 0;
	cout << "Account ID: ";
	cin >> Fid;
	cout << "Withdraw cash: ";
	cin >> input;
	for (auto &&ForAccount : Accountlist) {
		if (ForAccount->getID() == Fid) {
			if (ForAccount->getBalance() >= input) {
				ForAccount->Withdraw(input);
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

void Account::ShwoAccoutInfo() const
{
	cout << "-------------------------" << endl << "Accout ID: " << this->ID << endl << "Name: " << this->name << endl << "Balance: " << this->balance << endl << "-------------------------" << endl;
}

Account::Account(const Account & copy) :ID(copy.ID), name(copy.name), balance(copy.balance)
{
}