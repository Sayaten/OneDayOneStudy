#include "stdafx.h"
#include "HighCreditAccount.h"
//High Credit Account//
HighCreditAccount::HighCreditAccount(int inputID, string inputName, int inputRatio, CreditGrade inputGrade) :NormalAccount(inputID, inputName, inputRatio), accountGrade(inputGrade) {}
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