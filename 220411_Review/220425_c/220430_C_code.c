#define _CRT_SECURE_NO_WARNINGS    // strcat 보안 경고로 인한 컴파일 에러
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <assert.h>
#include <float.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

//typedef : 타입을 재정의 하는것. 어떤 타입에 별명을 지어주는것
typedef char btye;
typedef struct tagA {
	int n;
} A;

char* strstr3(char* str, char* str2) {
	
	int count = 0;

	char* temp2 = str;
	for (int i = 0; str[i] != '\0' ; i++)
	{
		if (str[i] == str2[0]) {//단어 시작 위치랑 같을때
			//char* temp = str;
			for (int j = 0; str2[j] != '\0'; j++)
			{
				if (str[i+j] == str2[j]) {
					//++temp;
					count += 1;
				}
				else {
					count = 0;
					break;
				}
			}
		}

		if (count != 0) {
			return temp2;
		}

		++temp2;
	}

	return NULL;
}


//해당 문자열자리에서 없애주고 null을 넣어줌
char* strtok2(char str [], const char str2 []) {
	
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str2[0] == str[i]) { //첫 문자열이 같으면 실행
			for (int j = 0; str2[j] != '\0'; j++)
			{
				//if () {
				//	
				//}
			}
		}
	}

	return 	str2;
}


//myprintf(1,2,3) => My Variadic Function : 1,2,3
//"My Variadic Function : ~"
void myprintf(int count, ...) {
	va_list args;//pointer to char라는걸 알수있다.
	va_start(args, count);
	printf("My Variadic Function :");
	for (int i = 0; i < count; i++)
	{
		int num = va_arg(args, int);
		printf(" %d, ", num);

	}
	va_end(args);
	printf("\n");
}



//선언

/// <summary>
/// printf와 유사하게 동작하나 기능이 제한됨
/// %d %c %f %s
/// </summary>
/// <param name="format">형식문자열</param>
/// <param name="">가변인자값</param>
void myprintf2(const char* format, ...);

void myprintf3(int a, int b, ...);


void CreateUser(const char* nickname) {

	//int n = 1;
	int n = strlen(nickname);
	assert(n);
}

//함수 호출 규약 : 스택 메모리를 어떻게 활용할 것인가, 인자는 어떻게 다룰 것인가
//x86아키텍쳐 한정

//64 에서는 인자 4번째 까지는 래지스터에서 처리함 

//인자를 오른쪽에서 왼쪽으로 순서로 스택에 담기게 한다. 가변인자 사용가능 , 스택 정리는 호출자(main)가 함
void __cdecl Foo(int a, ...) {
		
}

//가변인자 사용불가 => cdecl 이 처리해줌 : 스택 정리는 피호출된 함수에서 한다.
void __stdcall Foo3(int a, ...) {

}

int __stdcall Foo4(int a, int b) {
	return a + b;
}

//작은인자를 래지스터에 저장하고(큰 인자는 스택으로 저장) , 스택정리는 피호출된 함수가 한다. 
//가변인자 사용불가
void __fastcall Foo2(int a, ...) {


}


void functest10(int sta, int stb) {
	int result = sta + stb;
}


void __fastcall testadd(int a, int b) {
	int result = a + b;
}


