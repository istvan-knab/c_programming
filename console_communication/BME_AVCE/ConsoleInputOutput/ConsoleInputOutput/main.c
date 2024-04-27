// # define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>

// This program is intended to demonstrate how one can print and read strings and different variables from 
// and to the console output.

int main(int argc, char* argv[])
{

	// Checking the size of the default variable types
	printf("The size of char, int and double types are: %d, %d, %d\n", sizeof(char), sizeof(int), sizeof(double));
	
	// Declaration of variables (we have to tell the compiler what kind of variables do we create)
	char textVar[100]; // character array (string)
	int integerVar = 0; // integer number
	double floatingVar = 0.0; // floating point number with double precision (64 bit)

	printf("Please, type some text here!\n"); // Print a simple string to the console output
	// To use the simple scanf function in Visual Studio put the preprocessor definition: # define _CRT_SECURE_NO_WARNINGS
	// at the beginning of your code or add it to the project properties (right click on project) under C/C++ --> Preprocessor --> Preprossor definitions
	scanf("%[^\n]s", textVar); // Scan some text (string ~ character array) given by the user to the console, including white spaces until the '\n' new line character (enter)
	scanf_s("%[^\n]s", textVar, 100); // Same scan with Microsoft's implementation (no need for _CRT_SECURE_NO_WARNINGS preprocessor definition)
	printf("The read text is: %s\n", textVar); // Print out the result of scanf

	printf("Please, enter an integer number!\n");
	// When a number is scanned instead of character array, 
	// the memory adress of the variable in what one wants to store the scanned number should be passed to scanf function.
	// This can be performed by the & sign.
	scanf("%d", &integerVar);  
	printf("The read number is: %d\n", integerVar);

	printf("Please, enter an floating point number!\n");
	scanf("%lf", &floatingVar);
	// Printing out a floating point number with different formats:
	// - simple long float format
	// - with 5 characters and 2 decimal fraction characters (2 integer . 2 decimal fraction)
	// - %g determines whether the floating point variable has an integer value or a decimal fraction
	printf("The read decimal floating point number is: %lf\n", floatingVar);
	printf("The read decimal floating point number is: %5.2f\n", floatingVar);
	printf("The read decimal floating point number is: %g\n", floatingVar);
}