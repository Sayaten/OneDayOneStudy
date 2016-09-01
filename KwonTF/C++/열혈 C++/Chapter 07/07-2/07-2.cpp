// 07-2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
class MyFriendInfo
{
public:
	MyFriendInfo(string InputName, int InputAge);
	~MyFriendInfo();
	void ShowMyFriendInfo();
private:
	string name;
	int age;
};
class MyFriendDetailInfo : public MyFriendInfo
{
public:
	MyFriendDetailInfo(string InputName, int InputAge);
	MyFriendDetailInfo(string InputName, int InputAge, string InputAddr, string InputPhone);
	~MyFriendDetailInfo();
	void ShowMyFriendDetailInfo();
private:
	string addr;
	string phone;
};
MyFriendDetailInfo::MyFriendDetailInfo(string InputName, int InputAge):MyFriendInfo(InputName,InputAge) ,addr("Unknown"),phone("Unknown")
{
}
MyFriendDetailInfo::MyFriendDetailInfo(string InputName, int InputAge, string InputAddr, string InputPhone):MyFriendInfo(InputName, InputAge), addr(InputAddr), phone(InputPhone)
{
}
MyFriendDetailInfo::~MyFriendDetailInfo()
{
}
void MyFriendDetailInfo::ShowMyFriendDetailInfo()
{
	ShowMyFriendInfo();
	cout << "Address: " << addr << endl;
	cout << "Phone: " << phone << endl;
}
MyFriendInfo::MyFriendInfo(string InputName, int InputAge)
{
	name = InputName;
	age = InputAge;
}

MyFriendInfo::~MyFriendInfo()
{
}
void MyFriendInfo::ShowMyFriendInfo()
{
	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
}
int main()
{
	MyFriendDetailInfo myFriend1("KwonTF", 22);
	MyFriendDetailInfo myFriend2("TeFaL", 22, "Seoul", "010-7313-5137");
	myFriend1.ShowMyFriendDetailInfo();
	myFriend2.ShowMyFriendDetailInfo();
    return 0;
}

