#define _CRT_SECURE_NO_WARNINGS
#include "Console.h"
#include <windows.h>
#include <stdio.h>


void Clear(void)
{
	system("cls");
}





void SetConsoleSize(int _col, int _lines)
{
	char setText[100];
	sprintf(setText, "mode con cols=%d lines=%d", _col, _lines);
	system(setText);
}

