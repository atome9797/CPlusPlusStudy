#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {

#pragma region ������2



    //�����ʹ� Ÿ�� ������� 8����Ʈ�̹Ƿ� , ���ڿ� ������ �ִ�.
    char* s1z = (char*)"Hello"; // ���� NULL ��  , ���ڿ� �ּҰ� ���°��� ���� ���°� �ƴ�
    cout << s1z << endl; //���ڿ� �ּҸ� �ҷ��� ���� ������ 

    int* c1 = (int*)10;// �ּҸ� �Ҵ��ϴ°� �ƴ� ���� �Ҵ��ϰԵ�
    cout << c1 << endl;
    

    int c2 = 10;
    int* c3 = &c2;
    cout << *c3 << endl;
    

    //���ڿ� �����Ϳ��� �ε��� �� ����
    char* s1y = (char*)"Hello";
    cout << s1y << endl;
    cout << s1y[5] << endl; //5�� �ε��� ������ ����Ƿ� ���ڿ� �ǵ��� NULL �� ���

    //���� �Ҵ� �ȵ� => �б����� �̱� ������ ���࿡��(������) ������
    //s1y[0] = 's';


    //�迭
    char s10[10] = "Hello"; //�迭 �Ҵ��ϰ� ������ �޸𸮰����� null������ ä����
    cout << s10 << endl;
    s10[0] = 'S';
    cout << s10 << endl;//�迭 ũ�Ⱑ �������� �б� ������ �ƴϰԵ�

    char s11[] = "Hello";//�ε������� �ο����� �ʰ�


    //���ڿ� ����� (�迭 �Ǵ� �����ͷ� ���ڿ� ������ ����) => �����ʹ� �б� ����, �迭�� �ε��� �� ��밡��

    char *s1d = (char*)"Beethoven\n9th\nSymphony";
    cout << s1d << endl;

    //5�� �������� 4
    char s2d[5];
    cin >> s2d;
    cout << s2d << endl;




#pragma endregion

