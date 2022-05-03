#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void hello();// �Լ��� �Ʒ��� ���� ������ [�Լ� ����] ��������� ��밡��

int one() {
	return 1;
}

float onePointOne() {
	return 1.1f;
}

//������ �Լ�
int* ten() { //ten�̶�� �Լ��� int�� �����ͷ� ��ȯ
	int num1 = 10;
	return &num1;//�����ͷ� ��ȯ�ϱ� ������ �ּҰ��� �־��� => �ּҸ� �����Ͱ� �ް� ��ȯ��
	//�Լ����� ���������� �ּҸ� ��ȯ�ϴ°��� �߸��� �����
}

int* ten2() {
	
	//�����͸� ��ȯ�Ϸ��� malloc�Լ��� �޸� �Ҵ��� ���
	int* numPtr2 = malloc(sizeof(int)); //mallic���� �޸��Ҵ��ϸ� �Լ��� ������ ������� ����
	*numPtr2 = 10;

	return numPtr2;
}

char* helloLiteral()       // char �����͸� ��ȯ�ϴ� helloLiteral �Լ� ����
{
	char* s1 = "Hello, world!";

	return s1;    // ���ڿ� Hello, world!�� �޸𸮿� ����Ǿ� �����Ƿ� ������� ����
				  // ���ڿ� ������ ����
}

char* helloDynamicMemory()    // char �����͸� ��ȯ�ϴ� helloDynamicMemory �Լ� ����
{
	char* s1 = malloc(sizeof(char) * 20);    // char 20�� ũ�⸸ŭ ���� �޸� �Ҵ�

	strcpy(s1, "Hello, world!");    // Hello, world!�� s1�� ����

	return s1;   // ���ڿ� ������ ����
}

//void ������ ��ȯ�ϱ�
//�ڷ� �� ��� ���� ���� �������� ������ ���
void* allocMemory() {
	void* ptr = malloc(100);
	return ptr;
}

//����ü ����
struct Person {
	char name[20];
	int age;
	char address[100];
};

//����ü�� ��ȯ�ϴ� getPerson �Լ�����
struct Person getPerson() {
	struct Person p;
	strcpy(p.name, "�迵��");
	p.age = 30;
	strcpy(p.address, "����� ������");
	return p;
}

//�޸� ������ �����ϱ� ���� ������ ����ü �Լ� ���
struct Person* allocPerson() {
	
	struct Person* p = malloc(sizeof(struct Person));
	strcpy(p->name, "ȫ�浿");
	p->age = 20;
	strcpy(p->address, "����");

	return p;
}

//����ü ��Ī ����ϱ�
typedef struct _Person3 {
	char name[20];
	int age;
	char address[100];
} Person3, *PPerson3; //����ü ��Ī�� ������ ��Ī�� ��ȯ


//�����ͷ� ��ȯ => ��Ī���� ��밡�� 
PPerson3 allocPerson3() {
	//������ ���� ����
	PPerson3 p = malloc(sizeof(Person3));
	strcpy(p->name, "�����");
	p->age = 30;
	strcpy(p->address, "����");
	return p;
}

//����ü�� ������ ��ȯ�ϱ�
union Box {

	short candy;
	float snack;
	char doll[8];
};

enum BOX_TYPE {
	BOX_PAPER =0,
	BOX_WOOD,
	BOX_PLASTIC
};

//���ϰ��� ����ü��
union Box getBox () {
	
	union Box b1;
	b1.candy = 10;
	return b1;
};

//���ϰ��� ��������
enum BOX_TYPE getBoxType() {

	return BOX_WOOD;
};

//�Լ��� �Ű����� ���
void helloNumber(int num1) {
	printf("Hello, %d\n",num1);
}

//�����Լ� �����
int add(int a, int b) {
	return a + b;
}

//�Լ��� �Ű������� ������ ����ϱ�
void swapNumber(int* first, int* second) {
	int temp;
	temp = *first;
	*first = *second;
	*second = temp;
}

//�Ű����� �����Ϳ� in,out
//c��� ������ �ƴ����� ����� �˾ƺ��� �ֵ��� �����Ѱ� 
#define IN
#define OUT
void GetValue(IN int *a, OUT int* b) { //a�� �Էµ� �Ű�����, b�� ���ϵǴ� �Ű�����
	printf("%d\n", a);
	*b = 10;
}

enum TYPE {
	TYPE_CHAR,
	TYPE_INT,
	TYPE_FLOAT
};

