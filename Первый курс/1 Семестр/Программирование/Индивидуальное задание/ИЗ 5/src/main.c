#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int getSomeValueFromUser(int min, int max)
{
	int res;
	printf("\n������� ����� (������ %d � ������ %d): ", min, max);
	scanf("%d", &res);
	if ((res <= min) || (res >= max))
	{
		printf("����� �����������, ����������� 1");
		res = 1;
	}
	return res;
}

void addNewZeroInIndex(int nums[], int masLen, int indexOfNewValue)
{
	int buferOne = 0;
	int buferTo;
	for (int index = indexOfNewValue; index <= masLen; index++)
	{
		//��������� ������� �������� ��������
		buferTo = nums[index];

		//������� ����� ��������
		nums[index] = buferOne;

		//������������� �����, ������� ����� ������ � ��������� ��������
		buferOne = buferTo;

	}

	//������� ������������ ������, ��� �������
	for (int index = 0; index <= masLen; index++)
	{
		printf("%d ", nums[index]);
	}
}

int main()
{
	setlocale(LC_ALL, "rus");

	//��������� � �������� �� ������������ ������ �������
	int masLen = getSomeValueFromUser(0, 1000);

	//��������� � �������� �� ������������ ������ ������ �����(�������� 1, �� ������������ ������ �������, ������ �� 1, � �� �� 0)
	int indexOfNewValue = getSomeValueFromUser(0, masLen+1) - 1;

	//��������� � �������� �� ������������ ����������� ��������� �����, ������� ����� ���� �������������
	int max = getSomeValueFromUser(0, 100000000);

	printf("\n");

	//���������� ������
	int nums[1000];
	for (int index = 0; index < masLen; index++)
	{
		nums[index] = rand()%(max + 1);

		//������� �������� ��� �������
		printf("%d ", nums[index]);
	}

	printf("\n");

	//��������� 0 � ������
	addNewZeroInIndex(&nums[0], masLen, indexOfNewValue);

	return 0;
}