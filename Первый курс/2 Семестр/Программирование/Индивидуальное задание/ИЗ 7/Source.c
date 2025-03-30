#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct 
{
	char name[50];
	char secondName[50];
	char group[6];
	char** subject;
	int* mark;
}studentAcademicPerformance;

studentAcademicPerformance createNewStudent(char name[50], char secondName[50], char group[6], int defMarks)
{
	//������ ���������
	studentAcademicPerformance student;

	//������� ���
	strcpy(student.name, name);
	
	//������� �������
	strcpy(student.secondName, secondName);

	//������� ������
	strcpy(student.group, group);

	//������ � �������� ��������
	student.subject = malloc(sizeof(char*) * 6);
	for (int i = 0; i < 6; i++)
	{
		student.subject[i] = malloc(sizeof(char) * 10);
	}
	student.subject[0] = "Prog";
	student.subject[1] = "Math";
	student.subject[2] = "Info";
	student.subject[3] = "Engl";
	student.subject[4] = "Rus";
	student.subject[5] = "MatAnl";

	//������ ���� ������
	student.mark = malloc(sizeof(int) * 6);

	//������� ��������� �������� � ���� ������
	for (int i = 0; i < 6; i++)
	{
		student.mark[i] = defMarks;
	}

	//���������� ���������
	return student;
}

void objOut(studentAcademicPerformance student)
{
	printf("____________\n%s %s | %s\n------------\n", student.secondName, student.name, student.group);
	for (int i = 0; i < 6; i++)
	{
		printf("%s | %d\n------------\n", student.subject[i], student.mark[i]);
	}
	printf("\n\n\n");
}

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "rus");

	//�������� ������� � ��������� � ��������
	char names[10][50] = { {"���������"}, {"���������"}, {"������"}, {"��������"}, {"��������"}, {"������"}, {"�����"}, {"�����"}, {"����"}, {"����"} };
	char secondNames[10][50] = { {"������"}, {"������"}, {"�������"}, {"������������"}, {"����������"}, {"�������"}, {"��������"}, {"���������"}, {"��������"}, {"�������"} };
	char groups[10][6] = { {"431-3"}, {"431-2"}, {"431-1"}, {"441-1"}, {"441-2"}, {"341-3"}, {"532-3"}, {"143-3"}, {"214-2"}, {"411-3"} };

	//����������, ������� �������������
	int count;
	printf("������� �������� �������������: ");
	scanf("%d", &count);

	//����������
	studentAcademicPerformance* students = malloc(sizeof(studentAcademicPerformance) * count);
	for (int i = 0; i < count; i++)
	{
		students[i] = createNewStudent(names[rand()%10], secondNames[rand()%10], groups[rand()%10], 4);
		
		//����������� ��������� ������
		for (int j = 0; j < 6; j++)
		{
			students[i].mark[0] = 3 + rand() % 3;
			students[i].mark[1] = 3 + rand() % 3;
			students[i].mark[2] = 3 + rand() % 3;
			students[i].mark[3] = 3 + rand() % 3;
			students[i].mark[4] = 3 + rand() % 3;
			students[i].mark[5] = 3 + rand() % 3;
		}
	}

	//������� ������������ ��������
	for (int i = 0; i < count; i++)
	{
		objOut(students[i]);
	}

	//������� ���, � ���� ������ ������ > 3
	printf("��������� � ���������:\n");
	for (int i = 0; i < count; i++)
	{
		int flag = 1;
		for (int j = 0; j < 6; j++)
		{
			if (students[i].mark[j] < 4)
			{
				flag--;
				break;
			}
		}
		if (flag)
		{
			printf("%s %s\n", students[i].secondName, students[i].name);
		}
	}

	getch();
	return 0;
}