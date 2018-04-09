#include<iostream>
#include<iomanip>
#include "mixed.h"

using namespace std;

Mixed::Mixed(int i, int n, int d)
{
	if (valid(i, n, d))
	{
		integer = i;
		numerator = n;
		denominator = d;
	}
	else
	{
		integer = 0;
		numerator = 0;
		denominator = 1;

	}

}
Mixed::Mixed(int i)
{

	integer = i;
	numerator = 0;
	denominator = 1;
}



Mixed::Mixed()
{
	integer = 0;
	numerator = 0;
	denominator = 1;
}

bool Mixed::valid(int i, int n, int d)
{
	if (d == 0 || d<0) return false;
	if (i>0 && n<0) return false;
	if (i<0 && n<0) return false;
	return true;

}

double Mixed::Evaluate() const
{
	double val;
	val = static_cast<double>(numerator) / denominator;
	if (integer<0)
		val = integer - val;
	else
		val = integer + val;
	return val;
}

void Mixed::Simplify()
{
	int quote;
	int remainder;
	int c, numerator1, denominator1;
	quote = numerator / denominator;
	remainder = numerator%denominator;
	if (integer > 0)
	{
		integer = integer + quote;
		numerator = remainder;
	}
	else if (integer<0)
	{
		integer = integer - quote;
		numerator = remainder;
	}
	else if (integer == 0 && numerator > 0)
	{
		integer = integer + quote;
		numerator = remainder;
	}
	else
	{
		integer = quote;
		numerator = -remainder;
	}

	numerator1 = numerator;
	denominator1 = denominator;
	while (numerator1 != 0)
	{
		c = numerator1; numerator1 = denominator1%numerator1; denominator1 = c;
	}
	numerator = numerator / denominator1;
	denominator = denominator / denominator1;

}

void Mixed::ToFraction()
{
	int a;
	if (integer>0)
	{
		numerator = integer*denominator + numerator;
		integer = 0;
	}

	if (integer<0)
	{
		a = -integer;
		numerator = -(a*denominator + numerator);
		integer = 0;
	}

}

bool Mixed::operator<(const Mixed& f) const
{
	int nnumerator1, nnumerator2;
	if (integer >= 0)
		nnumerator1 = integer*denominator + numerator;
	if (integer<0)
		nnumerator1 = integer*denominator - numerator;

	if (f.integer >= 0)
		nnumerator2 = f.integer*f.denominator + f.numerator;
	if (f.integer<0)
		nnumerator2 = f.integer*f.denominator - f.numerator;

	if (nnumerator1*f.denominator<denominator*nnumerator2)
		return true;
	else
		return false;


}


bool Mixed::operator>(const Mixed& f) const
{

	int nnumerator1, nnumerator2;
	if (integer >= 0)
		nnumerator1 = integer*denominator + numerator;
	if (integer<0)
		nnumerator1 = integer*denominator - numerator;

	if (f.integer >= 0)
		nnumerator2 = f.integer*f.denominator + f.numerator;
	if (f.integer<0)
		nnumerator2 = f.integer*f.denominator - f.numerator;

	if (nnumerator1*f.denominator>denominator*nnumerator2)
		return true;
	else
		return false;



}



bool Mixed::operator<=(const Mixed& f) const
{

	int nnumerator1, nnumerator2;
	if (integer >= 0)
		nnumerator1 = integer*denominator + numerator;
	if (integer<0)
		nnumerator1 = integer*denominator - numerator;

	if (f.integer >= 0)
		nnumerator2 = f.integer*f.denominator + f.numerator;
	if (f.integer<0)
		nnumerator2 = f.integer*f.denominator - f.numerator;

	if (nnumerator1*f.denominator <= denominator*nnumerator2)
		return true;
	else
		return false;

}



bool Mixed::operator>=(const Mixed& f) const
{
	int nnumerator1, nnumerator2;
	if (integer >= 0)
		nnumerator1 = integer*denominator + numerator;
	if (integer<0)
		nnumerator1 = integer*denominator - numerator;

	if (f.integer >= 0)
		nnumerator2 = f.integer*f.denominator + f.numerator;
	if (f.integer<0)
		nnumerator2 = f.integer*f.denominator - f.numerator;

	if (nnumerator1*f.denominator >= denominator*nnumerator2)
		return true;
	else
		return false;
}


