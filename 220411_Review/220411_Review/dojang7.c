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

char* strstr3(char* str, char* str2) {

    int count = 0;

    char* temp2 = str;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == str2[0]) {//�ܾ� ���� ��ġ�� ������
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

        //������ �Ǻ�
        if (*rhs == '\0') {
            return A;
        }
        ++A;
    }

    return NULL;
}


/// <summary>
/// �� ������ �ܾ� ���۱��ڰ� ������ for������ ������ ���ڰ� �� ������ Ȯ���ϰ� ������ return ����
/// </summary>
/// <param name="str"></param>
/// <param name="str2"></param>
/// <returns></returns>
// �Ű� ������ �ϳ� �� �ø� => ���� ����
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


//�ϳ��� ž
int N = 0;
//a��ġ���� c��ġ�� �̵�
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

//��������� Ǯ��
void selfNumber(int num) {
    
    //1���� 10000���� �����ڿ� ���ϱ�

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
        //0 �϶��� ������ ��ã�� ����
        printf("%d\n", num);
    }

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


    //strstr ��� �Լ�
    char str201[] = "BlockDMask. He is a smart man";
    char str202[] = "He";
    char* ptr103 = strstr3(str201, str202);
    printf("str : �Լ� �� %s\n", ptr103);


    //�迭���� �����ͷ� ���������ν� ���ڿ��� ���
    char* ptr104 = strstr4(str201, str202);
    printf("str2 : �Լ� �� %s\n", ptr104);


    //�迭���� �����ͷ� ���������ν� ���ڿ��� ���
    char str203[] = "BlockDMask. He is a smart man";
    char str204[] = "art";
    char* ptr105 = strstr5(str203, str204, str203);
    printf("str3 : �Լ� �� %s\n", ptr105);



    char test_ch301[20] = "";
    char origin2[] = "BlockDMask";
    strcpy2(test_ch301, origin2);
    printf("%s\n", test_ch301);


    //strcmp
    char test_ch303[100] = "hana1";
    
    //���ڿ��� �� �ؼ� ������ �ٸ��� �Ǻ�
    if (0 == strcmp2(test_ch303, "hana1")) {
        puts("����");
    }
    else {
        puts("�ٸ�");
    }


    //strcmp ��������� Ǯ��
    char test_ch304[100] = "hana1";

    //���ڿ��� �� �ؼ� ������ �ٸ��� �Ǻ�
    if (0 == strcmp3(test_ch304, "hana")) {
        puts("��� ����");
    }
    else {
        puts("��� �ٸ�");
    }



    //�ϳ��� ž
    int hanoi = 0;
    //scanf("%d", &hanoi);
    //hanoiTop(hanoi,1,2,3);
    //printf("�ϳ��� : %d\n", N);
    //hanoiTop2(hanoi, 1, 2, 3);



    //���� �ѹ�
    /*for (int i = 1; i < 10001; i++)
    {
        selfNumber(i);
    }*/
    for (int i = 1; i < 10001; i++)
    {
        selfNumber(i);
    }

    int numtest = 5 % 10;
    printf("������ : %d\n", numtest); //10�����̱� ������ �������� 5 ����


	return 0;
}