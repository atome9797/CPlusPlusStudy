#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int arr[1000000];

int main() {

	//입력
	int test_case_num = 0;//반복 횟수
	char count_test[80] = "#";
	int count_score = 0;
	int count_sp = 0;
	scanf("%d", &test_case_num);


	for (int i = 0; i < test_case_num; i++){//5입력됨
		count_score = 0;
		
		scanf("%s", &count_test); //문자열


		for (int j = 0; j < 80; j++) { //한줄에 80개 까지 받을수 있도록 설정
			if (count_test[j] == 'O') {
				count_score += 1;
				if (j >= 1 && count_test[j] == 'O' && count_test[j - 1] == 'O') {
					count_sp += 1;
					count_score += count_sp;
				}
				else {
					count_sp = 0;
				}
			}
		}

		printf("%d\n", count_score);
	}

		//for (int k = 0; k < 80; k++) {
		//	count_score += count_test[k];
		//	if (count_test[k] == 1 && count_test[k-1] == 1) {
		//		count_score += 1;
		//	}
		//}

	//평균
	//1. 최댓값은 M, 모든점수 => 점수/M*100

	//입력
	int testCnt = 0; // 테스트 갯수
	int testScore = 0; //테스트 한개 점수
	int maxScore = 0; //최대점수
	double calScore = 0;//종합 점수
	int input_score[101] = { 0 };

	scanf("%d", &testCnt);

	for (int i = 0; i < testCnt; i++){
		scanf("%d", &testScore);
		input_score[testScore] += 1; //점수값을 저장해서 카운트로 가져올수 있음
		if (maxScore < testScore) {//최댓값 구하기
			maxScore = testScore;//최댓값에 넣기
		}	
	}

	for (int i = 1; i <= 100; i++)
	{
		if (input_score[i] >= 1) {//해당 인덱스에 값이 있을때
			calScore += (double)i* input_score[i] / maxScore * 100;
		}
	}

	printf("%f\n", calScore/ testCnt);




	//1. 나머지가 서로다른게 몇개있는지 구하기

	//입력
	int input_a[42] = {0};//받는 배열
	int number_c = 0;//입력값
	int count_a = 0;
	//처리
	for (int i = 0; i < 10; i++) {
		scanf("%d", &number_c);
		input_a[number_c % 42] +=1;
	}

	//printf("%d\n", input_a[0]);

	for (int i = 0; i < 42; i++)
	{
		if (input_a[i] >=1) {
			//각 나머지 index값을 검사 하는 것이므로 input_a[0]일때 3이든 4든 뭐든 1개로 카운트 됨
			count_a++;
		}
	}

	printf("%d\n", count_a);


	/*
		첫째 줄에 A, 둘째 줄에 B, 셋째 줄에 C가 주어진다. 
		A, B, C는 모두 100보다 크거나 같고, 1,000보다 작은 자연수이다.

		첫째 줄에는 A × B × C의 결과에 0 이 몇 번 쓰였는지 출력한다. 
		마찬가지로 둘째 줄부터 열 번째 줄까지 A × B × C의
		결과에 1부터 9까지의 숫자가 각각 몇 번 쓰였는지 차례로 한 줄에 하나씩 출력한다.

		1. A,B,C 값을 받을 변수 선언
		2. scanf 로 값 받기
		3. 곲값을 자리수 와 자리수의 값을 배열로 저장하기 => 0 자리수의 값 ? 이런식으로
		4. 2중 for문으로 각 자리수별 숫자 카운트해서 뽑기
	*/

	int digit[3];
	int sumDigit = 0;
	int cntDigit[] = {0,}; //빈 함수 선언해서 값을 할당할수 있음
	int count100 = 1;
	int ddd =0;

	for (int i = 0; i < 3; i++) {
		scanf("%d", &digit[i]);
	}

	sumDigit = digit[0] * digit[1] * digit[2];
	
	//printf("%d\n", sumDigit);

	//sumDigit 배열로 전환
	while (1) {
		if (sumDigit / 10 != 0) {
			sumDigit = sumDigit / 10;
			count100++;
		}
		else {
			break;
		}
	}

	//printf("자리수 : %d\n", count100);

	
	sumDigit = digit[0] * digit[1] * digit[2];


	for (int i = 0; i < count100; i++) {
		cntDigit[i] = sumDigit % 10;
		sumDigit = sumDigit / 10;
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < count100; j++){
			if (i == cntDigit[j]) {
				ddd += 1;
			}
		}
		printf("%d\n", ddd);
		ddd = 0;
	}

	//printf("배열 값 : %d %d %d %d %d %d\n", cntDigit[0], cntDigit[1], cntDigit[2], cntDigit[3], cntDigit[4], cntDigit[5]);
	
	

	


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

