/*
* 
	boolean 타입
	bool is_alive =false; //비교문에서 0 1 로 처리됨

	배열 (자료구조)
	같은 데이터 타입의 여러 변수를 하나의 묶음으로 나타낸 것.

	배열의 데이터 타입에 대한 동일한 크기로 메모리상에 연속된 공간이 할당된다.
	배열명이 메모리의 시작 주소이다.

	2차원 배열 및 다차원 배열
	: 배열이 (개념적으로) 2중으로, 다중으로 구성되어 있는 것.
	
	1차원 배열 : int student_nums[5]; //5개 int
		-> 5의 학생이 있다.
	2차원 배열 : int student_nums[3][10]; // 15개 int
		-> 3개의 반에 각각 5명의 학생이 있다.
	3차원 배열 : int student_nums[4][3][5]; -> 메모리 주소는 이어져 있다. // 60개 int
		-> 4개의 학년에 각각 3개 반이 존재 하고, 각 반에 5명의 학생이 있다.

	
	(엔터 없이)문자 하나를 입력받는 방법 !!!
	
	_getch();

	형변환 : 데이터 타입을 변환한다. 
	
	묵시적 형변환
	명시적 형변환


	콘솔용 탈출게임
	1. 10 * 10  크기의 맵을 구성한다. (2차원 배열)
	2. 플레이어 (시작 지점 0,0)가 존재한다.
	3. 탈출 지점이 존재한다.
	WASD 키 입력을 통해 플레이어를 이동시킨다.
	탈출 지점은 (0,0)을 제외하고 랜덤 설정
	(플레이어)O가 E에 도달하면 "탈출에 성공했습니다." 프로그램 종료

	#O#########
	###########
	###########
	###########
	###########
	###########
	###########
	#######E###
	###########
	###########

	system("cls"); //clear screen 명령어로 화면을 싹다 지워줌 => 게임처럼 작동될수 있도록 사용함
*/

#include <iostream>
#include <conio.h> //getch 받는 라이브러리

using namespace std;
int main()
{
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
	int user_point[2] = {0,0};

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
					
					if (user_point[0] != 0 && user_point != 0) {
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
					user_point[0] +=  1;
				}
				break; //->
			case 'K': 
				if (user_point[0] <= 9 && user_point[0] > 0) {
					user_point[0] -=  1;
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

#pragma region 강의


	//int input_key = _getch(); //문자하나 입력 받음
	//cout << input_key << endl; //아스키 코드 값이 나옴

	char input_key_char = _getch();
	cout << input_key_char << endl; //문자 값이 나옴  => 엔터 안해도됨

	char input_key_char2 = _getch();
	cout << (int)input_key_char2 << endl; //명시적 형변환으로 숫자값으로 출력되게함

	float test_float = 5.4f;//f안붙이면 double로 인식
	float test_float2 = (float)5.4;// 명시적 형변환으로도 표현가능


	cout << "==========================" << endl;


	

	//2차원 배열
	int student_nums[3][5] = { {1,2,3,4,5}, {6,7,8,9,10}, {11,12,13,14,15} };
	//cout << student_nums[0][5] << endl; 
	// 인덱스 5에 해당하는 자리는 없지만 연속된 메모리 공간으로 인해 [1][0] 메모리 주소에접근된다.


	//순서대로 출력하는 코드
	for (int i = 0; i < 5; i++) {
		cout << student_nums[0][i] << endl;
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			cout << student_nums[i][j] << endl;
		}
	}


	int exnum[10]; // int 형 데이터 타입의 4*10 메모리를 할당 받음

	int nums[10] = { 1,2,3,4,5,6,7,8,9,12 };
	cout << nums << endl; //nums 배열 명이 해당 메모리의 시작 주소다.0000008A669FF5F8

	//cout << nums[10] << endl; //[10] -> runtime error :잘못된 주소를 입력
	cout << &(nums[1]) << endl; //주소 접근 -> 0 메모리 주소에서 int 4바이트 만큼 떨어져 있는 주소를 의미
	cout << &(nums[2]) << endl;
	cout << &(nums[3]) << endl;

	//16진수로 메모리가 계산되므로 4씩 떨어져 있는 것을 확인할수 있다.


	for (int i = 0; i < 10; i++) {
		cout << &(nums[i]) << endl;
	}

	/*
		실습1. string형배열 변수 5개 짜리를 선언하고
		반복문을 통해 학생의 이름을 입력 받는다. => 학생이름 5개 저장할수있는 배열 만들기

		입력을 다 받고 나서 1 ~ 5사이의 값을 입력하면 해당 학생의 이름이 출력된다.

		예시)
		1번째 학생의 이름을 입력하세요.:
		2번째 학생의 이름을 입력하세요.:
		3번째 학생의 이름을 입력하세요.:
		4번째 학생의 이름을 입력하세요.:
		5번째 학생의 이름을 입력하세요.:

		1 ~ 5사이의 번호를 입력하세요. : 3

		3번째 학생의 이름은 ...입니다.
	*/

	//입력 :
	string student_name[5];// 저장소
	int input_num = 0;//숫자 입력값

	//처리 :
	for (int i = 0; i < 5; i++) {
		cout << i + 1 << "번째 학생의 이름을 입력하세요." << endl;
		cin >> student_name[i];
	}

	cout << "1 ~ 5사이의 번호를 입력하세요." << endl;
	cin >> input_num;

	cout << input_num << "번째 학생의 이름은 " << student_name[input_num - 1] << "입니다." << endl;

	//출력 :
#pragma endregion

#pragma region 배열실습
	/*
		실습.
		구구단의 결과를 저장하는 2차원 배열을 하나 선언하고,
		2 * 2 = 2

		이중 for문을 이용해서 배열 변수에 구구단의 결과값을 저장하고,

		두수를 입력받아서 적합한 결과값을 출력해보자.

		예시) 
			(결과 저장 완료)
			몇 단을 볼까요? : (입력) 4
			몇을 곱할까요? : (입력) 7
			4 * 7 = 28(저장한 결과에서 불러오기)
	*/

	//입력 :
	int array_gugu[9][9];
	int dan = 0;
	int gob = 0;

	//처리 :
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j <= 9; j++) {
			array_gugu[i-1][j-1] = i * j;//해당 자리에 맞게 들어감
		}
	}

	cout << "몇 단을 볼까요?" << endl;
	cin >> dan;
	cout << "몇을 곱할까요?" << endl;
	cin >> gob;

	cout << dan << " * " << gob << " = " << array_gugu[dan-1][gob-1] << endl;

	//출력 :
