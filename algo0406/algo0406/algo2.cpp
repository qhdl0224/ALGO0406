#include <stdio.h>
int fact(int);

int main(void)
{
	int num = 1;
	printf("%d! = %d \n",num ,fact(num));
	return 0;
}
int fact(int x)
{
	printf("x = %2d\n", x);
	if (x == 1) return 1;
	else return x * fact(x - 1);
}