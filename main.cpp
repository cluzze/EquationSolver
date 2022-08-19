#include <stdio.h>

#include "equation.h"

int main(int argc, char *argv[])
{
	Roots roots = solve_equation(argc, argv);
	switch (roots.n)
	{
		case 0:
			printf("No roots\n");
			break;
		case 1:
			printf("One root: %f\n", roots.x);
			break;
		case 2:
			printf("Two roots: %f, %f\n", roots.x, roots.y);
			break;
		case 3:
			printf("Infinite number of roots\n");
			break;
		default:
			break;
	}
	return 0;
}