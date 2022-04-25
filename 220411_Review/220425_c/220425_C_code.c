#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {


#pragma region 알고리즘

	/*
		각 테스트케이스마다 A+B를 한 줄에 하나씩 순서대로 출력한다.
	*/


	/*
		n이 주어졌을 때, 1부터 n까지 합을 구하는 프로그램을 작성하시오.
	*/
	int sumCal = 0; //합계
	int countNUm = 0; // n값
	int cnt = 0;
	scanf("%d", &countNUm);
	//n=3일때
	for (int i = 0; i < countNUm/2; i++) {
		sumCal += countNUm +1 ;
	}
	if (countNUm % 2 != 0) {
		sumCal += (countNUm + 1) / 2;
	}

	printf("계산값 : %d\n", sumCal);


	//케이스 밑 출력
	int replay = 0; //반복횟수
	int input1 = 0; //첫번째 입력값
	int input2 = 0; //구번째 입력값
	int replaySum = 0;
	scanf("%d", &replay); 

	for (int i = 0; i < replay; i++) {//반복횟수 만큼 입력값 받음
		scanf("%d %d", &input1, &input2); //넣을값
		replaySum = input1 + input2;
		printf("%d\n", replaySum);
	}


	//구구단
	//int number = 0;
	//scanf("%d\n", &number);

	//for (int i = 1; i < 10; i++) {
	//	printf("%d * %d = %d\n", number, i, number * i);
	//}

	
	/*
		원래 설정되어 있는 알람을 45분 앞서는 시간으로 바꾸는 것
		첫째 줄에 두 정수 H와 M이 주어진다. (0 ≤ H ≤ 23, 0 ≤ M ≤ 59)
		그리고 이것은 현재 상근이가 설정한 놓은 알람 시간 H시 M분을 의미한다.
		24시간 표현에서 하루의 시작은 0:0(자정)이고, 끝은 23:59(다음날 자정 1분 전)이다
		불필요한 0은 사용하지 않는다.
	*/
	int hour = 0;
	int minute = 0;
	scanf("%d", &hour);
	scanf("%d", &minute);

	//if (hour == 0) {
	//	hour = 24;
	//}
	//int output = (hour * 60 + minute) - 45;

	//if (output / 60 == 24) {
	//	hour = 0;
	//}
	//else {
	//	hour = output / 60;
	//}
	//printf("출력 : %d:%d\n", hour, output % 60);


	if (minute - 45 < 0) {
		hour -= 1;
		minute = 60 + (minute-45);
		if (hour < 0) {
			hour = 23;
		}
	}
	else {
		minute -= 45;
	}

	printf("알람 -45 : %d %d", hour, minute);


	int dies1 = 0;
	int dies2 = 0;
	int dies3 = 0;
	int count = 0;
	int price = 0;

	scanf("%d %d %d", &dies1, &dies2, &dies3);
	
	if (dies1 == dies2 && dies2 == dies3) {
		count += 2;
	}
	else if (dies1 == dies3 || dies2 == dies3 || dies1 == dies2) {
		count += 1;
	}


	if (count >= 2) {
		price = 10000 + dies1 * 1000;
	}
	else if (count == 1) {
		if (dies1 == dies2) {
			price = 1000 + dies1 * 100;
		}
		else if (dies1 == dies3) {
			price = 1000 + dies1 * 100;
		}
		else if (dies2 == dies3) {
			price = 1000 + dies2 * 100;
		}
	}
	else {
		if (dies1 > dies2 && dies1 > dies3) { // 3 4 6
			price = dies1 * 100;
		}
		else if (dies2 > dies3 && dies2 > dies1) {
			price = dies2 * 100;
		}
		else if (dies3 > dies2 && dies3 > dies1) {
			price = dies3 * 100;
		}
	}

	printf("상금 : %d\n", price);


	/*
		첫째 줄에는 현재 시각
		두 번째 줄에는 요리하는 데 필요한 시간
	*/
	int hr = 0;
	int min = 0;
	int oven = 0;
	scanf("%d %d", &hr, &min);
	scanf("%d", &oven);

	//분과 오븐 시간이 1시간이 넘어 갈때
	if (min+oven >= 60) {
		hr += (min+oven)/60; //시간을 추가해줌
		min = (min + oven) % 60;//나머지 분 추가됨

		if (hr > 23){
			hr = hr % 24;
		}
	}
	else {
		min = (min + oven);
	}

	printf("%d %d", hr, min);


	///*
	//	원래 설정되어 있는 알람을 45분 앞서는 시간으로 바꾸는 것
	//	첫째 줄에 두 정수 H와 M이 주어진다. (0 ≤ H ≤ 23, 0 ≤ M ≤ 59)
	//	그리고 이것은 현재 상근이가 설정한 놓은 알람 시간 H시 M분을 의미한다.
	//	24시간 표현에서 하루의 시작은 0:0(자정)이고, 끝은 23:59(다음날 자정 1분 전)이다
	//	불필요한 0은 사용하지 않는다.
	//*/
	//int hour = 0;
	//int minute = 0;
	//scanf("%d", &hour);
	//scanf("%d", &minute);

	//if (hour == 0) {
	//	hour = 24;
	//}
	//int output = (hour * 60 + minute) - 45;

	//if (output / 60 == 24) {
	//	hour = 0;
	//}
	//else {
	//	hour = output / 60;
	//}
	//printf("출력 : %d:%d\n", hour, output % 60);


	//if (minute - 45 < 0) {
	//	hour -= 1;
	//	minute = 60 + minute;
	//	if (hour < 0) {
	//		hour = 23;
	//	}
	//}
	//
	//printf("%d %d", hour, minute);


	int numa = 0;
	int numb = 0;
	scanf("%d", &numa);
	scanf("%d", &numb);

	//385
	int layer100 = numb / 100;//3
	int layer10 = (numb % 100) / 10;//8
	int layer1 = numb % 10;//5

	/*
		알고리즘으로 규칙성을 부여하면 a / 100 % 10 으로 연산 가능하다.
	
		int layer100 =  numb / 100 %10;
		int layer10 = (numb / 10) % 10;
		int layer1 = numb /1 % 10;
	*/



	printf("%d\n", numa * layer1);
	printf("%d\n", numa * layer10);
	printf("%d\n", numa * layer100);
	printf("%d\n", (numa * layer1) + (numa * layer10 * 10) + (numa * layer100 * 100));

	int num1 = 0;
	int num2 = 0;
	int sum = 0;
	char num2ch[30];
	printf("입력을 받으시오 =======\n");
	scanf("%d", &num1);
	scanf("%d", &num2);
	sprintf(num2ch, "%d", num2);
	printf("숫자 : %d\n", sizeof(num2ch) / sizeof(char));
	//for (int i = 0; i < sizeof(num2ch) /sizeof(char); i++) { //숫자 갯수 만큼 담음
	//	int count = 10 * (sizeof(num2ch) / sizeof(char) - i -1);//5-1
	//	printf("%d\n", num1 * num2ch[i]);
	//	if (count ==0) {
	//		sum += num1 * num2ch[i];
	//	}
	//	else {
	//		sum += num1 * num2ch[i] * count;
	//	}
	//}
	

	//쌍따옴표 역슬레쉬 출력방법
	/*
		\t : 수평 tab tab(8)칸 띄우기

		\n : 개행 커서를 한줄 밑으로 이동(enter와 같은효과)

		\' : '(쿼티션)을 표시 , 단독으로 '입력시 화면에 출력 x

		\" : "(더블 쿼티션) 표시

		\\ : \(역슬래시 표시)

	*/

	printf("\\    /\\\n");
	printf(" )  ( ')\n");
	printf("(  /  )\n");
	printf(" \\(__)|\n");

	printf("|\\_/|\n");
	printf("|q p|   /}\n");
	printf("( 0 )\"\"\"\\\n");
	printf("|\" ^ \"`    |\n");
	printf("||_/=\\\\__|\n");

	//
	int a = 0;
	int b = 0;
	double result = 0.0; //double 형은 소수 15자리까지 오차없이 표현할수 있다.

	//형변환
	scanf("%d", &a);
	scanf("%d", &b);
	result = (double)a / b;
	printf("%.13f\n", result);

	char name[40];
	scanf("%s", name);
	printf("%s??!\n", name);

	int year = 0;
	scanf("%d", &year);
	printf("날짜 : %d\n", year - 543);


	/*
		A가 B보다 큰 경우에는 '>'를 출력한다.
		A가 B보다 작은 경우에는 '<'를 출력한다.
		A와 B가 같은 경우에는 '=='를 출력한다.
	*/

	/*
		시험 점수를 입력받아 90 ~ 100점은 A, 80 ~ 89점은 B, 
		70 ~ 79점은 C, 60 ~ 69점은 D, 나머지 점수는 F를 출력하는 프로그램을 작성하시오.
	*/
	
	int score = 0;
	scanf("%d", &score);
	if (score >= 90 && score <= 100) {
		printf("A");
	}
	else if (score >= 80) {
		printf("B");
	}
	else if (score >= 70) {
		printf("C");
	}
	else if (score >= 60) {
		printf("D");
	}
	else {
		printf("F");
	}


	/*
		윤년은 연도가 4의 배수이면서, 100의 배수가 아닐 때 또는 400의 배수일 때이다.
		연도가 주어졌을 때, 윤년이면 1, 아니면 0을 출력하는 프로그램을 작성하시오.
	*/

	/*
		1사 : ++
		2사 : -+
		3사 : --
		4사 : +-
	*/
	int x = 0;
	int y = 0;

	scanf("%d", &x);
	scanf("%d", &y);

	if (x > 0 && y > 0) {
		printf("1");
	}
	else if (x < 0 && y > 0) {
		printf("2");
	}
	else if (x < 0 && y < 0) {
		printf("3");
	}
	else{
		printf("4");
	}



