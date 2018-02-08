#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

int main()
{
	START:
	system("cls");
	cout<<"Enter Password:";
	char pass[32];
	int i=0; char a;
	for(i=0 ;;) // infinite loop
	{
		a=getch();
		if((a>='a' && a<='z') || (a>='A' && a<='Z') || (a>='0' && a<='9'))
		// check if a is a number or alphabet
		{
			pass[i]=a; //stores a in pass;
			++i;
			cout<<"*";
		}
		if(a=='\b' && i>=1) // if user typed backspace
		{
			cout<<"\b \b";
			--i;
		}
		if(a=='\r') // if enter is pressed
		{
			pass[i]='\0';
			break;
		}
	}
	if(i<=5)
	{
		cout<<endl<<"Minimum 6 digits needed."<<endl<<"Enter again"<<endl;
		system("pause");
		goto START;
	}
	return 0;
}
