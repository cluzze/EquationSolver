#ifndef _QUADRATIC_EQUATION_SOLVER_HELPER_
#define _QUADRATIC_EQUATION_SOLVER_HELPER_

#include "equation.h"

/*!
transforms char* to double
\param[in] s char* to be converted
*/
double almost_my_atof(const char s[]);

/*!
Checks if argument is a valid number
\param[in] arg to be checked
*/
int is_argument_valid(const char* const arg);

/*!
Function to fix -0.000000
\param a if a is almost zero it will be round to zero
*/
double round_to_zero(const double a);

/*!
Prints helpful info
*/
void print_doc();

#endif