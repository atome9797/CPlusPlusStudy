#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Console.h"

	

int main(void)
{

	
	//HWND handle = GetForegroundWindow();
	SetConsoleSize(100, 30);
	
	system("title game1.exe");

	
	//시작 메뉴 구현
	printf("┏----------------------------------------┓\n");
	printf("┃                                        ┃\n");
	printf("┃              모험가의 여정             ┃\n");
	printf("┃                                        ┃\n");
	printf("┃      화살표로 메뉴를 선택해주세요.     ┃\n");
	printf("┗----------------------------------------┛\n");

	int start_location = 1; //1. 게임 시작 , 2. 조작법,  3.게임 종료

	printf("▷1.게임 시작\n");
	printf("2.조작법\n");
	printf("3.게임 종료\n");



	//종료 여부
	bool finish_game = false;
	char pointer ='A';

	do {
		
		//커서이동을 위한 위아래 입력 받기
		pointer = _getch();


		//키보드 입력값
		/*
			엔터 13
			위  : H
			아래  : P
		*/

		//좌표값으로 계산해야함
		switch (pointer) {
			case 'H': {//위

				if (start_location > 1) {
					start_location -= 1;
				}

				break;
			}
			case 'P': {//아래
				
				if (start_location < 3) {
					start_location += 1;
				}

				break;
			}		
			case 13 : {//엔터
				//x좌표의 위치에 따라 이동하는 페이지가 다르게 설정
				
				break;
			}
		}


		//메뉴
		for (int i = 0; i < 3; i++)
		{
			if (start_location == i) {
				
			}
		}
		


	} while (!finish_game);
	



	system("pause");




	return 0;
}
