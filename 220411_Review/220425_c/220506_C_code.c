#include <stdio.h>
//#include "MyHeaderFile.h"

#include "A.h"

//정의
#define SPEED_OF_LIGHT 299792458
#define MIN(a,b) ((a) < b ? a : b)
//음수 처리를 위해 괄호 사용할것
#define PRINT(msg) puts(#msg);
#define DECLARE_MYTYPE(typename) struct MyType##typename
// 가변 인자도 사용할 수 있다.
// __VA_ARGS__는 ...이 들어갈 곳이다.
#define SIMPLE_PRINT(...) puts(#__VA_ARGS__) //문자열로 출력
#define FORMAT_PRINT(fmt, ...) printf(fmt, __VA_ARGS__)

#undef SPEED_OF_LIGHT // 매크로 해제 => 빨간줄뜸

#define PRINT_ERROR(msg) printf("[%s:%d] %s\n", __FILE__, __LINE__, msg);



int main(void) {

	
	
	//Add(10, 20);

	//printf("빛의 속도는 %d m/s이다.\n", SPEED_OF_LIGHT);
	
	//-10 , 0
	if (MIN(10-20 ,20 < 4)) {//0이 아닐대 실행
		printf("10과 20중에 작은 수는 10입니다.\n");
	}

	PRINT(안녕하세요);//#을 붙이면 문자열 리터럴로 인식됨
	
	DECLARE_MYTYPE(Student)
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

#if 1
	puts("1. 이건 실행됨");
#endif

#if defined(TEST)
	puts("2. 이건 실행 안됨");
	// #else로 #if의 식이 만족하지 않았을 때의 내용을 만들 수 있다.
#else
	puts("2. 이건 실행됨");
#endif

#if !defined(TEST)
	puts("3. 이건 실행됨");
#endif

	// #if defined를 #ifdef로 줄일 수 있다.
#define TEST
#ifdef TEST
	puts("4. 이건 실행됨");
#endif

	// 마찬가지로 #if !defined를 #ifndef로 줄일 수 있다.
#define T 10
#ifndef TEST
	puts("5. 이건 실행 안됨");
	// #elif는 else if 쓰는 것과 비슷하다.
#elif defined(T) && T > 2
	printf("5. 이건 실행됨");
#else
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






	return 0;
}
