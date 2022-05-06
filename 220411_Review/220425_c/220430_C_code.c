#define _CRT_SECURE_NO_WARNINGS    // strcat ���� ���� ���� ������ ����
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <assert.h>
#include <float.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

//typedef : Ÿ���� ������ �ϴ°�. � Ÿ�Կ� ������ �����ִ°�
typedef char btye;
typedef struct tagA {
	int n;
} A;

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


void CreateUser(const char* nickname) {

	//int n = 1;
	int n = strlen(nickname);
	assert(n);
}

//�Լ� ȣ�� �Ծ� : ���� �޸𸮸� ��� Ȱ���� ���ΰ�, ���ڴ� ��� �ٷ� ���ΰ�
//x86��Ű���� ����

//64 ������ ���� 4��° ������ �������Ϳ��� ó���� 

//���ڸ� �����ʿ��� �������� ������ ���ÿ� ���� �Ѵ�. �������� ��밡�� , ���� ������ ȣ����(main)�� ��
void __cdecl Foo(int a, ...) {
		
}

//�������� ���Ұ� => cdecl �� ó������ : ���� ������ ��ȣ��� �Լ����� �Ѵ�.
void __stdcall Foo3(int a, ...) {

}

int __stdcall Foo4(int a, int b) {
	return a + b;
}

//�������ڸ� �������Ϳ� �����ϰ�(ū ���ڴ� �������� ����) , ���������� ��ȣ��� �Լ��� �Ѵ�. 
//�������� ���Ұ�
void __fastcall Foo2(int a, ...) {


}


void functest10(int sta, int stb) {
	int result = sta + stb;
}


void __fastcall testadd(int a, int b) {
	int result = a + b;
}