#pragma region ����ã��
    //���� ã�� �˰��� ����
    int m5 = 0;
    int n5 = 0;
    cout << "�� ũ�� : ";
    cin >> m5;
    cout << "�� ũ�� : ";
    cin >> n5;

    cout << "�� ���� : ";
    //�迭 ũ�⸦ ����ڰ� �������� + ���� �迭�� ������� �ϴµ� �԰�������
    char** matrix5 = (char**)malloc(sizeof(char*) * m5);//����
    for (int i = 0; i < m5; i++) {
        matrix5[i] = (char*)malloc(sizeof(char) * n5);//����
    }
    //���� int[][]�迭�� ����� �����ߴµ� �Է°� ������ �ְԵ�
    int** matrix6 = (int**)malloc(sizeof(int*) * m5);//����
    for (int i = 0; i < m5; i++) {
        matrix6[i] = (int*)malloc(sizeof(int) * n5);//����
    }

    //�Է°�
    for (int i = 0; i < m5; i++) {
        for (int j = 0; j < n5; j++) {
            cin >> matrix5[i][j];
            if (matrix5[i][j] == '.') {
                matrix6[i][j] = 0;
            }
        }
        cout << endl;
    }

    for (int k = 0; k < m5; k++) {
        for (int p = 0; p < n5; p++) {

            //3x3�迭�� �� ��
            if (matrix5[k][p] != '*') {
                for (int i = k - 1; i <= k + 1; i++) {
                    for (int j = p - 1; j <= p + 1; j++) {
                        if (i >= 0 && i < m5 && j >= 0 && j < n5) {
                            if (matrix5[i][j] == '*') {
                                matrix6[k][p] += 1;
                            }
                        }
                    }
                }
            }

        }
    }

    //.�� ���� ���ڷ� ����
    //for (int i = 0; i < m5; i++) {
    //    for (int j = 0; j < n5; j++) {
    // 
    //        if (matrix5[i][j] != '*') {//���� �ƴ� .�϶� ����
    //            
    //            //���� ���� �ȿ� ��� �� �ְ� , ���� ��ĭ �����ϼ� �������, ����ĭ�� *�� ������
    //            if (i > 0 && i <= m5-1 && matrix5[i-1][j] == '*') {
    //                matrix6[i][j] += 1;
    //            }
    //            if (i >= 0 && i <= m5 - 2 && matrix5[i + 1][j] == '*') {//���� ���� �ȿ� ��� �� �ְ� , �Ʒ��� ��ĭ �����ϼ� �������, �Ʒ�ĭ�� *�� ������
    //                matrix6[i][j] += 1;
    //            }
    //            if (j >= 0 && j <= m5 - 2 && matrix5[i][j+1] == '*') {//���� ���� �ȿ� ��� �� �ְ� , �����ʷ� ��ĭ �����ϼ� �������, ������ĭ�� *�� ������
    //                matrix6[i][j] += 1;
    //            }
    //            if (j > 0 && j <= m5 - 1 && matrix5[i][j- 1] == '*') {//���� ���� �ȿ� ��� �� �ְ� , ���ʷ� ��ĭ �����ϼ� �������, ����ĭ�� *�� ������
    //                matrix6[i][j] += 1;
    //            }

    //            if (j >= 0 && j <= m5 - 2 && i > 0 && i <= m5 - 1 && matrix5[i - 1][j + 1] == '*') {//���� �밢�� ���� �ȿ� ��� �� �ְ� , ���밢������ ��ĭ �����ϼ� �������, �� �밢���� *�� ������
    //                matrix6[i][j] += 1;
    //            }
    //            if (j >= 0 && j <= m5 - 2 && j >= 0 && j <= m5 - 2 && matrix5[i + 1][j + 1] == '*') {//���� �밢�� ���� �ȿ� ��� �� �ְ� , ���밢������ ��ĭ �����ϼ� �������, �� �밢���� *�� ������
    //                matrix6[i][j] += 1;
    //            }
    //            if (j > 0 && j <= m5 - 1 && i >= 0 && i <= m5 - 2 && matrix5[i + 1][j - 1] == '*') {//�޾� �밢�� ���� �ȿ� ��� �� �ְ� , ���밢������ ��ĭ �����ϼ� �������, �� �밢���� *�� ������
    //                matrix6[i][j] += 1;
    //            }
    //            if (j > 0 && j <= m5 - 1 && i > 0 && i <= m5 - 1 && matrix5[i - 1][j - 1] == '*') {//�� �밢�� ���� �ȿ� ��� �� �ְ� , ���밢������ ��ĭ �����ϼ� �������, �� �밢���� *�� ������
    //                matrix6[i][j] += 1;
    //            }
    //        }
    //    }
    //}


    //�� ���
    for (int i = 0; i < m5; i++) {
        for (int j = 0; j < n5; j++) {

            if (matrix5[i][j] == '*') {
                cout << matrix5[i][j];
            }
            else {
                cout << matrix6[i][j];
            }
        }
        cout << endl;
    }

    for (int i = 0; i < n5; i++) {
        free(matrix6[i]);
    }

    //���� �޸� �ʱ�ȭ
    free(matrix6);

    //���� �޸� �ʱ�ȭ
    for (int i = 0; i < n5; i++) {
        free(matrix5[i]);
    }

    //���� �޸� �ʱ�ȭ
    free(matrix5);

