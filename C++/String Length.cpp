#include<iostream>
#include<string.h>
using namespace std;
int main()
	{
		string a;
		int x;
		cout<<"Enter a string ";
		getline(cin, a);
		x=a.length();
		cout<<"Length of given string = "<<x<<endl;
		return(0);
	}