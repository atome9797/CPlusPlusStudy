#include <stdio.h>

#pragma region 열거형정의

//열거형 정의 : 구조체와 비슷하게 상수만 선언해서 사용
//순서대로 값이 들어가기 때문에 0,1,2,3,4..이어짐 
enum DayOfWeek {
	Sunday =0, //아무 값도 할당 하지 않으면 0부터 시작됨 
	Monday,
	Tuesday,
	Wednesday,
	Friday,
	Saturday
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
	Sunday = 0,
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday
}DayOfWeek2; //typedef 를 이용하여, 열거형 별칭으로 DayOfWeek2 정의

DayOfWeek2 week; //열거형의 별칭으로 공용체 변수 선언

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




	return 0;
}