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
struct A2 {
	int a;
	double d;
	char ch;
};


int main(void) {

	sizeof(struct A2);//24����Ʈ�� �ƴ� 13����Ʈ�� �ٲ�
	
	
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






	return 0;
}
