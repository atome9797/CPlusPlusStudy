#include <stdio.h>
#include <string.h>



char* strstr3(char* str, char* str2) {
	
	int count = 0;

	char* temp2 = str;
	for (int i = 0; str[i] != '\0' ; i++)
	{
		if (str[i] == str2[0]) {//단어 시작 위치랑 같을때
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

	//문자열 : stack에 있는거라 수정가능함
	char str[] = "Hello, world";
	//str = "HELLO"; => 문자열 리터럴 타입은 const char * 이기 때문에 배열에 할당 못한다.
	str[0] = 'x';
	
	//strcpy(str, "jee"); //정적 메모리라 안됨
	printf("%s\n", str);


	//포인터는 data 정적 메모리이므로 수정 불가능함
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