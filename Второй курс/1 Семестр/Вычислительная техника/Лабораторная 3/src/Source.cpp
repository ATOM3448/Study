#include <iostream>
using namespace std;
//7 �������
int main()
{
	_int32 a = 1;			//EAX
	_int32 b = 2;			//EAX
	_int16 c = 3;			//AX

	_int32 d = 0;			//EAX  (c/a)*c+b  
	_int32 e = 0;			//EAX  (b-c)/a*c
	_asm //���������� d
	{
		mov ax, c;
		cwde;					//�������� � � EAX

		mov edx, 0;				//�������� � ���� ������� 0
		div a;					//C/A
		mov d, eax;				//��������� ���������

		mov ax, c;				//��������� � ��� ������������
		cwde;

		mul d;					//����������� EAX �� D

		add ax, word ptr b;		//���������� ������� �����
		add dx, word ptr b[2];	//���������� ������� �����

		mov word ptr d, ax;		//��������� ���������
		mov word ptr d[2], dx;	
	}
	
	cout << d << " - " << hex << d << endl;

	bool f;

	_asm //���������� e
	{
		mov ax, c;				//��������  C �� B
		cwde;
		sbb b, eax; 
		mov eax, b;
		
		cmp eax, 0;				//���� EAX ������ ��� 0
		jnl pos1;				

		neg eax;				//�� ������ ���� � ������ ����
		mov f, 1;

		pos1:					//����� - ���

		mov edx, 0;				//�������� � ���� ������� 0
		idiv a;					//����� ��������� �� A
		mov e, eax;				//��������� ���������

		mov ax, c;				//��������� C �� dw
		cwde;

		imul e;					//�������� �� C

		mov word ptr e, ax;		//��������� ���������
		mov word ptr e[2], dx;
	}

	if (f)
	{
		cout << dec << -e << " - " << hex << -e << endl;
	}
	else
	{
		cout << dec << e << " - " << hex << e << endl;
	}
	

	system("pause");
	return 0;
}