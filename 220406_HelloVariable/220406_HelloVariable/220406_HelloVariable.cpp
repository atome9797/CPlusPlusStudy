#include <iostream>
#include <string>

using namespace std;


int main()
{

    // 변수
    /*
        1) 이름 : testNum 2) 데이터 크기 : 4byte 3) 메모리 주소:00000059686FFAD4  4) 값 2.8
    */

    float testNum = 2.8f;//형태 표시 -> f안붙힐시 double형으로 인식
    double testNum1 = 2.8;

    cout << sizeof(testNum) << endl;
    cout << &testNum << endl; //&사용시 메모리 주소 나옴
    cout << testNum1 << endl;

    std::cout << "Hello World!\n";

    // 실습1. 상대방 이름과 내 이름, 상대방 나이를 입력 받아서 축하메세지를 출력하는 프로그램을 만들어보자.



    /*
         예시 ) 상대방 이름을 입력하세요.
                _이승일
                본인의 이름을 입력하세요.
                _김영훈
                상대방 나이를 입력하세요.
                _27

                김영훈 : 이승일님 27살 생일을 축하합니다.
                

        해답 : 1. 상대방 이름과 내 이름, 상대방 나이를 입력 받는다.
                변수가 필요함
                데이터 타입 변수명;

                string your_name;
                cout << "상대방 이름을 입력하세요." << endl;
                cin >> your_name;

                string my_name;
                cout << "본인의 이름을 입력하세요." << endl;
                cin >> my_name;

                int your_age;
                cout << "상대방 나이를 입력하세요.\n" << endl;
                cin >> your_age;
                
    */

    /*
        변수명 이름 규칙

        1.C++ 에서 사용하는 키워드들은 변수명으로 사용할 수 없다.
        int float = 3;(x)

        2.알파벳, 숫자, _로만 구성할 수 있다.
        int num = 3;
            1) 숫자로 변수명을 시작 할수는 없다.
                int 2customer_count=200 ; (x)
    
        3. 대/소문자 구분을 한다.
               int My_age = 10;
               int my_age = 10;    
        4. 변수명 사이에 띄어쓰기를 넣을수 없다.
            int my age = 10;
        5. 전부 소문자로 작성한다. (일부 카멜기법)
        6. 축약어를 쓰지 않는다. -> int n =3;(x)

        헝가리안 표기법, 카멜표기법

        오늘의 과제 
        1. 자기 자신을 분석해서
        2. 여러가지 타입의 변수로 정의한다.
        
        총 20개 정의를 해서 변수명을 지어보고 테이터 타입을 지정해서 정하기

        예) 이름 : ...
            나이 : ...
            키 : ...
            혈액형 : ...
            mbti : ...

            

    */

    int num = 3;
    int customer_count=100 ;
    int customer_count1=200 ;
    //int 2customer_count=200 ;
    int _num = 5;// 언더바로 시작 가능 
    int my_age = 10;
    int My_age = 10; //대소문자로도 다른 변수로 구분 됨

    //int my age = 10; (x)

    //변수의 값을 설정 안해도됨 =>  string name1; (자바도 동일)
    string name1 = ""; //string name1;
    string name2 = ""; //string name2;
    int age = 0; // int age;

    cout << "상대방 이름을 입력하세요.\n";
    std::cin >> name1;
    cout << "본인의 이름을 입력하세요.\n";
    std::cin >> name2;
    cout << "상대방 나이를 입력하세요.\n";
    std::cin >> age;

    cout << name2 << " : " << name1 << "님의 " <<  age << "살 생일을 축하합니다.\n";
    
    // 배열 기반으 문자열 입출력

    char name[100]; //char 배열
    char lang[200];

    cout << "이름은 무엇입니까?";
    cin >> name;
    
    cout << "좋아하는 프로그래밍 언어는 무엇입니까?";
    cin >> lang;

    cout << "내 이름은 " << name << "입니다." << endl;
    cout << "제일 좋아하는 언어는 " << lang << "입니다." << endl;

    /*
       연산자
       데이터를 가공(연산)하는 모든 명령에 필요한 것들
       1) 어떤 종류의 연산자들이 있는지?
       2) 우선 순위 : 어떤 순서로 연산이 진행되는지?
       3) 결합 순서 : 좌측부터 연산하는 연산자, 우측부터 연산하는 연산자

       1. 사칙연산 : 산술연산자(좌측부터 연산)
       + : 더하기
       - : 빼기
       * : 곱하기
       / : 나누기  11/3 => 3
       % : 나머지구하기 11%3 => 2
       *,/,% > +,-
       
       2. 대입 연산자 (우측부터 연산)
       = : 왼쪽 항에 오른쪽 항의 값을 대입한다.(복사한다.)

       3. 복합 대입 연산자
       += :  a += b; => a = a + b;
       -= :  a -= b; => a = a - b;
       *= :  a *= b; => a = a * b;
       /= :  a /= b; => a = a / b;
       %= :  a %= b; => a = a % b; (a와 b는 정수형타입이어야한다.)

       4. 증감 연산자
       특정 변수의 값을 1씩 증가시키거나 감소시킬 때 사용한다.
       변수의 앞이나 뒤에 ++ / -- 를 붙여서 사용한다.

       5. 관계연산자
       두 값을 비교한 결과가 참(1,true)인지 거짓인지(0,false)인지 반환하는 연산자

       < : a < b : 왼쪽 항의 값이 오른쪽 항의 값보다 작으면 참을 반환한다.
       > : a > b : 왼쪽 항의 값이 오른쪽 항의 값보다 크면 참을 반환한다.
       <= : a <= b : 왼쪽 항의 값이 오른쪽 항의 값보다 작거나 같으면 참을 반환한다.
       >= : a >= b : 왼쪽 항의 값이 오른쪽 항의 값보다 크거나 같으면 참을 반환한다.
       == : 왼쪽 항의 값과 오른쪽 항의 값이 같을때, 참을 반환한다.
       != : 왼쪽 항의 값과 오른쪽 항의 값이 다를때, 참을 반환한다.
       
   */

    /*
        실습. 
        고객의 나이를 입력받아서 미성년자(19세 이하)이면 true
        성인이면 false를 출력.

        아까 입력 받은 나이를 기준으로, 주민등록증 발급대상(20살)이면 true를 아니면,false를 출력

        + )입력 받은 나이가 아홉수(1의 자리가 9인수) 인지 확인해서 true,false를 출력
    
        int customer_age2;
        cout << "고객의 나이를 입력하세요.";
        cin >> customer_age2;
        cout << boolalpha;
        cout << "고객님은 미성년자가 " << (customer_age2 <= 19) << "입니다." << endl;
        cout << "고객님은 주민등록발급대상 " << (customer_age2 == 20) << "입니다" << endl;
        cout << "고객님은 아홉수 " << ((customer_age2 % 10) == 9) << "입니다" << endl;

    */


    int left_value = 14;
    int right_value = 3;

    // ++가 뒤에 있으면 실행문이 종료가 되어야 값이 변한다.
    // 
    //left_value++; //15
    cout << left_value++ << endl; // 출력 : 14, 메모리 : 15 (출력된후 메모리에 +1 저장됨)
    //++left_value; //16 
    cout << ++left_value << endl; // 출력 : 16, 메모리 : 16 
 
    cout << left_value-- << endl; // 출력 : 16, 메모리 : 15
    cout << --left_value << endl; // 출력 : 14, 메모리 : 14


    cout << "+ : " << left_value + right_value << endl;
    cout << "- : " << left_value - right_value << endl;
    cout << "* : " << left_value * right_value << endl;
    cout << "/ : " << left_value / right_value << endl;
    cout << "% : " << left_value % right_value << endl;

    //left_value = left_value + right_value; or left_value += right_value;
    //cout << "+= : " << left_value << endl;

    // 복합 대입 연산자 () 괄호 사용해야한다. 
    //=> cout은 함수로써 함수의 인자를 표현하려면
    //계산을 해야하는데 계산을 하려면 ()괄호 표현해야한다 => () 에서 모든 연산 끝남
    cout << "+= : " << (left_value += right_value) << endl;
    cout << "-= : " << (left_value -= right_value) << endl;
    cout << "*= : " << (left_value *= right_value) << endl;
    cout << "/= : " << (left_value /= right_value) << endl;
    cout << "%= : " << (left_value %= right_value) << endl;

    int customer_age = 0;
    //실습1.
    cout << "고객님 나이를 입력해 주세요." << endl;
    cin >> customer_age;
    if (customer_age < 19) {
        cout << "true" << endl;
        if (customer_age == 20) {
            cout << "true" << endl;
        }
        else {
            cout << "false" << endl;
        }
    }
    else {
        cout << "false" << endl;
    }

    if (customer_age % 10 == 9) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
        
    }
    
    //boolalpha 사용시 판단 true, false 로 나온다.
    bool ageTest = customer_age >= 19;
    cout << boolalpha << ageTest << endl; //cout << boolalpha << (customer_age >= 19) << endl;
    
    int num99 = 0;
    //구구단 5단 만들기
    cout << "구구단을 계산할 단을 알려주세요." << endl;
    cin >> num99;
    
    for (int i = 0; i < 10; i++) {
        cout << num99 << " x " << i << " = " << num99 * i << endl;
    }


    //급여 계산
    int sale_price = 0;
    cout << "판매 금액 : " << endl;
    cin >> sale_price;
    cout << "급여 : " << (50 + sale_price * 0.12) << endl;







}
