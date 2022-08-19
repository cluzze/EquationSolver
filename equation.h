#ifndef _QUADRATIC_EQUATION_SOLVER_
#define _QUADRATIC_EQUATION_SOLVER_

typedef struct
{
	int n;
	double x;
	double y;
} Roots;

Roots solve_equation(int argc, char* argv[]);

#endif