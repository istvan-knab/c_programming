#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(int argc, char* argv[])
{
	printf("This program computes the n! factorial of a given number.\n");

	printf("Please, enter the number! n = ");
	int number = 0;
	scanf("%d", &number);

	// With wile iterator
	int iterationVar = 2;
	int factorialWhile = 1;
	while (iterationVar <= number)
	{	
		factorialWhile *= iterationVar; // compact format of: factorialWhile = factorialWhile * iterationVar
		iterationVar++; // compact format of: iterationVar = iterationVar + 1
	}
	printf("The factorial with while iteration: %d! = %d\n", number, factorialWhile);

	// With for iterator
	int factorialFor = 1;
	for (int i = 2; i <= number; i++)
	{
		factorialFor *= i; // compact format of: factorialFor = factorialFor * i
	}
	printf("The factorial with for iteration: %d! = %d\n", number, factorialFor);
}