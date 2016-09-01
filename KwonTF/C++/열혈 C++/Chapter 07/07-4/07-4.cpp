// 07-4.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Book
{
public:
	Book(string a, string b, int c);
	void ShowBookInfo();
private:
	string title;
	string isbn;
	int price;
};

Book::Book(string a, string b, int c) : title(a), isbn(b), price(c)
{
}

void Book::ShowBookInfo()
{
	cout << "Title: " << title << endl << "ISBN: " << isbn << endl << "Price: " << price << endl;
}

class EBook : public Book
{
public:
	EBook(string a, string b, int c, string d);
	void ShowEBookInfo();
private:
	string DRMKey;
};

EBook::EBook(string a, string b, int c, string d) : Book(a, b, c), DRMKey(d)
{
}
void EBook::ShowEBookInfo()
{
	ShowBookInfo();
	cout << "DRMKey: " << DRMKey << endl;
}
int main()
{
	Book book("Good C++", "555-12345-890-0", 20000);
	book.ShowBookInfo();
	cout << endl << endl;
	EBook ebook("Good C++ EBook", "555-12345-890-1", 10000 ,"fdx9w0i8kiw");
	ebook.ShowEBookInfo();
    return 0;
}

