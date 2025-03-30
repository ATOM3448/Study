#include "MyBaseClass.h"
#include <iostream>
#include <iomanip>

using namespace std;

namespace myTask
{
	MyBaseClass::MyBaseClass(unsigned int _rows, unsigned int _cols, unsigned int* _counter, double* _data) : id{(*_counter)++}
	{
		cout << "I'm constructor, for id: " << id << endl;

		data = (double*)malloc(sizeof(double) * _cols * _rows);

		rows = _rows;
		cols = _cols;

		if (_data)
		{
			for (unsigned int i = 0; i < cols * rows; i++)
			{
				data[i] = _data[i];
			}

			return;
		}

		for (unsigned int i = 0; i < cols * rows; i++)
		{
			data[i] = i;
		}
	}

	//�������������
	MyBaseClass::~MyBaseClass()
	{
		cout << "I'm destrucor, for id: " << id << endl;

		if (data)
		{
			delete[] data;
		}
		
		rows = 0;
		cols = 0;
	}

	//�������� id
	int MyBaseClass::getId()const
	{
		return id;
	}

	//�������� ������
	int MyBaseClass::getRows()const
	{
		return rows;
	}

	//�������� ������
	void MyBaseClass::setRows(int _in)
	{
		rows = _in;
	}

	//�������� �������
	int MyBaseClass::getCols()const
	{
		return cols;
	}

	//�������� �������
	void MyBaseClass::setCols(int _in)
	{
		cols = _in;
	}

	//�������� ��������� �� ������ ������
	double* MyBaseClass::getData()const
	{
		return data;
	}

	//�������� ��������� �� ������ ������
	void MyBaseClass::setData(double* _in)
	{
		data = _in;
	}

	//�������� ��������
	double MyBaseClass::max()const
	{
		double max = data[0];
		for (unsigned int i = 1; i < rows*cols; i++)
		{
			if (max < data[i])
			{
				max = data[i];
			}
		}

		return max;
	}

	//�������� �������
	double MyBaseClass::min()const
	{
		double min = data[0];
		for (unsigned int i = 1; i < rows*cols; i++)
		{
			if (min > data[i])
			{
				min = data[i];
			}
		}

		return min;
	}
}