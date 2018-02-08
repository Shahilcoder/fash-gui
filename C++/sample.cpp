#include<iostream>
#include<windows.h>
using namespace std;
int main()
{
	InitCommonControls();
	cout<<"Message Box Example!"<<endl;
	MessageBox(NULL, "Hellow World!", "Title", MB_OK | MB_ICONINFORMATION);
	system("pause");
	return 0;
}
