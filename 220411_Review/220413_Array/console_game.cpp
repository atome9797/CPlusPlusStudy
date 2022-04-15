#include <iostream>
#include <string>
#include <conio.h>


using namespace std;


//���ӿ� ���� ����ü game
struct game{
	
	int map_width; //�� �ʺ�
	int map_height; // �� ����
	char array_game[10][10]; //���ӿ� ����Ǵ� ���� �����͸� �����ϴ� ����
	int random_fin ; //������ �޴� ���� 2 ~99
	int random_fin_quotient;  //������ �� : y��ǥ��
	int random_fin_remain; //������ ������ : x��ǥ��
	bool finish_game; // ���� ������ �����ߴ��� ���ߴ��� �Ǵ�
	bool died;//����
	char input_user_control; //���� �Է°�
	int user_point[2] = { 0,0 }; //������� => main�Լ����� �ʱⰪ ���� �����������
	int player_hp = 20;
	int random_swamp;
	int cnt;
};


int main() {

#pragma region �ֿܼ�Ż�����


	//�Է� : 
	game kimyounghoon; //����ü ���� ����
	
	kimyounghoon.map_width = 10;
	kimyounghoon.map_height = 10;
	srand(time(NULL));
	kimyounghoon.random_fin = rand() % 99 + 1; //���� ������ ������ �޴´� (0 ~ 99 ������ 1���� 99���� �޴´�)
	//������ ��� �������� ���� i j ��ǥ�� �����Ѵ�.
	kimyounghoon.random_fin_quotient = kimyounghoon.random_fin / 10; //��
	kimyounghoon.random_fin_remain = kimyounghoon.random_fin % 10; //������
	kimyounghoon.finish_game = false;// ���� ������ �����ߴ��� ���ߴ��� �Ǵ�
	kimyounghoon.died = false;// �׾����� �Ǵ�
	kimyounghoon.input_user_control = 'A'; //������ ������ ����

	kimyounghoon.random_swamp = rand() % 4;// 0~3������ ��/�� ���� �������� ����
	
	kimyounghoon.cnt = 0;

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

		//user_point[1] -> x��ǥ
		//user_point[0] -> y��ǥ

		cout << "user_point : " << kimyounghoon.user_point[1] << " , " << kimyounghoon.user_point[0] << endl;
		cout << "random_fin_remain , random_fin_quotient :  " << kimyounghoon.random_fin_remain << " , " << kimyounghoon.random_fin_quotient << endl;
		cout << "ü�� : " << kimyounghoon.player_hp << endl;
		cout << "�Ƿε� : " << 20 - kimyounghoon.player_hp << endl;
		cout << "�� : " << kimyounghoon.random_swamp << endl;

		cout << "�̵� ����Ʈ : " << kimyounghoon.cnt << endl;

		//���� ������ �����ص�
		for (int i = 0; i < kimyounghoon.map_height; i++) {
			for (int j = 0; j < kimyounghoon.map_width; j++) {
				kimyounghoon.array_game[i][j] = '#';
			}
		}


		//������Ʈ�� ��ġ�� �����Ѵ�.

		//�� ��ġ ���� -> ������ 3X3���� ����
		for (int i = kimyounghoon.random_swamp; i < kimyounghoon.random_swamp+3; i++) {
			for (int j = kimyounghoon.random_swamp; j < kimyounghoon.random_swamp+3; j++)  { //�� ���� ��ġ
				kimyounghoon.array_game[i][j] = '*';
			}
		}

		//�� ��ġ ���� random_swamp=9
		for (int i = kimyounghoon.random_swamp + 3; i < kimyounghoon.random_swamp + 6; i++) {
			for (int j = kimyounghoon.random_swamp + 3; j < kimyounghoon.random_swamp + 6; j++) {
				kimyounghoon.array_game[i][j] = '@';
			}
		}

		//������ġ ����
		int y = kimyounghoon.user_point[0];
		int x = kimyounghoon.user_point[1];
		kimyounghoon.array_game[x][y] = 'O';

		//�ⱸ ��ġ ����
		kimyounghoon.array_game[kimyounghoon.random_fin_remain][kimyounghoon.random_fin_quotient] = 'E';
				

		//������Ʈ�� ���� ������ ������ ��ü �迭���� ����
		for (int i = 0; i < kimyounghoon.map_height; i++) {
			for (int j = 0; j < kimyounghoon.map_width; j++) {
				cout << kimyounghoon.array_game[i][j];
			}
			cout << endl;
		}

		//�Է� ���� �ʿ��� ȭ��ǥ �̵�
		kimyounghoon.input_user_control = _getch();
		switch (kimyounghoon.input_user_control) {

		case 'M':
			if (kimyounghoon.user_point[0] <= 8 && kimyounghoon.user_point[0] >= -1) {
				kimyounghoon.user_point[0] += 1;
				kimyounghoon.player_hp -= 1 ;
				kimyounghoon.cnt += 1;

				for (int i = kimyounghoon.random_swamp; i < kimyounghoon.random_swamp + 3; i++) {
					for (int j = kimyounghoon.random_swamp; j < kimyounghoon.random_swamp + 3; j++) { //�� ���� ��ġ
						if (kimyounghoon.user_point[0] == i && kimyounghoon.user_point[1] == j) {
							kimyounghoon.player_hp -= 1;
							kimyounghoon.cnt += 1;
						}
					}
				}
				for (int i = kimyounghoon.random_swamp + 3; i < kimyounghoon.random_swamp + 6; i++) {
					for (int j = kimyounghoon.random_swamp + 3; j < kimyounghoon.random_swamp + 6; j++) { //�� ���� ��ġ
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
					for (int j = kimyounghoon.random_swamp; j < kimyounghoon.random_swamp + 3; j++) { //�� ���� ��ġ
						if (kimyounghoon.user_point[0] == i && kimyounghoon.user_point[1] == j) {
							kimyounghoon.player_hp -= 1;
							kimyounghoon.cnt += 1;
						}
					}
				}
				for (int i = kimyounghoon.random_swamp + 3; i < kimyounghoon.random_swamp + 6; i++) {
					for (int j = kimyounghoon.random_swamp + 3; j < kimyounghoon.random_swamp + 6; j++) { //�� ���� ��ġ
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
					for (int j = kimyounghoon.random_swamp; j < kimyounghoon.random_swamp + 3; j++) { //�� ���� ��ġ
						if (kimyounghoon.user_point[0] == i && kimyounghoon.user_point[1] == j) {
							kimyounghoon.player_hp -= 1;
							kimyounghoon.cnt += 1;
						}
					}
				}
				for (int i = kimyounghoon.random_swamp + 3; i < kimyounghoon.random_swamp + 6; i++) {
					for (int j = kimyounghoon.random_swamp + 3; j < kimyounghoon.random_swamp + 6; j++) { //�� ���� ��ġ
						if (kimyounghoon.user_point[0] == i && kimyounghoon.user_point[1] == j) {
							kimyounghoon.player_hp -= 2;
							kimyounghoon.cnt += 2;
						}
					}
				}
			}
			break; //��
		case 'P':

			if (kimyounghoon.user_point[1] <= 8 && kimyounghoon.user_point[1] >= 0) {
				kimyounghoon.user_point[1] += 1;
				kimyounghoon.player_hp -= 1 ;
				kimyounghoon.cnt += 1;

				for (int i = kimyounghoon.random_swamp; i < kimyounghoon.random_swamp + 3; i++) {
					for (int j = kimyounghoon.random_swamp; j < kimyounghoon.random_swamp + 3; j++) { //�� ���� ��ġ
						if (kimyounghoon.user_point[0] == i && kimyounghoon.user_point[1] == j) {
							kimyounghoon.player_hp -= 1;
							kimyounghoon.cnt += 1;
						}
					}
				}
				for (int i = kimyounghoon.random_swamp + 3; i < kimyounghoon.random_swamp + 6; i++) {
					for (int j = kimyounghoon.random_swamp + 3; j < kimyounghoon.random_swamp + 6; j++) { //�� ���� ��ġ
						if (kimyounghoon.user_point[0] == i && kimyounghoon.user_point[1] == j) {
							kimyounghoon.player_hp -= 2;
							kimyounghoon.cnt += 2;
						}
					}
				}
			}
			break; //�Ʒ�
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
		cout << "����" << endl;
	}
	else {
		cout << "����" << endl;
	}


	//��� :
#pragma endregion

}