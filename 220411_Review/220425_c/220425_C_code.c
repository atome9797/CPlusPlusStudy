#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {


#pragma region �˰���

	/*
		�� �׽�Ʈ���̽����� A+B�� �� �ٿ� �ϳ��� ������� ����Ѵ�.
	*/


	/*
		n�� �־����� ��, 1���� n���� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
	*/
	int sumCal = 0; //�հ�
	int countNUm = 0; // n��
	int cnt = 0;
	scanf("%d", &countNUm);
	//n=3�϶�
	for (int i = 0; i < countNUm/2; i++) {
		sumCal += countNUm +1 ;
	}
	if (countNUm % 2 != 0) {
		sumCal += (countNUm + 1) / 2;
	}

	printf("��갪 : %d\n", sumCal);


	//���̽� �� ���
	int replay = 0; //�ݺ�Ƚ��
	int input1 = 0; //ù��° �Է°�
	int input2 = 0; //����° �Է°�
	int replaySum = 0;
	scanf("%d", &replay); 

	for (int i = 0; i < replay; i++) {//�ݺ�Ƚ�� ��ŭ �Է°� ����
		scanf("%d %d", &input1, &input2); //������
		replaySum = input1 + input2;
		printf("%d\n", replaySum);
	}


	//������
	//int number = 0;
	//scanf("%d\n", &number);

	//for (int i = 1; i < 10; i++) {
	//	printf("%d * %d = %d\n", number, i, number * i);
	//}

	
	/*
		���� �����Ǿ� �ִ� �˶��� 45�� �ռ��� �ð����� �ٲٴ� ��
		ù° �ٿ� �� ���� H�� M�� �־�����. (0 �� H �� 23, 0 �� M �� 59)
		�׸��� �̰��� ���� ����̰� ������ ���� �˶� �ð� H�� M���� �ǹ��Ѵ�.
		24�ð� ǥ������ �Ϸ��� ������ 0:0(����)�̰�, ���� 23:59(������ ���� 1�� ��)�̴�
		���ʿ��� 0�� ������� �ʴ´�.
	*/
	int hour = 0;
	int minute = 0;
	scanf("%d", &hour);
	scanf("%d", &minute);

	//if (hour == 0) {
	//	hour = 24;
	//}
	//int output = (hour * 60 + minute) - 45;

	//if (output / 60 == 24) {
	//	hour = 0;
	//}
	//else {
	//	hour = output / 60;
	//}
	//printf("��� : %d:%d\n", hour, output % 60);


	if (minute - 45 < 0) {
		hour -= 1;
		minute = 60 + (minute-45);
		if (hour < 0) {
			hour = 23;
		}
	}
	else {
		minute -= 45;
	}

	printf("�˶� -45 : %d %d", hour, minute);


	int dies1 = 0;
	int dies2 = 0;
	int dies3 = 0;
	int count = 0;
	int price = 0;

	scanf("%d %d %d", &dies1, &dies2, &dies3);
	
	if (dies1 == dies2 && dies2 == dies3) {
		count += 2;
	}
	else if (dies1 == dies3 || dies2 == dies3 || dies1 == dies2) {
		count += 1;
	}


	if (count >= 2) {
		price = 10000 + dies1 * 1000;
	}
	else if (count == 1) {
		if (dies1 == dies2) {
			price = 1000 + dies1 * 100;
		}
		else if (dies1 == dies3) {
			price = 1000 + dies1 * 100;
		}
		else if (dies2 == dies3) {
			price = 1000 + dies2 * 100;
		}
	}
	else {
		if (dies1 > dies2 && dies1 > dies3) { // 3 4 6
			price = dies1 * 100;
		}
		else if (dies2 > dies3 && dies2 > dies1) {
			price = dies2 * 100;
		}
		else if (dies3 > dies2 && dies3 > dies1) {
			price = dies3 * 100;
		}
	}

	printf("��� : %d\n", price);


	/*
		ù° �ٿ��� ���� �ð�
		�� ��° �ٿ��� �丮�ϴ� �� �ʿ��� �ð�
	*/
	int hr = 0;
	int min = 0;
	int oven = 0;
	scanf("%d %d", &hr, &min);
	scanf("%d", &oven);

	//�а� ���� �ð��� 1�ð��� �Ѿ� ����
	if (min+oven >= 60) {
		hr += (min+oven)/60; //�ð��� �߰�����
		min = (min + oven) % 60;//������ �� �߰���

		if (hr > 23){
			hr = hr % 24;
		}
	}
	else {
		min = (min + oven);
	}

	printf("%d %d", hr, min);


	///*
	//	���� �����Ǿ� �ִ� �˶��� 45�� �ռ��� �ð����� �ٲٴ� ��
	//	ù° �ٿ� �� ���� H�� M�� �־�����. (0 �� H �� 23, 0 �� M �� 59)
	//	�׸��� �̰��� ���� ����̰� ������ ���� �˶� �ð� H�� M���� �ǹ��Ѵ�.
	//	24�ð� ǥ������ �Ϸ��� ������ 0:0(����)�̰�, ���� 23:59(������ ���� 1�� ��)�̴�
	//	���ʿ��� 0�� ������� �ʴ´�.
	//*/
	//int hour = 0;
	//int minute = 0;
	//scanf("%d", &hour);
	//scanf("%d", &minute);

	//if (hour == 0) {
	//	hour = 24;
	//}
	//int output = (hour * 60 + minute) - 45;

	//if (output / 60 == 24) {
	//	hour = 0;
	//}
	//else {
	//	hour = output / 60;
	//}
	//printf("��� : %d:%d\n", hour, output % 60);


	//if (minute - 45 < 0) {
	//	hour -= 1;
	//	minute = 60 + minute;
	//	if (hour < 0) {
	//		hour = 23;
	//	}
	//}
	//
	//printf("%d %d", hour, minute);


	int numa = 0;
	int numb = 0;
	scanf("%d", &numa);
	scanf("%d", &numb);

	//385
	int layer100 = numb / 100;//3
	int layer10 = (numb % 100) / 10;//8
	int layer1 = numb % 10;//5

	/*
		�˰������� ��Ģ���� �ο��ϸ� a / 100 % 10 ���� ���� �����ϴ�.
	
		int layer100 =  numb / 100 %10;
		int layer10 = (numb / 10) % 10;
		int layer1 = numb /1 % 10;
	*/



	printf("%d\n", numa * layer1);
	printf("%d\n", numa * layer10);
	printf("%d\n", numa * layer100);
	printf("%d\n", (numa * layer1) + (numa * layer10 * 10) + (numa * layer100 * 100));

	int num1 = 0;
	int num2 = 0;
	int sum = 0;
	char num2ch[30];
	printf("�Է��� �����ÿ� =======\n");
	scanf("%d", &num1);
	scanf("%d", &num2);
	sprintf(num2ch, "%d", num2);
	printf("���� : %d\n", sizeof(num2ch) / sizeof(char));
	//for (int i = 0; i < sizeof(num2ch) /sizeof(char); i++) { //���� ���� ��ŭ ����
	//	int count = 10 * (sizeof(num2ch) / sizeof(char) - i -1);//5-1
	//	printf("%d\n", num1 * num2ch[i]);
	//	if (count ==0) {
	//		sum += num1 * num2ch[i];
	//	}
	//	else {
	//		sum += num1 * num2ch[i] * count;
	//	}
	//}
	

	//�ֵ���ǥ �������� ��¹��
	/*
		\t : ���� tab tab(8)ĭ ����

		\n : ���� Ŀ���� ���� ������ �̵�(enter�� ����ȿ��)

		\' : '(��Ƽ��)�� ǥ�� , �ܵ����� '�Է½� ȭ�鿡 ��� x

		\" : "(���� ��Ƽ��) ǥ��

		\\ : \(�������� ǥ��)

	*/

	printf("\\    /\\\n");
	printf(" )  ( ')\n");
	printf("(  /  )\n");
	printf(" \\(__)|\n");

	printf("|\\_/|\n");
	printf("|q p|   /}\n");
	printf("( 0 )\"\"\"\\\n");
	printf("|\" ^ \"`    |\n");
	printf("||_/=\\\\__|\n");

	//
	int a = 0;
	int b = 0;
	double result = 0.0; //double ���� �Ҽ� 15�ڸ����� �������� ǥ���Ҽ� �ִ�.

	//����ȯ
	scanf("%d", &a);
	scanf("%d", &b);
	result = (double)a / b;
	printf("%.13f\n", result);

	char name[40];
	scanf("%s", name);
	printf("%s??!\n", name);

	int year = 0;
	scanf("%d", &year);
	printf("��¥ : %d\n", year - 543);


	/*
		A�� B���� ū ��쿡�� '>'�� ����Ѵ�.
		A�� B���� ���� ��쿡�� '<'�� ����Ѵ�.
		A�� B�� ���� ��쿡�� '=='�� ����Ѵ�.
	*/

	/*
		���� ������ �Է¹޾� 90 ~ 100���� A, 80 ~ 89���� B, 
		70 ~ 79���� C, 60 ~ 69���� D, ������ ������ F�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
	*/
	
	int score = 0;
	scanf("%d", &score);
	if (score >= 90 && score <= 100) {
		printf("A");
	}
	else if (score >= 80) {
		printf("B");
	}
	else if (score >= 70) {
		printf("C");
	}
	else if (score >= 60) {
		printf("D");
	}
	else {
		printf("F");
	}


	/*
		������ ������ 4�� ����̸鼭, 100�� ����� �ƴ� �� �Ǵ� 400�� ����� ���̴�.
		������ �־����� ��, �����̸� 1, �ƴϸ� 0�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
	*/

	/*
		1�� : ++
		2�� : -+
		3�� : --
		4�� : +-
	*/
	int x = 0;
	int y = 0;

	scanf("%d", &x);
	scanf("%d", &y);

	if (x > 0 && y > 0) {
		printf("1");
	}
	else if (x < 0 && y > 0) {
		printf("2");
	}
	else if (x < 0 && y < 0) {
		printf("3");
	}
	else{
		printf("4");
	}



