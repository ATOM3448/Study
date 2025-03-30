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

void powMinPlus(int nums[], int masLen)
{
	for (int index = 0; index < masLen; index++)
	{
		//��������� �������� ��� ������� �������� �������
		if (index == 0)
		{
			if (nums[index] < nums[index + 1])
			{
				nums[index] *= nums[index];
			}
			continue;
		}

		//��������� �������� ��� ���������� �������� �������
		if (index == (masLen-1))
		{
			if (nums[index] < nums[index - 1])
			{
				nums[index] *= nums[index];
			}
			continue;
		}

		//�������� ��� ������ ������� ��������
		if ((nums[index - 1] > nums[index]) && (nums[index] < nums[index + 1]))
		{
			nums[index] *= nums[index];
			continue;
		}
	}

	//����� ����������� �������
	for (int index = 0; index < masLen; index++)
	{
		printf("%d ", nums[index]);
	}
}

void powMinMinus(int numses[], int masLen)
{
	int buferOne;
	int buferTwo;
	for (int index = 0; index < masLen; index ++)
	{
		//���������� �������� ���������
		buferOne = numses[index];

		//��������� �������� ��� ������� �������� �������
		if (index == 0)
		{
			if (numses[index] < numses[index + 1])
			{
				numses[index] *= numses[index];
			}

			//��������� �������������� �������� ��������
			buferTwo = buferOne;
			continue;
		}

		//��������� �������� ��� ���������� �������� �������
		if (index == (masLen - 1))
		{
			if (numses[index] < buferTwo)
			{
				numses[index] *= numses[index];
			}

			//��������� �������������� �������� ��������
			buferTwo = buferOne;
			continue;
		}

		//�������� ��� ������ ������� ��������
		if ((buferTwo > numses[index]) && (numses[index] < numses[index + 1]))
		{
			numses[index] *= numses[index];

			//��������� �������������� �������� ��������
			buferTwo = buferOne;
			continue;
		}

		//��������� �������������� �������� ��������
		buferTwo = buferOne;
	}

	//����� ����������� �������
	for (int index = 0; index < masLen; index++)
	{
		printf("%d ", numses[index]);
	}
}

int main()
{
	setlocale(LC_ALL, "rus");

	//�������� �� ������������ ������������ ������ �������
	int masLen = getSomeValueFromUser(0, 1000);

	//�������� �� ����������� ����������� ��������� ��������������� �����)
	int max = getSomeValueFromUser(0, 10000000);

	printf("\n");

	//���������� �������
	int numsPlus[1000];
	int numsMinus[1000];
	for (int index = 0; index < masLen; index++)
	{
		numsPlus[index] = rand()%(max+1);
		numsMinus[index] = numsPlus[index];
		printf("%d ", numsPlus[index]);
	}

	printf("\n");

	//�������� ������� �� ���������� � ������� ��������� ��������� � ������ ������� ����������
	powMinPlus(&numsPlus[0], masLen);

	printf("\n");

	powMinMinus(&numsMinus[0], masLen);

	return 0;
}