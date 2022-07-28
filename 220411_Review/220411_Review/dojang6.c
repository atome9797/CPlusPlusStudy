#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>    // malloc, free �Լ��� ����� ��� ����
#include <string.h>    // memset �Լ��� ����� ��� ����
struct Calc {
	int (*fp)(int, int);
};

int add(int a, int b) {
	return a + b;
}

int sub(int a, int b) {
	return a - b;
}


struct Calc4 {
	int (*fp4[2]) (int, int);
};

int executer4(int (* fp4)(int, int), int a, int b) {
	return fp4(a, b); //�Լ��� ���ϰ����� ����=> �Լ��� �����ͷ� ����
}

//�Լ� �����ͷ� ����
int (* getFunc4(struct Calc4* c, int index)) (int, int) {
	return c->fp4[index];
}



//�Լ� �����͸� �Լ��� �Ű������� ����ϱ�
void executer(int (*fp)(int, int)) {
	printf("%d\n", fp(10,20));
}



//getAdd��� �������Լ��� add�Լ� �ּҰ��� ����
int (*getAdd())(int, int) { //int (*fp)(int, int) getAdd() �� �����Ѱ�
	return add;
}



//�Ű������� �ִ� �Լ� ������ ��ȯ�ϱ�
//�Ű������� �ִ� ������ �Լ��� add�Լ� �ּҰ��� ����
int (*getAdd2(int x, int y))(int, int) {
	printf("�Լ� %d %d\n", x, y);
	return add;
}

//��Ī���� �Լ� ������ ����
typedef int (*FP)(int, int);


//��Ī���� ��ȯ�� ����
FP getAdd3() {
	return add;
}

//����ü �Լ� ������ ���
typedef int (*FP2)(int, int);

//����ü�� �Լ� �ɹ��� �ޱ�
struct Calc2 {
	FP2 fp2;
};


//�Լ� �����͸� �Ű������� �޴� �Լ� ����
void executer2(FP2 fp2) {
	printf("%d\n", fp2(70,80));
}


struct Person {
	char name[30];
	int age;
	void (*print)(struct Person*);
};

void print(struct Person* p)
{
	printf("�� %s %d\n", p->name, p->age);
}

void executer3(void (*fp[])(struct Person*), struct Person p[], int count)
{
	for (int i = 0; i < count; i++)
	{
		fp[i](&p[i]);
	}
}

//void �Լ��� ���ϰ��� �����Ҽ� �ִ�.
//������ �Լ��� ���� �Լ��� ���� => ���۱���
//p�� ������ �Լ��� �ҷ��;� ������ ���ڰ� �ƴ� �Ű������� �ִ� �Լ��� ���ϰ��� �����ؾ���
void (* getPrintFunc(struct Person* p))(struct Person *) {
	return p->print;
}

//�̷��� ���ϰ� �ּ� �Ҵ����� ��밡��
void *getPrintFunc2(struct Person *p) {
	return p->print;
}


#pragma pack(push, 1)    // 1����Ʈ ũ��� ����
struct Data {
	char c1;        //  1����Ʈ
	short num1;     //  2����Ʈ
	int num2;       //  4����Ʈ
	char s1[20];    // 20����Ʈ
};
#pragma pack(pop)        // ���� ������ ���� ����(�⺻��)�� �ǵ���


