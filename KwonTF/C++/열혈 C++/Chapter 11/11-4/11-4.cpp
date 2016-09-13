// 11-4.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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
	Book operator=(const Book& book);
	Book(const Book& book);
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

Book Book::operator=(const Book & book)
{
	this->title = string(book.title);
	this->isbn = string(book.isbn);
	this->price = book.price;
	return *this;
}

Book::Book(const Book & book)
{
	title = string(book.title);
	isbn = string(book.isbn);
	price = book.price;
}

class EBook : public Book
{
public:
	EBook(string a, string b, int c, string d);
	void ShowEBookInfo();
	EBook(const EBook& eb);
	EBook operator=(const EBook& eb);
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
EBook::EBook(const EBook & eb):Book(eb)
{
	DRMKey = string(eb.DRMKey);
}
EBook EBook::operator=(const EBook & eb)
{
	Book::operator=(eb);
	DRMKey = string(eb.DRMKey);
	return *this;
}
int main()
{
	Book book("Good C++", "555-12345-890-0", 20000);
	book.ShowBookInfo();
	cout << endl << endl;
	EBook ebook("Good C++ EBook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	ebook.ShowEBookInfo();
	EBook ebook2("A", "s", 1, "SD");
	ebook2 = ebook;
	EBook ebook3 = ebook;
	cout << endl << endl;
	ebook2.ShowEBookInfo();
	cout << endl << endl;
	ebook3.ShowEBookInfo();
	return 0;
}

