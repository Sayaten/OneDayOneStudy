// 08-OOPProject06.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
#include "stdafx.h"
#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
//Credit Grade//
enum class CreditGrade
{
	A, B, C
};
//Account Class//
class Account
{
public:
	Account(int inputID, string inputName);
	~Account();
	int getID() const;
	int getBalance() const;
	void setBalance(int money);
	virtual void Deposit(int money) = 0;
	void Withdraw(int money);
	void ShwoAccoutInfo() const;
	Account(const Account &copy);
private:
	int ID;
	string name;
	int balance;
};
class NormalAccount : public Account
{
public:
	NormalAccount(int inputID, string inputName, int inputRatio);
	void Deposit(int money);
	void SetRatio(int input);
	int GetRatio();
private:
	int raito;
};
class HighCreditAccount : public NormalAccount
{
public:
	HighCreditAccount(int inputID, string inputName, int inputRatio, CreditGrade inputGrade);
	void Deposit(int money);
private:
	CreditGrade accountGrade;
};
//Account//
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
void Account::setBalance(int money)
{
	balance = money;
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
//Handler//
class AccountHandler
{
public:
	//Function//
	AccountHandler();
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
AccountHandler::AccountHandler() : Booting(true)
{
}
void AccountHandler::CallMenu() const
{
	cout << "--------------Menu--------------" << endl << "1. 계좌 개설" << endl << "2. 입금" << endl << "3. 출금" << endl << "4. 계좌정보 전체 출력" << endl << "5, 프로그램 종료" << endl << "선택: ";
}
void AccountHandler::ChooseFunction()
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
void AccountHandler::MainMenu()
{
	CallMenu();
	ChooseFunction();
}
void AccountHandler::MakeAcc()
{
	string TName;
	int TID, AccountType, raito, firstBalance, tempgrade;
	CreditGrade grade;
	cout << "[1. NormalAccount, 2. HighCreditAccount]" << endl;
	cout << "Choose Your Account Type: ";
	cin >> AccountType;
	cout << "Input your name: ";
	cin >> TName;
	cout << "Input account ID you want: ";
	cin >> TID;
	cout << "Deposit Please: ";
	cin >> firstBalance;
	cout << "Input Ratio: ";
	cin >> raito;
	switch (AccountType)
	{
	case 1:
		Accountlist.push_back(new NormalAccount(TID, TName, raito));
		Accountlist.at(Accountlist.size() - 1)->Deposit(firstBalance);
		return;
	case 2:
		cout << "[1toA, 2toB, 3toC]" << endl;
		cout << "Input Account Grade: ";
		cin >> tempgrade;
		switch (tempgrade)
		{
		case 1:
			grade = CreditGrade::A;
			break;
		case 2:
			grade = CreditGrade::B;
			break;
		case 3:
			grade = CreditGrade::C;
			break;
		default:
			cout << "Uncorrect CreditGradeType" << endl;
			return;
		}
		Accountlist.push_back(new HighCreditAccount(TID, TName, raito, grade));
		Accountlist.at(Accountlist.size() - 1)->Deposit(firstBalance);
		break;
	default:
		cout << "Uncorrect AccountType" << endl;
		break;
	}
	return;
}
void AccountHandler::DepoAcc()
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
void AccountHandler::AllAcc() const
{
	for (auto &&account : Accountlist) {
		account->ShwoAccoutInfo();
	}
}
bool AccountHandler::ISBooting()
{
	return Booting;
}
void AccountHandler::WithAcc()
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
//Normal Account//
NormalAccount::NormalAccount(int inputID, string inputName, int inputRatio): Account(inputID, inputName), raito(inputRatio){}
void NormalAccount::Deposit(int money)
{
	int temp = getBalance();
	temp += money;
	temp += temp / 100 * raito;
	setBalance(temp);
}
void NormalAccount::SetRatio(int input)
{
	raito = input;
}
int NormalAccount::GetRatio()
{
	return raito;
}
//High Credit Account//
HighCreditAccount::HighCreditAccount(int inputID, string inputName, int inputRatio, CreditGrade inputGrade):NormalAccount(inputID, inputName,inputRatio), accountGrade(inputGrade){}
void HighCreditAccount::Deposit(int money)
{
	int temp = getBalance();
	int tempratio = GetRatio();
	temp += money;
	switch (accountGrade)
	{
	case CreditGrade::A:
		tempratio += 7;
		break;
	case CreditGrade::B:
		tempratio += 4;
		break;
	case CreditGrade::C:
		tempratio += 2;
		break;
	default:
		cout << "CreditGradeError...." << endl;
		return;
	}
	temp += temp / 100 * tempratio;
	setBalance(temp);
	return;
}
int main()
{
	AccountHandler KookminAccountHandler;
	while (KookminAccountHandler.ISBooting()) {
		KookminAccountHandler.MainMenu();
	}
	return 0;
}