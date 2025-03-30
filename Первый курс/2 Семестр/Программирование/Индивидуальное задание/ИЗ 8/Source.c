#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>

struct order
{
	char payerAccount[21];
	char recipientAccount[21];
	int amount;

	short noNullFirst;
	short noNullSecond;
	short noNullThird;
};

int checkOnNums(char str[50])
{
	int flag = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if ((str[i] < '0') || (str[i] > '9'))
		{
			flag++;
			break;
		}
	}
	return flag;
}

void inputOfPayerAccount(int processedOrder, struct order* procOrder)
{
	char input[50];
	int out = 1;
	while (out)
	{
		system("cls");
		printf("�� ������������ \"�ר� �����������\" � ORDER #%d\n\n����: ", processedOrder);
		scanf("%s", &input);
		if (checkOnNums(input))
		{
			puts("������� ����� ��������� ����� �� 20 ����, ��� ��������\n������� ����� ������� ��� ������� �������!");
			system("pause>nul");
			continue;
		}

		if ((strlen(input) > 20) || (strlen(input) < 20))
		{
			puts("������� ����� ��������� ����� �� 20 ����, ��� ��������\n������� ����� ������� ��� ������� �������!");
			system("pause>nul");
			continue;
		}

		strcpy(procOrder[0].payerAccount, input);
		procOrder[0].noNullFirst = 1;
		puts("��������� �������, ��� ����������� ������� ����� �������.");
		system("pause>nul");
		break;
	}
}

void inputOfRecipientAccount(int processedOrder, struct order* procOrder)
{
	char input[50];
	int out = 1;
	while (out)
	{
		system("cls");
		printf("�� ������������ \"�ר� ����������\" � ORDER #%d\n\n����: ", processedOrder);
		scanf("%s", &input);
		if (checkOnNums(input))
		{
			puts("������� ����� ��������� ����� �� 20 ����, ��� ��������\n������� ����� ������� ��� ������� �������!");
			system("pause>nul");
			continue;
		}

		if ((strlen(input) > 20) || (strlen(input) < 20))
		{
			puts("������� ����� ��������� ����� �� 20 ����, ��� ��������\n������� ����� ������� ��� ������� �������!");
			system("pause>nul");
			continue;
		}

		strcpy(procOrder[0].recipientAccount, input);
		procOrder[0].noNullSecond = 1;
		puts("��������� �������, ��� ����������� ������� ����� �������.");
		system("pause>nul");
		break;
	}
}

void inputOfAmount(int processedOrder, struct order* procOrder)
{
	char input[50];
	int out = 1;
	while (out)
	{
		system("cls");
		printf("�� ������������ \"�����\" � ORDER #%d\n\n����: ", processedOrder);
		scanf("%s", &input);
		if (checkOnNums(input))
		{
			puts("�����, ������������ ����� ����� �� �� ����� ��� 9 � �� ����� ��� 1 ����.\n������� ����� ������� ��� ������� �������!");
			system("pause>nul");
			continue;
		}

		if ((strlen(input) > 9) || (strlen(input) < 1))
		{
			puts("�����, ������������ ����� ����� �� �� ����� ��� 9 � �� ����� ��� 1 ����.\n������� ����� ������� ��� ������� �������!");
			system("pause>nul");
			continue;
		}

		procOrder[0].amount = atoi(input);
		procOrder[0].noNullThird = 1;
		puts("��������� �������, ��� ����������� ������� ����� �������.");
		system("pause>nul");
		break;
	}
}

