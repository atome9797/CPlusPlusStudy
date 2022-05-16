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

	return 0;
}