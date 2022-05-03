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
	int a;
	int b;
	if (num1 == 10) {
		a = 0;
		b = 1;
	}
	
	if (num1 == 0) {
		return;
	}

	a = num1;	
	b = b + a;

	return b + fib(b);//변화 값을 들고가야함
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


	return 0;
}