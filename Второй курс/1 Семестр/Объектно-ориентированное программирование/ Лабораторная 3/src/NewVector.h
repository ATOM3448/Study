#pragma once 

#include "MyBaseClass.h"

namespace myTask
{
	class NewVector:MyBaseClass
	{
	private:
		static unsigned int counter;
	public:

		//����������� �� ���������
		explicit NewVector();

		//����������� � �����������
		NewVector(unsigned int _col, double* _data);

		//����������� ����������
		NewVector(const NewVector& _in);

		//����������� �����������
		NewVector(NewVector&& _in);

		//�������� �������� ��������
		unsigned int MyBaseClass::getNextId();

		//�������������
		//�������� �� ����������� ��������
		bool CheckAdd(const NewVector& _in)const;

		//�������������
		//�������� �� ����������� ���������
		bool CheckMul(const NewVector& _in)const;

		//�������� ������
		friend std::ostream& operator<<(std::ostream& _os, const NewVector& _in);

		//�������� �����������
		NewVector& operator=(const NewVector& _in);

		//�������� �����������
		NewVector& operator=(NewVector&& _in);

		//�������� +=
		NewVector& operator+=(const NewVector& _in);

		//�������� -=
		NewVector& operator-=(const NewVector& _in);

		//�������� *=
		NewVector& operator*=(const NewVector& _in);

		//�������� *= ������
		NewVector& operator*=(const double _in);
	};

	//��������������� ��������� +
	NewVector operator+(const NewVector& _left, const NewVector& _right);

	//��������������� ��������� -
	NewVector operator-(const NewVector& _left, const NewVector& _right);

	//��������������� ��������� *
	NewVector operator*(const NewVector& _left, const NewVector& _right);

	//��������������� ��������� * �� ������
	NewVector operator*(const NewVector& _left, const double _right);

}
