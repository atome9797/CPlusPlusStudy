#include <iostream>  // iostream ������ �ҷ��� ���� ����Ҽ� �ְ� ����
#include <string>

using namespace std;

int main()
{
    int star_num = 10;
    cout << "�� ��� 1)" << endl;
    for (int i = 0; i < star_num; i++) {
        for (int j = 0; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }


    //0 10/ 0 9 / 0 8 / 0 7 ... 0 0
    //1 10/ 0 9 / 0 8 .....     0 1 => 00 ������ �������� * �� �ϳ� ���� 
    int star_num2 = 10;
    cout << "�� ��� 3)" << endl;
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
    //10 10  -> 1�� *
    //9 1/9  2/9 3 ..... 9 9 -> 10�ڸ� ���� ����
    //10 9/ 9 9 -> 2�� *
    cout << "�� ��� 2)" << endl;
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
    //0 1 => j�� 1 ���� ����̶� "-"�� ��¸���
    //0 10/0 9/0 8/0 7.... 0 0 => "*" ���
    //1 0/1 1 =======> "-" ���
    //1 10/1 9/1 8 ....1 1 => "*" 0������ ���ϰ� ���
    cout << "�� ��� 4)" << endl;
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
    //10 0/10 1/10 2 ... 10 9 => "-" ���
    //10 
    //10 1/10 2....... 10 10 => "-"���
    cout << "�� ��� 5)" << endl;
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

        cout << endl;
    }


    /*
        *******
        -*****-
        --***--
        ---*---
    */

    //
    cout << "�� ��� 6)" << endl;
    int star_num6 = 10;
    for (int i = 0; i < star_num6; i++) {
        for (int j = 1; j <= i; j++) {
            cout << " ";
        }

        for (int j = star_num6; j > i; j--) {
            cout << "*";
        }
        for (int j = star_num6 - 1; j > i; j--) {
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


    cout << "�� ��� 7)" << endl;
    int star_num7 = 11;
    int star_num8 = 11;

    for (int i = star_num7; i > 0; i--) {
        for (int j = 0; j <= i - 2; j++) {
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
}