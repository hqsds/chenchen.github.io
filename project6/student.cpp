#include<iostream>
#include<cstring>
#include<cctype>
#include<string>
#include"student.h"
using namespace std;

student::student(char* f, char* l)
{
	strcpy_s(firstname,20,f);
	strcpy_s(lastname,20,l);
	finalgrade = 0;
}


student::~student()
{
	delete[] grade;
}

char* student::getfirstname()
{
	return firstname;
}

char* student::getlastname()
{
	return lastname;
}


int student::getfinal()
{
	return finalgrade;
}

char student::lettergrade()
{
	double g;
	char l;
	g = finalaverage();
	if (g >= 90)
		l = 'A';
	else if (g >= 80 && g < 90)
		l = 'B';
	else if (g >= 70 && g < 80)
		l = 'C';
	else if (g >= 60 && g < 70)
		l = 'D';
	else if (g < 60)
		l = 'F';
	return l;
}

Subject student::getcourse()
{
	return course;
}
//english student
engstudent::engstudent(char* f, char* l, Subject s, int g1, int g2, int g3, int g4) :student(f, l)
{
	course= s;
	finalgrade = g4;
	grade = new int[4];
	grade[0] = g1;
	grade[1] = g2;
	grade[2] = g3;
	grade[3] = g4;
}

double engstudent::finalaverage()
{
	double score;
	score =0.1*grade[0] + 0.3*grade[1] + 0.3*grade[2] + 0.3*grade[3];
	return score;
}


//history student
histstudent::histstudent(char* f, char* l, Subject s, int g1, int g2, int g3) :student(f,l)
{
	course = s;
	finalgrade = g3;
	grade = new int[3];
	grade[0] = g1;
	grade[1] = g2;
	grade[2] = g3;
}

double histstudent::finalaverage()
{
	double score;
    score = 0.25*grade[0] + 0.35*grade[1] + 0.4*grade[2];
	return score;
}


//math student
mathstudent::mathstudent(char* f, char* l, Subject s, int g1, int g2, int g3, int g4, int g5, int g6, int g7, int g8) :student(f,l)
{
	course = s;
	finalgrade = g8;
	grade = new int[8];
	grade[0] = g1;
	grade[1] = g2;
	grade[2] = g3;
	grade[3] = g4;
	grade[4] = g5;
	grade[5] = g6;
	grade[6] = g7;
	grade[7] = g8;
}

double mathstudent::finalaverage()
{
	double score;
	score = (grade[0] + grade[1] + grade[2] + grade[3] + grade[4])* 0.15 / 5 + grade[5] * 0.25 + grade[6] * 0.25 + grade[7] * 0.35;
	return score;

}
















