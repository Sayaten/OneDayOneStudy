// 11-3.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
class Gun
{
public:
	Gun(int bnum);
	void shot();
	int getBull()const;
private:
	int bullet;
};

Gun::Gun(int bnum):bullet(bnum){}
class Police
{
public:
	Police(int bnum, int bcuff);
	void PutHandcuff();
	void shot();
	~Police();
	Police operator=(const Police& pman);
	Police(const Police& pman);
	int getHand() const;
	int getBull() const;
	bool isPistol() const;
private:
	int handcuffs;
	Gun* pistol;
};

Police::Police(int bnum, int bcuff):handcuffs(bcuff){
	if (bnum > 0) {
		pistol = new Gun(bnum);
	}
	else
	{
		pistol = NULL;
	}
}

void Police::PutHandcuff()
{
	cout << "Hand!" << endl;
	handcuffs--;
}

void Police::shot()
{
	if (pistol == NULL) {
		cout << "No Shot" << endl;
	}
	else
	{
		pistol->shot();
	}
}

Police::~Police()
{
	if (pistol != NULL)
		delete pistol;
}

Police Police::operator=(const Police & pman)
{
	handcuffs = pman.getHand();
	if (pistol != NULL) {
		delete pistol;
	}
	if (!pman.isPistol()) {
		pistol = NULL;
	}
	else
	{
		pistol = new Gun(pman.getBull());
	}
	return *this;
}

Police::Police(const Police & pman) :handcuffs(pman.getHand())
{
	if (!pman.isPistol() || pman.getBull() <= 0) {
		pistol = NULL;
	}
	else {
		pistol = new Gun(pman.getBull());
	}
}

int Police::getHand() const
{
	return handcuffs;
}

int Police::getBull() const
{
	return pistol->getBull();
}

bool Police::isPistol() const
{
	if(pistol == NULL)
		return false;
	return true;
}


void Gun::shot()
{
	cout << "Shot" << endl;
	bullet--;
}
int Gun::getBull() const
{
	return bullet;
}
int main()
{
	Police pman1(5, 3);
	pman1.shot();
	pman1.PutHandcuff();

	Police pman2(0, 3);
	pman2.shot();
	pman2.PutHandcuff();
	Police pman3 = pman1;
	pman1 = pman2;
	pman1.shot();
	pman3.shot();
    return 0;
}

