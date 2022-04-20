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


    char s104[40] = "Alice's Adventures in Wonderland";
    char* ptr104 = strtok(s104, " ");
    while (ptr104 != NULL)
    {
        printf("%s\n", ptr104);
        ptr104 = strtok(NULL, " "); //버퍼 안에 있는 " " 부분을 NULL로 변경함
    }


    char s105[100];
    printf("주소 입력 :");
    scanf("%s", s105);
    char* ptr105 = strtok(s105, ".");
    while (ptr105 != NULL) {
        printf("%s\n", ptr105);
        ptr105 = strtok(NULL, ".");
    }

    //문자열과 숫자를 서로 변환하기
    char* s106 = "283"; //문자열 주소 추가
    int num106;
    
    num106 = atoi(s106); //문자열을 정수로 변환
    printf("%d\n", num106);

    //특정 진법 문자열을 정수로표현
    char* s107 = "0xaf10";
    int num107;
    num107 = strtol(s107, NULL, 16);//16진수 문자열을 정수로 바꾸기 
    //=> strtol 함수에서 문자열 띄어쓰기 또는끝부분에 null 을 넣어 줌으로써 짤라서 출력하게 해줌
       
    printf("%x %d\n", num107, num107);//%x는 16진수로 표현  => af10 44816

    char* s108 = "0xaf10 42 0x27C 9952";
    int num108;
    int num109;
    int num110;
    int num111;
    char* end;

    num108 = strtol(s108, &end, 16); //s108 char 불러와 end주소에 16진수로 띄어쓰기까지 끊어서 넣어줌
    num109 = strtol(end, &end, 16); //42 0x27C 9952 불러와 end 주소에 16진수로 띄어쓰기까지 끊어서 넣어줌
    num110 = strtol(end, &end, 16); //0x27C 9952 불러와 띄어쓰기 까지 끊어서 end에 저장함
    num111 = strtol(end, NULL, 16); //9952 는 null 만나고 끝나고 마직막 end값을 num111에 저장함

    printf("%x\n", num108);
    printf("%d\n", num109);
    printf("%x\n", num110);
    printf("%d\n", num111);


    //문자열을 실수로 변환
    char* s112 = "35.283672";
    float num112;
    
    num112 = atof(s112);
    printf("%f\n", num112);

    char* s113 = "35.283672 3.e5 9.281772 7.e-5";
    float num113;
    float num114;
    float num115;
    float num116;
    char* end113;
    
    num113 = strtof(s113, &end113); //s113문자열을 띄어쓰기 부분에서 자른후 나머지값을 포인터에 대입
    num114 = strtof(end113, &end113); //포인터에 대입한 값에서 띄어쓰기 부분에서 자른후 나머지값을 다시 포인터에 대입
    num115 = strtof(end113, &end113);
    num116 = strtof(end113, NULL); //문자열의 NULL 만나면 종료

    printf("%f\n",num113);
    printf("%e\n",num114);
    printf("%f\n",num115);
    printf("%e\n",num116);

    //정수를 문자열로 변환하기
    char s117[10];
    int num117 = 283;
    sprintf(s117, "%d", num117); //정수를 문자열로 변환
    printf("%s\n", s117);
    sprintf(s117, "%x", num117); //정수를 문자열로 변환
    printf("%s\n", s117);
    sprintf(s117, "%X", num117); //정수를 문자열로 변환
    printf("%s\n", s117); //16진수 출력함

    //실수를 문자열로 변환
    char s118[10];
    float num118 = 38.972340f;
    sprintf(s118, "%f", num118);
    printf("%s\n", s118);
    
    //예제
    char* s119 = "0x1facefee";
    int num119;
    num119 = strtol(s119, NULL, 16); //첫인자 : NULL로 종결되는 부분을 포함하는 문자열 포인터, 두번째 인자 : 변환이 멈춘 문자열 포인터, 새번째 : 진수
    printf("0x%X\n", num119); //16진수로 출력

    //예제2 문자열을 실수로 변환
    char* s120 = "97.527824";
    float num120;
    num120 = atof(s120);
    printf("%f\n", num120);

    //예제2 문자열 실수로 변환
    char* s121 = "29.977213 4528.112305";
    float num121;
    float num122;
    char* end121;

    num121 = strtof(s121, &end121); //문자열을 문자 끊어지는데까지 받고 포인터에 나머지 넣기 그리고 float 에 받은값 담기
    num122 = strtof(end121, NULL); //문자열을 문자 끊어지는데까지 받고 NULL이면 끝내기 그리고 float 에 받은값 담기

    printf("%f\n", num121);
    printf("%f\n", num122);
    
    //예제3 숫자를 문자열로 변환하기
    char* s123[10];
    float num123 = 98.415237f;
    int num124 = 0x3fce1920;
    sprintf(s123, "%f 0x%x", num123, num124);

    printf("%s\n", s123);
    
    //예제 4 문자열 숫자로 변환하기
    char s125[50];
    int num125;
    int num126;
    float num127;
    char* end125;

    printf("문자열 숫자로 변환\n");
    scanf(" %[^\n]", s125);

    num125 = strtof(s125, &end125); //실수 부분을 끊어줌, 
    num126 = strtof(end125, &end125); //실수 부분을 끊어줌, 
    num127 = strtof(end125, NULL); //마지막 문자열 만나고 NULL로 끝남
    printf("0x%x\n", num125);
    printf("%d\n", num126);
    printf("%f\n", num127);
    
    return 0;
}