#include<iostream>
#include<iomanip>
#include<cstring>
#include<cctype>
#include"store.h"
#include"book.h"


Store::Store(double m)
{
	size = 5;
	currentsize = 0;
	money = m;
	inventory = new Book[size];
}

Store::~Store()
{
	delete [] inventory;
}

void Store::grow()
{
		size = size + 5;
		Book* newinventory = new Book[size];
		for (int i = 0; i < currentsize;i++)
		{
			newinventory[i] = inventory[i];
		}
		delete[] inventory;
		inventory = newinventory;
}

int Store::Findname(const char* name) const
{
	for (int i = 0; i < currentsize; i++)
	{
		if (strcmp(inventory[i].GetAuthor(), name) == 0)
			return i;
	}
	for (int i = 0; i < currentsize; i++)
	{
		if (strcmp(inventory[i].GetTitle(), name) == 0)
			return i;
	}
	return -1;
}

void Store::add(Book newbook)
{
	if (currentsize==size)
	{
		grow();
	}
	inventory[currentsize++] = newbook;

}
void Store::lookup(const char* a) const
{
	int ibook = Findname(a);
	if (ibook == -1)
		cout << "No such book" << endl;
	else
	inventory[ibook].Display();

}//look up by author name or title

void Store::sell(const char* t)
{
	int sbook = Findname(t);
	if (sbook == -1)
		cout << "No such a book";
	else
	{
		money = money + inventory[sbook].GetPrice();
		for (int j = sbook; j < currentsize - 1;j++)
			inventory[j] = inventory[j + 1];
		currentsize--;
		
	}

		
}
void Store::display() const
{
	for (int i = 0; i < currentsize; i++)
	{
			inventory[i].Display();
			
	}
	cout << "The total number of those books:" << currentsize<<endl;
	cout << "The cash number is:" << money<<endl;

}

void Store::Genredisp(Genre g) const
{
	int totnum=0;
	for (int i = 0; i < currentsize; i++)
	{
		if (inventory[i].GetGenre() == g)
		{
			inventory[i].Display();
    		totnum = totnum + 1;
		}
 	}
	cout << "The total number of those books:" << totnum<<endl;
}//display the genre summary