#pragma endregion

#pragma region c언어


	char ch = 'a';
	int number = 20;
	float number2 = 2.4f;

	printf("%c\n", ch);
	printf("%-5d", number); //-5는 5자리를 만들고 왼쪽 정렬해서 빈칸을 만드는 작업임
	printf("%.3f\n", number2);
	
	long long number3 = 1024LL;
	printf("%lld\n", number3);

	float temp1 = 0.0f;
	int temp2 =0;
	//변수 초기화 안하면 쓰레기값이 들어가 있다.
	scanf("%f | %d", &temp1, &temp2);

	printf("%f %d\n", temp1, temp2);


	/*
		float ,double, long double
		소수점 밑의 자리가 9개까지 같아야 함
		float :9개
		double : 9개
		long double : 15개

		오류의 종류
		컴파일 에러 : 문법을 잘못쓴것
		link error : 연결을 잘못한것
			- 함수를 선언만하고 정의하지 않았다거나
			- 이미 정의된 식별자를 다시 재정의한다거나
			- 범위 밖의 식별자를 사용했다거나
		runtime error : 프로그램 실행중 오류발생-> 버그 -> 논리 오류

	*/

	
	//10bit
	//0100 0000 0000
	(signed char)1024; //char 는 8비트이므로 10비트를 못담아 잘린다.

	/*
		while문에 0이 아닌 다른수는 다 참, 0은 거짓
		while(-1){ //무한 반복됨
		}
	*/


#pragma endregion


	return 0;
}