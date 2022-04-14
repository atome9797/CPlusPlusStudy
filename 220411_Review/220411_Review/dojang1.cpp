#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {

#pragma region 포인터

    cout << "========== 포인터 변수 =========" << endl;

    //포인터 변수 선언
    /*
        자료형 *포인터이름; -> 값 저장해줌
        포인터 = &변수; -> 메모리 주소 저장해줌
    */
    int* numPtr; //메모리 주소 저장해줌 => 포인터 변수 선언
    int exnum5 = 10;

    numPtr = &exnum5; //exnum5의메모리 주소를 포인터 변수에 저장

    cout << numPtr << endl;
    cout << *numPtr << endl;

    cout << sizeof(numPtr) << endl; //64비트 운영체제 에서는 8바이트로 나온다. 32비트 운영체제는 4바이트

    *numPtr = 2; //포인터로 연결된 주소값도 같이 변함

    cout << exnum5 << endl; //2로 바뀐것을 볼수있음


    //!!!!!!주의 !!!!!!!
    //포인터 변수 사용전에 반드시 초기화 시켜 줘야함 
    //-> 값을 가지고 있어서 문제 발생할수있음 -> 프로그램 꼬일수 있음
    *numPtr = NULL;

    int a = 10, b = 10, temp;
    int* x, * y;
    x = &a; //포인터로 연결됨 -> 값이 바뀜
    y = &b;
    cout << "a : b => " << a << " : " << b << endl;

    temp = *x; //포인터 변수의 값을 저장함 temp = 10
    *x = *y;  //역참조로 포인터 변수에 포인트 변수값을 할당함 *x= 10
    *y = temp; // temp의 값을 역참조로 y포인트 변수에 할당함 *y = 10 -> y와 temp은 역참조로 연결됨

    *y = 15;

    cout << "a : b => " << a << " : " << b << endl; // 10 15로 나옴

    //디버깅으로 포인터 변수 값 확인하기
    int* numPtr10;
    int exnum10 = 10;

    numPtr10 = &exnum10; //포인터로 연결
    *numPtr10 = 20; //역참조로 값 할당 -> exnum10 도 값이 바뀜
    cout << *numPtr10 << endl;
    cout << exnum10 << endl;


    //void pointer 선언하기
    int num1v = 10;
    char c1v = 'a';
    int* numPtr1v = &num1v; //메모리 주소 할당 -> 포인터로 연결
    char* cPtr1v = &c1v;

    void* ptrv; //void 포인터 변수 선언 

    //포인터는 자료형 달라도 컴파일 경고 없음
    ptrv = numPtr1v; //void 포인터에 int 포인터 저장
    //cout << *ptrv << endl; -> void 포인터는 역참조 할수없음 
    // -> 역 참조 하기 전에 void 포인터를 형변환 해주면된다.


    numPtr1v = (int*)ptrv;
    //형변환을 시켜주면 void 포인터도 역참조 할수있다.
    //void 포인터를 int형 포인터에 저장


    //이중 포인터 사용하기
    //포인터의 메모리 주소를 저장하는 포인터의 포인터
    int* numPtr1a; //단일 포인터
    int** numPtr2a; //이중 포인터 => 포인터의 포인터를 저장할수 있다.
    int num1a = 10;

    numPtr1a = &num1a;//int 변수의 메모리 주소 단일포인터에 저장
    numPtr2a = &numPtr1a; //단일 포인터의 메모리 주소를 2중 포인터에 저장

    // numPtr2a ->numPtr1a ->num1a 연결됨 (java의 super와 동일)
    cout << **numPtr2a << endl; //역참조한 값을 출력함

    //연습문제
    int* numPtrb;
    int num1b = 10;
    int num2b = 20;
    
    numPtrb = &num1b;
    cout << *numPtrb << endl;

    numPtrb = &num2b;
    cout << *numPtrb << endl;

    //연습문제
    int* numPtr1c;
    int** numPtr2c;
    int num1c;
    
    cin >> num1c;

    numPtr1c = &num1c;
    numPtr2c = &numPtr1c;

    printf("%d\n", **numPtr2c);
    
    //메모리 사용하기
    int num1d = 20;
    int* numPtr1d;

    numPtr1d = &num1d;

    int* numPtr2d;

    numPtr2d = (int*)malloc(sizeof(int)); 
    //int 형 포인터에 int 타입의 4바이트 메모리 공간을 만들어준다
    //c++에서는 void 함수의 경우 형변환을 해줘야한다.

    printf("%p\n", numPtr1d);//num1d의 메모리 주소 출력
    printf("%p\n", numPtr2d);//malloc에 의해 만들어진 heap 메모리 주소 출력
    
    free(numPtr2d);//동적 할당 메모리 해제 (heap할당 메모리는 반드시 해제 해줘야함)
    //메모리를 해제 하지 않아서 메모리가 쌓여 시스템이 꺼지는 문제 발생할수 있음
    //buffer 메모리를 clean 하는 것과 비슷함 