//ȣ���ڴ� �ü���� �� => main �Լ��� ��ȣ���ڷ� ��밡��(cdecl�� ����)
int main() {

	Foo(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,  14, 15);
	Foo3(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,  14, 15);
	Foo4(1, 2);
	Foo2(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);

	functest10(10, 20);

	testadd(10,20);



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
	myprintf2("Hello My ptrinf : %d, %c , %s", -10, 'A', "Hello");
	//output : Hello My ptrinf : 10, A, 3.140000, Hello
	//printf ������� ���� => putchar ����Ұ� : ������ �� ������ �װ͸� �����

	myprintf3(3, 4, 10, 20, 30);




	//<assert.h>
	//assert : ����ó���� ��� : ����׿��� �ۿ�
	//assert�� � ������ �ݵ�� �����ؾ��Ҷ� ����� => �������ϸ� exception������ ����
	assert(0 != 10);
	
	//<float.h>
	//�Ǽ� ��ü�� �����Ҷ� ����� , ���� epsilon ���� ���� �����
	printf("float�� ��ȿ���� : %f\n", FLT_DIG);
	printf("double�� ��ȿ���� : %f\n", DBL_DIG);
	printf("long double �� ��ȿ���� : %f\n", LDBL_DIG);

	//�Ҽ� ��
	float f = 1.0 - 0.7;
	if (f - 0.3 < FLT_EPSILON) { //f == 0.3 �ƴ�
		printf("����");
	}

	//<math.h>
	//�������� ���� ����
	// pow , hyopot , cos ,sin, tan , round
	

	// <stdlib.h>
	//���� 
	//����ڷκ��� �μ��� �Է� �ް�
	// ��� �������� ����ϼ���.
	int testnum1 = 0;
	int testnum2 = 0;
	scanf("%d %d", &testnum1, &testnum2);
	
	div_t result = div(testnum1, testnum2); //��� ������ ����

	printf("�� : %d, ������ : %d\n", result.quot, result.rem);

	// <stdbool.h>
	//�� ���� �Ǻ�
	bool bool1 = true;
	bool1 = false;
	
	//<stddef.h>
	//<stdint.h>
	//ȣȯ�� ������� ���� ����,Ÿ���� ����
	//int8_t;

	//<time.h>
	//time : ���� �ð��� ��Ÿ����
	time_t timeresult = time(NULL);//null���� �ʱ�ȭ
	char timestr[128] = "";
	printf("���� �ð� : %s\n", asctime(gmtime(&timeresult))); //���ʽð� ����
	
	//clock : ���� ����


	//���� ������ �����
// 1. ������ �ٷ�� ���� ��ü ����
	FILE* fp = NULL;

	// -------------------------------
	// �ؽ�Ʈ ����
	// -------------------------------

	// 2. ������ ����.
	// 1) �ؽ�Ʈ ���� : �ؽ�Ʈ �����ͷ� �� �� �ִ� ���Ϸ� �츮�� ���� �� �ִ� ���ڷ� ����
	// 2) ���̳ʸ� ���� : �� ���� ��� ����

	// Metaverse��� �̸��� ���� �ؽ�Ʈ ������ ����.
	//���������� 0�� ��ȯ�Ѵ�. ���������� �����ڵ带 ��ȯ�Ѵ�.
	if (0 != fopen_s(&fp, "Metaverse", "w"))
	{
		printf("���� �߻���.");

		return 1;
	}

	// 3. ������ �����Ѵ�.
	// �ؽ�Ʈ ���Ͽ� �ۼ��� �� �ִ� �Լ� : fputs() / fputc() / fprintf()
	// ���̳ʸ� ���Ͽ� �ۼ��� �� �ִ� �Լ� : fwrite()
	fputs("Hello File!", fp);
	fputc('J', fp);
	fprintf(fp, "\nThe name of the queen : %s\n", "������");

	// 4. ������ �ݴ´�.
	fclose(fp);

	if (0 != fopen_s(&fp, "Metaverse", "r"))
	{
		printf("���� �߻���.");

		return 1;
	}

	// �ؽ�Ʈ ���Ͽ��� �о���� �� �ִ� �Լ� : fgets() / fgetc() / fscanf()
	// ���̳ʸ� ���Ͽ��� �о���� �� �ִ� �Լ� : fread()
	char ch = fgetc(fp); //���� 1�� �б�
	char strf1[128] = "";
	fgets(strf1, sizeof(strf1), fp); // ���� ���ڱ��� �޾Ƶ��δ�. 
	char strf2[128] = "";
	fscanf_s(fp, "The name of the queen : %s", strf2, sizeof(strf2)); //���ڿ��� ������ null��ġ���� �޴´�.


	printf("�о���� ���� : %c\n", ch);
	printf("�о���� ���ڿ� : %s\n", strf1);
	printf("���� ����? : %s\n", strf2);

	fclose(fp);

	// -------------------------------
	// ���̳ʸ� ���� ����� �� ����
	// -------------------------------
	if (0 != fopen_s(&fp, "Metaverse2", "wb")) //write binary�� ����
	{
		printf("���� �߻���.");

		return 1;
	}

	struct Student
	{
		int Age;                  // 4����Ʈ
		enum { A, B, O, AB } BloodType;
		char Name[24];
	};

	struct Student s = { 20, A, "�ּ���" };
	//���̳ʸ� ���� 1�� �ۼ� ����ü�� => �������̸� 1 ��µ�
	if (1 != fwrite(&s, sizeof(s), 1, fp))
	{
		printf("���� �߻���.");

		fclose(fp);

		return 1;
	}

	fclose(fp);

	if (0 != fopen_s(&fp, "Metaverse2", "rb"))//read binary�� ����
	{
		printf("���� �߻���.");

		fclose(fp);

		return 1;
	}

	struct Student s2 = { 0 };
	//�ش� ����ü�� �����͸� ���� 1���� ���̳ʸ��� �о����
	if (1 != fread(&s2, sizeof(s2), 1, fp)) //������ ���� ���� �� 1���� �ƴϸ� => ���� ��ȯ
		//���� �϶� 0�� �����
	{
		printf("���� �߻���.");

		fclose(fp);

		return 1;
	}

	printf("���� : %d, ������ : %d, �̸� : %s\n", s2.Age, s2.BloodType, s2.Name);//BloodType�� ���� ����


	fclose(fp);

	//���̳ʸ��� ����ü�� �����͸� ������ �����ϴ�.
	


	//malloc => ���� �Ҵ�
	int pnum = 0;
	scanf("%d", &pnum);
	int* pm = malloc(sizeof(int) * pnum);

	//�޸𸮴� �ڿ��̴�.
	//�ڿ��̶�� ���� �ý������κ��� �����ͼ� ����� ������ ������� �ϴ°�
	//����� ���� �޸𸮸� �������� ������ �޸� ����(memory Leak)�� �߻�

	//������ �������� �޸𸮸� �����ִ� free�Լ��� ����ؾ� �Ѵ�.
	free(pm);//���� �޸� ��ȯ
	pm = NULL; //������ ��ٸ� �� null�����ͷ� ������ٰ�

	//�޸𸮸� �������� �����Ҷ� ������
	//1. ���� ����� �������� �Ҹ�Ȯ�� => ��ȯ�� �ȵɼ� ����. => �޸� ���� �߻�
	//2. ��ȯ�� �������� �ұ��ϰ� �����ϴ� ��� => �޸� ���� ������ ���� �� => ��ȿ���� �ʴ� �޸� �ּҸ� ���� �ִ� �����͸� ��۸� �����Ͷ���Ѵ�.
	//3. ��ȯ�� �������� �ұ��ϰ� �� ��ȯ�ϴ� ��� => ��������(double free)
	


	//�Լ��� �ĺ��ڴ� �����ؾ��� => �Լ��� �����Ǹ� �Ҽ� ����
	
	//stack : ���� �Ҵ翵�� => �Լ��� ����ϴ� ���� => �̹� �󸶳� �޸𸮸� ����ؾ����� �˰�����
	//heap : ���� �Ҵ翵��
	//data : ���� ������
	//code : ���α׷� ��ɾ�

	int spa = 10; //4����Ʈ


	// �Լ��� ����ϴ� �޸� : ����(Stack)
	// �Լ��� ���õ� ����(���� ������)
	// 1. �󸶳� �޸𸮸� ����� ������ => �ӽ� ������
	// 2. �Ű�����(����)
	// 3. ��ȯ �ּ�
	// ���� ������ bp, sp�� �̿���.
	// bp : �Լ��� ����ϴ� �޸��� ���� �ּ�
	// sp : �Լ��� ����� �� �ִ� �޸��� �� �ּ�

	// ȣ�� �Ծ�(Calling Convention)
	// => ���ڸ� ��� ������ ���̸�, ��ȯ ���� ��� ������ ���ΰ�
	// ����ϴ� ���� : stdcall, fastcall �� ����ϸ� �޸� ��뷮�� ���ϼ� ����
	
	// x86
	// __cdecl : �⺻ ȣ�� �Ծ�. ���ڴ� �����ʺ��� ���� ������� ���ÿ� �ְ�, ���� ������ ȣ���ڰ� �Ѵ�. ���� ���� ��� ����
	// __stdcall : ���ڸ� �����ʺ��� ���� ������� ���ÿ� �ְ�, ���� ������ ��ȣ���ڰ� �Ѵ�. ���� ���� ��� �Ұ���
	// __fastcall : (�����ϴٸ�) ù ��° ���ڿ� �� ��° ���ڸ� �������Ϳ� �����ϰ�, ������ ���ڴ� �����ʿ��� ���� ������� ���ÿ� ����. �׸��� ���� ������ ��ȣ���ڰ� �Ѵ�.
	
	//�������� ���Ұ�
	// x64
	// 4��° ���ڱ��� �������Ϳ� �ְ�, ���� ������ ��ȣ���ڰ� �Ѵ�.

	



	return 0;
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

void stringNumber(int num) {
	
	//32 ��Ʈ(4����Ʈ) �ڸ����� ���ϰ� 1�̸� ������ =>0�϶� ������������ ����
	//&�Ѱ� ����ϴ� ������ ��Ʈ ���� �����Ҷ��� &�ϳ� �����
	const int isNegative = num & (1 << 31);//��ȣ ��Ʈ ��� (1&&1 �� 1) => 0�� �ƴҶ� ����


	//�����̹Ƿ� ���� ������
	// ����� 2�� ���� ��Ʈ ���� �Ҷ� , 1) ��� ��Ʈ �����ϱ� 2) +1�ϱ� => ��������
	// �װ��� �Ųٷ� �������� ����� ��ȯ �ҷ��� , 1) -1�ϱ� 2) ���� ��Ʈ �����ϱ� => �������
	if (isNegative) {
		putchar('-');
		num -= 1; 
		num = ~num; 
	}


	char temp[31] = {0}; //����Ʈ�� ��ŭ ����
	int count = 0;
	while (num != 0) {
		temp[count] = num % 10 + '0';
		num = num / 10;
		count++;
	}

	for (int i = count-1; i >= 0; i--)
	{
		putchar(temp[i]);
	}


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
				
				stringNumber(num);
											 
				/*if (num >= 10) {
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
				}*/

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