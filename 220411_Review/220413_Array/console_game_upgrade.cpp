#include <iostream>
#include <conio.h> //getch 받는 라이브러리
#include <map> 
#include <list>

int main() {

#pragma region 콘솔용탈출게임

	//입력 : 
	int map_width = 10; //맵 가로
	int map_height = 10; // 맵 세로
	//배열에 담아보자 (char 형)
	//char array_game[10][10];
	srand(time(NULL));
	int random_fin = rand() % 99 + 1; //도착 지점을 난수로 받는다 (0 ~ 99 숫자중 1부터 99까지 받는다)
	//몬스터 자리수 랜덤
	int random_monster = rand() % 99 + 1;

	//난수의 몫과 나머지를 구해 i j 좌표로 설정한다.
	int random_fin_y = random_fin / 10; //몫
	int random_fin_x = random_fin % 10; //나머지

	//난수의 몫과 나머지를 구해 i j 좌표로 설정한다.
	int random_monster_y = random_monster / 10; //몫
	int random_monster_x = random_monster % 10; //나머지

	bool finish_game = false;// 도착 지점에 도착했는지 안했는지 판단
	bool playing_game = false;//게임에 승리 했는지 안했는지 판단
	char input_user_control = 'A'; //임의의 변수값 설정


	//end_point와 start_point 를 지정s
	int end_point[2]; //E
	int user_point[2] = { 0,0 }; //O


	//몬스터 포인트 난수값 미리 구현
	int monster_point[2] = { random_monster_x , random_monster_y }; //M -> 일단 몬스터 한마리 부터 만들어 보자


	// + 추가 부분
	int round_point = 1; //깨면 한번씩 올라감
	int player_max_hp = 10; //플레이어 체력 MAX 10
	int monster_max_hp = 50; //몬스터 체력 Max 50
	int monster_random_power; //몬스터 공격 주사위 랜덤
	int player_random_power; //유저 공격 주사위 랜덤
	int monster_move_random = 1; //몬스터 움직임 랜덤

	int kill_monster_cnt = 0;//죽인 몬스터수 표시
	int monster_cnt = 0;//나온 총 몬스터수 표시
	
	bool correct_monster = false;//몬스터와 유저의 좌표가 같은것이 있는지 검사
	std::list<int> monster_x_coordinate;

	//list에서 push_back 과 push_front 사용

	//map으로 몬스터 값 받기
	//map은 insert(make_pair(int,int))
	//		find(int) 로 넣고 빼고 함

	std::map<int, int> monster_map; //index, x
	std::map<int, int> monster_map_sub; // index , y




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

		//라운드 올라갈때 마다 배열증가
		for (int i = 0; i < round_point; i++)
		{
			//난수 생성
			int random_monster = rand() % 99 + 1;

			//난수의 몫과 나머지를 구해 i j 좌표로 설정한다.
			int random_monster_y = random_monster / 10; //몫
			int random_monster_x = random_monster % 10; //나머지

			monster_map.insert(std::make_pair(i, random_monster_x)); //index, x
			monster_map_sub.insert(std::make_pair(i, random_monster_y)); //index, y
			monster_x_coordinate.push_back(i); // 1 2라고 가정

			//라운드 올라갈때마다 라운드 수에 맞게 몬스터 및 좌표 증가
		}
		
		////몬스터 좌표와 같은지 for문을 돌려 검사 하고 해당 몬스터의 좌표값을 불러와 
		////계산하도록 한다.
		//remain_monster_cnt = round_point;
		//for (int i = 0; i < round_point; i++) {
		//	//monster_map value값은 x , monster_map_sub value 값은 y이다
		//	if (user_point[0] == monster_map[i] && user_point[1] == monster_map_sub[i]) {
		//		correct_monster = true; //유저와 몬스터의 좌표가 같은 것이 있다는 뜻
		//	}
		//}


		//몬스터와 유저의 좌표 값이 같아졌을때 죽이고 맵이 나오게 설정
		if (user_point[0] == monster_point[0] && user_point[1] == monster_point[1]) {
			std::cout << "전투가 시작됩니다" << std::endl;
			std::cout << "--------------------------------------" << std::endl;
			std::cout << "몬스터" << std::endl;
			std::cout << "HP : " << monster_max_hp << std::endl;
			std::cout << std::endl;
			std::cout << "플레이어";
			std::cout << "HP : " << player_max_hp << std::endl;
			std::cout << "(F키 누르면 공격)" << std::endl;

			do {
				input_user_control = _getch();
				if (input_user_control == 'f' || input_user_control == 'F') {

					//몬스터 및 유저 체력 감소 시킴
					monster_random_power = rand() % 2 + 1;
					player_random_power = (rand() % 6) * 10;

					player_max_hp = player_max_hp - monster_random_power;
					monster_max_hp = monster_max_hp - player_random_power;

					finish_game = false;
					playing_game = true;

					if (player_max_hp <= 0) {
						finish_game = true; //게임 종료
						playing_game = true;
						break;
					}
					else if (monster_max_hp <= 0) {
						playing_game = false; //몬스터 체력이 0이 되면 게임 끝남

						//몬스터가 0면 라운드가 올라감
						if ((monster_cnt - kill_monster_cnt) == 0) {
							round_point += 1;//라운드
							monster_cnt += round_point;//총 몬스터
						}

						//몬스터 포인트 지점을 임의의 값으로 설정
						int y = random_monster / 10; //몫
						int x = random_monster % 10; //나머지
						monster_point[0] = x;
						monster_point[1] = y;
						monster_max_hp = 50;
						kill_monster_cnt++;

						//몬스터 죽이면 다음 라운드에서 + 1 몬스터로 중가함


						break;
					}

				}


			} while (input_user_control != 'F' && input_user_control != 'f');

			system("cls");


		}//end if

		if (finish_game == false && playing_game == true) {
			std::cout << "게임중" << std::endl;
		}

		//게임 종료 안했고 전투중이 아닐때 실행
		if (finish_game == false && playing_game == false) {

			// 게임중일땐 표시 안함
			std::cout << "라운드 : " << round_point << std::endl;

			std::cout << "user_point : " << user_point[0] << " , " << user_point[1] << std::endl;
			std::cout << "monster_point : " << monster_point[0] << " , " << monster_point[1] << std::endl;
			std::cout << "player hp : " << player_max_hp << std::endl;
			std::cout << "monster_move_random : " << monster_move_random << std::endl;
			std::cout << "random_monster_x : " << random_monster_x << std::endl;
			std::cout << "random_monster_y : " << random_monster_y << std::endl;

			monster_move_random = rand() % 4 + 1; // 몬스터 이동값을 랜덤으로 받음

			//1.맵 표출
			for (int y = 0; y < map_height; y++) { //세로
				for (int x = 0; x < map_width; x++) {//가로
					//0,0 일때는 O가 들어가도록 설정 , M위치 설정
					if (y == 0 && x == 0) {
						//array_game[i][j] = '0';

						//0은 x축 1은 y축
						if (user_point[0] != 0 || user_point[1] != 0) {
							std::cout << " ";
						}
						else {
							std::cout << "O";
						}

					}
					else {//0,0이 아니라면 # , M

/*						if (user_point[0] == x && user_point[1] == y) {
							std::cout << "O";
						}
						else if (monster_point[0] == x && monster_point[1] == y) {
							std::cout << "M";
						}
						else {
							std::cout << " ";
						}	*/					
						
						if (user_point[0] == x && user_point[1] == y) {
							std::cout << "O";
						}
						else if ((monster_cnt - kill_monster_cnt ) >= 0) {//남은 몬스터 갯수가 0이 아니면
							//몬스터 갯수 만큼 반복
							for (auto loop : monster_x_coordinate) {
			
								//monster_x_coordinate에 남은 좌표 x값을 불러온후
								//x,y 가로세로 for문과 비교해서 맞으면 "M" 출력되게함
								if (monster_map[loop] == x && monster_map_sub[1] == y) {
									std::cout << "M";
								}

								
							}
							
						}
						else {
							std::cout << " ";
						}


					}

				}
				std::cout << std::endl;
			}


			//입력 받은 맵에서 화살표 이동
			input_user_control = _getch();

			switch (input_user_control) {

			case 'M':
				if (user_point[0] <= 8 && user_point[0] >= -1) {
					user_point[0] += 1;
				}

				//유저가 이동했으면 몬스터도 이동함 (방향은 랜덤 => 벽은 넘을수 없음)
				if (monster_move_random == 1) {
					if (monster_point[0] <= 8 && monster_point[0] >= -1) {
						monster_point[0] += 1;
					} // -> (+1 , 0)
				}
				else if (monster_move_random == 2) {
					if (monster_point[0] <= 9 && monster_point[0] > 0) {
						monster_point[0] -= 1;
					}// <- (-1 , 0)
				}
				else if (monster_move_random == 3) {
					if (monster_point[1] <= 9 && monster_point[1] > 0) {
						monster_point[1] -= 1;
					}// 위  (0, +1)
				}
				else if (monster_move_random == 4) {
					if (monster_point[1] <= 8 && monster_point[1] >= 0) {
						monster_point[1] += 1;
					}
				}

				break; //->

			case 'K':
				if (user_point[0] <= 9 && user_point[0] > 0) {
					user_point[0] -= 1;
				}

				//유저가 이동했으면 몬스터도 이동함 (방향은 랜덤 => 벽은 넘을수 없음)
				if (monster_move_random == 1) {
					if (monster_point[0] <= 8 && monster_point[0] >= -1) {
						monster_point[0] += 1;
					} // -> (+1 , 0)
				}
				else if (monster_move_random == 2) {
					if (monster_point[0] <= 9 && monster_point[0] > 0) {
						monster_point[0] -= 1;
					}// <- (-1 , 0)
				}
				else if (monster_move_random == 3) {
					if (monster_point[1] <= 9 && monster_point[1] > 0) {
						monster_point[1] -= 1;
					}// 위  (0, +1)
				}
				else if (monster_move_random == 4) {
					if (monster_point[1] <= 8 && monster_point[1] >= 0) {
						monster_point[1] += 1;
					}
				}


				break; //<-
			case 'H':
				if (user_point[1] <= 9 && user_point[1] > 0) {
					user_point[1] -= 1;
				}

				//유저가 이동했으면 몬스터도 이동함 (방향은 랜덤 => 벽은 넘을수 없음)
				if (monster_move_random == 1) {
					if (monster_point[0] <= 8 && monster_point[0] >= -1) {
						monster_point[0] += 1;
					} // -> (+1 , 0)
				}
				else if (monster_move_random == 2) {
					if (monster_point[0] <= 9 && monster_point[0] > 0) {
						monster_point[0] -= 1;
					}// <- (-1 , 0)
				}
				else if (monster_move_random == 3) {
					if (monster_point[1] <= 9 && monster_point[1] > 0) {
						monster_point[1] -= 1;
					}// 위  (0, +1)
				}
				else if (monster_move_random == 4) {
					if (monster_point[1] <= 8 && monster_point[1] >= 0) {
						monster_point[1] += 1;
					}
				}

				break; //위
			case 'P':

				if (user_point[1] <= 8 && user_point[1] >= 0) {
					user_point[1] += 1;
				}

				//유저가 이동했으면 몬스터도 이동함 (방향은 랜덤 => 벽은 넘을수 없음)
				if (monster_move_random == 1) {
					if (monster_point[0] <= 8 && monster_point[0] >= -1) {
						monster_point[0] += 1;
					} // -> (+1 , 0)
				}
				else if (monster_move_random == 2) {
					if (monster_point[0] <= 9 && monster_point[0] > 0) {
						monster_point[0] -= 1;
					}// <- (-1 , 0)
				}
				else if (monster_move_random == 3) {
					if (monster_point[1] <= 9 && monster_point[1] > 0) {
						monster_point[1] -= 1;
					}// 위  (0, +1)
				}
				else if (monster_move_random == 4) {
					if (monster_point[1] <= 8 && monster_point[1] >= 0) {
						monster_point[1] += 1;
					}
				}


				break; //아래
			}


			//end point 
			/*if (user_point[0] == random_fin_x && user_point[1] == random_fin_y) {
				finish_game = true;
				break;
			}*/

			system("cls");

		}

	} while (!finish_game);


	//죽었을때 true가 됨
	if (finish_game != false) {
		std::cout << "죽음 수고" << std::endl;
	}


	//출력 :
#pragma endregion
}