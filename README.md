# CPlusPlusStudy

## 1. 연산자 

### 1) 출력 연산자 =>  <<
### 2) 입력 연산자 =>  >>  
</br>

## 2. std:: => <iostream> 라이브러리에 존재하는 표준클래스
- #include <iostream>으로 선언후 사용
- using namespace std 선언시 std:: 생략가능 ex) std::string helloText = "Hello World"; cout <<  sizeof(helloText) << endl;

## 3. std::cin, std::cout, std::endl
###  1) std::cin => 데이터를 입력 받을때 사용 ex) int num = 3; std::cin >> num; => 입력값을 새로 받는다 
### 2) std::cout => 결과값을 출력할때 사용 ex) std::cout << num << "hellon\n";
### 3) std::endl => 개행문자로 사용 ex) std::cout << num << std::endl; => \n

```
ex) 

#include <iostream>
using namespace std;

int main(){
 cout << "Hello World";
 return 0;
 }
 ```

## 4. 변수의 구성요소 
- 이름 : testNum 2) 데이터 크기 :  4btye 3) 메모리 주소 00000059686FFAD4 4) 값 2.8
- cout << &testNum << endl; // &사용시 메모리 주소나옴

## 5. 변수명 이름 규칙
### 1) 카멜기법, 파스칼 기법, 스네이크 기법, 헝가리안 기법 , 케밥 기법
 
## 6. 연산자 
### 1) 사칙 연산 

```  
  cout << "+ : " << left_value + right_value << endl;
  cout << "- : " << left_value - right_value << endl;
  cout << "* : " << left_value * right_value << endl;
  cout << "/ : " << left_value / right_value << endl;
  cout << "% : " << left_value % right_value << endl;
```

  
## 2) 대입 연산
 
```
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
```

## 3) 증감 연산자 
 
-   ++가 뒤에 있으면 실행문이 종료가 되어야 값이 변한다.

```  
   int left_value = 14;
   int right_value =3;
   
   cout << left_value++ << endl; // 출력 : 14, 메모리 : 15 (출력된후 메모리에 +1 저장됨)
   cout << ++left_value << endl; // 출력 : 16, 메모리 : 16 
 
   cout << left_value-- << endl; // 출력 : 16, 메모리 : 15
   cout << --left_value << endl; // 출력 : 14, 메모리 : 14
```   
   
## 4) 관계 연산자
-   두 값을 비교한 결과가 참(1,true)인지 거짓인지(0,false)인지 반환하는 연산자

###
       < : a < b : 왼쪽 항의 값이 오른쪽 항의 값보다 작으면 참을 반환한다.
       > : a > b : 왼쪽 항의 값이 오른쪽 항의 값보다 크면 참을 반환한다.
       <= : a <= b : 왼쪽 항의 값이 오른쪽 항의 값보다 작거나 같으면 참을 반환한다.
       >= : a >= b : 왼쪽 항의 값이 오른쪽 항의 값보다 크거나 같으면 참을 반환한다.
       == : 왼쪽 항의 값과 오른쪽 항의 값이 같을때, 참을 반환한다.
       != : 왼쪽 항의 값과 오른쪽 항의 값이 다를때, 참을 반환한다
###

```      
   int customer_age2;
   cout << "고객의 나이를 입력하세요.";
   cin >> customer_age2;
   cout << boolalpha;
   cout << "고객님은 미성년자가 " << (customer_age2 <= 19) << "입니다." << endl;
   cout << "고객님은 주민등록발급대상 " << (customer_age2 == 20) << "입니다" << endl;
   cout << "고객님은 아홉수 " << ((customer_age2 % 10) == 9) << "입니다" << endl;
```

## 5) 논리 연산자 
-   두 값을 비교해서 참과 거짓을 반환하는 연산자
###
        && : 논리 곱 (AND)
        a && b  :  a의 결과 값이 참이고, b의 결과값이 참이면 1을 반환

        || : 논리 합 (OR)
        a || b  :  a의 결과 값이 참이거나, b의 결과값이 참이면 1을 반환

        ! : 논리 부정(NOT)
        !a : a 의 결과값이 참이면 거짓을 반환, 거짓이면 참을 반환

###

    cout << !1 << endl; // 0이 출력
    cout << !0 << endl; // 1이 출력
    cout << !-300 << endl; // 0이 출력
