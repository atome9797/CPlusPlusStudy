#include <stdio.h>
#include <string.h>



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




	return 0;
}