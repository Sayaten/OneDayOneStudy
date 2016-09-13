#include "stdafx.h"
#include "NormalAccount.h"
//Normal Account//
NormalAccount::NormalAccount(int inputID, string inputName, int inputRatio) : Account(inputID, inputName), raito(inputRatio) {}
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