###

##  6) 삼항 연산자
-  a ? b : c; a의 결과값이 참이면 b 실행문이 동작, 거짓이면 c실행문이 동작.
-    (10 < 5) ? cout << "10이 5보다 크다." << endl : cout << "10이 5보다 작다" << endl;
    
## 7) 난수
-   rand(); -> 랜덤 값 나옴 // 0 ~ 32767 사이의 랜덤한 값이 반환된다. 
        : 2 바이트의 최대 표현 범위에서 나옴 
        함수 내부에 seed값이 있어서 이 값에 의해서 리턴값이 정해진다.
        기본적으로 seed : 1로 세팅되어 있다.

-   srand(time(NULL)); => 컴퓨터는 난수를 출력할수 없다. 난수를 만드는 계산식만 표함하고 있기 때문에 시드속성을 부여해서, 난수를 만든다.
                         시드로는  "시간"을 부여한다.
   
```
   EX) 3 ~7 사이의 난수 값을 구하시오. 
        int ran_num;
        ran_num = 3 , 4, 5,6,7
                 0+3 , 1+3, 2+3, 3+3 , 4+3  => 0~4사이의 숫자 값이 나오게 하려면 나머지의 범위로 설정하면됨   
        srand(time(NULL));
        ran_num = rand() % 5 +3;     => rand() % (임의의 큰수 - 작은수 +1 )+ 작은수
   
```

##  8) 제어문

```
    1-1. 조건문 : if/switch
    1-2. 반복문 : while/for/do-while
 
 
    1-1) switch 
    
     switch (정수형 변수)
    {
        case 정수1: 실행문1; break;
        case 정수2: 실행문2; break;
        case -3: 실행문3; break;
        default :  실행문4; break;  //해당하는 조건값이 없을때 실행
    }
    
    1-2) while 반복문  
    
    while (조건식)  => 조건식에 true나 1을 넣으면 무한 반복 된다.
    {
        실행문;
        조건식을 바꾸는 실행문; // while문을 중단시키는 첫번째 방법

        if (조건식) break; // whlie문을 중단시키는 두번째 방법
    }
    
    ex) 난수값과 입력 값을 비교 하여, 같은 값이 나올때까지 입력 받기
    (1) 번 풀이
    int user_num =0;
    int ran_num =0; // 1~9 사이값
    srand(time(NULL));
    
    while(true){
      
      ran_num = rand() % 9 +1;
      cin >> user_num;
      
      if(user_num == ran_num){
        cout << "정답입니다." << endl;
        break;
      }
    }
    
    (2) 번 풀이
    int user_num =0;
    int ran_num =0; // 1~9 사이값
    srand(time(NULL));
    ran_num = rand() % 9 +1;
    
    while(user_num != ran_num){ => 값이 다를때만 입력 받기
      cin >> user_num;
      (user_num == ran_num) ? cout << "true" << endl : cout << "false" << endl;
    }
    
    (3) 번풀이
    do {
        cout << "while문 임의의 값 : " << endl;
        cin >> val_num;
        int val_num2 = rand() % 9 + 1;
        if (val_num == val_num2) {
            cout << "정답입니다." << endl;
            break;
        }
        
    } while (val_num != val_num2);
```    
    
    1-3) for문 반복문
    구구단 출력 문제, 별찍기 문제 참고 
    
    
## 9) 배열 

```   
        배열 (자료구조)
     같은 데이터 타입의 여러 변수를 하나의 묶음으로 나타낸 것.

     배열의 데이터 타입에 대한 동일한 크기로 메모리상에 연속된 공간이 할당된다.
     배열명이 메모리의 시작 주소이다.

     2차원 배열 및 다차원 배열
     : 배열이 (개념적으로) 2중으로, 다중으로 구성되어 있는 것.

     1차원 배열 : int student_nums[5]; //5개 int
      -> 5의 학생이 있다.
     2차원 배열 : int student_nums[3][10]; // 15개 int
      -> 3개의 반에 각각 5명의 학생이 있다.
     3차원 배열 : int student_nums[4][3][5]; -> 메모리 주소는 이어져 있다. // 60개 int
      -> 4개의 학년에 각각 3개 반이 존재 하고, 각 반에 5명의 학생이 있다.
```

     //입력 :
     int array_gugu[9][9];
     int dan = 0;
     int gob = 0;

     //처리 :
     for (int i = 1; i < 10; i++) {
      for (int j = 1; j <= 9; j++) {
       array_gugu[i-1][j-1] = i * j;//해당 자리에 맞게 들어감
      }
     }

     cout << "몇 단을 볼까요?" << endl;
     cin >> dan;
     cout << "몇을 곱할까요?" << endl;
     cin >> gob;

     cout << dan << " * " << gob << " = " << array_gugu[dan-1][gob-1] << endl;
 
