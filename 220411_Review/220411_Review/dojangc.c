#define _CRT_SECURE_NO_WARNINGS    // strcat ���� ���� ���� ������ ����
#include <stdio.h>
#include <string.h> // strcpy �Լ��� ����� ��� ����
#include <stdlib.h>    // malloc, free �Լ��� ����� ��� ����
#include <stdbool.h>
#include <math.h>
#include <stddef.h>

#pragma region ����ü����
struct Person {//����ü ���� �±׶� �Ѵ�

    char name[20];
    int age;
    char address[100];

} p1; //���������� ����ü �������� : � �Լ����� ������ ���� ������ ���� ��������


struct Person2 {

    char name[20];
    int age;

};

typedef struct Person_test {
    char name[20];
    int age;
    char address[100];
} test;

struct Data {

    char c123;
    int* numPtr123;//����ü �ȿ��� �����͸� ����
};


struct Point2D {
    int x;
    int y;
};

struct Rectangle {
    int x1, y1;
    int x2, y2;
};

#pragma pack(push,1)
struct PacketHeader {

    char flags;
    int seq;
};
#pragma pack(pop)

struct Phone {    // �޴���ȭ ����ü
    int areacode;                 // ������ȣ
    unsigned long long number;    // �޴���ȭ ��ȣ
};

struct Person3 {
    char name[20];
    int age;
    struct Phone phone;
};

struct Person4 {
    char name[20];
    int age;
    struct Phone *phone;
};

struct Vector3 { //3���� ���� ��ǥ
    union { //�͸����ü 12����Ʈ
        struct { //�͸���ü
            float x; //x��ǥ
            float y; //y��ǥ
            float z; //z��ǥ
        };
        float v[3]; //��ǥ �迭�� ����
    };
};

//��Ʈ �ʵ� ���� : unsigned �ڷ����� �ַ� ��� + �Ǽ� �ڷ����� ��� ����
struct Flags {
    unsigned int a : 1; //a�� 1��Ʈ ũ��
    unsigned int b : 3; //b�� 3��Ʈ ũ��
    unsigned int c : 7; //c�� 7��Ʈ ũ��
};

//��Ʈ�ʵ�� ����ü �Բ� ����ϱ�
struct Flags2 {
    union {
        struct {
            unsigned short a : 3;
            unsigned short b : 2;
            unsigned short c : 7;
            unsigned short d : 4;
        };
        unsigned short e; //���� 16��Ʈ�� �޸� ����
    };
};

#pragma endregion

#pragma region typedef���� 

    // ����
typedef struct _Point3D {
    float x;
    float y;
    float z;
} Point3D;

    //typedef : ������ �����ϴ� Ŭ���� : �ڷ����� ��Ī�� �ο��ϰ� ����
typedef int MYINT; //int���� ��Ī ����
typedef int *PMYINT;//�������� ��Ī ����

    //typedef ����ü �±׸� ��������
typedef struct {
    char name[20];
    int age;
    char address[100];
    char asd;
} User;



#pragma endregion

#pragma region ����ü����

union Box {
    short candy; //2����Ʈ
    float snack; //4����Ʈ
    char doll[8]; //8����Ʈ
};

union uData {
    char c1;
    short num1;
    int num2;
};

//�͸��� ����ü ����
typedef union { 
    short candy;
    float snack;
    char doll[8];
} Box2;//��Ī ����

Box2 bx2;//��Ī���� ����ü ���� ����


//����ü ���ǿ� ���ÿ� ���� ����
union Box3 {
    short candy;
    float snack;
    char doll[8];
} b2;


#pragma endregion


