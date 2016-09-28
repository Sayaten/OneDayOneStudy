#include "stdafx.h"
#include "ErrorControl.h"

ValueError::ValueError(int errorItem):ErrorItem(errorItem){}

void ValueError::ShowErrorMessage()
{
	cout << "You can't depoist under 0 value: " << ErrorItem << endl;
}

WithdrawError::WithdrawError(int input, int input2):ErrorItem(input),balance(input2){}

void WithdrawError::ShowErrorMessage()
{
	cout << "Your account be minus!: " << balance - ErrorItem << endl;
}
