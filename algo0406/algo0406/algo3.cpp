#include <stdio.h>
int c;
void f(int n);
int main(void)
{
	int num = 10;
	f(num);
	printf("%d\n", c);
	return 0;
}
void f(int n)
{
	if (n <= 1) c++;
	else
	{
		f(n / 2);
		f(n / 2);
		f(n / 2);
	}
	return;
}