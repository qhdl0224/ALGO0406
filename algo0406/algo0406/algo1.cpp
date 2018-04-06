#include <stdio.h>
int a = 0;
void sub()
{
	printf("a=%d\n", a++);
	sub();

	return;
}
int main()
{
	sub();
	return 0;

}