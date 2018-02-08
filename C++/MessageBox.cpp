#include<windows.h>
#include<commctrl.h>
using namespace std;
int main()
{
	InitCommonControls();
	MessageBox(NULL, "Hellow World!", "Message Box", MB_OK | MB_ICONINFORMATION);
	return 0;
}
