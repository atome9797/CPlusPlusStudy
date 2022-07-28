#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {

	//파일 포인터 만들기
	//1. 파일을 다루기 위한 객체 생성
	FILE* fp = NULL;

	//2. 파일을 연다.
	//1_ 텍스트 파일 : 텍스트 에디터로 열수있는 모든 파일로 우리가 읽을수 있는 문자로 구성
	//2_ 바이너리 파일 : 그외의 모든 파일
	//Metaverse라는 의미를 가진 파일을 연다는 의미
	//파일이 있으면 열어주고 없으면 새로 만든다.
	if (0 != fopen_s(&fp, "Metaverse.txt", "w")) { //조건 성공했을때 0반환
		printf("오류 발생함");
		return 1;
	};

	//3.컨텐츠를 작성한다.
	// 텍스트 파일에 작성할수 있는 함수 :fputs(), fputc(), fprintf()
	// 바이너리 파일에 작성할수 있는 함수 :fwrite()
	fputs("Hello File!", fp);
	fputc('J', fp);
	fprintf(fp, "The name of the queen : %s\n", "퀸균지");//멀티 바이트 방식 사용


	//4. 파일을 닫는다.
	fclose(fp);


	//5. 파일을 read 모드로 열기
	if (0 != fopen_s(&fp, "Metaverse", "r")) {
		printf("오류 발생함1");
		return 1;
	}



	//텍스트 파일에서 읽어들일수 있는 함수 () : fgets, fgetc(), fscanf()
	//바이너리 파일에서 읽어들일수 있는 함수 : read()
	char ch = fgetc(fp);
	char str1000[128] = "";
	fgets(str1000, sizeof(str1000), fp);//개행 문자 까지 받는다.
	char str2000[128] = "";
	fscanf_s(fp, "The name of the queen : %s", str2000, sizeof(str2000));

	printf("읽어들인 문자 :%c\n", ch);
	printf("읽어들인 문자열 :%s\n", str1000);
	printf("퀸은 누구? :%s\n", str2000);

	fclose(fp);


	/*
		바이너리 파일
	*/
	if (0 != fopen_s(&fp, "Metaverse2", "wb")) {
		printf("오류 발생함2");
		return 1;
	}


	struct Student {

		int Age;
		enum { A, B, O, AB } BloodType;
		char Name[24];
	};

	struct Student s = { 20, A, "ChoiSeonMun" };

	if (1 != fwrite(&s, sizeof(s), 1, fp)) {
		printf("오류 발생함3");
		fclose(fp);
		return 1;
	};

	fclose(fp);

	//read
	if (0 != fopen_s(&fp, "Metaverse2", "rb")) {
		printf("오류 발생함");
		fclose(fp);
		return 1;
	}
	struct Student s2 = { 0 };
	if (1 != fread(&s2, sizeof(s2), 1, fp)) {
		printf("오류 발생함");
		fclose(fp);
		return 1;
	}

	printf("나이 : %d, 혈액형 : %d, 이름 : %s\n", s2.Age, s2.BloodType, s2.Name);

	fclose(fp);

	return 0;
}