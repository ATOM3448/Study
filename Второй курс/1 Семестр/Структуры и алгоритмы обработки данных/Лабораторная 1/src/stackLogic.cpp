#include <iostream>

using namespace std;

namespace myTaskLogic
{
	class MyStack 
	{
	public:
		explicit MyStack()
		{
			size = 100;
			t = -1;
		}
		~MyStack()
		{
			delete[] stack;
			size = 0;
			t = 0;
		}

		//��������� ������� � ����
		void Push(int num)
		{
			if (t == (size - 1))
			{
				cout << "���������� �������� ������� ������������ �����" << endl;
				exit(EXIT_FAILURE);
			}
			else 
			{
				stack[++t] = num;
			}
		}

		//������ ������� �� �����
		int Pop()
		{
			if (t == -1)
			{
				cout << "���� ���� � �� ����� ������������ ��������" << endl;
				exit(EXIT_FAILURE);
			}
			else
			{
				int out = stack[t--];
				return out;
			}
		}

		//��������� �������� �������� � �����
		int Top()const
		{
			return stack[t];
		}

		//�������� �� ���� ������
		bool IsEmpty()const
		{
			if (t == -1)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

	private:
		short int t;
		int size;
		int stack[100];
	};
}