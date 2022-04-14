#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {

#pragma region ������

    cout << "========== ������ ���� =========" << endl;

    //������ ���� ����
    /*
        �ڷ��� *�������̸�; -> �� ��������
        ������ = &����; -> �޸� �ּ� ��������
    */
    int* numPtr; //�޸� �ּ� �������� => ������ ���� ����
    int exnum5 = 10;

    numPtr = &exnum5; //exnum5�Ǹ޸� �ּҸ� ������ ������ ����

    cout << numPtr << endl;
    cout << *numPtr << endl;

    cout << sizeof(numPtr) << endl; //64��Ʈ �ü�� ������ 8����Ʈ�� ���´�. 32��Ʈ �ü���� 4����Ʈ

    *numPtr = 2; //�����ͷ� ����� �ּҰ��� ���� ����

    cout << exnum5 << endl; //2�� �ٲ���� ��������


    //!!!!!!���� !!!!!!!
    //������ ���� ������� �ݵ�� �ʱ�ȭ ���� ����� 
    //-> ���� ������ �־ ���� �߻��Ҽ����� -> ���α׷� ���ϼ� ����
    *numPtr = NULL;

    int a = 10, b = 10, temp;
    int* x, * y;
    x = &a; //�����ͷ� ����� -> ���� �ٲ�
    y = &b;
    cout << "a : b => " << a << " : " << b << endl;

    temp = *x; //������ ������ ���� ������ temp = 10
    *x = *y;  //�������� ������ ������ ����Ʈ �������� �Ҵ��� *x= 10
    *y = temp; // temp�� ���� �������� y����Ʈ ������ �Ҵ��� *y = 10 -> y�� temp�� �������� �����

    *y = 15;

    cout << "a : b => " << a << " : " << b << endl; // 10 15�� ����

    //��������� ������ ���� �� Ȯ���ϱ�
    int* numPtr10;
    int exnum10 = 10;

    numPtr10 = &exnum10; //�����ͷ� ����
    *numPtr10 = 20; //�������� �� �Ҵ� -> exnum10 �� ���� �ٲ�
    cout << *numPtr10 << endl;
    cout << exnum10 << endl;


    //void pointer �����ϱ�
    int num1v = 10;
    char c1v = 'a';
    int* numPtr1v = &num1v; //�޸� �ּ� �Ҵ� -> �����ͷ� ����
    char* cPtr1v = &c1v;

    void* ptrv; //void ������ ���� ���� 

    //�����ʹ� �ڷ��� �޶� ������ ��� ����
    ptrv = numPtr1v; //void �����Ϳ� int ������ ����
    //cout << *ptrv << endl; -> void �����ʹ� ������ �Ҽ����� 
    // -> �� ���� �ϱ� ���� void �����͸� ����ȯ ���ָ�ȴ�.


    numPtr1v = (int*)ptrv;
    //����ȯ�� �����ָ� void �����͵� ������ �Ҽ��ִ�.
    //void �����͸� int�� �����Ϳ� ����


    //���� ������ ����ϱ�
    //�������� �޸� �ּҸ� �����ϴ� �������� ������
    int* numPtr1a; //���� ������
    int** numPtr2a; //���� ������ => �������� �����͸� �����Ҽ� �ִ�.
    int num1a = 10;

    numPtr1a = &num1a;//int ������ �޸� �ּ� ���������Ϳ� ����
    numPtr2a = &numPtr1a; //���� �������� �޸� �ּҸ� 2�� �����Ϳ� ����

    // numPtr2a ->numPtr1a ->num1a ����� (java�� super�� ����)
    cout << **numPtr2a << endl; //�������� ���� �����

    //��������
    int* numPtrb;
    int num1b = 10;
    int num2b = 20;
    
    numPtrb = &num1b;
    cout << *numPtrb << endl;

    numPtrb = &num2b;
    cout << *numPtrb << endl;

    //��������
    int* numPtr1c;
    int** numPtr2c;
    int num1c;
    
    cin >> num1c;

    numPtr1c = &num1c;
    numPtr2c = &numPtr1c;

    printf("%d\n", **numPtr2c);
    
    //�޸� ����ϱ�
    int num1d = 20;
    int* numPtr1d;

    numPtr1d = &num1d;

    int* numPtr2d;

    numPtr2d = (int*)malloc(sizeof(int)); 
    //int �� �����Ϳ� int Ÿ���� 4����Ʈ �޸� ������ ������ش�
    //c++������ void �Լ��� ��� ����ȯ�� ������Ѵ�.

    printf("%p\n", numPtr1d);//num1d�� �޸� �ּ� ���
    printf("%p\n", numPtr2d);//malloc�� ���� ������� heap �޸� �ּ� ���
    
    free(numPtr2d);//���� �Ҵ� �޸� ���� (heap�Ҵ� �޸𸮴� �ݵ�� ���� �������)
    //�޸𸮸� ���� ���� �ʾƼ� �޸𸮰� �׿� �ý����� ������ ���� �߻��Ҽ� ����
    //buffer �޸𸮸� clean �ϴ� �Ͱ� ����� 


