#include<iostream.h>
#include<string.h>
using namespace std;
int main()
{
	string s1;
		getline(cin, s1);
	string s2="", s3="";
	s1=s1+' ';
	int x=s1.length();
	cout<<endl<<x<<endl;
	for(int i=0; i<x ; i++)
		{
			if(s1[i]!=' ')
			s2=s2+s1[i];
			else
			{
			s3=s2+" "+s3;
			s2=' ';
			}
		}
	cout<<s1<<endl;
	cout<<s3<<endl;
	return(0);
}
