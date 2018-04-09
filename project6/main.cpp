#include<iostream>
#include<fstream>
#include<cstring>
#include<cctype>
#include<iomanip>
#include"student.h"
using namespace std;

int subnum(char* c);
ofstream& display(ofstream& fileout);
int main()
{
	//char filenamein[10];
	char filenameout[10];
	ifstream filein;
	ofstream fileout;

	filein.open("grade.txt");
	if (!filein)
	{
		cout << "open file failed\n";
		exit(1);

	}
	cout << "Please enter the name of the output file. \n";
	cout << "Filename: ";
	cin >> filenameout;

	fileout.open(filenameout);
	
	int stnum;//student number
	//char stnum0;
	filein>>stnum;
	filein.ignore(INT_MAX,'\n');
	student** stlist=new student*[stnum];
	
	char firstname0[20];
	char firstname[20];
	char lastname[20];
	Subject course;
	char course0[10];
	int cc;
	int g1, g2, g3, g4, g5, g6, g7, g8;
for (int i = 0; i < stnum; i++)
	{
	filein.getline(lastname,20, ',');
	filein.ignore();
	filein.getline(firstname0,20);
	strcpy_s(firstname, 20, firstname0);
	filein >> course0;
	
		
		cc = subnum(course0);
	
		switch (cc)
		{
		case 1:
		{
		course = Subject(0);
		filein >> g1 >> g2 >> g3 >> g4;
		filein.ignore(INT_MAX, '\n');
		stlist[i] = new engstudent(firstname, lastname, course, g1, g2, g3, g4);
		 
		}
			break;
		case 2:
		{
		filein >> g1 >> g2 >> g3;
		filein.ignore(INT_MAX, '\n');
		course = Subject(1);
		stlist[i] = new histstudent(firstname, lastname, course, g1, g2, g3);
		 
		}
			break;
		case 3:
		{
			filein >> g1 >> g2 >> g3 >> g4 >> g5 >> g6 >> g7 >> g8;
			filein.ignore(INT_MAX, '\n');
			course = Subject(2);
			stlist[i] = new mathstudent(firstname, lastname, course, g1, g2, g3, g4, g5, g6, g7, g8);
		
		}
			break;
		default:
			break;
		}
	}

	fileout << "Student Grade Summary\n";
	fileout << "----------------------\n\n\n";
	fileout <<left<< "ENGLISH CLASS\n\n";
	display(fileout);
	char name[40];
	for (int i = 0; i < stnum; i++)
	{
		
		if ((stlist[i])->getcourse() == Subject(0))
		{
			strcpy_s(name, 40, stlist[i]->getfirstname());
			strcat_s(name, 40, " ");
			strcat_s(name, 40, stlist[i]->getlastname());
			fileout << left << setw(31) << name;
			fileout << setw(10) << (stlist[i]->getfinal()) <<setprecision(2)<<fixed<<setw(10) << stlist[i]->finalaverage() << setw(10)
				<< stlist[i]->lettergrade() << '\n';
		}
		
	}
	
	fileout << "\n\nHISTORY CLASS\n\n";
	display(fileout);

	for (int i = 0; i < stnum; i++)
	{
		if ((stlist[i])->getcourse() == Subject(1))
		{
			
			strcpy_s(name, 40, stlist[i]->getfirstname());
			strcat_s(name, 40, " ");
			strcat_s(name, 40, stlist[i]->getlastname());
			fileout << left << setw(31) << name;
			fileout << setw(10) << stlist[i]->getfinal() << setw(10)<<setprecision(2) << fixed << stlist[i]->finalaverage() << setw(10)
				<< stlist[i]->lettergrade() << '\n';
		}
	}
	
	fileout << "\n\nMATH CLASS\n\n";
	display(fileout);
	for (int i = 0; i < stnum; i++)
	{
		if ((stlist[i])->getcourse() == Subject(2))
		{
			strcpy_s(name, 40, stlist[i]->getfirstname());
			strcat_s(name, 40, " ");
			strcat_s(name, 40, stlist[i]->getlastname());
			fileout << left << setw(31) << name;
			fileout << setw(10) << stlist[i]->getfinal() << setw(10)<<setprecision(2) << fixed << stlist[i]->finalaverage()
				<< setw(10) << stlist[i]->lettergrade() << '\n';
		}
		
	}

	
	filein.close();
	fileout.close();

	delete[] stlist;
	return 0;


}

int subnum(char* c)
{
	int n;
	if (strcmp(c, "English") == 0)
		n=1;
	else if (strcmp(c, "History") == 0)
		n=2;
	else if (strcmp(c, "Math") == 0)
		n=3;
	return n;
}


ofstream& display(ofstream& fileout)
{
	fileout << left << setw(31) << "Student";
	fileout << setw(10) << "Final" << setw(10) << "Final" << setw(10) << "Letter" << '\n';
	fileout << left << setw(31) << "Name";
	fileout << setw(10) << "Exam" << setw(10) << "Avg" << setw(10) << "Grade" << '\n';
	fileout << "--------------------------------------------------------\n";
	return fileout;
}










