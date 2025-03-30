#include <iostream>
using namespace std;

//7 �������
int main()
{
	_int16 count = 0;
	_int16 x = 0;
	_int16 y = 0;

	_int16 xOut = 0;
	_int16 yOut = 0;

	_asm
	{
		//������� ��� X
		mov cx, 256;

		//����� �������� ��� X
		pointone:

		//������� � X �������� ��������(X = CX - 129)
		mov x, cx;

		//������� X
		sub x, 129;

		//��������� ������ CX � ���� �� ����� ���� ������� Y
		push cx;

		//������� ��� Y
		mov cx, 256;

		//����� �������� ��� Y
		pointtwo:

		//������� � Y �������� ��������(Y = CX - 129)
		mov y, cx;
		
		//������� Y
		sub y, 129;

		//������� x-y
		mov ax, x;
		sub ax, y;

		//���������� ��������� � 50
		cmp ax, 50;

		//���� 50 < ��������, �� ���������� ������ 
		jle exittwo;
		
		//���������� ��������� � 80
		cmp ax, 80;

		//���� ��������� <= 80, �� ����������� count
		jg exitone;

		inc count;

		//���� 200�� ����
		cmp count, 200;
		jne exitThree;

		mov ax, x;
		mov xOut, ax;
		mov ax, y;
		mov yOut, ax;

		exitThree:

		//����� - �����
		exitone:
		exittwo:

		//"����" ��� �������� �������� Y
		loop pointtwo;

		//�������� �������� CX �� �����, �� ������������ � �������� X
		pop cx;

		//"����" ��� �������� �������� X
		loop pointone;
	}

	cout << "result of assembler: " << count  << "\nx 200: " << xOut << "\ny 200: " << yOut << endl;
	


	//���� �� C++ ��� �������� ����������� ����

	xOut = 0;
	yOut = 0;
	count = 0;

	for (int i = 256; i > 0; i--)
	{
		x = i - 129;
		for (int j = 256; j > 0; j--)
		{
			y = j - 129;
			if ((50 < (x-y)) && ((x-y) <= 80))
			{
				count++;
			}
			if (count == 200)
			{
				xOut = x;
				yOut = y;
			}
		}
	}

	cout << "\nresult of C++: " << count << "\nx 200: " << xOut << "\ny 200: " << yOut << endl;

	system("pause");

	return 0;
}