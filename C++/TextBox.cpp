#include <windows.h>
#define ID_BTN 1							//Defined the Button Type
#define ID_TEXTBOX 2						
static HWND hwndTextbox;					//HWND is a Data type provided by Windows.h
//EVERYTHING IS CASE SENSITIVE! REMEMBER IT! //

LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	switch(Message) {
		case WM_CREATE:{
			CreateWindow(TEXT("STATIC"), TEXT("Enter any text"), 			//First TEXT is the Type of the box, Second Text is the Caption.
				WS_VISIBLE | WS_CHILD, 										//Style of the Text
				50, 30,														//Coordinates of the box on the screen
				200, 20,													//Size of the box
				hwnd, (HMENU) NULL, NULL, NULL								//HMENU NULL for no ID or simple text box
				
			);
		    hwndTextbox = CreateWindow(TEXT("EDIT"), TEXT(""),				//"EDIT" for Editable Text Box. "STATIC" for non-editable text box
				WS_VISIBLE | WS_CHILD | WS_BORDER| ES_AUTOHSCROLL,			//WS_BORDER makes a 1 pixel border, AUTOHSCROLL to expand the limit of the box
				50, 50,														// x-coordinate, y-coordinate
				200, 20,													//width, height
				hwnd, (HMENU) ID_TEXTBOX, NULL, NULL						//(HMENU) ID_TEXTBOX declares the ID of the Window, i.e. a text box
			);
			
			CreateWindow(TEXT("button"), TEXT("Click Me"),					//"button" for clickable button
				WS_VISIBLE | WS_CHILD,
				50, 80,
				200, 20,
				hwnd, (HMENU) ID_BTN, NULL, NULL
			);
						
			break;
		}		
		case WM_COMMAND:{													//Set Command of the Box
			// actions for default button
			if(LOWORD(wParam == ID_BTN)){									//Fixed Syntax. I don't know why :P
						
				// create some default vars
				int len= GetWindowTextLength(hwndTextbox) +1;
				static char title[500];
				
				GetWindowText(hwndTextbox, title, len);						// 3 Parameters for GetWindowText: HWND Type, String, Length
				MessageBox(hwnd, title, "Message Box", MB_OK);				//MB_OK for OK Type Button on Message Box. Last Parameter is the style of box
				SetWindowText(hwnd, title );								//Sets the text on text box to the message box
				
			}
			
			
			break;
		}
		
		case WM_DESTROY: {
			PostQuitMessage(0);
			break;
		}
		
		/* All other messages (a lot of them) are processed using default procedures */
		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}

/* The 'main' function of Win32 GUI programs: this is where execution starts */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASSEX wc; /* A properties struct of our window */
	HWND hwnd; /* A 'HANDLE', hence the H, or a pointer to our window */
	MSG msg; /* A temporary location for all messages */

	/* zero out the struct and set the stuff we want to modify */
	memset(&wc,0,sizeof(wc));
	wc.cbSize		 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = WndProc; /* This is where we will send messages to */
	wc.hInstance	 = hInstance;
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);
	
	
	wc.hbrBackground = GetSysColorBrush(COLOR_3DFACE);  				//Change Colour
	wc.lpszClassName = "WindowClass";
	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION); /* Load a standard icon */
	wc.hIconSm		 = LoadIcon(NULL, IDI_APPLICATION); /* use the name "A" to use the project icon */

	if(!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	hwnd = CreateWindowEx(
		WS_EX_CLIENTEDGE,
		"WindowClass",
		"Text Tutorial",
		WS_VISIBLE|WS_OVERLAPPEDWINDOW,  //Window Style: OVERLAPPEDWINDOW= Changable Size, SYSMENU= Fixed Size
		CW_USEDEFAULT, /* x */
		CW_USEDEFAULT, /* y */
		640, /* width */
		480, /* height */
		NULL,NULL,hInstance,NULL);

	if(hwnd == NULL) {
		MessageBox(NULL, "Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	/*
		This is the heart of our program where all input is processed and 
		sent to WndProc. Note that GetMessage blocks code flow until it receives something, so
		this loop will not produce unreasonably high CPU usage
	*/
	while(GetMessage(&msg, NULL, 0, 0) > 0) { /* If no error is received... */
		TranslateMessage(&msg); /* Translate key codes to chars if present */
		DispatchMessage(&msg); /* Send it to WndProc */
	}
	return msg.wParam;
}
