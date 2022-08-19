#include <assert.h>
#include <stdio.h>

#include "equation.h"
#include "helper.h"

int main()
{
	/*is_argument_valid tests*/
	{ 
		assert(is_argument_valid("1.23") && "invalid argument");
		assert(is_argument_valid("1,23") && "invalid argument");
		assert(is_argument_valid("1") && "invalid argument");
		assert(is_argument_valid("-1") && "invalid argument");
		assert(!is_argument_valid(".23") && "invalid argument");
		assert(!is_argument_valid("1.") && "invalid argument");
		assert(!is_argument_valid("1,3,4") && "invalid argument");
		assert(!is_argument_valid("1.2.4") && "invalid argument");
	}
	/*almost_my_atof tests*/
	{
		assert(float_equals(almost_my_atof("1,23"), 1.23, EPS) && "atof fail");
		assert(float_equals(almost_my_atof("1.23"), 1.23, EPS) && "atof fail");
	}
	/*linear_solve tests*/
	{
		Scalars scalars[] = {{0, 1, 1},
							 {0, 1, 5},
							 {0, 2.5, 5}};
		Roots roots[3];
		linear_solve(scalars[0], &roots[0]);
		linear_solve(scalars[1], &roots[1]);
		linear_solve(scalars[2], &roots[2]);
		assert(roots[0].n == 1 && float_equals(roots[0].x, -1, EPS));
		assert(roots[1].n == 1 && float_equals(roots[1].x, -5, EPS));
		assert(roots[2].n == 1 && float_equals(roots[2].x, -2, EPS));
	}

	/*linear_solve tests*/
	{
		Scalars scalars[] = {{1, 1, -1},
							 {10, 5, -3},
							 {1, -2, 1},
							 {1, 0, 1},
							 {1, 1, 0}};
		Roots roots[4];
	 	quadratic_solve(scalars[0], &roots[0]);
		quadratic_solve(scalars[1], &roots[1]);
		quadratic_solve(scalars[2], &roots[2]);
		quadratic_solve(scalars[3], &roots[3]);
		quadratic_solve(scalars[4], &roots[4]);
		assert(roots[0].n == 2 && float_equals(roots[0].x, 0.61803, EPS) && float_equals(roots[0].y, -1.6180, EPS));
		assert(roots[1].n == 2 && float_equals(roots[1].x, 0.35208, EPS) && float_equals(roots[1].y, -0.85208, EPS));
		assert(roots[2].n == 1 && float_equals(roots[2].x, 1, EPS));
		assert(roots[3].n == 0);
		assert(roots[4].n == 2 && float_equals(roots[4].x, 0, EPS) && float_equals(roots[4].y, -1, EPS));
	}

	printf("All tests passed!\n");
}