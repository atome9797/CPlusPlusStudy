#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct tagPlayer
{
    //int num;
    int		Gun2[2];
} Player;


typedef struct tagGun
{
    int	BulletCount;
} Gun;

void bubble_sort(int arr[], int count)    // 매개변수로 정렬할 배열과 요소의 개수를 받음
{
    int temp;

    for (int i = 0; i < count; i++)    // 요소의 개수만큼 반복
    {
        for (int j = 0; j < count - 1; j++)   // 요소의 개수 - 1만큼 반복
        {
            //a 와 b의 위치를 바꿈
            if (arr[j] > arr[j + 1])          // 현재 요소의 값과 다음 요소의 값을 비교하여
            {                                 // 큰 값을
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;            // 다음 요소로 보냄
            }
        }
    }
}



char* replaceAll(char* s, const char* olds, const char* news) {
    char* result, * sr;
    size_t i, count = 0;
    size_t oldlen = strlen(olds); if (oldlen < 1) return s;
    size_t newlen = strlen(news);


    if (newlen != oldlen) {
        for (i = 0; s[i] != '\0';) {
            if (memcmp(&s[i], olds, oldlen) == 0) count++, i += oldlen;
            else i++;
        }
    }
    else i = strlen(s);


    result = (char*)malloc(i + 1 + count * (newlen - oldlen));
    if (result == NULL) return NULL;


    sr = result;
    while (*s) {
        if (memcmp(s, olds, oldlen) == 0) {
            memcpy(sr, news, newlen);
            sr += newlen;
            s += oldlen;
        }
        else *sr++ = *s++;
    }
    *sr = '\0';

    return result;
}

