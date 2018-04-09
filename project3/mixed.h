#include<iostream>
using namespace std;
class Mixed{
private:
	int integer;
	int numerator;
	int denominator;

public:
	Mixed(int i, int n, int d);
	Mixed(int i);
	Mixed();

	double Evaluate() const;
	void Simplify();
	void ToFraction();
	bool valid(int i, int n, int d);


	bool operator<(const Mixed&) const;
	bool operator>(const Mixed&) const;
	bool operator<=(const Mixed&) const;
	bool operator>=(const Mixed&) const;
	bool operator==(const Mixed&) const;
	bool operator!=(const Mixed&) const;

	Mixed& operator++();
	Mixed& operator++(int);
	Mixed& operator--();
	Mixed& operator--(int);

	friend Mixed operator+(const Mixed&, const Mixed&);
	friend Mixed operator-(const Mixed&, const Mixed&);
	friend Mixed operator*(const Mixed&, const Mixed&);
	friend Mixed operator/(const Mixed&, const Mixed&);
	friend istream& operator>>(istream&, Mixed&);
	friend ostream& operator<<(ostream&, const Mixed&);

};
