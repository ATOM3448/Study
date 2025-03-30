#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

void addOneEliment(int masLen, int mas[])
{
    int indexOfEndSeries = 0;
    int lenOfMaxSeries = 0;
    int lenOfSeries = 1;
    int buferOne;
    int buferTo;

    //���������� ��� ��������� �������, ���� ����� � ������� ������������ �����, � �������+1,
    //����������� ������ �����, ���� ����� �����������, ���������, ������ �� ��� ������� ������������
    //���� �� - ��������� ������������ ����� � ���������� ������ ����� �����
    for (int index = 0; index < masLen; index++)
    {
        if (mas[index] == mas[index + 1])
        {
            lenOfSeries++;
        }
        else
        {
            lenOfSeries = 1;
        }
        if (lenOfMaxSeries <= lenOfSeries)
        {
            lenOfMaxSeries = lenOfSeries;

            //��������� �����, ����� �������� ����������� �� 1
            buferTo = mas[index]; 

            if (lenOfMaxSeries > 1)
            {
                indexOfEndSeries = index + 1;
            }
            else
            {
                indexOfEndSeries = index;
            }
        }
    }

    //������������ �������� � �������
    for (int index = indexOfEndSeries; index <= masLen; index++)
    {
        //��������� ������� ��������
        buferOne = mas[index]; 
        //������� ����� ��������
        mas[index] = buferTo;
        //������������� �����, ������� ����� ����� ������ � ��������� ������� �������
        buferTo = buferOne;
    }

    //����� ��������� �������
    for (int index = 0; index <= masLen; index++)
    {
        printf("%d ", mas[index]);
    }
}

int main(void)
{
    setlocale(LC_ALL, "rus");

    //�������� ������������ ������ �������
    int masLen;
    printf("������� ������������ ������ ������� (������ 0 � ������ 1000)");
    scanf("%d", &masLen);
    if ((masLen < 1) || (masLen > 999))
    {
        printf("�������� ������������ �����. ����������� 10");
        masLen = 10;
    }

    //�������� ����������� ��������� ��������������� �����
    int max;
    printf("\n������� ����������� ��������� ��������������� ����� (������ 0)");
    scanf("%d", &max);
    if (max < 1)
    {
        printf("�������� ������������ �����. ����������� 10");
        max = 10;
    }
    printf("\n");

    //���������� � ������� ������
    int mas[1001];
    for (int index = 0; index < masLen; index++)
    {
        mas[index] = rand()%(max+1);
        printf("%d ", mas[index]);
    }

    printf("\n");

    addOneEliment(masLen, &mas[0]);

    return 0;
}