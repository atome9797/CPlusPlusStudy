#define _CRT_SECURE_NO_WARNINGS    // strcat 보안 경고로 인한 컴파일 에러
#include <stdio.h>
#include <string.h> // strcpy 함수가 선언된 헤더 파일
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일
#include <stdbool.h>
#include <math.h>
#include <stddef.h>

#pragma region 구조체선언
struct Person {//구조체 명은 태그라 한다

    char name[20];
    int age;
    char address[100];

} p1; //전역변수로 구조체 변수선언 : 어떤 함수에도 속하지 않은 변수를 전역 변수라함


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
    int* numPtr123;//구조체 안에서 포인터를 받음
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

struct Phone {    // 휴대전화 구조체
    int areacode;                 // 국가번호
    unsigned long long number;    // 휴대전화 번호
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

struct Vector3 { //3차원 벡터 좌표
    union { //익명공용체 12바이트
        struct { //익명구조체
            float x; //x좌표
            float y; //y좌표
            float z; //z좌표
        };
        float v[3]; //좌표 배열로 저장
    };
};

//비트 필드 설정 : unsigned 자료형에 주로 사용 + 실수 자료형은 사용 못함
struct Flags {
    unsigned int a : 1; //a는 1비트 크기
    unsigned int b : 3; //b는 3비트 크기
    unsigned int c : 7; //c는 7비트 크기
};

//비트필드와 공용체 함께 사용하기
struct Flags2 {
    union {
        struct {
            unsigned short a : 3;
            unsigned short b : 2;
            unsigned short c : 7;
            unsigned short d : 4;
        };
        unsigned short e; //도합 16비트와 메모리 맞춤
    };
};

#pragma endregion

#pragma region typedef선언 

    // 예제
typedef struct _Point3D {
    float x;
    float y;
    float z;
} Point3D;

    //typedef : 형식을 정의하는 클래스 : 자료형에 별칭을 부여하고 선언
typedef int MYINT; //int형의 별칭 선언
typedef int *PMYINT;//포인터의 별칭 선언

