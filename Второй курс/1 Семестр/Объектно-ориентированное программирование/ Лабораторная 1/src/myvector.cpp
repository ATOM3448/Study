#include <iostream>
#include <ctime>
#include <math.h>
#include "myvector.h"
using namespace std;

namespace myClasses
{
			int My_Vector::newID = 0;

			//����������� ��������
			My_Vector::My_Vector(double _x = 0.0, double _y = 0.0, double _z = 0.0) :id{ newID++ }
			{
				cout << "�������� ����������� 1 ��� id: " << id << "\n";
				X = _x;
				Y = _y;
				Z = _z;				
			}

			//����������� �����������
			My_Vector::My_Vector(const My_Vector& early) :id{ newID++ }
			{
				cout << "�������� ����������� 2 ��� id: " << id << "\n";

				X = early.X;
				Y = early.Y;
				Z = early.Z;
			}
		
			//����������
			My_Vector::~My_Vector()
			{
				cout << "�������� ������������� id: " << id << "\n";
				X = 0.0;
				Y = 0.0;
				Z = 0.0;
			}

			int My_Vector::getId()
			{
				return id;
			}

			//������
			double My_Vector::get_X()const
			{
				return X;
			}
			double My_Vector::get_Y()const
			{
				return Y;
			}
			double My_Vector::get_Z()const
			{
				return Z;
			}

			//������
			void My_Vector::set_X(double _x)
			{
				X = _x;
			}
			void My_Vector::set_Y(double _y)
			{
				Y = _y;
			}
			void My_Vector::set_Z(double _z)
			{
				Z = _z;
			}

			//���������� ������ �������
			double My_Vector::mod()
			{
				double res = sqrt(X*X + Y*Y + Z*Z);
				return res;
			}

			//��������� ������� �� ������
			void My_Vector::multiplication(double _x)
			{
				X *= _x;
				Y *= _x;
				Z *= _x;
			}

			//����������� �������
			void My_Vector::copy(My_Vector& early)
			{
				X = early.X;
				Y = early.Y;
				Z = early.Z;
			}

			//����������
			void My_Vector::unitVect()
			{
				X /= mod();
				Y /= mod();
				Z /= mod();
			}

	

	//��������� ��������
	My_Vector sum(My_Vector& vectorOne, My_Vector& vectorTwo)
	{
		My_Vector C_one;
		C_one.set_X(vectorOne.get_X() + vectorTwo.get_X());
		C_one.set_Y(vectorOne.get_Y() + vectorTwo.get_Y());
		C_one.set_Z(vectorOne.get_Z() + vectorTwo.get_Z());
		return C_one;
	}

	//��������� ���������
	My_Vector sub(My_Vector& vectorOne, My_Vector& vectorTwo)
	{
		My_Vector C_two;
		C_two.set_X(vectorOne.get_X() - vectorTwo.get_X());
		C_two.set_Y(vectorOne.get_Y() - vectorTwo.get_Y());
		C_two.set_Z(vectorOne.get_Z() - vectorTwo.get_Z());
		return C_two;
	}
	
	//��������� ������������ ���������
	My_Vector multiplVect(My_Vector& vectorOne, My_Vector& vectorTwo)
	{
		My_Vector C_three;
		C_three.set_X(vectorOne.get_Y() * vectorTwo.get_Z() + vectorOne.get_Z() * vectorTwo.get_Y());
		C_three.set_Y(vectorOne.get_X() * vectorTwo.get_Z() + vectorOne.get_Z() * vectorTwo.get_X());
		C_three.set_Z(vectorOne.get_X() * vectorTwo.get_Y() + vectorOne.get_Y() * vectorTwo.get_X());
		return C_three;
	}

	//��������� ������������ ���������
	double multiplSkal(My_Vector& vectorOne, My_Vector& vectorTwo)
	{
		return (vectorOne.get_X() * vectorTwo.get_X() + vectorOne.get_Y() * vectorTwo.get_Y() + vectorOne.get_Z() * vectorTwo.get_Z());
	}
	
	//��������� ������
	double mySin(My_Vector& vectorOne, My_Vector& vectorTwo)
	{
		My_Vector C_three = multiplVect(vectorOne, vectorTwo);
		return (C_three.mod() / (vectorOne.mod() * vectorTwo.mod()));
	}

	//��������� ��������
	double myCos(My_Vector& vectorOne, My_Vector& vectorTwo)
	{
		return (multiplSkal(vectorOne, vectorTwo) / (vectorOne.mod() * vectorTwo.mod()));
	}
	
	//��������� ����
	double myAngle(My_Vector& vectorOne, My_Vector& vectorTwo)
	{
		return (acos(myCos(vectorOne, vectorTwo))*(180 /M_PI));
	}
}