#pragma endregion

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


    //�޸𸮿� �� �����ϱ�
    int *numPtr1e;
    numPtr1e = (int*)malloc(sizeof(int));
    
    // malloc �Լ��� �޸�ũ�� �Ҵ����ְ� �Ҵ� ���� �޸𸮿� 10�̶�� ������ ���������ν� �������Ѵ�
    *numPtr1e = 10; 

    cout << *numPtr1e << endl;
    
    free(numPtr1e); //heap ���� ������ �ӽ� �޸� ������ ���� �������


    //�޸� ������ �Ѳ����� �����ϱ� memset
    char numf[20];

    
    cout << "�޸� ������(����Ʈ ��) : " << sizeof(numf) << endl;

    //=> sizeof(numf) ���� numf[20] �� char�� 1����Ʈ �޸� ������ 20�� ����� �Ͱ� ����
    memset(numf, 65, sizeof(numf));  // 65��� ���ڴ� char������ ǥ���ϸ� A�̹Ƿ� A�� 20���� �迭�� ���� �����Ŵ

    //sizeof(numf)/sizeof(char)  �� 20/1 �̹Ƿ� 20�� ���´� => 20�� �����ϴ°Ͱ� ����
    for (int i = 0; i < (sizeof(numf)/sizeof(char)); i++) {
        cout << numf[i] << endl;
    }
    

    //memset 
    long long* numPtrg = (long long *)malloc(sizeof(long long)); //8����Ʈ�� �޸� ������ �������
    memset(numPtrg, 0, 8); // ������ ������ 0 ���� 8����Ʈ������ �ְڴٴ� �ǹ� => �ʱ�ȭ ��ų�� 0 �־ ���

    cout << *numPtrg << endl;

    free(numPtrg);
    
    int* numPtrh = (int*)malloc(sizeof(int));
    memset(numPtrh, 1, sizeof(int)); //(int�� �̹Ƿ� 4����Ʈ)1����Ʈ ���� 01�� ä���� =>  16������ 0x01010101 = 16843009

    cout << *numPtrh << endl;

    free(numPtrh);

    //memset �Լ� �ʱ�ȭ 

    long long* numPtri = (long long*)malloc(sizeof(long long));
    memset(numPtri, 0, sizeof(long long)); //0�� �������ν� �޸� ���� �ʱ�ȭ ��Ų��.
    free(numPtri);


    //null �� �޸� �Ҵ����� �ʴ� ������ ���� �����
    int *numPtrj = NULL;
    cout << "null :" << numPtrj << endl; //00000000

    if (numPtrj == NULL) {
        numPtrj = (int *)malloc(1024); //1024 ����Ʈ��ŭ�� �޸� ���� �ο�
    }


    //�迭�� �����Ϳ� �ֱ�
    cout << "========= �迭 ������ ==========" << endl;
    //�迭�� ��� ù ��° ����� �ּڰ��� ��� �ִ�. => �ּڰ��̶� �����Ϳ� ������ ����
    int numArrl[10] = { 11,22,33,44,55,66,77,88,99,110 };
    int* numPtrl = numArrl; //�����Ϳ� �迭 �ּ� �Ҵ� 
    cout << *numPtrl << endl; // 11
    cout << *numArrl << endl; //�迭�� �������ص� �����Ϳ� �Ȱ��� 11�� ����
    
    cout << numPtrl[5] << endl; // �ּҴ� �ϳ����� �ε����� �޸𸮿� ���� ����
    
    // �޸��ּҰ� 32��Ʈ ��ǻ�ʹ� 4����Ʈ ���� , 64��Ʈ ��ǻ�ʹ� 8����Ʈ ���� �̴�
    // ������ ������ �ּҰ��� �����Ƿ� , int , char , double ������� (32��Ʈ ��ǻ��) 4����Ʈ �Ǵ�
    // (64��Ʈ ��ǻ��) 8����Ʈ�� �ش�ȴ�.
    cout << sizeof(numArrl) << endl; //4*10 ����Ʈ �޸� ���� : 40
    cout << sizeof(numPtrl) << endl; 
    //�迭�� �ּҰ��� ����Ʈ�� ǥ�� : 8 (int,char,double ������� �ּҰ� 8����Ʈ�� �޴´�)

    //�迭�� �̿��� 10������ 2������ �����
    //�Է� : 
    int input_user1 = 13; //������ �Է��� ���� -> �̰��� 2������ �ٲپ����
    int binary[10] = { 0, };//������ �迭���� �����
    int cnt = 0; //binary �迭�� �ε���

    //ó�� : ���� �ݺ��� ��� , �����⸦ �Ҽ� ���������� �ݺ�
    while (true) {

        binary[cnt] = input_user1 % 2; //�������� ��
        input_user1 = input_user1 / 2; //���� ���� ���� ���ʷ� �ѱ�

        cnt++; //binary �迭�� �ε����� ���
        if (input_user1 == 0) {
            break;
        }
    }

    //cnt �� �ε����� ��������Ƿ� ��Ȱ��
    for (int i =  cnt-1 ; i >= 0; i--){
        cout << "binary�� : "<< i << " : " << binary[i] << endl;
    }

    float scores1[10] = { 67.2f, 84.3f, 97.0f, 87.1f, 71.9f, 63.0f, 90.1f, 88.0f, 79.7f, 95.3f };
    float sum1 = 0.0f;
    float average1;

    for (int i = 0; i < sizeof(scores1) / sizeof(float); i++) { //�迭 ���� ���
        sum1 += scores1[i];
    }

    average1 = sum1 / (sizeof(scores1) / sizeof(float));


    cout << average1 << endl;

    //2������ 10������ ��ȯ
    //int decimal10 = 0;//�����
    //int binary10[4] = { 1, 1, 0, 1 };    // 1101 ������� �����

    //for (int i = 0; i < sizeof(binary10)/sizeof(int); i++) { //4�� �ݺ�
    //    decimal10 = 2 * decimal10 + binary10[i];
    //}

    //cout << decimal10 << endl;

    int decimal10 = 0;//�����
    int binary10[4] = { 1, 1, 0, 1 };    // 1101 ������� �����
    int position = 0;
    for (int i = sizeof(binary10) / sizeof(int) - 1; i >= 0; i--)
    {
        if (binary10[i] == 1)
            decimal10 += 1 << position;

        position++;
    }

    cout << decimal10 << endl;

    //���� ���� ������
    int numArrg[5];
    int smallestNumber;

    cin >> numArrg[0] >> numArrg[1] >> numArrg[2] >> numArrg[3] >> numArrg[4];

    smallestNumber = numArrg[0];

    for (int i = 0; i < sizeof(numArrg)/sizeof(int); i++) {
        if (smallestNumber > numArrg[i]) {
            smallestNumber = numArrg[i];
        }
    }

    cout << "���� ���� �� :  " << smallestNumber << endl;
    

    //2���� �迭�� ������ �ֱ�
    
    int(*numPtrm)[4]; //int �� �����͸� 4�� ������ �ִ�. 
    //=> 1���� �迭�� �ּҰ� 1�� �̹Ƿ� �����Ϳ� ������ ����

    int numArro[3][4] = { {11,22,33,44},{55,66,77,88},{99,110,121,132} };
    int(*numPtro)[4] = numArro; // 1���� �迭�� ������ 2�����迭�� 4���� ������ ���� �� ����

    cout << *numPtro[0] << endl;
    cout << *numArro[0] << endl; //�迭 ù ������

    //3���� �迭�� ������ �ֱ�
    int numArrp[2][3][4] = {
    {
        { 11, 22, 33, 44 },
        { 55, 66, 77, 88 },
        { 99, 110, 121, 132 }
    },
    {
        { 111, 122, 133, 144 },
        { 155, 166, 177, 188 },
        { 199, 1110, 1121, 1132 }
    }
    };

    int(*numPtrp)[3][4] = numArrp;

    //�� �밢�� ���� ���ϱ�
    int matrix[8][8] = {
        {  1,  2,  3,  4,  5,  6,  7,  8 },
        {  9, 10, 11, 12, 13, 14, 15, 16 },
        { 17, 18, 19, 20, 21, 22, 23, 24 },
        { 25, 26, 27, 28, 29, 30, 31, 32 },
        { 33, 34, 35, 36, 37, 38, 39, 40 },
        { 41, 42, 43, 44, 45, 46, 47, 48 },
        { 49, 50, 51, 52, 53, 54, 55, 56 },
        { 57, 58, 59, 60, 61, 62, 63, 64 }
    };
    
    cout << "�� �밢 " << endl;
    for (int i = 0; i < sizeof(matrix) / sizeof(matrix[0]); i++) {//8 x
        for (int j = 0; j < sizeof(matrix[0]) / sizeof(int); j++){ //8 y
            if (j == i) {
                cout << matrix[i][j] << " ";
            }
        }
    }
    cout << endl;
    

    //�����͸� �迭 ó�� ���
    int* numPtrq = (int*)malloc(sizeof(int) * 10); //int�� �޸𸮰����� 10�� ����
    numPtrq[0] = 10;
    numPtrq[9] = 20;

    cout << numPtrq << endl; // malloc �Լ��� ��������� 0000023A51D7EBC0 �޸� �ּ� ��������
    cout << numPtrq[0] << endl;
    cout << numPtrq[9] << endl;

    free(numPtrq);

    //�������� �޸𸮸� 2���� �迭 ó�� ���

    int** m = (int**)malloc(sizeof(int*) * 3); //���������ͷ� int�� ������ 3�� ���� ����

    for (int i = 0; i < 3; i++) {
        m[i] = (int*)malloc(sizeof(int) * 4); //int�� ������ ������ 4���� �޸� ������ ����
                                              // => ���������Ϳ� �����Ͱ� 3�� �ְ� �� �����ʹ� 4���� �޸� ������ ����
    }

    m[2][3] = 14;//3*4�� 2���� �迭 ������
    cout << m[2][3] << endl;

    //�ʱ�ȭ
    for (int i = 0; i < 3; i++) {
        free(m[i]); //���� (������ ���� ���� �ʱ�ȭ)
    }

    free(m); //���� ���� �ʱ�ȭ


    //����ڰ� �Է��� ��ŭ �޸� ũ�� �Ҵ�
    int row, col;
    cin >> row;
    cin >> col;

    int **m2 = (int**)malloc(sizeof(int*) * row);//2�� �����Ϳ� ������ ���ϴ� ������ŭ �ֱ�

    //������ �����ٷ� ����
    for (int i = 0; i < row; i++) {
        m2[i] = (int*)malloc(sizeof(int) * col); //�����͸� �ҷ��� ������ �ȿ� ���ϴ� ���� ��ŭ int�� �޸� ����
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            m2[i][j] = i + j;
        }
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << m2[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < row; i++){
        free(m2[i]);
    }

    free(m2);

    //�����͸� 3���� �迭ó�� ����ϱ�
    
    long long*** m3 = (long long***)malloc(sizeof(long long**) * 2); //3�� �����Ϳ� 2�������� 2�� ����

    for (int i = 0; i < 2; i++) {//���� 2��
        m3[i] = (long long**)malloc(sizeof(long long*) * 3);//���� ũ�� 3�� �����ͷ� ����
        for (int j = 0; j < 3; j++) {//����3��
            m3[i][j] = (long long*)malloc(sizeof(long long) * 5);//����ũ�� 5�� int�� ���� 
        }
    }
    

    m3[1][2][4] = 100;

    cout << m3[1][2][4] << endl;

    //������ �ʱ�ȭ
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++){
            free(m3[i][j]); // ���� �������� ������ 2�� �迭���� �ʱ�ȭ ��Ŵ
        }
        free(m3[i]); //2�������Ͱ� �� �迭���� �ʱ�ȭ ��Ŵ
    }

    int m4;
    cin >> m4;


    int** plan = (int **)malloc(sizeof(int*) * m4);

    for (int i = 0; i < m4; i++) {
        plan[i] = (int*)malloc(sizeof(int) * m4);
        memset(plan[i], 0, sizeof(int)* m4);
    }

    for (int i = 0; i < m4; i++)
    {
        plan[i][i] = 1;
    }

    for (int i = 0; i < m4; i++) {
        for (int j = 0; j < m4; j++) {
            printf("%d ", plan[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < m4; i++) {
        free(plan[i]);
    }

    free(plan);



#pragma endregion

    cout << "============== ������ ���� end =============" << endl;

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