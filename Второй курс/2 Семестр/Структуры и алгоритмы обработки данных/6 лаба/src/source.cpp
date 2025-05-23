/*
10. Напишите программу, которая в неориентированном связном графе находит сильно связные компоненты.
Для представления графа в программе использовать списки смежности.
Данные о графе вводятся из файла.
Программа должна вывести для каждой сильно связной компоненте графа множество вершин, входящих в найденную компоненту сильной связности графа.
После завершения работы с динамическими структурами данных необходимо освободить занимаемую ими память.
*/

#include <iostream>
#include <locale.h>
#include "MyGraph.h"

using namespace std;
using namespace MyTask;

int main()
{
	setlocale(LC_ALL, "rus");

	MyGraph graph;

	graph.ImportFromFile("File.txt");

	graph.Components();

	system("pause");

	return 0;
}