#include<iostream>
#include<iomanip>
#include<cctype>
#include<cstring>
#include"stack.h"
using namespace std;
int main()
{
	char s[100], s1[100];
	Stack<char> sta;
	int i, j, k; int g;
	i = j = k = 0;
	cout << "Please enter a string:\n";
	cin.getline(s, 100);
	while (s[i])
	{
		g = s[i];
		if (isalpha(g))
		{
			s1[j] = toupper(s[i]);
			sta.push(s1[j]);
			j++;
		}
		i++;

	}

	
	char* s3 = new char[j];
	char* s4 = new char[j];
	for (int l = 0; l<j; l++)
	{
		s3[l] = s1[l];
	}

	while (!sta.isStackEmpty())
	{
		sta.pop(s4[k]);
		k++;
	}
	
	if (strcmp(s3, s4) == 0)
	cout <<'"'<<s<<'"'<<" IS a palindrome\n";
	else
	cout <<'"'<< s<<'"' << " is NOT palindrome\n";
	delete[] s3;
	delete[] s4;
	return 0;

}