#pragma endregion

#pragma region c���


	char ch = 'a';
	int number = 20;
	float number2 = 2.4f;

	printf("%c\n", ch);
	printf("%-5d", number); //-5�� 5�ڸ��� ����� ���� �����ؼ� ��ĭ�� ����� �۾���
	printf("%.3f\n", number2);
	
	long long number3 = 1024LL;
	printf("%lld\n", number3);

	float temp1 = 0.0f;
	int temp2 =0;
	//���� �ʱ�ȭ ���ϸ� �����Ⱚ�� �� �ִ�.
	scanf("%f | %d", &temp1, &temp2);

	printf("%f %d\n", temp1, temp2);


	/*
		float ,double, long double
		�Ҽ��� ���� �ڸ��� 9������ ���ƾ� ��
		float :9��
		double : 9��
		long double : 15��

		������ ����
		������ ���� : ������ �߸�����
		link error : ������ �߸��Ѱ�
			- �Լ��� �����ϰ� �������� �ʾҴٰų�
			- �̹� ���ǵ� �ĺ��ڸ� �ٽ� �������Ѵٰų�
			- ���� ���� �ĺ��ڸ� ����ߴٰų�
		runtime error : ���α׷� ������ �����߻�-> ���� -> �� ����

	*/

	
	//10bit
	//0100 0000 0000
	(signed char)1024; //char �� 8��Ʈ�̹Ƿ� 10��Ʈ�� ����� �߸���.

	/*
		while���� 0�� �ƴ� �ٸ����� �� ��, 0�� ����
		while(-1){ //���� �ݺ���
		}
	*/


#pragma endregion


	return 0;
}