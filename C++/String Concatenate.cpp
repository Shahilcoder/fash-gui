#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	string s1, s2, s3;
	cout<<"Enter a string ";
	getline(cin, s1);
	cout<<"\nEnter another string ";
	getline(cin, s2);
	s3 = s1 + s2;
	cout<<s3<<endl;
	return(0);	
}