bool Mixed::operator==(const Mixed& f) const
{
	int nnumerator1, nnumerator2;
	if (integer >= 0)
		nnumerator1 = integer*denominator + numerator;
	if (integer<0)
		nnumerator1 = integer*denominator - numerator;

	if (f.integer >= 0)
		nnumerator2 = f.integer*f.denominator + f.numerator;
	if (f.integer<0)
		nnumerator2 = f.integer*f.denominator - f.numerator;

	if (nnumerator1*f.denominator == denominator*nnumerator2)
		return true;
	else
		return false;
}



bool Mixed::operator!=(const Mixed& f) const
{
	if (*this == f)
		return false;
	return true;
}


Mixed& Mixed::operator++()
{
	integer = integer + 1;
	Simplify();
	return *this;
}
Mixed& Mixed::operator++(int)
{
	Mixed a;
	a = *this;
	++*this;
	return a;
}
Mixed& Mixed::operator--()
{
	integer = integer + 1;
	Simplify();
	return *this;
}
Mixed& Mixed::operator--(int)
{
	Mixed a;
	a = *this;
	--*this;
	return a;
}

Mixed operator+(const Mixed& f1, const Mixed& f2)
{
	Mixed a, f11, f22;
	int ndenominator, nnumerator;
	f11 = f1; f22 = f2;
	
	f11.ToFraction();
	f22.ToFraction();
	ndenominator = f11.denominator*f22.denominator;
	a.denominator = ndenominator;
	nnumerator = f11.numerator*f22.denominator + f22.numerator*f11.denominator;
	a.numerator = nnumerator;
	a.Simplify();
	return a;

}

Mixed operator-(const Mixed& f1, const Mixed& f2)
{
	Mixed a, f11, f22;
	int ndenominator, nnumerator;
	f11 = f1; f22 = f2;
	f11.ToFraction();
	f22.ToFraction();
	ndenominator = f11.denominator*f22.denominator;
	a.denominator = ndenominator;
	nnumerator = f11.numerator*f22.denominator - f22.numerator*f11.denominator;
	a.numerator = nnumerator;
	a.Simplify();
	return a;
}

Mixed operator*(const Mixed& f1, const Mixed& f2)
{
	Mixed a, f11, f22;
	int ndenominator, nnumerator;
	f11 = f1; f22 = f2;
	f11.ToFraction();
	f22.ToFraction();
	ndenominator = f11.denominator*f22.denominator;
	a.denominator = ndenominator;
	nnumerator = f11.numerator*f22.numerator;
	a.numerator = nnumerator;
	a.Simplify();
	return a;
}

 Mixed operator/(const Mixed& f1, const Mixed& f2)
{
	Mixed a, f11, f22;
	int ndenominator, nnumerator;
	if (f2.integer == 0 && f2.numerator == 0)
		return a;
	f11 = f1; f22 = f2;
	f11.ToFraction();
	f22.ToFraction();
	ndenominator = f11.denominator*f22.numerator;
	a.denominator = ndenominator;
	nnumerator = f11.numerator*f22.denominator;
	a.numerator = nnumerator;
	a.Simplify();
	return a;
}

istream& operator>>(istream& s, Mixed& f)
{
 int i,n,d;
  char m,l;
 s>>i>>m>>n>>l>>d;
 if (d == 0 || d < 0) return s;
 if (i>0 && n < 0) return s;
 if (i < 0 && n < 0) return s;
 
	 f.integer = i;
	 f.numerator = n;
	 f.denominator = d;
  return s;

}


//}

ostream& operator << (ostream& s, const Mixed& f)
{
	if (f.integer== 0 && f.numerator == 0)
		s << 0;
	else if (f.integer == 0)
		s << f.numerator << '/' << f.denominator;
	else if (f.integer != 0 && f.numerator == 0)
		s << f.integer;
	else
s<<f.integer<<' '<<f.numerator<<'/'<<f.denominator;
return s;
	
	
}




















