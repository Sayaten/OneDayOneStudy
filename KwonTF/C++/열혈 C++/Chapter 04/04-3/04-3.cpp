// 04-3.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

namespace POS
{
	enum class COMP_POS
	{
		CLERK, SENIOR, ASSIST
	};
	void ShowPOS(POS::COMP_POS pos) {
		switch (pos)
		{
		case COMP_POS::CLERK:
			cout << "SAWON" << endl;
			break;
		case COMP_POS::ASSIST:
			cout << "DAERII" << endl;
			break;
		case COMP_POS::SENIOR:
			cout << "JUIM" << endl;
			break;
		default:
			break;
		}
	}
};
class NameCard
{
public:
	NameCard(string inputName, string inputCompany, string inputPhone, POS::COMP_POS inputPosition);
	~NameCard();
	void ShowNamecard();
private:
	string name;
	string Company;
	string Phone;
	POS::COMP_POS Position;
};
NameCard::NameCard(string inputName, string inputCompany, string inputPhone, POS::COMP_POS inputPosition)
	:name(inputName), Company(inputCompany), Phone(inputPhone), Position(inputPosition)
{
}

NameCard::~NameCard()
{
	cout << name << "'s namecard 확 찢" << endl;
}

void NameCard::ShowNamecard()
{
	cout << "name: " << name << endl;
	cout << "Company: " << Company << endl;
	cout << "Phone: " << Phone << endl;
	cout << "Position: ";
	POS::ShowPOS(this->Position);
}

int main()
{
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", POS::COMP_POS::CLERK);
	NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", POS::COMP_POS::SENIOR);
	NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", POS::COMP_POS::ASSIST);
	manClerk.ShowNamecard();
	manSENIOR.ShowNamecard();
	manAssist.ShowNamecard();
    return 0;
}

