#ifndef myvector_h
#define myvector_h

namespace myClasses
{
	class My_Vector
	{
	private:
		double X, Y, Z;
		static int newID;
		const int id;
	public:
		//����������� ��������
		explicit My_Vector(double _x, double _y, double _z);

		//����������� �����������
		My_Vector(const My_Vector& early);

		//�������������
		~My_Vector();

		int getId();

		//������
		double get_X()const;
		double get_Y()const;
		double get_Z()const;

		//������
		void set_X(double _x);
		void set_Y(double _y);
		void set_Z(double _z);

		//���������� ������ �������
		double mod();

		//��������� ������� �� ������
		void multiplication(double _x);

		//����������� �������
		void copy(My_Vector& early);

		//����������
		void unitVect();
	};
	My_Vector sum(My_Vector& vectorOne, My_Vector& vectorTwo);

	My_Vector sub(My_Vector& vectorOne, My_Vector& vectorTwo);

	My_Vector multiplVect(My_Vector& vectorOne, My_Vector& vectorTwo);

	double multiplSkal(My_Vector& vectorOne, My_Vector& vectorTwo);

	double mySin(My_Vector& vectorOne, My_Vector& vectorTwo);

	double myCos(My_Vector& vectorOne, My_Vector& vectorTwo);

	double myAngle(My_Vector& vectorOne, My_Vector& vectorTwo);
}

#endif