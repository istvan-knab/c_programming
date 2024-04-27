# define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>

// This program is intended to demonstrate how scanf works on the buffer. The buffered behavior can cause unintended output,
// so this example shows how one can avoid this problem.
// Actually the scanf does not read the user input from the console. The user inputs are loaded into a buffer and the scanf reads
// the content of this buffer. If the buffer is empty the, the scanf waits until the user gives some input into the buffer. 
// However, if the buffer is not empty, the scanf does not wait for the user but it tries to read and parse the current buffer content.
int main(int argc, char* argv[])
{
	int integerNum = 0;
	double floatingNum;
	char characterVariable = 0;
	int numOfReadVariables = 0;
	int numOfBufferedChars = 0;

	printf("Please, enter an integer number!\n");
	// If the user gives a string instead of an integer (bad user), the given string will be put in the buffer.
	// But the scanf cannot parse the string as a decimal integer (%d), so it wont be read from th buffer and the
	// string remains in the buffer. Therefore, the next scanf wont waint for the user input but it will try again
	// to read the content of the non-empty buffer. 
	// Don't forget that a developer hardly can prepare for the user creativity: https://www.youtube.com/watch?v=981Pl9-pCLQ

	while ((numOfReadVariables == 0) || (numOfBufferedChars > 0)) // The program asks the user to give an integer number until the input can not be parsed.
	{
		numOfReadVariables = scanf("%d", &integerNum);

		// The buffer content is deleted again by the getchar() function that reads the buffer content until EOF (end of file) or 
		// the '\n' new line feed character
		numOfBufferedChars = 0;
		while (((characterVariable = getchar()) != EOF) && (characterVariable != '\n'))
		{
			printf("The character read from the buffer: %c\n", characterVariable);
			numOfBufferedChars++;
		}

		// The input is wrong if scanf could not read anything (e.g., the input is a string) or the input was partially read and something
		// remained in the buffer (e.g., the input is a floating-point number --> integer part is read, fraction remains in the buffer)

		if ((numOfReadVariables == 0) || (numOfBufferedChars > 0))
		{
			printf("Your input was not successfully read.\nMaybe it is not an integer.\nPlease, give an integer number!\n");
		}
		
	}
	
	printf("The scanned number is: %d\n", integerNum);

	// Since the buffer is deleted after reading the decimal integer number, the scanf will request for a new user input (floating point number) even if 
	// the previous input was a floating-point number instead of decimal integer.
	printf("Please, enter an floating point number!\n");

	// The same process for floating point number:
	numOfReadVariables = 0;
	numOfBufferedChars = 0;
	while ((numOfReadVariables == 0) || (numOfBufferedChars > 0)) // The program asks the user to give an integer number until the input can not be parsed.
	{
		numOfReadVariables = scanf("%lf", &floatingNum);

		// The buffer content is deleted again by the getchar() function that reads the buffer content until EOF (end of file) or 
		// the '\n' new line feed character
		numOfBufferedChars = 0;
		while (((characterVariable = getchar()) != EOF) && (characterVariable != '\n'))
		{
			printf("The character read from the buffer: %c\n", characterVariable);
			numOfBufferedChars++;
		}

		// The input is wrong if scanf could not read anything (e.g., the input is a string) or the input was partially read and something
		// remained in the buffer

		if ((numOfReadVariables == 0) || (numOfBufferedChars > 0))
		{
			printf("Your input was not successfully read.\nMaybe it is not a floating point number.\nPlease, give a floating point number!\n");
		}

	}
	printf("The scanned number is: %g\n", floatingNum);

	return 0;
}