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
	
	//함수 포인터 구조체 멤버 사용하기
	struct Calc c;

	c.fp = add; //구조체 멤버에 함수 포인터를 저장

	printf("%d\n", c.fp(10, 20));//구조체 접근 해서 포인터 함수 호출 
	
	executer(add);//함수 포인터 호출 => add함수의 메모리 주소를 전달
	


}