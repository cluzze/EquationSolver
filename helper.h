#ifndef _QUADRATIC_EQUATION_SOLVER_HELPER_
#define _QUADRATIC_EQUATION_SOLVER_HELPER_

#include "equation.h"

#define EPS 0.001
/*solves equation like a linear one*/
Roots linear_solve(const Scalars scalars);

/*solves equation like a quadratic one*/
Roots quadratic_solve(const Scalars scalars);

/*atof which handles ','*/
float almost_my_atof(const char s[]);

/*checks if program is run with correct arguments*/
Scalars parse_arguments(int argc, char *argv[]);

/*checks if argument is a valid number*/
int is_argument_valid(const char* const arg);

/*compares two float with EPS precision*/
int float_equals(const float a, const float b, const float eps);

/*prints "documentaion"*/
void print_doc();

#endif