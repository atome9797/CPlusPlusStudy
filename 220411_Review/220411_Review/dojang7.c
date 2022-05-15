#include <stdio.h>

void bubble_sort(int arr[], int count)    // �Ű������� ������ �迭�� ����� ������ ����
{
    int temp;

    for (int i = 0; i < count; i++)    // ����� ������ŭ �ݺ�
    {
        for (int j = 0; j < count - 1; j++)   // ����� ���� - 1��ŭ �ݺ�
        {
            //a �� b�� ��ġ�� �ٲ�
            if (arr[j] > arr[j + 1])          // ���� ����� ���� ���� ����� ���� ���Ͽ�
            {                                 // ū ����
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;            // ���� ��ҷ� ����
            }
        }
    }
}



int main() {

	//��ǰ ���� �����ϱ�
    int numArr[10] = { 8, 4, 2, 5, 3, 7, 10, 1, 6, 9 };   // ���ĵ��� ���� �迭

    bubble_sort(numArr, sizeof(numArr) / sizeof(int));    // ��ǰ ���� �Լ� ȣ��

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", numArr[i]);    // 1 2 3 4 5 6 7 8 9 10
    }

    printf("\n");


	return 0;
}