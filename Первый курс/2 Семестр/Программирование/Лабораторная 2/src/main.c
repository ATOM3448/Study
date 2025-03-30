#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int** genMatrix(int M, int N)
{
	int** mat = malloc(sizeof(int*) * M);
	for (int i = 0; i < M; i++)
	{
		printf("\n");
		mat[i] = malloc(sizeof(int) * N);
		for (int j = 0; j < N; j++)
		{
			mat[i][j] = rand()%5;
			printf("%4d ", mat[i][j]);
		}
	}
	printf("\n");
	return mat;
}

int* nums(int* string, int N, int* size)
{
	//���� ���-�� ��������� �����
	int countOfNums = 1;
	for (int i = 1; i < N; i++)
	{
		int flag = 1;
		for (int j = i-1; j >= 0; j--)
		{
			if (string[i] == string[j])
			{
				flag = 0;
			}
		}
		if (flag)
		{
			countOfNums++;
		}
	}

	//��������� ���������
	int* plenty = malloc(sizeof(int) * countOfNums);
	plenty[0] = string[0];
	int index = 1;
	for (int i = 1; i < N; i++)
	{
		int flag = 1;
		for (int j = i - 1; j >= 0; j--)
		{
			if (string[i] == string[j])
			{
				flag = 0;
			}
		}
		if (flag)
		{
			plenty[index++] = string[i];
		}
	}

	//��������� ���������
	for (int j = 0; j < countOfNums; j++)
	{
		for (int i = 0; i < (countOfNums - 1); i++)
		{
			if (plenty[i] > plenty[i + 1])
			{
				int buf = plenty[i];
				plenty[i] = plenty[i + 1];
				plenty[i + 1] = buf;
			}
		}
	}

	//������� ���������
	printf("\n");
	printf("\n");
	for (int i = 0; i < countOfNums; i++)
	{
		printf("%3d", plenty[i]);
	}
	printf("\n");

	*size = countOfNums;
	return plenty;
}

int countingSimilar(int* plenty, int lenghtOfPlenty, int** mat, int M, int N)
{
	//����������, ������������ ���-�� ������ �����
	int countOfSimilar = 0;

	//���������� ��� ������
	for (int i = 1; i < M; i++)
	{
		int size;
		int* bufPlenty = nums(mat[i], N, &size);
		if (size != lenghtOfPlenty)
		{
			continue;
		}

		int flag = 1;
		for (int j = 0; j < lenghtOfPlenty; j++)
		{
			if (bufPlenty[j] != plenty[j])
			{
				flag--;
				break;
			}
		}
		if (flag)
		{
			countOfSimilar++;
		}
	}

	
	return countOfSimilar;
}

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	//���� ��������
	int M;
	int N;
	printf("������� M: ");
	scanf("%d", &M);
	printf("������� N: ");
	scanf("%d", &N);

	//��������� �������
	int** mat = genMatrix(M, N);

	//��������� ���������
	int size;
	int* plenty = nums(mat[0], N, &size);

	//��������� ������ ������
	printf("\n������ ����� � ������: %d", countingSimilar(plenty, size, mat, M, N));

	free(mat);
	getch();
	return 0;
}