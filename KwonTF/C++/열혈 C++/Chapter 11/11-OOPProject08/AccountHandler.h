#pragma once
#ifndef __ACCOUNT_HANDLER__
#define __ACCOUNT_HANDLER__

#include "BankingCummonDec1.h"
#include "HighCreditAccount.h"
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
#endif // !__ACCOUNT_HANDLER__