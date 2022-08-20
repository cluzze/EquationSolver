#ifndef _QUADRATIC_EQUATION_SOLVER_
#define _QUADRATIC_EQUATION_SOLVER_

#include <stdio.h>

#define EPS 0.001

typedef struct
{
	double a;
	double b;
	double c;
} Scalars;

typedef struct
{
	int n;
	double x;
	double y;
} Roots;

char** parse_line(char* line, int* tokens_len);

void get_scalars(char** tokens, int tokens_len, Scalars* scalars);

/*solves equation like a linear one*/
void linear_solve(const Scalars scalars, Roots* roots);

/*solves equation like a quadratic one*/
void quadratic_solve(const Scalars scalars, Roots* roots);

/*compares two double with EPS precision*/
int float_equals(const double a, const double b, const double eps);

void compare_two_files(FILE* fd1, FILE* fd2);

#endif