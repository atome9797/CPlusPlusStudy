#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

int main() {
#pragma region �ֿܼ�Ż�����

	//�Է� : 
	int map_width = 10; //�� ����
	int map_height = 10; // �� ����
	//�迭�� ��ƺ��� (char ��)
	char array_game[10][10];
	srand(time(NULL));
	int random_fin = rand() % 99 + 1; //���� ������ ������ �޴´� (0 ~ 99 ������ 1���� 99���� �޴´�)

	//������ ��� �������� ���� i j ��ǥ�� �����Ѵ�.
	int random_fin_quotient = random_fin / 10; //��
	int random_fin_remain = random_fin % 10; //������

	bool finish_game = false;// ���� ������ �����ߴ��� ���ߴ��� �Ǵ�
	char input_user_control = 'A'; //������ ������ ����

	//end_point�� start_point �� ����
	int end_point[2];
	int user_point[2] = { 0,0 };



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

		cout << "user_point : " << user_point[0] << " , " << user_point[1] << endl;


		//1.�� ǥ��
		for (int i = 0; i < map_height; i++) { //����
			for (int j = 0; j < map_width; j++) {//����
				//0,0 �϶��� O�� ������ ����
				if (i == 0 && j == 0) {
					array_game[i][j] = '0';

					if (user_point[0] != 0 && user_point[0] != 0) {
						cout << "#";
					}
					else {
						cout << "O";

					}

				}
				else {//0,0�� �ƴ϶�� #, E
					if (random_fin_quotient == i && random_fin_remain == j) {//��� ������ ���� ��ǥ���̸�
						array_game[i][j] = 'E';
						end_point[0] = j;//x ��ǥ��
						end_point[1] = i;//y ��ǥ��
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


		//�Է� ���� �ʿ��� ȭ��ǥ �̵�
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
			break; //��
		case 'P':

			if (user_point[1] <= 8 && user_point[1] >= 0) {
				user_point[1] += 1;
			}
			break; //�Ʒ�
		}

		//end point 
		if (user_point[0] == random_fin_remain && user_point[1] == random_fin_quotient) {
			finish_game = true;
			break;
		}

		system("cls");

	} while (!finish_game);

	if (finish_game != false) {
		cout << "����" << endl;
	}


	//��� :
#pragma endregion
}