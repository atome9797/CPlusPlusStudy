#include <iostream>
#include <string>
#include <conio.h>


using namespace std;


//게임에 관한 구조체 game
struct game{
	
	int map_width; //맵 너비
	int map_height; // 맵 높이
	char array_game[10][10]; //게임에 저장되는 맵의 데이터를 저장하는 공간
	int random_fin ; //난수를 받는 공간 2 ~99
	int random_fin_quotient;  //난수의 몫 : y좌표값
	int random_fin_remain; //난수의 나머지 : x좌표값
	bool finish_game; // 도착 지점에 도착했는지 안했는지 판단
	bool died;//죽음
	char input_user_control; //유저 입력값
	int user_point[2] = { 0,0 }; //출발지점 => main함수전에 초기값 까지 설정해줘야함
	int player_hp = 20;
	int random_swamp;
	int cnt;
};


int main() {

#pragma region 콘솔용탈출게임


	//입력 : 
	game kimyounghoon; //구조체 변수 선언
	
	kimyounghoon.map_width = 10;
	kimyounghoon.map_height = 10;
	srand(time(NULL));
	kimyounghoon.random_fin = rand() % 99 + 1; //도착 지점을 난수로 받는다 (0 ~ 99 숫자중 1부터 99까지 받는다)
	//난수의 몫과 나머지를 구해 i j 좌표로 설정한다.
	kimyounghoon.random_fin_quotient = kimyounghoon.random_fin / 10; //몫
	kimyounghoon.random_fin_remain = kimyounghoon.random_fin % 10; //나머지
	kimyounghoon.finish_game = false;// 도착 지점에 도착했는지 안했는지 판단
	kimyounghoon.died = false;// 죽었는지 판단
	kimyounghoon.input_user_control = 'A'; //임의의 변수값 설정

	kimyounghoon.random_swamp = rand() % 4;// 0~3까지의 늪/숲 구간 시작점을 추출
	
	kimyounghoon.cnt = 0;

	//키보드 입력값 
	/*
		->  : M
		<-  : K
		위  : H
		아래  : P
	*/

	//처리 :






	//도착 지점에 도달했는지 안했는지 판단 하고 도착했으면 반복문을 빠져 나오도록 설정
	do {

		//user_point[1] -> x좌표
		//user_point[0] -> y좌표

		cout << "user_point : " << kimyounghoon.user_point[1] << " , " << kimyounghoon.user_point[0] << endl;
		cout << "random_fin_remain , random_fin_quotient :  " << kimyounghoon.random_fin_remain << " , " << kimyounghoon.random_fin_quotient << endl;
		cout << "체력 : " << kimyounghoon.player_hp << endl;
		cout << "피로도 : " << 20 - kimyounghoon.player_hp << endl;
		cout << "늪 : " << kimyounghoon.random_swamp << endl;

		cout << "이동 포인트 : " << kimyounghoon.cnt << endl;

		//맵의 정보를 저장해둠
		for (int i = 0; i < kimyounghoon.map_height; i++) {
			for (int j = 0; j < kimyounghoon.map_width; j++) {
				kimyounghoon.array_game[i][j] = '#';
			}
		}


		//오브젝트의 위치를 지정한다.

		//숲 위치 지정 -> 범위는 3X3으로 고정
		for (int i = kimyounghoon.random_swamp; i < kimyounghoon.random_swamp+3; i++) {
			for (int j = kimyounghoon.random_swamp; j < kimyounghoon.random_swamp+3; j++)  { //늪 시작 위치
				kimyounghoon.array_game[i][j] = '*';
			}
		}

		//늪 위치 지정 random_swamp=9
		for (int i = kimyounghoon.random_swamp + 3; i < kimyounghoon.random_swamp + 6; i++) {
			for (int j = kimyounghoon.random_swamp + 3; j < kimyounghoon.random_swamp + 6; j++) {
				kimyounghoon.array_game[i][j] = '@';
			}
		}

		//유저위치 지정
		int y = kimyounghoon.user_point[0];
		int x = kimyounghoon.user_point[1];
		kimyounghoon.array_game[x][y] = 'O';

		//출구 위치 지정
		kimyounghoon.array_game[kimyounghoon.random_fin_remain][kimyounghoon.random_fin_quotient] = 'E';
				

		//오브젝트와 맵이 결합한 형태의 전체 배열값을 추출
		for (int i = 0; i < kimyounghoon.map_height; i++) {
			for (int j = 0; j < kimyounghoon.map_width; j++) {
				cout << kimyounghoon.array_game[i][j];
			}
			cout << endl;
		}

		//입력 받은 맵에서 화살표 이동
		kimyounghoon.input_user_control = _getch();
		switch (kimyounghoon.input_user_control) {

		case 'M':
			if (kimyounghoon.user_point[0] <= 8 && kimyounghoon.user_point[0] >= -1) {
				kimyounghoon.user_point[0] += 1;
				kimyounghoon.player_hp -= 1 ;
				kimyounghoon.cnt += 1;

				for (int i = kimyounghoon.random_swamp; i < kimyounghoon.random_swamp + 3; i++) {
					for (int j = kimyounghoon.random_swamp; j < kimyounghoon.random_swamp + 3; j++) { //늪 시작 위치
						if (kimyounghoon.user_point[0] == i && kimyounghoon.user_point[1] == j) {
							kimyounghoon.player_hp -= 1;
							kimyounghoon.cnt += 1;
						}
					}
				}
				for (int i = kimyounghoon.random_swamp + 3; i < kimyounghoon.random_swamp + 6; i++) {
					for (int j = kimyounghoon.random_swamp + 3; j < kimyounghoon.random_swamp + 6; j++) { //늪 시작 위치
						if (kimyounghoon.user_point[0] == i && kimyounghoon.user_point[1] == j) {
							kimyounghoon.player_hp -= 2;
							kimyounghoon.cnt += 2;
						}
					}
				}
			}
			break; //->
		case 'K':
			if (kimyounghoon.user_point[0] <= 9 && kimyounghoon.user_point[0] > 0) {
				kimyounghoon.user_point[0] -= 1;
				kimyounghoon.player_hp -= 1 ;
				kimyounghoon.cnt += 1;

				for (int i = kimyounghoon.random_swamp; i < kimyounghoon.random_swamp + 3; i++) {
					for (int j = kimyounghoon.random_swamp; j < kimyounghoon.random_swamp + 3; j++) { //늪 시작 위치
						if (kimyounghoon.user_point[0] == i && kimyounghoon.user_point[1] == j) {
							kimyounghoon.player_hp -= 1;
							kimyounghoon.cnt += 1;
						}
					}
				}
				for (int i = kimyounghoon.random_swamp + 3; i < kimyounghoon.random_swamp + 6; i++) {
					for (int j = kimyounghoon.random_swamp + 3; j < kimyounghoon.random_swamp + 6; j++) { //늪 시작 위치
						if (kimyounghoon.user_point[0] == i && kimyounghoon.user_point[1] == j) {
							kimyounghoon.player_hp -= 2;
							kimyounghoon.cnt += 2;
						}
					}
				}
			}
			break; //<-
		case 'H':
			if (kimyounghoon.user_point[1] <= 9 && kimyounghoon.user_point[1] > 0) {
				kimyounghoon.user_point[1] -= 1;
				kimyounghoon.player_hp -= 1 ;
				kimyounghoon.cnt += 1;

				for (int i = kimyounghoon.random_swamp; i < kimyounghoon.random_swamp + 3; i++) {
					for (int j = kimyounghoon.random_swamp; j < kimyounghoon.random_swamp + 3; j++) { //늪 시작 위치
						if (kimyounghoon.user_point[0] == i && kimyounghoon.user_point[1] == j) {
							kimyounghoon.player_hp -= 1;
							kimyounghoon.cnt += 1;
						}
					}
				}
				for (int i = kimyounghoon.random_swamp + 3; i < kimyounghoon.random_swamp + 6; i++) {
					for (int j = kimyounghoon.random_swamp + 3; j < kimyounghoon.random_swamp + 6; j++) { //늪 시작 위치
						if (kimyounghoon.user_point[0] == i && kimyounghoon.user_point[1] == j) {
							kimyounghoon.player_hp -= 2;
							kimyounghoon.cnt += 2;
						}
					}
				}
			}
			break; //위
		case 'P':

			if (kimyounghoon.user_point[1] <= 8 && kimyounghoon.user_point[1] >= 0) {
				kimyounghoon.user_point[1] += 1;
				kimyounghoon.player_hp -= 1 ;
				kimyounghoon.cnt += 1;

				for (int i = kimyounghoon.random_swamp; i < kimyounghoon.random_swamp + 3; i++) {
					for (int j = kimyounghoon.random_swamp; j < kimyounghoon.random_swamp + 3; j++) { //늪 시작 위치
						if (kimyounghoon.user_point[0] == i && kimyounghoon.user_point[1] == j) {
							kimyounghoon.player_hp -= 1;
							kimyounghoon.cnt += 1;
						}
					}
				}
				for (int i = kimyounghoon.random_swamp + 3; i < kimyounghoon.random_swamp + 6; i++) {
					for (int j = kimyounghoon.random_swamp + 3; j < kimyounghoon.random_swamp + 6; j++) { //늪 시작 위치
						if (kimyounghoon.user_point[0] == i && kimyounghoon.user_point[1] == j) {
							kimyounghoon.player_hp -= 2;
							kimyounghoon.cnt += 2;
						}
					}
				}
			}
			break; //아래
		}



		//end point 
		if (kimyounghoon.user_point[1] == kimyounghoon.random_fin_remain && kimyounghoon.user_point[0] == kimyounghoon.random_fin_quotient) {
			kimyounghoon.finish_game = true;
			break;
		}

		if (kimyounghoon.player_hp < 0) {
			kimyounghoon.finish_game = true;
			kimyounghoon.died = true;
			break;
		}

		system("cls");

	} while (!kimyounghoon.finish_game);

	if (kimyounghoon.finish_game != false && kimyounghoon.died != true ) {
		cout << "성공" << endl;
	}
	else {
		cout << "죽음" << endl;
	}


	//출력 :
#pragma endregion

}