//호출자는 운영체제가 됨 => main 함수는 피호출자로 사용가능(cdecl만 가능)
int main() {

	Foo(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,  14, 15);
	Foo3(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,  14, 15);
	Foo4(1, 2);
	Foo2(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);

	functest10(10, 20);

	testadd(10,20);



	int arr[5][5];
	int arr2[5][4];

	int(*parr)[5] = arr;
	parr = arr2;

	//문자열 : stack에 있는거라 수정가능함
	char str[] = "Hello, world";
	//str = "HELLO"; => 문자열 리터럴 타입은 const char * 이기 때문에 배열에 할당 못한다.
	str[0] = 'x';
	
	//strcpy(str, "jee"); //정적 메모리라 안됨
	printf("%s\n", str);


	//포인터는 data 정적 메모리이므로 수정 불가능함
	char* str2 = "hello";
	//str2[0] = 'c';
	//strcpy(str2, "asd");
	printf("%s\n", str2);
	


	int num[] = { 1,2,3,4,5 };
	num[0] = 10; 
	
	char str100[] = "blockpaint";
	char str101[] = "paint";
	//char* ptr = strstr2(str100, str101);
	
	char str200[] = "BlockDMask. He is a smart man";

	char str300[] = "He";
	char* ptr100 = strstr(str200, str300);


	printf("%s\n", ptr100);


	//strstr
	char str201[] = "BlockDMask. He is a smart man";
	char str202[] = "art";
	char* ptr103 = strstr3(str201, str202);

	printf("%s\n", ptr103);

	int* numptr1000;


	//char* str1000 = "hello";
	//*(str1000 + 2) = 'x';
	//printf("%s", str1000);
	int ddd[] = { 1,2,3 };
	int* asdasd = ddd;
	asdasd[0] = 10;
	printf("%d\n", asdasd[0]);

	//chnum 배열은 정적메모리에 저장된 문자열을 
	//stack에서 복사해서 사용하기 때문에, 문자열을 변경할수 있다.
	char chnum[] = "asdasdasd";
	char* ptrch = chnum;
	ptrch[0] = 'x';
	printf("%s\n", ptrch);



	//strtok
	char stok[] = "Block D Mask.";
	char* ptrtok = strtok(stok, "Ma");
	while (ptrtok != NULL)
	{
		printf("%s\n", ptrtok);
		ptrtok = strtok(NULL, "Ma");
	}
	

	
	/*char stok100[] = "Block D Mask.";
	char* ptrtok100 = strtok2(stok100, "Ma");
	while (ptrtok100 != NULL)
	{
		printf("%s\n", ptrtok100);
		ptrtok100 = strtok2(NULL, "Ma");
	}*/

	
	//1.Type : 데이터를 해석하는 방법
	//2.memory : 데이터를 저장하는 공간
	//3.object : 데이터를 저장하는 영역 -> memory

	int a;
	a = 10; //왜 이게 되는 것일까?
	//연산자는 피연산자를 동반한다.
	//a+b
	//a = b : 할당 연산자는 피연산자가 2개 필요하다.
	//피연산자에 조건 => 타입.
	//모든 연산자는 피연산자의 조건(타입)이 있다.
	int* p;
	//p = 3.14; 타입이 다르기 때문에 할당 못함

	//a[b] = *(a+b);
	//1.왜 a+b는 주소연산일까? => 피연산자의 타입 때문에 주소연산이란 걸 알게됨.
	//=> a의 타입은 포인터이고 b의 타입은 int
	//2. *연산자는 오직 pointer타입에만 적용할수 있음 => (a+b)타입은 pointer
	//3. 역참조한 값의 타입은? pointer 를 가리키고 있는 타입

	
	int arr3[2][3];
	*(*(arr3 + 2) + 3);
	arr3 + 2; //arr3 : int(*)[3];
			//주소연산가능


	//가변인자
	myprintf(1, 10);
	myprintf(2, 10 , 20);
	myprintf(3, 10,20,30);


	int test3 = 7;
	char test10 = test3 + '0';
	//printf("The value is :%c", test);
	putchar(test10);


	printf("\n");

	//가변인자2
	myprintf2("Hello My ptrinf : %d, %c , %s", -10, 'A', "Hello");
	//output : Hello My ptrinf : 10, A, 3.140000, Hello
	//printf 사용하지 말것 => putchar 사용할것 : 문자을 한 넣으면 그것만 출력함

	myprintf3(3, 4, 10, 20, 30);




	//<assert.h>
	//assert : 예외처리시 사용 : 디버그에서 작용
	//assert은 어떤 조건을 반드시 만족해야할때 사용함 => 만족못하면 exception나오게 설정
	assert(0 != 10);
	
	//<float.h>
	//실수 객체를 실행할때 사용함 , 보통 epsilon 값을 볼때 사용함
	printf("float의 유효숫자 : %f\n", FLT_DIG);
	printf("double의 유효숫자 : %f\n", DBL_DIG);
	printf("long double 의 유효숫자 : %f\n", LDBL_DIG);

	//소수 비교
	float f = 1.0 - 0.7;
	if (f - 0.3 < FLT_EPSILON) { //f == 0.3 아님
		printf("같음");
	}

	//<math.h>
	//수학적인 계산들 지원
	// pow , hyopot , cos ,sin, tan , round
	

	// <stdlib.h>
	//예제 
	//사용자로부터 두수를 입력 받고
	// 몫과 나머지를 출력하세요.
	int testnum1 = 0;
	int testnum2 = 0;
	scanf("%d %d", &testnum1, &testnum2);
	
	div_t result = div(testnum1, testnum2); //몫과 나머지 연산

	printf("몫 : %d, 나머지 : %d\n", result.quot, result.rem);

	// <stdbool.h>
	//참 거짓 판별
	bool bool1 = true;
	bool1 = false;
	
	//<stddef.h>
	//<stdint.h>
	//호환성 상관없이 고정 길이,타입을 지정
	//int8_t;

	//<time.h>
	//time : 현재 시간을 나타내줌
	time_t timeresult = time(NULL);//null값은 초기화
	char timestr[128] = "";
	printf("현재 시간 : %s\n", asctime(gmtime(&timeresult))); //최초시간 나옴
	
	//clock : 시점 적용


	//파일 포인터 만들기
// 1. 파일을 다루기 위한 객체 생성
	FILE* fp = NULL;

	// -------------------------------
	// 텍스트 파일
	// -------------------------------

	// 2. 파일을 연다.
	// 1) 텍스트 파일 : 텍스트 에디터로 열 수 있는 파일로 우리가 읽을 수 있는 문자로 구성
	// 2) 바이너리 파일 : 그 외의 모든 파일

	// Metaverse라는 이름을 가진 텍스트 파일을 연다.
	//성공했을때 0을 반환한다. 실패했을대 오류코드를 반환한다.
	if (0 != fopen_s(&fp, "Metaverse", "w"))
	{
		printf("오류 발생함.");

		return 1;
	}

	// 3. 파일을 조작한다.
	// 텍스트 파일에 작성할 수 있는 함수 : fputs() / fputc() / fprintf()
	// 바이너리 파일에 작성할 수 있는 함수 : fwrite()
	fputs("Hello File!", fp);
	fputc('J', fp);
	fprintf(fp, "\nThe name of the queen : %s\n", "퀸균지");

	// 4. 파일을 닫는다.
	fclose(fp);

	if (0 != fopen_s(&fp, "Metaverse", "r"))
	{
		printf("오류 발생함.");

		return 1;
	}

	// 텍스트 파일에서 읽어들일 수 있는 함수 : fgets() / fgetc() / fscanf()
	// 바이너리 파일에서 읽어들일 수 있는 함수 : fread()
	char ch = fgetc(fp); //문자 1개 읽기
	char strf1[128] = "";
	fgets(strf1, sizeof(strf1), fp); // 개행 문자까지 받아들인다. 
	char strf2[128] = "";
	fscanf_s(fp, "The name of the queen : %s", strf2, sizeof(strf2)); //문자열이 끝나는 null위치까지 받는다.


	printf("읽어들인 문자 : %c\n", ch);
	printf("읽어들인 문자열 : %s\n", strf1);
	printf("퀸은 누구? : %s\n", strf2);

	fclose(fp);

	// -------------------------------
	// 바이너리 파일 만들기 및 열기
	// -------------------------------
	if (0 != fopen_s(&fp, "Metaverse2", "wb")) //write binary의 약자
	{
		printf("오류 발생함.");

		return 1;
	}

	struct Student
	{
		int Age;                  // 4바이트
		enum { A, B, O, AB } BloodType;
		char Name[24];
	};

	struct Student s = { 20, A, "최선문" };
	//바이너리 파일 1개 작성 구조체에 => 정상적이면 1 출력됨
	if (1 != fwrite(&s, sizeof(s), 1, fp))
	{
		printf("오류 발생함.");

		fclose(fp);

		return 1;
	}

	fclose(fp);

	if (0 != fopen_s(&fp, "Metaverse2", "rb"))//read binary의 약자
	{
		printf("오류 발생함.");

		fclose(fp);

		return 1;
	}

	struct Student s2 = { 0 };
	//해당 구조체의 데이터를 파일 1개에 바이너리로 읽어오기
	if (1 != fread(&s2, sizeof(s2), 1, fp)) //파일을 읽은 개수 가 1개가 아니면 => 오류 반환
		//오류 일땐 0을 출력함
	{
		printf("오류 발생함.");

		fclose(fp);

		return 1;
	}

	printf("나이 : %d, 혈액형 : %d, 이름 : %s\n", s2.Age, s2.BloodType, s2.Name);//BloodType은 값이 나옴


	fclose(fp);

	//바이너리는 구조체에 데이터를 담을때 유용하다.
	


	//malloc => 동적 할당
	int pnum = 0;
	scanf("%d", &pnum);
	int* pm = malloc(sizeof(int) * pnum);

	//메모리는 자원이다.
	//자원이라는 것은 시스템으로부터 빌려와서 사용이 끝나면 돌려줘야 하는것
	//사용이 끝난 메모리를 돌려주지 않으면 메모리 누수(memory Leak)가 발생

	//누수를 막으려면 메모리를 돌려주는 free함수를 사용해야 한다.
	free(pm);//힙에 메모리 반환
	pm = NULL; //해제가 됬다면 꼭 null포인터로 만들어줄것

	//메모리를 수동으로 관리할때 문제점
	//1. 언제 사용이 끝나는지 불명확함 => 반환이 안될수 있음. => 메모리 누수 발생
	//2. 반환이 됐음에도 불구하고 접근하는 경우 => 메모리 접근 엑세스 위반 뜸 => 유효하지 않는 메모리 주소를 갖고 있는 포인터를 댕글링 포인터라고한다.
	//3. 반환이 됏음에도 불구하고 또 반환하는 경우 => 이중해제(double free)
	


	//함수의 식별자는 유일해야함 => 함수는 재정의를 할수 없다
	
	//stack : 정적 할당영역 => 함수가 사용하는 공간 => 이미 얼마나 메모리를 사용해야할지 알고있음
	//heap : 동적 할당영역
	//data : 정적 데이터
	//code : 프로그램 명령어

	int spa = 10; //4바이트


	// 함수가 사용하는 메모리 : 스택(Stack)
	// 함수와 관련된 내용(스택 프레임)
	// 1. 얼마나 메모리를 사용할 것인지 => 임시 데이터
	// 2. 매개변수(인자)
	// 3. 반환 주소
	// 스택 관리는 bp, sp를 이용함.
	// bp : 함수가 사용하는 메모리의 시작 주소
	// sp : 함수가 사용할 수 있는 메모리의 끝 주소

	// 호출 규약(Calling Convention)
	// => 인자를 어떻게 전달할 것이며, 반환 값을 어떻게 돌려줄 것인가
	// 사용하는 이유 : stdcall, fastcall 을 사용하면 메모리 사용량을 줄일수 있음
	
	// x86
	// __cdecl : 기본 호출 규약. 인자는 오른쪽부터 왼쪽 순서대로 스택에 넣고, 스택 정리는 호출자가 한다. 가변 인자 사용 가능
	// __stdcall : 인자를 오른쪽부터 왼쪽 순서대로 스택에 넣고, 스택 정리는 피호출자가 한다. 가변 인자 사용 불가능
	// __fastcall : (가능하다면) 첫 번째 인자와 두 번째 인자를 레지스터에 저장하고, 나머지 인자는 오른쪽에서 왼쪽 순서대로 스택에 넣음. 그리고 스택 정리는 피호출자가 한다.
	
	//가변인자 사용불가
	// x64
	// 4번째 인자까지 레지스터에 넣고, 스택 정리는 피호출자가 한다.

	



	return 0;
}


