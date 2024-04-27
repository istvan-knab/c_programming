// #define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <ctype.h>


// the constants between the user can think on a number given by macros
#define MIN 1
#define MAX 100

int main(int argc, char* argv[])
{
	// This program guesses the number on what the user thought based on interval halving method.
	// The user thinks on a number and the computer makes a guess in every iteration and waits for the answer by the user
	// whether its guess is lower (L), greater (G) than the thought number or the guess is correct (E).
	printf("This program is a number guesser robot.\n");
	printf("Please, think on a number between %d and %d!\n", MIN, MAX);
	printf("Press any button to start!\n");
	printf("-------------------------------------------------------\n");

	_getch(); // Does not wait for enter. The program immediately continues after a key is pressed.

	int lowerLimit = MIN;
	int upperLimit = MAX + 1; // consdering rounding unless the robot can never find out MAX
	int guess = 0;
	int guessCount = 0;
	char answer = '\0'; // L - Lower than my number, G - Greater than my number, E - Equals
	int isAnswerOk = 1; // Indicator for checking whether the user input is OK (L, G or E)
	char characterVariable;

	while (answer != 'E')
	{
		guessCount++; // increment the guess count
		guess = (lowerLimit + upperLimit) / 2; // obtain the new guess based on bisection method

		printf("My guess is: %d.\n", guess);
		printf("Is your number greater (G) or lower (L) than my guess? Or does it equal (E) your number?\n");

		isAnswerOk = 0; // initializing with zero to grant at least one loop in the following while
		while (!isAnswerOk) // Trying to get an answer until it is a 'G', 'L' or 'E'
		{
			answer = _getch();
			answer = toupper(answer); // Creates capital letter from normal one

			switch (answer)
			{
			case 'G':
			{
				lowerLimit = guess;
				isAnswerOk = 1;
				break;
			}
			case 'L':
			{
				upperLimit = guess;
				isAnswerOk = 1;
				break;
			}
			case 'E':
			{
				printf("Your number was %d, wasn't it?\n", guess);
				printf("I needed %d guesses to find it out.\n", guessCount);
				isAnswerOk = 1;
				break;
			}
			default:
			{
				printf("This answer is not interpreted. Please, try it again!\n");
				isAnswerOk = 0;
				break;
			}
			}
		}
	}
	return 0;
}