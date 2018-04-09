#include <iostream>
#include "myint.h"

using namespace std;

int C2I(char c)
// converts character into integer (returns -1 for error)
{
	if (c < '0' || c > '9')	return -1;	// error
	return (c - '0');				// success
}

char I2C(int x)
// converts single digit integer into character (returns '\0' for error)
{
	if (x < 0 || x > 9)		return '\0';	// error
	return (static_cast<char>(x)+'0'); 	// success
}

// Add in operator overload and member function definitions 

MyInt::MyInt()// first constructor
{
	digits = 5;
	currentdigits = 1;
	myinteger = new int[digits];
	myinteger[0] = 0;

}
MyInt::MyInt(int number)      //second constructor
{

	if (number > 0)
	{
		int number1, n;
		number1 = number;
		n = 0;
		while (number1 != 0)
		{
			number1 = number1 / 10;
			n++;
		}
		currentdigits = n;
		digits = n;
		myinteger = new int[digits];
		for (int i = 0; i < n; i++)
		{
			myinteger[i] = number % 10;
			number = number / 10;
		}
	}
	else
	{
		digits = 5;
		currentdigits = 1;
		myinteger = new int[digits];
		myinteger[0] = 0;
	}
}

MyInt::MyInt(char* cnumber)           //user-defined constructor
{
	int n = strlen(cnumber);
	digits = n;
	currentdigits = n;
	myinteger = new int[digits];
	
	for (int i = currentdigits-1; i>=0; i--)
	{
		if (cnumber[i]<'0' || cnumber[i]>'9')
		{
			digits = 5;
	    	currentdigits = 1;
			delete[] myinteger;
			myinteger = new int[digits];
			myinteger[0] = 0;
			break;
		}

		myinteger[i] = C2I(cnumber[i]);
	}

}

MyInt::MyInt(const MyInt& m)  //copy constructor
{
	digits = m.digits;
	currentdigits = m.currentdigits;
	myinteger = new int[digits];

	for (int i = 0; i < currentdigits; i++)
	{
		myinteger[i] = m.myinteger[i];
	}
}


MyInt::~MyInt()
{
	delete[] myinteger;

}
MyInt& MyInt::operator=(const MyInt& m)
{
	if (this == &m)
		return *this;
	digits = m.digits;
	currentdigits = m.currentdigits;
	delete[] myinteger;
	myinteger = new int[digits];
	for (int i = 0; i < m.currentdigits; i++)
	{
		myinteger[i] = m.myinteger[i];
	}
	return *this;


}
MyInt& MyInt::grow()
{
	digits = digits + 5;
	int* newmyinteger = new int[digits];
	for (int i = 0; i < currentdigits; i++)
	{
		newmyinteger[i] = myinteger[i];
	}
	delete [] myinteger;
	myinteger = newmyinteger;
	return *this;
}

MyInt& MyInt::operator++()
{
	*this = *this + 1;
	return *this;
}

MyInt MyInt::operator++(int)
{
	MyInt m;
	m = *this;
	*this = *this + 1;
	return m;
}

MyInt operator+ (const MyInt& x, const MyInt& y)
{
	int q1=0;
	int q,s;
	int r = 0;
	int maxdigits,mindigits;
	MyInt sum;
	maxdigits = (x.currentdigits>=y.currentdigits ? x.currentdigits:y.currentdigits);
	mindigits = (x.currentdigits<=y.currentdigits ? x.currentdigits : y.currentdigits);
	sum.digits = maxdigits+1;
	sum.currentdigits = maxdigits;
	delete[] sum.myinteger;
	sum.myinteger = new int[sum.digits];
	
	for (int i = 0; i < mindigits; i++)
	{
		s = x.myinteger[i] + y.myinteger[i];
		q = (s+q1)/10;
		r = (s+q1) % 10;
		sum.myinteger[i] = r;
		q1 = q;
	}
	for (int i = mindigits; i < maxdigits; i++)
	{
		s = x.currentdigits > y.currentdigits ? x.myinteger[i] : y.myinteger[i];
		q = (s + q1) / 10;
		r = (s + q1) % 10;
		sum.myinteger[i] = r;
		q1 = q;
	}
	sum.myinteger[maxdigits] = q;
	if (q != 0)
		sum.currentdigits++;
	return sum;
}

