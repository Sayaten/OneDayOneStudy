#pragma once
#include "stdafx.h"
#include "BankingCummonDec1.h"
class ErrorClass
{
public:
	virtual void ShowErrorMessage() = 0;
};
class ValueError : public ErrorClass
{
public:
	ValueError(int errorItem);
	void ShowErrorMessage();
private:
	int ErrorItem;
};

class WithdrawError : public ErrorClass
{
public:
	WithdrawError(int input, int input2);
	void ShowErrorMessage();
private:
	int balance;
	int ErrorItem;
};
