#include<iostream>
#include<cmath>
#include <iomanip>
#include "Diamond.h"
using namespace std;



int Diamond:: GetSize()

{
	return size;
}

int Diamond::Perimeter()

{
	return 4*size; 
}


double  Diamond :: Area()

{

return 1.732050807/2*size*size;

}

void Diamond::Grow()
	{
int size_grow;
 size_grow= size +1; 

 if (size_grow<=39)

 {size= size_grow;}


}

void Diamond::SetBorder(char int_border)
{
if ((int (int_border)<33)||(int(int_border))>126)
{
	border='#';
}
else 
{border=int_border;}
}
void Diamond::SetFill(char int_fill)
{
if ((int (int_fill)<33)||(int(int_fill))>126)
{
	fill='*';
}
else 
{fill=int_fill;}
}
void Diamond::Shrink()
	{
int size_shrink;
 
size_shrink= size -1; 

 if (size_shrink>=1)

 {
	 size= size_shrink;
 
 }

 }


void Diamond:: Draw()

{

int i; 
int j; 
int k; 

for ( i = 1; i <=size; i++) 


{

for ( j =size-i+1; j >=1;j--)
	
{ cout << " ";};

cout << border<< " ";


for (k =1; k <=i-2;k++) 
{
	cout<< fill<< " ";
}
if (i ==1) 
{cout<<endl;}
else 
{
	cout << border<<endl;}
}

cout<<" ";

for ( i = 1; i <=size-1; i++) 

{

for ( j =1; j<=i ;j++)
	
{ cout << " ";};

cout << border<< " ";

for (k =size-i-2; k >=1;k--) 
{
	cout<< fill<< " ";
}
if (i ==size-1) 
{cout<<endl;}
else 
{cout << border<<endl;
cout<< " ";}
} 
}

void Diamond::Summary()

{
	cout<<"Size of diamond's side ="<<GetSize()<<" "<<"units."<<endl;
	cout<<"Perimeter of diamond ="<<Perimeter()<<" "<<"units."<<endl;
	cout<<"Area of diamond =="<<Area()<<" "<<"units."<<endl;
	cout<<"Diamond looks like:"<<endl;
	Draw();
}
void main() 

{
// set decimal outputs to 2 decimal places
  cout << setiosflags( ios::fixed | ios::showpoint )
	<< setprecision( 2 );

  // create some Diamonds
  Diamond d1( -5 ), d2( 7, '^' ), d3( 12, 'X', 'O' ), d4( 50 , '$' , 'o');
  

  // display original Diamonds
  cout << "d1 has size = " << d1.GetSize() << " units.\n";
  d1.Draw();
  cout << "\nd2 has size = " << d2.GetSize() << " units.\n";
  d2.Draw();
  cout << "\nd3 has size = " << d3.GetSize() << " units.\n";
  d3.Draw();
  cout << "\nd4 has size = " << d4.GetSize() << " units.\n";
  d4.Draw();
  cout << '\n';

  d1.Shrink(); // demonstrate shrink
  d2.Shrink();
  d3.Grow(); // and grow
  d4.Grow();
  cout << "d1 now has size = " << d1.GetSize() << " units.\n";
  cout << "d2 now has size = " << d2.GetSize() << " units.\n";
  cout << "d3 now has size = " << d3.GetSize() << " units.\n";
  cout << "d4 now has size = " << d4.GetSize() << " units.\n";

  // demonstrate perimeter
  cout << "d2 has perimeter = " << d2.Perimeter() << " units.\n"; 
  cout << "d3 has perimeter = " << d3.Perimeter() << " units.\n"; 
  // and area
  cout << "d2 has area = " << d2.Area() << " square units.\n\n"; 
  cout << "d3 has area = " << d3.Area() << " square units.\n\n"; 

  d1.Draw();
  d1.Grow();               // show that fill character
  cout << "d1 grows:\n";   // appears only when size
  d1.Draw();               // is at least 3
  d1.Grow();
  cout << "... and grows:\n";
  d1.Draw();
  cout << '\n';

  d1 = d2; // demonstrate the default overload of the
  // assignment operator
  cout << "d1 now has size = " << d1.GetSize() << " units.\n";
  d1.Draw(); 

  // demonstrate the changing of border and fill characters
  d2.SetBorder('@');
  d2.SetFill('-');
  cout << "d2 now looks like:\n";
  d2.Draw();
  cout << '\n';
  d2.SetBorder('\n');	 // illegal border
  d2.SetFill('\a');	 // illegal fill
  cout << "d2 now looks like:\n";
  d2.Draw();
  cout << '\n';

  cout << "\nHere is a summary on d3:\n"; // demonstrate summary
  d3.Summary();
system("pause");


}