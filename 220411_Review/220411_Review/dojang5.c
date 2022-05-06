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
	
	if (num1 == 0) {
		return 0;
	} else if(num1 == 1) {
		return 1;
	}

	return fib(num1 - 2) + fib(num1 - 1);//��ȭ ���� �������

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
	sprintf(buffer, "%d", n); //buffer�� ���ڿ� n����
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


	//�Լ� ������ ����ϱ�
	printf("%p\n", hello2); 
	//�Լ� �̸��� �������� => �Լ��� �����ϴ� �޸���ġ�� �˾ƾ� �ϴµ�, �� ��ġ���� �ٷ� �Լ� �̸�
	//�Լ� ȣ�� (*hello)();
	printf("%d\n", (*fib)(5));
	(*hello2)(); //hello�� �Լ� ������ ������
	
	
	//�Լ� ������ �����
	//: �Լ��� ������ �ִ� �Լ� �����͸� �����ϰ�, �Լ��� �ּҸ� ��´�.
	void (*fp)();

	fp = hello2; //hello�Լ��� �޸� �ּҸ� �Լ� �����Ϳ� ����
	fp(); //hello�ּ� �޾ұ� ������ �Լ� ������ �Լ� �������� ȣ�� ����
	
	fp = bonjour2; //bonjour2�Լ��� �޸� �ּҸ� �Լ� �����Ϳ� ����
	fp(); //hello�ּ� �޾ұ� ������ �Լ� ������ �Լ� �������� ȣ�� ����


	//��ȯ���� �Ű������� �ִ� �Լ� ������ �����
	int(*fp2)(int, int); //��ȯ���� �Ű������� �ִ� �Լ� ������ ����
	fp2 = add2; //�Լ������Ϳ� �Լ��� �ּҸ� ����
	printf("%d\n", fp2(10,20)); //������ �Լ��� ���ڰ��� �־� �Լ����� ������

	fp2 = mul2;
	printf("%d\n", fp2(10,20)); //������ �Լ��� ���ڰ��� �־� �Լ����� ������

	
	//����1
	//�Լ� ������ �����
	void (*fp3)();
	void (*fp4)(int, char*);
	
	char buffer[20];
	

	fp3 = hello2;
	fp4 = numberToString;
	
	fp3();
	fp4(100, buffer);//buffer�ּҰ��� �����ͷ� ������ �� �����Ŵ
	printf("%s\n", buffer);


	char funcName[10];
	int num100, num200;

	printf("�Է� : \n");
	scanf("%s %d %d", funcName, &num100, &num200);


	int (*fp5)(int*, int*) = NULL;


	//if������ ���ڿ��� ���Ҷ� strcmp�� ����Ұ�
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
	printf("�Լ� ��ȣ�� ����� ���� �Է��ϼ���. :");
	scanf("%d %d %d", &funcNumber, &fnum, &fnum2);
	
	switch (funcNumber) {
	case 0: fp6 = add3; break;
	case 1: fp6 = sub3; break;
	case 2: fp6 = mul3; break;
	case 3: fp6 = div3; break;
	}


	printf("%d\n", fp6(fnum, fnum2));


	//�Լ� ������ �迭 ����ϱ� => 4���� �����Ϳ� ���� �Լ��� �ּҰ��� �־���
	int (*fp7[4])(int, int) = {0}; //int�� ��ȯ��
	fp7[0] = add3;
	fp7[1] = sub3;
	fp7[2] = mul3;
	fp7[3] = div3;

	printf("�Լ� ��ȣ�� ����� ���� �Է��ϼ���.: ");
	scanf("%d %d %d", &funcNumber, &fnum, &fnum2);
	printf("%d\n", fp7[funcNumber](fnum, fnum2));


	//�Լ� ������ ����ü ��� ����ϱ�
	
	





	return 0;
}