void myprintf3(int a, int b, ...) {
	va_list args;
	va_start(args, b);//시작위치 지정
	for (int i = 0; i < 3; i++)
	{
		printf("테스트 : %d\n", va_arg(args, int));
		//타입을 준 이유는 몇바이트 만큼 읽어야 하는지 알기위해 사용
	}
	
	va_end(args);
}

void stringNumber(int num) {
	
	//32 비트(4바이트) 자리수를 비교하고 1이면 음수임 =>0일땐 거짓나오도록 설정
	//&한개 사용하는 이유는 비트 단위 연산할때는 &하나 사용함
	const int isNegative = num & (1 << 31);//부호 비트 사용 (1&&1 은 1) => 0이 아닐땐 참임


	//음수이므로 계산식 적용함
	// 양수의 2의 보수 비트 반전 할때 , 1) 양수 비트 반전하기 2) +1하기 => 음수나옴
	// 그것을 거꾸로 음수에서 양수로 변환 할려면 , 1) -1하기 2) 음수 비트 반전하기 => 양수나옴
	if (isNegative) {
		putchar('-');
		num -= 1; 
		num = ~num; 
	}


	char temp[31] = {0}; //바이트수 만큼 지정
	int count = 0;
	while (num != 0) {
		temp[count] = num % 10 + '0';
		num = num / 10;
		count++;
	}

	for (int i = count-1; i >= 0; i--)
	{
		putchar(temp[i]);
	}


}

