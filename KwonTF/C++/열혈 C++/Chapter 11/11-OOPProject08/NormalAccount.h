#pragma once
#ifndef __NORMAL_ACCOUNT__
#define __NORMAL_ACCOUNT__

#include "BankingCummonDec1.h"
#include "Account.h"
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

#endif // !__NORMAL_ACCOUNT__