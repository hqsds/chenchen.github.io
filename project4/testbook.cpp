#include<iostream>
#include"book.h"
using namespace std;
void main()
{
	
	Book math;
	const char* t;
	const char* a;
	char tt[20] = "introduction";
	char aa[20] = "vastola";
	t = tt;
	a = aa;
	double p=10.898;
	Genre g =SCIFI;
	math.Set(t,a,g,p);
	math.Display();



}