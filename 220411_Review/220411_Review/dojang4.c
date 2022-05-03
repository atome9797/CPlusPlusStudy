#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void hello();// 함수를 아래에 적고 싶을땐 [함수 원형] 선언해줘야 사용가능

int one() {
	return 1;
}

float onePointOne() {
	return 1.1f;
}

//포인터 함수
int* ten() { //ten이라는 함수를 int형 포인터로 반환
	int num1 = 10;
	return &num1;//포인터로 반환하기 때문에 주소값을 넣어줌 => 주소를 포인터가 받고 반환함
	//함수에서 지역변수의 주소를 반환하는것은 잘못된 방법임
}

int* ten2() {
	
	//포인터를 반환하려면 malloc함수로 메모리 할당후 사용
	int* numPtr2 = malloc(sizeof(int)); //mallic으로 메모리할당하면 함수가 끝나도 사라지지 않음
	*numPtr2 = 10;

	return numPtr2;
}

char* helloLiteral()       // char 포인터를 반환하는 helloLiteral 함수 정의
{
	char* s1 = "Hello, world!";

	return s1;    // 문자열 Hello, world!는 메모리에 저장되어 있으므로 사라지지 않음
				  // 문자열 포인터 리턴
}

char* helloDynamicMemory()    // char 포인터를 반환하는 helloDynamicMemory 함수 정의
{
	char* s1 = malloc(sizeof(char) * 20);    // char 20개 크기만큼 동적 메모리 할당

	strcpy(s1, "Hello, world!");    // Hello, world!를 s1에 복사

	return s1;   // 문자열 포인터 리턴
}

//void 포인터 반환하기
//자료 형 상관 없이 값을 가져오고 싶을때 사용
void* allocMemory() {
	void* ptr = malloc(100);
	return ptr;
}

//구조체 선언
struct Person {
	char name[20];
	int age;
	char address[100];
};

//구조체를 반환하는 getPerson 함수선언
struct Person getPerson() {
	struct Person p;
	strcpy(p.name, "김영훈");
	p.age = 30;
	strcpy(p.address, "서울시 광진구");
	return p;
}

//메모리 공간을 절약하기 위해 포인터 구조체 함수 사용
struct Person* allocPerson() {
	
	struct Person* p = malloc(sizeof(struct Person));
	strcpy(p->name, "홍길동");
	p->age = 20;
	strcpy(p->address, "서울");

	return p;
}

//구조체 별칭 사용하기
typedef struct _Person3 {
	char name[20];
	int age;
	char address[100];
} Person3, *PPerson3; //구조체 별칭과 포인터 별칭을 반환


//포인터로 반환 => 별칭으로 사용가능 
PPerson3 allocPerson3() {
	//포인터 변수 선언
	PPerson3 p = malloc(sizeof(Person3));
	strcpy(p->name, "김실장");
	p->age = 30;
	strcpy(p->address, "서울");
	return p;
}

//공용체와 열거형 반환하기
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

//리턴값이 공용체임
union Box getBox () {
	
	union Box b1;
	b1.candy = 10;
	return b1;
};

//리턴값이 열거형임
enum BOX_TYPE getBoxType() {

	return BOX_WOOD;
};

//함수의 매개변수 사용
void helloNumber(int num1) {
	printf("Hello, %d\n",num1);
}

//덧셈함수 만들기
int add(int a, int b) {
	return a + b;
}

//함수의 매개변수로 포인터 사용하기
void swapNumber(int* first, int* second) {
	int temp;
	temp = *first;
	*first = *second;
	*second = temp;
}

//매개변수 포인터와 in,out
//c언어 문법은 아니지만 사람만 알아볼수 있도록 정의한것 
#define IN
#define OUT
void GetValue(IN int *a, OUT int* b) { //a는 입력된 매개변수, b는 리턴되는 매개변수
	printf("%d\n", a);
	*b = 10;
}

enum TYPE {
	TYPE_CHAR,
	TYPE_INT,
	TYPE_FLOAT
};