```
```

## 10) _getch()
    
    (엔터 없이)문자 하나를 입력받는 방법
    
    char input_key_char = _getch();
	   cout << input_key_char << endl; //문자 값이 나옴  => 엔터 안해도됨
 
 
## 11) 구조체 
 
    변수 모아두는 "클래스"!!랑 비슷한 개념
	- 변수를 모아 놓은 집합체
	- 특정 변수들이 무언가의 하위개념으로 묶일수 있을때

	- studentName[10], studentAge[10] ....
	- '학생'의 땡땡땡
	- 이름, 나이, 국어 점수, 석차 등등을 '학생' 이라는 구조체로 묶어서 사용
	
###	1. 구조체를 정의하는 위치 : 구조체가 사용되는 함수의 앞에 구조체는 정의한다.
	(해당 함수의 바깥쪽 위)

###	2. 구조체 정의 방법
	struct 구조체 변수명 {
		구조체 안에  들어갈 하위 변수들
		(위의 예시에 따르면 이름,나이,국어점수, 석차 같은 애들이 하위 변수다.)
	};

	구조체는 일종의 우리가 새롭게 만든 테이터형
	
	구조체 안에 들어갈수 있는 하위 변수는 무엇이 있을까?
	: 당연히 int/bool/float 같은 기본 자료형들은 모두 사용가능
	string <- 클래스도 쓸수 있고

	3. 구조체의 선언과 초기화
	기본적으로 구조체 변수의 개념은 배열 변수의 개념과 동일
	int a [3] = {50,70,80};
	구조체 변수도 다음과 같이 선언과 동시에 초기화 할수 있다.
	
	
	//구조체 선언 score
	struct score{
		int kor;
		int eng;
		int math;
	};


	//구조체 선언 student
	struct student {
		string name;
		int age;
		string homeTown;
		char blood;
		int monthlyScore[12];
		score myScore;//구조체에 구조체로 선언 가능 -> !!! struct score myScore라고 해도됨 
	}seoyon, jeahyuk; //중괄호 끝에 세미콜론 사이에다 ,student의 변수를 미리 선언해 줄수 있다.
	
	int main(){
	
		student kimyounghoon; //구조체 변수 선언 => 변수명은 사용자가 지정 가능
		kimyounghoon.age = 27;
		kimyounghoon.name = "김영훈";
		kimyounghoon.homeTown = "서울";
		kimyounghoon.blood = 'A';

		//구조체에 변수명을 선언하고 java의  this 형태로 받은후 출력  
		//=> java는 this 의 변수명은 선언 하지 않았지만  구조체는 변수명을 선언하고 변수명의 변수명을 지정한다.

		//student 구조체를 이용해서 자기 자신의 정보를 입력하고 출력한다.
		cout << "제 이름은 " << kimyounghoon.name << "이고," << "혈액형은 "<< kimyounghoon.blood << "입니다. 나이는 " << kimyounghoon.age << "이고. 사는곳은" << kimyounghoon.homeTown << "입니다.";

		//구조체의 구조체 값을 가져와서 대입해준다. -> 상위를 지정하던지 아니면 하위에서 지정하든지 상관 없음
		kimyounghoon.myScore.eng = 79; 
		kimyounghoon.myScore.kor = 95;

		kimyounghoon.monthlyScore[0] = 80;
		kimyounghoon.monthlyScore[1] = 95;

		score myScore = { 50,80,90 }; //구조체 변수 선언 -> 상위 구조체 선언 안하고 사용할수있음
		cout << myScore.kor << myScore.eng << myScore.math << endl;


		//student seoyon;없이 진행 가능
		seoyon.name = "최서영"; //위에서 student 구조체에서 이름을 정의 했으므로  student 를 생략 가능하다

	}
