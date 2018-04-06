#include <stdio.h>
double iteratorPowerOf2(int power);
double recursivePowerOf2(int power);

int main()
{
	int power = 1001;
	printf("2ÀÇ %d½Â °ª = %lf\n", power, iteratorPowerOf2(power));
	printf("2ÀÇ %d½Â °ª = %lf\n", power, recursivePowerOf2(power));
	return 0;
}

double iteratorPowerOf2(int power)
{
	double result = 1;
	for (int i = 1; i <= power; i++)
	{
		result *= 2;
	}
	return result;
}
double recursivePowerOf2(int power)
{
	if (power == 0)
	{
		return 1;
	}
	else
	{
		return 2 * recursivePowerOf2(power - 1);
	}
}