//타입 바꿔주는 함수
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
	case TYPE_FLOAT:    // 실수면 float *로 변환한 뒤 역참조하여 값을 서로 바꿈
		{
			float temp;
			temp = *(float*)ptr1;
			*(float*)ptr1 = *(float*)ptr2;
			*(float*)ptr2 = temp;
			break;
		}
	}
}


//ptr 포인터에 메모리를 할당했을뿐 main에서 사용한 포인터에는 영향없음
void allocMemory2(void* ptr, int size)  
{
	ptr = malloc(size);    // ptr은 allocMemory를 벗어나면 사용할 수 없음 => 리턴값을 할당 안해서 그럼
}


//이중포인터에 main에서 사용한 포인터를 넣어주고
//역참조로 main에서 사용한 포인터에 메모리를 할당한거라 할당가능 
void allocMemory3(void **ptr, int size)   
{
    *ptr = malloc(size);    // void **ptr을 역참조하여 void *ptr에 메모리 할당
}


void helloString(char *s1) {
	printf("Hello, %s\n",s1);
}


void helloString2(char s1[])    // 반환값 없음, char 배열을 매개변수로 지정, 크기 생략
{
	printf("Hello, %s\n", s1);    // Hello, 와 매개변수를 조합하여 문자열 출력
}


