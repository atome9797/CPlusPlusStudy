#include <stdio.h>
#include <stdlib.h>

#pragma region 열거형정의

//열거형 정의 : 구조체와 비슷하게 상수만 선언해서 사용
//순서대로 값이 들어가기 때문에 0,1,2,3,4..이어짐 
enum DayOfWeek {
	Sunday4 =0, //아무 값도 할당 하지 않으면 0부터 시작됨 
	Monday4,
	Tuesday4,
	Wednesday4,
	Friday4,
	Saturday4
};

//열거형 이름과 대소문자
enum hdmi_content_type {
	HDMI_CONTENT_TYPE_GRAPHICS,
	HDMI_CONTENT_TYPE_PHOTO,
	HDMI_CONTENT_TYPE_CINEMA,
	HDMI_CONTENT_TYPE_GAME
};

//typedef 익명 열거형
typedef enum {
	Sunday2 = 0,
	Monday2,
	Tuesday2,
	Wednesday2,
	Thursday2,
	Friday2,
	Saturday2
}DayOfWeek2; //typedef 를 이용하여, 열거형 별칭으로 DayOfWeek2 정의

DayOfWeek2 week2; //열거형의 별칭으로 공용체 변수 선언

//열거형 정의하는 동시에 변수 선언하기
enum DayOfWeek4 {
	Sunday = 0,
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday
} week3; //정의 동시에 변수 선언 (typedef 가 아니기 때문에 , 변수 선언임)


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
	DayOfWeekCount3 //0인덱스부터 세기 때문에 마지막값은 전체 갯수를 구해줌
}DayOfWeek3;


#pragma endregion

#pragma region 공용체
struct Flags {

	union {
		struct {
			unsigned short a : 3;
			unsigned short b : 2;
			unsigned short c : 7;
			unsigned short d : 4;
		};
		unsigned short e; //공용체로 16비트 공유
	};
};

struct Flags2 {
	unsigned int a : 2;
	unsigned int b : 1;
	unsigned int c : 6;
};


#pragma endregion

#pragma region 구조체

struct Data{
	char c1;
	int num1;
};

//구조체 포인터 별칭 정의
typedef struct _Data {

	char c100;
	int num100;
} Data2, *PData; //구조체 별칭, 구조체 포인터 별칭 정의


#pragma endregion


