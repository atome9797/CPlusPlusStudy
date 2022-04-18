#define _CRT_SECURE_NO_WARNINGS    // strcat 보안 경고로 인한 컴파일 에러
#include <stdio.h>
#include <string.h> // strcpy 함수가 선언된 헤더 파일
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일

int main()
{
    int num1 = 20;    // int형 변수 선언
    int* numPtr1;     // int형 포인터 선언

    numPtr1 = &num1;  // num1의 메모리 주소를 구하여 numPtr에 할당

    int* numPtr2;     // int형 포인터 선언

    numPtr2 = (int*)malloc(sizeof(int));    // int의 크기 4바이트만큼 동적 메모리 할당

    printf("%p\n", numPtr1);    // 006BFA60: 변수 num1의 메모리 주소 출력
                                // 컴퓨터마다, 실행할 때마다 달라짐

    printf("%p\n", numPtr2);     // 009659F0: 새로 할당된 메모리의 주소 출력
                                // 컴퓨터마다, 실행할 때마다 달라짐

    free(numPtr2);    // 동적으로 할당한 메모리 해제


    //strcat 포인터 붙이기
    char* s1 = "world";
    char* s2 = malloc(sizeof(char) * 20);

    strcpy(s2, "Hello");
    strcat(s2, s1);
    printf("%s\n", s2);


    //배열형태 문자열을 문자열 포인터에 복사하기
    char s1a[10] = "Hello";
    char* s1b = malloc(sizeof(char) * 10);
    
    strcpy(s1b, s1a);//s1a 의 문자열을 s1b에 복사 => 포인터에 문자열 들어감
    printf("%s\n", s1b); //Hello
    
    //동적 메모리 해제
    free(s1b);

    //예제1
    char s1c[40];

    scanf("%30s", s1c);

    strcat(s1c, "th");
    printf("%s\n", s1c);



    //배열에 문자열 만들기 sprintf
    char s1d[20]; //버퍼로 사용됨
    sprintf(s1d, "Hello ,%s", "world");
    printf("%s\n", s1d);
    
    char s1e[20];
    //sprintf(s1e, "Hello ,%s %d %f", "world",10,3.2f);
    //printf("%s\n", s1e);

    //문자열 포인터에 문자열 만들기
    char* s1f = malloc(sizeof(char) * 20); //버퍼로 사용됨
    sprintf(s1f, "Hello, %s", "world");
    printf("%s\n", s1f);
    free(s1f);
    
    char* s1g = malloc(sizeof(char) * 30);
    sprintf(s1g, "%c %d %f %e", 'a',10,3.4f,1.123456e-21);
    printf("%s\n", s1g);
    free(s1g);

    //strchr : 문자열 검색하기 : 문자열에서 특정문자로 검색해서 이후 문자열 출력
    char s1h[30] = "A Garden Diary";
    char* ptr = strchr(s1h, 'a'); 
    while (ptr != NULL)
    {
        printf("%s\n", ptr);
        ptr = strchr(ptr + 1, 'a'); //1번 ptr 문자열 뽑았으면 다음 해당 글자가 있는 지점 찾아서 출력
    }


    //strrchr : 오른쪽끝을 기준으로 문자열 검색하기 : 문자열에서 특정문자로 검색해서 이후 문자열 출력
    char s1j[30] = "A Garden Diary";
    char* ptrj = strrchr(s1j, 'a');
    
    //strstr :문자열 안에서 문자열 검색


    return 0;
}