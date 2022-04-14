#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

int main() {
#pragma region 콘솔용탈출게임

	//입력 : 
	int map_width = 10; //맵 가로
	int map_height = 10; // 맵 세로
	//배열에 담아보자 (char 형)
	char array_game[10][10];
	srand(time(NULL));
	int random_fin = rand() % 99 + 1; //도착 지점을 난수로 받는다 (0 ~ 99 숫자중 1부터 99까지 받는다)

	//난수의 몫과 나머지를 구해 i j 좌표로 설정한다.
	int random_fin_quotient = random_fin / 10; //몫
	int random_fin_remain = random_fin % 10; //나머지

	bool finish_game = false;// 도착 지점에 도착했는지 안했는지 판단
	char input_user_control = 'A'; //임의의 변수값 설정

	//end_point와 start_point 를 지정
	int end_point[2];
	int user_point[2] = { 0,0 };



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

		cout << "user_point : " << user_point[0] << " , " << user_point[1] << endl;


		//1.맵 표출
		for (int i = 0; i < map_height; i++) { //세로
			for (int j = 0; j < map_width; j++) {//가로
				//0,0 일때는 O가 들어가도록 설정
				if (i == 0 && j == 0) {
					array_game[i][j] = '0';

					if (user_point[0] != 0 && user_point[0] != 0) {
						cout << "#";
					}
					else {
						cout << "O";

					}

				}
				else {//0,0이 아니라면 #, E
					if (random_fin_quotient == i && random_fin_remain == j) {//몫과 나머지 값이 좌표값이면
						array_game[i][j] = 'E';
						end_point[0] = j;//x 좌표값
						end_point[1] = i;//y 좌표값
						cout << "E";
					}
					else {
						array_game[i][j] = '#';

						if (user_point[0] == j && user_point[1] == i) {
							cout << "O";
						}
						else {
							cout << "#";
						}


					}

				}

			}
			cout << endl;
		}


		//입력 받은 맵에서 화살표 이동
		input_user_control = _getch();
		switch (input_user_control) {

		case 'M':
			if (user_point[0] <= 8 && user_point[0] >= -1) {
				user_point[0] += 1;
			}
			break; //->
		case 'K':
			if (user_point[0] <= 9 && user_point[0] > 0) {
				user_point[0] -= 1;
			}
			break; //<-
		case 'H':
			if (user_point[1] <= 9 && user_point[1] > 0) {
				user_point[1] -= 1;
			}
			break; //위
		case 'P':

			if (user_point[1] <= 8 && user_point[1] >= 0) {
				user_point[1] += 1;
			}
			break; //아래
		}

		//end point 
		if (user_point[0] == random_fin_remain && user_point[1] == random_fin_quotient) {
			finish_game = true;
			break;
		}

		system("cls");

	} while (!finish_game);

	if (finish_game != false) {
		cout << "성공" << endl;
	}


	//출력 :
#pragma endregion
}