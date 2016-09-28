#include "stdafx.h"
#include "Account.h"
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
Account::Account(const Account & copy) :ID(copy.ID), name(string(copy.name)), balance(copy.balance)
{
}

void Account::operator=(const Account & copy){
	ID = copy.ID;
	name = string(copy.name);
	balance = copy.balance;
}
