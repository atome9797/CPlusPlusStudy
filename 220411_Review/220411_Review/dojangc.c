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



    //�迭�� ���ڿ� ����� sprintf
    char s1d[20]; //���۷� ����
    sprintf(s1d, "Hello ,%s", "world");
    printf("%s\n", s1d);
    
    char s1e[20];
    //sprintf(s1e, "Hello ,%s %d %f", "world",10,3.2f);
    //printf("%s\n", s1e);

    //���ڿ� �����Ϳ� ���ڿ� �����
    char* s1f = malloc(sizeof(char) * 20); //���۷� ����
    sprintf(s1f, "Hello, %s", "world");
    printf("%s\n", s1f);
    free(s1f);
    
    char* s1g = malloc(sizeof(char) * 30);
    sprintf(s1g, "%c %d %f %e", 'a',10,3.4f,1.123456e-21);
    printf("%s\n", s1g);
    free(s1g);

    //strchr : ���ڿ� �˻��ϱ� : ���ڿ����� Ư�����ڷ� �˻��ؼ� ���� ���ڿ� ���
    char s1h[30] = "A Garden Diary";
    char* ptr = strchr(s1h, 'a'); 
    while (ptr != NULL)
    {
        printf("%s\n", ptr);
        ptr = strchr(ptr + 1, 'a'); //1�� ptr ���ڿ� �̾����� ���� �ش� ���ڰ� �ִ� ���� ã�Ƽ� ���
    }


    //strrchr : �����ʳ��� �������� ���ڿ� �˻��ϱ� : ���ڿ����� Ư�����ڷ� �˻��ؼ� ���� ���ڿ� ���
    char s1j[30] = "A Garden Diary";
    char* ptrj = strrchr(s1j, 'a');
    
    //strstr :���ڿ� �ȿ��� ���ڿ� �˻� : �ش� ���ڿ��� �ִ°� �˻��ؼ� ���� ���ڿ� ���
    char s1k[30] = "A Garden Diary";
    char* ptrk = strstr(s1k, "den");
    printf("%s\n", ptrk);
    
    while (ptrk != NULL) {
        printf("%s\n", ptrk);
        ptrk = strstr(ptrk + 1, "den");
    }

    //����
    char s1m[30] = "Alice in Wonderland";
    char* ptrm = strchr(s1m, 'n');
    
    //n�ڸ����� ����ϸ��
    
    while (ptrm != NULL) {
        printf("%s\n", ptrm);
        ptrm = strchr(ptrm + 1, 'n');
    }


    printf("============== strtchr\n");
    char s1o[30] = "The Little Prince";
    char* ptro = strrchr(s1o , 'i');
    printf("%s\n", ptro);

    
    printf("================= ���ڿ�\n");

    
    char v10[1001];
    printf("���ڿ��� �Է��ϼ��� :");
    //%[^\n] ���� ���� ���� ��ĭ ���� ���ֱ�
    scanf(" %[^\n]",v10);
    
    
    char* ptr10 = strchr(v10, ' '); //���ڿ��� �ޱ� ������ ���ڿ� �����Ϳ� char v10[1001] �迭 �ּ� ��
    int count = 0;
    while (ptr10 != NULL) {
        ptr10 = strchr(ptr10 + 1 , ' ');
        count++;
    }


    printf(" %d\n", count);


    //strtok : ���ڿ� �ڸ��� => ������ �̿��ϴ� ��� (s100�� �ּҸ� ����) 
    char s100[30] = "The Little Prince";
    char* ptr100 = strtok(s100, " "); //s100 �迭�� ���� �κб��� ©��  �����Ϳ� �ּҿ� �� �Է�
    //��ū [0][1][2] 

    while (ptr100 != NULL) {
        printf("%s\n", ptr100);
        ptr100 = strtok(NULL, " "); //NULL �� �־��ָ� ���ۿ� �ִ� ���尪�� ���� ���ڿ��� �ҷ���
    } //=> �ڸ��� �κп� NULL �� �ξ� ������ ������ �ٲ�°� ����



    char s1h50[30] = "A Garden Diary";
    char* ptr50 = strchr(s1h50, 'a');
    while (ptr50 != NULL)
    {
        printf("%s\n", ptr50);
        ptr50 = strchr(ptr50 + 1, 'a'); //1�� ptr ���ڿ� �̾����� ���� �ش� ���ڰ� �ִ� ���� ã�Ƽ� ���
    }


    //malloc ���ڿ� �ڸ���
    char* s101 = malloc(sizeof(char*) * 30); //����, ���� �޸�
    strcpy(s101, "The Little Prince");// ���ڿ��� �����ؼ� �Ҵ�

    char* ptr101 = strtok(s101, " ");
    while (ptr101 != NULL)
    {
        printf("%s\n", ptr101);
        ptr101 = strtok(NULL, " "); //���� ���� " "�κ��� �ҷ��� NULL�� ä����
    }
    free(s101);


    //�پ��� ���ع��� �����ؼ� ���ڿ� �ڸ���
    char s102[30] = "2015-06-10T15:32:19";
    char* ptr102 = strtok(s102, "-T:");//���ع��� ������ ����
    
    while (ptr102 != NULL)
    {
        printf("%s\n", ptr102);
        ptr102 = strtok(NULL, "-T:"); //���� ���� "-T:"�κ��� �ҷ��� NULL�� ä����
    }

    //�ڸ� ���ڿ� �迭�� ��� ����ϱ�
    char s103[30] = "The Little Prince";
    char* sArr103[10] = { NULL, };//�迭 ���� �����
    int i = 0;

    char* ptr103 = strtok(s103, " ");
    while (ptr103 != NULL)
    {
        sArr103[i] = ptr103;//��ū���� �ڸ� ���� �־���
        i++;
        ptr103 = strtok(NULL, " ");//���� �ڸ��� null �־���
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