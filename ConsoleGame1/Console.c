#define _CRT_SECURE_NO_WARNINGS
#include "Console.h"
#include <windows.h>
#include <stdio.h>


void Clear(void)
{
	system("cls");
}


void GotoXY(int _x, int _y)
{
	//커서 이동 함수
	COORD pos = { _x, _y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


void SetConsoleSize(int _col, int _lines)
{
	char setText[100];
	sprintf(setText, "mode con cols=%d lines=%d", _col, _lines);
	system(setText);
}

