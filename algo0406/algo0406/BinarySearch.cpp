#pragma warning(disable : 4996)
#include <stdio.h>
void myBubbleSort(int ary[],int size);
void output(int *ary, int size);
int binarySearch(int *ary, int leftIndex, int rightIndex, int key);
int rbinarySearch(int *ary, int leftIndex, int rightIndex, int key);
int main(void)
{
	int ary[11] = { 1,11,3,25,7,19,10,13,35,8,19 };
	int size;
	int key;
	int index;
	int res;
	size = sizeof(ary) / sizeof(ary[0]);
	myBubbleSort(ary, size);
	output(ary, size);

	while (1)
	{
		printf("검색할 숫자 입력(문자입력 시 종료) : ");
		res = scanf("%d", &key);
		if (res != 1) { break; }
		if ((index = rbinarySearch(ary, 0, size - 1, key)) != -1)
		{
			printf("%d는 %d번방 데이터입니다.\n", key, index);
		}
		else
		{
			printf("%d는 존재하지 않습니다.\n", key);
		}
	}
	return 0;
}
void myBubbleSort(int ary[],int size)
{
	int tmp;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (ary[j] > ary[j + 1])
			{
				tmp = ary[j];
				ary[j] = ary[j + 1];
				ary[j + 1] = tmp;
			}
		}
	}
}
int binarySearch(int *ary, int leftIndex, int rightIndex, int key)
{
	
	
	while (rightIndex - leftIndex>=0)
	{
		int mid = (rightIndex + leftIndex) / 2;
		if (ary[mid] == key)
		{
			return mid;
		}
		else if (key > ary[mid])
		{
			leftIndex = mid+1;
		}
		else
		{
			rightIndex = mid-1;
		}
	}
	return -1;
}
int rbinarySearch(int *ary, int leftIndex, int rightIndex, int key)
{
	if (rightIndex - leftIndex >= 0)
	{
		int mid = (rightIndex + leftIndex) / 2;
		if (ary[mid] == key)
		{
			return mid;
		}
		else if (key > ary[mid])
		{
			return rbinarySearch(ary, mid+1, rightIndex, key);
		}
		else
		{
			return rbinarySearch(ary, leftIndex, mid-1, key);
		}
	}
	else
	{
		return -1;
	}
}
void output(int *ary, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", ary[i]);
	}
	printf("\n");
}