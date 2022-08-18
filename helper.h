#ifndef _QUADRATIC_EQUATION_SOLVER_HELPER_
#define _QUADRATIC_EQUATION_SOLVER_HELPER_

#include "equation.h"

#define EPS 0.001
/*solve equation like a linear one*/
Roots linear_solve(const Scalars scalars);

/*solve equation like a quadratic one*/
Roots quadratic_solve(const Scalars scalars);

/*atof which handles ','*/
float almost_my_atof(const char s[]);

/*solve equation like a linear one*/
Scalars parse_arguments(int argc, char *argv[]);

/*solve equation like a linear one*/
int is_argument_valid(const char* const arg);

/*compares two float with EPS precision*/
int float_equals(const float a, const float b, const float eps);

/*prints "documentaion"*/
void print_doc();

#endif