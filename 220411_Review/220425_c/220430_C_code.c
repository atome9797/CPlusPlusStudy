#define _CRT_SECURE_NO_WARNINGS    // strcat 보안 경고로 인한 컴파일 에러
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

//


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

int main() {

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
	myprintf2("Hello My ptrinf : %d, %c , %s", 10, 'A', "Hello");
	//output : Hello My ptrinf : 10, A, 3.140000, Hello
	//printf 사용하지 말것 => putchar 사용할것 : 문자을 한 넣으면 그것만 출력함

	myprintf3(3, 4, 10, 20, 30);


	return -4;
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
				if (num >= 10) {
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
				}

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