/*
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

	
	구조체
	1. 절차적
	2. 구조적
	3. 객체지향적

	### 추상화 ###
	c언어에서 코드를 추상화 하는데 사용하는 삼총사 : 배열 ,구조체, 함수
	추상화 ???? 실제 세계(현상)를 간략화/기호화/보변화 해서 표현하는것
	코드에서 추상화가 필요한 이유 : 결국 코드는 사람이 짜는 것이기 때문에
	다른 사람이 코드를 해석하기 편리하고
	다른 사람이 인수인계받아서 유지보수하기 편리해야하고
	다른사람들과 함께 공동으로 코드를 만들기 편리해야하고

	배열 : 속성이 동일한 여러개의 데이터를 같은 이름과 순서를 지정한 연속된 번호로
	서로 연관되어 있음을 표시함으로써 추상화함
	변수명[숫자]

	구조체 : 데이터(자료형)을 실제로 쓰이는 데이터끼리 묶어서 추상화함
	함수 : 프로세스 (코드)를 특정 기능 단위로 묶어서 추상화함


	최악의 추상화 > 추상화 단계를 상승시키는 과정

	구조체란????  -> 변수 모아두는 "클래스"!!랑 비슷한 개념
	- 변수를 모아 놓은 집합체
	- 특정 변수들이 무언가의 하위개념으로 묶일수 있을때

	- studentName[10], studentAge[10] ....
	- '학생'의 땡땡땡
	- 이름, 나이, 국어 점수, 석차 등등을 '학생' 이라는 구조체로 묶어서 사용
	
	1. 구조체를 정의하는 위치 : 구조체가 사용되는 함수의 앞에 구조체는 정의한다.
	(해당 함수의 바깥쪽 위)

	2. 구조체 정의 방법
	struct 구조체 변수명 {
		구조체 안에  들어갈 하위 변수들
		(위의 예시에 따르면 이름,나이,국어점수, 석차 같은 애들이 하위 변수다.)
	};

	구조체는 일종의 우리가 새롭게 만든 테이터형
	
	구조체 안에 들어갈수 있는 하위 변수는 무엇이 있을까?
	: 당연히 int/bool/float 같은 기본 자료형들은 모두 사용가능
	string <- 클래스도 쓸수 있고

	3. 구조체의 선언과 초기화
	기본적으로 구조체 변수의 개념은 배열 변수의 개념과 동일
	int a [3] = {50,70,80};
	구조체 변수도 다음과 같이 선언과 동시에 초기화 할수 있다.
	
	과제 : 미궁 탈출 게임 업데이트 
	사용할수 있는 모든요소에 구조체를 활용해서 소스코드를 개선해보시오.
	tile : 지형 정보를 넣고 (숲,늪,평지)
	player : 피로도 넣고
	플레이어가 어느 지형에 있는지,플레이어의 피로도가 얼마인지 (숲 -1,늪 -3,평지 0)
	표시되도록 수정해 봅시다.

*/



#include <iostream>
#include <conio.h> //getch 받는 라이브러리
#include <map> 
#include <list>

using namespace std;

#pragma region 구조체 


//구조체 선언 score
struct score{
	int kor;
	int eng;
	int math;
};


//구조체 선언 student
struct student {
	string name;
	int age;
	string homeTown;
	char blood;
	int monthlyScore[12];
	score myScore;//구조체에 구조체로 선언 가능 -> !!! struct score myScore라고 해도됨 
}seoyon, jeahyuk; //중괄호 끝에 세미콜론 사이에다 ,student의 변수를 미리 선언해 줄수 있다.

//name,age,korScore, rank 라는 하위 변수를 가지고 있는 student라는 구조체를 정의한다. 

#pragma endregion


int main()
{


#pragma region 추상화강의
	//string a, b, c; // <- 최악의 추상화
	//string a[3]; //<- 위의 것보다는 좀 낫다
	//string name1, name2, name3; //<- 아니명 이런식이라든지
	//string studentName[3]; //위의 것보다 의도가 명료하게 드러나기 때문에 좋은 추상화다


#pragma endregion

#pragma region 구조체 예시


	student kimyounghoon; //구조체 변수 선언 => 변수명은 사용자가 지정 가능
	kimyounghoon.age = 27;
	kimyounghoon.name = "김영훈";
	kimyounghoon.homeTown = "서울";
	kimyounghoon.blood = 'A';

	//구조체에 변수명을 선언하고 java의  this 형태로 받은후 출력  
	//=> java는 this 의 변수명은 선언 하지 않았지만  구조체는 변수명을 선언하고 변수명의 변수명을 지정한다.

	//student 구조체를 이용해서 자기 자신의 정보를 입력하고 출력한다.
	cout << "제 이름은 " << kimyounghoon.name << "이고," << "혈액형은 "<< kimyounghoon.blood << "입니다. 나이는 " << kimyounghoon.age << "이고. 사는곳은" << kimyounghoon.homeTown << "입니다.";

	//구조체의 구조체 값을 가져와서 대입해준다. -> 상위를 지정하던지 아니면 하위에서 지정하든지 상관 없음
	kimyounghoon.myScore.eng = 79; 
	kimyounghoon.myScore.kor = 95;
	
	kimyounghoon.monthlyScore[0] = 80;
	kimyounghoon.monthlyScore[1] = 95;
	
	score myScore = { 50,80,90 }; //구조체 변수 선언 -> 상위 구조체 선언 안하고 사용할수있음
	cout << myScore.kor << myScore.eng << myScore.math << endl;


	//student seoyon;없이 진행 가능
	seoyon.name = "최서영"; //위에서 student 구조체에서 이름을 정의 했으므로  student 를 생략 가능하다


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


	//
	
	
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

