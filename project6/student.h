#include<iostream>
using namespace std;

enum Subject { English, History, Math };

class student
{
protected:
	char firstname[20];
	char lastname[20];
	Subject course;
	int* grade;
	int finalgrade;
public:
	student(char* f,char* l);
	Subject getcourse();
	int getfinal();//get final grade
	virtual double finalaverage()=0;  //compute final average grade
	char lettergrade();   //give the final letter grade
	char* getfirstname();
	char* getlastname();
	~student();
};

class engstudent : public student
{

public:
	engstudent(char* ,char* ,Subject c,int g1,int g2,int g3, int g4);
	double finalaverage();
	int getfinal();
	
};

class histstudent : public student
{
public:
	histstudent(char*, char*, Subject c, int g1, int g2, int g3);
	double finalaverage();
	int getfinal();
	
};

class mathstudent :public student
{
public:
	mathstudent(char*, char*, Subject c, int g1, int g2, int g3, int g4,int g5,int g6,int g7,int g8);
	double finalaverage();
	int getfinal();
	
};