char* strstr3(char* str, char* str2) {

    int count = 0;

    char* temp2 = str;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == str2[0]) {//단어 시작 위치랑 같을때
            //char* temp = str;
            for (int j = 0; str2[j] != '\0'; j++)
            {
                if (str[i + j] == str2[j]) {
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

/// <summary>
/// 
/// </summary>
/// <param name="A"></param>
/// <param name="B"></param>
/// <returns></returns>
char* strstr4(const char A[], const char B[]) {
    if (*B == '\0') {
        return A;
    }

    while (*A != '\0') {
        int isFound = 0;
        const char* lhs = A;
        const char* rhs = B;
        while (*lhs != '\0' && *rhs != '\0') {
            if (*lhs != *rhs) {
                break;
            }
            ++lhs;
            ++rhs;
        }

        //같은지 판별
        if (*rhs == '\0') {
            return A;
        }
        ++A;
    }

    return NULL;
}


/// <summary>
/// 두 문장의 단어 시작글자가 같을때 for문으로 나머지 글자가 다 같은지 확인하고 같으면 return 해줌
/// </summary>
/// <param name="str"></param>
/// <param name="str2"></param>
/// <returns></returns>
// 매개 변수를 하나 더 늘림 => 원본 저장
char* strstr5(char* str, char* str2, char* str3) {
    
    if (*str2 == '\0') {
        return str3;
    }

    if (*str == *str2) {
        strstr5(++str, ++str2, str3); 
    }
    else {
        strstr5(++str, str2, ++str3); 
    }
}


void strcpy2(char* str, char* str2) {

    if (*str2 == '\0') {
        return;
    }
    *str = *str2;

    strcpy2(++str, ++str2);
}

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


int strcmp3(char* str, char* str2) {

    if (*str2 != *str) {
        return 1;
    }

    if (*str2 == '\0') {
        return 0;
    }
    
    strcmp3(++str, ++str2);
    
}


//하노이 탑
int N = 0;
//a위치에서 c위치로 이동
void hanoiTop(int hanoi, int a, int b, int c) {
    
    
    if (hanoi == 1) {
        return N++;
    }

    hanoiTop(hanoi - 1, a, c, b);
    hanoiTop(1, a, b, c);
    hanoiTop(hanoi - 1, b, a, c);

}

void hanoiTop2(int hanoi, int a, int b, int c) {


    if (hanoi == 1) {
        printf("%d %d\n", a, c);
        return;
    }

    hanoiTop2(hanoi - 1, a, c, b);
    hanoiTop2(1, a, b, c);
    hanoiTop2(hanoi - 1, b, a, c);

}

//재귀적으로 풀기
void selfNumber(int num) {
    
    //1부터 10000까지 생성자와 비교하기

    int count = 0;
    
    for (int i = 1; i < 10000; i++)
    {
        int testp = i;

        int num1 = testp % 10;
        testp = testp / 10;
        int num2 = testp % 10;
        testp = testp / 10;
        int num3 = testp % 10;
        testp = testp / 10;
        int num4 = testp % 10;
        testp = testp / 10;
        int num5 = testp % 10;


        
        if (num5 > 0) {
            int test = (num5 * 10000 + num4 * 1000 + num3 * 100 + num2 * 10 + num1) + num5 + num4+ num3 + num2 + num1;

            if (test == num) {
                count++;
            }
        }else if (num4 > 0) {
            int test = (num4 * 1000 + num3 * 100 + num2 * 10 + num1) + num4 + num3 + num2 + num1;

            if (test == num) {
                count++;
            }
        }else if (num3 > 0) {
            int test = (num3 * 100 + num2 * 10 + num1) + num3 + num2 + num1;

            if (test == num) {
                count++;
            }
        }else if (num2 > 0) {
            int test = (num2 * 10 + num1) + num2 + num1;

            if (test == num) {
                count++;
            }
        } else if (num1 > 0) {
            int test = num1 + num1;

            if (test == num) {
                count++;
            }
        }
    }

    if(count == 0) {
        //0 일때는 생성자 못찾은 거임
        printf("%d\n", num);
    }

}

int main() {

	//거품 정렬 구현하기
    int numArr[10] = { 8, 4, 2, 5, 3, 7, 10, 1, 6, 9 };   // 정렬되지 않은 배열

    bubble_sort(numArr, sizeof(numArr) / sizeof(int));    // 거품 정렬 함수 호출

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", numArr[i]);    // 1 2 3 4 5 6 7 8 9 10
    }

    printf("\n");
    
    
    Player py;

    int count = 0;
    
    

    printf("%d\n", sizeof(Player));


    char one_line_string[128];
    FILE* p_file = NULL;
    if (0 == fopen_s(&p_file, "school.csv", "rt")) {
        if (NULL != fgets(one_line_string, 128, p_file)) {
            fclose(p_file);
        }
    }
    wchar_t wtext2[30];

    char* ptr = replaceAll(one_line_string, ",", "\n");

    //mbstowcs(wtext2, one_line_string, sizeof(one_line_string)+1); //문자 1개만 인식됨
    //printf("%s", wtext2);
    MultiByteToWideChar(0, NULL, one_line_string, -1, wtext2, 30);
    wprintf(L"%s\n", wtext2);


    char str[128] = "기억나abc나비야";
    wchar_t *warr = L"김영훈";
    //mbstowcs(warr, L"김영훈", 128);
    wprintf(L"%s\n", warr);//유니코드 문자열 출력


    //strstr 재귀 함수
    char str201[] = "BlockDMask. He is a smart man";
    char str202[] = "He";
    char* ptr103 = strstr3(str201, str202);
    printf("str : 함수 값 %s\n", ptr103);


    //배열값을 포인터로 리턴함으로써 문자열을 출력
    char* ptr104 = strstr4(str201, str202);
    printf("str2 : 함수 값 %s\n", ptr104);


    //배열값을 포인터로 리턴함으로써 문자열을 출력
    char str203[] = "BlockDMask. He is a smart man";
    char str204[] = "art";
    char* ptr105 = strstr5(str203, str204, str203);
    printf("str3 : 함수 값 %s\n", ptr105);



    char test_ch301[20] = "";
    char origin2[] = "BlockDMask";
    strcpy2(test_ch301, origin2);
    printf("%s\n", test_ch301);


    //strcmp
    char test_ch303[100] = "hana1";
    
    //문자열을 비교 해서 같은지 다른지 판별
    if (0 == strcmp2(test_ch303, "hana1")) {
        puts("같음");
    }
    else {
        puts("다름");
    }


    //strcmp 재귀적으로 풀기
    char test_ch304[100] = "hana1";

    //문자열을 비교 해서 같은지 다른지 판별
    if (0 == strcmp3(test_ch304, "hana")) {
        puts("재귀 같음");
    }
    else {
        puts("재귀 다름");
    }



    //하노이 탑
    int hanoi = 0;
    //scanf("%d", &hanoi);
    //hanoiTop(hanoi,1,2,3);
    //printf("하노이 : %d\n", N);
    //hanoiTop2(hanoi, 1, 2, 3);



    //셀프 넘버
    /*for (int i = 1; i < 10001; i++)
    {
        selfNumber(i);
    }*/
    for (int i = 1; i < 10001; i++)
    {
        selfNumber(i);
    }

    int numtest = 5 % 10;
    printf("나머지 : %d\n", numtest); //10이하이기 때문에 나머지가 5 나옴


	return 0;
}