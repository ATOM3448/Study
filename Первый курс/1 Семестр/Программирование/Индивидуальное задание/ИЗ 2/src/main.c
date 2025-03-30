#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <math.h>

int boolMessage(int k, int max)
{
	srand(time(NULL));
	int num = rand()%(max+1);
	if (num < k)
	{
		return 1;
	}
	return 0;
}

int main()
{
	setlocale(LC_ALL, "rus");

	//�������� ����� K, ���� ��� ����������� - ������ ������
	int k;
	printf("������� ����� \"K\" (������ 1): ");
	scanf("%d", &k);
	if (k < 2)
	{
		printf("������� ������������ �����, ����������� 25");
		k = 25;
	}

	//�������� ����� N, ���� ��� ����������� - ������ ������
	int n;
	printf("\n������� ����� \"N\" (������ 0): ");
	scanf("%d", &n);
	if (n < 1)
	{
		printf("������� ������������ �����, ����������� �����, ������ �������� \"K\"");
		n = k/2;
	}

	//�������� ����������� ���������, ��� ��������� �����, ���� ��� ����������� - ������ ������
	int max;
	printf("\n������� ����������� ���������, ��� ��������� ����� (������ 0): ");
	scanf("%d", &max);
	if (max < 1)
	{
		printf("������� ������������ �����, ����������� �����, ������ \"K\"+2");
		max = k+2;
	}

	//�������� �������� ��������������� ������������������.
	for (int i = 0; i < n; i++)
	{
		if (boolMessage(k, max) > 0)
		{
			printf("\nTRUE");
			return 0;
		}
	}
	printf("\nFALSE");

	return 0;
}