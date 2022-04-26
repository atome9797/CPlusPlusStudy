#include <stdio.h>

#pragma region ����������

//������ ���� : ����ü�� ����ϰ� ����� �����ؼ� ���
//������� ���� ���� ������ 0,1,2,3,4..�̾��� 
enum DayOfWeek {
	Sunday =0, //�ƹ� ���� �Ҵ� ���� ������ 0���� ���۵� 
	Monday,
	Tuesday,
	Wednesday,
	Friday,
	Saturday
};

//������ �̸��� ��ҹ���
enum hdmi_content_type {
	HDMI_CONTENT_TYPE_GRAPHICS,
	HDMI_CONTENT_TYPE_PHOTO,
	HDMI_CONTENT_TYPE_CINEMA,
	HDMI_CONTENT_TYPE_GAME
};

//typedef �͸� ������
typedef enum {
	Sunday = 0,
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday
}DayOfWeek2; //typedef �� �̿��Ͽ�, ������ ��Ī���� DayOfWeek2 ����

DayOfWeek2 week; //�������� ��Ī���� ����ü ���� ����

#pragma endregion

#pragma region ����ü
struct Flags {

	union {
		struct {
			unsigned short a : 3;
			unsigned short b : 2;
			unsigned short c : 7;
			unsigned short d : 4;
		};
		unsigned short e; //����ü�� 16��Ʈ ����
	};
};

struct Flags2 {
	unsigned int a : 2;
	unsigned int b : 1;
	unsigned int c : 6;
};


#pragma endregion

int main() {

	//��Ʈ �ʵ�� ����ü �Բ� ���
	struct Flags f1 = { 0, };
	f1.a = 4;
	f1.b = 2;
	f1.c = 80;
	f1.d = 15;
	
	printf("%d\n", f1.e);

	//����ü�� �÷��� �ʵ� �����
	struct Flags2 f2;
	f2.a = 0xffffffff; //0xffffffff 32��Ʈ�� ǥ���� ����ū���� �ǹ� => a�� ��Ʈ �ʵ�� 2�̹Ƿ� 11��µ�
	f2.b = 0xffffffff;
	f2.c = 0xffffffff;
	//11 1 111111 => 3 1 63
	printf("%u%u%u\n", f2.a,f2.b,f2.c); 
	


	//������ ����ϱ� => ������ �������� ������ �����ϱ� ������
	const int ValueA = 1;
	const int ValueB = 2;
	const int ValueC = 3;

	//������ ���� ����
	enum DayOfWeek week;
	week = Tuesday; //���������� �ش� ���� �ε������� ������
	printf("������ ������ %d\n", week);




	return 0;
}