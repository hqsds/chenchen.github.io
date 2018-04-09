#include<iostream>
#include"book.h"
using namespace std;

class Store
{
private:
	int size;
	int currentsize;
	double money;
	Book* inventory;
	
    
public:
	Store(double);
	~Store();
	void grow();
	int Findname(const char* name) const;
	void add(Book newbook);
	void lookup(const char* a) const;
	void sell(const char* t);
	void display() const;
	void Genredisp(Genre g) const;//display the genre summary

};