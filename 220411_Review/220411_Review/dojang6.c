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


//�Լ� �迭2�� �޴� ������ ����
struct Calc4 {
	int (*fp4[2]) (int, int);
};


//�Լ��� ������Ű�� ������ �Լ��� �Ű������� ����
int executer(int (*fp4) (int, int), int a,int b) {
	return fp(a, b);//�Լ� �����ͷ� add, sub�Լ��� �����ؼ� ȣ��
}


int(*getFunc(struct Calc4 *c4, int index))(int, int) {

	return c4->fp4[index];
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



int main() {
	
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


	//�Լ� ����1
	



}