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
	va_list args;//�������� ��� ������ pointer to btye
	va_start(args, num);//������ġ ����-> ���� �����Ϳ��� �̵��ؼ� ���� �������°�
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

	return b + fib(b);//��ȭ ���� �������
}


int main() {

	struct Point2D p1;
	int offsetX, offsetY;
	
	//scanf("%d %d %d %d", &p1.x, &p1.y, &offsetX, &offsetY);

	//movePoint2D(&p1, offsetX, offsetY);
	
	//printf("%d %d\n", p1.x, p1.y);
	

	//�������� �����
	printNumbers(1, 10);
	printNumbers(2, 10 , 20);


	//��� ȣ��
	hello(5);//hello �Լ� ���� ȣ�� 


	//���丮��
	//���丮���� 1���� n���� ���ڸ� ������� ���Ѱ��̸�, !��ȣ�� ǥ���մϴ�.
	//5!�� 5*4*3*2*1 �̸� ������� 120�̴�.
	printf("%d\n", factorial(5));

	//�Ǻ���ġ ���� �����
	int num10;
	scanf("%d", &num10);
	printf("%d\n", fib(num10));


	return 0;
}