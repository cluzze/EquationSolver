#ifndef _QUADRATIC_EQUATION_SOLVER_HELPER_
#define _QUADRATIC_EQUATION_SOLVER_HELPER_

#include "equation.h"

/*!
 *	\brief atof which also hadles ','
 *	\param[in] s - string to be converted to number
 */
double almost_my_atof(const char s[]);

/*!
 *	\brief checks if line is a vild number
 *	\param[in] arg - line to be checked
 */
int is_argument_valid(const char* const arg);

/*!
 *	\brief if a number is close to zero, like -0.0000 it will be rounded
 *	\param[in] a - number to be rounded
 */
double round_to_zero(const double a);

/*!
 *	\brief prints some helpful info
 */
void print_doc();

#endif