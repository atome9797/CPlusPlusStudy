// 220411_Review.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//


// c++ 문법

// 주석 : 실행(컴파일) 되지 않고 설명만을 위해서 사용되는 문법
/*
    1
    2
    3
    4
*/


/*
    c++ 문법을 사용 할때 주의해야 할점
     1. 대소문자를 구분해야 한다.

     main / Main /maIN

     2. 띄어쓰기를 통헤 요소를 구분한다. 

     (1)float (2)num1 (3)= (4) 1.0f

     3. 실행문의 마무리는 세미콜론(;)으로 한다.

     [변수] : 데이터를 저장할 메모리 공간을 할당 받는다.
     데이터 타입 변수명;
     데이터 타입 변수명 =10;
     데이터 타입 변수명 ='a';
     데이터 타입 변수명 ="Hello";

     데이터 타입
     1. 정수형 (0,1,2,3,...,-1,-2,-3,...)
     
     int
     short
     long
     long long
     __init8, __init16, __init32, __init64

     2. 실수형 

     float
     double
     long double

     3. 문자형

     char

     4. 문자열

     string

     변수명 이름 짓기 (표기법)
     1. 헝가리안 표기법
        - 데이터 타입 약자를 접두어로 붙인다.
        int nMaxCount =10;

     2. 카멜 표기법
        int maxCount = 10;
     3. 파스칼 표기법
        int TokenMaxCount = 10;

        int token_max_count = 10;

        int nn = 10; (x)
        int cmprs = 20; (x)

        1. 대소문자를 구분한다.
        2. 알파벳, 숫자, _(언더바)만 사용한다.
            2-1. 숫자는 가장 앞에 올 수 없다.
    
    4. 변수의 4가지 속성
    1) 이름 : input_key 2) 크기 4btye 3) 값 10 4) 메모리 주소 000000B974EFF874
     
    5. 연산자
        데이터를 가공(연산)하는 모든 명령에 필요한 것들
        1) 어떤 종류의 연산자인가
        2) 우선순위 : 어떤 순서로 연산이 되는가
        3) 결합순서 : 좌측부터 연산하는가, 우측부터 연산하는가

        1. 사칙 연산 : 산술 연산자  (좌측부터 연산된다.)
        + : 더하기
        - : 빼기
        * : 곱하기
        / : 나누기 11/3 -> 3 (몫)
        % : 나머지 11/3 -> 2 (나머지)

        2. 대입 연산자 (우측 부터 연산된다.)
        = : 왼쪽 항에 오른쪽 항의 값을 대입(복사)한다.

        3. 복합 대입 연산자 
        += : a += b;  -> a = a + b;
        -= :  a -= b;  -> a = a - b;
        *= :  a *= b;  -> a = a * b;
        /= :  a /= b;  -> a = a / b; (b==0, 런타임 에러 발생)
        %= :  a %= b;  -> a = a % b; (데이터 타입이 정수형이 아닐때)

        4. 증감 연산자
        특정 변수의 값을 1씩 증가 시키거나 감소시킬때 사용하는 연산자
        변수명 앞이나 뒤에 ++ / -- 를 붙여서 사용한다.

        5. 관계 연산자
        두항의 값을 비교한 결과가 참(1,true) 또는 , 거짓(0,false)으로 반환되는 연산자

        a < b 
        a > b
        a <= b
        a >= b
        a == b
        a != b

        6. 논리 연산자
        왼쪽 항과 오른쪽 항의 값을 각각 참과 거짓으로 연산해서 
        두 값을 비교해서 참과 거짓을 반환하는 연산자

        && : 논리 곱 (AND)
        a && b  :  a의 결과 값이 참이고, b의 결과값이 참이면 1을 반환

        || : 논리 합 (OR)
        a || b  :  a의 결과 값이 참이거나, b의 결과값이 참이면 1을 반환

        ! : 논리 부정(NOT)
        !a : a 의 결과값이 참이면 거짓을 반환, 거짓이면 참을 반환

        7. 삼항 연산자
        a ? b : c; a의 결과값이 참이면 b 실행문이 동작, 거짓이면 c실행문이 동작.

        난수 (랜덤값) 
        rand(); -> 랜덤 값 나옴 // 0 ~ 32767 사이의 랜덤한 값이 반환된다. 
        : 2 바이트의 최대 표현 범위에서 나옴 
        함수 내부에 seed값이 있어서 이 값에 의해서 리턴값이 정해진다.
        기본적으로 seed : 1로 세팅되어 있다.

        srand(time(NULL));
        
     */

