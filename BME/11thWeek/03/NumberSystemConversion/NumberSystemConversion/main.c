#include <stdio.h>

int main(int argc, char* argv[])
{
	printf("This program converts a decimal integer into an arbitrary number system.\n");

	// Scannning the user inputs (the number and the target number system)
	printf("Please enter the decimal number that you would like to convert!\n");
	printf("number = ");
	int number = 0;
	scanf("%d", &number);

	printf("Please enter the number system into what you like to convert the previous number!\n");
	printf("base of number system = ");
	int base = 0;
	scanf("%d", &base);

	printf("-------------------------------------------------------------------------------\n");

	// Conversion
	int currentDigit = 0;
	printf("%d (10) = (%d) ", number, base);
	while (number > 0)
	{
		int currentDigit = number % base; // The digit of the current place value equals the remainder
		number /= base;

		printf("%d ", currentDigit);
	}
	printf("\n");
	printf("-------------------------------------------------------------------------------\n");
	// The printing flips the correct order of the digits but now we neglect this problem.
	return 0;
}