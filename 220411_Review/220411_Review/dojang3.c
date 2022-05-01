#include <stdio.h>
#include <stdlib.h>

#pragma region ����������

//������ ���� : ����ü�� ����ϰ� ����� �����ؼ� ���
//������� ���� ���� ������ 0,1,2,3,4..�̾��� 
enum DayOfWeek {
	Sunday4 =0, //�ƹ� ���� �Ҵ� ���� ������ 0���� ���۵� 
	Monday4,
	Tuesday4,
	Wednesday4,
	Friday4,
	Saturday4
};

//������ �̸��� ��ҹ���
enum hdmi_content_type {
	HDMI_CONTENT_TYPE_GRAPHICS,
	HDMI_CONTENT_TYPE_PHOTO,
	HDMI_CONTENT_TYPE_CINEMA,
	HDMI_CONTENT_TYPE_GAME
};

//typedef �͸� ������
typedef enum {
	Sunday2 = 0,
	Monday2,
	Tuesday2,
	Wednesday2,
	Thursday2,
	Friday2,
	Saturday2
}DayOfWeek2; //typedef �� �̿��Ͽ�, ������ ��Ī���� DayOfWeek2 ����

DayOfWeek2 week2; //�������� ��Ī���� ����ü ���� ����

//������ �����ϴ� ���ÿ� ���� �����ϱ�
enum DayOfWeek4 {
	Sunday = 0,
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday
} week3; //���� ���ÿ� ���� ���� (typedef �� �ƴϱ� ������ , ���� ������)


enum LuxSkill {
	LightBinding = 1,
	PrismaticBarrier,
	LucentSigngularity,
	FinalSpark
};

typedef enum _DayOfWeek {
	Sunday3 =0,
	Monday3,
	Tuesday3,
	Wednesday3,
	Thursday3,
	Friday3,
	Saturday3,
	DayOfWeekCount3 //0�ε������� ���� ������ ���������� ��ü ������ ������
}DayOfWeek3;


#pragma endregion

#pragma region ����ü
struct Flags {

	union {
		struct {
			unsigned short a : 3;
			unsigned short b : 2;
			unsigned short c : 7;
			unsigned short d : 4;
		};
		unsigned short e; //����ü�� 16��Ʈ ����
	};
};

struct Flags2 {
	unsigned int a : 2;
	unsigned int b : 1;
	unsigned int c : 6;
};


#pragma endregion

#pragma region ����ü

struct Data{
	char c1;
	int num1;
};

//����ü ������ ��Ī ����
typedef struct _Data {

	char c100;
	int num100;
} Data2, *PData; //����ü ��Ī, ����ü ������ ��Ī ����


struct Data3 {
	int num1;
	int num2;
};

#pragma endregion


