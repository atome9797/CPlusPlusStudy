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
    
    

    
    
}
