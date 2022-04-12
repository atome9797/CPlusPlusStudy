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
        : 4 바이트의 최대 표현 범위에서 나옴 
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
/*
    6. 제어문         데이터(타입) / 연산자 / <제어구조>

    1. 조건문 : 특정 조건에 따라서 실행문을 실행할지 안할지 제어 : if/switch
    2. 반복문 : 특정 조건에 따라서 실행문을 일정횟수 만큼 반복실행시키도록 제어 : while/for

    조건문
    1-1. if 문

    if (조건식1) 
    {
        실행문1;
    }
    else if(조건식2)
    {
        실행문3;
    }
    else
    {
        실행문2;
    }

    조건문 실습 1. 
    정수를 하나 입력 받아서 입력 받은 숫자가 10보다 크면 
    "입력된 숫자가 10보다 큽니다." 출력
    10이하 9 초과이면 "9보다 큽니다." 출력
    9 이하 6 초과이면 "6보다 큽니다." 출력
    그 이외에는 "6보다 작거나 같습니다." 출력

    1-2. switch 문

    switch (정수형 변수)
    {
        case 정수1: 실행문1; break;
        case 정수2: 실행문2; break;
        case -3: 실행문3; break;
        default :  실행문4; break;  //해당하는 조건값이 없을때 실행
    }

    switch문 실습.
    당신의 고향은 어디입니까?
    1. 서울, 2. 양평 3. 광주 4. 대전 5. 제주도
    _1 
    
    안녕하세요. 당신의 고향은 서울이군요.
    안녕하수꽝. 혼저옵서예.
    디폴트는 5개중 선택해 주세요.

    7. 반복문
    2_1 . while 문 (루프)

    while (조건식) 
    {
        실행문;
        조건식을 바꾸는 실행문; // while문을 중단시키는 첫번째 방법

        if (조건식) break; // whlie문을 중단시키는 두번째 방법
    }

    do~ while문
    do{
        실행문;
    } while (조건식);

    2_2 . for문

    for ((1)초기식; (2)조건식; (3)증감식;)
    {
        (4)실행문;
    }

    (1) -> (2) -> (4) -> (3) -> (2) -> (4) -> (3) .... => 조건식의 결과값이 0이 나올때 까지
*/
#include <iostream>  // iostream 파일을 불러와 문법 사용할수 있게 해줌
#include <string>

using namespace std;

