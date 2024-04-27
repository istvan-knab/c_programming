#include <stdio.h>

// This program is intended to demonstrate how the command line arguments can be parsed in C.
// If your program is not designed to run from command window (e.g., PowerShell or cmd.exe) with different input arguments
// the main function does not have to have input arguments: int main() or int main(void).
// If one wants to run the built program from command window with command line inputs the main function should include 
// these arguments as: int main(int argc, char* argv[]). The argc stands for the argument counter and it determines the number of
// input arguments (as nargin in Matlab). The argv contains the input arguments in array.
int main(int argc, char* argv[])
{
	if (argc > 1) // The first command line argument is always the program name with path, so argc cannot be less than 1
	{
		printf("The program is called with extra command line arguments.\n");
		printf("The number of command line arguments: %d\n", argc - 1);
	}
	else
	{
		printf("The program is called without extra command line arguments.\n");
	}

	for (int i = 1; i < argc; i++)
	{
		printf("The %d. command line argument: %s\n", i, argv[i]);
	}

	return 0;
}