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

void reflection(int** matrix, int m)
{
	int startPoint = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = startPoint++; j < m; j++)
		{
			int buf = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = buf;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	//�������� ������� �������
	int m;
	printf("������� M: ");
	scanf("%d", &m);

	//���������� �������
	int** matrix = matGen(m, m, 0, 2);

	//��������
	reflection(matrix, m);

	//�����
	matOut(matrix, m, m);

	getch();
	return 0;
}