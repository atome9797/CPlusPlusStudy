#include <stdio.h>

struct Calc {
	int (*fp)(int, int);
};

int add(int a, int b) {
	return a + b;
}

void executer(int (*fp)(int, int)) {
	printf("%d\n", fp(10,20));
}




int main() {
	
	//�Լ� ������ ����ü ��� ����ϱ�
	struct Calc c;

	c.fp = add; //����ü ����� �Լ� �����͸� ����

	printf("%d\n", c.fp(10, 20));//����ü ���� �ؼ� ������ �Լ� ȣ�� 
	
	executer(add);//�Լ� ������ ȣ�� => add�Լ��� �޸� �ּҸ� ����
	


}