void editingMode(struct order* orders, int countOfOrders)
{
	system("cls");
	//����������� � ������������ ����� ORDER �� ����� �������������
	char input[50];
	printf("�������, ����� ORDER �� ������ �������������(1 - %d): ", countOfOrders);
	scanf("%s", &input);
	while ((getchar())!= '\n');
	if (checkOnNums(input))
	{
		puts("���������� �������� �����!\n������� ����� ������� ��� ������� �������!");
		system("pause>nul");
		return 0;
	}

	if ((atoi(input) < 1) || (atoi(input) > countOfOrders))
	{
		puts("�� ����� �� ������ ������������ ��������!\n������� ����� ������� ��� ������� �������!");
		system("pause>nul");
		return 0;
	}

	//����������� � ������������, ��� �� ����� ���������������
	int processedOrder = atoi(input);
	int out = 1;
	while (out)
	{
		system("cls");
		printf("�� ������������ ORDER #%d\n�������� �����: \n\t1. ������ ���� �����������\n\t2. ������ ���� ����������\n\t3. ������ �����\n\t4. ����� �� ��������������\n����: ", processedOrder);
		scanf("%s", &input);
		while ((getchar())!= '\n');

		if (checkOnNums(input))
		{
			puts("���������� �������� �����!\n������� ����� ������� ��� ������� �������!");
			system("pause>nul");
			continue;
		}

		if (strlen(input) > 1)
		{
			puts("�� ����� �� ������ ������������ ��������!\n������� ����� ������� ��� ������� �������!");
			system("pause>nul");
			continue;
		}

		switch (input[0])
		{
		case '1':
			inputOfPayerAccount(processedOrder, &orders[processedOrder+1]);
			break;
		case '2':
			inputOfRecipientAccount(processedOrder, &orders[processedOrder+1]);
			break;
		case '3':
			inputOfAmount(processedOrder, &orders[processedOrder+1]);
			break;
		case '4':
			out = 0;
			printf("\n�� ����� �� �������������� ORDER #%d!\n����� ���������� ������� ����� �������!\n", processedOrder);
			system("pause>nul");
			break;
		default:
			puts("�� ����� �� ������ ������������ ��������!\n������� ����� ������� ��� ������� �������!");
			system("pause>nul");
			break;
		}
	}
}

void viewingMode(struct order* orders, int countOfOrders)
{
	int out = 1;
	char input[50];
	while (out)
	{
		system("cls");
		puts("������� ���� ����� �����������, ���������� � ������ ����� �������� �� ������ �������: ");
		scanf("%s", &input);
		if (checkOnNums(input))
		{
			puts("������� ����� ��������� ����� �� 20 ����, ��� ��������\n������� ����� ������� ��� ������� �������!");
			system("pause>nul");
			continue;
		}

		if ((strlen(input) > 20) || (strlen(input) < 20))
		{
			puts("������� ����� ��������� ����� �� 20 ����, ��� ��������\n������� ����� ������� ��� ������� �������!");
			system("pause>nul");
			continue;
		}

		for (int i = 0; i < countOfOrders; i++)
		{
			if (!strcmp(input, orders[i].payerAccount))
			{
				if (orders[i].noNullThird)
				{
					printf("��������� �������: %d\n", orders[i].amount);
				}
				else 
				{
					printf("��������� �������: ���������� �� �������\n");
				}
				printf("��� ������ �� ������ ��������� ������� ����� �������.");
				system("pause>nul");
				return 0;
			}
		}
		printf("����� �� ������. ���������� ������.");
		system("pause>nul");
		return 0;
	}
}

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "rus");

	//����������� ���-�� �������
	int count;
	printf("������� ���-�� �������: ");
	scanf("%d", &count);
	while ((getchar()) != '\n');

	//������ ������
	struct order* orders = malloc(sizeof(struct order) * count);
	for (int i = 0; i < count; i++)
	{
		orders[i].noNullFirst = 0;
		orders[i].noNullSecond = 0;
		orders[i].noNullThird = 0;
	}

	//�����������, ��� ����� ������� ������������
	int out = 1;
	char input[50];
	while (out)
	{
		system("cls");
		printf("�������� �����:\n\t1. �������� ������ �� ORDER\n\t2. ������������� ������ ORDER\n\t3. �����\n����: ");
		scanf("%s", input);
		while ((getchar())!= '\n');

		if (checkOnNums(input))
		{
			puts("���������� �������� �����!\n������� ����� ������� ��� ������� �������!");
			system("pause>nul");
			continue;
		}

		if (strlen(input) > 1)
		{
			puts("�� ����� �� ������ ������������ ��������!\n������� ����� ������� ��� ������� �������!");
			system("pause>nul");
			continue;
		}

		switch (input[0])
		{
		case '1':
			viewingMode(&orders[0], count);
			break;
		case '2':
			editingMode(&orders[0], count);
			break;
		case '3':
			out = 0;
			puts("��������� ��������� ��� ����������!\n����� ���������� ������� ����� �������!");
			system("pause>nul");
			break;
		default:
			puts("�� ����� �� ������ ������������ ��������!\n������� ����� ������� ��� ������� �������!");
			system("pause>nul");
			break;
		}
	}

	return 0;
}