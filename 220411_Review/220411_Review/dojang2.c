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
	void* ptr; // �������� �Ҽ� ������ ����ȯ�ؼ� �������� ��밡��

	ptr = &num10; //int �� �����ͷ� ����
	printf("%d\n", *(int*)ptr); //int�� �����ͷ� ����ȯ�ϰ� ������ �ϱ�
	
	ptr = &num11;
	printf("%f\n", *(float*)ptr);//float �� �����ͷ� �� ��ȯ�ϰ� �������ϱ�

	ptr = &c1; 
	printf("%c\n", *(char*)ptr);//char �� �����ͷ� �� ��ȯ�ϰ� �� �����ϱ�


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

	numPtrA = numArr;//�迭 ������ ����

	numPtrB = numPtrA + 1; //������ ����
	numPtrC = numPtrA + 2; //������ ����


	printf("%p\n", numPtrA); //11�ּ� ����
	printf("%p\n", numPtrB); //22�ּ� ���� (4����Ʈ ��ŭ �̵�)
	printf("%p\n", numPtrC); //33�ּ� ���� (8����Ʈ ��ŭ �̵�)

	//������ ���� ����ϱ�2
	char* cPtr1 = NULL;
	short* numPtr1000 = NULL;


	


	return 0;
}