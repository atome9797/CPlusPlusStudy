#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "MyHeaderFile.h"

//#include "A.h"

//정의
#define SPEED_OF_LIGHT 299792458
#define MIN(a,b) ((a) < b ? a : b)
//음수 처리를 위해 괄호 사용할것
#define PRINT(msg) puts(#msg);
#define DECLARE_MYTYPE2(typename) struct MyType##typename
// 가변 인자도 사용할 수 있다.
// __VA_ARGS__는 ...이 들어갈 곳이다.
#define SIMPLE_PRINT(...) puts(#__VA_ARGS__) //문자열로 출력
#define FORMAT_PRINT(fmt, ...) printf(fmt, __VA_ARGS__)

#undef SPEED_OF_LIGHT // 매크로 해제 => 빨간줄뜸

//#define PRINT_ERROR(msg) printf("[%s:%d] %s\n", __FILE__, __LINE__, msg);


//pragma pack
#pragma pack(1) //정렬요건이 1바이트로 바뀜
//struct A2 {
//	int a;
//	double d;
//	char ch;
//};



/*
* 점화식
	1! = 1
	2! = 2 * 1 =  2 * 1! 
	3! = 3 * 2 * 1 = 3 * 2!

	N! = N * !(N - 1);
*/

//부등호로 해야함
//0일때도 처리해줘야 함으로 부등호 사용
int factorial(int num) {
	if (num <= 1) {
		return 1;
	}
	return num * factorial(num - 1);
}

//피보나치 수열
int pivo(int num) {

	//if (num == 0) {
	//	return 0;
	//}
	//else if (num == 1) {
	//	return 1;
	//}
	
	if (num <= 1) {
		return num;
	}

	return pivo(num - 1) + pivo(num - 2);
}


int count = 0;

void jhs(int num) {


	//재귀 전 실행
	if (count == num) {
		printf("어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n");
	}

	for (int i = 0; i < count - num; i++)
	{
		printf("____");
	}

	printf("\"재귀함수가 뭔가요?\"\n");

	
	for (int i = 0; i < count-num; i++)
	{
		printf("____");
	}


	//가장 바깥에 있다는 걸 어떻게 알수 있을까?
	if (0 == num) {
		printf("\"재귀함수는 자기 자신을 호출하는 함수라네\"\n");
		for (int i = 0; i < count - num; i++)
		{
			printf("____");
		}
		printf("라고 답변하였지.\n");
		//printf("____");
		return;
	}
	else {
		printf("\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n");
		for (int i = 0; i < count - num; i++)
		{
			printf("____");
		}
		printf("마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n");
		for (int i = 0; i < count - num; i++)
		{
			printf("____");
		}
		printf("그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n");
		//printf("____");
		
	}


	//기준으로 for문 2개랑 비슷 => 별그리기
	jhs(num - 1);

	

	//재귀 후 실행
	for (int i = 0; i < count-num; i++)
	{
		printf("____");
	}

	
	printf("라고 답변하였지.\n");


}





void bitcount2(int num) {
	
	
	if (num == 0) {
		return;
	}

	bitcount2(num / 2);
	
	printf("%d", num % 2);

}

//하노이 탑
/*
7
1 3
1 2
3 2
1 3
2 1
2 3
1 3
*/
//재귀 함수를 이용해서 어떤값을 올려야 할때
//전역 변수를 이용하면 좋음
int countHanoi = 0;
int (*ptr10)[3];

//옮기는데 작은거 위에 큰 원판이 들어갈수 없다.
//가장 큰 원판을 옮기려면 다른곳에 쌓아둬야함
void Hanoitop(int num) {
	

	//printf("%d %d", );
}



//별의 규칙성은 전체로 봤을때 ㅁ모양을 그리고,
//안에서 봤을때 ㅁ모양을 그리고,
//안쪽에서 ㅁ모양을 그림
void star(int num) {


	if (num == 0) {
		return 0;
	}

	
	star(num / 3);
	
	
	for (int i = 0; i < num / 3; i++)
	{
		for (int j = 0; j < num / 3; j++)
		{
			if (i % 3 == 1 && j % 3 == 1) {
				printf(" ");
			}
			else {
				printf("*");
			}
		}
		printf("\n");
	}

}