    //typedef 구조체 태그명 생략가능
typedef struct {
    char name[20];
    int age;
    char address[100];
    char asd;
} User;



#pragma endregion

#pragma region 공용체선언

union Box {
    short candy; //2바이트
    float snack; //4바이트
    char doll[8]; //8바이트
};

union uData {
    char c1;
    short num1;
    int num2;
};

//익명의 공용체 선언
typedef union { 
    short candy;
    float snack;
    char doll[8];
} Box2;//별칭 지정

Box2 bx2;//별칭으로 공용체 변수 선언


//공용체 정의와 동시에 변수 선언
union Box3 {
    short candy;
    float snack;
    char doll[8];
} b2;


#pragma endregion


int main()
{

#pragma region 공용체

    // 메모리 공간을 절약할수 있다.
    //공용체 사용하기 => 멤버 저장 방식이 구조체와 다름
    union Box b1;
    printf("%d\n", sizeof(b1)); //공용체는 가장큰 자료형 크기로 설정됨 (서로 다른 자료형이 동일한 데이터 기억장소를 서로 공유)

    strcpy(b1.doll, "bear");
    b1.candy = 1;
    b1.snack = 1.3;

    //공용체는 데이터 기억 장소를 공유하기 때문에 값을 하나만 할당 할 수 있고, 
    //나머지 값들은 엉망이 되어 출력됨 => 한번씩만 쓰면 정상적으로 사용할수 있다.
    printf("%d\n", b1.candy);  
    printf("%f\n", b1.snack);  
    printf("%s\n", b1.doll);

    
    //한번씩만 사용하면 정상적으로 사용가능
    strcpy(b1.doll, "bear");
    printf("공용체 : %s\n", b1.doll);
    b1.candy = 1;
    printf("공용체 : %d\n", b1.candy);  
    b1.snack = 1.3;
    printf("공용체 : %f\n", b1.snack);  
    

    //공용체와 엔디언
    union uData udt;// 공용체 선언

    udt.num2 = 0x12345678;//리틀 엔디언 방식으로 메모리 설정 => 78 56 34 12 메모리 순 (4가지로 4바이트)
    printf("0x%x\n", udt.num2); //4바이트 전체값 출력  
    printf("0x%x\n", udt.num1); //2바이트 출력 => 78 56 앞 2개만 출력됨 (리틀 엔디언은 78이 낮은 자리수임)
    printf("0x%x\n", udt.c1); //1바이트 출력 => 78 앞 1개만 출력됨

    printf("%d\n", sizeof(udt));//가장큰 메모리값 int형 4바이트 가짐


    //공용체 포인터를 선언하고 메모리 할당하기
    //공용체의 별칭으로 변수 선언했으므로 , 변수에서 직접 공용체에 접근가능
    bx2.candy;

    //포인터에 선언 => 공용체 용량은 8바이트임 
    union Box *bxp = malloc(sizeof(union Box));
    printf("%d\n", sizeof(union Box));

    bxp->snack = 1.3f;
    strcpy(bxp->doll, "bear"); //마지막에 대입된 값으로 공용체 타입및 값이 바뀜
    
    printf("%d\n", bxp->candy); 
    printf("%s\n", bxp->doll);
    printf("%f\n", bxp->snack); 
    
    free(bxp);


    //공용체 별칭과 익명 공용체 포인터에 메모리 할당하기
    //union Box bx10; //공용체 변수 선언
    //union Box *bxptr;//공용체 변수 포인터 선언
    //
    //bxptr = &bx10; //공용체 포인터에 공용체 할당
    //
    //strcpy(bxptr->doll, "bear");

    //printf("%d\n", bxptr->candy);
    //printf("%f\n", bxptr->snack);
    //printf("%s\n", bxptr->doll);

    //free(bxptr); => heap영역 초기화 할때 에러 발생


    //구조체 안에 구조체 선언
    struct Person3 psn;
    psn.phone.areacode = 82;
    psn.phone.number = 3045671234;
    printf("%d %llu\n", psn.phone.areacode, psn.phone.number);

    //선언과 동시에 초기화
    struct Person3 psn2 = { .name = "Andrew", .age = 25, {.areacode = 82, .number= 3045671234} };
    //선언과 동시에 초기화2
    struct Person3 psn3 = { "Andrew",25,{82,3045671234} };


    //구조체 안의 구조체에 메모리 할당하기
    //포인터에서 구조체의구조체로 값 할당
    struct Person3* psn4 = malloc(sizeof(struct Person3));
    psn4->phone.areacode = 83;
    psn4->phone.number = 3045671234;

    //포인터에서 구조체의 포인터로 값 할당
    struct Person4* psn5 = malloc(sizeof(struct Person4));
    psn5->phone->areacode = 83;
    psn5->phone->number = 3045671234;
    printf("포인터로 값 : %d %llu\n", psn5->phone->areacode, psn5->phone->number);

    free(psn5->phone);//포인터구조체안의 포인터를 초기화 시켜줌
    free(psn5);// 포인터 초기화


    //익명 구조체와 익명 공용체 활용하기
    struct Vector3 pos;

    for (int i = 0; i < 3; i++)
    {
        pos.v[i] = 1.0f;//익명 공용체, 익명구조체이기 때문에 .으로 들어가는거 없이 바로 사용가능
        //union이기 때문에 x,y,z에 값이 할당됨(같은 공간 공유 성질이용)
    }
    
    printf("%f %f %f\n", pos.x,pos.y,pos.z);//union으로 할당받음
    

    //구조체 비트 필드 사용하기 => 지정한 비트수 만큼만 저장됨(나머지 잘라냄)
    struct Flags f1;
    f1.a = 1; //1비트이므로 안잘림
    f1.b = 15; //3비트이므로 3비트자리 만큼만 잘려서 출력됨 111 =>7
    f1.c = 255; //7비트 자리까지만 잘려서 출력됨

    //비트 필드의 메모리는 작은 비트부터 나머지 비트들을 순서대로 배치함
    printf("%d", sizeof(struct Flags)); //4출력
    //멤버를 unsigned int로 선언했으므로 4출력됨

    //주의
    /*
        unsigned int a : 37;    // 컴파일 에러. unsigned int보다 큰 비트 수는 지정할수 없음
    */


    //비트필드와 공용체 함께 사용하기
    struct Flags2 f2 = { 0, };//구조체 초기화
    f2.a = 4; //4비트 까지이므로 안잘림 0000 0100
    f2.b = 2; //안잘림 0000 0010
    f2.c = 80;//안잘림 0101 0000
    f2.d = 15;//0000 1111

    //%u는 부호없는 정수에서 사용
    printf("%u\n", f2.e); 
    //1111 1010000 10 100 => 비트순서대로 배치하기 때문에 해당 2진수를 10진수로 바꾸면 64020됨
    


#pragma endregion

    printf("=============공용체 end ==========\n");

#pragma region 구조체

    /*
        struct 태그 {
            자료형 멤버이름;
        };

        typedef struct 태그 {
            자료형 멤버이름;
        } 타입이름;
    */
    
    //struct Person p1; //구조체명(태그) 과 구조체 변수선언 => 전역변수를 선언하면 따로 선언할 필요없음
    strcpy(p1.name, "홍길동");//문자열 넣어줌
    p1.age = 30;
    strcpy(p1.address, "서울시 광진구");

    printf("이름 : %s\n", p1.name);
    printf("나이 : %d\n", p1.age);
    printf("주소 : %s\n", p1.address);

    
    //구조체 변수 선언과 동시에 초기화 하기
    struct Person p2 = { "김영훈",27,"서울시 용산구" };

    //별칭으로 선언
    test t1;
    strcpy(t1.name, "김영훈");
    t1.age = 30;
    strcpy(t1.address, "제주특별시");

    printf("이름 : %s\n", t1.name);
    printf("나이 : %d\n", t1.age);
    printf("주소 : %s\n", t1.address);


    //typedef

    MYINT numMY; //별칭에서 변수 선언
    PMYINT numPtrMY; //별칭에서 변수 선언

    numPtrMY = &numMY;

    //2중 포인터로 선언
    PMYINT* numPtrMY2; //2중포인터 됨


    User ip;
    strcpy(ip.name, "김영훈");
    ip.age = 27;
    strcpy(ip.address, "경기도");
    //strcpy(ip.asd, "a"); => 문자열을 받을수 없어서 안됨
    ip.asd = 'a';
    printf("문자 : %c\n", ip.asd);
    
    //포인터를 사용해야 하는 이유
    /*
        변수 접근이 용이 상수가 아니라 값을 변화시키는데 용이
        메모리 절약가능
    */


    printf("구조체 공간 : %d\n", sizeof(struct Person_test)); //구조체 공간은 구조체안의 변수의 데이터 공간만큼 할당됨

    //구조체의 포인터 생성
    struct Person_test* pt1 = malloc(sizeof(struct Person_test));

    //화살표 연산자로 구조체 멤버 접근 한다. 
    strcpy(pt1->name, "김영훈");
    pt1->age = 26;
    strcpy(pt1->address, "서울특별시");
    //strcpy((*pt1).address, "서울특별시"); 화살표 연산자 대신 .으로도 표현 가능하다.
    //pointer to struct Person_test 에서 pointer to 가 (*pt1) 로 제거되서 표현 가능해짐
    
    printf("%s\n", pt1->name);
    printf("%d\n", pt1->age);
    printf("%s\n", pt1->address);

    free(pt1);


    int num100 = 10;
    struct Data dt; //구조체 변수 선언
    struct Data* dt2 = malloc(sizeof(struct Data)); //구조체메모리공간을 포인터로 받기
    
    dt.numPtr123 = &num100; //int 메모리 주소값을 구조체의 int형 변수에 대입
    dt2->numPtr123 = &num100; //구조체의 포인터변수에 int형 변수를 할당
    
    printf("구조체 변수 주소 : %d\n", *dt.numPtr123);//포인터가 아니더라도 주소값을 할당해주면 역참조시 값을 가져올수있다.
    printf("구조체 포인터변수에 int주소 할당값 : %d\n", *dt2->numPtr123);//값 잘나옴

    dt2->c123 = 'a';
    printf("%c\n",(* dt2).c123);
    printf("%d\n", *(*dt2).numPtr123);//포인터 구조체에서 포인터를 찾아 가져옴
    printf("%d\n", *dt2->numPtr123);//포인터 구조체에서 역참조해, 구조체를 가져온뒤 구조체의 포인터를 역참조해 값을 불러온다.

    free(dt2);

    //포인터는 주소값에 접근 하는것으로 역참조는주소값을 거슬러 올라가 값을 출력 해주는 역할을 한다.
    //int *ptr = &abc; 라는 값이 있을때 int adc의 주소를 참조한 포인터로써 주소값을 가지고 있지만 
    //int abd = 10이라는 값을 가지고 있다면  포인터 ptr은 int abc를 역추적해서 값 10 을 불러온다.

    /*
        결론 : *(*dt2).numPtr123)는 dt2 포인터로 역추적하고, 구조체의 포인터로 *으로 역추적해서 포인터의 값을 불러온다.
    */

    //구조체 포인터에 구조체 변수 할당
    struct Person_test pt100;
    struct Person_test* pt200;
    
    pt200 = &pt100; //포인터 구조체에 구조체 할당
    pt200->age = 30;
    printf("나이 : %d\n", pt200->age);
    printf("나이 : %d\n", (* pt200).age); //포인터 역추적후 구조체에 접근


    Point3D* p1 = malloc(sizeof(Point3D));
    
    p1->x = 10.0f;
    p1->y = 20.0f;
    p1->z = 30.0f;

    free(p1);

    char asd[10] = "asdasd";


    //두점 사이의 거리 구하기
    struct Point2D p2d1; //구조체 1
    struct Point2D p2d2; //구조체 2
    
    p2d1.x = 30;//구조체 1의 x값
    p2d1.y = 20;//구조체 1의 y값
    
    p2d2.x = 60;//구조체 2의 x값
    p2d2.y = 50;//구조체 2의 y값

    printf("p2d1 : %d %d\n", p2d1.x, p2d1.y);
    printf("p2d2 : %d %d\n", p2d2.x, p2d2.y);

    //피타고라스 이용 c^2 = a^2+d^2
    int numa = p2d2.x - p2d1.x; //x좌표의 거리 구하기
    int numb = p2d2.y - p2d1.y;// y좌표 거리 구하기

    //제곱근 함수 sqrt 사용 => 4의 제곱근은 2, -2 => 음수의 제곱근은 sqrt(-d) 로 사용한다.
    double numc = sqrt((numa* numa) + (numb*numb));
    //double numc = sqrt(pow(numa,2) + pow(numb,2)); 
    //pow 함수를 이용하여, 제곱을 할수도 있다.
    printf("%f\n", numc);

    //절댓값을 구할때 사용
    int negative_number = abs(-10);
    float negative_number2 = fabs(-10.459);
    float negative_number3 = fabsf(-16.364);

    printf("절댓값 : %d\n", negative_number);
    printf("절댓값2 : %.3f\n", negative_number2);
    printf("절댓값3 : %.3f\n", negative_number3);


    //사각형 넓이 구하기 예제1
    struct Rectangle rect;
    int area;

    rect.x1 = 20; //a점
    rect.y1 = 20;//a점
    rect.x2 = 40;//b점
    rect.y2 = 30;//b점
    
    area = abs(rect.x1 - rect.x2) * abs(rect.y1 - rect.y2);
    
    
    //구조체 크기 
    struct PacketHeader header;
    printf("%d\n", sizeof(header.flags)); //1바이트 나옴
    printf("%d\n", sizeof(header.seq));//4바이트 나옴
    printf("%d\n", sizeof(header));//8바이트 나옴 => 왜냐하면 구조체는 가장큰 자료형의 크기의 배수로 정렬함
    //5바이트중 남은 3바이트 공간을 채워 주는데 , 이것을 패딩(padding)이라고 한다.
    printf("%d\n", sizeof(struct PacketHeader));

    //offsetof : 멤버의 메모리위치구하기
    printf("%d\n", offsetof(struct PacketHeader, flags));//메모리 0바이트위치 시작
    printf("%d\n", offsetof(struct PacketHeader, seq)); //메모리 4바이트 위치에서 시작


    dt.c123 = 'c';
    dt.numPtr123 = 40; //구조체 안의 포인터에 int 형 주소와 값을 부여

    //구조체 메모리 0으로 설정
    struct Data data = { 0, };//구조체 변수의 내용 모두 0으로 초기화(malloc에는 사용불가)
    //memset을 이용하여 메모리 0으로 설정
    memset(&data, 0, sizeof(struct Data));
    printf("메모리 초기화 1 %c %d\n", data.c123, data.numPtr123);
    //구조체 포인터 메모리 0으로 설정
    struct Data* data2 = malloc(sizeof(struct Data));
    memset(data2, 0, sizeof(struct Data)); //포인터를 구조체 크기만큼 0으로 초기화
    printf("메모리 초기화 2 %c %d\n", data2->c123, data2->numPtr123);
    free(data2);


    //구조체 메모리 활용하기
    struct Point2D pt2d;
    memset(&pt2d, 0, sizeof(struct Point2D));//구조체에 접근해서 구조체 0(null)으로 초기화 함
                                            //0비트는 null과 동일 (int형이면 0값 출력)
    printf("메모리 초기화 : %d %d\n", pt2d.x, pt2d.y);


    //포인터를 사용한 메모리 초기화
    struct Point2D* ppt2d = malloc(sizeof(struct Point2D));
    memset(ppt2d, 0, sizeof(struct Point2D));//포인터 구조체에 접근해(어차피 구조체와 동일) 구조체를 메모리 초기화
    printf("포인터 메모리 초기화 : %d %d\n", ppt2d->x, ppt2d->y);//포인터에서 구조체 접근하는법
    free(ppt2d);


    //구조체와 메모리 복사하기
    struct Point2D pt101;
    struct Point2D pt102;
    pt101.x = 10;
    pt101.y = 10;
    //목적지 , 원본 , 메모리크기
    memcpy(&pt102, &pt101, sizeof(struct Point2D));

    printf("복사 : %d %d \n", pt102.x, pt102.y);

    //포인터로 메모리 복사하기
    struct Point2D * pt103 = malloc(sizeof(struct Point2D));
    struct Point2D * pt104 = malloc(sizeof(struct Point2D));
    
    pt103->x = 10;
    pt103->y = 20;
    //목적지 , 원본 , 메모리크기
    memcpy(pt104, pt103, sizeof(struct Point2D));
    printf("포인터 복사 : %d %d\n", pt104->x, pt104->y);
    free(pt103);
    free(pt104);


    //구조체 배열 사용하기
    struct Point2D pt105[3];//구조체에 배열 붙여 사용
    pt105[0].x = 10;
    pt105[0].y = 20;
    pt105[1].x = 30;
    pt105[1].y = 40;
    pt105[2].x = 50;
    pt105[2].y = 60;
    
    printf("구조체 배열0 : %d %d\n", pt105[0].x, pt105[0].y);
    printf("구조체 배열1 : %d %d\n", pt105[1].x, pt105[1].y);
    printf("구조체 배열2 : %d %d\n", pt105[2].x, pt105[2].y);

    //구조체 배열 초기화
    //구조체 배열을 선언 하면서 초기화1
    struct Point2D pt106[3] = { {.x = 10,.y = 20}, {.x = 30,.y = 40},{.x = 50,.y = 60} };//인덱스 없이 사용
    
    printf("구조체 배열 초기화 0 : %d %d\n", pt106[0].x, pt106[0].y);
    printf("구조체 배열1 : %d %d\n", pt106[1].x, pt106[1].y);
    printf("구조체 배열2 : %d %d\n", pt106[2].x, pt106[2].y);

    //// 구조체 배열을 선언하면서 초기화2
    struct Point2D pt107[3] = {{10,20},{30,40},{50,60}};
    printf("구조체 배열 초기화 2 0 : %d %d\n", pt107[0].x, pt107[0].y);
    printf("구조체 배열1 : %d %d\n", pt107[1].x, pt107[1].y);
    printf("구조체 배열2 : %d %d\n", pt107[2].x, pt107[2].y);

    //// 구조체 배열을 선언하면서 0으로 초기화
    struct Point2D pt108[3] = { 0, }; 

    
    // 포인터 구조체 배열 선언하기
    struct Point2D* pt109[3]; //포인터 구조체 배열
    // 포인터 배열 사이즈 / 포인터 => 배열 크기 나옴
    for (int i = 0; i < sizeof(pt109)/sizeof(struct Point2D *); i++) {
        pt109[i] = malloc(sizeof(struct Point2D)); //포인터 구조체 배열에 구조체 대입
    }


    pt109[0]->x = 10;
    pt109[0]->y = 20;
    pt109[1]->x = 30;
    pt109[1]->y = 40;
    pt109[2]->x = 50;
    pt109[2]->y = 60;

    printf("======================\n");
    printf("포인터 구조체 배열 0: %d %d\n", pt109[0]->x, pt109[0]->y);
    printf("포인터 구조체 배열 1: %d %d\n", pt109[1]->x, pt109[1]->y);
    printf("포인터 구조체 배열 2: %d %d\n", pt109[2]->x, pt109[2]->y);


    for (int i = 0; i < sizeof(pt108)/sizeof(struct Point2D*); i++) {
        free(pt109[i]);
    }
    
    struct Person2* p100[5];
    int index = 0;
    for (int i = 0; i < sizeof(p100) / sizeof(struct Person*); i++) {
        p100[i] = malloc(sizeof(struct Person));
    }

    strcpy(p100[0]->name, "김영훈");
    p100[0]->age = 20;

    char strn[30] = "";
    int stri = 0;
    int stri2 = 0;
    //scanf("%s %d\n", &p100[0]->name, &p100[0]->age); //주소를 붙여야함(포인터 변수에 접근해서 화살표 연산자로 구조체에접근한다)

    printf("숫자 1 : %d\n", sizeof(p100) / sizeof(struct Person*));
    

    for (int i = 0; i < sizeof(p100) / sizeof(struct Person*); i++) {
        scanf("%s %d", &p100[i]->name, &p100[i]->age); //scanf에는 줄바꿈을 넣으면 안됨(오류남)
    }

    
    for (int i = 1; i < sizeof(p100) / sizeof(struct Person*); i++) {
        if (p100[i - 1]->age < p100[i]->age) {
            index = i;
        }
    }
    printf("%s\n", p100[index]->name);
    

#pragma endregion

    printf("========== 구조체 end ===========\n");

#pragma region 포인터와문자열 

    int num1 = 20;    // int형 변수 선언
    int* numPtr1;     // int형 포인터 선언

    numPtr1 = &num1;  // num1의 메모리 주소를 구하여 numPtr에 할당

    int* numPtr2;     // int형 포인터 선언

    numPtr2 = (int*)malloc(sizeof(int));    // int의 크기 4바이트만큼 동적 메모리 할당

    printf("%p\n", numPtr1);    // 006BFA60: 변수 num1의 메모리 주소 출력
                                // 컴퓨터마다, 실행할 때마다 달라짐

    printf("%p\n", numPtr2);     // 009659F0: 새로 할당된 메모리의 주소 출력
                                // 컴퓨터마다, 실행할 때마다 달라짐

    free(numPtr2);    // 동적으로 할당한 메모리 해제


    //strcat 포인터 붙이기
    char* s1 = "world";
    char* s2 = malloc(sizeof(char) * 20);

    strcpy(s2, "Hello");
    strcat(s2, s1);
    printf("%s\n", s2);


    //배열형태 문자열을 문자열 포인터에 복사하기
    char s1a[10] = "Hello";
    char* s1b = malloc(sizeof(char) * 10);
    
    strcpy(s1b, s1a);//s1a 의 문자열을 s1b에 복사 => 포인터에 문자열 들어감
    printf("%s\n", s1b); //Hello
    
    //동적 메모리 해제
    free(s1b);

    //예제1
    char s1c[40];

    scanf("%30s", s1c);

    strcat(s1c, "th");
    printf("%s\n", s1c);



    //배열에 문자열 만들기 sprintf
    char s1d[20]; //버퍼로 사용됨
    sprintf(s1d, "Hello ,%s", "world");
    printf("%s\n", s1d);
    
    char s1e[20];
    //sprintf(s1e, "Hello ,%s %d %f", "world",10,3.2f);
    //printf("%s\n", s1e);

    //문자열 포인터에 문자열 만들기
    char* s1f = malloc(sizeof(char) * 20); //버퍼로 사용됨
    sprintf(s1f, "Hello, %s", "world");
    printf("%s\n", s1f);
    free(s1f);
    
    char* s1g = malloc(sizeof(char) * 30);
    sprintf(s1g, "%c %d %f %e", 'a',10,3.4f,1.123456e-21);
    printf("%s\n", s1g);
    free(s1g);

    //strchr : 문자열 검색하기 : 문자열에서 특정문자로 검색해서 이후 문자열 출력
    char s1h[30] = "A Garden Diary";
    char* ptr = strchr(s1h, 'a'); 
    while (ptr != NULL)
    {
        printf("%s\n", ptr);
        ptr = strchr(ptr + 1, 'a'); //1번 ptr 문자열 뽑았으면 다음 해당 글자가 있는 지점 찾아서 출력
    }


    //strrchr : 오른쪽끝을 기준으로 문자열 검색하기 : 문자열에서 특정문자로 검색해서 이후 문자열 출력
    char s1j[30] = "A Garden Diary";
    char* ptrj = strrchr(s1j, 'a');
    
    //strstr :문자열 안에서 문자열 검색 : 해당 문자열이 있는곳 검색해서 이후 문자열 출력
    char s1k[30] = "A Garden Diary";
    char* ptrk = strstr(s1k, "den");
    printf("%s\n", ptrk);
    
    while (ptrk != NULL) {
        printf("%s\n", ptrk);
        ptrk = strstr(ptrk + 1, "den");
    }

    //예제
    char s1m[30] = "Alice in Wonderland";
    char* ptrm = strchr(s1m, 'n');
    
    //n자리에서 출력하면됨
    
    while (ptrm != NULL) {
        printf("%s\n", ptrm);
        ptrm = strchr(ptrm + 1, 'n');
    }


    printf("============== strtchr\n");
    char s1o[30] = "The Little Prince";
    char* ptro = strrchr(s1o , 'i');
    printf("%s\n", ptro);

    
    printf("================= 문자열\n");

    
    char v10[1001];
    printf("문자열을 입력하세요 :");
    //%[^\n] 사용시 오류 나면 한칸 띄어쓰기 해주기
    scanf(" %[^\n]",v10);
    
    
    char* ptr10 = strchr(v10, ' '); //문자열을 받기 때문에 문자열 포인터에 char v10[1001] 배열 주소 들어감
    int count = 0;
    while (ptr10 != NULL) {
        ptr10 = strchr(ptr10 + 1 , ' ');
        count++;
    }


    printf(" %d\n", count);


    //strtok : 문자열 자르기 => 포인터 이용하는 방식 (s100의 주소를 받음) 
    char s100[30] = "The Little Prince";
    char* ptr100 = strtok(s100, " "); //s100 배열중 띄어쓰기 부분까지 짤라서  포인터에 주소와 값 입력
    //토큰 [0][1][2] 


    while (ptr100 != NULL) {
        printf("%s\n", ptr100);
        ptr100 = strtok(NULL, " "); //NULL 을 넣어주면 버퍼에 있는 저장값의 다음 문자열을 불러옴
    } //=> 자르는 부분에 NULL 을 널어 줌으로 원본이 바뀌는것 주의



    char s1h50[30] = "A Garden Diary";
    char* ptr50 = strchr(s1h50, 'a');
    while (ptr50 != NULL)
    {
        printf("%s\n", ptr50);
        ptr50 = strchr(ptr50 + 1, 'a'); //1번 ptr 문자열 뽑았으면 다음 해당 글자가 있는 지점 찾아서 출력
    }


    //malloc 문자열 자르기
    char* s101 = malloc(sizeof(char*) * 30); //버퍼, 동적 메모리
    strcpy(s101, "The Little Prince");// 문자열값 복사해서 할당

    char* ptr101 = strtok(s101, " ");
    while (ptr101 != NULL)
    {
        printf("%s\n", ptr101);
        ptr101 = strtok(NULL, " "); //버퍼 값의 " "부분을 불러와 NULL로 채워줌
    }
    free(s101);


    //다양한 기준문자 지정해서 문자열 자르기
    char s102[30] = "2015-06-10T15:32:19";
    char* ptr102 = strtok(s102, "-T:");//기준문자 여러개 가능
    
    while (ptr102 != NULL)
    {
        printf("%s\n", ptr102);
        ptr102 = strtok(NULL, "-T:"); //버퍼 값의 "-T:"부분을 불러와 NULL로 채워줌
    }

    //자른 문자열 배열에 담고 출력하기
    char s103[30] = "The Little Prince";
    char* sArr103[10] = { NULL, };//배열 담을 저장소
    int i = 0;

    char* ptr103 = strtok(s103, " ");
    while (ptr103 != NULL)
    {
        sArr103[i] = ptr103;//토큰별로 자른 값을 넣어줌
        i++;
        ptr103 = strtok(NULL, " ");//띄어쓰기 자리에 null 넣어줌
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
        ptr104 = strtok(NULL, " "); //버퍼 안에 있는 " " 부분을 NULL로 변경함
    }


    char s105[100];
    printf("주소 입력 :");
    scanf("%s", s105);
    char* ptr105 = strtok(s105, ".");
    while (ptr105 != NULL) {
        printf("%s\n", ptr105);
        ptr105 = strtok(NULL, ".");
    }

    //문자열과 숫자를 서로 변환하기
    char* s106 = "283"; //문자열 주소 추가
    int num106;
    
    num106 = atoi(s106); //문자열을 정수로 변환
    printf("%d\n", num106);

    //특정 진법 문자열을 정수로표현
    char* s107 = "0xaf10";
    int num107;
    num107 = strtol(s107, NULL, 16);//16진수 문자열을 정수로 바꾸기 
    //=> strtol 함수에서 문자열 띄어쓰기 또는끝부분에 null 을 넣어 줌으로써 짤라서 출력하게 해줌
       
    printf("%x %d\n", num107, num107);//%x는 16진수로 표현  => af10 44816

    char* s108 = "0xaf10 42 0x27C 9952";
    int num108;
    int num109;
    int num110;
    int num111;
    char* end;

    num108 = strtol(s108, &end, 16); //s108 char 불러와 end주소에 16진수로 띄어쓰기까지 끊어서 넣어줌
    num109 = strtol(end, &end, 16); //42 0x27C 9952 불러와 end 주소에 16진수로 띄어쓰기까지 끊어서 넣어줌
    num110 = strtol(end, &end, 16); //0x27C 9952 불러와 띄어쓰기 까지 끊어서 end에 저장함
    num111 = strtol(end, NULL, 16); //9952 는 null 만나고 끝나고 마직막 end값을 num111에 저장함

    printf("%x\n", num108);
    printf("%d\n", num109);
    printf("%x\n", num110);
    printf("%d\n", num111);


    //문자열을 실수로 변환
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
    
    num113 = strtof(s113, &end113); //s113문자열을 띄어쓰기 부분에서 자른후 나머지값을 포인터에 대입
    num114 = strtof(end113, &end113); //포인터에 대입한 값에서 띄어쓰기 부분에서 자른후 나머지값을 다시 포인터에 대입
    num115 = strtof(end113, &end113);
    num116 = strtof(end113, NULL); //문자열의 NULL 만나면 종료

    printf("%f\n",num113);
    printf("%e\n",num114);
    printf("%f\n",num115);
    printf("%e\n",num116);

    //정수를 문자열로 변환하기
    char s117[10];
    int num117 = 283;
    sprintf(s117, "%d", num117); //정수를 문자열로 변환
    printf("%s\n", s117);
    sprintf(s117, "%x", num117); //정수를 문자열로 변환
    printf("%s\n", s117);
    sprintf(s117, "%X", num117); //정수를 문자열로 변환
    printf("%s\n", s117); //16진수 출력함

    //실수를 문자열로 변환
    char s118[10];
    float num118 = 38.972340f;
    sprintf(s118, "%f", num118);
    printf("%s\n", s118);
    
    //예제
    char* s119 = "0x1facefee";
    int num119;
    num119 = strtol(s119, NULL, 16); //첫인자 : NULL로 종결되는 부분을 포함하는 문자열 포인터, 두번째 인자 : 변환이 멈춘 문자열 포인터, 새번째 : 진수
    printf("0x%X\n", num119); //16진수로 출력

    //예제2 문자열을 실수로 변환
    char* s120 = "97.527824";
    float num120;
    num120 = atof(s120);
    printf("%f\n", num120);

    //예제2 문자열 실수로 변환
    char* s121 = "29.977213 4528.112305";
    float num121;
    float num122;
    char* end121;

    num121 = strtof(s121, &end121); //문자열을 문자 끊어지는데까지 받고 포인터에 나머지 넣기 그리고 float 에 받은값 담기
    num122 = strtof(end121, NULL); //문자열을 문자 끊어지는데까지 받고 NULL이면 끝내기 그리고 float 에 받은값 담기

    printf("%f\n", num121);
    printf("%f\n", num122);
    
    //예제3 숫자를 문자열로 변환하기
    char* s123[10];
    float num123 = 98.415237f;
    int num124 = 0x3fce1920;
    sprintf(s123, "%f 0x%x", num123, num124);

    printf("%s\n", s123);
    
    //예제 4 문자열 숫자로 변환하기
    char s125[50];
    int num125;
    int num126;
    float num127;
    char* end125;

    printf("문자열 숫자로 변환\n");
    scanf(" %[^\n]", s125);

    num125 = strtol(s125, &end125,16); //16 진수로 출력 
    num126 = strtol(end125, &end125,10); //10진수로 출력 
    num127 = strtof(end125, NULL); //실수형으로 출력
    printf("0x%x\n", num125);
    printf("%d\n", num126);
    printf("%f\n", num127);
    
    //정수,실수를 문자열로 변환
    char s128[10];
    char s129[10];
    int num128;
    float num129;

    scanf("%d %f", &num128, &num129); //포인터가 아닌 변수를 넣을때는 주소로 넣어줌

    sprintf(s128, "%d", num128);
    sprintf(s129, "%f", num129);

    printf("%s\n", s128);
    printf("%s\n", s129);

    //회문 판별과 n-gram 만들기
    char word1[30];
    int length1;
    bool isPalindrome1 = true;

    printf("단어를 입력하세요. :");
    scanf("%s", word1);
    
    length1 = strlen(word1);
    for (int i = 0; i < length1/2; i++) {
        if (word1[i] != word1[length1-1-i]) {//왼쪽 과 오른족이 같지 않으면
            isPalindrome1 = false;
            break; //회문이 아니므로 끝냄
        }
    }
    printf("%d\n", isPalindrome1);



#pragma endregion

    return 0;
}