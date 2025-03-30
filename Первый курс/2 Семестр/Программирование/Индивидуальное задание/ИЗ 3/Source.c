#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void matOut(int** matrix, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		printf("\n");
		for (int j = 0; j < n; j++)
		{
			printf("%4d ", matrix[i][j]);
		}
	}
}

int** matGen(int countOfString, int countOfCollum, int emptyCollums, short mode)
{
	//mode = 0 - ��������� ������, ��� ���������� ��������
	//mode = 1 - ��������� ������, �������� �������������, �� ���������
	//mode = 2 - ��������� ������, �������� �������������, ��� �����
	//�������� emptyCollums ���������, ������� �������� � ����� ����� �������

	int** matrix = malloc(sizeof(int**) * countOfString);
	for (int indexOfString = 0; indexOfString < countOfString; indexOfString++)
	{
		matrix[indexOfString] = malloc(sizeof(int) * (countOfCollum + emptyCollums));
		if (mode == 1)
		{
			for (int indexOfCollum = 0; indexOfCollum < (countOfCollum); indexOfCollum++)
			{
				matrix[indexOfString][indexOfCollum] = rand() % 100;
			}
		}
		if (mode == 2)
		{
			for (int indexOfCollum = 0; indexOfCollum < (countOfCollum); indexOfCollum++)
			{
				matrix[indexOfString][indexOfCollum] = rand() % 100;
				printf("%4d ", matrix[indexOfString][indexOfCollum]);
			}
			printf("\n");
		}
	}
	return matrix;
}

void finFunc(int** matrix, int m, int n, short modeFirstModule, short modeSecondModule)
{
	//modeFirstModule = 0 - � ������ ���� ������������ ����� ��������� ��������� - ������ ���������
	//modeFirstModule = 1 - � ������ ���� ������������ ����� ��������� ��������� - ������ ������
	//modeSecondModule = 0 - ����������� � �������� �� ������� - �������� ���. ��������
	//modeSecondModule = 1 - ����������� � ����� �������
	
	//���� ����������� �������
	int min = matrix[0][0];
	int numOfCollumWithMin = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (modeFirstModule)
			{
				if (matrix[i][j] < min)
				{
					min = matrix[i][j];
					numOfCollumWithMin = j;
				}
			}
			else
			{
				if (matrix[i][j] <= min)
				{
					min = matrix[i][j];
					numOfCollumWithMin = j;
				}
			}
		}
	}

	//��������� �������
	if (modeSecondModule)
	{
		for (int i = 0; i < m; i++)
		{
			matrix[i][n] = matrix[i][numOfCollumWithMin];
		}
	}
	else
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = n; j > numOfCollumWithMin; j--)
			{
				matrix[i][j] = matrix[i][j - 1];
			}
		}
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	//�������� ������� �������
	int m;
	int n;
	printf("������� M: ");
	scanf("%d", &m);
	printf("������� n: ");
	scanf("%d", &n);

	//���������� �������
	int** matrix = matGen(m, n, 1, 2);

	//��������� ������� � ����������� ���������
	finFunc(matrix, m, n, 0, 0);

	//�����
	matOut(matrix, m, n + 1);

	getch();
	return 0;
}