/*
		for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i % 3 == 1 && j % 3 == 1) {
				printf(" ");
			}
			else {
				printf("*");
			}
		}
		printf("\n");
	}

*/

int main(void) {

	//sizeof(struct A2);//24바이트가 아닌 13바이트로 바뀜
	
	
	printf("외부 함수 : %d\n", Add(10, 20));

	//printf("빛의 속도는 %d m/s이다.\n", SPEED_OF_LIGHT);
	
	//-10 , 0
	if (MIN(10-20 ,20 < 4)) {//0이 아닐때 실행
		printf("10과 20중에 작은 수는 10입니다.\n");
	}

	PRINT(안녕하세요);//#을 붙이면 문자열 리터럴로 인식됨
	
	DECLARE_MYTYPE2(Student)
	{
		int a;
	} a;

	SIMPLE_PRINT(1, 'a', "Hello");

	FORMAT_PRINT("Hello Macro : %d, %c, %s", 12, 'c', "Hello");


	//로그 찍을때 사용하기 좋음
	printf("FILE : %s\n", __FILE__);
	printf("LINE : %d\n", __LINE__);
	printf("DATE : %s\n", __DATE__);
	printf("TIME : %s\n", __TIME__);

	if (1) {
		PRINT_ERROR("오류가 발생했습니다.");
	}

//#if : 참일때 실행
#if 1
	puts("1. 이건 실행됨");
#endif

//#if defined : 정의 되어있을때 실행
#if defined(TEST)
	puts("2. 이건 실행 안됨");
	// #else로 #if의 식이 만족하지 않았을 때의 내용을 만들 수 있다.
#else
	puts("2. 이건 실행됨");
#endif

//#if !defined : 정의 되어 있지 않을때 실행
#if !defined(TEST)
	puts("3. 이건 실행됨");
#endif

#define TEST
// #if defined를 #ifdef로 줄일 수 있다.
#ifdef TEST
	puts("4. 이건 실행됨");
#endif


//T라는 식별자로 10일 정의함
#define T 10
// 마찬가지로 #if !defined를 #ifndef로 줄일 수 있다.
#ifndef TEST
	puts("5. 이건 실행 안됨");
	// #elif는 else if 쓰는 것과 비슷하다.
#elif defined(T) && T > 2
	printf("5. 이건 실행됨");
#else
	//위에서 참이면 else 는 실행 안되도록 설계됨
	printf("5. 이건 실행 안됨");
#endif



	//빌드 : 프로그램을 만드는 과정
	/*
		1. 전처리 : 컴파일 전에 하는 처리
			> - 조건부 컴파일 / 매크로 대체 / 다른 파일 포함등
		2. 컴파일 : 사람의 언어로 작성된 소스코드를 컴퓨터가 알수있는 언어호 번역
		3. 링크 : 식별자가 의미하는 메모리 주소를 연결
	*/

	

	//함수 포인터
	//pointer to function


	//재귀 함수
	int N;
	//scanf("%d", &N);
	//int fac = factorial(N);
	//printf("%d\n", fac);

	int N2 = 0;
	//scanf("%d", &N2);
	//printf("%d\n", pivo(N2));

	//재귀함수3
	//목표 : 문자열이 출력되도록 재귀함수 설정
	//입력 
	//처리
	//출력
	int N3;
	scanf("%d", &N3);
	count = N3;
	jhs(N3);

	//교수님 예제
	//printf("어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n");
	//jhs2(N3);
	

	//10진수를 2진수로
	//2로 나눈다.
	int N4=0;
	printf("입력 : \n");
	//scanf("%d", &N4);
	//bitcount2(N4);
	

	//하노이 탑
	int N5 = 0;
	printf("하노이 입력 : \n");
	//scanf("%d", &N5);
	/*for (int i = 0; ptr10[0][i] != '0'; i++)
	{
		ptr10[0][i] = i + 1;
	}
	hanoitop(N5);*/



	//별찍기
	int N6 = 0;
	printf("별찍기 : \n");
	scanf("%d",&N6);
	star(N6);










	


	return 0;
}
