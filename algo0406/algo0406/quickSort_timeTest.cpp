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
	quickSort(dataList, size); 	/* 퀵 정렬 함수 호출 */
	endTime = clock();
	printf("\n\n[ 오름차순으로 소트된 데이터 퀵 정렬  후 출력 ]\n");
	//output(dataList, size);
	printf("오름차순으로 소트된 데이터 퀵소트 알고리즘 실행 소요시간 : %d(millisecond)\n", (endTime - startTime));

	initArrayRandom(dataList, size);
	startTime = clock();
	quickSort(dataList, size); 	/* 퀵 정렬 함수 호출 */
	endTime = clock();
	printf("\n\n[ 난순 저장 데이터 퀵 정렬  후 출력 ]\n");
	//output(dataList, size);
	printf("난순 저장 데이터 퀵소트 알고리즘 실행 소요시간 : %d(millisecond)\n", (endTime - startTime));

	getchar();
	return 0;
}
/*----------------------------------------------------------------------
함수명 및 기능 : quickSort() - 퀵 정렬 함수
전달인자: ary - 정렬할 데이터 배열의 시작주소 / size - 소트할 데이터의 개수
리턴값: 없음
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
함수명 및 기능 : output() - 배열의 모든 원소 출력하기
전달인자: ary - 정렬할 데이터 배열의 시작주소 / size - 데이터의 개수
리턴값: 없음
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
함수명 및 기능 : initArray() - 배열의 원소를 오름차순 소트된 상태로 초기화
전달인자: ary - 초기화할 데이터 배열의 시작주소 / size - 데이터의 개수
리턴값: 없음
------------------------------------------------------------------------*/
void initArray(int *ary, int n)
{
	int i;
	for (i = 0; i<n; ++i)
		ary[i] = i;
}
/*------------------------------------------------------------------------
함수명 및 기능 : initArray() - 배열의 원소를 난수로 초기화
전달인자: ary - 초기화할 데이터 배열의 시작주소 / size - 데이터의 개수
리턴값: 없음
------------------------------------------------------------------------*/
void initArrayRandom(int *ary, int n)
{
	int i;
	for (i = 0; i<n; ++i)
		ary[i] = rand() % 1000 + 1;
}
