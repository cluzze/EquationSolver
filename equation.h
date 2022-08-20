/*!
Module to solve quadratic equations
*/

#ifndef _QUADRATIC_EQUATION_SOLVER_
#define _QUADRATIC_EQUATION_SOLVER_

#include <stdio.h>

#define EPS 0.001


/*!
Struct to hold 3 parameters of the equation
*/
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

/*!
Splits the line by " \n\t" delimeters into array of char*
\param[in] line line which will be splited
\param[out] tokens_len number of tokens line was splited to
\return allocated array of tokens 
*/
char** parse_line(char* line, int* tokens_len);

/*!
Fills up Scalars structer with 3 floating point numbers if tokens were valid numbers
or it will prints some helpful information or exit with error code
\param[in] tokens array of char* which are supposed to be numbers
\param[in] size of this array
\param[out] scalars struct consisting of 3 doubles to which array was converted
*/
void get_scalars(char** tokens, int tokens_len, Scalars* scalars);

/*!
Solves equation like a linear one
\param[in] scalars paramaters of equation
\param[out] calculated roots of equation
*/
void linear_solve(const Scalars scalars, Roots* roots);

/*!
Solves equation like a quadratic one
\param[in] scalars paramaters of equation
\param[out] calculated roots of equation
*/
void quadratic_solve(const Scalars scalars, Roots* roots);

/*!
Compares two double with EPS precision
\param a,b compared numbers
\param eps precision with which numbers are compared
*/
int float_equals(const double a, const double b, const double eps);

/*!
Checks if data in first file is the same as in the second one
\param[in] fd1, fd2 two files 
*/
void compare_two_files(FILE* fd1, FILE* fd2);

#endif