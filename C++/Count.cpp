#include<iostream>
#include<stdlib.h>
#include<cstdio>
using namespace std;

int main()
{
	char a[1000];
	int x=1, i=0;
	gets(a);
	while(i != '\0')
	{
		if(a[i] == ' ')
		x++;
		else
		continue;
		i++;
	}
	cout<<"The Number of words is "<<x;
}
