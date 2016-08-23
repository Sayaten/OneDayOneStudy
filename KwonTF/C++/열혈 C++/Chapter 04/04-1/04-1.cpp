// 04-1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class FruitSeller
{
public:
	void InitMembers(int price, int num, int money) {
		if (price < 0 || num<0||money<0) {
			cout << "Info Error" << endl;
			return;
		}
		APPLE_PRICE = price;
		numOfApple = num;
		myMoney = money;
	}
	int saleApples(int money) {
		int num = money / APPLE_PRICE;
		numOfApple -= num;
		myMoney += money;
		return num;
	}
	void ShowSalesResult() const{
		cout << "Left Apples: " << numOfApple << endl;
		cout << "Balance: " << myMoney << endl;
	}
private:
	int APPLE_PRICE;
	int numOfApple;
	int myMoney;
};
class FruitBuyer
{
public:
	void InitMembers(int money) {
		if (money < 0) {
			cout << "Your Balance is less than 0. How Poor..." << endl;
			return;
		}
		myMoney = money;
		numOfApples = 0;
	}
	void buyApples(FruitSeller &seller, int money) {
		if (money < 0) {
			cout << "No Way...." << endl;
			return;
		}
		numOfApples += seller.saleApples(money);
		myMoney -= money;
	}
	void ShowBuyResult() const{
		cout << "Current Balance: " << myMoney << endl;
		cout << "Current Apples: " << numOfApples << endl;
	}
private:
	int myMoney;
	int numOfApples;
};

int main()
{
	FruitSeller seller;
	seller.InitMembers(1000, 20, 0);
	FruitBuyer buyer;
	buyer.InitMembers(5000);
	buyer.buyApples(seller, 2000);
	cout << "Seller Result" << endl;
	seller.ShowSalesResult();
	cout << "Buyer Result" << endl;
	buyer.ShowBuyResult();
	FruitBuyer buyer2;
	FruitSeller seller2;
	buyer2.InitMembers(-100);
	seller2.InitMembers(-10, 200, 192);
	buyer.buyApples(seller, -200);
    return 0;
}

