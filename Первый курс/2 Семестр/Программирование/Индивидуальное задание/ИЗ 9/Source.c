#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <locale.h>

//48 - 122

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	//������ ���������� ������, ������� �������� �� ������� ��������
	FILE *f, *g;
	/*f = fopen("F.txt", "w");
	fputc('\0', f);
	fclose(f);*/
	g = fopen("G.txt", "w");
	fputc('\0', g);
	fclose(g);

	////����������� ���� F
	//f = fopen("F.txt", "a");
	//for (int i = 0; i < 1000; i++)
	//{
	//	char c = 48 + rand() % 75;
	//	fputc(c, f);
	//	printf("%c", c);
	//}
	//printf("\n");
	//printf("\n");
	//printf("\n");
	//fclose(f);

	//������� �����
	f = fopen("F.txt", "r");
	rewind(f);
	g = fopen("G.txt", "a");
	rewind(g);

	//������������ �� F � G
	while (1)
	{
		char buf = fgetc(f);
		if (buf == EOF)
		{
			break;
		}
		if (buf == 48)
		{
			buf += 1;
		}
		printf("%c", buf);
		fputc(buf, g);
	}

	//��������� �����
	fclose(f);
	fclose(g);

	system("pause>nul");
	return 0;
}