#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	
	ofstream file;
	file.open("test.txt");
		file<<"Hello!";
	file.close();
	
	cout<<"File has been written!";
	system("pause");
	return 0;
	
}
