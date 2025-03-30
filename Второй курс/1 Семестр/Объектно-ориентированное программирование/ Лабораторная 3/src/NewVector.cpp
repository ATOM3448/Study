#include "NewVector.h"
#include <iostream>
#include <iomanip>

using namespace std;

namespace myTask
{
	//������� id
	unsigned int NewVector::counter = 0;

	//����������� �� ���������
	NewVector::NewVector() : MyBaseClass(1, 3, &counter, nullptr)
	{
		cout << "Constructor #1 for id: " << id << endl;
	}

	//����������� � �����������
	NewVector::NewVector(unsigned int _col, double* _data) : MyBaseClass(1, _col, &counter, _data)
	{
		cout << "Constructor #2 for id: " << id << endl;
	}

	//����������� ����������
	NewVector::NewVector(const NewVector& _in) : MyBaseClass(_in.rows, _in.cols, &counter, _in.data)
	{
		cout << "Constructor #3 for id: " << id << endl;
	}

	//����������� �����������
	NewVector::NewVector(NewVector&& _in) : MyBaseClass(_in.rows, _in.cols, &counter, _in.data)
	{
		_in.rows = 0;
		_in.cols = 0;
		_in.data = nullptr;

		cout << "Constructor #4 for id: " << id << endl;
	}
	
	//�������� �������� ��������
	unsigned int NewVector::getNextId()
	{
		return counter;
	}

	//�������� �� ����������� ���������
	bool NewVector::CheckMul(const NewVector& _right)const
	{
		if (cols == _right.getCols())
		{
			return 1;
		}

		if (rows == _right.getCols())
		{
			return 1;
		}

		return 0;
	}

	//�������� ���������
	NewVector& NewVector::operator*=(const NewVector& _right)
	{
		if (!CheckMul(_right))
		{
			throw logic_error{ "������ ������� ����������� ������" };
		}

		double* buf = _right.getData();

		if (_right.getRows() == 1)
		{
			for (unsigned int i = 0; i < cols; i++)
			{
				data[i] *= buf[i];
			}

			return *this;
		}

		return *this;
	}

	//�������� ����������� ��������
	bool NewVector::CheckAdd(const NewVector& _in)const
	{
		if ((this->rows == _in.rows) && (this->cols == _in.cols))
		{
			return 1;
		}

		return 0;
	}

	//��������������� ��������� <<
	ostream& operator<<(ostream& _os, const NewVector& _in)
	{
		double* buf = _in.getData();
		unsigned int row = _in.getRows();
		unsigned int col = _in.getCols();
		for (unsigned int i = 0; i < row; i++)
		{
			_os << endl;
			for (unsigned int j = 0; j < col; j++)
			{
				_os << setw(6) << fixed << setprecision(3) << buf[i * col + j] << " ";
			}
		}
		_os << endl << endl;
		return _os;
	}

	//�������� �����������
	NewVector& NewVector::operator=(const NewVector& _in)
	{
		if (!((rows == _in.rows) && (cols == _in.cols)))
		{
			delete[] data;

			rows = _in.rows;
			cols = _in.cols;

			data = (double*)malloc(sizeof(double) * cols * rows);
		}

		for (unsigned int i = 0; i < rows; i++)
		{
			for (unsigned int j = 0; j < cols; j++)
			{
				data[i * cols + j] = _in.data[i * cols + j];
			}
		}

		return *this;
	}

	//�������� �����������
	NewVector& NewVector::operator=(NewVector&& _in)
	{

		double* buf = _in.data;
		_in.data = data;
		data = buf;

		unsigned int bufInt = _in.rows;
		_in.rows = rows;
		rows = bufInt;

		bufInt = _in.cols;
		_in.cols = cols;
		cols = bufInt;

		return *this;
	}

	//�������� +=
	NewVector& NewVector::operator+=(const NewVector& _in)
	{
		if (!CheckAdd(_in))
		{
			throw logic_error{ "������ ������� ���������� ������" };
		}

		for (unsigned int i = 0; i < cols * rows; i++)
		{
			data[i] += _in.data[i];
		}

		return *this;
	}

	//�������� -=
	NewVector& NewVector::operator-=(const NewVector& _in)
	{
		if (!CheckAdd(_in))
		{
			throw logic_error{ "������ ������� ������ ��������" };
		}

		for (unsigned int i = 0; i < cols * rows; i++)
		{
			data[i] -= _in.data[i];
		}

		return *this;
	}

	//�������� *= ������
	NewVector& NewVector::operator *= (const double _in)
	{
		for (unsigned int i = 0; i < rows*cols; i++)
		{
			data[i] *= _in;
		}

		return *this;
	}

	//��������������� ��������� +
	NewVector operator+(const NewVector& _left, const NewVector& _right)
	{
		if (!_left.CheckAdd(_right))
		{
			throw logic_error{ "������ ������� ���������� ������" };
		}

		NewVector toOut(_left);

		return toOut += _right;
	}

	//��������������� ��������� -
	NewVector operator-(const NewVector& _left, const NewVector& _right)
	{
		if (!_left.CheckAdd(_right))
		{
			throw logic_error{ "������ ������� �������� ������" };
		}

		NewVector toOut(_left);

		return toOut -= _right;
	}

	//��������������� ��������� *
	NewVector operator*(const NewVector& _left, const NewVector& _right)
	{
		if (!_left.CheckMul(_right))
		{
			throw logic_error{ "������ ������� �������� ������" };
		}

		NewVector toOut(_left);

		return toOut *= _right;
	}

	//��������������� ��������� * �� ������
	NewVector operator*(const NewVector& _left, const double _right)
	{
		NewVector toOut(_left);

		return toOut *= _right;
	}
}