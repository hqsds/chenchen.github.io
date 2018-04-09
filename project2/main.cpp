# include <iostream>
# include <iomanip>
# include <string>
# include "date.h"

using namespace std;

void main()
{
Date d1;		// should default to 1/1/2000

Date d2(12,31,2013);  // should init to 4/10/1992

   // display dates to the screen
   cout << "\nDate d1 is: ";
   d1.Show();			
   cout << "\nDate d2 is: ";
   d2.Show();

   //d1.Input();			// Allow user to enter a date for d1
   cout << "\nDate d1 is: ";
   d1.Show();			
//   
   d2.SetFormat('T');		// change format of d1 to "Long" format
   cout << "\nDate d1 is: ";
   d2.Show();			// print d1 -- should show now in long format;
 
d1.input();
d1.Show();

d2.Increment();
d2.Show();
d2.Increment(400);
d2.Show();

d1.Show();
d2.Show();
cout<<endl;

cout<< d1.compare(d2)<<"\n";
cout<<d2.compare(d1)<<"\n";

}
