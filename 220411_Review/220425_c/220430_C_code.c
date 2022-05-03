#define _CRT_SECURE_NO_WARNINGS    // strcat ���� ���� ���� ������ ����
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

//


char* strstr3(char* str, char* str2) {
	
	int count = 0;

	char* temp2 = str;
	for (int i = 0; str[i] != '\0' ; i++)
	{
		if (str[i] == str2[0]) {//�ܾ� ���� ��ġ�� ������
			//char* temp = str;
			for (int j = 0; str2[j] != '\0'; j++)
			{
				if (str[i+j] == str2[j]) {
					//++temp;
					count += 1;
				}
				else {
					count = 0;
					break;
				}
			}
		}

		if (count != 0) {
			return temp2;
		}

		++temp2;
	}

	return NULL;
}


//�ش� ���ڿ��ڸ����� �����ְ� null�� �־���
char* strtok2(char str [], const char str2 []) {
	
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str2[0] == str[i]) { //ù ���ڿ��� ������ ����
			for (int j = 0; str2[j] != '\0'; j++)
			{
				//if () {
				//	
				//}
			}
		}
	}

	return 	str2;
}


//myprintf(1,2,3) => My Variadic Function : 1,2,3
//"My Variadic Function : ~"
void myprintf(int count, ...) {
	va_list args;//pointer to char��°� �˼��ִ�.
	va_start(args, count);
	printf("My Variadic Function :");
	for (int i = 0; i < count; i++)
	{
		int num = va_arg(args, int);
		printf(" %d, ", num);

	}
	va_end(args);
	printf("\n");
}



//����

/// <summary>
/// printf�� �����ϰ� �����ϳ� ����� ���ѵ�
/// %d %c %f %s
/// </summary>
/// <param name="format">���Ĺ��ڿ�</param>
/// <param name="">�������ڰ�</param>
void myprintf2(const char* format, ...);

void myprintf3(int a, int b, ...);

