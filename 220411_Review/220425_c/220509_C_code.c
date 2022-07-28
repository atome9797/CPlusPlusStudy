#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void strcpy2(char* str, char * str2) {
	
	if (*str2 == '\0') {
		return ;
	}
	*str = *str2;

	strcpy2(++str, ++str2);
}



//프렐탈과 똑같은 문제임
char* strstr4(char* str, char* str2) {


	//2중 for문을 재귀 함수로
	
	return NULL;

}


char* strstr3(char* str, char* str2) {


	int count = 0;
	while (*str != '\0') {
		char* temp1 = str;
		char* temp2 = str2;
		if (*temp1 == *temp2) {
			while (*temp2 != '\0') {
				count++;
				if (*temp2 != *temp1) {
					count = 0;
					break;
				}
				++temp1;
				++temp2;

			}
		}

		if (count != 0) {
			return str;
		}

		++str;
	}

	return NULL;

}

void practal(int n, int k, int j) {
	if (n == 0) {
		putchar('*');
		return;
	}

	if ((k / n) % 3 == 1 && (j / n) % 3 == 1) {
		putchar(' ');
	}
	else {
		practal(n / 3, k, j);
	}
}

int N;

void CountHanoi(int count, int s, int m, int e)
{
	if (count == 1)
	{
		++N;

		return;
	}

	CountHanoi(count - 1, s, e, m);
	CountHanoi(1, s, m, e);
	CountHanoi(count - 1, m, s, e);
}

// 반환값 : 수행 횟수
int CountHanoi2(int count, int s, int m, int e)
{
	if (count == 1)
	{
		return 1;
	}


	int result = 0;
	result += CountHanoi2(count - 1, s, e, m);
	result += CountHanoi2(1, s, m, e);
	result += CountHanoi2(count - 1, m, s, e);

	return result;
}

void PrintHanoi(int count, int s, int m, int e)
{
	if (count == 1)
	{
		printf("%d %d\n", s, e);

		return;
	}

	PrintHanoi(count - 1, s, e, m);
	PrintHanoi(1, s, m, e);
	PrintHanoi(count - 1, m, s, e);
}


int main() {
	
	printf("asdasd\n");

	char test_ch301[20]="";
	char origin2[]="BlockDMask";
	strcpy2(test_ch301, origin2);
	printf("%s\n", test_ch301);


	char str201[] = "smart man";
	char str202[] = "art";
	char* ptr103 = strstr3(str201, str202);
	printf("%s\n", ptr103);

	int input_num = 0;
	//scanf("%d", &input_num);

	/*for (int i = 0; i < input_num; i++) {
		for (int j = 0; j < input_num; j++) {
			practal(input_num, i, j);
		}
		puts("");
	}*/


	int n;
	scanf_s("%d", &n);

	CountHanoi(n, 1, 2, 3);
	printf("%d\n", N);
	PrintHanoi(n, 1, 2, 3);


	return 0;
}