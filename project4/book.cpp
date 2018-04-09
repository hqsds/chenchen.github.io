#ifndef _BOOK_H
#include "book.h"
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cctype>


using namespace std;
Book::Book()
{
	//strcpy(title, " ");
	//strcpy(author, " ");
	price = 0;

}

void Book::Set( const char* t, const char* a, Genre g, double p)
{
	int i,j;
	if (title != t)
		strcpy_s(title, t);

		if (author != a)
			strcpy_s(author, a);
	type = g;
	price = p;
}

const char* Book::GetTitle() const
{
	return title;

}

const char* Book::GetAuthor() const
{
	return author;
}

double Book::GetPrice() const
{
	return price;
}	

Genre Book::GetGenre() const
{
	return type;

}

void Book::Display() const
{
	const char* genrestring [] = { "FICTION", "MYSTERY", "SCIFI", "COMPUTER" };
	cout << setprecision(2) << fixed;
	cout.setf(ios::left);cout.width(31);
	cout << title;
	cout.width(21);cout << author;
	cout.width(12);cout <<genrestring[type] ;
	cout << '$';
	cout.width(6); cout<< price<<endl;

}



#endif