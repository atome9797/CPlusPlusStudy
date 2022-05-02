#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int arr[1000000];
char alpha_arr[10000000];
char aaa[10000000];


//=> ///3개 써서 함수 설명 적음
/// <summary>
/// 배열에 모든 원소를 더한다.
/// </summary>
/// <param name="a">정수 n개가 저장되어 있는 배열</param>
/// <param name="n">배열의 크기</param>
/// <returns>배열의 모든원소를 더한값</returns>
long long sum(int* a, int n) {
	long long sum100 = 0LL;
	for (int i = 0; i < n; i++)
	{
		sum100 += (long long)a[i]; //a는 퐁니터 타입이기때문에 배열로 변환 가능
	}
	return sum100;
}



/// <summary>
/// 두수의 값을 서로 교체한다.
/// </summary>
/// <param name="a">정수 a의 값</param>
/// <param name="b">정수 b의 값</param>
/// <returns>두 정수값을 교체한다.</returns>
void Swap(int* a, int* b)
{
	// a : 0x1234 -> 0xabcd
	// b : 0x5678 -> 0x5780
	int temp = *a;
	*a = *b;
	*b = temp;
}

//함수
//return-type identifier(parameter-list) => header
//complicated statement => Body

//매개변수(Parameter)
//Parameter : 함수에서 사용되는 변수, 함수 외부에서 입력값을 받기 위해 사용.

//함수를 사용하는 의의는 코드를 재사용하기 위함이다.

//함수를 호출한다. 호출한 main을 호출자, 호출된 함수를 피호출자
//호출자에게 내가 계산한 결과를 '반환'해줄수 있다.
//반환은 return문을 사용함. 반환 값은 반환 타입과 일치 해야함
//반환 해줄것이 없다면 void 타입 사용.
int sum2(int x, int y) {
	return x + y;
}



void foo() {
	if (1) {
		return; //반환 타입이 void인 경우에도 return문을 사용할수있으며,
		//함수를 중간에 끝낼때 사용한다.
	}
}


//3개의 입력을 받아 모든 입력값을 더해서 반환하는 함수 sum3()를 만들어라
int sum3(int a, int b, int c) {
	return a + b + c;
}


