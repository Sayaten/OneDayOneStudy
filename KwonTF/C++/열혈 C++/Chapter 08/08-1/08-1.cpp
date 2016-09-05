// 08-1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;
//Risk Level//
enum class RISK_LEVEL
{
	RISK_A, RISK_B, RISK_C
};
//Class//
class Employee
{
public:
	Employee(string input);
	void ShowYourName() const;
	virtual int GetPay() const = 0;
	virtual void ShowSalaryInfo() const = 0;
private:
	string name;
};
class PermanentWorker : public Employee
{
public:
	PermanentWorker(string input, int money);
	int GetPay() const;
	void ShowSalaryInfo() const;
private:
	int salary;
};
class TemporaryWorker : public Employee {
public:
	TemporaryWorker(string input,int pay);
	void AddWorktime(int time);
	int GetPay() const;
	void ShowSalaryInfo() const;
private:
	int workTime;
	int payPerHour;
};
class SalesWorker : public PermanentWorker
{
public:
	SalesWorker(string input, int money, double ratio);
	void AddSalesResult(int value);
	int GetPay() const;
	void ShowSalaryInfo() const;
private:
	int salesResult;
	double bonusRatio;
};
class ForeginSalesWorker : public SalesWorker
{
public:
	ForeginSalesWorker(string input, int money, double ratio, RISK_LEVEL level);
	int GetPay() const;
	void ShowSalaryInfo() const;
	int GetRiskPay() const;
private:
	RISK_LEVEL riskLevel;
};

//-----------------------//
//Handler Class//
class EmployeeHandler
{
public:
	EmployeeHandler();
	void AddEmployee(Employee* emp);
	void ShowAllSalaryInfo();
	void ShowTotalSalary();
private:
	vector<Employee*> empList;
};
//Employee Function//
Employee::Employee(string input) : name(input) {}
void Employee::ShowSalaryInfo() const {}
void Employee::ShowYourName() const
{
	cout << "Name: " << name << endl;
}
int Employee::GetPay() const
{
	return 0;
}
//-----------------------//
//Permanet Worker Function//
PermanentWorker::PermanentWorker(string input, int money): Employee(input), salary(money){}
int PermanentWorker::GetPay() const
{
	return salary;
}
void PermanentWorker::ShowSalaryInfo() const
{
	ShowYourName();
	cout << "Salary: " << salary << endl<<endl;
}
//------------------------//
//Temporary Worker Function//
TemporaryWorker::TemporaryWorker(string input, int pay) : Employee(input), payPerHour(pay), workTime(0){}
void TemporaryWorker::AddWorktime(int time)
{
	workTime += time;
}
int TemporaryWorker::GetPay() const
{
	return workTime*payPerHour;
}
void TemporaryWorker::ShowSalaryInfo() const
{
	ShowYourName();
	cout << "Salary: " << GetPay() << endl << endl;
}
//------------------------//
//Sales Worker Function//
SalesWorker::SalesWorker(string input, int money, double ratio) : PermanentWorker(input, money), bonusRatio(ratio), salesResult(0){}
void SalesWorker::AddSalesResult(int value)
{
	salesResult += value;
}
int SalesWorker::GetPay() const
{
	return PermanentWorker::GetPay() + (int)(salesResult*bonusRatio);
}
void SalesWorker::ShowSalaryInfo() const
{
	ShowYourName();
	cout << "Salary: " << GetPay() << endl << endl;
}
//------------------------//
//Foregin Sales Worker Function//
ForeginSalesWorker::ForeginSalesWorker(string input, int money, double ratio, RISK_LEVEL level) :SalesWorker(input, money, ratio), riskLevel(level) {}
int ForeginSalesWorker::GetPay() const
{
	return SalesWorker::GetPay()+GetRiskPay();
}
void ForeginSalesWorker::ShowSalaryInfo() const
{
	ShowYourName();
	cout << "Salary: " << SalesWorker::GetPay() << endl;
	cout << "Risk Pay: " << GetRiskPay() << endl;
	cout << "sum: " << GetPay() << endl << endl;
}
int ForeginSalesWorker::GetRiskPay() const
{
	switch (riskLevel)
	{
	case RISK_LEVEL::RISK_A:
		return SalesWorker::GetPay() / 10 * 3;
	case RISK_LEVEL::RISK_B:
		return SalesWorker::GetPay() / 10 * 2;
	case RISK_LEVEL::RISK_C:
		return SalesWorker::GetPay() / 10 * 1;
	default:
		break;
	}
	return 0;
}
//------------------------//
//------------------------//
//Employee Handler Function//
EmployeeHandler::EmployeeHandler() {}
void EmployeeHandler::AddEmployee(Employee* emp)
{
	empList.push_back(emp);
}
void EmployeeHandler::ShowAllSalaryInfo()
{
	for (auto &&tempEmp : empList) {
		tempEmp->ShowSalaryInfo();
	}
}
void EmployeeHandler::ShowTotalSalary()
{
	int sum = 0;
	for (auto &&tempEmp : empList) {
		sum += tempEmp->GetPay();
	}
	cout << "TotalSalary: " << sum << endl;
}
int main()
{
	EmployeeHandler handler;
	handler.AddEmployee(new PermanentWorker("KIM", 1000));
	handler.AddEmployee(new PermanentWorker("LEE", 1500));
	TemporaryWorker* alba = new TemporaryWorker("Jung", 700);
	alba->AddWorktime(5);
	handler.AddEmployee(alba);
	SalesWorker* seller = new SalesWorker("Hong", 1000, 0.1);
	seller->AddSalesResult(7000);
	handler.AddEmployee(seller);
	ForeginSalesWorker* fseller1 = new ForeginSalesWorker("KwonTF", 1000, 0.1, RISK_LEVEL::RISK_A);
	fseller1->AddSalesResult(7000);
	ForeginSalesWorker* fseller2 = new ForeginSalesWorker("TeFaL", 1000, 0.1, RISK_LEVEL::RISK_B);
	fseller2->AddSalesResult(7000);
	ForeginSalesWorker* fseller3 = new ForeginSalesWorker("RaFaL", 1000, 0.1, RISK_LEVEL::RISK_C);
	fseller3->AddSalesResult(7000);
	handler.AddEmployee(fseller1);
	handler.AddEmployee(fseller2);
	handler.AddEmployee(fseller3);
	handler.ShowAllSalaryInfo();
	handler.ShowTotalSalary();
    return 0;
}

