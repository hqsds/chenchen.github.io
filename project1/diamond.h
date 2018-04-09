#include <iostream>

using namespace std;

class Diamond

{
public:
	Diamond(int int_size,char int_border, char int_fill)
{ 
		if (int_size <1)
	{
	size =1;
	}
		else if (int_size >39)
		{
		size =39 ;
		}
		else {size = int_size;} 

		border=int_border;
		fill = int_fill;


	}


	Diamond(int int_size)
{ 
		if (int_size <1)
	{
	size =1;
	}
		else if (int_size >39)
		{
		size =39 ;
		}

		else{size = int_size;}
		border='#';
		fill = '*';


	}

	Diamond(int int_size, char int_border)
{ 
		if (int_size <1)
	{
	size =1;
	}
		else if (int_size >39)
		{
		size =39 ;
		}

		else{size =int_size;} 

		border=int_border;
		fill = '*';
		
	}

	
int GetSize();
int Perimeter();
double Area();

void Grow();
void Shrink();
void SetBorder(char int_border);
void SetFill(char int_fill);
void Draw ();
void Summary(); 

private:

char fill;
char border ;
int size; 

};