#include<iostream.h>
#include<string.h>
using namespace std;
int main()
{
	string s1, rev;
	int i=0, x;
		cout<<" Please Enter a string (case sensitive) ";
		getline(cin, s1);
	x=s1.length();
	do
		{
		rev=rev + s1[x-1];
		x--;
		}
	while(x!=0);
		cout<<"The reversed string is \" "<<rev<<"\""<<endl;
	if(rev==s1)
		cout<<"The string is a Palindrome"<<endl;
	else
		cout<<"The string is not a Palindrome"<<endl;
	return(0);
}
