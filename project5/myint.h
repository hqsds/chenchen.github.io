#include<iostream>
using namespace std;
class MyInt
{
	// these overload starters are declared as friend functions

	friend MyInt operator+ (const MyInt& x, const MyInt& y);
	// add in multiplication, as well
	friend MyInt operator* (const MyInt& x, const MyInt& y);
	

	friend bool operator< (const MyInt& x, const MyInt& y);
	// add in the other comparison overloads, as well
	friend bool operator>(const MyInt& x, const MyInt& y);
	friend bool operator<=(const MyInt& x, const MyInt& y);
	friend bool operator>=(const MyInt& x, const MyInt& y);
	friend bool operator==(const MyInt& x, const MyInt& y);
	friend bool operator!=(const MyInt& x, const MyInt& y);
	// declare overloads for input and output (MUST be non-member functions)
	//  you may make them friends of the class
	friend istream& operator>>(istream& s, MyInt&);
	friend ostream& operator<<(ostream& s, const MyInt& m);
public:
	MyInt();		// first constructor
	MyInt(int number);      //second constructor
	MyInt(char*);           //user-defined constructor
	MyInt(const MyInt& m);    //copy constructor
	MyInt& grow();
	MyInt& mult(int integer);//MyInt*integer(1-9)
	MyInt& shift(int);
	// be sure to add in the second constructor, and the user-defined 
	//  versions of destructor, copy constructor, and assignment operator
	MyInt& operator=(const MyInt& m);
	MyInt& operator++();
	MyInt operator++(int);
	~MyInt();
private:
	int* myinteger;
	int currentdigits;
	unsigned int digits;  //save the number of digits of myinteger;
	// member data (suggested:  use a dynamic array to store the digits)

};