int main()
{

#pragma region ����ü

    // �޸� ������ �����Ҽ� �ִ�.
    //����ü ����ϱ� => ��� ���� ����� ����ü�� �ٸ�
    union Box b1;
    printf("%d\n", sizeof(b1)); //����ü�� ����ū �ڷ��� ũ��� ������ (���� �ٸ� �ڷ����� ������ ������ �����Ҹ� ���� ����)

    strcpy(b1.doll, "bear");
    b1.candy = 1;
    b1.snack = 1.3;

    //����ü�� ������ ��� ��Ҹ� �����ϱ� ������ ���� �ϳ��� �Ҵ� �� �� �ְ�, 
    //������ ������ ������ �Ǿ� ��µ� => �ѹ����� ���� ���������� ����Ҽ� �ִ�.
    printf("%d\n", b1.candy);  
    printf("%f\n", b1.snack);  
    printf("%s\n", b1.doll);

    
    //�ѹ����� ����ϸ� ���������� ��밡��
    strcpy(b1.doll, "bear");
    printf("����ü : %s\n", b1.doll);
    b1.candy = 1;
    printf("����ü : %d\n", b1.candy);  
    b1.snack = 1.3;
    printf("����ü : %f\n", b1.snack);  
    

    //����ü�� �����
    union uData udt;// ����ü ����

    udt.num2 = 0x12345678;//��Ʋ ����� ������� �޸� ���� => 78 56 34 12 �޸� �� (4������ 4����Ʈ)
    printf("0x%x\n", udt.num2); //4����Ʈ ��ü�� ���  
    printf("0x%x\n", udt.num1); //2����Ʈ ��� => 78 56 �� 2���� ��µ� (��Ʋ ������� 78�� ���� �ڸ�����)
    printf("0x%x\n", udt.c1); //1����Ʈ ��� => 78 �� 1���� ��µ�

    printf("%d\n", sizeof(udt));//����ū �޸𸮰� int�� 4����Ʈ ����


    //����ü �����͸� �����ϰ� �޸� �Ҵ��ϱ�
    //����ü�� ��Ī���� ���� ���������Ƿ� , �������� ���� ����ü�� ���ٰ���
    bx2.candy;

    //�����Ϳ� ���� => ����ü �뷮�� 8����Ʈ�� 
    union Box *bxp = malloc(sizeof(union Box));
    printf("%d\n", sizeof(union Box));

    bxp->snack = 1.3f;
    strcpy(bxp->doll, "bear"); //�������� ���Ե� ������ ����ü Ÿ�Թ� ���� �ٲ�
    
    printf("%d\n", bxp->candy); 
    printf("%s\n", bxp->doll);
    printf("%f\n", bxp->snack); 
    
    free(bxp);


    //����ü ��Ī�� �͸� ����ü �����Ϳ� �޸� �Ҵ��ϱ�
    //union Box bx10; //����ü ���� ����
    //union Box *bxptr;//����ü ���� ������ ����
    //
    //bxptr = &bx10; //����ü �����Ϳ� ����ü �Ҵ�
    //
    //strcpy(bxptr->doll, "bear");

    //printf("%d\n", bxptr->candy);
    //printf("%f\n", bxptr->snack);
    //printf("%s\n", bxptr->doll);

    //free(bxptr); => heap���� �ʱ�ȭ �Ҷ� ���� �߻�


    //����ü �ȿ� ����ü ����
    struct Person3 psn;
    psn.phone.areacode = 82;
    psn.phone.number = 3045671234;
    printf("%d %llu\n", psn.phone.areacode, psn.phone.number);

    //����� ���ÿ� �ʱ�ȭ
    struct Person3 psn2 = { .name = "Andrew", .age = 25, {.areacode = 82, .number= 3045671234} };
    //����� ���ÿ� �ʱ�ȭ2
    struct Person3 psn3 = { "Andrew",25,{82,3045671234} };


    //����ü ���� ����ü�� �޸� �Ҵ��ϱ�
    //�����Ϳ��� ����ü�Ǳ���ü�� �� �Ҵ�
    struct Person3* psn4 = malloc(sizeof(struct Person3));
    psn4->phone.areacode = 83;
    psn4->phone.number = 3045671234;

    //�����Ϳ��� ����ü�� �����ͷ� �� �Ҵ�
    struct Person4* psn5 = malloc(sizeof(struct Person4));
    psn5->phone->areacode = 83;
    psn5->phone->number = 3045671234;
    printf("�����ͷ� �� : %d %llu\n", psn5->phone->areacode, psn5->phone->number);

    free(psn5->phone);//�����ͱ���ü���� �����͸� �ʱ�ȭ ������
    free(psn5);// ������ �ʱ�ȭ


    //�͸� ����ü�� �͸� ����ü Ȱ���ϱ�
    struct Vector3 pos;

    for (int i = 0; i < 3; i++)
    {
        pos.v[i] = 1.0f;//�͸� ����ü, �͸���ü�̱� ������ .���� ���°� ���� �ٷ� ��밡��
        //union�̱� ������ x,y,z�� ���� �Ҵ��(���� ���� ���� �����̿�)
    }
    
    printf("%f %f %f\n", pos.x,pos.y,pos.z);//union���� �Ҵ����
    

    //����ü ��Ʈ �ʵ� ����ϱ� => ������ ��Ʈ�� ��ŭ�� �����(������ �߶�)
    struct Flags f1;
    f1.a = 1; //1��Ʈ�̹Ƿ� ���߸�
    f1.b = 15; //3��Ʈ�̹Ƿ� 3��Ʈ�ڸ� ��ŭ�� �߷��� ��µ� 111 =>7
    f1.c = 255; //7��Ʈ �ڸ������� �߷��� ��µ�

    //��Ʈ �ʵ��� �޸𸮴� ���� ��Ʈ���� ������ ��Ʈ���� ������� ��ġ��
    printf("%d", sizeof(struct Flags)); //4���
    //����� unsigned int�� ���������Ƿ� 4��µ�

    //����
    /*
        unsigned int a : 37;    // ������ ����. unsigned int���� ū ��Ʈ ���� �����Ҽ� ����
    */


    //��Ʈ�ʵ�� ����ü �Բ� ����ϱ�
    struct Flags2 f2 = { 0, };//����ü �ʱ�ȭ
    f2.a = 4; //4��Ʈ �����̹Ƿ� ���߸� 0000 0100
    f2.b = 2; //���߸� 0000 0010
    f2.c = 80;//���߸� 0101 0000
    f2.d = 15;//0000 1111

    //%u�� ��ȣ���� �������� ���
    printf("%u\n", f2.e); 
    //1111 1010000 10 100 => ��Ʈ������� ��ġ�ϱ� ������ �ش� 2������ 10������ �ٲٸ� 64020��
    


#pragma endregion

    printf("=============����ü end ==========\n");

#pragma region ����ü

    /*
        struct �±� {
            �ڷ��� ����̸�;
        };

        typedef struct �±� {
            �ڷ��� ����̸�;
        } Ÿ���̸�;
    */
    
    //struct Person p1; //����ü��(�±�) �� ����ü �������� => ���������� �����ϸ� ���� ������ �ʿ����
    strcpy(p1.name, "ȫ�浿");//���ڿ� �־���
    p1.age = 30;
    strcpy(p1.address, "����� ������");

    printf("�̸� : %s\n", p1.name);
    printf("���� : %d\n", p1.age);
    printf("�ּ� : %s\n", p1.address);

    
    //����ü ���� ����� ���ÿ� �ʱ�ȭ �ϱ�
    struct Person p2 = { "�迵��",27,"����� ��걸" };

    //��Ī���� ����
    test t1;
    strcpy(t1.name, "�迵��");
    t1.age = 30;
    strcpy(t1.address, "����Ư����");

    printf("�̸� : %s\n", t1.name);
    printf("���� : %d\n", t1.age);
    printf("�ּ� : %s\n", t1.address);


    //typedef

    MYINT numMY; //��Ī���� ���� ����
    PMYINT numPtrMY; //��Ī���� ���� ����

    numPtrMY = &numMY;

    //2�� �����ͷ� ����
    PMYINT* numPtrMY2; //2�������� ��


    User ip;
    strcpy(ip.name, "�迵��");
    ip.age = 27;
    strcpy(ip.address, "��⵵");
    //strcpy(ip.asd, "a"); => ���ڿ��� ������ ��� �ȵ�
    ip.asd = 'a';
    printf("���� : %c\n", ip.asd);
    
    //�����͸� ����ؾ� �ϴ� ����
    /*
        ���� ������ ���� ����� �ƴ϶� ���� ��ȭ��Ű�µ� ����
        �޸� ���డ��
    */


    printf("����ü ���� : %d\n", sizeof(struct Person_test)); //����ü ������ ����ü���� ������ ������ ������ŭ �Ҵ��

    //����ü�� ������ ����
    struct Person_test* pt1 = malloc(sizeof(struct Person_test));

    //ȭ��ǥ �����ڷ� ����ü ��� ���� �Ѵ�. 
    strcpy(pt1->name, "�迵��");
    pt1->age = 26;
    strcpy(pt1->address, "����Ư����");
    //strcpy((*pt1).address, "����Ư����"); ȭ��ǥ ������ ��� .���ε� ǥ�� �����ϴ�.
    //pointer to struct Person_test ���� pointer to �� (*pt1) �� ���ŵǼ� ǥ�� ��������
    
    printf("%s\n", pt1->name);
    printf("%d\n", pt1->age);
    printf("%s\n", pt1->address);

    free(pt1);


    int num100 = 10;
    struct Data dt; //����ü ���� ����
    struct Data* dt2 = malloc(sizeof(struct Data)); //����ü�޸𸮰����� �����ͷ� �ޱ�
    
    dt.numPtr123 = &num100; //int �޸� �ּҰ��� ����ü�� int�� ������ ����
    dt2->numPtr123 = &num100; //����ü�� �����ͺ����� int�� ������ �Ҵ�
    
    printf("����ü ���� �ּ� : %d\n", *dt.numPtr123);//�����Ͱ� �ƴϴ��� �ּҰ��� �Ҵ����ָ� �������� ���� �����ü��ִ�.
    printf("����ü �����ͺ����� int�ּ� �Ҵ簪 : %d\n", *dt2->numPtr123);//�� �߳���

    dt2->c123 = 'a';
    printf("%c\n",(* dt2).c123);
    printf("%d\n", *(*dt2).numPtr123);//������ ����ü���� �����͸� ã�� ������
    printf("%d\n", *dt2->numPtr123);//������ ����ü���� ��������, ����ü�� �����µ� ����ü�� �����͸� �������� ���� �ҷ��´�.

    free(dt2);

    //�����ʹ� �ּҰ��� ���� �ϴ°����� ���������ּҰ��� �Ž��� �ö� ���� ��� ���ִ� ������ �Ѵ�.
    //int *ptr = &abc; ��� ���� ������ int adc�� �ּҸ� ������ �����ͷν� �ּҰ��� ������ ������ 
    //int abd = 10�̶�� ���� ������ �ִٸ�  ������ ptr�� int abc�� �������ؼ� �� 10 �� �ҷ��´�.

    /*
        ��� : *(*dt2).numPtr123)�� dt2 �����ͷ� �������ϰ�, ����ü�� �����ͷ� *���� �������ؼ� �������� ���� �ҷ��´�.
    */

    //����ü �����Ϳ� ����ü ���� �Ҵ�
    struct Person_test pt100;
    struct Person_test* pt200;
    
    pt200 = &pt100; //������ ����ü�� ����ü �Ҵ�
    pt200->age = 30;
    printf("���� : %d\n", pt200->age);
    printf("���� : %d\n", (* pt200).age); //������ �������� ����ü�� ����


    Point3D* p1 = malloc(sizeof(Point3D));
    
    p1->x = 10.0f;
    p1->y = 20.0f;
    p1->z = 30.0f;

    free(p1);

    char asd[10] = "asdasd";


    //���� ������ �Ÿ� ���ϱ�
    struct Point2D p2d1; //����ü 1
    struct Point2D p2d2; //����ü 2
    
    p2d1.x = 30;//����ü 1�� x��
    p2d1.y = 20;//����ü 1�� y��
    
    p2d2.x = 60;//����ü 2�� x��
    p2d2.y = 50;//����ü 2�� y��

    printf("p2d1 : %d %d\n", p2d1.x, p2d1.y);
    printf("p2d2 : %d %d\n", p2d2.x, p2d2.y);

    //��Ÿ��� �̿� c^2 = a^2+d^2
    int numa = p2d2.x - p2d1.x; //x��ǥ�� �Ÿ� ���ϱ�
    int numb = p2d2.y - p2d1.y;// y��ǥ �Ÿ� ���ϱ�

    //������ �Լ� sqrt ��� => 4�� �������� 2, -2 => ������ �������� sqrt(-d) �� ����Ѵ�.
    double numc = sqrt((numa* numa) + (numb*numb));
    //double numc = sqrt(pow(numa,2) + pow(numb,2)); 
    //pow �Լ��� �̿��Ͽ�, ������ �Ҽ��� �ִ�.
    printf("%f\n", numc);

    //������ ���Ҷ� ���
    int negative_number = abs(-10);
    float negative_number2 = fabs(-10.459);
    float negative_number3 = fabsf(-16.364);

    printf("���� : %d\n", negative_number);
    printf("����2 : %.3f\n", negative_number2);
    printf("����3 : %.3f\n", negative_number3);


    //�簢�� ���� ���ϱ� ����1
    struct Rectangle rect;
    int area;

    rect.x1 = 20; //a��
    rect.y1 = 20;//a��
    rect.x2 = 40;//b��
    rect.y2 = 30;//b��
    
    area = abs(rect.x1 - rect.x2) * abs(rect.y1 - rect.y2);
    
    
    //����ü ũ�� 
    struct PacketHeader header;
    printf("%d\n", sizeof(header.flags)); //1����Ʈ ����
    printf("%d\n", sizeof(header.seq));//4����Ʈ ����
    printf("%d\n", sizeof(header));//8����Ʈ ���� => �ֳ��ϸ� ����ü�� ����ū �ڷ����� ũ���� ����� ������
    //5����Ʈ�� ���� 3����Ʈ ������ ä�� �ִµ� , �̰��� �е�(padding)�̶�� �Ѵ�.
    printf("%d\n", sizeof(struct PacketHeader));

    //offsetof : ����� �޸���ġ���ϱ�
    printf("%d\n", offsetof(struct PacketHeader, flags));//�޸� 0����Ʈ��ġ ����
    printf("%d\n", offsetof(struct PacketHeader, seq)); //�޸� 4����Ʈ ��ġ���� ����


    dt.c123 = 'c';
    dt.numPtr123 = 40; //����ü ���� �����Ϳ� int �� �ּҿ� ���� �ο�

    //����ü �޸� 0���� ����
    struct Data data = { 0, };//����ü ������ ���� ��� 0���� �ʱ�ȭ(malloc���� ���Ұ�)
    //memset�� �̿��Ͽ� �޸� 0���� ����
    memset(&data, 0, sizeof(struct Data));
    printf("�޸� �ʱ�ȭ 1 %c %d\n", data.c123, data.numPtr123);
    //����ü ������ �޸� 0���� ����
    struct Data* data2 = malloc(sizeof(struct Data));
    memset(data2, 0, sizeof(struct Data)); //�����͸� ����ü ũ�⸸ŭ 0���� �ʱ�ȭ
    printf("�޸� �ʱ�ȭ 2 %c %d\n", data2->c123, data2->numPtr123);
    free(data2);


    //����ü �޸� Ȱ���ϱ�
    struct Point2D pt2d;
    memset(&pt2d, 0, sizeof(struct Point2D));//����ü�� �����ؼ� ����ü 0(null)���� �ʱ�ȭ ��
                                            //0��Ʈ�� null�� ���� (int���̸� 0�� ���)
    printf("�޸� �ʱ�ȭ : %d %d\n", pt2d.x, pt2d.y);


    //�����͸� ����� �޸� �ʱ�ȭ
    struct Point2D* ppt2d = malloc(sizeof(struct Point2D));
    memset(ppt2d, 0, sizeof(struct Point2D));//������ ����ü�� ������(������ ����ü�� ����) ����ü�� �޸� �ʱ�ȭ
    printf("������ �޸� �ʱ�ȭ : %d %d\n", ppt2d->x, ppt2d->y);//�����Ϳ��� ����ü �����ϴ¹�
    free(ppt2d);


    //����ü�� �޸� �����ϱ�
    struct Point2D pt101;
    struct Point2D pt102;
    pt101.x = 10;
    pt101.y = 10;
    //������ , ���� , �޸�ũ��
    memcpy(&pt102, &pt101, sizeof(struct Point2D));

    printf("���� : %d %d \n", pt102.x, pt102.y);

    //�����ͷ� �޸� �����ϱ�
    struct Point2D * pt103 = malloc(sizeof(struct Point2D));
    struct Point2D * pt104 = malloc(sizeof(struct Point2D));
    
    pt103->x = 10;
    pt103->y = 20;
    //������ , ���� , �޸�ũ��
    memcpy(pt104, pt103, sizeof(struct Point2D));
    printf("������ ���� : %d %d\n", pt104->x, pt104->y);
    free(pt103);
    free(pt104);


    //����ü �迭 ����ϱ�
    struct Point2D pt105[3];//����ü�� �迭 �ٿ� ���
    pt105[0].x = 10;
    pt105[0].y = 20;
    pt105[1].x = 30;
    pt105[1].y = 40;
    pt105[2].x = 50;
    pt105[2].y = 60;
    
    printf("����ü �迭0 : %d %d\n", pt105[0].x, pt105[0].y);
    printf("����ü �迭1 : %d %d\n", pt105[1].x, pt105[1].y);
    printf("����ü �迭2 : %d %d\n", pt105[2].x, pt105[2].y);

    //����ü �迭 �ʱ�ȭ
    //����ü �迭�� ���� �ϸ鼭 �ʱ�ȭ1
    struct Point2D pt106[3] = { {.x = 10,.y = 20}, {.x = 30,.y = 40},{.x = 50,.y = 60} };//�ε��� ���� ���
    
    printf("����ü �迭 �ʱ�ȭ 0 : %d %d\n", pt106[0].x, pt106[0].y);
    printf("����ü �迭1 : %d %d\n", pt106[1].x, pt106[1].y);
    printf("����ü �迭2 : %d %d\n", pt106[2].x, pt106[2].y);

    //// ����ü �迭�� �����ϸ鼭 �ʱ�ȭ2
    struct Point2D pt107[3] = {{10,20},{30,40},{50,60}};
    printf("����ü �迭 �ʱ�ȭ 2 0 : %d %d\n", pt107[0].x, pt107[0].y);
    printf("����ü �迭1 : %d %d\n", pt107[1].x, pt107[1].y);
    printf("����ü �迭2 : %d %d\n", pt107[2].x, pt107[2].y);

    //// ����ü �迭�� �����ϸ鼭 0���� �ʱ�ȭ
    struct Point2D pt108[3] = { 0, }; 

    
    // ������ ����ü �迭 �����ϱ�
    struct Point2D* pt109[3]; //������ ����ü �迭
    // ������ �迭 ������ / ������ => �迭 ũ�� ����
    for (int i = 0; i < sizeof(pt109)/sizeof(struct Point2D *); i++) {
        pt109[i] = malloc(sizeof(struct Point2D)); //������ ����ü �迭�� ����ü ����
    }


    pt109[0]->x = 10;
    pt109[0]->y = 20;
    pt109[1]->x = 30;
    pt109[1]->y = 40;
    pt109[2]->x = 50;
    pt109[2]->y = 60;

    printf("======================\n");
    printf("������ ����ü �迭 0: %d %d\n", pt109[0]->x, pt109[0]->y);
    printf("������ ����ü �迭 1: %d %d\n", pt109[1]->x, pt109[1]->y);
    printf("������ ����ü �迭 2: %d %d\n", pt109[2]->x, pt109[2]->y);


    for (int i = 0; i < sizeof(pt108)/sizeof(struct Point2D*); i++) {
        free(pt109[i]);
    }
    
    struct Person2* p100[5];
    int index = 0;
    for (int i = 0; i < sizeof(p100) / sizeof(struct Person*); i++) {
        p100[i] = malloc(sizeof(struct Person));
    }

    strcpy(p100[0]->name, "�迵��");
    p100[0]->age = 20;

    char strn[30] = "";
    int stri = 0;
    int stri2 = 0;
    //scanf("%s %d\n", &p100[0]->name, &p100[0]->age); //�ּҸ� �ٿ�����(������ ������ �����ؼ� ȭ��ǥ �����ڷ� ����ü�������Ѵ�)

    printf("���� 1 : %d\n", sizeof(p100) / sizeof(struct Person*));
    

    for (int i = 0; i < sizeof(p100) / sizeof(struct Person*); i++) {
        scanf("%s %d", &p100[i]->name, &p100[i]->age); //scanf���� �ٹٲ��� ������ �ȵ�(������)
    }

    
    for (int i = 1; i < sizeof(p100) / sizeof(struct Person*); i++) {
        if (p100[i - 1]->age < p100[i]->age) {
            index = i;
        }
    }
    printf("%s\n", p100[index]->name);
    

#pragma endregion

    printf("========== ����ü end ===========\n");

#pragma region �����Ϳ͹��ڿ� 

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

    num125 = strtol(s125, &end125,16); //16 ������ ��� 
    num126 = strtol(end125, &end125,10); //10������ ��� 
    num127 = strtof(end125, NULL); //�Ǽ������� ���
    printf("0x%x\n", num125);
    printf("%d\n", num126);
    printf("%f\n", num127);
    
    //����,�Ǽ��� ���ڿ��� ��ȯ
    char s128[10];
    char s129[10];
    int num128;
    float num129;

    scanf("%d %f", &num128, &num129); //�����Ͱ� �ƴ� ������ �������� �ּҷ� �־���

    sprintf(s128, "%d", num128);
    sprintf(s129, "%f", num129);

    printf("%s\n", s128);
    printf("%s\n", s129);

    //ȸ�� �Ǻ��� n-gram �����
    char word1[30];
    int length1;
    bool isPalindrome1 = true;

    printf("�ܾ �Է��ϼ���. :");
    scanf("%s", word1);
    
    length1 = strlen(word1);
    for (int i = 0; i < length1/2; i++) {
        if (word1[i] != word1[length1-1-i]) {//���� �� �������� ���� ������
            isPalindrome1 = false;
            break; //ȸ���� �ƴϹǷ� ����
        }
    }
    printf("%d\n", isPalindrome1);



#pragma endregion

    return 0;
}