#include<iostream>
#include<iomanip>
#include"store.h"
#include"book.h"
#include<cstring>
#include<cctype>
using namespace std;

void showmenu()
{
	cout << "A: Add a book to inventory" << endl;
	cout << "F: Find a book from inventory" << endl;
	cout << "S: Sell a book" << endl;
	cout << "D: Display the inventory list" << endl;
	cout << "G: Genre summary" << endl;
	cout << "M: Show this Menu" << endl;
	cout << "X: Exit the program" << endl;

}

void main()
{
	double money;
	cout << "input your money for your bookstore"<<endl;
	cin >> money;
	Store mystore(money);
	showmenu();
	char choice;
	
	do
	{
		cin >> choice;
		if (choice == 'A')
		{
			cout << "input the information of this book" << endl;
			Book newbook;
			cout << "input the title" << endl;
			char t[31];
			cin >> t;
			cout << "input the author name" << endl;
			char a[21];
			cin >> a;
			cout << "input the Genre" << endl;
			char g;
			Genre g0;
			do{
				cin >> g;
				g = toupper(g);
				switch (g)
				{
				case 'F': g0 = Genre(0); break;
				case 'M': g0 = Genre(1); break;
				case 'S': g0 = Genre(2); break;
				case 'C': g0 = Genre(3); break;
                default:
					cout << "No such Genre,type again" << endl;
					break;
				}
			} while ((g != 'F') && (g != 'S') && (g != 'C') && (g != 'M'));
			
			cout << "input the price" << endl;
			double p;
			cin >> p;
			newbook.Set(t, a, g0, p);
			mystore.add(newbook);
			cout << "input option" << endl;
			
		}
		else if (choice == 'F')
		{
			cout << "input the title or the name of author" << endl;
			char name[31];
			cin >> name;
			mystore.lookup(name);
			cout << "input option" << endl;
		}
		else if (choice == 'S')
		{
			cout << "input the title of the selling book" << endl;
			char t[31];
			cin >> t;
			mystore.sell(t);
			cout << "input option" << endl;
		}
		else if (choice == 'D')
		{
			mystore.display();
			cout << "input option" << endl;
		}
		else if (choice == 'G')
		{
			cout << "input the Genre you wanna to see" << endl;
			char g;
			Genre g0;
            cin >> g;
		    g=toupper(g);
			switch (g)
			{
			case 'F':g0 = Genre(0); mystore.Genredisp(g0); break;
			case 'M':g0 = Genre(1); mystore.Genredisp(g0); break;
			case 'S':g0 = Genre(2); mystore.Genredisp(g0); break;
			case 'C':g0 = Genre(3); mystore.Genredisp(g0); break;
            default:
				cout << "no such Genre" << endl;
				break;
			}

			cout << "input option" << endl;
		}
		else if (choice == 'M')
		{
			showmenu();
		}
		else if (choice == 'X')
			break;
		else
			cout << "invalid option,input again" << endl;
	


	} while (choice != 'X');

}