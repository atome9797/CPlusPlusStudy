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

void bubble_sort(int arr[], int count)    // �Ű������� ������ �迭�� ����� ������ ����
{
    int temp;

    for (int i = 0; i < count; i++)    // ����� ������ŭ �ݺ�
    {
        for (int j = 0; j < count - 1; j++)   // ����� ���� - 1��ŭ �ݺ�
        {
            //a �� b�� ��ġ�� �ٲ�
            if (arr[j] > arr[j + 1])          // ���� ����� ���� ���� ����� ���� ���Ͽ�
            {                                 // ū ����
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;            // ���� ��ҷ� ����
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

	//��ǰ ���� �����ϱ�
    int numArr[10] = { 8, 4, 2, 5, 3, 7, 10, 1, 6, 9 };   // ���ĵ��� ���� �迭

    bubble_sort(numArr, sizeof(numArr) / sizeof(int));    // ��ǰ ���� �Լ� ȣ��

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

    //mbstowcs(wtext2, one_line_string, sizeof(one_line_string)+1); //���� 1���� �νĵ�
    //printf("%s", wtext2);
    MultiByteToWideChar(0, NULL, one_line_string, -1, wtext2, 30);
    wprintf(L"%s\n", wtext2);


    char str[128] = "��ﳪabc�����";
    wchar_t *warr = L"�迵��";
    //mbstowcs(warr, L"�迵��", 128);
    wprintf(L"%s\n", warr);//�����ڵ� ���ڿ� ���

	return 0;
}