#pragma endregion

#pragma region 강의

    cout << "=============강의 ================" << endl;

    float testFloat = 5.3f;
    float testFloat2 = 5.3; //데이터 범위가 double로 바뀐다
    char testCharacter = 'a';
    std::cout << "Hello World!\n";
    std::string testString = "Hello"; //string 은 클래스 이므로 앞에 std를 붙인다.
    //std::cin >> input_key;


    float num1 = 1.0f;
    float num2 = 0.0f;
    float num3;

    num3 = num1 / num2;
    printf("%f\n", num3); //결과값 : inf // inf 는 무한대라는 의미임

    //실수의 나머지 연산은 fmod, fmodf, fmodl 함수사용
    double num4 = 10.843;
    double num5 = 4.95;
    printf("%f\n", fmod(num4, num5)); //fmod로 double 형태의 나머지값 계산 0.943000

    float num6 = 9.85f;
    float num7 = 3.15f;
    printf("%f\n", fmodf(num6, num7)); //fmodf로 float 형태의 나머지 값 계산 0.400000

    //long double 은 16 바이트로 고 용량으로 쓰임
    long double num8 = 10.795;
    long double num9 = 2.795;
    printf("%Lf\n", fmodl(num8, num9)); //fmodl 로 long double 형태의 나머지 값 계산 2.410000

    //음수의 나머지 값 구하기
    printf("%d\n", -5 % -3); // -5를 -3으로 나눈 나머지 값은 -2이다
    printf("%d\n", -5 % 3); // -5를 3으로 나눈 나머지 값은 -2이다
    printf("%d\n", 5 % -3); // 5를 -3으로 나눈 나머지 값은 2이다

    //정수를 실수로 나누기
    int num10 = 11;
    float num11 = 4.4f;

    printf("%f\n", num10 + num11); //정수 11이 실수형으로 변환됨 (표현 범위 넓은 쪽으로 자동 변환됨)

    //실수를 정수로 표현하기 : 형변환시 값 손실이 발생 (범위가 작은쪽으로 변환 하는 것이므로)
    float num12 = 11.0f;
    float num13 = 5.0f;

    int num14 = num12 / num13;// 작은 범위 쪽으로 형변환
    printf("%d\n", num14); //정수 2 출력됨

    char num15 = 28;
    int num16 = 10000000008; //int가 char랑 합쳐질때 char형태로 축소되는데, 축소될때 앞자리수는 삭제되고 
    //8만 남아 int와 연산하게됨
    char num17 = num15 + num16;
    printf("%d\n", num17);//36

    //스플렌더 게임
    int token[6] = { 7,7,7,7,7,5 }; //에메랄드, 다이아몬드,사파이어, 줄비노, 루비, 황금
    int del_card = 90; //개발 카드 수
    int royal_card = 10; // 귀족 카드 수


    cout << "에메랄드 수 : " << token[0] << endl;


    //if 조건문 => if문 인자에 0을 넣으면 false, 0이 아니면 true로 반환 
    int num18 = 10;
    if (num18 == 10) {
        printf("10입니다\n");
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

    // 논리 연산자
    int num19 = 10;
    int num20 = 20;


    if (num19 == 10 && num20 == 20) {
        printf("참\n");
    }

    //교통카드 차감 문제

    int balance = 10000;
    int age;
    cout << "나이 입력 : " << endl;
    //cin >> age;

    cin >> age;

    //성인
    if (age >= 19) {
        balance -= 1200;
    } //청소년
    else if (age >= 13 && age <= 18) {
        balance -= 720;
    } //어린이
    else if (age >= 7 && age <= 12) {
        balance -= 450;

    }

    cout << "총합: " << balance;

    //시프트 연산으로 2의 거듭제곱 알아보기
    unsigned char num21 = 1; // 1 : 0000 0001
    printf("%u\n", num21 << 1); //  2 : 0000 0010 : 2
    printf("%u\n", num21 << 2); //  4 : 0000 0100 : 2^2
    printf("%u\n", num21 << 3); //  8 : 0000 1000 : 2^3
    printf("%u\n", num21 << 4); //  16 : 0001 0000 : 2^4
    printf("%u\n", num21 << 5); //  32 : 0010 0000 : 2^5
    printf("%u\n", num21 << 6); //  64 : 0100 0000 : 2^6
    printf("%u\n", num21 << 7); //  128 : 1000 0000 : 2^7

    //논리 연산자 우선순위 : ! , && , || 순
    bool b1;
    b1 = (false || true) && !false || false;
    printf("%d\n", b1); //true 출력됨 1

    //비교연산자 우선순위 : < , == 순
    int num22 = 5;
    num22 = 5 == 5 < 10;
    //5<10 비교로 true 1이 나옴, 5와1을 비교 false됨 0, num22에 0을 대입 
    printf("%d\n", num22);

    //시프트 연산자와 산술연산자 우선순위
    int num23 = 1;
    int num24 = 2;
    int num25;

    cout << "========================" << endl;
    num25 = num23 << 2 + num24 << 1;// (+) 연산자가 우선시 됨
    printf("%d\n", num25);

    int num26;
    cout << "번호 입력 : ";
    cin >> num26;
    switch (num26) {
    case 1: cout << "1입니다 \n" << endl; break;
    case 2: cout << "2입니다 \n" << endl; break;
    case 3: cout << "3입니다 \n" << endl; break;
    case 4: cout << "4입니다 \n" << endl; break;
    default: cout << "기본" << endl; break;
    }

    //내림 차순 만들기
    for (int i = 25; i > 0; i--) {
        printf("hello %d\n", i);
    }

    int num27;
    //for문 안에서 입력 함수를 선언하고 사용할수 있음 
    for (cin >> num27; num27 > 0; num27--) {
        cout << num27 << endl;
    }

    //for문 안에 2개의 변수를 사용하기
    for (int i = 0, j = 0; i < 10 && j < 10; i++, j += 2) {
        cout << " i : " << i << " j : " << j << endl;
    }

    cout << "while 반복문" << endl;
    int num30 = 0;
    while (true) { //조건문을 넣지 않고 true를 넣으면 무한 반복됨
        if (num30 > 10) {
            break;
        }
        cout << num30 << endl;
        num30++;
    }

    //문제 1 반복문
    //입력 : 없음
    //처리 : 
    for (int i = 2, j = 5; j > 0; i *= 2, j--) {
        cout << " i : " << i << " j : " << j << endl;
    }

    //출력 : 
    /*
    *       2 5
            4 4
            8 3
            16 2
            32 1
    */

    // 범위 난수 while문으로 표현
    srand(time(NULL));


    int num31 = 0;
    while (true) { //true 대신 1도 사용가능
        num31 = rand() % 10;
        if (num31 >= 3 && num31 <= 7) {
            cout << "while문의 범위 난수 3~7 : " << num31 << endl;
            break;
        }
    }

    int num32 = 0;
    //do ~ while 에서 do문을 실행하고 while 조건에 맞으면 다시 do문이 실행된다.
    do {
        cout << "dowhlie" << endl;
    } while (num32 != 0);

    do {} while (0); //do문 한번만 실행됨

    //continue
    for (int i = 1; i <= 25; i++) {
        if (i % 2 != 0) continue;

        //continue를 사용하면 밑의 부분은 실행하지 않고 다음 for문으로 넘어감
        cout << i << endl; //짝수가 아닐때 넘어가도록 설정함 -> 홀수는 출력안함
    }

    //입력한 숫자까지 짝수 구하기
    int count;
    cin >> count;

    cout << "입력한 숫자까지 반복문 ==========" << endl;
    //입력한 숫자가지 반복문
    for (int i = 0; i < count; i++)
    {
        if (i % 2 == 0) {//짝수면 출력하는 구문
            cout << i << endl;
        }

        //괄호로 쓰거나 continue를 사용해 나타낼수 있다.
        if (i % 2 != 0) continue; cout << i << endl;
    }

    //연습 문제1
    //입력 : 
    int exnum1 = 0; //정수1
    int exnum2 = 0; // 정수2
    int exnum3 = 0;



    cout << "두번재 정수" << endl;
    cin >> exnum2;

    exnum3 = exnum1;

    //처리 : 
    //나머지가 7이 아닌 숫자들만 출력되게 설정
    //첫번째 정수는 1 ~200사이값
    // 두번째 정수는 10 ~ 200 사이값
    // 두번째 정수 > 첫번째 정수 (항상)

    //무한 반복문
    do {
        cout << "첫번재 정수" << endl;
        cin >> exnum1;
    } while (!(exnum1 >= 1 && exnum1 <= 200));
    do {
        cout << "두번재 정수" << endl;
        cin >> exnum2;
    } while (!(exnum2 >= 10 && exnum2 <= 200));

    while (1) {
        exnum3++;

        //exnum3 가 exnum2보다 커지면 break;
        if (exnum3 >= exnum2) {
            break;
        }
        if (exnum3 % 10 == 7) {
            continue; //7로 끝나면 밑에있는것 실행하지 않고 다음 루프로 넘어감
        }

        cout << exnum3 << endl;
    }


    //별 트리 만들기 
    cout << "========= 별 만들기 ===================";
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i >= j) cout << "*";
        }
        cout << endl;
    }

    cout << "========== 레이블 =============== 넘어가려면 5" << endl;
    /*
        goto 제어문 => 자바의 level 문과 비슷 => 지정 레이블로 이동
        => 루프문을 빠져 나올때 사용가능
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
//    cout << "1입니다\n";
//    goto EXIT;//끝났다는 것을 지정해줌
//TWO:
//    cout << "2입니다\n";
//    goto EXIT;
//EXIT: return 0; //main()함수를 빠져 나가면서 정수 0을 반환 한다는 뜻

    //return 문 끝내면 main 함수 멈추므로 잘 실행할것







    



#pragma endregion

}//end main