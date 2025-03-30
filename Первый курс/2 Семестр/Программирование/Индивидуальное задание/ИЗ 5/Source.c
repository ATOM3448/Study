#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

char** getDict(char* str, int* secOut)
{
	//��������� ����� � ������
	int countOfWords = 1;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ',')
		{
			countOfWords++;
		}
	}

	//��������� ������ ������� �����
	int* lenOfWord = malloc(sizeof(int) * countOfWords);
	int indexOfWord = -1;
	int flag = 1;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if ((str[i] == ',') || (str[i] == ' '))
		{
			flag = 1;
		}
		if ((str[i] != ',') && (str[i] != ' ') && (flag == 0))
		{
			lenOfWord[indexOfWord]++;
		}
		if (((str[i] != ',') && (str[i] != ' ')) && (flag == 1))
		{
			flag = 0;
			indexOfWord++;
			lenOfWord[indexOfWord] = 1;
		}
	}

	//������ ������� ��� �������
	char** dictionary = malloc(sizeof(char*) * countOfWords);
	for (int i = 0; i < countOfWords; i++)
	{
		dictionary[i] = malloc(sizeof(char) * (lenOfWord[i] + 1));
	}

	//������� ���� ����� � �������
	indexOfWord = 0;
	flag = 0;
	int indexInWord = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if ((str[i] == ',') || (str[i] == ' '))
		{
			flag = 1;
		}
		if ((str[i] != ',') && (str[i] != ' ') && (flag == 0))
		{
			dictionary[indexOfWord][indexInWord++] = str[i];
		}
		if (((str[i] != ',') && (str[i] != ' ')) && (flag == 1))
		{
			flag = 0;
			dictionary[indexOfWord++][indexInWord] = '\0';
			indexInWord = 0;
			dictionary[indexOfWord][indexInWord++] = str[i];
		}
	}
	dictionary[indexOfWord][indexInWord] = '\0';

	//������� ���-�� ��������� ����
	int countOfUnic = 0;
	int* indexOfRepeapts = malloc(sizeof(int) * countOfWords);
	int ind = 0;
	for (int i = 0; i < countOfWords; i++)
	{
		int flags = 0;
		for (int k = 0; k < ind; k++)
		{
			if (i == indexOfRepeapts[k])
			{
				flags++;
				break;
			}
		}
		if (flags)
		{
			continue;
		}
		for (int j = 0; j < countOfWords; j++)
		{
			if (i == j)
			{
				continue;
			}
			if (!strcmp(dictionary[i], dictionary[j]))
			{
				indexOfRepeapts[ind++] = j;
			}
		}
		int flagTwo = 1;
		for (int j = 0; j < ind; j++)
		{
			if (i == indexOfRepeapts[j])
			{
				flagTwo--;
				break;
			}
		}
		if (flagTwo)
		{
			countOfUnic++;
		}
	}

	//��������� �������� ������ �������, ��� ��������
	char** finalDictionary = malloc(sizeof(char*) * countOfUnic);
	int indexForFD = 0;
	for (int i = 0; i < countOfWords; i++)
	{
		int flagTwo = 1;
		for (int j = 0; j < ind; j++)
		{
			if (i == indexOfRepeapts[j])
			{
				flagTwo--;
			}
		}
		if (flagTwo)
		{
			finalDictionary[indexForFD] = malloc(sizeof(char) * strlen(dictionary[i]));
			strcpy(finalDictionary[indexForFD++], dictionary[i]);
		}
	}

	//��������� ������
	free(dictionary);
	free(lenOfWord);
	free(indexOfRepeapts);

	*secOut = countOfUnic;
	return finalDictionary;
}

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	//������ ������
	char str[] = " text,some,text,text,that,separated,by, spaces, with, repetitions, by, repetitions, that";
	char separator[] = ", ";

	//������ "�������"
	int countOfWords;
	char** dictionary = getDict(&str[0], &countOfWords);

	//���������� ������
	int sizeOfString = sizeof(char);
	for (int i = 0; i < countOfWords; i++)
	{
		sizeOfString += sizeof(char) * (strlen(dictionary[i]) * strlen(separator) - strlen(separator));
	}
	char* string = malloc(sizeOfString);
	string[0] = '\0';
	for (int i = 0; i < countOfWords; i++)
	{
		strcat(string, dictionary[i]);
		if ((countOfWords - i) != 1)
		{
			strcat(string, separator);
		}
	}

	//����� ����������
	puts(string);

	getch();
	return 0;
}