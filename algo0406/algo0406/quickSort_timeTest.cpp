#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

void quickSort(int *ary, int size);
void output(int *ary, int size);
void initArray(int *ary, int n);
void initArrayRandom(int *ary, int n);

int main()
{
	int dataList[10000];

	int startTime, endTime;
	int size = sizeof(dataList) / sizeof(dataList[0]);

	srand((unsigned int)time(NULL));

	initArray(dataList, size);
	startTime = clock();
	quickSort(dataList, size); 	/* �� ���� �Լ� ȣ�� */
	endTime = clock();
	printf("\n\n[ ������������ ��Ʈ�� ������ �� ����  �� ��� ]\n");
	//output(dataList, size);
	printf("������������ ��Ʈ�� ������ ����Ʈ �˰��� ���� �ҿ�ð� : %d(millisecond)\n", (endTime - startTime));

	initArrayRandom(dataList, size);
	startTime = clock();
	quickSort(dataList, size); 	/* �� ���� �Լ� ȣ�� */
	endTime = clock();
	printf("\n\n[ ���� ���� ������ �� ����  �� ��� ]\n");
	//output(dataList, size);
	printf("���� ���� ������ ����Ʈ �˰��� ���� �ҿ�ð� : %d(millisecond)\n", (endTime - startTime));

	getchar();
	return 0;
}
/*----------------------------------------------------------------------
�Լ��� �� ��� : quickSort() - �� ���� �Լ�
��������: ary - ������ ������ �迭�� �����ּ� / size - ��Ʈ�� �������� ����
���ϰ�: ����
--------------------------------------------------------------------*/
void quickSort(int *ary, int size)
{
	
	int pivot, temp;

	if (size <= 1) return;
	pivot = ary[size-1];

	int i = 0;
	int j = size - 2;
	while (1)
	{
		for (; i < size; i++)
		{
			if (ary[i] >= pivot)
			{
				break;
			}
		}

		for (; j >= 0; j--)
		{
			if (ary[j] < pivot)
			{
				break;
			}
		}

		if (i < j)
		{
			temp = ary[i];
			ary[i] = ary[j];
			ary[j] = temp;
		}
		else
		{
			temp = ary[size - 1];
			ary[size - 1] = ary[i];
			ary[i] = temp;
			break;
		}
	}
	quickSort(ary, i);
	quickSort(ary + i + 1, size - i - 1);
	
}
/*------------------------------------------------------------------------
�Լ��� �� ��� : output() - �迭�� ��� ���� ����ϱ�
��������: ary - ������ ������ �迭�� �����ּ� / size - �������� ����
���ϰ�: ����
------------------------------------------------------------------------*/
void output(int *ary, int size)
{
	for (int i = 0; i<size; i++)
	{
		printf(" %d ", ary[i]);
	}
	printf("\n");
}
/*------------------------------------------------------------------------
�Լ��� �� ��� : initArray() - �迭�� ���Ҹ� �������� ��Ʈ�� ���·� �ʱ�ȭ
��������: ary - �ʱ�ȭ�� ������ �迭�� �����ּ� / size - �������� ����
���ϰ�: ����
------------------------------------------------------------------------*/
void initArray(int *ary, int n)
{
	int i;
	for (i = 0; i<n; ++i)
		ary[i] = i;
}
/*------------------------------------------------------------------------
�Լ��� �� ��� : initArray() - �迭�� ���Ҹ� ������ �ʱ�ȭ
��������: ary - �ʱ�ȭ�� ������ �迭�� �����ּ� / size - �������� ����
���ϰ�: ����
------------------------------------------------------------------------*/
void initArrayRandom(int *ary, int n)
{
	int i;
	for (i = 0; i<n; ++i)
		ary[i] = rand() % 1000 + 1;
}