int main() {
	
	struct Calc4 c4 = { { add, sub } };

	printf("��� : %d\n", executer4(getFunc4(&c4, 0), 10, 20));
	printf("��� : %d\n", executer4(getFunc4(&c4, 1), 10, 20));



	//�Լ� ������ ����ü ��� ����ϱ�
	struct Calc c;

	c.fp = add; //����ü ����� �Լ� �����͸� ����

	printf("%d\n", c.fp(10, 20));//����ü ���� �ؼ� ������ �Լ� ȣ�� 
	

	//�Լ� �����͸� �Լ��� �Ű������� ����ϱ�
	executer(add);//�Լ� ������ ȣ�� => add�Լ��� �޸� �ּҸ� ����
	
	
	
	//�Լ� �����͸� �Լ��� ��ȯ������ ����ϱ�
	//getAdd �������Լ��� �ҷ� add�ּҰ��� ������
	printf("%d\n", getAdd()(10, 20));


	//������ ȣ���Լ� =>�������� add �Լ� ȣ�� => add�Լ��� ���� 10,20���
	printf("%d\n", getAdd2(8,9)(10,20));

	
	//typedef �Լ� ������ ��Ī �����ϱ�
	//��ȯ���ڷ����� �Ű������ڷ����� ������ִ°� full pointer type�̶�� �ϴµ�, ����ϱ� ���ŷο�
	//��Ī���� �Լ� ������ ���
	printf("%d\n", getAdd3()(10,20));

	
	FP2 fp2; //���ϰ��� ���� �Լ� ������
	fp2 = add; //�Լ� �����Ϳ� �Լ��ּҸ� �Ҵ�
	printf("%d\n", fp2(10, 20));//�Լ� �����ͷ� add�Լ��� �ҷ��� 

	FP2 fp3[10]; //�Լ� ������ �迭 ���� int (*FP2[10])(int, int); �� ����
	fp3[0] = add;
	printf("%d\n", fp3[0](30, 40));

	struct Calc2 c2;
	c2.fp2 = add; //����ü ������ �Լ��� �����ؼ� add�Լ��� �ּҸ� �Ҵ���
	printf("%d\n", c2.fp2(50, 50));

	//executer�Լ��� ���ڷ� add�Լ��� ������ fp ������ �Լ��� ������Ų��. => ���� ���

	executer2(add);


	//�Լ� ����2
	struct Person p[3]; //����ü ����
	p[0].print = print; //����ü�� �Լ������Ϳ� �Լ��ּһ��� => ���� 
	p[1].print = print; //����ü�� �Լ������Ϳ� �Լ��ּһ��� => ����
	p[2].print = print; //����ü�� �Լ������Ϳ� �Լ��ּһ��� => ����

								//���ڿ��� �ּ� ��������, int�� �������
	//scanf("%s %d %s %d %s %d", p[0].name, &p[0].age, p[1].name, &p[1].age, p[2].name, &p[2].age);


	void (*fp4[3])(struct Person*);//����ü �����͸� ���ڷ� �޴� ������ �Լ� �迭 ����


	for (int i = 0; i < sizeof(p)/sizeof(struct Person); i++) //�迭�� 3��ŭ �ݺ�
	{
		fp4[i] = getPrintFunc2(&p[i]); //����ü�� ������ ������ �Լ��� ����
	}


	executer3(fp4, p, sizeof(p) / sizeof(struct Person)); //������ �Լ��� ����ü , �迭 3ũ�⸦ ����
	

	//���Ͽ��� ���ڿ��� �а� ����
	//���� ������
	FILE* fp5 = fopen("hello.txt", "w");
	fprintf(fp5, "%s %d\n", "hello", 100);
	fclose(fp5);

	//���Ͽ��� ���ڿ� �б�
	char s1[10];
	int num1;
	FILE* fp6 = fopen("hello.txt", "r");
	fscanf(fp6, "%s %d", s1, &num1); //������ �����Ͽ� ���ڿ� �б�
	
	printf("%s %d\n", s1, num1);
	fclose(fp6);
	
	//���Ͽ��� ���ڿ� ����
	FILE* fp7 = fopen("hello.txt", "w");
	fputs("Hello, world", fp7);
	fclose(fp7);

	char* s10 = "Hello, world!";
	FILE* fp8 = fopen("hello.txt", "w");
	fwrite(s10, strlen(s10), 1, fp8);
	fclose(fp8);
	
	//���Ͽ��� ���ڿ� �б�
	char buffer[20];
	FILE* fp9 = fopen("hello.txt", "r");
	fgets(buffer, sizeof(buffer), fp9);
	fclose(fp9);
	

	char buffer2[20];
	FILE* fp10 = fopen("hello.txt","r");
	fread(buffer2, sizeof(buffer2), 1, fp10); //���� ũ�⸸ŭ ���� ���������� ���ڿ� ������
	printf("���� �� : %s\n", buffer2);
	fclose(fp10);



	//����ũ�� ���ϱ�
	int size;
	FILE* fp11 = fopen("hello.txt", "r");
	//      �̵��� ũ��, ������ 
	// SEEK_SET : ������ ó�� ���� �̵��� ����
	// SEEK_CUR : ���� ��ġ ���� �̵��� ����
	// SEEK_END : ������ ������ �̵��� ����
	fseek(fp11, 0, SEEK_END);//���� �����͸� ������ ������ �̵���Ŵ
	size = ftell(fp11);//���� �������� ���� ��ġ�� ����
	printf("%d\n", size);
	fclose(fp11);//���� �ݱ�

	//���� ũ�� ��ŭ �б�
	char* buffer3;
	int size3;
	int count;

	FILE* fp12 = fopen("hello.txt", "r");
	fseek(fp12, 0, SEEK_END);
	size3 = ftell(fp12);//���ڿ� ���̸� ��ȯ

	buffer3 = malloc(size3 + 1);
	memset(buffer3, 0, size3 + 1); //char �����͸� 0���� �ʱ�ȭ

	fseek(fp12, 0, SEEK_SET); //������ ��ġ�� �� ó�� ��ġ�� �̵���Ŵ
	count = fread(buffer3, size3, 1, fp12); //fp12�����͸� buffer�� ���� => ������ 1��ȯ

	printf("%s size: %d, count : %d\n", buffer3, size3, count);
	fclose(fp12);
	free(buffer3);

	//������ �κ������� �а� ���� 1
	char buffer4[10] = { 0, };
	FILE* fp13 = fopen("hello.txt", "r");

	fseek(fp13, 2, SEEK_SET);//���� ���� ó�� ������ġ���� 2����Ʈ ��ŭ ������
	fread(buffer4, 3, 1, fp13);//3����Ʈ ��ŭ �б�,3����Ʈ ��ŭ ������

	printf("%s\n", buffer4);//llo
	memset(buffer4, 0, 10);//pointer to char �ʱ�ȭ

	fseek(fp13, 3, SEEK_CUR);//���� ��ġ���� 3����Ʈ �̵�
	fread(buffer4, 4, 1, fp13);//���� ��ġ���� 4����Ʈ ��ŭ �б�
	
	printf("%s\n", buffer4); //orld
	fclose(fp13);
	
	//������ �κ������� �а� ���� 2
	char* s11 = "abcd";
	char buffer5[20] = { 0, };
	FILE* fp14 = fopen("hello.txt", "r+"); //r+�� ���� �б�/���� ���
	fseek(fp14, 3, SEEK_SET);//��ó������ 3����Ʈ �̵�
	fwrite(s11, strlen(s11), 1, fp14);//���ڿ� �� ���Ͽ� ����
	
	rewind(fp14);//���� �����͸� ������ �� ó������ �̵���Ŵ
	fread(buffer5, 20, 1, fp14); //���� ��ġ���� fp14�� 20����Ʈ �о char*�� ����

	printf("���� : %s\n", buffer5);
	fclose(fp14);

	
	//���ѵ� ���۷� ���� ��ü �б�
	//������ ������ �˻��ϴ� �Լ� feof
	
	char buffer6[5] = { 0, };
	int  count2 = 0;
	int total = 0;
	FILE* fp15 = fopen("hello.txt", "r");

	//������ ���� �ƴϸ� 0, ������ ���̸� 1�� ��ȯ��
	while (feof(fp15) == 0) {
		count2 = fread(buffer6, sizeof(char), 4, fp15);//1����Ʈ �� 4�� �����͸� �о�� => 4����Ʈ ����
		printf("�� %s\n", buffer6);
		memset(buffer, 0, 5);//5����Ʈ ��ŭ �޸�0���� �ʱ�ȭ => ������ null����
		total += count2;//������ 1��ȯ
	}

	printf("\ntotal: %d\n", total);
	fclose(fp15);


	//���Ͽ��� ����ü�� �а� ����
	//������ �ؽ�Ʈ ���ϰ� ���̳ʸ� ����(2�� ����)�� ������ ����
	//������ ���̳ʸ� ������

	struct Data d1;
	memset(&d1, 0, sizeof(d1));    // ����ü ������ ������ 0���� �ʱ�ȭ

	d1.c1 = 'a';                       // ���� ����
	d1.num1 = 32100;                   // 2����Ʈ ũ���� ���� ����
	d1.num2 = 2100000100;              // 4����Ʈ ũ���� ���� ����
	strcpy(d1.s1, "Hello, world!");    // ���ڿ� ����

	FILE* fp16 = fopen("data2.csv", "wb");   // ������ ����/���̳ʸ� ���(wb)�� ����

	fwrite(&d1, sizeof(d1), 1, fp16);        // ����ü�� ������ ���Ͽ� ����

	fclose(fp16);    // ���� ������ �ݱ�


	//���Ͽ��� ����ü �б�
	FILE* fp17 = fopen("data2.csv", "rb");
	fread(&d1, sizeof(d1), 1, fp17);
	printf("%c %d %d %s\n", d1.c1, d1.num1, d1.num2, d1.s1);    // a 32100 210
	fclose(fp17);






}