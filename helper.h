#ifndef _QUADRATIC_EQUATION_SOLVER_HELPER_
#define _QUADRATIC_EQUATION_SOLVER_HELPER_

#include "equation.h"

/*atof which handles ','*/
double almost_my_atof(const char s[]);

/*checks if argument is a valid number*/
int is_argument_valid(const char* const arg);

/*function to fix -0.000000*/
double round_to_zero(const double a);

/*prints "documentaion"*/
void print_doc();

#endif