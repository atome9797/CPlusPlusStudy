#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdarg.h>


struct Point2D {
	int x;
	int y;
};

void movePoint2D(struct Point2D *p1, int a, int b) {
	p1->x += a;
	p1->y += b;
}

void printNumbers(int num , ...) {
	va_list args;//가변인자 목록 포인터 pointer to btye
	va_start(args, num);//시작위치 지정-> 지정 포인터에서 이동해서 값을 가져오는것
	for (int i = 0; i < num; i++)
	{
		int num2 = va_arg(args, int);
		
		printf("%d ", num2);
	}
	
	va_end(args);
	printf("\n");
}


void hello(int count) {
	
	if (count == 0) {
		return;
	}

	printf("Hello, world! %d\n", count);

	hello(--count);

}


int factorial(int n) {
	if (n == 1) {
		return 1;
	}
	return n * factorial(n - 1);
}




int fib(int num1) {
	
	if (num1 == 0) {
		return 0;
	} else if(num1 == 1) {
		return 1;
	}

	return fib(num1 - 2) + fib(num1 - 1);//변화 값을 들고가야함

}


void hello2() {
	printf("Hello, world!\n");
}

void bonjour2() {
	printf("bonjour le monde!\n");
}


int add2(int a, int b) {
	return a + b;
}

int mul2(int a, int b) {
	return a * b;
}

void numberToString(int n, char * buffer) {
	sprintf(buffer, "%d", n); //buffer에 문자열 n저장
}

int add(int* a, int* b)
{
	return *a + *b;
}

int sub(int* a, int* b)
{
	return *a - *b;
}

int mul(int* a, int* b)
{
	return  (*a)* (*b);
}

int div2(int* a, int* b)
{
	return *a / *b;
}


int add3(int a, int b)
{
	return a + b;
}

int sub3(int a, int b)
{
	return a - b;
}

int mul3(int a, int b)
{
	return  (a) * (b);
}

int div3(int a, int b)
{
	return a / b;
}



int main() {

	struct Point2D p1;
	int offsetX, offsetY;
	
	//scanf("%d %d %d %d", &p1.x, &p1.y, &offsetX, &offsetY);

	//movePoint2D(&p1, offsetX, offsetY);
	
	//printf("%d %d\n", p1.x, p1.y);
	

	//가변인자 만들기
	printNumbers(1, 10);
	printNumbers(2, 10 , 20);


	//재귀 호출
	hello(5);//hello 함수 최초 호출 


	//팩토리얼
	//팩토리얼은 1부터 n까지 숫자를 차레대로 곱한값이며, !기호로 표기합니다.
	//5!는 5*4*3*2*1 이며 결과값은 120이다.
	printf("%d\n", factorial(5));

	//피보나치 수열 만들기
	int num10;
	scanf("%d", &num10);
	printf("%d\n", fib(num10));


	//함수 포인터 사용하기
	printf("%p\n", hello2); 
	//함수 이름도 포인터임 => 함수가 존재하는 메모리위치를 알아야 하는데, 이 위치값이 바로 함수 이름
	//함수 호출 (*hello)();
	printf("%d\n", (*fib)(5));
	(*hello2)(); //hello는 함수 포인터 변수임
	
	
	//함수 포인터 만들기
	//: 함수를 담을수 있는 함수 포인터를 선언하고, 함수의 주소를 담는다.
	void (*fp)();

	fp = hello2; //hello함수의 메모리 주소를 함수 포인터에 저장
	fp(); //hello주소 받았기 때문에 함수 포인터 함수 실행으로 호출 가능
	
	fp = bonjour2; //bonjour2함수의 메모리 주소를 함수 포인터에 저장
	fp(); //hello주소 받았기 때문에 함수 포인터 함수 실행으로 호출 가능


	//반환값과 매개변수가 있는 함수 포인터 만들기
	int(*fp2)(int, int); //반환값과 매개변수가 있는 함수 포인터 선언
	fp2 = add2; //함수포인터에 함수의 주소를 받음
	printf("%d\n", fp2(10,20)); //포인터 함수의 인자값을 넣어 함수값을 리턴함

	fp2 = mul2;
	printf("%d\n", fp2(10,20)); //포인터 함수의 인자값을 넣어 함수값을 리턴함

	
	//예제1
	//함수 포인터 만들기
	void (*fp3)();
	void (*fp4)(int, char*);
	
	char buffer[20];
	

	fp3 = hello2;
	fp4 = numberToString;
	
	fp3();
	fp4(100, buffer);//buffer주소값을 포인터로 적용해 값 적용시킴
	printf("%s\n", buffer);


	char funcName[10];
	int num100, num200;

	printf("입력 : \n");
	scanf("%s %d %d", funcName, &num100, &num200);


	int (*fp5)(int*, int*) = NULL;


	//if문에서 문자열을 비교할땐 strcmp을 사용할것
	if (strcmp(funcName, "add") == 0) {
		fp5 = add;
	}
	else if (strcmp(funcName, "sub") == 0) {
		fp5 = sub;
	}
	else if (strcmp(funcName, "mul") == 0) {
		fp5 = mul;
	}
	else if (strcmp(funcName, "div2") == 0) {
		fp5 = div2;
	}
	
	//fp5(10, 20);
	printf("%d\n", fp5(&num100, &num200));


	
	int funcNumber;
	int fnum, fnum2;
	int (*fp6)(int, int) = NULL;
	printf("함수 번호와 계산할 값을 입력하세요. :");
	scanf("%d %d %d", &funcNumber, &fnum, &fnum2);
	
	switch (funcNumber) {
	case 0: fp6 = add3; break;
	case 1: fp6 = sub3; break;
	case 2: fp6 = mul3; break;
	case 3: fp6 = div3; break;
	}


	printf("%d\n", fp6(fnum, fnum2));


	//함수 포인터 배열 사용하기 => 4개의 포인터에 각자 함수의 주소값을 넣어줌
	int (*fp7[4])(int, int) = {0}; //int형 반환값
	fp7[0] = add3;
	fp7[1] = sub3;
	fp7[2] = mul3;
	fp7[3] = div3;

	printf("함수 번호와 계산할 값을 입력하세요.: ");
	scanf("%d %d %d", &funcNumber, &fnum, &fnum2);
	printf("%d\n", fp7[funcNumber](fnum, fnum2));


	//함수 포인터 구조체 멤버 사용하기
	
	





	return 0;
}