/*
    실습 1.  3 ~ 7 사이의 랜덤한 숫자를 출력하는 프로그램을 작성하자.(3,7 포함)
    
    실습 2.  가장 작은 값과 큰값을 입력 받아서, 
    그 사이의 임의의 값 (랜덤)을 출력하는 프로그램을 작성하자.

    실습 3. 프로그램을 실행하면 내부적으로 1 ~ 9 사이의 숫자가 정답으로 정해진다.
    유저가 1~9 사이의 숫자를 입력하면 맞으면 true, 틀리면 false 를 출력한다.

*/
#include <iostream>  // iostream 파일을 불러와 문법 사용할수 있게 해줌
#include <string>

using namespace std;

int main()
{   
    //cout << boolalpha; //boolalpha 사용시 숫자가 아닌 true false로 출력됨
    //cout << ((10 < 5) == 0) << endl; // 1, true 출력됨
    
    //논리 부정
    cout << !1 << endl; // 0이 출력
    cout << !0 << endl; // 1이 출력
    cout << !-300 << endl; // 0이 출력

    // 삼항 연산자
    (10 < 5) ? cout << "10이 5보다 크다." << endl : cout << "10이 5보다 작다" << endl;

    //랜덤
    srand(time(NULL)); //시간에 따라 seed값이 바뀌게 나옴
    cout << rand() << endl;

    //실습 1. 3 ~ 7
    srand((int)time(NULL));
    int val = rand() % 5 +3; 
    //5의 나머지는 0~4로 랜덤값은 0에서 4사이의 값이 나오는데, 원하는값은 3 ~7 사이값이므로
    // +3 해준다.
    cout << "실습 1 :" << val << endl;
    
    //실습 2. 임의의 랜덤값 사이값 출력
    int maxInt = 0;
    int minInt = 0;
    cout << "임의의 큰수 : " << endl;
    cin >> maxInt;
    cout << "임의의 작은 수 : " << endl;
    cin >> minInt;
    //(최댓값 - 최솟값) + 1 => 사이값 갯수임 , 최솟값을 +로 더해줌
    int val10 = rand() % ((maxInt - minInt) + 1) + minInt;
    cout << "실습 2 : " << val10 << endl;
    
    //실습3. 1~9 
    cout << "임의의 값 : " << endl;
    int val11;
    cin >> val11;
    int val12 = rand() % 9 +1; // 1~9 사이값 나옴
    (val11 == val12) ? cout << "true" << endl : cout << "false" << endl;

    cout << "=====================" << endl;

    int input_key = 10;
    cout << input_key++ << endl; // 10
    cout << ++input_key << endl; // 12
    cout << input_key-- << endl; // 12
    cout << --input_key << endl; // 10

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
    int token [6] = {7,7,7,7,7,5}; //에메랄드, 다이아몬드,사파이어, 줄비노, 루비, 황금
    int del_card = 90; //개발 카드 수
    int royal_card = 10; // 귀족 카드 수
    
    
    cout << "에메랄드 수 : " << token[0] << endl;
    
    
    //if 조건문 => if문 인자에 0을 넣으면 false, 0이 아니면 true로 반환 
    int num18 = 10;
    if (num18 ==10) {
        printf("10입니다\n");
    }

    if (num18 ==12) {
        cout << "12" << endl;
    }
    else if (num18 ==10) {
        cout << "10" << endl;
    }
    else {
        cout << "out" << endl;

    }

    // 논리 연산자
    int num19 = 10;
    int num20 = 20;
    
    
    if (num19 ==10 && num20==20) {
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
    else if(age >= 7  && age <= 12) {
        balance -= 450;
        
    }

    cout << "총합: " << balance;


}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
