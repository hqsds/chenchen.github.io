class Date

{
public:

Date()
{
	m=1;
	d=1;
	y=2000;
	f='D';
}
Date(int month, int day, int year)
{

	if (valid(month,day, year))

	{
	y=year;
	d=day;
	m=month;
	f='D';
	}
	
	else 
	{
	m=1;
	d=1;
	y=2000;
	f='D';
	}
}

void input();
//test if the input date is valid;
bool valid(int m , int d , int y);

//set the month, day and year to the d variable.

bool Set(int month, int day, int year ) ; 
//return the month of the date;

int GetMonth(); 
// return the day of the date;

int GetDay();
//return the year of the date;

int GetYear();
 //define the format of the date;

bool SetFormat(char f) ; 
//increase the number of the day;

void Increment(int numDays); 
//compare the order of two dates.

void Increment ();
	
int compare (const Date& day);
//output the date to the screen

void Show();
private:
	int d; // denoted the day;
	int m; // denont the month;
	int y; // denote the year; 
	char f;
};