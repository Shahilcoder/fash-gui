#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	string s1;
	int c=0, k=0, j=1;
	cout<<"Enter a sentence ";
	getline(cin, s1);
	s1=' '+s1;
	int x=s1.length();
	cout<<""<<endl;
	for(int i=0 ; i<x ; i++)
		{
			
				if(s1[k]==' ' && s1[j]!=' ')
				c=c+1;
				j++;
				k++;
			
		}
	cout<<c<<endl;
	return(0);
}