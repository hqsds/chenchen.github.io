# include <iostream>
# include <iomanip>
# include <string>
# include "date.h"

using namespace std;

void Date::Increment(int number )

{
int month[12]={1,2,3,4,5,6,7,8,9,10,11,12};
int day[12]={31,28,31,30,31,30,31,31,30,31,30,31};

int num = d+ number;
while (num>day[m-1]) 
{
	if(m!=12)
	{
	num=num-day[m-1];
	m=m+1;
	}
	else if (m==12)

	{
	num=num-day[m-1];
	m=1;
	y=y+1;
	}
}
d=num;

}

void Date::Increment()

{
int number =1;
int month[12]={1,2,3,4,5,6,7,8,9,10,11,12};
int day[12]={31,28,31,30,31,30,31,31,30,31,30,31};

int num = d+ number;
while (num>day[m]) 
{
	if(m!=12)
	{
	num=num-d;
	m=m+1;
	}
	else if (m==12)

	{
	num=num-d;
	m=1;
	y=y+1;
	}
}
d=num;

}
void Date::input()

{
	int month, day , year;
	char m;
	bool correct=true;
	
	while (correct)
    {cout << " Please input the date as the form M/D/Y:\n";
	cin >>month>>m>>day>>m>>year;

	if (valid(month,day,year))

	{
	m=month;
	d=day;
	y=year;
	correct=false;
	}
	else {cout<< "Your input is illgal and please input the date again\n";}
	}
}
bool Date::valid(int m,int d, int y)
{
//use ind as the test indicator;
bool ind=true;

// the following defined the min and max of days in a month 

int min=1;
int max;
//define the max based on different month.
if ( m==2)

{
	max=28; 
}
if ((m==1)||( m==3) || (m == 5)|| (m == 7) ||(m==8)|| (m == 10)||(m==12))

{
max = 31; 
}

if (( m==4) || (m == 6)|| (m == 7) ||(m==9)|| (m == 11))

{
max = 30; 

}

if ( d>max || d < min) 

{
	ind =false;

} 

else if ( m>12 || m <1)

{
ind = false;
}

else if (y<=0)
{
ind = false; 
}

else {ind =true;}

return ind;

};

bool Date::Set(int month, int day, int year)

{
	if (valid(month,day,year))
	{m=month;
	d=day;
	y=year;
	return true;}

	else 
	{return false;}
}


int Date::GetMonth()

{
return m;
}

int Date::GetDay()

{
return d;
}

int Date::GetYear()

{
return y;
}

bool Date:: SetFormat(char format)

{
if ( (format=='D')||(format=='T')||(format=='L'))
{
f=format;
return true;
}

else
{return false;}
}

int Date::compare(const Date& d)
{
	int ind;
	if (this->y>d.y)
	{
	ind=1;
	}

	else if (this->y<d.y)
	{ind=-1;}

	else 
	{
	if (this->m>d.m)
	{
	ind =1;
	}
	else if(this->m<d.m)
	{
		ind =-1;
	}
	else {
	if ( this->d>d.d)
	{
		ind =1; 
	}
	else if (this->d<d.d)
	{
	ind = -1;
	}
	else {ind=0;}
	}
	
	}

return ind;

}

void Date::Show () 

{
	string date[12]={"Jan","Feb","Mar","Apr","May","June","July","Aug","Sept","Oct","Nov","Dec"};

	if (f=='D')

	{
	cout<<m<<'/'<<d<<'/'<<y;
	}

	else if (f=='T')
	{
		cout.width(2);
		cout.fill('0');
cout<<m<<'/';
		cout.width(2);
		cout.fill('0');
	cout<<d<<'/';
	cout.width(2);
	cout.fill('0');	
	cout<<y%100;
	}
	else if(f=='L')
	{
	cout<<date[m-1]<<" "<<d<<","<<y;

	}

	cout<<endl;
}