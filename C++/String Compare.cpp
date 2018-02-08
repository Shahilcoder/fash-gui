#include<iostream>
#include<string.h>
using namespace std;
int main()
	{
		string s1, s2;
		int x;
		cout<<"Enter a string ";
		getline(cin, s1);
		cout<<"Enter another string ";
		getline(cin, s2);
		cout<<"\nThe Strings are "<<s1<<" ---AND--- "<<s2<<endl;
		x= s1.compare(s2);
		if(x==0)
		{
			cout<<"The Given strings are equal"<<endl;
		}
		else
		cout<<"The Given Strings are not equal"<<endl;
		return(0);	
	}