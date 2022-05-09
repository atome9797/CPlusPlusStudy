#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Console.h"

typedef struct 	user_point {
	int start_location[3];
	int user_x;
	bool finish_game;
	char pointer;
}User_point;

void three_menu(int num) {
	switch (num) {
	case 0: {
		game_start();
		break;
	}
	case 1: {
		game_manual();
		break;
	}
	case 2: {
		game_finish();
		break;
	}
	}
}

int first_menu(void) {
	
	User_point usp = { 0 };
	//1. 게임 시작 , 2. 조작법,  3.게임 종료
	usp.start_location[0] = 1;
	usp.start_location[1] = 0;
	usp.start_location[2] = 0;
	//0 0 0
	usp.user_x = 0;
	//종료 여부
	usp.finish_game = false;
	usp.pointer = 'A';

	do {

		//시작 메뉴 구현
		printf("┏----------------------------------------┓\n");
		printf("┃                                        ┃\n");
		printf("┃              모험가의 여정             ┃\n");
		printf("┃                                        ┃\n");
		printf("┃      화살표로 메뉴를 선택해주세요.     ┃\n");
		printf("┗----------------------------------------┛\n");


		for (int i = 0; i < 3; i++)
		{
			if (usp.start_location[i] == 1) {
				printf("▷");
			}
			if (i == 0) {
				printf("1.게임 시작\n");
			}
			else if (i == 1) {
				printf("2.조작법\n");
			}
			else if (i == 2) {
				printf("3.게임 종료\n");
			}
		}

		//커서이동을 위한 위아래 입력 받기
		usp.pointer = _getch();


		//키보드 입력값
		/*
			엔터 13
			위  : H
			아래  : P
		*/

		//좌표값으로 계산해야함
		switch (usp.pointer) {
			case 'H': {//위

				if (usp.user_x > 0) {
					usp.user_x -= 1; //1,2,3
					for (int i = 0; i < 3; i++)
					{
						if (usp.user_x == i) {
							usp.start_location[i] = 1;
						}
						else {
							usp.start_location[i] = 0;
						}
					}
				}

				break;
			}
			case 'P': {//아래

				if (usp.user_x < 2) {
					usp.user_x += 1;
					for (int i = 0; i < 3; i++)
					{
						if (usp.user_x == i) {
							usp.start_location[i] = 1;
						}
						else {
							usp.start_location[i] = 0;
						}
					}
				}

				break;
			}
			case 13: {//엔터
				usp.finish_game = true;
				break;
			}
		}

		system("cls");

	} while (!usp.finish_game);

	//x좌표의 위치에 따라 이동하는 페이지가 다르게 설정
	//three_menu(usp.user_x);
	//three_menu(0);
	return usp.user_x;
}

void game_start(void) {
	printf("asdasd");
}

void game_manual(void) {
	
	//User_point usp2 = {0};
	//usp2.start_location[0] = 1;
	//usp2.start_location[1] = 0;
	//usp2.start_location[2] = 0;
	////0 0 0
	//usp2.user_x = 0;
	////종료 여부
	//usp2.finish_game = false;
	//usp2.pointer = 'A';


	//do {

	//	printf("┏----------------------------------------┓\n");
	//	printf("┃                                        ┃\n");
	//	printf("┃             키 조작 : → ← ↑ ↓          ┃\n");
	//	printf("┃									     ┃\n");
	//	printf("┗----------------------------------------┛\n");


	//	for (int i = 0; i < 3; i++)
	//	{
	//		if (usp2.start_location[i] == 1) {
	//			printf("▷");
	//		}
	//		if (i == 0) {
	//			printf("1.게임 시작\n");
	//		}
	//		else if (i == 2) {
	//			printf("2.게임 종료\n");
	//		}
	//	}

	//	//커서이동을 위한 위아래 입력 받기
	//	usp2.pointer = _getch();


	//	//키보드 입력값
	//	/*
	//		엔터 13
	//		위  : H
	//		아래  : P
	//	*/

	//	//좌표값으로 계산해야함
	//	switch (usp2.pointer) {
	//		case 'H': {//위

	//			if (usp2.user_x > 0) {
	//				usp2.user_x -= 1; //1,2,3
	//				for (int i = 0; i < 3; i++)
	//				{
	//					if (usp2.user_x == i) {
	//						usp2.start_location[i] = 1;
	//					}
	//					else {
	//						usp2.start_location[i] = 0;
	//					}
	//				}
	//			}

	//			break;
	//		}
	//		case 'P': {//아래

	//			if (usp2.user_x < 2) {
	//				usp2.user_x += 1;
	//				for (int i = 0; i < 3; i++)
	//				{
	//					if (usp2.user_x == i) {
	//						usp2.start_location[i] = 1;
	//					}
	//					else {
	//						usp2.start_location[i] = 0;
	//					}
	//				}
	//			}

	//			break;
	//		}
	//		case 13: {//엔터
	//			usp2.finish_game = true;
	//			break;
	//		}
	//	}

	//	system("cls");

	//} while (!usp2.finish_game);


	//three_menu(usp2.user_x);
	
}

void game_finish(void) {
	printf("게임 종료\n");
}


int main(void)
{

	
	//HWND handle = GetForegroundWindow();
	SetConsoleSize(100, 30);
	system("title game1.exe");

	int num = first_menu();
	switch (num) {
	case 0: {
		game_start();
		break;
	}
	case 1: {
		game_manual();
		break;
	}
	case 2: {
		game_finish();
		break;
	}
	}

	//system("pause");

	return 0;
}



