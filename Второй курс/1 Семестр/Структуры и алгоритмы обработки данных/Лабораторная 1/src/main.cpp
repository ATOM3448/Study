#include <iostream>
#include <locale.h>

#include "stackLogic.cpp"
#include "queueLogic.cpp"

using namespace std;
using namespace myTaskLogic;

int main()
{
	setlocale(LC_ALL, "rus");

	MyStack stack;
	

	//�������� ����, � ����� ������� ��� ���������
	for (int i = 0; i < 100; i++)
	{
		int num = ;
		stack.Push(roll);
		cout << roll << " ";
	}

	cout << "\n" << endl;

	for (int i = 0; i < 100; i++)
	{
		int out = stack.Pop();
		cout << out << " ";
	}

	cout << "\n" << endl;

	MyQueue queue;

	//�������� �������, � ����� ������� ��� ��������
	for (int i = 0; i < 100; i++)
	{
		int roll = rand() % 10000;
		queue.Push(roll);
		cout << roll << " ";
	}

	cout << "\n" << endl;

	for (int i = 0; i < 100; i++)
	{
		int out = queue.Pop();
		cout << out << " ";
	}

	return 0;
}
