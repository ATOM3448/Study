#pragma once

#include <iostream>

namespace myTask
{
	class MyBaseClass
	{
	public:
		//�������� �����������
		explicit MyBaseClass(unsigned int _rows, unsigned int _cols, unsigned int* _counter, double* _data = nullptr);

		//����������
		~MyBaseClass();

		//�������� id
		int getId()const;

		//�������� �������� ��������
		virtual unsigned int getNextId() = 0;

		//�������� ������
		int getRows()const;

		//�������� ������
		void setRows(int _in);

		//�������� �������
		int getCols()const;

		//�������� �������
		void setCols(int _in);

		//�������� ��������� �� ������ ��������
		double* getData()const;

		//�������� ��������� �� ������ ��������
		void setData(double* _in);

		//��������
		double max()const;

		//�������
		double min()const;

	protected:
		double* data;
		unsigned int rows;
		unsigned int cols;
		const int id;
	};
}