#include <stdio.h>
#include <stdlib.h>
#include "Console.h"

	

int main(void)
{

	int x = 14, y = 28;
	
	//HWND handle = GetForegroundWindow();
	SetConsoleSize(30, 30);
	
	system("title game1.exe");

	while (1) {
		Clear();
		if (GetAsyncKeyState(VK_UP) & 0x8000) {
			y--;
			if (y < 0) {
				y = 0;
			}
			
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
			y++;
			if (y > 28) {
				y = 28;
			}

		}
		if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
			x--;
			if (x < 0) {
				x = 0;
			}
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
			x++;
			if (x > 28) {
				x = 28;
			}
		} 
		
		
		GotoXY(x, y);
		printf("▲");
		Sleep(50);
	}




	system("pause");




	return 0;
}