int main()
{   

#pragma region 별찍기숙제
    /*
        별찍기 
        1) 
        *
        * *
        * * *
        * * * *
        * * * * *
        
        2) 
            *
           **
          ***
         ****
        *****
        
        3) 
        *****
        ****
        ***
        **
        * 
        
        4) 
        *****
         ****
          ***
           **
            *
        5)
          *
         ***
        *****
       *******
      ********* (5줄이고, 9개)
       
       6)
       ******* (5줄이고 , 9개)
        *****
         ***
          *
       7)
          *
         ***
        *****
       *******
      *********
       *******
        *****
         ***
          *
    */

    int star_num = 10;
    cout << "별 찍기 1)" << endl;
    for (int i = 0; i < star_num; i++) {
        for (int j = 0; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }


    //0 10/ 0 9 / 0 8 / 0 7 ... 0 0
    //1 10/ 0 9 / 0 8 .....     0 1 => 00 까지는 못감으로 * 가 하나 빠짐 
    int star_num2 = 10;
    cout << "별 찍기 3)" << endl;
    for (int i = 0; i < star_num2; i++) {
        for (int j = star_num2; j >= i; j--) {
            cout << "*";
        }
        cout << endl;
    }
    
    /*
        ----*
        ---**
        --***
        -****
        *****
    */
    //10 1/ 10 2/10 3 .... 10 10 
    //10 10  -> 1개 *
    //9 1/9  2/9 3 ..... 9 9 -> 10자리 까지 못감
    //10 9/ 9 9 -> 2개 *
    cout << "별 찍기 2)" << endl;
    int star_num3 = 10;
    for (int i = star_num3; i > 0; i--) {
        for (int j = 1; j <= i; j++) {
                cout << " ";
        }
        
        for (int j = star_num3; j >= i; j--) {
                cout << "*";
        }
        cout << endl;
    } 

    
    /*
        *****
        -****
        --***
        ---**
        ----*
    */
    //0 1 => j는 1 부터 출력이라 "-"로 출력못함
    //0 10/0 9/0 8/0 7.... 0 0 => "*" 출력
    //1 0/1 1 =======> "-" 출력
    //1 10/1 9/1 8 ....1 1 => "*" 0까지는 못하고 출력
    cout << "별 찍기 4)" << endl;
    int star_num4 = 10;
    for (int i = 0; i < star_num4; i++) {
        for (int j = 1; j <= i; j++) {
            cout << " ";
        }

        for (int j = star_num4; j > i; j--) {
            cout << "*";
        }
        cout << endl;
    }

    
    /*
      ----*----
      ---***---
      --*****--
      -*******-
      ********* 
    */
    //10
    //10 0/10 1/10 2 ... 10 9 => "-" 출력
    //10 
    //10 1/10 2....... 10 10 => "-"출력
    cout << "별 찍기 5)" << endl;
    int star_num5 = 10;
    for (int i = star_num5; i > 0; i--) {
        for (int j = 0; j <= i; j++) {
            cout << " ";
        }
        for (int j = star_num5; j >= i; j--) {
            cout << "*";
        }
        for (int j = star_num5; j > i; j--) {
            cout << "*";
        }

        for (int j = 0; j < i; j++) {
            cout << " ";
        }
        
        cout <<  endl;
    }


    /*
        ******* 
        -*****-
        --***--
        ---*---
    */

    //
    cout << "별 찍기 6)" << endl;
    int star_num6 = 10;
    for (int i = 0; i < star_num6; i++) {
        for (int j = 1; j <= i; j++) {
            cout << " ";
        }

        for (int j = star_num6; j > i; j--) {
            cout << "*";
        }
        for (int j = star_num6-1; j > i; j--) {
            cout << "*";
        }

        for (int j = 0; j < i; j++) {
            cout << " ";
        }


        cout << endl;
    }
    

    /*
          *
         ***
        *****
       *******
      *********
       *******
        *****
         ***
          *
    */


    cout << "별 찍기 7)" << endl;
    int star_num7 = 11;
    int star_num8 = 11;

    for (int i = star_num7; i > 0; i--) {
        for (int j = 0; j <= i-2; j++) {
            cout << " ";
        }
        for (int j = star_num7; j >= i; j--) {
            cout << "*";
        }
        for (int j = star_num7; j > i; j--) {
            cout << "*";
        }

        for (int j = 0; j < i; j++) {
            cout << " ";
        }

        cout << endl;
    }

    //0 0/0 1 ...........0 10
    //0 9
    for (int i = 0; i < star_num8; i++) {


        for (int j = 0; j <= i; j++) {
            cout << " ";
        }

        for (int j = star_num8; j > i; j--) {
            cout << "*";
        }
        for (int j = star_num8 - 3; j > i; j--) {
            cout << "*";
        }

        for (int j = 1; j < i; j++) {
            cout << "-";
        }


        cout << endl;
    }



    

    
#pragma endregion



#pragma region for문실습
    /*
        for문 실습1.
        10부터 1까지 차례대로 출력되는 코드를 작성해보자.
        10
        9
        8...1

        실습2.
        100미만의 3의 배수를 차례대로 출력되는 코드를 작성해보자.
        3
        6
        9

        실습3. 1000 미만의 2의 승수를 차례대로 출력되는 코드를 작성해 보자
        1
        2
        4
        8
        16
    */

    cout << "실습 1 : " << endl;
    for (int i = 10; i > 0; i--)
    {
        cout << i << endl;
    }

    cout << "실습 2 : " << endl;
    for (int i = 3; i < 100; i += 3)
    {
        cout << i << endl;
    }

    cout << "실습 3 : " << endl;
    for (int i = 1; i < 1000; i *= 2)
    {
        cout << i << endl;
    }

    /*
        실습 4. 구구단을 출력해보자.
        4_1. 구구단 2단을 차례대로 출력해보자.
        
        4_2 . 구구단 2단 ~9 단을 차례대로 출력해보자.
        2단

        3단

        4단
        ...
        8단

        9단

        4_3. 구구단 2단 ~9 단을 다음과 같은 형태로 출력해보자.
        2단 3단 4단

        5단 6단 7단

        8단 9단
    */

    cout << "실습 4_1 .===============" << endl;
    for (int i = 1; i < 10; i++)
    {
        cout << "2 * " << i << " = " << 2 * i << endl;
    }
    cout << "실습 4_2 .===============" << endl;
    for (int i = 2; i < 10; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            cout << i << " * " << j << " = " << i * j << endl;
        }
        cout << endl;
    }
    cout << "실습 4_3 .===============" << endl;
    //for (int i = 1; i < 10; i++){
    //    for (int j = 2; j < 10; j++){
    //        //cout << j << " * " << i << " = " << i * j << "   ";

    //        //나머지가  5 , 8 일때 줄바꿈
    //       if (j % 5 == 0 || j % 8 ==0) {
    //           continue;
    //       }
    //       else {
    //           cout << j << " * " << i << " = " << i * j << "    ";

    //       }
    //    }
    //    cout << endl;
    //}

    int cnt = 3;
    for (int i = 0; i < 3; i++) //3줄 : 234 567 8910 3줄을 표현
    {
        for (int j = 1; j < 10; j++) //곱해지는 수
        {
            for (int k = 2 + cnt*i; k <= 4+cnt*i ; k++) // 한줄에 표현되는 숫자 범위
            {  
                if (k >= 10) {
                    break;
                }
                cout << k << " * " << j << " = " << k * j << "    ";
            }
            cout << endl;
        }
        cout << endl;
    }


    
    int idx, idx2; for (idx = 1; idx <= 9; idx++) { 
        for (idx2 = 2; idx2 <= 4; idx2++) { 
            printf("%2d *%2d = %2d ", idx2, idx, idx * idx2); 
        } 
        printf("\n"); 
    } 
    
    printf("\n"); 
    
    for (idx = 1; idx <= 9; idx++) { 
        for (idx2 = 5; idx2 <= 7; idx2++) { 
            printf("%2d *%2d = %2d ", idx2, idx, idx * idx2); 
        } 
        printf("\n"); 
    } 
    printf("\n"); 
    
    for (idx = 1; idx <= 9; idx++) { 
        for (idx2 = 8; idx2 <= 9; idx2++) { 
            printf("%2d *%2d = %2d ", idx2, idx, idx * idx2); 
        } 
        printf("\n"); 
    }


#pragma endregion


#pragma region 실습123

    //실습 1. 3 ~ 7
    // 입력 : 없음

    // 처리 : 
    /*
        int ran_num;
        ran_num = 3 , 4, 5,6,7
                 0+3 , 1+3, 2+3, 3+3 , 4+3  => 0~4사이의 숫자 값이 나오게 하려면 나머지의 범위로 설정하면됨   
        srand(time(NULL));
        ran_num = rand() % 5 +3;
    */

    // 출력 : 숫자 하나 출력
    //cout << "실습 1 :" << val << endl;
    
    srand((int)time(NULL));
    int val = rand() % 5 +3; 
    //5의 나머지는 0~4로 랜덤값은 0에서 4사이의 값이 나오는데, 원하는값은 3 ~7 사이값이므로
    // +3 해준다.
    cout << "실습 1 :" << val << endl;

    
    //실습 2. 임의의 랜덤값 사이값 출력
    /*
    *   int max_number;
    *   int min_number;
        cin >> int max_number;
        cin >> int min_number;
        
    */
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
    //입력
    cout << "임의의 값 : " << endl;
    int val11;
    cin >> val11;
    //처리
    int val12 = rand() % 9 +1; // 1~9 사이값 나옴
    
    //출력
    (val11 == val12) ? cout << "true" << endl : cout << "false" << endl;
    
    //실습4. while문을 써서 정답을 맞출때까지 반복되는 프로그램으로 수정해보자.
    //입력 :
    int val_num = 0;
    int val_num2 = 0;

    //처리 :
 
    do {
        cout << "while문 임의의 값 : " << endl;
        cin >> val_num;
        int val_num2 = rand() % 9 + 1;
        if (val_num == val_num2) {
            cout << "정답입니다." << endl;
            break;
        }
        
    } while (val_num != val_num2);

    //처리
    int val_num10=0;
    int val_num11 = rand() % 9 + 1; // 1~9 사이값 나옴

    while (val_num10 != val_num11) {
        cout << "while문 임의의 값 : " << endl;
        cin >> val_num10;
        //출력
        (val_num10 == val_num11) ? cout << "true" << endl : cout << "false" << endl;
    }
    //출력 : 2 4 8 6 7 .. => 입력값과 난수 값이 같으면 "정답" 이록 표시 되며 멈춤

#pragma endregion

#pragma region 조건문실습

    //입력 : 
    int input_num;
    cout << "조건문 숫자 입력 : ";
    cin >> input_num;
    
    //처리 :
    if (input_num > 10) {
        cout << "입력된 숫자가 10보다 큽니다." << endl;
    }
    else if (input_num > 9) {//굳이 num < 10을 사용할 필요 없다
        cout << "9보다 큽니다." << endl;
        
    }else if (input_num > 6) {
        cout << "6보다 큽니다." << endl;
    
    }else {
        cout << "6보다 작거나 같습니다." << endl;
        
    }
    //출력 :
   /* cout << "입력된 숫자가 10보다 큽니다." << endl;
    cout << "9보다 큽니다." << endl;
    cout << "6보다 큽니다." << endl;
    cout << "6보다 작거나 같습니다." << endl;*/


#pragma endregion

#pragma region switch문실습

    //입력 
    int region_num;
    cout << "당신의 고향은 어디입니까?" << endl;
    cout << "1. 서울, 2. 양평 3. 광주 4. 대전 5. 제주도" << endl;
    cin >> region_num;
    //처리
    switch (region_num)
    {
    case 1: cout << "안녕하세요. 당신의 고향은 서울이군요." << endl; break;
    case 2: cout << "안녕하세요. 당신의 고향은 양평이군요." << endl; break;
    case 3: cout << "안녕하세요. 당신의 고향은 광주이군요." << endl; break;
    case 4: cout << "안녕하세요. 당신의 고향은 대전이군요." << endl; break;
    case 5: cout << "안녕하수꽝. 혼저옵서예." << endl; break;
    default:
        cout << "5개중 선택해 주세요." << endl;
        break;
    }
    //출력
    cout << "안녕하세요. 당신의 고향은 서울이군요." << endl;
    cout << "안녕하세요. 당신의 고향은 양평이군요." << endl;
    cout << "안녕하세요. 당신의 고향은 광주이군요." << endl;
    cout << "안녕하세요. 당신의 고향은 대전이군요." << endl;
    cout << "안녕하수꽝. 혼저옵서예." << endl;
    cout << "5개중 선택해 주세요." << endl;

    
    //switch문을 if문으로 변경
    if (region_num == 1) {
        cout << "안녕하세요. 당신의 고향은 서울이군요." << endl;
    }
    else if (region_num == 2) {
        cout << "안녕하세요. 당신의 고향은 양평이군요." << endl;
    }
    else if (region_num == 3) {
        cout << "안녕하세요. 당신의 고향은 광주이군요." << endl;
    }
    else if (region_num == 4) {
        cout << "안녕하세요. 당신의 고향은 대전이군요." << endl;
    }
    else if (region_num == 5) {
        cout << "안녕하수꽝. 혼저옵서예." << endl;
    }
    else {
        cout << "5개중 선택해 주세요." << endl;
    }
#pragma endregion

#pragma region 수업내용

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

    cout << "=====================" << endl;

    int input_key = 10;
    cout << input_key++ << endl; // 10
    cout << ++input_key << endl; // 12
    cout << input_key-- << endl; // 12
    cout << --input_key << endl; // 10


    //반복문 while
    int repeat_count = 0;
    while (repeat_count < 5) {
        cout << "Hello World" << endl;
        repeat_count++;
    } 
    
    while (1) {
        if (repeat_count >= 5) break;
        cout << "Hello World" << endl;
        repeat_count++;
    }

    //do while문
    do {
        cout << "Hello World" << endl;
        repeat_count++;
    } while (repeat_count < 5);


    //for문
    for (int i = 0; i < 5; i++)
    {
        cout << "Hello World" << endl;
    }

#pragma endregion

#pragma region dojang

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
    for (int i = 0, j = 0; i < 10 && j < 10; i++,j+=2) {
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
        if (num31 >= 3 && num31 <=7) {
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
        if (i %2 ==0) {//짝수면 출력하는 구문
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
    } while (!(exnum1 >= 1 && exnum1 <=200));
    do {
        cout << "두번재 정수" << endl;
        cin >> exnum2;
    } while (!(exnum2 >= 10 && exnum2 <=200));
    
    while (1) {
        exnum3++;

        //exnum3 가 exnum2보다 커지면 break;
        if (exnum3 >= exnum2) {
            break;
        }
        if (exnum3 % 10 == 7 ) {
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

    

#pragma endregion


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
