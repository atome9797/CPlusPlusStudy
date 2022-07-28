#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {

	//���� ������ �����
	//1. ������ �ٷ�� ���� ��ü ����
	FILE* fp = NULL;

	//2. ������ ����.
	//1_ �ؽ�Ʈ ���� : �ؽ�Ʈ �����ͷ� �����ִ� ��� ���Ϸ� �츮�� ������ �ִ� ���ڷ� ����
	//2_ ���̳ʸ� ���� : �׿��� ��� ����
	//Metaverse��� �ǹ̸� ���� ������ ���ٴ� �ǹ�
	//������ ������ �����ְ� ������ ���� �����.
	if (0 != fopen_s(&fp, "Metaverse.txt", "w")) { //���� ���������� 0��ȯ
		printf("���� �߻���");
		return 1;
	};

	//3.�������� �ۼ��Ѵ�.
	// �ؽ�Ʈ ���Ͽ� �ۼ��Ҽ� �ִ� �Լ� :fputs(), fputc(), fprintf()
	// ���̳ʸ� ���Ͽ� �ۼ��Ҽ� �ִ� �Լ� :fwrite()
	fputs("Hello File!", fp);
	fputc('J', fp);
	fprintf(fp, "The name of the queen : %s\n", "������");//��Ƽ ����Ʈ ��� ���


	//4. ������ �ݴ´�.
	fclose(fp);


	//5. ������ read ���� ����
	if (0 != fopen_s(&fp, "Metaverse", "r")) {
		printf("���� �߻���1");
		return 1;
	}



	//�ؽ�Ʈ ���Ͽ��� �о���ϼ� �ִ� �Լ� () : fgets, fgetc(), fscanf()
	//���̳ʸ� ���Ͽ��� �о���ϼ� �ִ� �Լ� : read()
	char ch = fgetc(fp);
	char str1000[128] = "";
	fgets(str1000, sizeof(str1000), fp);//���� ���� ���� �޴´�.
	char str2000[128] = "";
	fscanf_s(fp, "The name of the queen : %s", str2000, sizeof(str2000));

	printf("�о���� ���� :%c\n", ch);
	printf("�о���� ���ڿ� :%s\n", str1000);
	printf("���� ����? :%s\n", str2000);

	fclose(fp);


	/*
		���̳ʸ� ����
	*/
	if (0 != fopen_s(&fp, "Metaverse2", "wb")) {
		printf("���� �߻���2");
		return 1;
	}


	struct Student {

		int Age;
		enum { A, B, O, AB } BloodType;
		char Name[24];
	};

	struct Student s = { 20, A, "ChoiSeonMun" };

	if (1 != fwrite(&s, sizeof(s), 1, fp)) {
		printf("���� �߻���3");
		fclose(fp);
		return 1;
	};

	fclose(fp);

	//read
	if (0 != fopen_s(&fp, "Metaverse2", "rb")) {
		printf("���� �߻���");
		fclose(fp);
		return 1;
	}
	struct Student s2 = { 0 };
	if (1 != fread(&s2, sizeof(s2), 1, fp)) {
		printf("���� �߻���");
		fclose(fp);
		return 1;
	}

	printf("���� : %d, ������ : %d, �̸� : %s\n", s2.Age, s2.BloodType, s2.Name);

	fclose(fp);

	return 0;
}