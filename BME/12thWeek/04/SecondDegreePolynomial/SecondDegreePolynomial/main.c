#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h> // to be able to utilize sqrt function

int main(int argc, char* argv[])
{
	printf("This program obtains the roots of equation:\n");
	printf("a.x^2 + b.x + c = 0.\n");


	// Reading the polynomial coefficients from user
	printf("a = ");
	double a = 0.0;
	scanf("%lf", &a);

	printf("b = ");
	double b = 0.0;
	scanf("%lf", &b);

	printf("c = ");
	double c = 0.0;
	scanf("%lf", &c);

	printf("Your polynomial is: %gx^2 + %gx + %g.\n", a, b, c);

	// Solve the equation

	if (a == 0) // The equation is not second degree
	{
		if (b == 0) // This function is a constant
		{
			if (c == 0)
			{
				printf("The function equals to zero over the entire interpretaion interval: 0 = 0.\n");
			}
			else
			{
				printf("There is no solution! %g != 0\n", c);
			}
		}
		else // This is a linear equation
		{
			printf("The solution of the linear equation is: x = %g.\n", -c / b);
		}
	}
	else // This is actually a second degree polynomial equation
	{
		double discriminant = b * b - 4 * a * c;
		if(discriminant == 0)
		{
			printf("The polynomial has a twice multiplicity solution: x = %g.\n", -b / (2 * a));
		}
		else if (discriminant > 0)
		{
			printf("The polynomial has two different real roots:\n");
			double x1 = (-b + sqrt(discriminant)) / (2 * a);
			double x2 = (-b - sqrt(discriminant)) / (2 * a);
			printf("x1 = %g, x2 = %g.\n", x1, x2);
		}
		else
		{
			double realPart = -b / (2 * a);
			double imaginaryPart = sqrt(-discriminant) / (2 * a);
			printf("The complex conjugate solutions of the equation:\n");
			printf("x1 = %g + %gi, x2 = %g - %gi.\n", realPart, imaginaryPart, realPart, imaginaryPart);
		}
	}

	return 0;
}