#pragma region 알고리즘

	/*
	N개의 정수가 주어진다. 이때, 최솟값과 최댓값을 구하는 프로그램을 작성하시오.
	1. 첫째 줄에 정수의 개수
	2.  둘째 줄에는 N개의 정수를 공백으로 구분해서 주어진다
	3. 첫째 줄에 주어진 정수 N개의 최솟값과 최댓값을 공백으로 구분해 출력한다.
*/

	int size = 0;
	int maxN = 0;
	int minN = 0;
	scanf("%d", &size);


	for (int i = 0; i < size; i++) {
		scanf("%d", &arr[i]);
	}

	maxN = arr[0];
	minN = arr[0];

	for (int i = 0; i < size; i++) {
		if (maxN < arr[i]) {
			maxN = arr[i];
		}
		if (minN > arr[i]) {
			minN = arr[i];
		}
	}


	printf("%d %d\n", minN, maxN);


	/*
		첫째 줄부터 아홉 번째 줄까지 한 줄에 하나의 자연수가 주어진다.
		주어지는 자연수는 100 보다 작다.

		첫째 줄에 최댓값을 출력하고, 둘째 줄에 최댓값이 몇 번째 수인지를 출력한다.
	*/

	int input10[9];
	int maxN2 = 0;
	int cnt100 = 0;

	for (int i = 0; i < 9; i++) {
		scanf("%d", &input10[i]);
	}

	maxN2 = input10[0];

	for (int i = 0; i < 9; i++) {

		if (maxN2 < input10[i]) {
			maxN2 = input10[i];
			cnt100 = i;
		}

	}


	printf("%d %d\n", maxN2, cnt100 + 1);


	/*int *arr;
	int size =0;
	int maxN = 0;
	int minN = 0;
	scanf("%d", &size);

	arr = (int*)malloc(sizeof(int) * size);

	for (int i = 1; i < size; i++) {
		scanf("%d", &arr[i]);
		if (i < size && numx[i] > numx[i-1]) {
			minN = numx[i - 1];
		}
		else {
			maxN = numx[i];
		}
	}

	free(arr);*/


	/*
		자연수 N이 주어졌을 때, 1부터 N까지 한 줄에 하나씩 출력하는 프로그램을 작성하시오.
	*/


	/*
		각 테스트케이스마다 A+B를 한 줄에 하나씩 순서대로 출력한다.
	*/

	printf("======== 알고리즘 =========\n");

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


	/*
		각 테스트 케이스마다 "Case #x: "를 출력한 다음, A+B를 출력한다. 테스트 케이스 번호는 1부터 시작한다.
	*/

	/*
		Case #1: 1 + 1 = 2
	*/

	/*
		별찍기 문제
		*
		**
		***
		****
		*****
		*
		* 예제입력 :5
	*/

	int starNum = 0;
	scanf("%d", &starNum);
	for (int i = 0; i < starNum; i++) { // 0 ~ 4
		for (int j = starNum - 1; j > -1; j--) {
			if (i >= j) {
				printf("*");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}

	/*
		정수 N개로 이루어진 수열 A와 정수 X가 주어진다.
		이때, A에서 X보다 작은 수를 모두 출력하는 프로그램을 작성
	*/
	//int n = 0;
	//int ix = 0;
	//int xa = 0;
	//scanf("%d %d", &n,&ix);
	//for (int i = 0; i < n; i++) {
	//	scanf("%d", &xa);
	//	if (xa < ix) {
	//		printf("%d ", xa);
	//	}
	//}
	//int numa1 = 0;
	//int numb1 = 0;
	//do {
	//	scanf("%d %d", &numa1, &numb1);
	//	if (numa1 != 0 && numb1 != 0) {
	//		printf("%d\n", numa1 + numb1);
	//	}
	//} while (numa1 != 0 && numb1 != 0);

	int numa9 = 0;
	int numb9 = 0;
	//do {
	//	scanf("%d %d", &numa9, &numb9);
	//	if (numa9 > 0 && numa9 < 10 && numb9 > 0 && numb9 < 10) {
	//		printf("%d\n", numa9 + numb9);
	//	}
	//} while (numa9 > 0 && numa9 < 10 && numb9 > 0 && numb9 < 10);

	/*while(1) {
		scanf("%d %d", &numa9, &numb9);
		if (!(numa9 > 0 && numa9 < 10 && numb9 > 0 && numb9 < 10)) {
			break;
		}
		printf("%d\n", numa9 + numb9);
	}*/


	//입력
	int input_num = 0;
	int first_num = 0;
	int second_num = 0;
	int sum_num = 0;
	int sum_last_num = 0;
	int new_num = 0; //새로운 번호
	int cnt10 = 0;

	scanf("%d", &input_num);
	new_num = input_num;
	//0 < A, B < 10
	do {

		if (new_num < 10) {
			first_num = new_num / 10;
			second_num = new_num % 10;
			sum_num = first_num + second_num;
			sum_last_num = sum_num % 10;//합의 끝자리수 
		}
		else {
			first_num = new_num / 10;
			second_num = new_num % 10;
			sum_num = first_num + second_num; //각 자리 숫자를 더한다.
			sum_last_num = sum_num % 10;//합의 끝자리수 
		}
		new_num = second_num * 10 + sum_last_num;

		cnt10++;
	} while (input_num != new_num);

	printf("%d\n", cnt10);


#pragma endregion



	return 0;
}