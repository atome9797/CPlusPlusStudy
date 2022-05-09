#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "MyHeaderFile.h"

//#include "A.h"

//����
#define SPEED_OF_LIGHT 299792458
#define MIN(a,b) ((a) < b ? a : b)
//���� ó���� ���� ��ȣ ����Ұ�
#define PRINT(msg) puts(#msg);
#define DECLARE_MYTYPE2(typename) struct MyType##typename
// ���� ���ڵ� ����� �� �ִ�.
// __VA_ARGS__�� ...�� �� ���̴�.
#define SIMPLE_PRINT(...) puts(#__VA_ARGS__) //���ڿ��� ���
#define FORMAT_PRINT(fmt, ...) printf(fmt, __VA_ARGS__)

#undef SPEED_OF_LIGHT // ��ũ�� ���� => �����ٶ�

//#define PRINT_ERROR(msg) printf("[%s:%d] %s\n", __FILE__, __LINE__, msg);


//pragma pack
#pragma pack(1) //���Ŀ���� 1����Ʈ�� �ٲ�
//struct A2 {
//	int a;
//	double d;
//	char ch;
//};



/*
* ��ȭ��
	1! = 1
	2! = 2 * 1 =  2 * 1! 
	3! = 3 * 2 * 1 = 3 * 2!

	N! = N * !(N - 1);
*/

//�ε�ȣ�� �ؾ���
//0�϶��� ó������� ������ �ε�ȣ ���
int factorial(int num) {
	if (num <= 1) {
		return 1;
	}
	return num * factorial(num - 1);
}

//�Ǻ���ġ ����
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


	//��� �� ����
	if (count == num) {
		printf("��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n");
	}

	for (int i = 0; i < count - num; i++)
	{
		printf("____");
	}

	printf("\"����Լ��� ������?\"\n");

	
	for (int i = 0; i < count-num; i++)
	{
		printf("____");
	}


	//���� �ٱ��� �ִٴ� �� ��� �˼� ������?
	if (0 == num) {
		printf("\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n");
		for (int i = 0; i < count - num; i++)
		{
			printf("____");
		}
		printf("��� �亯�Ͽ���.\n");
		//printf("____");
		return;
	}
	else {
		printf("\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n");
		for (int i = 0; i < count - num; i++)
		{
			printf("____");
		}
		printf("���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n");
		for (int i = 0; i < count - num; i++)
		{
			printf("____");
		}
		printf("���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n");
		//printf("____");
		
	}


	//�������� for�� 2���� ��� => ���׸���
	jhs(num - 1);

	

	//��� �� ����
	for (int i = 0; i < count-num; i++)
	{
		printf("____");
	}

	
	printf("��� �亯�Ͽ���.\n");


}





void bitcount2(int num) {
	
	
	if (num == 0) {
		return;
	}

	bitcount2(num / 2);
	
	printf("%d", num % 2);

}

//�ϳ��� ž
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
//��� �Լ��� �̿��ؼ� ����� �÷��� �Ҷ�
//���� ������ �̿��ϸ� ����
int countHanoi = 0;
int (*ptr10)[3];

//�ű�µ� ������ ���� ū ������ ���� ����.
//���� ū ������ �ű���� �ٸ����� �׾Ƶ־���
void Hanoitop(int num) {
	

	//printf("%d %d", );
}



//���� ��Ģ���� ��ü�� ������ ������� �׸���,
//�ȿ��� ������ ������� �׸���,
//���ʿ��� ������� �׸�
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

	//sizeof(struct A2);//24����Ʈ�� �ƴ� 13����Ʈ�� �ٲ�
	
	
	printf("�ܺ� �Լ� : %d\n", Add(10, 20));

	//printf("���� �ӵ��� %d m/s�̴�.\n", SPEED_OF_LIGHT);
	
	//-10 , 0
	if (MIN(10-20 ,20 < 4)) {//0�� �ƴҶ� ����
		printf("10�� 20�߿� ���� ���� 10�Դϴ�.\n");
	}

	PRINT(�ȳ��ϼ���);//#�� ���̸� ���ڿ� ���ͷ��� �νĵ�
	
	DECLARE_MYTYPE2(Student)
	{
		int a;
	} a;

	SIMPLE_PRINT(1, 'a', "Hello");

	FORMAT_PRINT("Hello Macro : %d, %c, %s", 12, 'c', "Hello");


	//�α� ������ ����ϱ� ����
	printf("FILE : %s\n", __FILE__);
	printf("LINE : %d\n", __LINE__);
	printf("DATE : %s\n", __DATE__);
	printf("TIME : %s\n", __TIME__);

	if (1) {
		PRINT_ERROR("������ �߻��߽��ϴ�.");
	}

//#if : ���϶� ����
#if 1
	puts("1. �̰� �����");
#endif

//#if defined : ���� �Ǿ������� ����
#if defined(TEST)
	puts("2. �̰� ���� �ȵ�");
	// #else�� #if�� ���� �������� �ʾ��� ���� ������ ���� �� �ִ�.
#else
	puts("2. �̰� �����");
#endif

//#if !defined : ���� �Ǿ� ���� ������ ����
#if !defined(TEST)
	puts("3. �̰� �����");
#endif

#define TEST
// #if defined�� #ifdef�� ���� �� �ִ�.
#ifdef TEST
	puts("4. �̰� �����");
#endif


//T��� �ĺ��ڷ� 10�� ������
#define T 10
// ���������� #if !defined�� #ifndef�� ���� �� �ִ�.
#ifndef TEST
	puts("5. �̰� ���� �ȵ�");
	// #elif�� else if ���� �Ͱ� ����ϴ�.
#elif defined(T) && T > 2
	printf("5. �̰� �����");
#else
	//������ ���̸� else �� ���� �ȵǵ��� �����
	printf("5. �̰� ���� �ȵ�");
#endif



	//���� : ���α׷��� ����� ����
	/*
		1. ��ó�� : ������ ���� �ϴ� ó��
			> - ���Ǻ� ������ / ��ũ�� ��ü / �ٸ� ���� ���Ե�
		2. ������ : ����� ���� �ۼ��� �ҽ��ڵ带 ��ǻ�Ͱ� �˼��ִ� ���ȣ ����
		3. ��ũ : �ĺ��ڰ� �ǹ��ϴ� �޸� �ּҸ� ����
	*/

	

	//�Լ� ������
	//pointer to function


	//��� �Լ�
	int N;
	//scanf("%d", &N);
	//int fac = factorial(N);
	//printf("%d\n", fac);

	int N2 = 0;
	//scanf("%d", &N2);
	//printf("%d\n", pivo(N2));

	//����Լ�3
	//��ǥ : ���ڿ��� ��µǵ��� ����Լ� ����
	//�Է� 
	//ó��
	//���
	int N3;
	scanf("%d", &N3);
	count = N3;
	jhs(N3);

	//������ ����
	//printf("��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n");
	//jhs2(N3);
	

	//10������ 2������
	//2�� ������.
	int N4=0;
	printf("�Է� : \n");
	//scanf("%d", &N4);
	//bitcount2(N4);
	

	//�ϳ��� ž
	int N5 = 0;
	printf("�ϳ��� �Է� : \n");
	//scanf("%d", &N5);
	/*for (int i = 0; ptr10[0][i] != '0'; i++)
	{
		ptr10[0][i] = i + 1;
	}
	hanoitop(N5);*/



	//�����
	int N6 = 0;
	printf("����� : \n");
	scanf("%d",&N6);
	star(N6);










	


	return 0;
}
