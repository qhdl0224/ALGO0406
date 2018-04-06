#pragma warning(disable : 4996)
#include <stdio.h>
#include <string>
//void swap(char arr[],int size);
void swap(char arr[]);
int main()
{
	int length;
	char arr[100];
	printf("입력하세요 : ");
	scanf("%s", arr);
	length = strlen(arr);
//	swap(arr, length-1);
	swap(arr);
//	printf("\n%s", arr);
	return 0;
}
/*
void swap(char arr[],int size)
{
	printf("%c", arr[size]);
	if (size == 0)
	{
		return;
	}
	else
	{
		swap(arr, size - 1);
	}
}*/
void swap(char arr[])
{
	if (*arr == '\0')
	{
		return;
	}
	else
	{
		swap(arr+1);
		printf("%c", *arr);

	}
	
}