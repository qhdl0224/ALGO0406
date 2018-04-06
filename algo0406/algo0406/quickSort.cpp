#include <stdio.h>
void quickSort(int *ary, int size);
void output(int *ary, int size);
int main()
{
	int dataList[] = { 76,12,29,3,15,6,34,29,25 };
	int size = sizeof(dataList) / sizeof(dataList[0]);
	quickSort(dataList, size);
	printf("[ 퀵 정렬 후 출력 ]\n");
	output(dataList, size);
	return 0;
}
void quickSort(int *ary, int size)
{
	int pivot, temp;
	int i, j;

	if (size <= 1) return;
	pivot = ary[size - 1];
	
	i = 0;
	j = size - 2;
	while (1)
	{
		for (; i < size; i++)
		{
			if (ary[i] > pivot)
			{
				break;
			}
		}

		for (; j >= 0; j--)
		{
			if (ary[j] <= pivot)
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
			temp = ary[size-1];
			ary[size-1] = ary[i];
			ary[i] = temp;
			break;
		}
	}
	quickSort(ary, i);
	quickSort(ary+i+1, size-i-1);
}
void output(int *ary, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", ary[i]);
	}
	printf("\n");
}