//Swap() : 2개의 정수를 입력받아 서로 데이터를 교환
void Swap2(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

//isLower() : 한개의 문자를 받아 소문자인지 판별한다.
int islower(char n) {
	int testnum = 0;
	if (n >='a' && n <= 'z') {
		testnum = 1;
	}
	return testnum;
}

//isupper() : 한개의 문자를 받아 대문자인지 판별한다.
int isupper(char n) {
	int testnum = 0;
	if (n >= 'A' && n <= 'Z') {
		testnum = 1;
	}
	return testnum;
}


//tolower()/ toupper()
char tolower2(char a) {
	const int special_acii_num = 32;
	if (a >= 'A' && a <= 'Z') {
		a + special_acii_num;
	}

	return a;
}

char toupper2(char a) {
	const int special_acii_num = 32;
	if (a >= 'a' && a <= 'z') {
		a - special_acii_num;
	}

	return a;
}

//strlen() : 문자열의 길이를 구하는 함수
// 배열을 받으려면 포인터를 사용해야한다.
// 배열을 매개변수로 받는 함수는 배열의 크기를 같이 받는다.
// 문자열의 끝은 null문자다 => 따라서 배열의 크기를 알지 않아도 끝을 알수 있다.
//매개변수 1개 => 문자열을 저장하기 위한 객체  => pointer to char  
int strlen2(const char *str) {
	
	int count = 0;
	for (int i = 0; str[i] != '\0' ; i++)
	{
		count++;
	}
	//둘중하나 사용가능

	while (*str++ != '\0') {
		++count;
	}

	return count;
}


// strchr() : 문자열에서 특정 문자의 위치를 찾는 것
// 입력 : 문자열(const char*), 내가 찾을 문자(const char)
// 처리 : 입력된 문자열에서 그 문자가 나온 위치(메모리 주소)를 찾는다.
// 출력 : 문자의 위치 => 그 문자가 있는 메모리 주소값(char*)
// 1. 문자가 있는 경우 => 그 문자의 위치
// 2. 문자가 없는 경우 => NULL
// char* pos = strchr("Hello, 'l');
// "Hello"
//    ↑

// 1. 문제 정의 => 입력, 처리, 출력. 문제를 충분히 해결할 수 있을 정도로 계속해서 작은 단위로 쪼개서 생각해야 함.
// 2. 작은 문제로 쪼갰다면 그 문제를 해결할 절차를 기술.
// 3. 문제를 해결하기 위해 어떤 데이터가 필요한가? => 즉, 어떤 데이터를 저장해야 하는가?

char* strchr3(const char* str, const char ch)
{
	while (*str != '\0')
	{
		if (*str == ch)
		{
			return (char*)str;
		}

		++str;
	}

	return NULL;
}



/// <summary>
/// 문자열을 입력 받아, 문자열에서 거꾸로 문자를 찾아 주소값을 반환
/// </summary>
/// <param name="str">문자열 str 배열로 받음</param>
/// <param name="ch">찾으려는 문자</param>
/// <returns>문자열 str을 거꾸로 검색해 해당 문자의 주소를 찾는다.</returns>
char* strrchr(const char* str, const char ch) {

	int count = 0;
	while (*str != '\0') {
		++str;
		count++;
	}

	while (count > 0) {
		--str;
		
		if (*str == ch)
		{
			return (char*)str;
		}
		count--;
	}

	return NULL;
}





	


//char* strrchr(char* str) {
//	char* temp="asdasd";
//	//temp = str; // reverse해줄 변수 선언 => 포인터에서 포인터로 참조할땐 &안씀 => 값이 동일해짐
//	int count = 0;
//	int count2 = 0;
//
//	while (*str != '\0') {
//		//temp[count] = *str;
//		//printf("리버스1 : %c\n", temp[count]);
//		count++;
//		++str;
//	}
//
//	printf("카운트 : %d\n", count);
//
//	while (count > 0) {
//		temp[count] = *str;
//		--str;
//		printf("리버스2 : %c\n", *str);
//		printf("리버스3 : %c\n", temp[count]);
//		count--;
//		count2++;
//	}
//
//
//	return temp;
//
//}


/// <summary>
/// 문자열을 반대로 출력한다.
/// </summary>
/// <param name="str">문자열을 받는다.</param>
/// <returns>받은 문자열을 반대로 출력한다.</returns>
char* strreverse(char str[]) {
	
	int length;
	char temp;
	
	length = strlen(str);

	for (int i = 0; i < length/2; i++){
		temp = str[i];
		str[i] = str[length - i - 1];
		str[length - i - 1] = temp;
	}

	return str;
}



//strcpy

/// <summary>
/// 문자열을 복사해서 바꿔주는 함수
/// </summary>
/// <param name="str">원래 문자열</param>
/// <param name="str2">바꿀 문자열</param>
/// char *str은 test_ch301배열의 주소값을 참조한것으로 *str을 바꾸면 test_ch301값이 변한다.
void strcpy2(char *str, char * str2) {
	while (*str2 != '\0') {
		*str = *str2;
		str2++;
		str++;
	}
}


//strcat

/// <summary>
/// 기존 문자열에 새로운 문자열을 더해주는 함수
/// </summary>
/// <param name="str">기존문자열</param>
/// <param name="str2">새로운 문자열</param>
void strcat2(char* str, char* str2) {
	while (*str != '\0') {
		str++;
	}
	while (*str2 != '\0') {
		*str = *str2;
		str2++;
		str++;
	}
}


//strcmp

/// <summary>
/// 기존 문자열과 새로운 문자열이 같은지 비교하는 함수
/// </summary>
/// <param name="str">기존문자열</param>
/// <param name="str2">새로운 문자열</param>
/// <returns>같으면 0, 다르면 1 리턴</returns>
int strcmp2(char* str, char* str2) {
	
	while (*str != '\0' || *str2 != '\0') {
		
		if (*str != *str2) {
			return 1;
		}
		str++;
		str2++;
	}

	return 0;
}


//함수






int main() {//main함수는 시스템이 호출하는 것 => runtime 라이브러리에서 처리 해줌



	

#pragma region c언어강의


	int isAlreadyExist[26] = { 0 };

	isAlreadyExist[0] = -1;
	if (isAlreadyExist[0])
	{
		printf("참");

	}

	char ch = 'a';
	int number = 20;
	float number2 = 2.4f;

	printf("%c\n", ch);
	printf("%-5d", number); //-5는 5자리를 만들고 왼쪽 정렬해서 빈칸을 만드는 작업임
	printf("%.3f\n", number2);
	
	long long number3 = 1024LL;
	printf("%lld\n", number3);

	float temp1 = 0.0f;
	int temp2 =0;
	//변수 초기화 안하면 쓰레기값이 들어가 있다.
	//scanf("%f | %d", &temp1, &temp2);

	printf("%f %d\n", temp1, temp2);


	/*
		float ,double, long double
		소수점 밑의 자리가 9개까지 같아야 함
		float :9개
		double : 9개
		long double : 15개

		오류의 종류
		컴파일 에러 : 문법을 잘못쓴것
		link error : 연결을 잘못한것
			- 함수를 선언만하고 정의하지 않았다거나
			- 이미 정의된 식별자를 다시 재정의한다거나
			- 범위 밖의 식별자를 사용했다거나
		runtime error : 프로그램 실행중 오류발생-> 버그 -> 논리 오류

	*/

	
	//10bit
	//0100 0000 0000
	(signed char)1024; //char 는 8비트이므로 10비트를 못담아 잘린다.

	/*
		while문에 0이 아닌 다른수는 다 참, 0은 거짓
		while(-1){ //무한 반복됨
		}
	*/


	//1.입력
	//Case#1 : 10 20 30
	//int caseNum, data1, data2, data3;
	//scanf("Case#%d : %d %d %d", &caseNum, &data1, &data2, &data3);

	//2. 출력
	//Case#1 : 10 20 30
	//printf("Case#%d : %d %d %d", caseNum, data1, data2, data3);

	//3.연산

	//4. 분기문
	//if/switch

	/*
		5. 반복문
		- for/while/do-while
		- for: 반복 횟수가 정해져 있지 않을때
		- while :반복횟수가 정해져 있지 않을때
		- do-while : 조건식 평가가 나중에 일어나야 할때
	*/

	//6.배열
	// 같은 성질의 여러 데이터를 한번에 다루기 위한것


	//시프트 연산자

	signed char chs = -1;
	//0000 0001 => ...1111 1111 1111 1110 +1 => ...1111 1111 1111 1111
	

	chs >> 2;//2의2제곱 만큼 나누기 한값 출력됨
	//... 1111 1111 => 부호 비트가 내려옴 (부호 비트는 시프트 연산자로 안바뀜)

	chs << 2; //2의 2제곱 만큼 곱한 값 출력됨

	chs << 1; //2의 1제곱 만큼 곱한 값 출력됨

	//0x24 16진수를 10진수로 표현 하면 16*1+ 16*2 = 36으로 표현가능



	//함수 : 일련의 코드에 이름을 붙인것 
	//함수는 api라고 불리기도함
	//API
	// Apllication Programming
	/*
		Interface => 함수 하나를 일컫는것

		standard => 플랫폼에 독립적이다. (ios, android, window...등등 표준이면 다 사용가능)
		-> 이식성이 높다고 함

		Library => 유용한 api 모음
	*/


	//220428 문자열
	char str100[128];
	str100[0] = 'H';
	str100[1] = 'H';
	str100[2] = 'H';
	str100[3] = 'H';
	str100[4] = 'H';
	str100[5] = NULL;//null문자로 끝내야함 '\0'

	printf("문자 %s", str100);// 문자열을 종료시키지 않았을때 쓰레기값 나옴
	//왜냐하면 128 배열이므로 나머지 값도 함께 나옴 (null로 끝내줘야함) 


	//pointer type : 주소값으로 해석하는 타입
	//배열은 pointer type으로 암시적 변환됨 -> 포인터로 퇴행했다.

	char str101[10];
	//10 이상 담으면 오류뜸 => buffer overrun이라고 한다.
	//scanf("%s", str101); //=> 배열은 포인터 타입임, 주소 안씀

	//문자열 길이를 지정할수 있는 %n을 설정한다 => 시큐어 함수
	//scanf("%9s", str101);
	
	//scanf_s 로 범위를 지정할수도 있다.
	//scanf_s("%s", str101, 10); 

	char N100[26] = { 0 };
	char asdasdasd[23] = "";
	//scanf("%s", asdasdasd);
	printf("%s \n", asdasdasd);

	for (int i = 0; i < 3; i++)
	{
		//scanf("%1s", &N100[i]); //=> 1글자씩 받기 때문에 줄바꿈이나 이어붙여도 3개까지 저장시킴
	}

	for (int i = 0; i < 3; i++) {

		printf("%c ", N100[i]);
	}

	printf("줄바꿈\n");

	//strcpy : 복사해서 바꿔줌
	char word[128] = "Hello, String!";

	//Hello, string => Drunkenjaesung
	strcpy(word, "Drunkenjaesung"); //조건 : 반드시 null종료 문자열 이어야 함
	puts(word); //출력문

	
	char word2[128] = "";
	strcpy(word2, word);
	puts(word2);

	char word3[5];
	word3[0] = 'H';
	word3[1] = 'H';
	word3[2] = 'H';
	word3[3] = 'H';
	//word3[4] = '\0';  => null값이 없으면 다른 메모리 침범 가능성 생김


	strcpy(word2, word3); //null값 설정 안해서 오류남 => 다른 메모리 침범해서 저장하게 될수 있음 (오류 원인)


	//strcat
	char nameT[100] = "hana"; //소스는 null로 종료가 되었는지 꼭 확인
	strcat(nameT, " one");
	puts(nameT);

	//strlen 
	char nameF[100] = "hana1"; //소스는 null로 종료가 되었는지 꼭 확인
	size_t lenf = strlen(nameF);//null문자를 제외한 갯수를 알려줌

	//size_t : 타입의 별명을 지어줌 (타입 재정의)
	//puts(lenf); //=> 안됨
	printf("%d", lenf);

	//strcmp : 비교
	if (0 == strcmp(nameF, "hana1")) {
		puts("같음");
	}


	char input[] = "A bird came down the walk";

	// Pointer : 데이터를 메모리 주소값으로 해석
	// Type* Identifier;
	// int* p; => pointer to int

	int a10 = 10; // a : 0x1234
	int b10 = 20; // b : 0x5678

	// a <-> b
	Swap(&a10, &b10);
	printf("%d %d", a10, b10);

	int num = 10;
	int* p2 = NULL;
	int* p = &num;

	int** p3 = &p; // pointer to pointer to int
	**p3 = 30;

	int*** p4 = &p3; // pointer to pointer to pointer to int
	***p4 = 50;



	*p = 20;

	// 왜? 포인터를 사용해야 하는가
	// 메모리에 접근하는 방법은 2가지가 있다.
	// 직접 참조(Direct Reference / Direct Access) : 메모리 주소에 직접 접근하는 것
	// num = 20;
	// 간접 참조(Indirect Reference / Indirect Access) : 메모리 주소를 포인터를 통해서 접근하는 것
	// => 함수에서 불가능했던 다른 주소값에 접근후 할당이 가능하다 (예 . a와 b를 바꾸기)
	// *p = 20;
	// Scope : 프로그램이 식별자를 찾을 수 있는 영역
	// Block Scope => Local Variable
	// File Scope => Global Variable

	//Pointer Type 크기는 얼마인가?
	//Pointer Type :데이터를 메모리 주소값으로 해석한다.
	//x86에서는 4바이트
	//x64에서는 8바이트임

	//a[b] => *(a+b);

	//address operation 주소 연산 : 배열이나 포인터에서 사용가능
	// 주소 연산은 포인터 또는 배열에서 일어난다. 
	// int * ptr[] = {1,2,3,4};
	// int * ptr = malloc(sizeof(int));
	// char * am = "asdasdasdasd";
	// ...
	// 
	// + - : 메모리 주소를 가리키고 있는 타입의 크기 만큼옮긴다.
	int arr100[2] = { 10,20 };
	p = arr100;//arr의 첫번째 원소의 주소를 가리키게된다.
	p = p + 1; //&arr[1] => 배열의 다음주소로 이동하게된다. (int형이므로 4바이트 만큼 주소 이동)
	p = p - 1; //&arr[0]
	
	char* psh; //pointer to pointer
	psh + 1; // 1바이트 만큼 뒤로 이동
	psh - 1; // 1바이트 만큼 앞으로 이동
	
	//a[b] => *(a+b);
	int arr101[10] = { 1,2,3,4,5,6,7,8,9,10 };
	arr101[2] == *(arr101 + 2); // => 배열포인터에서 주소연산 +2 를 한다는건 arr의 3번째값을 가져온다는 뜻이다.
	p = arr101; //포인터와배열은 같다.
	p[2]; //같은 의미 => 배열과 포인터는 같기때문에 포인터에서 배열 인덱스에 접근가능하다.

	//주의 : 역참조 연산자와 증감 연산자를 결합할때 연산 순서를 유의해야한다.
	int testnum1 = *p++; //=> *p 가 실행된 다음 ++ 이 실행됨 (++은 주소 연산자로 주소 값을 이동하게됨)
	//testnum1에 역참조값 1값을 부여하고 포인터를 1 증가 시킴
	int testnum2 = *++p; 
	//testnum2에 포인터 2에서 1증가 시킨후 역참조값 3값을 변수에 대입시킨다.
	int testnum3 = ++(*p);
	//testnum3에 포인터 3에서 1증가시킨후 역참조 값 4값을 변수에 대입시킨다.

	printf("%d\n", testnum1);
	printf("%d\n", testnum2);
	printf("%d\n", testnum3);

	printf("포인터 사이즈 : %d\n", sizeof(p));


	//strchr  : 문자열에서 주소값을 반환 
	const char* str1001 = "Try not.Do, or do not. There is no try.";
	char target = 'T';
	const char* result1000 = str1001;

	const char* pos = strchr(str1001, target);
	
	while ((result1000 = strchr(result1000,target)) != NULL) {
		printf("%c %s\n", target, result1000);
		++result1000; //포인터 에 + 연산해줌 (포인터가 캐릭터 이므로 1바이트 이동함) => 배열에서 r찾음 
	} 
	

	//strtok : 토큰 단위로 분리 하기 => 문자열의 끝을 null 로 반환 해줌 => 끊어줌
	//null로 문자열을 끊어주며 단어를 분리시켜 반환 해줌 => 처음에는 문자열을 집어넣고 
	//안쪽에선 해당 문자열에 null을 삽입 시켜 토큰을 끊어주게된다.
	char input100[] = "A bird came down the walk";
	printf("Parsing the input string '%s' \n", input100);
	char* token = strtok(input100, " "); // => " " 띄어쓰기 만나면 해당 문자열을 끊어준다. 
	//strtok 함수에 토큰 쓰고 나머지값 남아 있음 => ""안에 다양한 문자를 지정해서 끊어줄수 있음
	while (token) { // token도 출력 하다 문자열이 null일때 끝난다.
		printf("%s\n", token);//puts(token) 가능
		token = strtok(NULL, "c");//다음 끊고 싶은 문자열 패턴을지정하고 NULL값을 삽입해 끝어준다.
	}


	//void pointer
	//함수나 포인터에서만 타입 선언가능 : 주소 자체로만 다룰때 사용함
	void* p1000; // pointer to void (int,double,function 등 여러 타입받음)
	int* p2000;  //int 


	//함수 
	//함수는 선언과 정의가 명확히 나뉜다.
	int func1 = sum2(1, 2); //인자(argument) : 매개변수의 초기값
	//puts(func1);
	printf("%d\n", func1);

	//()괄호도 호출 연산자이다


	int sp1 = 1;
	int sp2 = 2;
	Swap2(&sp1, &sp2);
	printf("Swap2 : %d %d", sp1, sp2);

	//문자가 소문자인지 함수 써서 판별
	char test_m = 'A';
	if (islower(test_m) == 1) {
		printf("소문자 입니다.\n");
	}
	else {
		printf("대문자 입니다.\n");		
	}

	printf("%c\n", tolower2('A'));
	printf("%c\n", toupper2('c'));

	char test_chch[100] = "asdasdasdasdasdasdasdasdasdasdasdasd";
	printf("%d\n", strlen2(test_chch));

	char test_ch100[100] = "asdasd";
	printf("%p\n", strchr3(test_ch100, 'd'));
	
	//메모리 주소값을 가져옴
	char test_ch200[100] = "qweqwe";
	printf("%p\n", strchr3(test_ch200, 'w'));

	char test_ch101[100] = "asdasd";
	printf("출력 : %s\n", strreverse(test_ch101));
	
	//strrchr
	char test_ch300[100] = "asdasd";
	printf("출력2 : %p\n", strrchr(test_ch300, 's'));




	//
	/*char test_ch300[100] = "asdasd";
	strrchr2(test_ch300);
	printf("%p", test_ch300);*/


	//숙제 : 레퍼런스에서 배운 함수들을 내가 함수 만들기
	
	//strcpy
	char test_ch301[100] = "hello";
	
	//hello => Drunkenjaesung

	strcpy2(test_ch301, "Drunkenjaesung"); //조건 : 반드시 null종료 문자열 이어야 함
	puts(test_ch301); //출력문


	//strcat
	char test_ch302[100] = "hana"; //소스는 null로 종료가 되었는지 꼭 확인
	strcat2(test_ch302, " one");
	puts(test_ch302);

	//strcmp
	char test_ch303[100] = "hana1";
	if (0 == strcmp2(test_ch303, "hana1")) {
		puts("같음");
	}
	else {
		puts("다름");
	}


#pragma endregion

	printf("============= 강의 끝 =====================\n");

#pragma region 알고리즘

	//입력
	int test_case_num = 0;//반복 횟수
	char count_test[80] = "#";
	int count_score = 0;
	int count_sp = 0;
	scanf("%d", &test_case_num);


	for (int i = 0; i < test_case_num; i++) {//5입력됨
		count_score = 0;

		scanf("%s", &count_test); //문자열


		for (int j = 0; j < 80; j++) { //한줄에 80개 까지 받을수 있도록 설정
			if (count_test[j] == 'O') {
				count_score += 1;
				if (j >= 1 && count_test[j] == 'O' && count_test[j - 1] == 'O') {
					count_sp += 1;
					count_score += count_sp;
				}
				else {
					count_sp = 0;
				}
			}
		}

		printf("%d\n", count_score);
	}

	//for (int k = 0; k < 80; k++) {
	//	count_score += count_test[k];
	//	if (count_test[k] == 1 && count_test[k-1] == 1) {
	//		count_score += 1;
	//	}
	//}

//평균
//1. 최댓값은 M, 모든점수 => 점수/M*100

//입력
	int testCnt = 0; // 테스트 갯수
	int testScore = 0; //테스트 한개 점수
	int maxScore = 0; //최대점수
	double calScore = 0;//종합 점수
	int input_score[101] = { 0 };

	scanf("%d", &testCnt);

	for (int i = 0; i < testCnt; i++) {
		scanf("%d", &testScore);
		input_score[testScore] += 1; //점수값을 저장해서 카운트로 가져올수 있음
		if (maxScore < testScore) {//최댓값 구하기
			maxScore = testScore;//최댓값에 넣기
		}
	}

	for (int i = 1; i <= 100; i++)
	{
		if (input_score[i] >= 1) {//해당 인덱스에 값이 있을때
			calScore += (double)i * input_score[i] / maxScore * 100;
		}
	}

	printf("%f\n", calScore / testCnt);




	//1. 나머지가 서로다른게 몇개있는지 구하기

	//입력
	int input_a[42] = { 0 };//받는 배열
	int number_c = 0;//입력값
	int count_a = 0;
	//처리
	for (int i = 0; i < 10; i++) {
		scanf("%d", &number_c);
		input_a[number_c % 42] += 1;
	}

	//printf("%d\n", input_a[0]);

	for (int i = 0; i < 42; i++)
	{
		if (input_a[i] >= 1) {
			//각 나머지 index값을 검사 하는 것이므로 input_a[0]일때 3이든 4든 뭐든 1개로 카운트 됨
			count_a++;
		}
	}

	printf("%d\n", count_a);


	/*
		첫째 줄에 A, 둘째 줄에 B, 셋째 줄에 C가 주어진다.
		A, B, C는 모두 100보다 크거나 같고, 1,000보다 작은 자연수이다.

		첫째 줄에는 A × B × C의 결과에 0 이 몇 번 쓰였는지 출력한다.
		마찬가지로 둘째 줄부터 열 번째 줄까지 A × B × C의
		결과에 1부터 9까지의 숫자가 각각 몇 번 쓰였는지 차례로 한 줄에 하나씩 출력한다.

		1. A,B,C 값을 받을 변수 선언
		2. scanf 로 값 받기
		3. 곲값을 자리수 와 자리수의 값을 배열로 저장하기 => 0 자리수의 값 ? 이런식으로
		4. 2중 for문으로 각 자리수별 숫자 카운트해서 뽑기
	*/

	int digit[3];
	int sumDigit = 0;
	int cntDigit[] = { 0, }; //빈 함수 선언해서 값을 할당할수 있음
	int count100 = 1;
	int ddd = 0;

	for (int i = 0; i < 3; i++) {
		scanf("%d", &digit[i]);
	}

	sumDigit = digit[0] * digit[1] * digit[2];

	//printf("%d\n", sumDigit);

	//sumDigit 배열로 전환
	while (1) {
		if (sumDigit / 10 != 0) {
			sumDigit = sumDigit / 10;
			count100++;
		}
		else {
			break;
		}
	}

	//printf("자리수 : %d\n", count100);


	sumDigit = digit[0] * digit[1] * digit[2];


	for (int i = 0; i < count100; i++) {
		cntDigit[i] = sumDigit % 10;
		sumDigit = sumDigit / 10;
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < count100; j++) {
			if (i == cntDigit[j]) {
				ddd += 1;
			}
		}
		printf("%d\n", ddd);
		ddd = 0;
	}

	//printf("배열 값 : %d %d %d %d %d %d\n", cntDigit[0], cntDigit[1], cntDigit[2], cntDigit[3], cntDigit[4], cntDigit[5]);



	/*
	N개의 정수가 주어진다. 이때, 최솟값과 최댓값을 구하는 프로그램을 작성하시오.
	1. 첫째 줄에 정수의 개수
	2.  둘째 줄에는 N개의 정수를 공백으로 구분해서 주어진다
	3. 첫째 줄에 주어진 정수 N개의 최솟값과 최댓값을 공백으로 구분해 출력한다.
*/

	int size = 0;
	int maxN = 0;
	int minN = 0;
	scanf("%d", &size);


	for (int i = 0; i < size; i++) {
		scanf("%d", &arr[i]);
	}

	maxN = arr[0];
	minN = arr[0];

	for (int i = 0; i < size; i++) {
		if (maxN < arr[i]) {
			maxN = arr[i];
		}
		if (minN > arr[i]) {
			minN = arr[i];
		}
	}


	printf("%d %d\n", minN, maxN);


	/*
		첫째 줄부터 아홉 번째 줄까지 한 줄에 하나의 자연수가 주어진다.
		주어지는 자연수는 100 보다 작다.

		첫째 줄에 최댓값을 출력하고, 둘째 줄에 최댓값이 몇 번째 수인지를 출력한다.
	*/

	int input10[9];
	int maxN2 = 0;
	int cnt100 = 0;

	for (int i = 0; i < 9; i++) {
		scanf("%d", &input10[i]);
	}

	maxN2 = input10[0];

	for (int i = 0; i < 9; i++) {

		if (maxN2 < input10[i]) {
			maxN2 = input10[i];
			cnt100 = i;
		}

	}


	printf("%d %d\n", maxN2, cnt100 + 1);


	/*int *arr;
	int size =0;
	int maxN = 0;
	int minN = 0;
	scanf("%d", &size);

	arr = (int*)malloc(sizeof(int) * size);

	for (int i = 1; i < size; i++) {
		scanf("%d", &arr[i]);
		if (i < size && numx[i] > numx[i-1]) {
			minN = numx[i - 1];
		}
		else {
			maxN = numx[i];
		}
	}

	free(arr);*/


	/*
		자연수 N이 주어졌을 때, 1부터 N까지 한 줄에 하나씩 출력하는 프로그램을 작성하시오.
	*/


	/*
		각 테스트케이스마다 A+B를 한 줄에 하나씩 순서대로 출력한다.
	*/

	printf("======== 알고리즘 =========\n");

	/*
		n이 주어졌을 때, 1부터 n까지 합을 구하는 프로그램을 작성하시오.
	*/
	int sumCal = 0; //합계
	int countNUm = 0; // n값
	int cnt = 0;
	scanf("%d", &countNUm);
	//n=3일때
	for (int i = 0; i < countNUm/2; i++) {
		sumCal += countNUm +1 ;
	}
	if (countNUm % 2 != 0) {
		sumCal += (countNUm + 1) / 2;
	}

	printf("계산값 : %d\n", sumCal);


	//케이스 밑 출력
	int replay = 0; //반복횟수
	int input1 = 0; //첫번째 입력값
	int input2 = 0; //구번째 입력값
	int replaySum = 0;
	scanf("%d", &replay); 

	for (int i = 0; i < replay; i++) {//반복횟수 만큼 입력값 받음
		scanf("%d %d", &input1, &input2); //넣을값
		replaySum = input1 + input2;
		printf("%d\n", replaySum);
	}


	//구구단
	//int number = 0;
	//scanf("%d\n", &number);

	//for (int i = 1; i < 10; i++) {
	//	printf("%d * %d = %d\n", number, i, number * i);
	//}

	
	/*
		원래 설정되어 있는 알람을 45분 앞서는 시간으로 바꾸는 것
		첫째 줄에 두 정수 H와 M이 주어진다. (0 ≤ H ≤ 23, 0 ≤ M ≤ 59)
		그리고 이것은 현재 상근이가 설정한 놓은 알람 시간 H시 M분을 의미한다.
		24시간 표현에서 하루의 시작은 0:0(자정)이고, 끝은 23:59(다음날 자정 1분 전)이다
		불필요한 0은 사용하지 않는다.
	*/
	int hour = 0;
	int minute = 0;
	scanf("%d", &hour);
	scanf("%d", &minute);

	//if (hour == 0) {
	//	hour = 24;
	//}
	//int output = (hour * 60 + minute) - 45;

	//if (output / 60 == 24) {
	//	hour = 0;
	//}
	//else {
	//	hour = output / 60;
	//}
	//printf("출력 : %d:%d\n", hour, output % 60);


	if (minute - 45 < 0) {
		hour -= 1;
		minute = 60 + (minute-45);
		if (hour < 0) {
			hour = 23;
		}
	}
	else {
		minute -= 45;
	}

	printf("알람 -45 : %d %d", hour, minute);


	int dies1 = 0;
	int dies2 = 0;
	int dies3 = 0;
	int count = 0;
	int price = 0;

	scanf("%d %d %d", &dies1, &dies2, &dies3);
	
	if (dies1 == dies2 && dies2 == dies3) {
		count += 2;
	}
	else if (dies1 == dies3 || dies2 == dies3 || dies1 == dies2) {
		count += 1;
	}


	if (count >= 2) {
		price = 10000 + dies1 * 1000;
	}
	else if (count == 1) {
		if (dies1 == dies2) {
			price = 1000 + dies1 * 100;
		}
		else if (dies1 == dies3) {
			price = 1000 + dies1 * 100;
		}
		else if (dies2 == dies3) {
			price = 1000 + dies2 * 100;
		}
	}
	else {
		if (dies1 > dies2 && dies1 > dies3) { // 3 4 6
			price = dies1 * 100;
		}
		else if (dies2 > dies3 && dies2 > dies1) {
			price = dies2 * 100;
		}
		else if (dies3 > dies2 && dies3 > dies1) {
			price = dies3 * 100;
		}
	}

	printf("상금 : %d\n", price);


	/*
		첫째 줄에는 현재 시각
		두 번째 줄에는 요리하는 데 필요한 시간
	*/
	int hr = 0;
	int min = 0;
	int oven = 0;
	scanf("%d %d", &hr, &min);
	scanf("%d", &oven);

	//분과 오븐 시간이 1시간이 넘어 갈때
	if (min+oven >= 60) {
		hr += (min+oven)/60; //시간을 추가해줌
		min = (min + oven) % 60;//나머지 분 추가됨

		if (hr > 23){
			hr = hr % 24;
		}
	}
	else {
		min = (min + oven);
	}

	printf("%d %d", hr, min);


	///*
	//	원래 설정되어 있는 알람을 45분 앞서는 시간으로 바꾸는 것
	//	첫째 줄에 두 정수 H와 M이 주어진다. (0 ≤ H ≤ 23, 0 ≤ M ≤ 59)
	//	그리고 이것은 현재 상근이가 설정한 놓은 알람 시간 H시 M분을 의미한다.
	//	24시간 표현에서 하루의 시작은 0:0(자정)이고, 끝은 23:59(다음날 자정 1분 전)이다
	//	불필요한 0은 사용하지 않는다.
	//*/
	//int hour = 0;
	//int minute = 0;
	//scanf("%d", &hour);
	//scanf("%d", &minute);

	//if (hour == 0) {
	//	hour = 24;
	//}
	//int output = (hour * 60 + minute) - 45;

	//if (output / 60 == 24) {
	//	hour = 0;
	//}
	//else {
	//	hour = output / 60;
	//}
	//printf("출력 : %d:%d\n", hour, output % 60);


	//if (minute - 45 < 0) {
	//	hour -= 1;
	//	minute = 60 + minute;
	//	if (hour < 0) {
	//		hour = 23;
	//	}
	//}
	//
	//printf("%d %d", hour, minute);


	int numa = 0;
	int numb = 0;
	scanf("%d", &numa);
	scanf("%d", &numb);

	//385
	int layer100 = numb / 100;//3
	int layer10 = (numb % 100) / 10;//8
	int layer1 = numb % 10;//5

	/*
		알고리즘으로 규칙성을 부여하면 a / 100 % 10 으로 연산 가능하다.
	
		int layer100 =  numb / 100 %10;
		int layer10 = (numb / 10) % 10;
		int layer1 = numb /1 % 10;
	*/



	printf("%d\n", numa * layer1);
	printf("%d\n", numa * layer10);
	printf("%d\n", numa * layer100);
	printf("%d\n", (numa * layer1) + (numa * layer10 * 10) + (numa * layer100 * 100));

	int num1 = 0;
	int num2 = 0;
	int sum = 0;
	char num2ch[30];
	printf("입력을 받으시오 =======\n");
	scanf("%d", &num1);
	scanf("%d", &num2);
	sprintf(num2ch, "%d", num2);
	printf("숫자 : %d\n", sizeof(num2ch) / sizeof(char));
	//for (int i = 0; i < sizeof(num2ch) /sizeof(char); i++) { //숫자 갯수 만큼 담음
	//	int count = 10 * (sizeof(num2ch) / sizeof(char) - i -1);//5-1
	//	printf("%d\n", num1 * num2ch[i]);
	//	if (count ==0) {
	//		sum += num1 * num2ch[i];
	//	}
	//	else {
	//		sum += num1 * num2ch[i] * count;
	//	}
	//}
	

	//쌍따옴표 역슬레쉬 출력방법
	/*
		\t : 수평 tab tab(8)칸 띄우기

		\n : 개행 커서를 한줄 밑으로 이동(enter와 같은효과)

		\' : '(쿼티션)을 표시 , 단독으로 '입력시 화면에 출력 x

		\" : "(더블 쿼티션) 표시

		\\ : \(역슬래시 표시)

	*/

	printf("\\    /\\\n");
	printf(" )  ( ')\n");
	printf("(  /  )\n");
	printf(" \\(__)|\n");

	printf("|\\_/|\n");
	printf("|q p|   /}\n");
	printf("( 0 )\"\"\"\\\n");
	printf("|\" ^ \"`    |\n");
	printf("||_/=\\\\__|\n");

	//
	int a = 0;
	int b = 0;
	double result = 0.0; //double 형은 소수 15자리까지 오차없이 표현할수 있다.

	//형변환
	scanf("%d", &a);
	scanf("%d", &b);
	result = (double)a / b;
	printf("%.13f\n", result);

	char name[40];
	scanf("%s", name);
	printf("%s??!\n", name);

	int year = 0;
	scanf("%d", &year);
	printf("날짜 : %d\n", year - 543);


	/*
		A가 B보다 큰 경우에는 '>'를 출력한다.
		A가 B보다 작은 경우에는 '<'를 출력한다.
		A와 B가 같은 경우에는 '=='를 출력한다.
	*/

	/*
		시험 점수를 입력받아 90 ~ 100점은 A, 80 ~ 89점은 B, 
		70 ~ 79점은 C, 60 ~ 69점은 D, 나머지 점수는 F를 출력하는 프로그램을 작성하시오.
	*/
	
	int score = 0;
	scanf("%d", &score);
	if (score >= 90 && score <= 100) {
		printf("A");
	}
	else if (score >= 80) {
		printf("B");
	}
	else if (score >= 70) {
		printf("C");
	}
	else if (score >= 60) {
		printf("D");
	}
	else {
		printf("F");
	}


	/*
		윤년은 연도가 4의 배수이면서, 100의 배수가 아닐 때 또는 400의 배수일 때이다.
		연도가 주어졌을 때, 윤년이면 1, 아니면 0을 출력하는 프로그램을 작성하시오.
	*/

	/*
		1사 : ++
		2사 : -+
		3사 : --
		4사 : +-
	*/
	int x = 0;
	int y = 0;

	scanf("%d", &x);
	scanf("%d", &y);

	if (x > 0 && y > 0) {
		printf("1");
	}
	else if (x < 0 && y > 0) {
		printf("2");
	}
	else if (x < 0 && y < 0) {
		printf("3");
	}
	else{
		printf("4");
	}


	/*
		각 테스트 케이스마다 "Case #x: "를 출력한 다음, A+B를 출력한다. 테스트 케이스 번호는 1부터 시작한다.
	*/

	/*
		Case #1: 1 + 1 = 2
	*/

	/*
		별찍기 문제
		*
		**
		***
		****
		*****
		*
		* 예제입력 :5
	*/

	int starNum = 0;
	scanf("%d", &starNum);
	for (int i = 0; i < starNum; i++) { // 0 ~ 4
		for (int j = starNum - 1; j > -1; j--) {
			if (i >= j) {
				printf("*");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}

	/*
		정수 N개로 이루어진 수열 A와 정수 X가 주어진다.
		이때, A에서 X보다 작은 수를 모두 출력하는 프로그램을 작성
	*/
	//int n = 0;
	//int ix = 0;
	//int xa = 0;
	//scanf("%d %d", &n,&ix);
	//for (int i = 0; i < n; i++) {
	//	scanf("%d", &xa);
	//	if (xa < ix) {
	//		printf("%d ", xa);
	//	}
	//}
	//int numa1 = 0;
	//int numb1 = 0;
	//do {
	//	scanf("%d %d", &numa1, &numb1);
	//	if (numa1 != 0 && numb1 != 0) {
	//		printf("%d\n", numa1 + numb1);
	//	}
	//} while (numa1 != 0 && numb1 != 0);

	int numa9 = 0;
	int numb9 = 0;
	//do {
	//	scanf("%d %d", &numa9, &numb9);
	//	if (numa9 > 0 && numa9 < 10 && numb9 > 0 && numb9 < 10) {
	//		printf("%d\n", numa9 + numb9);
	//	}
	//} while (numa9 > 0 && numa9 < 10 && numb9 > 0 && numb9 < 10);

	/*while(1) {
		scanf("%d %d", &numa9, &numb9);
		if (!(numa9 > 0 && numa9 < 10 && numb9 > 0 && numb9 < 10)) {
			break;
		}
		printf("%d\n", numa9 + numb9);
	}*/


	//입력
	int input_num = 0;
	int first_num = 0;
	int second_num = 0;
	int sum_num = 0;
	int sum_last_num = 0;
	int new_num = 0; //새로운 번호
	int cnt10 = 0;

	scanf("%d", &input_num);
	new_num = input_num;
	//0 < A, B < 10
	do {

		if (new_num < 10) {
			first_num = new_num / 10;
			second_num = new_num % 10;
			sum_num = first_num + second_num;
			sum_last_num = sum_num % 10;//합의 끝자리수 
		}
		else {
			first_num = new_num / 10;
			second_num = new_num % 10;
			sum_num = first_num + second_num; //각 자리 숫자를 더한다.
			sum_last_num = sum_num % 10;//합의 끝자리수 
		}
		new_num = second_num * 10 + sum_last_num;

		cnt10++;
	} while (input_num != new_num);

	printf("%d\n", cnt10);

	char asdasd[4] = { 'a','b','c' };
	printf("배열 갯수 %d\n", strlen(asdasd));
	//마지막 배열[4] 자리에 null이 들어 가는데, 
	//strlen함수는 배열의 null을 만나야 문자열의 끝을 판별할수 있다.


	//1157
	//입력 :
	// 1. 문자열 A 입력 받기 1,000,000
	// 1-1 문자열이 대문자이면 소문자로 전환
	// 2. 알파벳 문자열 alpha 입력 받기 26
	// 3. alpha 배열과 문자열 a 2중 반복문 돌린뒤 
	// 3-1 값이 같으면 알파벳 카운트 문자열 beta 에 +1입력 받기
	// 4. 최댓값과 같으면 ? 더 크면 큰값이 출력되게 설정

	scanf("%s", &alpha_arr);
	char mb = '#';
	int max = 0;
	int beta_count[92] = { 0 };
	int j = 0;
	while (alpha_arr[j] != 0) {//int i = 65; i <= 90; i++
		for (int i = 65; i <= 90; i++) {//alpha_arr[j] != 0

			if (alpha_arr[j] >= 'a' && alpha_arr[j] <= 'z') {
				alpha_arr[j] -= 32;
			}


			if ((char)i == alpha_arr[j]) {
				beta_count[i] += 1;

				if (beta_count[i] > max) {
					max = beta_count[i];
					mb = (char)i;
				}
				else if (beta_count[i] == max) {//같으면 ?
					mb = '?';
				}

				break;
			}

		}

		j++;
	}

	printf("%c\n", mb);



	//최적화
	// 입력 :
	//1. 문자열 A 입력 받기 1000000
	// 처리 : 
	//1. 아스키 코드값으로 대문자 A에서 Z사이의 범위를 반복문 돌리기
	//2. 문자열 A를 대문자로 바꾸고 A에서 Z사이중 몇번째 인지 



	//처리 :
	//출력 :


	//2675
	//입력 :
	// 1. 테스트 케이스 T입력 받기 1000
	// 2. T만큼 반복문 돌리기
	// 3. 반복문에서 반복 횟수 R입력 받기 8
	// 4. 문자열 s 받기 20
	// 5. s문자열 반복시켜서 R과 곱해줌으로 출력하기
	int logic_T;
	scanf("%d", &logic_T);

	//처리 :
	for (int i = 0; i < logic_T; i++) {
		int logic_R;
		char logic_S[20];
		scanf("%d %s", &logic_R, &logic_S);
		for (int i = 0; i < strlen(logic_S); i++)
		{
			for (int j = 0; j < logic_R; j++)
			{
				printf("%c", logic_S[i]);
			}
		}
		printf("\n");
	}

	//출력 :



	//10809
	//입력 : 
	// 1. 첫째 줄에 단어 S가 주어진다.(char 100배열) , s를 입력 받는다.
	// 2. 알파벳 문자열을 받는다 
	char logic_s[100] = { 0 };
	char logic_alpa[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	scanf("%s", logic_s);
	//처리 : 
	// 1. 문자열 반복문 돌리기
	// 1-1 . 문자열에 알파벳이 있는지 없는지 검사
	// 1-1-1 . 알파벳이 없으면 -1
	// 1-1-2 . 알파벳이 있으면 
	// 1-1-2-1. 몇번째 문자열에 있는지 검사
	//출력 : 
	int logic_count = 0;
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 100; j++) {
			if (logic_s[j] != logic_alpa[i]) {
				logic_count = -1;
			}
			else {
				logic_count = j;
				break;
			}
		}
		printf("%d ", logic_count);
	}


	//최적화




	//함수를 호출한 사람을 caller(main함수), 호출됨 함수(add함수)를 callee라고 한다.
	//매개변수()를 초기화 시켜주는 것 a, b을 인자라고 한다. 
	int fun1 = add(1, 2);//호출 연산자 : 함수를 호출 한다. 
	int fun2 = add(3, 4);
	int fun3 = add(5, 6);
	printf("%d\n", fun1);
	printf("%d\n", fun2);
	printf("%d\n", fun3);


	//11654
	//입력 :
	//  정수, 문자 int , char 를 입력 값으로 받는다.
	char aci;
	scanf("%c", &aci);
	//처리 :
	//출력 : int ,char 를 아스키 코드로 변환한 출력 값ㄴ을 출력한다.
	printf("%d\n", aci);

	//11720
	// 입력 :
	// 1. 첫 번째 줄은 입력할 숫자의 갯수 int 형식으로 입력받음
	// 2. 두번 째 줄은 문자열 입력받음 => 배열로 받음
	// 3. 총합 값 변수 선언 
	int logic_n = 0;
	char logic_c[101] = { 0 };
	int logic_sum = 0;

	scanf("%d", &logic_n);
	scanf("%s", &logic_c);


	// 처리 :
	// 1. n 갯수만큼 반복문 돌려 배열값을 추출하고 총합값 으로 더해준다.
	for (int i = 0; i < logic_n; i++)
	{
		logic_sum += logic_c[i] - 48; //문자열에서 int 형 뽑으려면 아스키코드 48을빼줘야함
	}

	// 출력 :
	// 1. 총합 값 출력
	printf("%d\n", logic_sum);



	//입력 :
	// 1. 출력할 테스트 케이스 n 을 입력 받는다.
	//처리 :
	// 2. n갯수 만큼 반복문을 돌린다.
	// 3. char 배열로 문자열을 입력 받는다. (80)
	// 4. 문자열에 o가 들어가면 count해준다
	// 4-1. 앞 문자열이 o 이면 count + 1을 더해준다. => 카운트는 별짓기 문제 처럼 푼다.
	// 
	//출력 :
	// 5. count값을 출력한다.
	int testcnt = 0;
	scanf("%d", &testcnt);
	for (int i = 0; i < testcnt; i++) {
		char testch[81];
		int testcount = 0;
		int testcount2 = 0;
		scanf("%80s", testch);
		for (int j = 1; j < strlen(testch) + 1; j++) {
			testcount = 0;
			for (int k = 0; k < j; k++) {
				if (testch[k] == 'O') {
					testcount++;
				}
				else {
					testcount = 0;
				}
			}

			testcount2 += testcount;
		}
		printf("%d\n", testcount2);

	}

	//5622
	//목표 : 전화을 걸기위해 필요한 최소한의 시간을 구하시오
	// 1. 숫자 1을 걸려면 2초 걸림, 안칸 옆 숫자는 1초씩 더걸림.
	// 2. 문자로 표현된 숫자를 가지고 걸리는 시간을 구하는 문제.
	//입력 : 
	// 1. 할머니의 문자열을 입력받음 (0과1 은 입력 안함)
	char phone_alpha[16] = { 0 };
	scanf("%15s", phone_alpha);

	// 2. 시간 총합값을 선언한다.
	int tel_time = 0;
	//처리 :
	// 3. 문자열을 for 반복문을 사용한다 2보다 크거나 같고 15보다 작거나 같다
	// 4. 알파벳은 3개씩에 1개의 번호를 가지므로, 나머지와 몫으로 번호를 출력한다.
	// 4-1. 
	for (int i = 0; i < strlen(phone_alpha); i++) {

		if (phone_alpha[i] >= 'a' && phone_alpha[i] <= 'z') {//대문자 범위 65 ~ 90
			phone_alpha[i] -= 32;
		}

		//대문자 범위를 반복문 돌림
		for (int j = 65; j <= 90; j++) {
			if (phone_alpha[i] == j) { //할머니 문자가 해당 대문자면
				phone_alpha[i] = (j - 65) / 3 + 2 + 48; //012345....26 
				if (j == 83 || j == 86 || j == 89 || j == 90) {
					phone_alpha[i] = (j - 65) / 3 + 2 + 47;
				}

				//시간을 더해줌
				tel_time += phone_alpha[i] + 1 - 48;
			}
		}
	}
	// 5. 번호를 출력했으면 번호 까지 가는 시간 값을 추가해준다. 
	//출력 :
	// 6. 총 시간을 출력한다.

	printf("%d", tel_time);










	//2908
	//목표 : 두 수를 입력 받고 숫자를 거꾸로 만든다음 비교하기
	//입력 : 
	// 1. A와 B를 int 형 정수로 입력 받는다. => 0이 없다
	int logic_A = 0;
	int logic_B = 0;

	char result_a[3] = { 0 };
	char result_b[3] = { 0 };


	scanf("%d", &logic_A);
	scanf("%d", &logic_B);

	//처리 : s
	// 2. A와 B의 숫자를 거꾸로 반복문을 돌려 입력한다.
	for (int i = 0; i < 3; i++) {
		result_a[2 - i] = logic_A % 10 + 48;
		logic_A = logic_A / 10;
		result_b[2 - i] = logic_B % 10 + 48;
		logic_B = logic_B / 10;
	}

	// 3. 두수를 비교 하고 큰수를 출력한다. => char를 정수로 변환 할때 - 48 사용 할것 
	int logic_count_test = 1;
	for (int i = 0; i < 3; i++) {
		logic_A += (result_a[i] - 48) * logic_count_test;
		logic_B += (result_b[i] - 48) * logic_count_test;
		logic_count_test *= 10;
	}

	//출력 : 
	if (logic_A > logic_B) {
		printf("%d\n", logic_A);
	}
	else {
		printf("%d\n", logic_B);
	}





	//1152
	//목표 : 문자열에 들어간 단어 갯수 구하기 (문자 아님 단어임) => fgets 사용
	//입력 :
	// 1. 문자열 str 을 입력 받는다. (1000000) , count 정수를 선언한다.
	char logic_str[1000001];
	int logic_count100 = 0;
	fgets(logic_str, 1000000, stdin); //띄어쓰기까지 받을수 있는 함수 

	//처리 :
	// 2. 문자열 str을 반복문 돌린다.
	// 2-1. 문자가 공백이면 count 해준다.
	// 3. 맨 앞 자리와 맨 뒷자리가 공백이면 -1 count 해준다.
	for (int i = 0; i < strlen(logic_str) - 1; i++) {
		if (logic_str[i] == ' ') {//strlen에 null 까지 포함됨
			logic_count100 += 1;
		}
	}


	if (logic_str[0] == ' ') {
		logic_count100 -= 1;
	}
	if (logic_str[strlen(logic_str) - 2] == ' ') {
		logic_count100 -= 1;
	}


	//출력 :
	printf("%d\n", logic_count100 + 1);



	//1316
	//목표 : 
	// 1. 그룹 단어 개수를 출력하는 프로그램을 만들기
	// 2. 그룹단어가 아닐땐 카운트 안한다. -> 그룹단어는 같은 문자는 같은 문자끼리 이어져 있음
	//입력 :
	// 1. 입력 할 그룹단어 갯수를 logic_group_cnt 로 선언하고 입력 받는다.
	int logic_group_cnt = 0;
	scanf("%d", &logic_group_cnt);
	//처리 :
	// 2. logic_group_cnt의 갯수 만큼 반복문을 돌린다.
	// 3. char 문자열로된 group_word 를 선언하고 입력 받는다.
	// 4. group_word 문자열을 반복문 돌린다.
	// 5. group_word문자의 알파벳을 0 ~ 26으로 뽑고 새로운 count 배열 [index]에 넣어준다. => 값은 group_word문자위치로
	// 6. group_word 반복문을 돌릴때, 별짓기 방식으로 count 해준다(새로운 for문)
	// 6-1. 예를들어 p 알파벳을 구한다 할때 별짓기 갯수 만큼 안늘어 나 있으면 그룹 단어가 아니다.
	// 6-2. 

	int minor = logic_group_cnt;

	for (int i = 0; i < logic_group_cnt; i++) {
		int word_array[26] = { 0 };
		for (int i = 0; i < 26; i++) {
			word_array[i] = -1;
		}
		char group_word[100];
		scanf("%s", group_word);
		int exp_count = 1;
		for (int j = 0; j < strlen(group_word); j++) {
			int word_count = group_word[j] - 'a';//0~25까지 알파벳인덱스를 받는다.

			if (group_word[j - 1] == group_word[j] && word_array[word_count] != -1) { //이미 자리에 값이 있을때
				exp_count++;
			}
			else {
				exp_count = 1;
			}


			word_array[word_count] = j;//문자열의 위치를 알파벳배열 index에 담아준다.
			int test_count = 0;
			//for (int k = 0; k < 3; k++) {
			for (int k = 0; k < j + 1; k++) {
				if (group_word[j] == group_word[k]) {//알파벳이 있는지 확인하기
					test_count++; //해당 알파벳을 카운트해서 갯수 가져오기
				}
			}
			if (test_count != exp_count) {
				minor--;
				break;
			}
		}
	}
	//출력 : 
	printf("%d", minor);



	//2941
	//목표 : 크로아티아 알파벳과 이외알파벳 갯수를 구한다.
	//입력 : 
	// 1. 최대 100글자단어를 입력 받는다.
	char cro_alpha[100] = { 0 };
	scanf("%s", cro_alpha);
	// 2. 크로아티아 배열을 만든다.
	// 3. count를 선언한다.
	int cro_count = strlen(cro_alpha);//글자를 카운트 해준다.
	//처리 :
	// 3. 단어를 반복문을 돌린다.

	for (int i = 0; i < strlen(cro_alpha); i++) {
		if (cro_alpha[i - 1] == 'c' && cro_alpha[i] == '=') {
			cro_count--;
		}
		if (cro_alpha[i - 1] == 'c' && cro_alpha[i] == '-') {
			cro_count--;
		}
		if (cro_alpha[i - 2] == 'd' && cro_alpha[i - 1] == 'z' && cro_alpha[i] == '=') {
			cro_count--;
		}
		if (cro_alpha[i - 1] == 'd' && cro_alpha[i] == '-') {
			cro_count--;
		}
		if (cro_alpha[i - 1] == 'l' && cro_alpha[i] == 'j') {
			cro_count--;
		}
		if (cro_alpha[i - 1] == 'n' && cro_alpha[i] == 'j') {
			cro_count--;
		}
		if (cro_alpha[i - 1] == 's' && cro_alpha[i] == '=') {
			cro_count--;
		}
		if (cro_alpha[i - 1] == 'z' && cro_alpha[i] == '=') {
			cro_count--;
		}


	}
	// 3-1. 이전 문자가 크로아티아 문자이고, 해당 문자가 크로아 티아 문자이면 count 해준다.
	// 3-1. 크로이티아 문자가 아니면 count 해준다.
	// 4-1. count 값을 출력해준다.
	//출력 :
	printf("%d\n", cro_count);



#pragma endregion



	return 0;
}


//함수
	/*
		함수 : 일련의 과정에 이름을 붙인것
		왜 이름을 붙였을까?
		재사용하기 위해서
	*/
	//두수를 입력받아 그 결과값을 출력하는 함수를 만들기로 했다.
int add(int a, int b) {
	int result = a + b;
	return result;
}