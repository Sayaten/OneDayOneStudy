#include "stdafx.h"
#include "AccountHandler.h"
#include "ErrorControl.h"
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
	while (1) {
		cout << "Deposit cash: ";
		cin >> input;
		try
		{
			if (input < 0)
				throw ValueError(input);
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
		catch (ErrorClass &Error)
		{
			Error.ShowErrorMessage();
		}
	}
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
	while (1) {
		cout << "Withdraw cash: ";
		cin >> input;
		try
		{
			if (input < 0)
				throw ValueError(input);
			for (auto &&ForAccount : Accountlist) {
				if (ForAccount->getID() == Fid) {
					try
					{
						if (ForAccount->getBalance() < input)
							throw WithdrawError(input, ForAccount->getBalance());
						ForAccount->Withdraw(input);
						cout << "Withdraw Complete" << endl;
						return;
					}
					catch (ErrorClass &Error) {
						Error.ShowErrorMessage();
						break;
					}
				}
			}
			cout << "Can't find your account's ID" << endl;
		}
		catch (ErrorClass &Error)
		{
			Error.ShowErrorMessage();
		}
	}
}