#pragma once
#ifndef __HIGH_CREDIT_ACCOUNT__
#define __HIGH_CREDIT_ACCOUNT__

#include "BankingCummonDec1.h"
#include "NormalAccount.h"
class HighCreditAccount : public NormalAccount
{
public:
	HighCreditAccount(int inputID, string inputName, int inputRatio, CreditGrade inputGrade);
	void Deposit(int money);
private:
	CreditGrade accountGrade;
};
#endif // !__HIGH_CREDIT_ACCOUNT__