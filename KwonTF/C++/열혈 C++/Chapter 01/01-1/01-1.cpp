// 01-1.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//
#include "stdafx.h"
#include <iostream>

void quest1();
void quest2();
void quest3();
void quest4();

int main()
{
	quest1();
	quest2();
	quest3();
	quest4();
    return 0;
}

void quest1()
{
	int sum = 0, temp;
	for (int i = 0; i < 5; i++) {
		std::cout << i + 1 << " ���� ���� �Է�: ";
		std::cin >> temp;
		sum += temp;
	}
	std::cout <<"�հ�: "<< sum << std::endl;
}

void quest2()
{
	char name[20];
	char phone[40];
	std::cout << "Input your name: ";
	std::cin >> name;
	std::cout << "Input your phone number: ";
	std::cin >> phone;
	std::cout << "Your name : " << name << std::endl << "Your phone number : " << phone << std::endl;
}

void quest3()
{
	int a;
	std::cout << "Input the number : ";
	std::cin >> a;
	for (int i = 1; i < 10; i++) {
		std::cout << a << " x " << i << " = " << a*i << std::endl;
	}
}

void quest4()
{
	int sell;
	while (true)
	{
		std::cout << "�Ǹ� �ݾ��� ���� ������ �Է� (-1 to end): ";
		std::cin >> sell;
		if (sell == -1) {
			std::cout << "���α׷��� �����մϴ�" << std::endl;
			break;
		}
		else
			std::cout << "�̹� �� �޿�: " << 50 + (sell*0.12) << "����" << std::endl;
	}
}
