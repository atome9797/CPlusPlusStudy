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
    
    //strstr :문자열 안에서 문자열 검색 : 해당 문자열이 있는곳 검색해서 이후 문자열 출력
    char s1k[30] = "A Garden Diary";
    char* ptrk = strstr(s1k, "den");
    printf("%s\n", ptrk);
    
    while (ptrk != NULL) {
        printf("%s\n", ptrk);
        ptrk = strstr(ptrk + 1, "den");
    }

    //예제
    char s1m[30] = "Alice in Wonderland";
    char* ptrm = strchr(s1m, 'n');
    
    //n자리에서 출력하면됨
    
    while (ptrm != NULL) {
        printf("%s\n", ptrm);
        ptrm = strchr(ptrm + 1, 'n');
    }


    printf("============== strtchr\n");
    char s1o[30] = "The Little Prince";
    char* ptro = strrchr(s1o , 'i');
    printf("%s\n", ptro);

    
    printf("================= 문자열\n");

    
    char v10[1001];
    printf("문자열을 입력하세요 :");
    //%[^\n] 사용시 오류 나면 한칸 띄어쓰기 해주기
    scanf(" %[^\n]",v10);
    
    
    char* ptr10 = strchr(v10, ' '); //문자열을 받기 때문에 문자열 포인터에 char v10[1001] 배열 주소 들어감
    int count = 0;
    while (ptr10 != NULL) {
        ptr10 = strchr(ptr10 + 1 , ' ');
        count++;
    }


    printf(" %d\n", count);


    //strtok : 문자열 자르기 => 포인터 이용하는 방식 (s100의 주소를 받음) 
    char s100[30] = "The Little Prince";
    char* ptr100 = strtok(s100, " "); //s100 배열중 띄어쓰기 부분까지 짤라서  포인터에 주소와 값 입력
    //토큰 [0][1][2] 

    while (ptr100 != NULL) {
        printf("%s\n", ptr100);
        ptr100 = strtok(NULL, " "); //NULL 을 넣어주면 버퍼에 있는 저장값의 다음 문자열을 불러옴
    } //=> 자르는 부분에 NULL 을 널어 줌으로 원본이 바뀌는것 주의



    char s1h50[30] = "A Garden Diary";
    char* ptr50 = strchr(s1h50, 'a');
    while (ptr50 != NULL)
    {
        printf("%s\n", ptr50);
        ptr50 = strchr(ptr50 + 1, 'a'); //1번 ptr 문자열 뽑았으면 다음 해당 글자가 있는 지점 찾아서 출력
    }


    //malloc 문자열 자르기
    char* s101 = malloc(sizeof(char*) * 30); //버퍼, 동적 메모리
    strcpy(s101, "The Little Prince");// 문자열값 복사해서 할당

    char* ptr101 = strtok(s101, " ");
    while (ptr101 != NULL)
    {
        printf("%s\n", ptr101);
        ptr101 = strtok(NULL, " "); //버퍼 값의 " "부분을 불러와 NULL로 채워줌
    }
    free(s101);


    //다양한 기준문자 지정해서 문자열 자르기
    char s102[30] = "2015-06-10T15:32:19";
    char* ptr102 = strtok(s102, "-T:");//기준문자 여러개 가능
    
    while (ptr102 != NULL)
    {
        printf("%s\n", ptr102);
        ptr102 = strtok(NULL, "-T:"); //버퍼 값의 "-T:"부분을 불러와 NULL로 채워줌
    }

    //자른 문자열 배열에 담고 출력하기
    char s103[30] = "The Little Prince";
    char* sArr103[10] = { NULL, };//배열 담을 저장소
    int i = 0;

    char* ptr103 = strtok(s103, " ");
    while (ptr103 != NULL)
    {
        sArr103[i] = ptr103;//토큰별로 자른 값을 넣어줌
        i++;
        ptr103 = strtok(NULL, " ");//띄어쓰기 자리에 null 넣어줌
    }

    for (int i = 0; i < 10; i++)
    {
        if (sArr103[i] != NULL)
        {
            printf("%s\n", sArr103[i]);
        }
    }

    return 0;
}