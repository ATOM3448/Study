#include <iostream>
#include <locale.h>
#include "MyGraph.h"

using namespace std;
using namespace MyTask;

/*
�������� ���������, ������� � ������� ��������� �������� ������� ����������� ����������� ������ ��� ������������� �������� ������������������ �����, ��������� �������� ���������. 
�������� �� ����� �����, �������� � ������� ������. 
������������� ���� ������ �� �����.
����� ���������� ������ � ������������� ����������� ������ ���������� ���������� ���������� ��� ������.
*/

int main()
{
	setlocale(LC_ALL, "rus");

	MyGraph graph;

	graph.ImportFromFile("File.txt");
	graph.ImportValues("Values.txt");

	graph.Kruskal();

	system("pause");

	return 0;
}
