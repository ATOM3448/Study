#include <iostream>

using namespace std;

namespace myTaskLogic
{
	class MyStack 
	{
	public:
		//��������� ������� � ����
		void Push(int num)
		{
			Node* NewNode = new Node();
			if (NewNode)
			{
				(*NewNode).next = top;
				(*NewNode).data = num;
				top = NewNode;
			}
			else
			{
				cout << "������ �������� ��������";
				exit(EXIT_FAILURE);
			}
		}

		//������ ������� �� �����
		int Pop()
		{
			if (top)
			{
				int out = (*top).data;
				Node* newTop = (*top).next;
				delete[] top;
				top = newTop;
				return out;
			}
			else
			{
				cout << "������ ������ ��������";
				exit(EXIT_FAILURE);
			}
		}

		//��������� �������� �������� � �����
		int Top()const
		{
			return (*top).data;
		}

		//�������� �� ���� ������
		bool IsEmpty()const
		{
			if (top)
			{
				return false;
			}
			else
			{
				return true;
			}
		}

	private:
		class Node
		{
		public:
			int data;
			Node* next;
			Node()
			{
				data = 0;
				next = NULL;
			}
		};

		Node* top = NULL;
	};
}