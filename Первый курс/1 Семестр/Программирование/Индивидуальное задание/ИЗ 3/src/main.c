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

void findTo(int k, int n, int max)
{
	//���������� ������ � ����� � ������ ������
	for (int numberOfKitNumbers = 0; numberOfKitNumbers < k; numberOfKitNumbers++)
	{
		int flag = 0;
		for (int numberOfNumberInKit = 0; numberOfNumberInKit < n; numberOfNumberInKit++)
		{
			//���������� ����� � ������
			 int num = rand()%(max+1);

			 //���� ����� = 2, ����� ���� = 1, ������� ����� ������(+1 ��� ��� ��� ������������ ����� �� 1) � ����� � ������ ������
			 if (num == 2)
			 {
				 flag = 1;

				 printf("%d - %d\n", numberOfKitNumbers + 1, numberOfNumberInKit + 1);
				 break;
			 }
		}
		//���� ���� = 0, �.� ������ �� �������, ������� ����� ������ � 0
		if (flag == 0)
		{
			printf("%d - 0\n", numberOfKitNumbers + 1);
		}
	}
}

int main()
{
	setlocale(LC_ALL, "rus");

	//�������� ����� K
	int k = getSomeValueFromUser(0, 1000);
	
	//�������� ����� N
	int n = getSomeValueFromUser(0, 1000);

	//�������� ����������� �������� ����� ��� ���������
	int max = getSomeValueFromUser(0, 1000);

	//�������� ������� �� ����� ������� ������
	findTo(k, n, max);

	return 0;
}