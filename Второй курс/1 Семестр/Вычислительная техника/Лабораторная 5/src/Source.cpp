#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

//7 �������. ��������� ������� ������������� �������� �� 64 �������.
int main()
{
	int sumtimec = 0;
	int sumtimes = 0;
	int sumtimev = 0;
	time_t start;
	for (int i = 0; i < 100; i++)
	{
		//������ ������
		start = clock();

		//���� c++. ���������� � ������ ���������
		FILE* in, * out;
		unsigned __int8* buffer;
		unsigned __int32 wight, height;

		fopen_s(&in, "test.bmp", "rb");
		buffer = (unsigned __int8*)malloc(54);
		fread(buffer, 1, 54, in);

		for (int i = 0; i <= 3; i++)
		{
			wight = buffer[21 - i] | wight << 8;
			height = buffer[25 - i] | height << 8;
		}

		if (i == 0)
		{
			cout << wight << "x" << height << endl;
		}
		

		fopen_s(&out, "test2_cpp.bmp", "wb");
		fwrite(buffer, 1, 54, out);

		free(buffer);

		//���� c++. ����������, ����������� � ������ �����

		buffer = (unsigned __int8*)malloc(wight * height * 4);

		fread(buffer, 1, wight * height * 4, in);
		fclose(in);

		for (int i = 0; i < wight; i += 128)
		{
			for (int j = 0; j < height; j++)
			{
				for (int k = i; k < (i + 64); k++)
				{
					buffer[wight * 3 * j + k * 3 + 0] = 255;
					buffer[wight * 3 * j + k * 3 + 1] = 255;
					buffer[wight * 3 * j + k * 3 + 2] = 255;
				}
			}
		}

		fwrite(buffer, 1, wight * height * 4, out);
		fclose(out);

		free(buffer);

		//���� ������
		sumtimec += clock() - start;

		//������ ������
		start = clock();

		//���� ����������. ������. ���������� � ������ ���������

		in = NULL;
		out = NULL;
		buffer = NULL;
		wight = 0;
		height = 0;

		fopen_s(&in, "test.bmp", "rb");
		buffer = (unsigned __int8*)malloc(54);
		fread(buffer, 1, 54, in);

		//������� ������ � ������
		__asm
		{
			mov esi, buffer;			//��������� �� ������

			mov ecx, 3;					//�������� ��������� ������ � ������
			mov ebx, 18;
			mov eax, [esi + ebx];
			mov wight, eax;
			mov eax, [esi + ebx + 4];
			mov height, eax;
		}

		fopen_s(&out, "test2_scal.bmp", "wb");
		fwrite(buffer, 1, 54, out);

		free(buffer);

		//���� ����������. ������. ����������, ����������� � ������ �����
		buffer = (unsigned __int8*)malloc(wight * height * 4);

		fread(buffer, 1, wight * height * 4, in);
		fclose(in);

		__asm
		{
			//�������� ������ �� ������
			mov esi, buffer;

			//������ ������� ��� 1 �����
			mov ecx, wight;

		l1:
			//������� ������� � ����
			push ecx;

			//������ ����� ������� ��� 2 �����
			mov ecx, height;

		l2:
			//�������������� ����� �������, ������� ������������ � 3 ����� (wight*3*j)
			mov eax, 3;
			mul wight;
			mov ebx, height;
			sub ebx, ecx;
			mul ebx;
			mov ebx, eax;

			//�������������� ��������� ����� �������(+i*3). �� ��� ������������ �������� �� 1 �����, ������ ��������� � ������
			mov eax, ecx;	//��������� ������� �������� ��������
			pop ecx;		//������ �������� �������� � �������� �����
			push eax;		//�� ��� ����������� eax, ��������� �������� �������� �������� � �����

			mov eax, wight;
			sub eax, ecx;
			mov edx, 3;
			mul edx;
			add ebx, eax;
			mov eax, 0;

			//���������� �������� �������� 1 ����� � ���� � ������ �������� ��������
			pop eax;
			push ecx;
			mov ecx, eax;
			mov eax, 0;

			push ecx;
			mov ecx, 192;

		l3:
			//�������� �������
			mov[esi + ebx], 255;
			inc ebx;

			//�����
			loop l3;

			pop ecx;		//�������� ������� 2 ����� �� �����
			loop l2;

			pop ecx;		//�������� ������� 3 ����� �� �����
			sub ecx, 127;	//��������� �� �� 1 �������, � �� 64*2-1, �� �������������� � 64 ������� ���� � 3 �����
			cmp ecx, 0;		//���� ���� �������� ������� � ��������������(��� ������� �����) ecx - ������� �� 1 �����
			jle ex;
			loop l1;
		ex:
		}

		fwrite(buffer, 1, wight * height * 4, out);
		fclose(out);

		free(buffer);

		//���� ������
		sumtimes += clock() - start;

		//������ ������
		start = clock();

		//���� ����������. ������. ���������� � ������ ���������

		in = NULL;
		out = NULL;
		buffer = NULL;
		wight = 0;
		height = 0;

		fopen_s(&in, "test.bmp", "rb");
		buffer = (unsigned __int8*)malloc(54);
		fread(buffer, 1, 54, in);

		//������� ������ � ������
		__asm
		{
			mov esi, buffer;			//��������� �� ������

			mov ecx, 3;					//�������� ��������� ������ � ������
			mov ebx, 18;
			mov eax, [esi + ebx];
			mov wight, eax;
			mov eax, [esi + ebx + 4];
			mov height, eax;
		}

		fopen_s(&out, "test2_vect.bmp", "wb");
		fwrite(buffer, 1, 54, out);

		free(buffer);

		//���� ����������. ������. ����������, ����������� � ������ �����
		buffer = (unsigned __int8*)malloc(wight * height * 4);

		fread(buffer, 1, wight * height * 4, in);
		fclose(in);

		__asm
		{
			//�������� ������ �� ������
			mov esi, buffer;

			//������ ������� ��� 1 �����
			mov ecx, wight;

		l11:
			//������� ������� � ����
			push ecx;

			//������ ����� ������� ��� 2 �����
			mov ecx, height;

		l12:
			//�������������� ����� �������, ������� ������������ � 3 ����� (wight*3*j)
			mov eax, 3;
			mul wight;
			mov ebx, height;
			sub ebx, ecx;
			mul ebx;
			mov ebx, eax;

			//�������������� ��������� ����� �������(+i*3). �� ��� ������������ �������� �� 1 �����, ������ ��������� � ������
			mov eax, ecx;	//��������� ������� �������� ��������
			pop ecx;		//������ �������� �������� � �������� �����
			push eax;		//�� ��� ����������� eax, ��������� �������� �������� �������� � �����

			mov eax, wight;
			sub eax, ecx;
			mov edx, 3;
			mul edx;
			add ebx, eax;
			mov eax, 0;

			//���������� �������� �������� 1 ����� � ���� � ������ �������� ��������
			pop eax;
			push ecx;
			mov ecx, eax;
			mov eax, 0;

			push ecx;
			mov ecx, 48;

		l13:
			//�������� �������
			movd mm0, [esi + ebx];
			mov eax, 0xFFFFFFFF;
			movd mm1, eax;
			paddusb mm0, mm1;
			movd[esi + ebx], mm0;
			add ebx, 4;

			//�����
			loop l13;

			pop ecx;		//�������� ������� 2 ����� �� �����
			loop l12;

			pop ecx;		//�������� ������� 3 ����� �� �����
			sub ecx, 127;	//��������� �� �� 1 �������, � �� 64*2-1, �� �������������� � 64 ������� ���� � 3 �����
			cmp ecx, 0;		//���� ���� �������� ������� � ��������������(��� ������� �����) ecx - ������� �� 1 �����
			jle ex1;
			loop l11;
		ex1:
		}

		fwrite(buffer, 1, wight * height * 4, out);
		fclose(out);

		free(buffer);

		//���� ������
		sumtimev += clock() - start;

		cout << "\nEnd of iteration: " << i;
	}

	cout << "\nAverage code time in C++: " << sumtimec / 100 << "\nAverage code time in assembler via scalar: " << sumtimes / 100 << "\nAverage assembly code time via mmx: " << sumtimev / 100 << endl;

	system("pause");
	return 0;
}
