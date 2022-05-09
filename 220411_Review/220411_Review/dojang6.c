#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

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
	



}