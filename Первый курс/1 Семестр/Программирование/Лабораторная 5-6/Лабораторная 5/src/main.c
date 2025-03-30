#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

//�������� �� ��������� ��������, �������� �� ����
int checkOnNums(char *str)
{
	for (int index = 0; str[index] != '\0'; index++)
	{
		if ((str[index] >= 48) && (str[index] <= 57))
		{

		}
		else
		{
			return 0;
		}
	}
	return 1;
}

//���� � ��������� �� ���������� ��������, �������� �� ����
void input(int *res)
{
	char str[300];
	scanf("%s", str);
	if (checkOnNums(&str[0]) != 1)
	{
		printf("������� �� �����. ����� 3\n");
		res[0] = 3;
	}
	else
	{
		res[0] = atoi(str);
	}
}

void handlerForTask(int* matrix, int lenOfMatrix)
{
	//������ ���. ������ � �������� ������
	int *res;
	res = (int*)malloc(lenOfMatrix * lenOfMatrix * sizeof(int));

	//��������� ��������� ���������� �������, ������� ����� ������������� ������ ��� 
	//�������� ������ �������� � ������ res
 	int index = 0;

	//���� � ������� ������������� �������� � �������
	for (int indexOfString = 0; indexOfString < lenOfMatrix; indexOfString++)
	{
		for (int indexOfCollum = 0; indexOfCollum < lenOfMatrix; indexOfCollum++)
		{
			if (matrix[indexOfString * lenOfMatrix + indexOfCollum] >= 0)
			{
				res[index] = matrix[indexOfString * lenOfMatrix + indexOfCollum];

				printf("%d ", res[index]);

				index++;
			}
		}
	}

	//���� � ������� ������������� �������� � �������
	for (int indexOfString = 0; indexOfString < lenOfMatrix; indexOfString++)
	{
		for (int indexOfCollum = 0; indexOfCollum < lenOfMatrix; indexOfCollum++)
		{
			if (matrix[indexOfString * lenOfMatrix + indexOfCollum] < 0)
			{
				res[index] = matrix[indexOfString * lenOfMatrix + indexOfCollum];

				printf("%d ", res[index]);

				index++;
			}
		}
	}
}

void allValueSetByProgram()
{
	//������ � ��������� �������
	int matrix[2][2] = 
	{ 
		{2, -10}, 
		{1, -20} 
	};
	int matrixLen = 2;

	//�������� ����������, ������� �������� ������� � ������
	handlerForTask(&matrix[0][0], matrixLen);

}

void allValueSetByUser()
{
	//����������� ������ �������
	int lenOfMatrix;
	printf("��� ������������ ������� M �� M ������� M: ");
	//���� � ��������� �� ������ ������ ����
	input(&lenOfMatrix);
	if (lenOfMatrix < 2)
	{
		printf("������ ������� ������������. ����������� 3\n");
		lenOfMatrix = 3;
	}
	
	//������ ���. ������ � �������� ������
	int *matrix;
	matrix = (int*)malloc(lenOfMatrix * lenOfMatrix * sizeof(int));

	//������ ������������ ��������� ������
	for (int indexOfString = 0; indexOfString < lenOfMatrix; indexOfString++)
	{
		for (int indexOfCollum = 0; indexOfCollum < lenOfMatrix; indexOfCollum++)
		{
			input(&matrix[indexOfString * lenOfMatrix + indexOfCollum]);
		}
	}

	//�������� ����������, ������� ������� ��������� ������
	handlerForTask(&matrix[0], lenOfMatrix);

	//������ ������ �� �������, ������� ��� �������� ���� �������
	free(matrix);
}

void lenOfMasAndMinMaxSetByUser()
{
	//����������� ������ �������
	int lenOfMatrix;
	printf("��� ������������ ������� M �� M ������� M(����� ������ 1): ");
	input(&lenOfMatrix);

	if (lenOfMatrix < 2)
	{
		printf("������ ������� ������������. ����������� 3\n");
		lenOfMatrix = 3;
	}

	//������ ���. ������ � �������� ������
	int *matrix;
	matrix = (int*)malloc(lenOfMatrix * lenOfMatrix * sizeof(int));

	//�������� �� ������������ ������������ � ����������� ��������, ������� ����� ���������������
	int max;
	printf("������� ������������ ����� ��� ���������(������ 0): ");
	input(&max);
	if (max < 1)
	{
		printf("������� ������������ �����, ����������� 10\n");
		max = 10;
	}

	int min;
	printf("������� ����������� ����� ��� ���������(������ -1 � ������ �������������): ");
	input(&min);
	if ((min < 0) || (min >= max))
	{
		printf("������� ������������ �����, ����������� max/2\n");
		min = max/2;
	}

	//��������� �������
	for (int indexOfString = 0; indexOfString < lenOfMatrix; indexOfString++)
	{
		for (int indexOfCollum = 0; indexOfCollum < lenOfMatrix; indexOfCollum++)
		{
			//� ������� ���������� ��������������� �����, ����������, ����� ����� ����� �������������, � ����� ���
			int mode = 1 + rand() % 2;
			if (mode == 1)
			{
				matrix[indexOfString * lenOfMatrix + indexOfCollum] = min + rand() % max;
				
				printf("%5d ", matrix[indexOfString * lenOfMatrix + indexOfCollum]);
			}
			else
			{
				matrix[indexOfString * lenOfMatrix + indexOfCollum] = -(min + rand() % max);

				printf("%5d ", matrix[indexOfString * lenOfMatrix + indexOfCollum]);
			}
		}
		printf("\n");
	}

	printf("\n");

	//�������� ����������, ������� ������� ��������� ������
	handlerForTask(&matrix[0], lenOfMatrix);

	//������ ������ �� �������, ������� ��� �������� ���� �������
	free(matrix);
}

int main()
{
	setlocale(LC_ALL, "rus");

	srand(LC_TIME, "NULL");

	//����� � ������������, ����� �� ����� ������������ ����� ���������
	int mode;
	printf("�������� ����� ������:\n\t1. ��� �������� �������� ����������\n\t2. ��� �������� �������� �������������\n\t3. ������������ ����� ������ ������ ������� � ���� � ��� ���. �����\n");
	input(&mode);

	printf("\n");

	//���������, ���������� �� ������ �����
	if ((mode > 0) && (mode < 4))
	{
		if (mode == 1)
		{
			//�������� ������� ������� ������, � ������ ���� ������ ������ �����
			allValueSetByProgram();
		}

		if (mode == 2)
		{
			//�������� ������� ������� ������, � ������ ���� ������ ������ �����
			allValueSetByUser();
		}

		if (mode == 3)
		{
			//�������� ������� �������� ������, � ������ ���� ������ ������ �����
			lenOfMasAndMinMaxSetByUser();
		}
	}
	else
	{
		//���� ������� ������ ��� - ������� �������������� ���������
		printf("����� ������������ �����. ������ ��������� ���������\n");
	}

	getch();

	return 0;
}