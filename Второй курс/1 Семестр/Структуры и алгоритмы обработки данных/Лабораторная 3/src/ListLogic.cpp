#include <iostream>
#include <string>
using namespace std;

namespace myTask
{
	struct Node
	{
		string info;
		Node* next;
		Node* last;
	};
	
	class MyList
	{
	public:
		//������ � �����
		Node* head;
		Node* tail;

		//�������������
		MyList()
		{
			head = NULL;
			tail = NULL;
		}

		~MyList()
		{
			Node* x = head;
			while (x)
			{
				Node* next = (*x).next;
				(*x).info = "";
				(*x).last = NULL;
				(*x).next = NULL;
				x = next;
			}
		}
		
		//������� ������� ����� �����
		void insertBefore(Node* node, string newData)
		{
			Node* newNode = new Node;
			(*newNode).info = newData;
			(*newNode).next = node;
			if ((*node).last)
			{
				(*newNode).last = (*node).last;
				(*(*node).last).next = newNode;
			}
			else
			{
				(*newNode).last = NULL;
				head = newNode;
			}
			(*node).last = newNode;
		}

		//������� ������� ����� ����
		void insertAfter(Node* node, string newData)
		{
			Node* newNode = new Node;
			(*newNode).info = newData;
			(*newNode).last = node;
			if ((*node).next)
			{
				(*newNode).next = (*node).next;
				(*(*node).next).last = newNode;
			}
			else
			{
				(*newNode).next = NULL;
				tail = newNode;
			}
			(*node).next = newNode;
		}

		//������� ������� ���� � ������, �������� ������� ������
		void insertBeginning(string newData)
		{
			if (head)
			{
				insertBefore(head, newData);
			}
			else
			{
				head = new Node;
				(*head).info = newData;
				(*head).next = NULL;
				(*head).last = NULL;
				tail = head;
			}
		}

		//������� ������� ���� � �����
		void insertEnd(string newData)
		{
			if (tail)
			{
				insertAfter(tail, newData);
			}
			else
			{
				insertBeginning(newData);
			}
		}

		//������� ������(� ������) �������� �� ������
		Node* findAtStart(string data)
		{
			Node* answer = head;

			while (answer)
			{
				if ((*answer).info == data)
				{
					return answer;
				}

				answer = (*answer).next;
			}

			cout << "������� �� ������";
			exit(EXIT_FAILURE);
		}

		//������� ������(� �����) �������� �� ������
		Node* findAtEnd(string data)
		{
			Node* answer = tail;

			while (answer)
			{
				if ((*answer).info == data)
				{
					return answer;
				}

				answer = (*answer).last;
			}

			cout << "������� �� ������";
			exit(EXIT_FAILURE);
		}

		//������� ������ �� ������
		string remove(string data)
		{
			Node* node = findAtStart(data);

			if (node == head)
			{
				if ((*node).next) 
				{
					head = (*node).next;
					(*head).last = NULL;
					string out = (*node).info;
					delete[] node;
					return out;
				}
				else
				{
					head = NULL;
					tail = NULL;
					string out = (*node).info;
					delete[] node;
					return out;
				}
			}
			else
			{
				if (node == tail)
				{
					if ((*node).last)
					{
						tail = (*node).last;
						(*tail).next = NULL;
						string out = (*node).info;
						delete[] node;
						return out;
					}
					else
					{
						head = NULL;
						tail = NULL;
						string out = (*node).info;
						delete[] node;
						return out;
					}
				}
				else
				{
					(*(*node).last).next = (*node).next;
					(*(*node).next).last = (*node).last;
					string out = (*node).info;
					delete[] node;
					return out;
				}
			}
		}

		//������� ������ �� ������ (�������)
		string remove()
		{
			Node* node = head;
			if (node)
			{

				if ((*node).next)
				{
					head = (*node).next;
					(*head).last = NULL;
					string out = (*node).info;
					delete[] node;
					return out;
				}
				else
				{
					head = NULL;
					tail = NULL;
					string out = (*node).info;
					delete[] node;
					return out;
				}
			}
			else
			{
				return NULL;
			}
		}
	};
}