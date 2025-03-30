#pragma once

#include "MyBaseClass.h"

namespace myTask
{
	class NewMatrix:MyBaseClass
	{
	private:
		static unsigned int counter;
	public:

		//����������� �� ���������
		explicit NewMatrix();

		//����������� � �����������
		NewMatrix(unsigned int _col, unsigned int _row, double* _data);

		//����������� ����������
		NewMatrix(const NewMatrix& _in);

		//����������� �����������
		NewMatrix(NewMatrix&& _in);

		//�������� �������� ��������
		unsigned int MyBaseClass::getNextId();

		//�������������
		//�������� �� ����������� ��������
		bool CheckAdd(const NewMatrix& _in)const;

		//�������������
		//�������� �� ����������� ���������
		bool CheckMul(const NewMatrix& _in)const;

		//�������� ������
		friend std::ostream& operator<<(std::ostream& _os, const NewMatrix& _in);

		//�������� �����������
		NewMatrix& operator=(const NewMatrix& _in);

		//�������� �����������
		NewMatrix& operator=(NewMatrix&& _in);

		//�������� +=
		NewMatrix& operator+=(const NewMatrix& _in);

		//�������� -=
		NewMatrix& operator-=(const NewMatrix& _in);

		//�������� *=
		NewMatrix& operator*=(const NewMatrix& _in);

		//�������� *= ������
		NewMatrix& operator*=(const double _in);
	};

	//��������������� ��������� +
	NewMatrix operator+(const NewMatrix& _left, const NewMatrix& _right);

	//��������������� ��������� -
	NewMatrix operator-(const NewMatrix& _left, const NewMatrix& _right);

	//��������������� ��������� *
	NewMatrix operator*(const NewMatrix& _left, const NewMatrix& _right);

	//��������������� ��������� * �� ������
	NewMatrix operator*(const NewMatrix& _left, const double _right);

}