//Ÿ�� �ٲ��ִ� �Լ�
void swapValue(void* ptr1, void* ptr2, enum TYPE t) {
	switch (t) {
	case TYPE_CHAR:
		{
			char temp;
			temp = *(char*)ptr1;
			*(char*)ptr1 = *(char*)ptr2;
			*(char*)ptr2 = temp;
			break;
		}
	case TYPE_INT:
		{
			int temp;
			temp = *(int*)ptr1;
			*(int*)ptr1 = *(int*)ptr2;
			*(int*)ptr2 = temp;
			break;
		}
	case TYPE_FLOAT:    // �Ǽ��� float *�� ��ȯ�� �� �������Ͽ� ���� ���� �ٲ�
		{
			float temp;
			temp = *(float*)ptr1;
			*(float*)ptr1 = *(float*)ptr2;
			*(float*)ptr2 = temp;
			break;
		}
	}
}


//ptr �����Ϳ� �޸𸮸� �Ҵ������� main���� ����� �����Ϳ��� �������
void allocMemory2(void* ptr, int size)  
{
	ptr = malloc(size);    // ptr�� allocMemory�� ����� ����� �� ���� => ���ϰ��� �Ҵ� ���ؼ� �׷�
}


//���������Ϳ� main���� ����� �����͸� �־��ְ�
//�������� main���� ����� �����Ϳ� �޸𸮸� �Ҵ��ѰŶ� �Ҵ簡�� 
void allocMemory3(void **ptr, int size)   
{
    *ptr = malloc(size);    // void **ptr�� �������Ͽ� void *ptr�� �޸� �Ҵ�
}


void helloString(char *s1) {
	printf("Hello, %s\n",s1);
}


void helloString2(char s1[])    // ��ȯ�� ����, char �迭�� �Ű������� ����, ũ�� ����
{
	printf("Hello, %s\n", s1);    // Hello, �� �Ű������� �����Ͽ� ���ڿ� ���
}


