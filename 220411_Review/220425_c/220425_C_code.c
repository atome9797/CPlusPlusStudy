#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>

int arr[1000000];
char alpha_arr[10000000];
char aaa[10000000];

int main() {//main�Լ��� �ý����� ȣ���ϴ� �� => runtime ���̺귯������ ó�� ����


	//1316
	//��ǥ : 
	// 1. �׷� �ܾ� ������ ����ϴ� ���α׷��� �����
	// 2. �׷�ܾ �ƴҶ� ī��Ʈ ���Ѵ�. -> �׷�ܾ�� ���� ���ڴ� ���� ���ڳ��� �̾��� ����
	//�Է� :
	// 1. �Է� �� �׷�ܾ� ������ logic_group_cnt �� �����ϰ� �Է� �޴´�.
	int logic_group_cnt = 0;
	scanf("%d", &logic_group_cnt);
	//ó�� :
	// 2. logic_group_cnt�� ���� ��ŭ �ݺ����� ������.
	// 3. char ���ڿ��ε� group_word �� �����ϰ� �Է� �޴´�.
	// 4. group_word ���ڿ��� �ݺ��� ������.
	// 5. group_word������ ���ĺ��� 0 ~ 26���� �̰� ���ο� count �迭 [index]�� �־��ش�. => ���� group_word������ġ��
	// 6. group_word �ݺ����� ������, ������ ������� count ���ش�(���ο� for��)
	// 6-1. ������� p ���ĺ��� ���Ѵ� �Ҷ� ������ ���� ��ŭ �ȴþ� �� ������ �׷� �ܾ �ƴϴ�.
	// 6-2. 
	
	int word_array[26]={0};
	int minor = 0;
	for (int i = 0; i < 26; i++){
		word_array[i] = -1;
	}

	for (int i = 0; i < logic_group_cnt; i++) {
		char group_word[100];
		scanf("%s", group_word);
		minor = strlen(group_word);
		int exp_count = 1;
		for (int j = 0; j < strlen(group_word); j++) {
			int word_count = group_word[j] - 'a';//0~25���� ���ĺ��ε����� �޴´�.
			
			if (word_array[word_count] != -1) { //�̹� �ڸ��� ���� ������
				exp_count++;
			}
			else {
				exp_count = 1;
			}
			

			word_array[word_count] = j;//���ڿ��� ��ġ�� ���ĺ��迭 index�� ����ش�.
			int test_count = 0;
			//for (int k = 0; k < j+1; k++){
			for (int k = 0; k < 3; k++) {
				if (group_word[j] == group_word[k]) {//���ĺ��� �ִ��� Ȯ���ϱ�
					test_count++; //�ش� ���ĺ��� ī��Ʈ�ؼ� ���� ��������
					printf("��¼��� %d\n", test_count);
				}
			}

			printf("�ù� %d\n", test_count);
			printf("��� %d\n", exp_count);

			if (test_count != exp_count) {
				minor--;
				break;
			}
		}
	}
	//��� : 
	printf("%d", minor);

	
	
	//2941
	//��ǥ : ũ�ξ�Ƽ�� ���ĺ��� �ܾ̿��ĺ� ������ ���Ѵ�.
	//�Է� : 
	// 1. �ִ� 100���ڴܾ �Է� �޴´�.
	char cro_alpha[100] = { 0 };
	scanf("%s", cro_alpha);
	// 2. ũ�ξ�Ƽ�� �迭�� �����.
	// 3. count�� �����Ѵ�.
	int cro_count = strlen(cro_alpha);//���ڸ� ī��Ʈ ���ش�.
	//ó�� :
	// 3. �ܾ �ݺ����� ������.

	for (int i = 0; i < strlen(cro_alpha); i++) {
		if (cro_alpha[i - 1] == 'c' && cro_alpha[i] == '=') {
			cro_count--;
		}
		if (cro_alpha[i - 1] == 'c' && cro_alpha[i] == '-') {
			cro_count--;
		}
		if (cro_alpha[i - 2] == 'd' && cro_alpha[i - 1] == 'z' && cro_alpha[i] == '=') {
			cro_count--;
		}
		if (cro_alpha[i - 1] == 'd' && cro_alpha[i] == '-') {
			cro_count--;
		}
		if (cro_alpha[i - 1] == 'l' && cro_alpha[i] == 'j') {
			cro_count--;
		}
		if (cro_alpha[i - 1] == 'n' && cro_alpha[i] == 'j') {
			cro_count--;
		}
		if (cro_alpha[i - 1] == 's' && cro_alpha[i] == '=') {
			cro_count--;
		}
		if (cro_alpha[i - 1] == 'z' && cro_alpha[i] == '=') {
			cro_count--;
		}
		

	}
	// 3-1. ���� ���ڰ� ũ�ξ�Ƽ�� �����̰�, �ش� ���ڰ� ũ�ξ� Ƽ�� �����̸� count ���ش�.
	// 3-1. ũ����Ƽ�� ���ڰ� �ƴϸ� count ���ش�.
	// 4-1. count ���� ������ش�.
	//��� :
	printf("%d\n", cro_count);



#pragma region c����


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
	//scanf("%f | %d", &temp1, &temp2);

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


	//1.�Է�
	//Case#1 : 10 20 30
	//int caseNum, data1, data2, data3;
	//scanf("Case#%d : %d %d %d", &caseNum, &data1, &data2, &data3);

	//2. ���
	//Case#1 : 10 20 30
	//printf("Case#%d : %d %d %d", caseNum, data1, data2, data3);

	//3.����

	//4. �б⹮
	//if/switch

	/*
		5. �ݺ���
		- for/while/do-while
		- for: �ݺ� Ƚ���� ������ ���� ������
		- while :�ݺ�Ƚ���� ������ ���� ������
		- do-while : ���ǽ� �򰡰� ���߿� �Ͼ�� �Ҷ�
	*/

	//6.�迭
	// ���� ������ ���� �����͸� �ѹ��� �ٷ�� ���Ѱ�


	//����Ʈ ������

	signed char chs = -1;
	//0000 0001 => ...1111 1111 1111 1110 +1 => ...1111 1111 1111 1111
	

	chs >> 2;//2��2���� ��ŭ ������ �Ѱ� ��µ�
	//... 1111 1111 => ��ȣ ��Ʈ�� ������ (��ȣ ��Ʈ�� ����Ʈ �����ڷ� �ȹٲ�)

	chs << 2; //2�� 2���� ��ŭ ���� �� ��µ�

	chs << 1; //2�� 1���� ��ŭ ���� �� ��µ�

	//0x24 16������ 10������ ǥ�� �ϸ� 16*1+ 16*2 = 36���� ǥ������



	//�Լ� : �Ϸ��� �ڵ忡 �̸��� ���ΰ� 
	//�Լ��� api��� �Ҹ��⵵��
	//API
	// Apllication Programming
	/*
		Interface => �Լ� �ϳ��� ���´°�

		standard => �÷����� �������̴�. (ios, android, window...��� ǥ���̸� �� ��밡��)
		-> �̽ļ��� ���ٰ� ��

		Library => ������ api ����
	*/


	//220428 ���ڿ�
	char str100[128];
	str100[0] = 'H';
	str100[1] = 'H';
	str100[2] = 'H';
	str100[3] = 'H';
	str100[4] = 'H';
	str100[5] = NULL;//null���ڷ� �������� '\0'

	printf("���� %s", str100);// ���ڿ��� �����Ű�� �ʾ����� �����Ⱚ ����
	//�ֳ��ϸ� 128 �迭�̹Ƿ� ������ ���� �Բ� ���� (null�� ���������) 


	//pointer type : �ּҰ����� �ؼ��ϴ� Ÿ��
	//�迭�� pointer type���� �Ͻ��� ��ȯ�� -> �����ͷ� �����ߴ�.

	char str101[10];
	//10 �̻� ������ ������ => buffer overrun�̶�� �Ѵ�.
	scanf("%s", str101); //=> �迭�� ������ Ÿ����, �ּ� �Ⱦ�

	//���ڿ� ���̸� �����Ҽ� �ִ� %n�� �����Ѵ� => ��ť�� �Լ�
	scanf("%9s", str101);
	
	//scanf_s �� ������ �����Ҽ��� �ִ�.
	scanf_s("%s", str101, 10); 
	


#pragma endregion

#pragma region �˰���

	//�Է�
	int test_case_num = 0;//�ݺ� Ƚ��
	char count_test[80] = "#";
	int count_score = 0;
	int count_sp = 0;
	scanf("%d", &test_case_num);


	for (int i = 0; i < test_case_num; i++) {//5�Էµ�
		count_score = 0;

		scanf("%s", &count_test); //���ڿ�


		for (int j = 0; j < 80; j++) { //���ٿ� 80�� ���� ������ �ֵ��� ����
			if (count_test[j] == 'O') {
				count_score += 1;
				if (j >= 1 && count_test[j] == 'O' && count_test[j - 1] == 'O') {
					count_sp += 1;
					count_score += count_sp;
				}
				else {
					count_sp = 0;
				}
			}
		}

		printf("%d\n", count_score);
	}

	//for (int k = 0; k < 80; k++) {
	//	count_score += count_test[k];
	//	if (count_test[k] == 1 && count_test[k-1] == 1) {
	//		count_score += 1;
	//	}
	//}

//���
//1. �ִ��� M, ������� => ����/M*100

//�Է�
	int testCnt = 0; // �׽�Ʈ ����
	int testScore = 0; //�׽�Ʈ �Ѱ� ����
	int maxScore = 0; //�ִ�����
	double calScore = 0;//���� ����
	int input_score[101] = { 0 };

	scanf("%d", &testCnt);

	for (int i = 0; i < testCnt; i++) {
		scanf("%d", &testScore);
		input_score[testScore] += 1; //�������� �����ؼ� ī��Ʈ�� �����ü� ����
		if (maxScore < testScore) {//�ִ� ���ϱ�
			maxScore = testScore;//�ִ񰪿� �ֱ�
		}
	}

	for (int i = 1; i <= 100; i++)
	{
		if (input_score[i] >= 1) {//�ش� �ε����� ���� ������
			calScore += (double)i * input_score[i] / maxScore * 100;
		}
	}

	printf("%f\n", calScore / testCnt);




	//1. �������� ���δٸ��� ��ִ��� ���ϱ�

	//�Է�
	int input_a[42] = { 0 };//�޴� �迭
	int number_c = 0;//�Է°�
	int count_a = 0;
	//ó��
	for (int i = 0; i < 10; i++) {
		scanf("%d", &number_c);
		input_a[number_c % 42] += 1;
	}

	//printf("%d\n", input_a[0]);

	for (int i = 0; i < 42; i++)
	{
		if (input_a[i] >= 1) {
			//�� ������ index���� �˻� �ϴ� ���̹Ƿ� input_a[0]�϶� 3�̵� 4�� ���� 1���� ī��Ʈ ��
			count_a++;
		}
	}

	printf("%d\n", count_a);


	/*
		ù° �ٿ� A, ��° �ٿ� B, ��° �ٿ� C�� �־�����.
		A, B, C�� ��� 100���� ũ�ų� ����, 1,000���� ���� �ڿ����̴�.

		ù° �ٿ��� A �� B �� C�� ����� 0 �� �� �� �������� ����Ѵ�.
		���������� ��° �ٺ��� �� ��° �ٱ��� A �� B �� C��
		����� 1���� 9������ ���ڰ� ���� �� �� �������� ���ʷ� �� �ٿ� �ϳ��� ����Ѵ�.

		1. A,B,C ���� ���� ���� ����
		2. scanf �� �� �ޱ�
		3. �鰪�� �ڸ��� �� �ڸ����� ���� �迭�� �����ϱ� => 0 �ڸ����� �� ? �̷�������
		4. 2�� for������ �� �ڸ����� ���� ī��Ʈ�ؼ� �̱�
	*/

	int digit[3];
	int sumDigit = 0;
	int cntDigit[] = { 0, }; //�� �Լ� �����ؼ� ���� �Ҵ��Ҽ� ����
	int count100 = 1;
	int ddd = 0;

	for (int i = 0; i < 3; i++) {
		scanf("%d", &digit[i]);
	}

	sumDigit = digit[0] * digit[1] * digit[2];

	//printf("%d\n", sumDigit);

	//sumDigit �迭�� ��ȯ
	while (1) {
		if (sumDigit / 10 != 0) {
			sumDigit = sumDigit / 10;
			count100++;
		}
		else {
			break;
		}
	}

	//printf("�ڸ��� : %d\n", count100);


	sumDigit = digit[0] * digit[1] * digit[2];


	for (int i = 0; i < count100; i++) {
		cntDigit[i] = sumDigit % 10;
		sumDigit = sumDigit / 10;
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < count100; j++) {
			if (i == cntDigit[j]) {
				ddd += 1;
			}
		}
		printf("%d\n", ddd);
		ddd = 0;
	}

	//printf("�迭 �� : %d %d %d %d %d %d\n", cntDigit[0], cntDigit[1], cntDigit[2], cntDigit[3], cntDigit[4], cntDigit[5]);



	/*
	N���� ������ �־�����. �̶�, �ּڰ��� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
	1. ù° �ٿ� ������ ����
	2.  ��° �ٿ��� N���� ������ �������� �����ؼ� �־�����
	3. ù° �ٿ� �־��� ���� N���� �ּڰ��� �ִ��� �������� ������ ����Ѵ�.
*/

	int size = 0;
	int maxN = 0;
	int minN = 0;
	scanf("%d", &size);


	for (int i = 0; i < size; i++) {
		scanf("%d", &arr[i]);
	}

	maxN = arr[0];
	minN = arr[0];

	for (int i = 0; i < size; i++) {
		if (maxN < arr[i]) {
			maxN = arr[i];
		}
		if (minN > arr[i]) {
			minN = arr[i];
		}
	}


	printf("%d %d\n", minN, maxN);


	/*
		ù° �ٺ��� ��ȩ ��° �ٱ��� �� �ٿ� �ϳ��� �ڿ����� �־�����.
		�־����� �ڿ����� 100 ���� �۴�.

		ù° �ٿ� �ִ��� ����ϰ�, ��° �ٿ� �ִ��� �� ��° �������� ����Ѵ�.
	*/

	int input10[9];
	int maxN2 = 0;
	int cnt100 = 0;

	for (int i = 0; i < 9; i++) {
		scanf("%d", &input10[i]);
	}

	maxN2 = input10[0];

	for (int i = 0; i < 9; i++) {

		if (maxN2 < input10[i]) {
			maxN2 = input10[i];
			cnt100 = i;
		}

	}


	printf("%d %d\n", maxN2, cnt100 + 1);


	/*int *arr;
	int size =0;
	int maxN = 0;
	int minN = 0;
	scanf("%d", &size);

	arr = (int*)malloc(sizeof(int) * size);

	for (int i = 1; i < size; i++) {
		scanf("%d", &arr[i]);
		if (i < size && numx[i] > numx[i-1]) {
			minN = numx[i - 1];
		}
		else {
			maxN = numx[i];
		}
	}

	free(arr);*/


	/*
		�ڿ��� N�� �־����� ��, 1���� N���� �� �ٿ� �ϳ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
	*/


	/*
		�� �׽�Ʈ���̽����� A+B�� �� �ٿ� �ϳ��� ������� ����Ѵ�.
	*/

	printf("======== �˰��� =========\n");

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


	/*
		�� �׽�Ʈ ���̽����� "Case #x: "�� ����� ����, A+B�� ����Ѵ�. �׽�Ʈ ���̽� ��ȣ�� 1���� �����Ѵ�.
	*/

	/*
		Case #1: 1 + 1 = 2
	*/

	/*
		����� ����
		*
		**
		***
		****
		*****
		*
		* �����Է� :5
	*/

	int starNum = 0;
	scanf("%d", &starNum);
	for (int i = 0; i < starNum; i++) { // 0 ~ 4
		for (int j = starNum - 1; j > -1; j--) {
			if (i >= j) {
				printf("*");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}

	/*
		���� N���� �̷���� ���� A�� ���� X�� �־�����.
		�̶�, A���� X���� ���� ���� ��� ����ϴ� ���α׷��� �ۼ�
	*/
	//int n = 0;
	//int ix = 0;
	//int xa = 0;
	//scanf("%d %d", &n,&ix);
	//for (int i = 0; i < n; i++) {
	//	scanf("%d", &xa);
	//	if (xa < ix) {
	//		printf("%d ", xa);
	//	}
	//}
	//int numa1 = 0;
	//int numb1 = 0;
	//do {
	//	scanf("%d %d", &numa1, &numb1);
	//	if (numa1 != 0 && numb1 != 0) {
	//		printf("%d\n", numa1 + numb1);
	//	}
	//} while (numa1 != 0 && numb1 != 0);

	int numa9 = 0;
	int numb9 = 0;
	//do {
	//	scanf("%d %d", &numa9, &numb9);
	//	if (numa9 > 0 && numa9 < 10 && numb9 > 0 && numb9 < 10) {
	//		printf("%d\n", numa9 + numb9);
	//	}
	//} while (numa9 > 0 && numa9 < 10 && numb9 > 0 && numb9 < 10);

	/*while(1) {
		scanf("%d %d", &numa9, &numb9);
		if (!(numa9 > 0 && numa9 < 10 && numb9 > 0 && numb9 < 10)) {
			break;
		}
		printf("%d\n", numa9 + numb9);
	}*/


	//�Է�
	int input_num = 0;
	int first_num = 0;
	int second_num = 0;
	int sum_num = 0;
	int sum_last_num = 0;
	int new_num = 0; //���ο� ��ȣ
	int cnt10 = 0;

	scanf("%d", &input_num);
	new_num = input_num;
	//0 < A, B < 10
	do {

		if (new_num < 10) {
			first_num = new_num / 10;
			second_num = new_num % 10;
			sum_num = first_num + second_num;
			sum_last_num = sum_num % 10;//���� ���ڸ��� 
		}
		else {
			first_num = new_num / 10;
			second_num = new_num % 10;
			sum_num = first_num + second_num; //�� �ڸ� ���ڸ� ���Ѵ�.
			sum_last_num = sum_num % 10;//���� ���ڸ��� 
		}
		new_num = second_num * 10 + sum_last_num;

		cnt10++;
	} while (input_num != new_num);

	printf("%d\n", cnt10);

	char asdasd[4] = { 'a','b','c' };
	printf("�迭 ���� %d\n", strlen(asdasd));
	//������ �迭[4] �ڸ��� null�� ��� ���µ�, 
	//strlen�Լ��� �迭�� null�� ������ ���ڿ��� ���� �Ǻ��Ҽ� �ִ�.


	//1157
	//�Է� :
	// 1. ���ڿ� A �Է� �ޱ� 1,000,000
	// 1-1 ���ڿ��� �빮���̸� �ҹ��ڷ� ��ȯ
	// 2. ���ĺ� ���ڿ� alpha �Է� �ޱ� 26
	// 3. alpha �迭�� ���ڿ� a 2�� �ݺ��� ������ 
	// 3-1 ���� ������ ���ĺ� ī��Ʈ ���ڿ� beta �� +1�Է� �ޱ�
	// 4. �ִ񰪰� ������ ? �� ũ�� ū���� ��µǰ� ����

	scanf("%s", &alpha_arr);
	char mb = '#';
	int max = 0;
	int beta_count[92] = { 0 };
	int j = 0;
	while (alpha_arr[j] != 0) {//int i = 65; i <= 90; i++
		for (int i = 65; i <= 90; i++) {//alpha_arr[j] != 0

			if (alpha_arr[j] >= 'a' && alpha_arr[j] <= 'z') {
				alpha_arr[j] -= 32;
			}


			if ((char)i == alpha_arr[j]) {
				beta_count[i] += 1;

				if (beta_count[i] > max) {
					max = beta_count[i];
					mb = (char)i;
				}
				else if (beta_count[i] == max) {//������ ?
					mb = '?';
				}

				break;
			}

		}

		j++;
	}

	printf("%c\n", mb);



	//����ȭ
	// �Է� :
	//1. ���ڿ� A �Է� �ޱ� 1000000
	// ó�� : 
	//1. �ƽ�Ű �ڵ尪���� �빮�� A���� Z������ ������ �ݺ��� ������
	//2. ���ڿ� A�� �빮�ڷ� �ٲٰ� A���� Z������ ���° ���� 



	//ó�� :
	//��� :


	//2675
	//�Է� :
	// 1. �׽�Ʈ ���̽� T�Է� �ޱ� 1000
	// 2. T��ŭ �ݺ��� ������
	// 3. �ݺ������� �ݺ� Ƚ�� R�Է� �ޱ� 8
	// 4. ���ڿ� s �ޱ� 20
	// 5. s���ڿ� �ݺ����Ѽ� R�� ���������� ����ϱ�
	int logic_T;
	scanf("%d", &logic_T);

	//ó�� :
	for (int i = 0; i < logic_T; i++) {
		int logic_R;
		char logic_S[20];
		scanf("%d %s", &logic_R, &logic_S);
		for (int i = 0; i < strlen(logic_S); i++)
		{
			for (int j = 0; j < logic_R; j++)
			{
				printf("%c", logic_S[i]);
			}
		}
		printf("\n");
	}

	//��� :



	//10809
	//�Է� : 
	// 1. ù° �ٿ� �ܾ� S�� �־�����.(char 100�迭) , s�� �Է� �޴´�.
	// 2. ���ĺ� ���ڿ��� �޴´� 
	char logic_s[100] = { 0 };
	char logic_alpa[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	scanf("%s", logic_s);
	//ó�� : 
	// 1. ���ڿ� �ݺ��� ������
	// 1-1 . ���ڿ��� ���ĺ��� �ִ��� ������ �˻�
	// 1-1-1 . ���ĺ��� ������ -1
	// 1-1-2 . ���ĺ��� ������ 
	// 1-1-2-1. ���° ���ڿ��� �ִ��� �˻�
	//��� : 
	int logic_count = 0;
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 100; j++) {
			if (logic_s[j] != logic_alpa[i]) {
				logic_count = -1;
			}
			else {
				logic_count = j;
				break;
			}
		}
		printf("%d ", logic_count);
	}


	//����ȭ




	//�Լ��� ȣ���� ����� caller(main�Լ�), ȣ��� �Լ�(add�Լ�)�� callee��� �Ѵ�.
	//�Ű�����()�� �ʱ�ȭ �����ִ� �� a, b�� ���ڶ�� �Ѵ�. 
	int fun1 = add(1, 2);//ȣ�� ������ : �Լ��� ȣ�� �Ѵ�. 
	int fun2 = add(3, 4);
	int fun3 = add(5, 6);
	printf("%d\n", fun1);
	printf("%d\n", fun2);
	printf("%d\n", fun3);


	//11654
	//�Է� :
	//  ����, ���� int , char �� �Է� ������ �޴´�.
	char aci;
	scanf("%c", &aci);
	//ó�� :
	//��� : int ,char �� �ƽ�Ű �ڵ�� ��ȯ�� ��� ������ ����Ѵ�.
	printf("%d\n", aci);

	//11720
	// �Է� :
	// 1. ù ��° ���� �Է��� ������ ���� int �������� �Է¹���
	// 2. �ι� ° ���� ���ڿ� �Է¹��� => �迭�� ����
	// 3. ���� �� ���� ���� 
	int logic_n = 0;
	char logic_c[101] = { 0 };
	int logic_sum = 0;

	scanf("%d", &logic_n);
	scanf("%s", &logic_c);


	// ó�� :
	// 1. n ������ŭ �ݺ��� ���� �迭���� �����ϰ� ���հ� ���� �����ش�.
	for (int i = 0; i < logic_n; i++)
	{
		logic_sum += logic_c[i] - 48; //���ڿ����� int �� �������� �ƽ�Ű�ڵ� 48���������
	}

	// ��� :
	// 1. ���� �� ���
	printf("%d\n", logic_sum);



	//�Է� :
	// 1. ����� �׽�Ʈ ���̽� n �� �Է� �޴´�.
	//ó�� :
	// 2. n���� ��ŭ �ݺ����� ������.
	// 3. char �迭�� ���ڿ��� �Է� �޴´�. (80)
	// 4. ���ڿ��� o�� ���� count���ش�
	// 4-1. �� ���ڿ��� o �̸� count + 1�� �����ش�. => ī��Ʈ�� ������ ���� ó�� Ǭ��.
	// 
	//��� :
	// 5. count���� ����Ѵ�.
	int testcnt = 0;
	scanf("%d", &testcnt);
	for (int i = 0; i < testcnt; i++) {
		char testch[81];
		int testcount = 0;
		int testcount2 = 0;
		scanf("%80s", testch);
		for (int j = 1; j < strlen(testch) + 1; j++) {
			testcount = 0;
			for (int k = 0; k < j; k++) {
				if (testch[k] == 'O') {
					testcount++;
				}
				else {
					testcount = 0;
				}
			}

			testcount2 += testcount;
		}
		printf("%d\n", testcount2);

	}

	//5622
	//��ǥ : ��ȭ�� �ɱ����� �ʿ��� �ּ����� �ð��� ���Ͻÿ�
	// 1. ���� 1�� �ɷ��� 2�� �ɸ�, ��ĭ �� ���ڴ� 1�ʾ� ���ɸ�.
	// 2. ���ڷ� ǥ���� ���ڸ� ������ �ɸ��� �ð��� ���ϴ� ����.
	//�Է� : 
	// 1. �ҸӴ��� ���ڿ��� �Է¹��� (0��1 �� �Է� ����)
	char phone_alpha[16] = { 0 };
	scanf("%15s", phone_alpha);

	// 2. �ð� ���հ��� �����Ѵ�.
	int tel_time = 0;
	//ó�� :
	// 3. ���ڿ��� for �ݺ����� ����Ѵ� 2���� ũ�ų� ���� 15���� �۰ų� ����
	// 4. ���ĺ��� 3������ 1���� ��ȣ�� �����Ƿ�, �������� ������ ��ȣ�� ����Ѵ�.
	// 4-1. 
	for (int i = 0; i < strlen(phone_alpha); i++) {

		if (phone_alpha[i] >= 'a' && phone_alpha[i] <= 'z') {//�빮�� ���� 65 ~ 90
			phone_alpha[i] -= 32;
		}

		//�빮�� ������ �ݺ��� ����
		for (int j = 65; j <= 90; j++) {
			if (phone_alpha[i] == j) { //�ҸӴ� ���ڰ� �ش� �빮�ڸ�
				phone_alpha[i] = (j - 65) / 3 + 2 + 48; //012345....26 
				if (j == 83 || j == 86 || j == 89 || j == 90) {
					phone_alpha[i] = (j - 65) / 3 + 2 + 47;
				}

				//�ð��� ������
				tel_time += phone_alpha[i] + 1 - 48;
			}
		}
	}
	// 5. ��ȣ�� ��������� ��ȣ ���� ���� �ð� ���� �߰����ش�. 
	//��� :
	// 6. �� �ð��� ����Ѵ�.

	printf("%d", tel_time);










	//2908
	//��ǥ : �� ���� �Է� �ް� ���ڸ� �Ųٷ� ������� ���ϱ�
	//�Է� : 
	// 1. A�� B�� int �� ������ �Է� �޴´�. => 0�� ����
	int logic_A = 0;
	int logic_B = 0;

	char result_a[3] = { 0 };
	char result_b[3] = { 0 };


	scanf("%d", &logic_A);
	scanf("%d", &logic_B);

	//ó�� : s
	// 2. A�� B�� ���ڸ� �Ųٷ� �ݺ����� ���� �Է��Ѵ�.
	for (int i = 0; i < 3; i++) {
		result_a[2 - i] = logic_A % 10 + 48;
		logic_A = logic_A / 10;
		result_b[2 - i] = logic_B % 10 + 48;
		logic_B = logic_B / 10;
	}

	// 3. �μ��� �� �ϰ� ū���� ����Ѵ�. => char�� ������ ��ȯ �Ҷ� - 48 ��� �Ұ� 
	int logic_count_test = 1;
	for (int i = 0; i < 3; i++) {
		logic_A += (result_a[i] - 48) * logic_count_test;
		logic_B += (result_b[i] - 48) * logic_count_test;
		logic_count_test *= 10;
	}

	//��� : 
	if (logic_A > logic_B) {
		printf("%d\n", logic_A);
	}
	else {
		printf("%d\n", logic_B);
	}





	//1152
	//��ǥ : ���ڿ��� �� �ܾ� ���� ���ϱ� (���� �ƴ� �ܾ���) => fgets ���
	//�Է� :
	// 1. ���ڿ� str �� �Է� �޴´�. (1000000) , count ������ �����Ѵ�.
	char logic_str[1000001];
	int logic_count100 = 0;
	fgets(logic_str, 1000000, stdin); //������� ������ �ִ� �Լ� 

	//ó�� :
	// 2. ���ڿ� str�� �ݺ��� ������.
	// 2-1. ���ڰ� �����̸� count ���ش�.
	// 3. �� �� �ڸ��� �� ���ڸ��� �����̸� -1 count ���ش�.
	for (int i = 0; i < strlen(logic_str) - 1; i++) {
		if (logic_str[i] == ' ') {//strlen�� null ���� ���Ե�
			logic_count100 += 1;
		}
	}


	if (logic_str[0] == ' ') {
		logic_count100 -= 1;
	}
	if (logic_str[strlen(logic_str) - 2] == ' ') {
		logic_count100 -= 1;
	}


	//��� :
	printf("%d\n", logic_count100 + 1);

#pragma endregion



	return 0;
}


//�Լ�
	/*
		�Լ� : �Ϸ��� ������ �̸��� ���ΰ�
		�� �̸��� �ٿ�����?
		�����ϱ� ���ؼ�
	*/
	//�μ��� �Է¹޾� �� ������� ����ϴ� �Լ��� ������ �ߴ�.
int add(int a, int b) {
	int result = a + b;
	return result;
}