int main() {

	int arr[5][5];
	int arr2[5][4];

	int(*parr)[5] = arr;
	parr = arr2;

	//���ڿ� : stack�� �ִ°Ŷ� ����������
	char str[] = "Hello, world";
	//str = "HELLO"; => ���ڿ� ���ͷ� Ÿ���� const char * �̱� ������ �迭�� �Ҵ� ���Ѵ�.
	str[0] = 'x';
	
	//strcpy(str, "jee"); //���� �޸𸮶� �ȵ�
	printf("%s\n", str);


	//�����ʹ� data ���� �޸��̹Ƿ� ���� �Ұ�����
	char* str2 = "hello";
	//str2[0] = 'c';
	//strcpy(str2, "asd");
	printf("%s\n", str2);
	


	int num[] = { 1,2,3,4,5 };
	num[0] = 10; 
	
	char str100[] = "blockpaint";
	char str101[] = "paint";
	//char* ptr = strstr2(str100, str101);
	
	char str200[] = "BlockDMask. He is a smart man";

	char str300[] = "He";
	char* ptr100 = strstr(str200, str300);


	printf("%s\n", ptr100);


	//strstr
	char str201[] = "BlockDMask. He is a smart man";
	char str202[] = "art";
	char* ptr103 = strstr3(str201, str202);

	printf("%s\n", ptr103);

	int* numptr1000;


	//char* str1000 = "hello";
	//*(str1000 + 2) = 'x';
	//printf("%s", str1000);
	int ddd[] = { 1,2,3 };
	int* asdasd = ddd;
	asdasd[0] = 10;
	printf("%d\n", asdasd[0]);

	//chnum �迭�� �����޸𸮿� ����� ���ڿ��� 
	//stack���� �����ؼ� ����ϱ� ������, ���ڿ��� �����Ҽ� �ִ�.
	char chnum[] = "asdasdasd";
	char* ptrch = chnum;
	ptrch[0] = 'x';
	printf("%s\n", ptrch);



	//strtok
	char stok[] = "Block D Mask.";
	char* ptrtok = strtok(stok, "Ma");
	while (ptrtok != NULL)
	{
		printf("%s\n", ptrtok);
		ptrtok = strtok(NULL, "Ma");
	}
	

	
	/*char stok100[] = "Block D Mask.";
	char* ptrtok100 = strtok2(stok100, "Ma");
	while (ptrtok100 != NULL)
	{
		printf("%s\n", ptrtok100);
		ptrtok100 = strtok2(NULL, "Ma");
	}*/

	
	//1.Type : �����͸� �ؼ��ϴ� ���
	//2.memory : �����͸� �����ϴ� ����
	//3.object : �����͸� �����ϴ� ���� -> memory

	int a;
	a = 10; //�� �̰� �Ǵ� ���ϱ�?
	//�����ڴ� �ǿ����ڸ� �����Ѵ�.
	//a+b
	//a = b : �Ҵ� �����ڴ� �ǿ����ڰ� 2�� �ʿ��ϴ�.
	//�ǿ����ڿ� ���� => Ÿ��.
	//��� �����ڴ� �ǿ������� ����(Ÿ��)�� �ִ�.
	int* p;
	//p = 3.14; Ÿ���� �ٸ��� ������ �Ҵ� ����

	//a[b] = *(a+b);
	//1.�� a+b�� �ּҿ����ϱ�? => �ǿ������� Ÿ�� ������ �ּҿ����̶� �� �˰Ե�.
	//=> a�� Ÿ���� �������̰� b�� Ÿ���� int
	//2. *�����ڴ� ���� pointerŸ�Կ��� �����Ҽ� ���� => (a+b)Ÿ���� pointer
	//3. �������� ���� Ÿ����? pointer �� ����Ű�� �ִ� Ÿ��

	
	int arr3[2][3];
	*(*(arr3 + 2) + 3);
	arr3 + 2; //arr3 : int(*)[3];
			//�ּҿ��갡��


	//��������
	myprintf(1, 10);
	myprintf(2, 10 , 20);
	myprintf(3, 10,20,30);


	int test3 = 7;
	char test10 = test3 + '0';
	//printf("The value is :%c", test);
	putchar(test10);


	printf("\n");

	//��������2
	myprintf2("Hello My ptrinf : %d, %c , %s", 10, 'A', "Hello");
	//output : Hello My ptrinf : 10, A, 3.140000, Hello
	//printf ������� ���� => putchar ����Ұ� : ������ �� ������ �װ͸� �����

	myprintf3(3, 4, 10, 20, 30);


	return -4;
}


void myprintf3(int a, int b, ...) {
	va_list args;
	va_start(args, b);//������ġ ����
	for (int i = 0; i < 3; i++)
	{
		printf("�׽�Ʈ : %d\n", va_arg(args, int));
		//Ÿ���� �� ������ �����Ʈ ��ŭ �о�� �ϴ��� �˱����� ���
	}
	
	va_end(args);
}


void myprintf2(const char* format, ...) {
	
	//va_start ���� byte�� �ٷ���� char �� ������ ĳ���� Ÿ���� �޴°� �ƴ�

	va_list args;//�޸� ���� ����(�������ڸ� �ٷ� ��ü�� �����.)
	va_start(args, format);//format�� ���������� ������ġ�� �˷��ִ� �� 
							//=> ���ڰ��� �������� ... ũ�⸸ŭ �����͸� ������ ������
							//...�� ����������


	while (*format != '\0') {
		
		if (*format == '%') {
			++format;

			switch (*format)
			{
			case 'd':  {
				int num = va_arg(args, int); //...�� ù ���ڸ� intŸ������ ������
				if (num >= 10) {
					int odd = num / 10;
					int pdd = num % 10;
					char test10 = odd + '0';
					putchar(test10);
					char test20 = pdd + '0';
					putchar(test20);
				}
				else {
					char test30 = num + '0';
					putchar(test30);
				}

				break;
			}
			case 'c': {
				char test2 = va_arg(args, char); //...�� ���ڸ� charŸ������ ������
				putchar(test2);
				break;
			}
			case 's': {
				char* test3 = va_arg(args, char*); //...�� ���ڸ� charŸ������ ������
				while (*test3 != '\0') {
					putchar(*test3);
					++test3;
				}
				break;
			}
			default:
				putchar(*format);
			}
		}
		else {
			putchar(*format);
		}

		++format;
	}
	va_end(args); //�������� ������.
	printf("\n");
	
}