#pragma endregion

#pragma region ����

    cout << "=============���� ================" << endl;

    float testFloat = 5.3f;
    float testFloat2 = 5.3; //������ ������ double�� �ٲ��
    char testCharacter = 'a';
    std::cout << "Hello World!\n";
    std::string testString = "Hello"; //string �� Ŭ���� �̹Ƿ� �տ� std�� ���δ�.
    //std::cin >> input_key;


    float num1 = 1.0f;
    float num2 = 0.0f;
    float num3;

    num3 = num1 / num2;
    printf("%f\n", num3); //����� : inf // inf �� ���Ѵ��� �ǹ���

    //�Ǽ��� ������ ������ fmod, fmodf, fmodl �Լ����
    double num4 = 10.843;
    double num5 = 4.95;
    printf("%f\n", fmod(num4, num5)); //fmod�� double ������ �������� ��� 0.943000

    float num6 = 9.85f;
    float num7 = 3.15f;
    printf("%f\n", fmodf(num6, num7)); //fmodf�� float ������ ������ �� ��� 0.400000

    //long double �� 16 ����Ʈ�� �� �뷮���� ����
    long double num8 = 10.795;
    long double num9 = 2.795;
    printf("%Lf\n", fmodl(num8, num9)); //fmodl �� long double ������ ������ �� ��� 2.410000

    //������ ������ �� ���ϱ�
    printf("%d\n", -5 % -3); // -5�� -3���� ���� ������ ���� -2�̴�
    printf("%d\n", -5 % 3); // -5�� 3���� ���� ������ ���� -2�̴�
    printf("%d\n", 5 % -3); // 5�� -3���� ���� ������ ���� 2�̴�

    //������ �Ǽ��� ������
    int num10 = 11;
    float num11 = 4.4f;

    printf("%f\n", num10 + num11); //���� 11�� �Ǽ������� ��ȯ�� (ǥ�� ���� ���� ������ �ڵ� ��ȯ��)

    //�Ǽ��� ������ ǥ���ϱ� : ����ȯ�� �� �ս��� �߻� (������ ���������� ��ȯ �ϴ� ���̹Ƿ�)
    float num12 = 11.0f;
    float num13 = 5.0f;

    int num14 = num12 / num13;// ���� ���� ������ ����ȯ
    printf("%d\n", num14); //���� 2 ��µ�

    char num15 = 28;
    int num16 = 10000000008; //int�� char�� �������� char���·� ��ҵǴµ�, ��ҵɶ� ���ڸ����� �����ǰ� 
    //8�� ���� int�� �����ϰԵ�
    char num17 = num15 + num16;
    printf("%d\n", num17);//36

    //���÷��� ����
    int token[6] = { 7,7,7,7,7,5 }; //���޶���, ���̾Ƹ��,�����̾�, �ٺ��, ���, Ȳ��
    int del_card = 90; //���� ī�� ��
    int royal_card = 10; // ���� ī�� ��


    cout << "���޶��� �� : " << token[0] << endl;


    //if ���ǹ� => if�� ���ڿ� 0�� ������ false, 0�� �ƴϸ� true�� ��ȯ 
    int num18 = 10;
    if (num18 == 10) {
        printf("10�Դϴ�\n");
    }

    if (num18 == 12) {
        cout << "12" << endl;
    }
    else if (num18 == 10) {
        cout << "10" << endl;
    }
    else {
        cout << "out" << endl;

    }

    // �� ������
    int num19 = 10;
    int num20 = 20;


    if (num19 == 10 && num20 == 20) {
        printf("��\n");
    }

    //����ī�� ���� ����

    int balance = 10000;
    int age;
    cout << "���� �Է� : " << endl;
    //cin >> age;

    cin >> age;

    //����
    if (age >= 19) {
        balance -= 1200;
    } //û�ҳ�
    else if (age >= 13 && age <= 18) {
        balance -= 720;
    } //���
    else if (age >= 7 && age <= 12) {
        balance -= 450;

    }

    cout << "����: " << balance;

    //����Ʈ �������� 2�� �ŵ����� �˾ƺ���
    unsigned char num21 = 1; // 1 : 0000 0001
    printf("%u\n", num21 << 1); //  2 : 0000 0010 : 2
    printf("%u\n", num21 << 2); //  4 : 0000 0100 : 2^2
    printf("%u\n", num21 << 3); //  8 : 0000 1000 : 2^3
    printf("%u\n", num21 << 4); //  16 : 0001 0000 : 2^4
    printf("%u\n", num21 << 5); //  32 : 0010 0000 : 2^5
    printf("%u\n", num21 << 6); //  64 : 0100 0000 : 2^6
    printf("%u\n", num21 << 7); //  128 : 1000 0000 : 2^7

    //�� ������ �켱���� : ! , && , || ��
    bool b1;
    b1 = (false || true) && !false || false;
    printf("%d\n", b1); //true ��µ� 1

    //�񱳿����� �켱���� : < , == ��
    int num22 = 5;
    num22 = 5 == 5 < 10;
    //5<10 �񱳷� true 1�� ����, 5��1�� �� false�� 0, num22�� 0�� ���� 
    printf("%d\n", num22);

    //����Ʈ �����ڿ� ��������� �켱����
    int num23 = 1;
    int num24 = 2;
    int num25;

    cout << "========================" << endl;
    num25 = num23 << 2 + num24 << 1;// (+) �����ڰ� �켱�� ��
    printf("%d\n", num25);

    int num26;
    cout << "��ȣ �Է� : ";
    cin >> num26;
    switch (num26) {
    case 1: cout << "1�Դϴ� \n" << endl; break;
    case 2: cout << "2�Դϴ� \n" << endl; break;
    case 3: cout << "3�Դϴ� \n" << endl; break;
    case 4: cout << "4�Դϴ� \n" << endl; break;
    default: cout << "�⺻" << endl; break;
    }

    //���� ���� �����
    for (int i = 25; i > 0; i--) {
        printf("hello %d\n", i);
    }

    int num27;
    //for�� �ȿ��� �Է� �Լ��� �����ϰ� ����Ҽ� ���� 
    for (cin >> num27; num27 > 0; num27--) {
        cout << num27 << endl;
    }

    //for�� �ȿ� 2���� ������ ����ϱ�
    for (int i = 0, j = 0; i < 10 && j < 10; i++, j += 2) {
        cout << " i : " << i << " j : " << j << endl;
    }

    cout << "while �ݺ���" << endl;
    int num30 = 0;
    while (true) { //���ǹ��� ���� �ʰ� true�� ������ ���� �ݺ���
        if (num30 > 10) {
            break;
        }
        cout << num30 << endl;
        num30++;
    }

    //���� 1 �ݺ���
    //�Է� : ����
    //ó�� : 
    for (int i = 2, j = 5; j > 0; i *= 2, j--) {
        cout << " i : " << i << " j : " << j << endl;
    }

    //��� : 
    /*
    *       2 5
            4 4
            8 3
            16 2
            32 1
    */

    // ���� ���� while������ ǥ��
    srand(time(NULL));


    int num31 = 0;
    while (true) { //true ��� 1�� ��밡��
        num31 = rand() % 10;
        if (num31 >= 3 && num31 <= 7) {
            cout << "while���� ���� ���� 3~7 : " << num31 << endl;
            break;
        }
    }

    int num32 = 0;
    //do ~ while ���� do���� �����ϰ� while ���ǿ� ������ �ٽ� do���� ����ȴ�.
    do {
        cout << "dowhlie" << endl;
    } while (num32 != 0);

    do {} while (0); //do�� �ѹ��� �����

    //continue
    for (int i = 1; i <= 25; i++) {
        if (i % 2 != 0) continue;

        //continue�� ����ϸ� ���� �κ��� �������� �ʰ� ���� for������ �Ѿ
        cout << i << endl; //¦���� �ƴҶ� �Ѿ���� ������ -> Ȧ���� ��¾���
    }

    //�Է��� ���ڱ��� ¦�� ���ϱ�
    int count;
    cin >> count;

    cout << "�Է��� ���ڱ��� �ݺ��� ==========" << endl;
    //�Է��� ���ڰ��� �ݺ���
    for (int i = 0; i < count; i++)
    {
        if (i % 2 == 0) {//¦���� ����ϴ� ����
            cout << i << endl;
        }

        //��ȣ�� ���ų� continue�� ����� ��Ÿ���� �ִ�.
        if (i % 2 != 0) continue; cout << i << endl;
    }

    //���� ����1
    //�Է� : 
    int exnum1 = 0; //����1
    int exnum2 = 0; // ����2
    int exnum3 = 0;



    cout << "�ι��� ����" << endl;
    cin >> exnum2;

    exnum3 = exnum1;

    //ó�� : 
    //�������� 7�� �ƴ� ���ڵ鸸 ��µǰ� ����
    //ù��° ������ 1 ~200���̰�
    // �ι�° ������ 10 ~ 200 ���̰�
    // �ι�° ���� > ù��° ���� (�׻�)

    //���� �ݺ���
    do {
        cout << "ù���� ����" << endl;
        cin >> exnum1;
    } while (!(exnum1 >= 1 && exnum1 <= 200));
    do {
        cout << "�ι��� ����" << endl;
        cin >> exnum2;
    } while (!(exnum2 >= 10 && exnum2 <= 200));

    while (1) {
        exnum3++;

        //exnum3 �� exnum2���� Ŀ���� break;
        if (exnum3 >= exnum2) {
            break;
        }
        if (exnum3 % 10 == 7) {
            continue; //7�� ������ �ؿ��ִ°� �������� �ʰ� ���� ������ �Ѿ
        }

        cout << exnum3 << endl;
    }


    //�� Ʈ�� ����� 
    cout << "========= �� ����� ===================";
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i >= j) cout << "*";
        }
        cout << endl;
    }

    cout << "========== ���̺� =============== �Ѿ���� 5" << endl;
    /*
        goto ��� => �ڹ��� level ���� ��� => ���� ���̺�� �̵�
        => �������� ���� ���ö� ��밡��
    */

//    int exnum4;
//
//    cin >> exnum4;
//
//    if (exnum4 == 1) {
//        goto ONE;
//    }
//    else if (exnum4 == 2) {
//        goto TWO;
//    }
//    else {
//        goto EXIT;
//    }
//
//ONE:
//    cout << "1�Դϴ�\n";
//    goto EXIT;//�����ٴ� ���� ��������
//TWO:
//    cout << "2�Դϴ�\n";
//    goto EXIT;
//EXIT: return 0; //main()�Լ��� ���� �����鼭 ���� 0�� ��ȯ �Ѵٴ� ��

    //return �� ������ main �Լ� ���߹Ƿ� �� �����Ұ�







    



#pragma endregion

}//end main