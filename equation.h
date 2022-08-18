#ifndef _QUADRATIC_EQUATION_SOLVER_
#define _QUADRATIC_EQUATION_SOLVER_

typedef struct
{
	float a;
	float b;
	float c;
} Scalars;

typedef struct
{
	int n;
	float x;
	float y;
} Roots;

Roots solve_equation(int argc, char* argv[]);

#endif