int main() {


	//��Ʈ �ʵ�� ����ü �Բ� ���
	struct Flags f1 = { 0, };
	f1.a = 4;
	f1.b = 2;
	f1.c = 80;
	f1.d = 15;
	
	printf("%d\n", f1.e);

	//����ü�� �÷��� �ʵ� �����
	struct Flags2 f2;
	f2.a = 0xffffffff; //0xffffffff 32��Ʈ�� ǥ���� ����ū���� �ǹ� => a�� ��Ʈ �ʵ�� 2�̹Ƿ� 11��µ�
	f2.b = 0xffffffff;
	f2.c = 0xffffffff;
	//11 1 111111 => 3 1 63
	printf("%u%u%u\n", f2.a,f2.b,f2.c); 
	


	//������ ����ϱ� => ������ �������� ������ �����ϱ� ������
	const int ValueA = 1;
	const int ValueB = 2;
	const int ValueC = 3;

	//������ ���� ����
	enum DayOfWeek week;
	week = Tuesday; //���������� �ش� ���� �ε������� ������
	printf("������ ������ %d\n", week);


	//������ switch ����ϱ�
	enum LuxSkill skill; //������ ���� ����
	skill = LightBinding; //������ �����ȿ� �ش� ���� �ε������� ������ => 1
	switch (skill) {
	case LightBinding : 
		{
		printf("LightBinding\n");
		break;
		}
	case PrismaticBarrier :
		{
		printf("PrismaticBarrier\n");
		break;
		}
	case LucentSigngularity :
		{
		printf("LucentSigngularity\n");
		break;
		}
	case FinalSpark :
		{
		printf("FinalSpark\n");
		break;
		}
	default :
	{
		printf("�ش����\n");
		break;
	}
	}

	//�������� ������ص� �������� ���ó�� �����ü� �ִ�.
	for (DayOfWeek3  i = Sunday3; i < DayOfWeekCount3; i++) //�������� ���� ���� �Ἥ �ݺ��� ��������
	{
		printf("������ : %d\n", i);
	}



	//�ڷ��� ��ȯ�ϱ�
	//char -> short -> int -> long -> long long -> float -> double -> long double


	//������ ����ȯ�ϱ�
	int* numPtr = malloc(sizeof(int));
	char* cPtr; //ĳ���� ������ ����

	*numPtr = 0x12345678;

	cPtr = (char*)numPtr; //char�� �����ͷ� ����ȯ => 1����Ʈ ũ���� little endian ������� 78�� �Ҵ�� 

	printf("0x%x\n", *cPtr);//�������� ���� ������� => 0x ���̹Ƿ� 16�������λ�� => %x 
	printf("0x%x\n", *(char*)cPtr); //����ȯ �ϸ鼭 ������ �ϱ�

	free(numPtr);




	//������ ����
	short* numPtr11 = malloc(sizeof(short));
	int* numPtr12;
	
	numPtr11 = malloc(sizeof(short)); //short �޸� ���� �����Ϳ� �ο�

	*numPtr11 = 0x1234;
	numPtr12 = (int *)numPtr11;//������ ����ȯ�� �Ͼ�� ������ �Ƚᵵ �Ǳ���

	printf("�� ��ȯ : 0x%x\n", *numPtr12); 
	//0xfdfd1234 1234�տ� ������ ���� ������, ��������� ���� ���������ϱ� �׷�
	free(numPtr11);

	
	
	//void ������ ����ȯ
	int num10 = 10;
	float num11 = 3.5f;
	char c1 = 'a';
	void* ptr400; // �������� �Ҽ� ������ ����ȯ�ؼ� �������� ��밡��

	ptr400 = &num10; //int �� �����ͷ� ����
	printf("%d\n", *(int*)ptr400); //int�� �����ͷ� ����ȯ�ϰ� ������ �ϱ�
	
	ptr400 = &num11;
	printf("%f\n", *(float*)ptr400);//float �� �����ͷ� �� ��ȯ�ϰ� �������ϱ�

	ptr400 = &c1;
	printf("%c\n", *(char*)ptr400);//char �� �����ͷ� �� ��ȯ�ϰ� �� �����ϱ�


	//void �����Ϳ� ����ü ������ ����ȯ
	struct Data *data100 = malloc(sizeof(struct Data));//����ü ������ ������ �޸� �Ҵ�
	void *ptr100; //void ������ ����

	data100->c1 = 'a';
	data100->num1 = 10;

	ptr100 = data100;//������ ����� & �ʿ����
	printf("���� %c\n", ((struct Data*)ptr100)->c1);
	//void �����͸� ����ü �����ͷ� ����ȯ ��Ų���� ����ü�����Ϳ��� ���� ������
	printf("%d\n", ((struct Data*)ptr100)->num1);
	
	free(data100);//���� �޸� ����


	//����ü ������ ��Ī ����
	PData dt100 = malloc(sizeof(Data2));//����ü ������ �޸� �Ҵ�
	void* ptr101; //void ������ ����
	
	dt100->c100 = 'a';
	dt100->num100 = 10;

	ptr101 = dt100;
	printf("%c\n", ((Data2*)ptr101)-> c100);
	printf("%d\n", ((PData)ptr101)-> num100);

	free(dt100);



	//������ ���� ����ϱ� (�޸� �����ϱ�)

	//������ ���� ����ϱ�
	//������ ������ �ϸ� �ٸ� �޸� �ּҸ� �ս��� �Ű� �ٴҼ��ִ�.
	int numArr[5] = { 11,22,33,44,55 };
	int *numPtrA;
	int *numPtrB;
	int *numPtrC;

	numPtrA = numArr;//�迭�� ù �ּҰ��� �����Ϳ� ����

	numPtrB = numPtrA + 1; //������ ����
	numPtrC = numPtrA + 2; //������ ����


	printf("%p\n", numPtrA); //11�ּ� ����
	printf("%p\n", numPtrB); //22�ּ� ���� (4����Ʈ ��ŭ �̵�)
	printf("%p\n", numPtrC); //33�ּ� ���� (8����Ʈ ��ŭ �̵�)



	//������ ���� ����ϱ�2
	char* cPtr1 = NULL;
	short* numPtr1000 = NULL;
	long long* numPtr2000 = NULL;

	printf("%p\n", cPtr1 + 1); //00000001 1����Ʈ��ŭ �̵���
	printf("%p\n", numPtr1000 +1);//00000004 1����Ʈ��ŭ �̵���
	printf("%p\n", numPtr2000 + 1);//00000008 1����Ʈ��ŭ �̵���
	

	//������ ���� ������
	int numArr100[5] = { 11,22,33,44,55};
	int* numPtrA100;
	int* numPtrB100;
	int* numPtrC100;


	numPtrA100 = &numArr100[2];//�迭 �ּҸ� �����Ϳ� ���� => 33
	numPtrB100 = numPtrA100;
	numPtrC100 = numPtrA100;
	
	numPtrB100++; // ������ ����
	numPtrC100--; // ������ ����

	printf("%d\n", *numPtrA100); //33�� �޸� �ּ�
	printf("%d\n", *numPtrB100); //44�� �޸� �ּ� (+4����Ʈ �̵�)
	printf("%d\n", *numPtrC100); //22�� �޸� �ּ� (-4����Ʈ �̵�)

	printf("===========================\n");

	//������ ����� ������ ����ϱ�
	int numArr200[5] = { 11,22,33,44,55 };
	int* numPtrA200;
	int* numPtrB200;
	int* numPtrC200;
	
	numPtrA200 = numArr200;
	numPtrB200 = numPtrA200 + 1;
	numPtrC200 = numPtrA200 + 2;

	printf("%d\n", *numPtrB200); //numPtrB200[1]�� ����
	printf("%d\n", *numPtrC200); //numPtrC200[2]�� ����

	//numPtrA200[1] = numPtrA200 + 1; => index 1�� 2�� ��ġ , �����͵� 2�� ��ġ
	//numPtrA200[2] = numPtrA200 + 2; 

	//�迭[ + ��] = *(������+��) => *�� ���������� ��������
	//�迭[ - ��] = *(������ - ��)  

	printf("%d\n", *(numPtrA + 1)); //�����Ϳ��� +1 �� 2index�ּҰ��� ������ ���� ������
	printf("%d\n", *(numPtrA + 2));
	
	// ++ --
	printf("%d\n", *(++numPtrB)); //++�� �ּҰ��� �̵���Ų�� ���������� ���
	printf("%d\n", *(--numPtrB)); //--�� �ּҰ��� �̵���Ų�� ���������� ���

	printf("%d\n", *++numPtrB); //�Ȱ��� ++�ϰ� ������
	printf("%d\n", *--numPtrB); //�Ȱ��� --�ϰ� ������

	printf("%d\n", *(numPtrB++)); //�������ѵ� �ּҰ��� �̵���Ŵ
	printf("%d\n", *(numPtrB--)); //�������ѵ� �ּҰ��� �̵���Ŵ



	//void �� ������ �����ϱ� :void�����ʹ� �ڷ��� ũ�Ⱑ ������ ���� �ʾ� void�� ���� �Ұ���
	void* ptr1000 = malloc(100); //�ڷ��� ���� 100����Ʈ �Ҵ�
	
	printf("%p\n", ptr1000);
	//printf("%p\n", ptr+1); ������ ����.void �����ʹ� ���� �Ұ�

	printf("=============================\n");

	//����ȯ�� �����ϱ�
	

	printf("%p\n", ptr1000);
	printf("%p\n", (int*)ptr1000 + 1); //�ٸ� �����ͷ� ��ȯ�ѵ� ����
	printf("%p\n", (int*)ptr1000 - 1);

	
	void* ptr2000 = ptr1000;//�޸� �ּ� ��ȭ ��ų���� �ٸ� �����Ϳ� ����
	printf("%p\n", ++(int*)ptr2000); //������ ��ȯ�ѵ� ������ ���
	printf("%p\n", --(int*)ptr2000); //������ ��ȯ�ѵ� ������ ���
	printf("%p\n", ((int*)ptr2000)++);// ������ ��ȯ�ѵ� ����� ����
	printf("%p\n", ((int*)ptr2000)--);// ������ ��ȯ�ѵ� ����� ����

	free(ptr1000);


	//������ ����, ���� ����� �޸� ����
	//������ ������ �޶��� �ּҷ� free�Լ� �ʱ�ȭ �Ϸ��� �ϸ� ������
	//�޸� �����Ҷ��� �ݵ�� ó�� �޸��ּҸ� ����ؾ���


	/*
		*((�ڷ��� *)void������ + ��)
		*((�ڷ��� *)void������ - ��)
		*(++(�ڷ��� *)void����s��)
		*(--(�ڷ��� *)void������)
		*(((�ڷ��� *)void������)++)
		*(((�ڷ��� *)void������)--)
	*/

	//������ �� Ȯ��
	int numArr1000[5] = { 11,22,33,44,55 };
	void* ptr3000 = &numArr1000[2]; //numArr1000 �ּҰ� �迭�� �Ҵ� ����
	
	printf("%d\n", *(int*)ptr3000); //33
	printf("%d\n", *((int*)ptr3000 + 1)); //44
	
	//ptr--�� ptr - 1�� �ٸ�!!! => ptr--�� ptr = ptr -1��
	printf("%d\n", *((int*)ptr3000 - 1)); //22 => �ּҿ��� -4����Ʈ �� ������ ��µ�
	printf("%d\n", *(++(int*)ptr3000)); //44
	printf("%d\n", *(int*)ptr3000); //44

	//free(ptr3000); => �ּҰ��� ���ؼ� �ʱ�ȭ�� �ȵ�;; ������ ������


	//����ü �����ͷ� ������ �����ϱ�
	struct Data3 dt1[3] = { {10,20},{30,40},{50,60} };
	struct Data3* ptr401;

	ptr401 = dt1;//������ ����ü�� ����ü�迭 �Ҵ�
	printf("%d %d\n", (ptr401+1)->num1, (ptr401+1)->num2); //+1�ϸ� ����ü �迭�� ���� ����ü�� {30,40} ����
	printf("%d %d\n", (ptr401+2)->num1, (ptr401+2)->num2); //50,60

	//free(ptr401); => �� �ȵǴ��� �𸣰���;; (�ּҰ��� �Ⱥ���)

	printf("=================================end1\n");

	num1 = *(numPtr + 3);
	num2 = *((int*)ptr + 2);

	//void �����ͷ� ����ü������ �����ϱ�
	void* ptr402 = malloc(sizeof(struct Data3) * 3);//����ü �迭 ��ŭ �޸� ����
	
	struct Data3 dt3[3];//����ü �迭 3�� ����

	//����ȯ�� ����ü�� �� �Ҵ� => dt3�� ���� �Ѱ� �ƴ϶� dt3�� �ƹ��� ������ ����

	((struct Data3*)ptr402)->num1 = 10; //[0] �迭 ����ü�� ������ ������ �� �Ҵ�
	((struct Data3*)ptr402)->num2 = 20; //[0] �迭 ����ü�� ������ ������ �� �Ҵ�

	((struct Data3*)ptr402 + 1)->num1 = 30; //[1] �迭 ����ü�� ������ ������ �� �Ҵ�
	((struct Data3*)ptr402 + 1)->num2 = 40; //[1] �迭 ����ü�� ������ ������ �� �Ҵ�

	((struct Data3*)ptr402 + 2)->num1 = 50; //[2] �迭 ����ü�� ������ ������ �� �Ҵ�
	((struct Data3*)ptr402 + 2)->num2 = 60;	//[2] �迭 ����ü�� ������ ������ �� �Ҵ�

	//void �����Ϳ� dt3�� �ƹ��� ���谡 �����Ƿ� dt3�� �����Ⱚ�� �������
	printf("%d %d\n", dt3[0].num1, dt3[0].num2);
	
	//�׷��� dt3����ü �迭�� void �����Ͱ��� ��������
	//  ������� ������, ������ ������ , ������ ũ��
	memcpy(dt3, ptr402, sizeof(struct Data3) * 3); //�޸� �����Ҷ� ��� => �� �Ҵ�����

	printf("%d %d\n", dt3[0].num1, dt3[0].num2);//void���� �Ҵ���� ���� ����ü�� ��
	printf("%d %d\n", ((struct Data3*)ptr402 + 2)->num1, ((struct Data3*)ptr402 + 2)->num2);

	free(ptr402);//void �����ͷ� ���� �ּҰ� �̵�������, ��밡��





	printf("=============== ����============\n");
	return 0;
}