#pragma endregion

#pragma region getch실습

	/*
		실습.1
		A ~ Z 키 중에 하나를 정답으로 설정한다.
		유저는 한개의 키를 입력해서 설정된 값을 맞춘다.
		유저가 입력한 키와 설정된 값이 맞으면 승리, 프로그램 종료
		틀리면 남은 기회를 보여주고, 5번틀리면 정답을 알려주고 게임오버

		+ 틀렸을때마다 정답 알파벳이 입력된 알파벳 앞에 있는지, 뒤에 있는지 힌트를 준다.

		+ 입력된 값이 대소문자 구분없이 처리될수 있도록 수정해보자.
	*/

	//실습1


	//입력 :

	//두 수 사이의 난수 값 
	char answer = 'c';
	char input_user = 'a';
	int cnt = 1;
	bool correct = false;

	//처리 :
	srand(time(NULL));
	int random_ch = rand() % 25 + 97; //97 ~ 122 사이의 난수 값을 구할수 있다
	answer = random_ch; //난수값 들어감

	cout << "A ~ Z 중 하나의 키를 입력해주세요." << endl;

	do {

		input_user = _getch();

		if (input_user >= 'A' && input_user <= 'Z') { //유저 입력값이 소문자면 대문자로 변환
			input_user += 32;
		}

		if (answer != input_user) {

			if (cnt != 5) {
				cout << "틀렸습니다. 남은기회는 " << 5 - cnt << "입니다.    ";

				//두 숫자 비교
				if (((int)answer - (int)input_user) > 0) { //answer > input_user
					cout << "정답은 입력된 값 뒤에 있습니다." << endl;
				}
				else { //answer < input_user
					cout << "정답은 입력된 값 앞에 있습니다." << endl;
				}
			}

		}
		else {
			correct = true;
			break;
		}
		cnt++;

	} while (cnt <= 5);

	if (correct) {
		cout << "정답입니다." << endl;
	}
	else {
		cout << "틀렸습니다. " << "정답은 " << answer << "입니다." << endl;
	}

	//출력 :
#pragma endregion



}

