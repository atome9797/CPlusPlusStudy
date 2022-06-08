#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int hansu(int num){
	
	int count = 0;
	//각 자리의 공차가 같아야 하는 문제
		
	//1부터 시작
	for (int i = 1; i <= num; i++)
	{
		int testp = i;

		int num1 = testp % 10; //1의 자리수
		testp = testp / 10;
		int num2 = testp % 10; //10의 자리수
		testp = testp / 10;
		int num3 = testp % 10; //100의 자리수
		testp = testp / 10;
		int num4 = testp % 10; //1000의 자리수
		

		//10의 자리수에 1을 더한값이 1의 자리수이면 공차임
		for (int j = 0; j <= 9; j++)
		{
			
			
			if (num3 > 0 && ((num3 + j == num2 && num2 + j == num1) || (num1 + j == num2 && num2 + j == num3))) {
			
				count++;
				printf("공차 : %d\n", j);
				printf("100의 자리수 : %d\n", num3);
				printf("10의 자리수 : %d\n", num2);
				printf("1의 자리수 : %d\n", num1);

			}
			else if (num4 == 0 && num3 == 0 && num2 >= 0 && (num2 + j == num1 || num1 + j == num2)) {
				count++;
				printf("공차 : %d\n", j);
				printf("10의 자리수 : %d\n", num2);
				printf("1의 자리수 : %d\n", num1);
			}

		}
	}

	return count;
}

int hansu2(int num) {
	int check = 0;
	//전 자리값과 비교하여 공차의 값과 비교
	for (int i = 0; i < 9; i++)
	{
		int num2 = 0;
		int num1 = 0;
		int tempt = num;
		while (tempt > 0) {
			num2 = num1;
			num1 = tempt % 10;
			if (num2 + i == num1 || num1 + i == num2) {
				//printf("공차 : %d\n", i);
				//printf("100의 자리수 : %d\n", num1);
				//printf("10의 자리수 : %d\n", num2);
				check = 1;
			}
			else {
				check = 0;
			}
			tempt = tempt / 10;
			//printf("카운트 : %d\n", count);

		}
		
		if (check == 1) {
			return 1;
		}
	}
	

	//true일때 1넘김
	return 0;
}

int sum(int A, int B, int C) {
	int count2 = 0;
	while (1) {
		if (B < C) {
			if (A / (C - B) <  count2) {
				break;
			}
		}
		else {
			count2 = -1;
			break;
		}
		count2++;
	}
	return count2;
}

int roadResult(int num) {
	
	int result = 0;
	int count = 1;
	int count2 = 2;
	int count3 = 1;
	for (int i = 1; i <= 1000000000; i++)
	{
		if (i == count2) {
			count += 1;
			count2 = 6 * count3 + i;
			count3 += 1;
		}

		if (num == i) {
			return count;
		}
	}

	return result;
}

int main() {
	
	//int check = 0;
	//int a = 0;
	//int arr[1001];
	//int count = 0;
	//printf("입력 : ");
	//scanf("%d", &a);

	//for (int i = 1; i <= a; i++)
	//{
	//	check = hansu2(a);
	//	if (check == 1) {
	//		arr[a] = 1;
	//	}
	//}

	//for (int i = 0; i < 1001; i++)
	//{
	//	if (arr[i] == 1) {
	//		count++;
	//	}
	//}

	//printf("%d", count);



	int A = 0;
	int B = 0;
	int C = 0;
	//scanf("%d %d %d", &A, &B, &C);

	//int result = sum(A, B, C);

	//printf("%d\n", result);


	int num = 0;
	scanf("%d", &num);
	int road = roadResult(num);
	printf("길찾기 :%d", road);

	return 0;
}
