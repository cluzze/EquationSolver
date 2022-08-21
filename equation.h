//!@mainpage
//!Hi thanks for trying out my quadratic equation solver
//!run this program with coefficients of the equation as arguments
//!you can use floating point numbers with dot or comma
//!\"equation.h\" header provides you with solve_equation() function, which will return Roots struct
//!Roots.n is the number of roots, Roots.x and Roots.y are roots value, Roots.x > Roots.y
//!If equation has only one root, it will be stored in Roots.x

#ifndef _QUADRATIC_EQUATION_SOLVER_
#define _QUADRATIC_EQUATION_SOLVER_
#include <math.h>
#include <stdio.h>

const double EPS = 0.001;

enum ERRORS
{
    ALL_GOOD = 0,
    ALL_BAD = 1
};

//! number of roots
enum NROOTS
{
	NO_ROOTS = 0,
	ONE_ROOT = 1,
	TWO_ROOTS = 2,
	INFINITE = 3
};

//! three parameters of equation
typedef struct
{
	double a = NAN;
	double b = NAN;
	double c = NAN;
} Scalars;

//! info about equation's roots
typedef struct
{
	int n = 0;
	double x = NAN;
	double y = NAN;
} Roots;


/*!
 *	\brief parses input line into words
 *	\param[in] line - input line
 *	\param[out] tokens_len - number of words
 */
char** parse_line(char* line, int* tokens_len);

/*!
 *	\brief gets parameters of equation from words if its possible
 *	\param[in] tokens - array of words
 *	\param[in] tokens_len - size of the array
 *	\param[out] scalars - received parameters
 */
void get_scalars(char** tokens, int tokens_len, Scalars* scalars);

/*!
 *	\brief solves equation like a linear one
 *	\param[in] scalars - parameters
 *	\param[out] roots - roots of equation
 */
void linear_solve(const Scalars scalars, Roots* roots);

/*!
 *	\brief solves equation like a linear one
 *	\param[in] scalars - parameters
 *	\param[out] roots - roots of equation
 */
void quadratic_solve(const Scalars scalars, Roots* roots);

/*!
 *	\brief check if two foating point numbers are equal with EPF precision
 *	\param[in] a, b - numbers to compare
 *	\param[ine] eps - precision
 */
int float_equals(const double a, const double b, const double eps);

/*!
 *	\brief solves equation
 *	\param[in] scalars - parameters
 *	\param[out] roots - roots of equation
 */
void solve(const Scalars scalars, Roots* roots);

/*!
 *	\brief checks if first file is the same as the seecond one
 *	\param[in] fd1, fd2 - files
 */
void compare_two_files(FILE* fd1, FILE* fd2);

#endif