//배열의 매개변수 사용하기
void printfArray(int arr[], int count) {
	for (int i = 0; i < count; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void setElement(int arr[]) {
	arr[2] = 300; //arr[]은 배열이고 배열은 포인터 타입이기 때문에 값 변경 가능
}


//매개변수를 포인터로 지정하여 배열을 받음
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



//복합 리터럴  사용하기
//배열 따로 선언없이 사용가능
void printArray2(int arr[], int count) {
	
	for (int i = 0; i < count; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}


//2차원 배열을 매개 변수로 사용할때는 요소 값을 저장해 줘야함
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

//pointer to array를 함수값으로 사용하기
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


//구조체 선언
struct Person2 {
	char name[20];
	int age;
	char address[100];
};

void printPerson(struct Person2 p) {
	printf("이름: %s\n", p.name);
	printf("나이: %d\n", p.age);
	printf("주소: %s\n", p.address);
}

void setPerson(struct Person2 p) {
	strcpy(p.name, "김영훈");
	p.age = 30;
	strcpy(p.address, "서울 광진구");
}

void setPerson2(struct Person2 *p10) {
	strcpy(p10->name, "철구");
	p10->age = 40;
	strcpy(p10->address, "서울 광진구");
}


//구조체 별칭 사용하기
typedef struct _Person {
	char name[20];
	int age;
	char address[100];
} Person, *PPerson;


void setPerson3(PPerson p) {
	strcpy(p->name, "김영훈");
	p->age = 40;
	strcpy(p->address, "서울시 광진구 중곡동");
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

	//함수 선언과 정의 분리하기
	hello();


	//함수에서 반환값 사용하기
	int num = one();
	printf("%d\n", num);

	num = (int)onePointOne();//float을 int형을 형변환함
	printf("%d\n", num);
	
	//포인터 반환하기
	int* numPtr;
	numPtr = ten(); //포인터끼리 주소 참조 //10값이 나오긴 하지만 이미 사라진 변수를 출력하고 있음
	printf("%d\n",*numPtr);//역참조 값 출력 

	//malloc으로 할당된 주소 반환
	int* numPtr2;
	numPtr2 = ten2(); //메모리 해제하기 전까지 안전함
	printf("%d\n", *numPtr2);
	free(numPtr2); //main에서 해제를 해도 함수에서 선언된 메모리를 받은거기때문에, 함수 메모리가 해제됨
	

	char* s1;
	char* s2;

	s1 = helloLiteral();
	s2 = helloDynamicMemory();

	printf("%s\n", s1);    // Hello, world!
	printf("%s\n", s2);    // Hello, world!

	free(s2);    // 동적 메모리 해제


	//void 포인터 반환하기
	//자료 형 상관 없이 값을 가져오고 싶을때 사용
	char* ptr3 = allocMemory();// void포인터가 char포인터로 형변환됨 (메모리는 100)
	strcpy(ptr3, "Hello, world");
	printf("%s\n", ptr3);
	free(ptr3);

	int* ptr4 = allocMemory();// void포인터가 int포인터로 형변환됨 (메모리는 100 바이트)
	ptr4[0] = 10; //25개까지 가능 
	ptr4[1] = 20;

	printf("%d %d\n", ptr4[0], ptr4[1]);
	free(ptr4);


	//구조체함수
	struct Person p1;
	p1 = getPerson(); 
	//구조체를 반환하는 함수를 구조체에 대입 
	//struct Person는 빈깡통임
	//p1으로 변수 선언시 새로운 깡통이 만들어짐 => 새로운 깡통에 함수에서 정의한 값을 할당해줘야 값이 할당됨
	//struct에 저장하고 쓰는게 아니라 선언할때마다 값을 재할당 해줘야함

	printf("이름 : %s\n", p1.name);
	printf("나이 : %d\n", p1.age);
	printf("주소 : %s\n", p1.address);

	//메모리 공간을 절약하기 위해 포인터 구조체 함수 사용
	//동적 메모리는 만들었다가 삭제가능
	//그리고 원하는 메모리만 꺼내올수 있어서 다른 메모리 선언 안해줘도됨
	struct Person *p2;
	p2 = allocPerson();//포인터에 할당

	printf("이름 : %s\n",p2->name);
	printf("나이 : %d\n",p2->age);
	printf("주소 : %s\n",p2->address);
	
	free(p2);//함수에서 받은 메모리 해제
	

	//구조체 포인터 별칭 사용
	PPerson3 pps;
	pps = allocPerson3();
	printf("이름 : %s\n", pps->name);
	printf("나이 : %d\n", pps->age);
	printf("주소 : %s\n", pps->address);

	//공용체와 열거형 반환하기
	union Box box;
	enum BOX_TYPE boxType;
	box = getBox(); //box 변수안에는 candy값이 들어있음
	boxType = getBoxType();

	printf("%d\n", box.candy);
	printf("%d\n", boxType); //열거형 값이 들어있음



	//함수에서 매개변수 사용하기
	helloNumber(10);
	helloNumber(30);

	//덧셈함수
	int num1;
	num1 = add(20, 30);
	printf("%d\n", num1);


	//함수에서 포인터 매개변수 사용하기
	int num2 = 10;
	int num3 = 40;
	swapNumber(&num2, &num3);//메모리 주소를 포인터에 할당
	printf("%d %d\n", num2, num3);

	int num4 = 30;
	int num5 = 20;
	GetValue(&num4,&num5);
	printf("출력 : %d %d\n", num4, num5);
	

	//void 포인터 매개변수 사용하기
	char c1 = 'a';
	char c2 = 'b';
	swapValue(&c1, &c2, TYPE_CHAR);
	printf("%c %c\n", c1, c2);

	int num6 = 10;
	int num7 = 20;
	swapValue(&num6, &num7, TYPE_INT);   // 변수의 메모리 주소와 TYPE_INT를 넣음
	printf("%d %d\n", num6, num7);       // 20 10: swapValue에 의해서 값이 서로 바뀜


	float num8 = 1.234567f;
	float num9 = 7.654321f;
	swapValue(&num8, &num9, TYPE_FLOAT);  // 변수의 메모리 주소와 TYPE_FLOAT를 넣음
	printf("%f %f\n", num8, num9);        // 7.654321f 1.234567: 
										  // swapValue에 의해서 값이 서로 바뀜



	//이중포인터 매개변수 사용하기
	long long* numPtr4 = NULL;

	// numPtr과 할당할 크기를 넣어줌 
	//allocMemory2(numPtr4, sizeof(long long));

	//*numPtr4 = 10;    // 메모리가 할당되지 않았으므로 실행 에러
	//printf("실행에러 : %lld\n", *numPtr4);

	//free(numPtr4);


	long long* numPtr5;
	allocMemory3((void**)&numPtr5, sizeof(long long));
	*numPtr5 = 10;
	printf("%lld\n", *numPtr5);
	free(numPtr5);    // 동적 메모리 해제
	


	//문자열 매개변수 사용하기
	char s100[10] = "world!";
	helloString(s100);
	helloString2("world!");
	

	
	//배열의 매개변수 사용하기
	int numArr[10] = {1,2,3,4,5,6,7,8,9,10};
	printfArray(numArr, sizeof(numArr) / sizeof(int));
	
	int numArr2[10] = { 1,2,3,4,5,6,7,8,9,10 };
	setElement(numArr2);
	printf("%d\n", numArr2[2]);


	//배열을 포인터로 받아 매개변수 사용하기
	int numArr3[10] = { 1,2,3,4,5,6,7,8,9,10 };
	printArray(numArr3, sizeof(numArr3) / sizeof(int));
	
	//배열의 요소 바꾸기
	int numArr4[10] = { 1,2,3,4,5,6,7,8,9,10 };
	swapElement(numArr4, 0, 1);//0 index와 1index 값 바꾸기
	printf("%d %d\n", numArr4[0], numArr4[1]);
	

	//복합리터럴 사용하기
	//int 배열 형태로 형변환
	printArray2((int[]) { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, 10);
	

	//2차원 배열 매개변수 사용하기
	int numArr5[2][5] = { {1,2,3,4,5},{6,7,8,9,10} };
	int col = sizeof(numArr5[0]) / sizeof(int); //가로 갯수 구함
	int row = sizeof(numArr5) / sizeof(numArr5[0]);
	print2DArray(numArr5, col, row);


	//pointer to array를 함수값으로 사용하기
	print2DArray2(numArr5, col, row);

	//복합 리터럴 사용하기
	print2DArray2((int[2][5]) { {1, 2, 3, 4, 5}, { 6,7,8,9,10 } }, 5,2);


	//단위 행렬 만들기
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


	//구조체 매개변수 사용하기
	struct Person2 p3;
	strcpy(p3.name, "홍길동");
	p3.age = 30;
	strcpy(p3.address, "서울시 광진구 중곡동");

	printPerson(p3);


	//복합 리터럴 사용하기
	printPerson((struct Person2) { .name = "홍길동", .age = 30, .address = "서울 한남동" });
	printPerson((struct Person2) { "홍길동", 30, "서울 한남동" });

	
	//setPerson에서 설정한 값은 함수 내에서 새로운 객체에 담은것으로
	//함수 밖으로 나오면 person p3객체에 영향이 없음 
	//객체는 독립적인 것으로 struct 구조체 자체에 영향을 주는것이 아니라
	// 타입만 받아오는것임
	setPerson(p3); //=> person p3에 영향을 주지 않음
	printf("이름 : %s\n",p3.name);
	printf("나이 : %d\n",p3.age);
	printf("주소 : %s\n",p3.address);


	//구조체 포인터 매개변수 사용하기
	setPerson2(&p3);//구조체의 주소를 넘겨줌
	printf("이름 : %s\n", p3.name);
	printf("나이 : %d\n", p3.age);
	printf("주소 : %s\n", p3.address);


	//복합 리터럴 
	setPerson2(&(struct Person2) { .name = "김영훈", .age = 30, .address = "사울" });
	setPerson2(&(struct Person2) { "김영훈", 30, "사울" });


	//공용체와 열거형 매개변수로 사용하기
	union Box2 box2;
	enum BOX_TYPE2 boxType2;
	
	box2.candy = 10;
	boxType2 = BOX_PLASTIC;
	

	//printBox(box);
	//printBoxType(boxType);


	
	
	

	return 0;
}




//함수 본체
void hello() {
	printf("Hello world\n");
}