int main() {


	//비트 필드와 공용체 함께 사용
	struct Flags f1 = { 0, };
	f1.a = 4;
	f1.b = 2;
	f1.c = 80;
	f1.d = 15;
	
	printf("%d\n", f1.e);

	//구조체로 플래그 필드 만들기
	struct Flags2 f2;
	f2.a = 0xffffffff; //0xffffffff 32비트로 표현한 가장큰수를 의미 => a의 비트 필드는 2이므로 11출력됨
	f2.b = 0xffffffff;
	f2.c = 0xffffffff;
	//11 1 111111 => 3 1 63
	printf("%u%u%u\n", f2.a,f2.b,f2.c); 
	


	//열거형 사용하기 => 갯수가 많아지면 일일히 선언하기 귀찮음
	const int ValueA = 1;
	const int ValueB = 2;
	const int ValueC = 3;

	//열거형 변수 선언
	enum DayOfWeek week;
	week = Tuesday; //열거형에서 해당 값의 인덱스값을 가져옴
	printf("열거형 변수값 %d\n", week);


	//열거형 switch 사용하기
	enum LuxSkill skill; //열거형 변수 선언
	skill = LightBinding; //열거형 변수안에 해당 값의 인덱스값을 가져옴 => 1
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
		printf("해당없음\n");
		break;
	}
	}

	//열거형은 선언안해도 전역변수 상수처럼 가져올수 있다.
	for (DayOfWeek3  i = Sunday3; i < DayOfWeekCount3; i++) //열거형의 변수 값을 써서 반복문 돌려도됨
	{
		printf("열거형 : %d\n", i);
	}



	//자료형 변환하기
	//char -> short -> int -> long -> long long -> float -> double -> long double


	//포인터 형변환하기
	int* numPtr = malloc(sizeof(int));
	char* cPtr; //캐릭터 포인터 선언

	*numPtr = 0x12345678;

	cPtr = (char*)numPtr; //char형 포인터로 형변환 => 1바이트 크기의 little endian 방식으로 78값 할당됨 

	printf("0x%x\n", *cPtr);//포인터의 값을 출력해줌 => 0x 값이므로 16진법으로사용 => %x 
	printf("0x%x\n", *(char*)cPtr); //형변환 하면서 역참조 하기

	free(numPtr);




	//역참조 가능
	short* numPtr11 = malloc(sizeof(short));
	int* numPtr12;
	
	numPtr11 = malloc(sizeof(short)); //short 메모리 공간 포인터에 부여

	*numPtr11 = 0x1234;
	numPtr12 = (int *)numPtr11;//묵시적 형변환이 일어나기 때문에 안써도 되긴함

	printf("역 변환 : 0x%x\n", *numPtr12); 
	//0xfdfd1234 1234앞에 쓰레기 값을 가져옴, 빈공간에서 값을 가져오려니까 그럼
	free(numPtr11);

	
	
	//void 포인터 형변환
	int num10 = 10;
	float num11 = 3.5f;
	char c1 = 'a';
	void* ptr; // 역참조는 할수 없지만 형변환해서 역참조로 사용가능

	ptr = &num10; //int 형 포인터로 대입
	printf("%d\n", *(int*)ptr); //int형 포인터로 형변환하고 역참조 하기
	
	ptr = &num11;
	printf("%f\n", *(float*)ptr);//float 형 포인터로 형 변환하고 역참조하기

	ptr = &c1; 
	printf("%c\n", *(char*)ptr);//char 형 포인터로 형 변환하고 역 참조하기


	//void 포인터에 구조체 포인터 형변환
	struct Data *data100 = malloc(sizeof(struct Data));//구조체 포인터 선언후 메모리 할당
	void *ptr100; //void 퐁니터 선언

	data100->c1 = 'a';
	data100->num1 = 10;

	ptr100 = data100;//포인터 연결시 & 필요없음
	printf("포인 %c\n", ((struct Data*)ptr100)->c1);
	//void 포인터를 구조체 포인터로 형변환 시킨다음 구조체포인터에서 값을 가져옴
	printf("%d\n", ((struct Data*)ptr100)->num1);
	
	free(data100);//동적 메모리 해제


	//구조체 포인터 별칭 정의
	PData dt100 = malloc(sizeof(Data2));//구조체 포인터 메모리 할당
	void* ptr101; //void 포인터 선언
	
	dt100->c100 = 'a';
	dt100->num100 = 10;

	ptr101 = dt100;
	printf("%c\n", ((Data2*)ptr101)-> c100);
	printf("%d\n", ((PData)ptr101)-> num100);

	free(dt100);



	//포인터 연산 사용하기 (메모리 연산하기)

	//포인터 연산 사용하기
	//포인터 연산을 하면 다른 메모리 주소를 손쉽게 옮겨 다닐수있다.
	int numArr[5] = { 11,22,33,44,55 };
	int *numPtrA;
	int *numPtrB;
	int *numPtrC;

	numPtrA = numArr;//배열 포인터 저장

	numPtrB = numPtrA + 1; //포인터 연산
	numPtrC = numPtrA + 2; //포인터 연산


	printf("%p\n", numPtrA); //11주소 받음
	printf("%p\n", numPtrB); //22주소 받음 (4바이트 만큼 이동)
	printf("%p\n", numPtrC); //33주소 받음 (8바이트 만큼 이동)

	//포인터 연산 사용하기2
	char* cPtr1 = NULL;
	short* numPtr1000 = NULL;


	


	return 0;
}