#include<iostream>
using namespace std;

int convert(int x)
{
	int d, bi=1;
	do
	{
		d=x%2;
		if(d==1)
		{
			bi= (bi*10) + 1;
		}
		else
		{
			bi= bi*10;
		}
		x/=2;
	}
	while(x!=0);
	return(bi);
}
int reverse(int y)
{
	int k;
	k=convert(y);
	int n, n1, s=0;
	n=k;
	do
	{
		n1=k%10;
		k/=10;
		s=s*10 + n1;	
	}
	while(k!=0);
	s=s-1;
	s=s/10;
	return(s);
}

int main()
{
	int n;
	cout<<"Enter any integer number: ";
	cin>>n;
	cout<<"The Binary form is "<<reverse(n);
	cout<<endl;
	return(0);
}