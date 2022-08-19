#ifndef _QUADRATIC_EQUATION_SOLVER_HELPER_
#define _QUADRATIC_EQUATION_SOLVER_HELPER_

#include "equation.h"

typedef struct
{
	double a;
	double b;
	double c;
} Scalars;

#define EPS 0.001
/*solves equation like a linear one*/
void linear_solve(const Scalars scalars, Roots* roots);

/*solves equation like a quadratic one*/
void quadratic_solve(const Scalars scalars, Roots* roots);

/*atof which handles ','*/
double almost_my_atof(const char s[]);

/*checks if program is run with correct arguments*/
void parse_arguments(int argc, char *argv[], Scalars* scalars);

/*checks if argument is a valid number*/
int is_argument_valid(const char* const arg);

/*compares two double with EPS precision*/
int float_equals(const double a, const double b, const double eps);

/*function to fix -0.000000*/
double round_to_zero(const double a);

/*prints "documentaion"*/
void print_doc();

#endif