void myprintf2(const char* format, ...) {
	
	//va_start 에서 byte를 다룰려고 char 를 쓴거지 캐릭터 타입을 받는게 아님

	va_list args;//메모리 공간 생성(가변인자를 다룰 객체를 만든다.)
	va_start(args, format);//format은 가변인자의 시작위치를 알려주는 것 
							//=> 인자값을 기준으로 ... 크기만큼 데이터를 가져와 저장함
							//...이 가변인자임


	while (*format != '\0') {
		
		if (*format == '%') {
			++format;

			switch (*format)
			{
			case 'd':  {
				int num = va_arg(args, int); //...의 첫 인자를 int타입으로 가져옴
				
				stringNumber(num);
											 
				/*if (num >= 10) {
					int odd = num / 10;
					int pdd = num % 10;
					char test10 = odd + '0';
					putchar(test10);
					char test20 = pdd + '0';
					putchar(test20);
				}
				else {
					char test30 = num + '0';
					putchar(test30);
				}*/

				break;
			}
			case 'c': {
				char test2 = va_arg(args, char); //...의 인자를 char타입으로 가져옴
				putchar(test2);
				break;
			}
			case 's': {
				char* test3 = va_arg(args, char*); //...의 인자를 char타입으로 가져옴
				while (*test3 != '\0') {
					putchar(*test3);
					++test3;
				}
				break;
			}
			default:
				putchar(*format);
			}
		}
		else {
			putchar(*format);
		}

		++format;
	}
	va_end(args); //가변인자 끝낸다.
	printf("\n");
	
}