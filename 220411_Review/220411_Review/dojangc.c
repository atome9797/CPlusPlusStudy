#define _CRT_SECURE_NO_WARNINGS    // strcat ���� ���� ���� ������ ����
#include <stdio.h>
#include <string.h> // strcpy �Լ��� ����� ��� ����
#include <stdlib.h>    // malloc, free �Լ��� ����� ��� ����

int main()
{
    int num1 = 20;    // int�� ���� ����
    int* numPtr1;     // int�� ������ ����

    numPtr1 = &num1;  // num1�� �޸� �ּҸ� ���Ͽ� numPtr�� �Ҵ�

    int* numPtr2;     // int�� ������ ����

    numPtr2 = (int*)malloc(sizeof(int));    // int�� ũ�� 4����Ʈ��ŭ ���� �޸� �Ҵ�

    printf("%p\n", numPtr1);    // 006BFA60: ���� num1�� �޸� �ּ� ���
                                // ��ǻ�͸���, ������ ������ �޶���

    printf("%p\n", numPtr2);     // 009659F0: ���� �Ҵ�� �޸��� �ּ� ���
                                // ��ǻ�͸���, ������ ������ �޶���

    free(numPtr2);    // �������� �Ҵ��� �޸� ����


    //strcat ������ ���̱�
    char* s1 = "world";
    char* s2 = malloc(sizeof(char) * 20);

    strcpy(s2, "Hello");
    strcat(s2, s1);
    printf("%s\n", s2);


    //�迭���� ���ڿ��� ���ڿ� �����Ϳ� �����ϱ�
    char s1a[10] = "Hello";
    char* s1b = malloc(sizeof(char) * 10);
    
    strcpy(s1b, s1a);//s1a �� ���ڿ��� s1b�� ���� => �����Ϳ� ���ڿ� ��
    printf("%s\n", s1b); //Hello
    
    //���� �޸� ����
    free(s1b);

    //����1
    char s1c[40];

    scanf("%30s", s1c);

    strcat(s1c, "th");
    printf("%s\n", s1c);
    
    //ũ�Ⱑ 20��




    return 0;

    
}