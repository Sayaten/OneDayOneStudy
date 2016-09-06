#pragma once
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "BankingCummonDec1.h"
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
#endif // !__ACCOUNT_H__