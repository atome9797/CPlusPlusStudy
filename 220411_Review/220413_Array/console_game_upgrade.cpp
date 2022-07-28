#include <iostream>
#include <conio.h> //getch �޴� ���̺귯��
#include <map> 
#include <list>

int main() {

#pragma region �ֿܼ�Ż�����

	//�Է� : 
	int map_width = 10; //�� ����
	int map_height = 10; // �� ����
	//�迭�� ��ƺ��� (char ��)
	//char array_game[10][10];
	srand(time(NULL));
	int random_fin = rand() % 99 + 1; //���� ������ ������ �޴´� (0 ~ 99 ������ 1���� 99���� �޴´�)
	//���� �ڸ��� ����
	int random_monster = rand() % 99 + 1;

	//������ ��� �������� ���� i j ��ǥ�� �����Ѵ�.
	int random_fin_y = random_fin / 10; //��
	int random_fin_x = random_fin % 10; //������

	//������ ��� �������� ���� i j ��ǥ�� �����Ѵ�.
	int random_monster_y = random_monster / 10; //��
	int random_monster_x = random_monster % 10; //������

	bool finish_game = false;// ���� ������ �����ߴ��� ���ߴ��� �Ǵ�
	bool playing_game = false;//���ӿ� �¸� �ߴ��� ���ߴ��� �Ǵ�
	char input_user_control = 'A'; //������ ������ ����


	//end_point�� start_point �� ����s
	int end_point[2]; //E
	int user_point[2] = { 0,0 }; //O


	//���� ����Ʈ ������ �̸� ����
	int monster_point[2] = { random_monster_x , random_monster_y }; //M -> �ϴ� ���� �Ѹ��� ���� ����� ����


	// + �߰� �κ�
	int round_point = 1; //���� �ѹ��� �ö�
	int player_max_hp = 10; //�÷��̾� ü�� MAX 10
	int monster_max_hp = 50; //���� ü�� Max 50
	int monster_random_power; //���� ���� �ֻ��� ����
	int player_random_power; //���� ���� �ֻ��� ����
	int monster_move_random = 1; //���� ������ ����

	int kill_monster_cnt = 0;//���� ���ͼ� ǥ��
	int monster_cnt = 0;//���� �� ���ͼ� ǥ��
	
	bool correct_monster = false;//���Ϳ� ������ ��ǥ�� �������� �ִ��� �˻�
	std::list<int> monster_x_coordinate;

	//list���� push_back �� push_front ���

	//map���� ���� �� �ޱ�
	//map�� insert(make_pair(int,int))
	//		find(int) �� �ְ� ���� ��

	std::map<int, int> monster_map; //index, x
	std::map<int, int> monster_map_sub; // index , y




	//Ű���� �Է°� 
	/*
		->  : M
		<-  : K
		��  : H
		�Ʒ�  : P
	*/

	//ó�� :


	//���� ������ �����ߴ��� ���ߴ��� �Ǵ� �ϰ� ���������� �ݺ����� ���� �������� ����
	do {

		//���� �ö󰥶� ���� �迭����
		for (int i = 0; i < round_point; i++)
		{
			//���� ����
			int random_monster = rand() % 99 + 1;

			//������ ��� �������� ���� i j ��ǥ�� �����Ѵ�.
			int random_monster_y = random_monster / 10; //��
			int random_monster_x = random_monster % 10; //������

			monster_map.insert(std::make_pair(i, random_monster_x)); //index, x
			monster_map_sub.insert(std::make_pair(i, random_monster_y)); //index, y
			monster_x_coordinate.push_back(i); // 1 2��� ����

			//���� �ö󰥶����� ���� ���� �°� ���� �� ��ǥ ����
		}
		
		////���� ��ǥ�� ������ for���� ���� �˻� �ϰ� �ش� ������ ��ǥ���� �ҷ��� 
		////����ϵ��� �Ѵ�.
		//remain_monster_cnt = round_point;
		//for (int i = 0; i < round_point; i++) {
		//	//monster_map value���� x , monster_map_sub value ���� y�̴�
		//	if (user_point[0] == monster_map[i] && user_point[1] == monster_map_sub[i]) {
		//		correct_monster = true; //������ ������ ��ǥ�� ���� ���� �ִٴ� ��
		//	}
		//}


		//���Ϳ� ������ ��ǥ ���� ���������� ���̰� ���� ������ ����
		if (user_point[0] == monster_point[0] && user_point[1] == monster_point[1]) {
			std::cout << "������ ���۵˴ϴ�" << std::endl;
			std::cout << "--------------------------------------" << std::endl;
			std::cout << "����" << std::endl;
			std::cout << "HP : " << monster_max_hp << std::endl;
			std::cout << std::endl;
			std::cout << "�÷��̾�";
			std::cout << "HP : " << player_max_hp << std::endl;
			std::cout << "(FŰ ������ ����)" << std::endl;

			do {
				input_user_control = _getch();
				if (input_user_control == 'f' || input_user_control == 'F') {

					//���� �� ���� ü�� ���� ��Ŵ
					monster_random_power = rand() % 2 + 1;
					player_random_power = (rand() % 6) * 10;

					player_max_hp = player_max_hp - monster_random_power;
					monster_max_hp = monster_max_hp - player_random_power;

					finish_game = false;
					playing_game = true;

					if (player_max_hp <= 0) {
						finish_game = true; //���� ����
						playing_game = true;
						break;
					}
					else if (monster_max_hp <= 0) {
						playing_game = false; //���� ü���� 0�� �Ǹ� ���� ����

						//���Ͱ� 0�� ���尡 �ö�
						if ((monster_cnt - kill_monster_cnt) == 0) {
							round_point += 1;//����
							monster_cnt += round_point;//�� ����
						}

						//���� ����Ʈ ������ ������ ������ ����
						int y = random_monster / 10; //��
						int x = random_monster % 10; //������
						monster_point[0] = x;
						monster_point[1] = y;
						monster_max_hp = 50;
						kill_monster_cnt++;

						//���� ���̸� ���� ���忡�� + 1 ���ͷ� �߰���


						break;
					}

				}


			} while (input_user_control != 'F' && input_user_control != 'f');

			system("cls");


		}//end if

		if (finish_game == false && playing_game == true) {
			std::cout << "������" << std::endl;
		}

		//���� ���� ���߰� �������� �ƴҶ� ����
		if (finish_game == false && playing_game == false) {

			// �������϶� ǥ�� ����
			std::cout << "���� : " << round_point << std::endl;

			std::cout << "user_point : " << user_point[0] << " , " << user_point[1] << std::endl;
			std::cout << "monster_point : " << monster_point[0] << " , " << monster_point[1] << std::endl;
			std::cout << "player hp : " << player_max_hp << std::endl;
			std::cout << "monster_move_random : " << monster_move_random << std::endl;
			std::cout << "random_monster_x : " << random_monster_x << std::endl;
			std::cout << "random_monster_y : " << random_monster_y << std::endl;

			monster_move_random = rand() % 4 + 1; // ���� �̵����� �������� ����

			//1.�� ǥ��
			for (int y = 0; y < map_height; y++) { //����
				for (int x = 0; x < map_width; x++) {//����
					//0,0 �϶��� O�� ������ ���� , M��ġ ����
					if (y == 0 && x == 0) {
						//array_game[i][j] = '0';

						//0�� x�� 1�� y��
						if (user_point[0] != 0 || user_point[1] != 0) {
							std::cout << " ";
						}
						else {
							std::cout << "O";
						}

					}
					else {//0,0�� �ƴ϶�� # , M

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
						else if ((monster_cnt - kill_monster_cnt ) >= 0) {//���� ���� ������ 0�� �ƴϸ�
							//���� ���� ��ŭ �ݺ�
							for (auto loop : monster_x_coordinate) {
			
								//monster_x_coordinate�� ���� ��ǥ x���� �ҷ�����
								//x,y ���μ��� for���� ���ؼ� ������ "M" ��µǰ���
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


			//�Է� ���� �ʿ��� ȭ��ǥ �̵�
			input_user_control = _getch();

			switch (input_user_control) {

			case 'M':
				if (user_point[0] <= 8 && user_point[0] >= -1) {
					user_point[0] += 1;
				}

				//������ �̵������� ���͵� �̵��� (������ ���� => ���� ������ ����)
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
					}// ��  (0, +1)
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

				//������ �̵������� ���͵� �̵��� (������ ���� => ���� ������ ����)
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
					}// ��  (0, +1)
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

				//������ �̵������� ���͵� �̵��� (������ ���� => ���� ������ ����)
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
					}// ��  (0, +1)
				}
				else if (monster_move_random == 4) {
					if (monster_point[1] <= 8 && monster_point[1] >= 0) {
						monster_point[1] += 1;
					}
				}

				break; //��
			case 'P':

				if (user_point[1] <= 8 && user_point[1] >= 0) {
					user_point[1] += 1;
				}

				//������ �̵������� ���͵� �̵��� (������ ���� => ���� ������ ����)
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
					}// ��  (0, +1)
				}
				else if (monster_move_random == 4) {
					if (monster_point[1] <= 8 && monster_point[1] >= 0) {
						monster_point[1] += 1;
					}
				}


				break; //�Ʒ�
			}


			//end point 
			/*if (user_point[0] == random_fin_x && user_point[1] == random_fin_y) {
				finish_game = true;
				break;
			}*/

			system("cls");

		}

	} while (!finish_game);


	//�׾����� true�� ��
	if (finish_game != false) {
		std::cout << "���� ����" << std::endl;
	}


	//��� :
#pragma endregion
}