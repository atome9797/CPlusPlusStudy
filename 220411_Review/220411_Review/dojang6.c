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


//함수 배열2개 받는 포인터 선언
struct Calc4 {
	int (*fp4[2]) (int, int);
};


//함수를 참조시키는 포인터 함수를 매개변수로 받음
int executer(int (*fp4) (int, int), int a,int b) {
	return fp(a, b);//함수 포인터로 add, sub함수에 접근해서 호출
}


int(*getFunc(struct Calc4 *c4, int index))(int, int) {

	return c4->fp4[index];
}





//함수 포인터를 함수의 매개변수로 사용하기
void executer(int (*fp)(int, int)) {
	printf("%d\n", fp(10,20));
}


//getAdd라는 포인터함수로 add함수 주소값을 리턴
int (*getAdd())(int, int) { //int (*fp)(int, int) getAdd() 와 동일한것
	return add;
}


//매개변수가 있는 함수 포인터 반환하기
//매개변수가 있는 포인터 함수로 add함수 주소값을 리턴
int (*getAdd2(int x, int y))(int, int) {
	printf("함수 %d %d\n", x, y);
	return add;
}

//별칭으로 함수 포인터 선언
typedef int (*FP)(int, int);


//별칭으로 반환값 지정
FP getAdd3() {
	return add;
}

//구조체 함수 포인터 사용
typedef int (*FP2)(int, int);

//구조체에 함수 맴버로 받기
struct Calc2 {
	FP2 fp2;
};


//함수 포인터를 매개변수로 받는 함수 선언
void executer2(FP2 fp2) {
	printf("%d\n", fp2(70,80));
}



int main() {
	
	//함수 포인터 구조체 멤버 사용하기
	struct Calc c;

	c.fp = add; //구조체 멤버에 함수 포인터를 저장

	printf("%d\n", c.fp(10, 20));//구조체 접근 해서 포인터 함수 호출 
	

	//함수 포인터를 함수의 매개변수로 사용하기
	executer(add);//함수 포인터 호출 => add함수의 메모리 주소를 전달
	
	
	
	//함수 포인터를 함수의 반환값으로 사용하기
	//getAdd 포인터함수를 불러 add주소값을 리턴함
	printf("%d\n", getAdd()(10, 20));


	//포인터 호출함수 =>리턴으로 add 함수 호출 => add함수의 인자 10,20사용
	printf("%d\n", getAdd2(8,9)(10,20));

	
	//typedef 함수 포인터 별칭 정의하기
	//반환값자료형과 매개변수자료형을 명시해주는게 full pointer type이라고 하는데, 사용하기 번거로움
	//별칭으로 함수 포인터 사용
	printf("%d\n", getAdd3()(10,20));

	
	FP2 fp2; //리턴값이 없는 함수 포인터
	fp2 = add; //함수 포인터에 함수주소를 할당
	printf("%d\n", fp2(10, 20));//함수 포인터로 add함수를 불러옴 

	FP2 fp3[10]; //함수 포인터 배열 선언 int (*FP2[10])(int, int); 과 동일
	fp3[0] = add;
	printf("%d\n", fp3[0](30, 40));

	struct Calc2 c2;
	c2.fp2 = add; //구조체 포인터 함수에 접근해서 add함수의 주소를 할당함
	printf("%d\n", c2.fp2(50, 50));

	//executer함수의 인자로 add함수를 보낸후 fp 포인터 함수에 참조시킨다. => 그후 출력

	executer2(add);


	//함수 예제1
	



}