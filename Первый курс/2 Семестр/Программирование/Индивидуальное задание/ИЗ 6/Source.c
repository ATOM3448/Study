#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//� / � - -33 / -1
//� / � - -34 / -2
//� / � - -35 / -3
//� / � - -37 / -5
//� / � - -45 / -13
//� / � - -50 / -18
//� / � - -56 / -24
//� / � - -59 / -27
//� / � - -64 / -32
//� / � - -88 / -56


int getCount(char* str)
{
	int count = 0;

	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] > (-33))
		{
			str[i] -= 32;
		}
		switch (str[i])
		{
		case -33:
			count++;
			break;
		case -34:
			count++;
			break;
		case -35:
			count++;
			break;
		case -37:
			count++;
			break;
		case -45:
			count++;
			break;
		case -50:
			count++;
			break;
		case -56:
			count++;
			break;
		case -59:
			count++;
			break;
		case -64:
			count++;
			break;
		case -88:
			count++;
			break;
		default:
			break;
		}
	}

	return count;
}

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	//������ ������
	char str[] = "��� ���� �� ����� � ������ �����";

	//�������� ���������� �������
	int count = getCount(&str[0]);

	//�����
	printf("%d ", count);

	getch();
	return 0;
}