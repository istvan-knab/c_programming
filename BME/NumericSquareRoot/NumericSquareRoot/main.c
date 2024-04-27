#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#define RELATIVE_TOLERANCE 1e-9
// #define ABS(x) (((x) > 0) ? (x) : (-(x)))
int main(int argc, char* argv[])
{
	printf("This program computes numerically the square root of a given number.\n");
	
	printf("Please, enter the number! x = ");
	double number = 0.0;
	scanf("%lf", &number);

	if (number < 0)
	{
		printf("The given number is negative. Exit...");
		return 1;
	}

	double lowerLimit = 0.0;
	double upperLimit = 0.0;
	double numericSqrt = 0.0;
	double numericSquare = 0.0;

	if (number > 1)
	{
		lowerLimit = 1;
		upperLimit = number;
	}
	else
	{
		lowerLimit = number;
		upperLimit = 1;
	}

	double tolerance = RELATIVE_TOLERANCE * fabs(number);
	while (fabs(numericSquare - number) > tolerance)
	{
		numericSqrt = (lowerLimit + upperLimit) / 2;
		numericSquare = numericSqrt * numericSqrt;
		if (numericSquare < number)
		{
			lowerLimit = numericSqrt;
		}
		else
		{
			upperLimit = numericSqrt;
		}
	}

	printf("The numeric solution of sqrt(x) = %g", numericSqrt);

	return 0;
}