//�迭�� �Ű����� ����ϱ�
void printfArray(int arr[], int count) {
	for (int i = 0; i < count; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void setElement(int arr[]) {
	arr[2] = 300; //arr[]�� �迭�̰� �迭�� ������ Ÿ���̱� ������ �� ���� ����
}


//�Ű������� �����ͷ� �����Ͽ� �迭�� ����
void printArray(int* arr, int count) {
	for (int i = 0; i < count; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}


void swapElement(int arr[], int first, int second) {
	int temp;
	temp = arr[first];
	arr[first] = arr[second];
	arr[second] = temp;
}



//���� ���ͷ�  ����ϱ�
//�迭 ���� ������� ��밡��
void printArray2(int arr[], int count) {
	
	for (int i = 0; i < count; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}


//2���� �迭�� �Ű� ������ ����Ҷ��� ��� ���� ������ �����
void print2DArray(int arr[][5], int col, int row) {
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

//pointer to array�� �Լ������� ����ϱ�
void print2DArray2(int (*arr)[5], int col, int row) {
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

void setIdentityMatrix(float(*arr)[4], int col) {
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (i == j) {
				arr[i][j] = 1.0f;
			}
		}

	}
}


//����ü ����
struct Person2 {
	char name[20];
	int age;
	char address[100];
};

void printPerson(struct Person2 p) {
	printf("�̸�: %s\n", p.name);
	printf("����: %d\n", p.age);
	printf("�ּ�: %s\n", p.address);
}

void setPerson(struct Person2 p) {
	strcpy(p.name, "�迵��");
	p.age = 30;
	strcpy(p.address, "���� ������");
}

void setPerson2(struct Person2 *p10) {
	strcpy(p10->name, "ö��");
	p10->age = 40;
	strcpy(p10->address, "���� ������");
}


//����ü ��Ī ����ϱ�
typedef struct _Person {
	char name[20];
	int age;
	char address[100];
} Person, *PPerson;


void setPerson3(PPerson p) {
	strcpy(p->name, "�迵��");
	p->age = 40;
	strcpy(p->address, "����� ������ �߰");
}


union Box2 {
	short candy;
	float snack;
	char doll[8];
};

enum BOX_TYPE2 {
	BOX_PAPER = 0,
	BOX_WOOD,
	BOX_PLASTIC
};

void printBox(union Box box) {
	printf("%d\n", box.candy);
}

void printBoxType(enum BOX_TYPE boxType) {
	printf("%d\n", boxType);
}


int main() {

	//�Լ� ����� ���� �и��ϱ�
	hello();


	//�Լ����� ��ȯ�� ����ϱ�
	int num = one();
	printf("%d\n", num);

	num = (int)onePointOne();//float�� int���� ����ȯ��
	printf("%d\n", num);
	
	//������ ��ȯ�ϱ�
	int* numPtr;
	numPtr = ten(); //�����ͳ��� �ּ� ���� //10���� ������ ������ �̹� ����� ������ ����ϰ� ����
	printf("%d\n",*numPtr);//������ �� ��� 

	//malloc���� �Ҵ�� �ּ� ��ȯ
	int* numPtr2;
	numPtr2 = ten2(); //�޸� �����ϱ� ������ ������
	printf("%d\n", *numPtr2);
	free(numPtr2); //main���� ������ �ص� �Լ����� ����� �޸𸮸� �����ű⶧����, �Լ� �޸𸮰� ������
	

	char* s1;
	char* s2;

	s1 = helloLiteral();
	s2 = helloDynamicMemory();

	printf("%s\n", s1);    // Hello, world!
	printf("%s\n", s2);    // Hello, world!

	free(s2);    // ���� �޸� ����


	//void ������ ��ȯ�ϱ�
	//�ڷ� �� ��� ���� ���� �������� ������ ���
	char* ptr3 = allocMemory();// void�����Ͱ� char�����ͷ� ����ȯ�� (�޸𸮴� 100)
	strcpy(ptr3, "Hello, world");
	printf("%s\n", ptr3);
	free(ptr3);

	int* ptr4 = allocMemory();// void�����Ͱ� int�����ͷ� ����ȯ�� (�޸𸮴� 100 ����Ʈ)
	ptr4[0] = 10; //25������ ���� 
	ptr4[1] = 20;

	printf("%d %d\n", ptr4[0], ptr4[1]);
	free(ptr4);


	//����ü�Լ�
	struct Person p1;
	p1 = getPerson(); 
	//����ü�� ��ȯ�ϴ� �Լ��� ����ü�� ���� 
	//struct Person�� �������
	//p1���� ���� ����� ���ο� ������ ������� => ���ο� ���뿡 �Լ����� ������ ���� �Ҵ������ ���� �Ҵ��
	//struct�� �����ϰ� ���°� �ƴ϶� �����Ҷ����� ���� ���Ҵ� �������

	printf("�̸� : %s\n", p1.name);
	printf("���� : %d\n", p1.age);
	printf("�ּ� : %s\n", p1.address);

	//�޸� ������ �����ϱ� ���� ������ ����ü �Լ� ���
	//���� �޸𸮴� ������ٰ� ��������
	//�׸��� ���ϴ� �޸𸮸� �����ü� �־ �ٸ� �޸� ���� �����൵��
	struct Person *p2;
	p2 = allocPerson();//�����Ϳ� �Ҵ�

	printf("�̸� : %s\n",p2->name);
	printf("���� : %d\n",p2->age);
	printf("�ּ� : %s\n",p2->address);
	
	free(p2);//�Լ����� ���� �޸� ����
	

	//����ü ������ ��Ī ���
	PPerson3 pps;
	pps = allocPerson3();
	printf("�̸� : %s\n", pps->name);
	printf("���� : %d\n", pps->age);
	printf("�ּ� : %s\n", pps->address);

	//����ü�� ������ ��ȯ�ϱ�
	union Box box;
	enum BOX_TYPE boxType;
	box = getBox(); //box �����ȿ��� candy���� �������
	boxType = getBoxType();

	printf("%d\n", box.candy);
	printf("%d\n", boxType); //������ ���� �������



	//�Լ����� �Ű����� ����ϱ�
	helloNumber(10);
	helloNumber(30);

	//�����Լ�
	int num1;
	num1 = add(20, 30);
	printf("%d\n", num1);


	//�Լ����� ������ �Ű����� ����ϱ�
	int num2 = 10;
	int num3 = 40;
	swapNumber(&num2, &num3);//�޸� �ּҸ� �����Ϳ� �Ҵ�
	printf("%d %d\n", num2, num3);

	int num4 = 30;
	int num5 = 20;
	GetValue(&num4,&num5);
	printf("��� : %d %d\n", num4, num5);
	

	//void ������ �Ű����� ����ϱ�
	char c1 = 'a';
	char c2 = 'b';
	swapValue(&c1, &c2, TYPE_CHAR);
	printf("%c %c\n", c1, c2);

	int num6 = 10;
	int num7 = 20;
	swapValue(&num6, &num7, TYPE_INT);   // ������ �޸� �ּҿ� TYPE_INT�� ����
	printf("%d %d\n", num6, num7);       // 20 10: swapValue�� ���ؼ� ���� ���� �ٲ�


	float num8 = 1.234567f;
	float num9 = 7.654321f;
	swapValue(&num8, &num9, TYPE_FLOAT);  // ������ �޸� �ּҿ� TYPE_FLOAT�� ����
	printf("%f %f\n", num8, num9);        // 7.654321f 1.234567: 
										  // swapValue�� ���ؼ� ���� ���� �ٲ�



	//���������� �Ű����� ����ϱ�
	long long* numPtr4 = NULL;

	// numPtr�� �Ҵ��� ũ�⸦ �־��� 
	//allocMemory2(numPtr4, sizeof(long long));

	//*numPtr4 = 10;    // �޸𸮰� �Ҵ���� �ʾ����Ƿ� ���� ����
	//printf("���࿡�� : %lld\n", *numPtr4);

	//free(numPtr4);


	long long* numPtr5;
	allocMemory3((void**)&numPtr5, sizeof(long long));
	*numPtr5 = 10;
	printf("%lld\n", *numPtr5);
	free(numPtr5);    // ���� �޸� ����
	


	//���ڿ� �Ű����� ����ϱ�
	char s100[10] = "world!";
	helloString(s100);
	helloString2("world!");
	

	
	//�迭�� �Ű����� ����ϱ�
	int numArr[10] = {1,2,3,4,5,6,7,8,9,10};
	printfArray(numArr, sizeof(numArr) / sizeof(int));
	
	int numArr2[10] = { 1,2,3,4,5,6,7,8,9,10 };
	setElement(numArr2);
	printf("%d\n", numArr2[2]);


	//�迭�� �����ͷ� �޾� �Ű����� ����ϱ�
	int numArr3[10] = { 1,2,3,4,5,6,7,8,9,10 };
	printArray(numArr3, sizeof(numArr3) / sizeof(int));
	
	//�迭�� ��� �ٲٱ�
	int numArr4[10] = { 1,2,3,4,5,6,7,8,9,10 };
	swapElement(numArr4, 0, 1);//0 index�� 1index �� �ٲٱ�
	printf("%d %d\n", numArr4[0], numArr4[1]);
	

	//���ո��ͷ� ����ϱ�
	//int �迭 ���·� ����ȯ
	printArray2((int[]) { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, 10);
	

	//2���� �迭 �Ű����� ����ϱ�
	int numArr5[2][5] = { {1,2,3,4,5},{6,7,8,9,10} };
	int col = sizeof(numArr5[0]) / sizeof(int); //���� ���� ����
	int row = sizeof(numArr5) / sizeof(numArr5[0]);
	print2DArray(numArr5, col, row);


	//pointer to array�� �Լ������� ����ϱ�
	print2DArray2(numArr5, col, row);

	//���� ���ͷ� ����ϱ�
	print2DArray2((int[2][5]) { {1, 2, 3, 4, 5}, { 6,7,8,9,10 } }, 5,2);


	//���� ��� �����
	float matrix[4][4] = { 0.0f };
	int n = sizeof(matrix[0]) / sizeof(float); //4
	
	setIdentityMatrix(matrix, n);
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%f ", matrix[i][j]);
		}
		printf("\n");
	}


	//����ü �Ű����� ����ϱ�
	struct Person2 p3;
	strcpy(p3.name, "ȫ�浿");
	p3.age = 30;
	strcpy(p3.address, "����� ������ �߰");

	printPerson(p3);


	//���� ���ͷ� ����ϱ�
	printPerson((struct Person2) { .name = "ȫ�浿", .age = 30, .address = "���� �ѳ���" });
	printPerson((struct Person2) { "ȫ�浿", 30, "���� �ѳ���" });

	
	//setPerson���� ������ ���� �Լ� ������ ���ο� ��ü�� ����������
	//�Լ� ������ ������ person p3��ü�� ������ ���� 
	//��ü�� �������� ������ struct ����ü ��ü�� ������ �ִ°��� �ƴ϶�
	// Ÿ�Ը� �޾ƿ��°���
	setPerson(p3); //=> person p3�� ������ ���� ����
	printf("�̸� : %s\n",p3.name);
	printf("���� : %d\n",p3.age);
	printf("�ּ� : %s\n",p3.address);


	//����ü ������ �Ű����� ����ϱ�
	setPerson2(&p3);//����ü�� �ּҸ� �Ѱ���
	printf("�̸� : %s\n", p3.name);
	printf("���� : %d\n", p3.age);
	printf("�ּ� : %s\n", p3.address);


	//���� ���ͷ� 
	setPerson2(&(struct Person2) { .name = "�迵��", .age = 30, .address = "���" });
	setPerson2(&(struct Person2) { "�迵��", 30, "���" });


	//����ü�� ������ �Ű������� ����ϱ�
	union Box2 box2;
	enum BOX_TYPE2 boxType2;
	
	box2.candy = 10;
	boxType2 = BOX_PLASTIC;
	

	//printBox(box);
	//printBoxType(boxType);


	
	
	

	return 0;
}




//�Լ� ��ü
void hello() {
	printf("Hello world\n");
}