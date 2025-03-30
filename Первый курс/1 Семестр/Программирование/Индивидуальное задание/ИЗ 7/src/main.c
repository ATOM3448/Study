#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <math.h>

int detector(int vertLen, int horLen, int matrix[])
{
	//���������� ��� ���������
	for (int vertIndex = (vertLen - 1); vertIndex >= 0; vertIndex--)
	{
		int flag = 0;
		for (int horIndex = 0; horIndex < horLen; horIndex++)
		{
			//�� �������� � ������� ��������� ������ ������, ���� �� ��������� � ��������� ������ � �������� �� � ������� ������ 
			//� ������ ������ �������� �� ���� ��������, �� ������� ������ �������� �� �������
			if ((matrix[vertIndex*50+horIndex] % 2 != 0) || (matrix[vertIndex*50+horIndex] == 0))
			{
				flag++;
				break;
			}
		}
		if (flag == 0)
		{
			return vertIndex+1;
			break;
		}
	}
	return 0;
}

int main()
{
	setlocale(LC_ALL, "rus");

	srand(time(NULL));

	//�������� ���-�� �����, ���� ����� �� ��������� - ������ ������
	int vertLen;
	printf("������� ���-�� ����� � �������(����� ������ 0 � ������ 51): ");
	scanf("%d", &vertLen);
	if ((vertLen < 1) || (vertLen > 50))
	{
		printf("����� �����������, ������������ �������� 25");
		vertLen = 25;
	}

	//�������� ���-�� ��������, ���� ����� �� ��������� - ������ ������
	int horLen;
	printf("\n������� ���-�� �������� � �������(����� ������ 0 � ������ 51): ");
	scanf("%d", &horLen);
	if ((horLen < 1) || (horLen > 50))
	{
		printf("����� �����������, ������������ �������� 25");
		horLen = 25;
	}

	//��������� � �������� ������������ �����, ��� �� ����� �������� ��� ��������� �����, ���� ����� �� ��������� - ������������� ������
	int maxValue;
	printf("\n������� ����������� ���������� �����, ��� ��������� ��������������� �����, ������ ������ ��� ����� 0: ");
	scanf("%d", &maxValue);
	if (maxValue < 0)
	{
		printf("������� ������������ ��������. ����������� 10");
		maxValue = 10;
	}

	//���������� �������
	int matrix[50][50];
	for (int vertIndex = 0; vertIndex < vertLen; vertIndex++)
	{
		for (int horIndex = 0; horIndex < horLen; horIndex++)
		{
			matrix[vertIndex][horIndex] = rand()%(maxValue + 1);
		}
	}

	//�������� ������, � ������ � ���������� - 0
	int numberOfResString = detector(vertLen, horLen, &matrix[0][0]);//������� ��������� �� ������, � �� ������

	//�����, ��������� �� ������ ������
	if (numberOfResString > 0)
	{
		printf("\n��������� ������ � ������� ������� - %d", numberOfResString);
	}
	else
	{
		printf("\n������ � ������� ������� ����������");
	}
}