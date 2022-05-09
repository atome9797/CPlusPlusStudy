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
	return fp4(a, b); //함수를 리턴값으로 받음=> 함수의 포인터로 받음
}

//함수 포인터로 선언
int (* getFunc4(struct Calc4* c, int index)) (int, int) {
	return c->fp4[index];
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


struct Person {
	char name[30];
	int age;
	void (*print)(struct Person*);
};

void print(struct Person* p)
{
	printf("함 %s %d\n", p->name, p->age);
}

void executer3(void (*fp[])(struct Person*), struct Person p[], int count)
{
	for (int i = 0; i < count; i++)
	{
		fp[i](&p[i]);
	}
}

//void 함수도 리턴값을 지정할수 있다.
//포인터 함수에 담을 함수를 선언 => 동작구현
//p에 접근해 함수를 불러와야 함으로 인자가 아닌 매개변수가 있는 함수로 리턴값을 지정해야함
void (* getPrintFunc(struct Person* p))(struct Person *) {
	return p->print;
}

//이렇게 안하고 주소 할당으로 사용가능
void *getPrintFunc2(struct Person *p) {
	return p->print;
}



int main() {
	
	struct Calc4 c4 = { { add, sub } };

	printf("출력 : %d\n", executer4(getFunc4(&c4, 0), 10, 20));
	printf("출력 : %d\n", executer4(getFunc4(&c4, 1), 10, 20));



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


	//함수 예제2
	struct Person p[3]; //구조체 선언
	p[0].print = print; //구조체의 함수포인터에 함수주소삽입 => 연결 
	p[1].print = print; //구조체의 함수포인터에 함수주소삽입 => 연결
	p[2].print = print; //구조체의 함수포인터에 함수주소삽입 => 연결

								//문자열은 주소 안적지만, int는 적어야함
	//scanf("%s %d %s %d %s %d", p[0].name, &p[0].age, p[1].name, &p[1].age, p[2].name, &p[2].age);


	void (*fp4[3])(struct Person*);//구조체 포인터를 인자로 받는 포인터 함수 배열 선언


	for (int i = 0; i < sizeof(p)/sizeof(struct Person); i++) //배열값 3만큼 반복
	{
		fp4[i] = getPrintFunc2(&p[i]); //구조체의 정보를 포인터 함수에 담음
	}


	executer3(fp4, p, sizeof(p) / sizeof(struct Person)); //포인터 함수와 구조체 , 배열 3크기를 보냄
	

	//파일에서 문자열을 읽고 쓰기
	//파일 포인터
	FILE* fp5 = fopen("hello.txt", "w");
	fprintf(fp5, "%s %d\n", "hello", 100);
	fclose(fp5);

	//파일에서 문자열 읽기
	char s1[10];
	int num1;
	FILE* fp6 = fopen("hello.txt", "r");
	fscanf(fp6, "%s %d", s1, &num1); //서식을 지정하여 문자열 읽기
	
	printf("%s %d\n", s1, num1);
	fclose(fp6);
	
	//파일에서 문자열 쓰기
	FILE* fp7 = fopen("hello.txt", "w");
	fputs("Hello, world", fp7);
	fclose(fp7);

	char* s10 = "Hello, world!";
	FILE* fp8 = fopen("hello.txt", "w");
	fwrite(s10, strlen(s10), 1, fp8);
	fclose(fp8);
	
	//파일에서 문자열 읽기
	char buffer[20];
	FILE* fp9 = fopen("hello.txt", "r");
	fgets(buffer, sizeof(buffer), fp9);
	fclose(fp9);
	

	char buffer2[20];
	FILE* fp10 = fopen("hello.txt","r");
	fread(buffer2, sizeof(buffer2), 1, fp10); //버퍼 크기만큼 파일 끝날때까지 문자열 가져옴
	printf("버퍼 끝 : %s\n", buffer2);
	fclose(fp10);



	//파일크기 구하기
	



}