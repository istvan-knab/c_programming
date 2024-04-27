# define _CRT_SECURE_NO_WARNINGS
# include <stdio.h> // for using printf and scanf
# include <ctype.h> // to be able to use toupper function

int main(int argc, char* argv[])
{
	printf("This program computes the resultant resistance.\n");
	printf("-----------------------------------------------\n");
	printf("Which resistance layout would you like to apply?\nSeries [S] or parallel [P]?\n");
	printf("........\n");
	char layoutType = 0;
	// We read the layout type as a character (S or P) corresponding to the series and parallel layouts. 
	scanf("%c", &layoutType);

	// Considering that the user can give small 's' or 'p' characters:
	layoutType = toupper(layoutType); // convert the read character to capital letter 

	if ((layoutType == 'S') || (layoutType == 'P')) // The computation starts if the layout type is correct (S or P)
	{
		double currentResistance = 0.0;
		double resultantResistance = 0.0;
		double reciprocalResultantResistance = 0.0;

		while (1) // infinite loop: we read the next resistance value until it is zero or negative
		{
			printf("R = ");
			scanf("%lf", &currentResistance);
			if (currentResistance <= 0)
			{
				break; // the infinite loop (while (1)) is broken if the given resistance value is zero or negative
			}
			switch (layoutType)
			{
				case 'S':
				{
					resultantResistance += currentResistance;
					break;
				}
				case 'P':
				{
					reciprocalResultantResistance += 1.0 / currentResistance;
					break;
				}
			}
		}
		if ((layoutType == 'P') && (resultantResistance > 0))
		{
			resultantResistance = 1.0 / reciprocalResultantResistance;
		}
		printf("The resultant resistance value: Rr = %g. \n", resultantResistance);
	}
	else
	{
		printf("The given %c layout type is not interpreted\n", layoutType);
	}


	return 0;
}