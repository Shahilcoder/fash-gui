#include <iostream>
#include <windows.h>
#include <cstdio>
#include <cstdlib>
#include <string.h>
using namespace std;

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);

class Fash{
	public:
		
		string msg, ttl;
		int height, width;
		char title[100];
		char message[100];
		
		//------------------winapi variables-----------------------------
		HINSTANCE hInst;
		HINSTANCE hPrevInst;
		LPSTR args;
		int ncmdshow;
		//-------------------------------------------------------------------

		void MakeWindow(int, int);
		void ShowMessage(string, string);
		
		//-------------------------------------the Winapi function---------------------------
		int WINAPI WinMsg(HINSTANCE, HINSTANCE, LPSTR, int)
		{
			MessageBox(NULL, message, title, MB_OK);
	
			return 0;
	
		}
		//--------------------------------------------------------------------------------------
		//------------------------second one-------------------------------------------------
		
		int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int, int height, int width)
		{
			WNDCLASSW wc = {0};
			
			wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
			wc.hCursor = LoadCursor(NULL, IDC_ARROW);
			wc.hInstance = hInst;
			wc.lpszClassName = L"myWindowClass";
			wc.lpfnWndProc = WindowProcedure;
			
			if(!RegisterClassW(&wc))
				return -1;
			
			CreateWindowW(L"myWindowClass", L"My Window", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100,100,width,height, NULL, NULL, NULL, NULL);
			
			MSG msg = {0};
			
			while( GetMessage(&msg,NULL,NULL,NULL) )
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			
			return 0;
		}
}Fash;

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
	switch( msg)
	{
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProcW(hWnd, msg, wp, lp);
	}
}


//------------------------Definition of ShowMessage function---------------------------------------------------------------
void Fash::ShowMessage(string ttl, string msg)
{
	strcpy(title, ttl.c_str());
	strcpy(message, msg.c_str());

	WINAPI WinMsg(hInst, hPrevInst, args, ncmdshow);
}
//------------------------------
void Fash::MakeWindow(int height, int width)
{
	WINAPI WinMain(hInst, hPrevInst, args, ncmdshow, height, width);
}
