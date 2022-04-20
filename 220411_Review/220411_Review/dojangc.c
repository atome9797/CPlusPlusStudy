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


    char s104[40] = "Alice's Adventures in Wonderland";
    char* ptr104 = strtok(s104, " ");
    while (ptr104 != NULL)
    {
        printf("%s\n", ptr104);
        ptr104 = strtok(NULL, " "); //���� �ȿ� �ִ� " " �κ��� NULL�� ������
    }


    char s105[100];
    printf("�ּ� �Է� :");
    scanf("%s", s105);
    char* ptr105 = strtok(s105, ".");
    while (ptr105 != NULL) {
        printf("%s\n", ptr105);
        ptr105 = strtok(NULL, ".");
    }

    //���ڿ��� ���ڸ� ���� ��ȯ�ϱ�
    char* s106 = "283"; //���ڿ� �ּ� �߰�
    int num106;
    
    num106 = atoi(s106); //���ڿ��� ������ ��ȯ
    printf("%d\n", num106);

    //Ư�� ���� ���ڿ��� ������ǥ��
    char* s107 = "0xaf10";
    int num107;
    num107 = strtol(s107, NULL, 16);//16���� ���ڿ��� ������ �ٲٱ� 
    //=> strtol �Լ����� ���ڿ� ���� �Ǵ³��κп� null �� �־� �����ν� ©�� ����ϰ� ����
       
    printf("%x %d\n", num107, num107);//%x�� 16������ ǥ��  => af10 44816

    char* s108 = "0xaf10 42 0x27C 9952";
    int num108;
    int num109;
    int num110;
    int num111;
    char* end;

    num108 = strtol(s108, &end, 16); //s108 char �ҷ��� end�ּҿ� 16������ ������� ��� �־���
    num109 = strtol(end, &end, 16); //42 0x27C 9952 �ҷ��� end �ּҿ� 16������ ������� ��� �־���
    num110 = strtol(end, &end, 16); //0x27C 9952 �ҷ��� ���� ���� ��� end�� ������
    num111 = strtol(end, NULL, 16); //9952 �� null ������ ������ ������ end���� num111�� ������

    printf("%x\n", num108);
    printf("%d\n", num109);
    printf("%x\n", num110);
    printf("%d\n", num111);


    //���ڿ��� �Ǽ��� ��ȯ
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
    
    num113 = strtof(s113, &end113); //s113���ڿ��� ���� �κп��� �ڸ��� ���������� �����Ϳ� ����
    num114 = strtof(end113, &end113); //�����Ϳ� ������ ������ ���� �κп��� �ڸ��� ���������� �ٽ� �����Ϳ� ����
    num115 = strtof(end113, &end113);
    num116 = strtof(end113, NULL); //���ڿ��� NULL ������ ����

    printf("%f\n",num113);
    printf("%e\n",num114);
    printf("%f\n",num115);
    printf("%e\n",num116);

    //������ ���ڿ��� ��ȯ�ϱ�
    char s117[10];
    int num117 = 283;
    sprintf(s117, "%d", num117); //������ ���ڿ��� ��ȯ
    printf("%s\n", s117);
    sprintf(s117, "%x", num117); //������ ���ڿ��� ��ȯ
    printf("%s\n", s117);
    sprintf(s117, "%X", num117); //������ ���ڿ��� ��ȯ
    printf("%s\n", s117); //16���� �����

    //�Ǽ��� ���ڿ��� ��ȯ
    char s118[10];
    float num118 = 38.972340f;
    sprintf(s118, "%f", num118);
    printf("%s\n", s118);
    
    //����
    char* s119 = "0x1facefee";
    int num119;
    num119 = strtol(s119, NULL, 16); //ù���� : NULL�� ����Ǵ� �κ��� �����ϴ� ���ڿ� ������, �ι�° ���� : ��ȯ�� ���� ���ڿ� ������, ����° : ����
    printf("0x%X\n", num119); //16������ ���

    //����2 ���ڿ��� �Ǽ��� ��ȯ
    char* s120 = "97.527824";
    float num120;
    num120 = atof(s120);
    printf("%f\n", num120);

    //����2 ���ڿ� �Ǽ��� ��ȯ
    char* s121 = "29.977213 4528.112305";
    float num121;
    float num122;
    char* end121;

    num121 = strtof(s121, &end121); //���ڿ��� ���� �������µ����� �ް� �����Ϳ� ������ �ֱ� �׸��� float �� ������ ���
    num122 = strtof(end121, NULL); //���ڿ��� ���� �������µ����� �ް� NULL�̸� ������ �׸��� float �� ������ ���

    printf("%f\n", num121);
    printf("%f\n", num122);
    
    //����3 ���ڸ� ���ڿ��� ��ȯ�ϱ�
    char* s123[10];
    float num123 = 98.415237f;
    int num124 = 0x3fce1920;
    sprintf(s123, "%f 0x%x", num123, num124);

    printf("%s\n", s123);
    
    //���� 4 ���ڿ� ���ڷ� ��ȯ�ϱ�
    char s125[50];
    int num125;
    int num126;
    float num127;
    char* end125;

    printf("���ڿ� ���ڷ� ��ȯ\n");
    scanf(" %[^\n]", s125);

    num125 = strtof(s125, &end125); //�Ǽ� �κ��� ������, 
    num126 = strtof(end125, &end125); //�Ǽ� �κ��� ������, 
    num127 = strtof(end125, NULL); //������ ���ڿ� ������ NULL�� ����
    printf("0x%x\n", num125);
    printf("%d\n", num126);
    printf("%f\n", num127);
    
    return 0;
}