MyInt& MyInt::mult(int integer)  //MyInt*integer
{
	int q1 = 0; int q,s;
	int r = 0;
	if (currentdigits == digits)
		grow();
	for (int i = 0; i < currentdigits; i++)
	{
		s = myinteger[i] * integer;
		q = (s+ q1) / 10;
		r = (s+q1) % 10;
		myinteger[i] = r;
		q1 = q;
	}
	myinteger[currentdigits] = q;
	if (q != 0)
		currentdigits++;
	return *this;

}

MyInt& MyInt::shift(int bits)
{
	int* temp = new int[currentdigits];
	for (int i = 0; i < currentdigits; i++)
	{
		temp[i] = myinteger[i];
	}
	currentdigits = currentdigits + bits;
	digits = currentdigits;
	delete[]myinteger;
	myinteger = new int[digits];
	for (int i = bits; i < currentdigits; i++)
	{
		myinteger[i] = temp[i-bits];
	}
	for (int i = 0; i < bits; i++)
	{
		myinteger[i] = 0;
	}
	return *this;
}

MyInt operator* (const MyInt& x, const MyInt& y)
{
	MyInt multip;
	MyInt m1= x;
	multip=m1.mult(y.myinteger[0]);
	for (int i = 1; i < y.currentdigits; i++)
	{
		MyInt m2 = x;
		m2.mult(y.myinteger[i]);
		m2=m2.shift(i);
		multip = multip + m2;
		
	}
	return multip;
}


bool operator< (const MyInt& x, const MyInt& y)
{
	if (x.currentdigits>y.currentdigits)
		return false;
	if (x.currentdigits == y.currentdigits)
	{
		for (int i = x.currentdigits - 1; i >= 1; i--)
		{
			if (x.myinteger[i] > y.myinteger[i])
				return false;
			if (x.myinteger[i] < y.myinteger[i])
				return true;
		}
		if (x.myinteger[0] >= y.myinteger[0])
			return false;
	}
	return true;
}
bool operator>(const MyInt& x, const MyInt& y)
{
	if (y < x)
		return true;
	else
		return false;

}
bool operator<=(const MyInt& x, const MyInt& y)
{
	if ((x < y) || (x == y))
		return true;
	else
		return false;

}
bool operator>=(const MyInt& x, const MyInt& y)
{
	if (!(x < y))
		return true;
	else
		return false;

}
bool operator==(const MyInt& x, const MyInt& y)
{
	if (x.currentdigits != y.currentdigits)
		return false;
	for (int i = 0; i < x.currentdigits; i++)
	{
		if (x.myinteger[i] != y.myinteger[i])
			return false;
	}
	return true;
}
bool operator!=(const MyInt& x, const MyInt& y)
{
	if (!(x == y))
		return true;
	else return false;
}
// declare overloads for input and output (MUST be non-member functions)
//  you may make them friends of the class

ostream& operator<<(ostream& s, const MyInt& m)
{
	for (int i = m.currentdigits - 1; i >= 0; i--)
	{
		s << m.myinteger[i];
	}
	return s;
}

istream& operator>>(istream& s,  MyInt& m)
{
	char ch;
	int digit0;
	int n = 1;
	s >> ch;
	if (ch > '0'&&ch <= '9')
		m.myinteger[0]= C2I(ch);

	//ch = s.peek();
	//cout << "peek is" << ch;
	
		ch = s.get();
		while (ch >= '0'&&ch <= '9')
		{
			n++;
			m.currentdigits = n;
			if (m.currentdigits == m.digits)
				m.grow();
			m.myinteger[n-1] = C2I(ch);
			ch = s.get();
		}
		int* ninteger = new int[n];
		for (int i = 0; i < n; i++)
		{
			ninteger[i] = m.myinteger[n - 1 - i];
		}
	m.currentdigits = n;
	m.digits = n;
	delete[] m.myinteger;
	m.myinteger = new int[n];
	m.myinteger=ninteger;

	return s;

}
