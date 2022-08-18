#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "helper.h"
#include "equation.h"

//**********************************DEFINITIONS**********************************

Scalars parse_arguments(int argc, char *argv[])
{
	Scalars scalars = {0, 0, 0};
	switch(argc)
	{
		case 2:
			if (strcmp(argv[1], "help") == 0)
			{
				print_doc();
				exit(EXIT_FAILURE);
			}
			break;
		case 4:													//calling with 3 scalars of equation
			if (is_argument_valid(argv[1]) 
				&& is_argument_valid(argv[2])
				&& is_argument_valid(argv[3]))
			{
				scalars.a = almost_my_atof(argv[1]);
				scalars.b = almost_my_atof(argv[2]);
				scalars.c = almost_my_atof(argv[3]);
			}
			else
			{
				printf("Incorrect arguments, try running with \"help\" option\n");
				exit(EXIT_FAILURE);
			}
			break;
		default:												//calling with something else
			printf("Incorrect arguments, try running with \"help\" option\n");
			exit(EXIT_FAILURE);
	}
	return scalars;
}

Roots solve_equation(int argc, char* argv[])					//main function
{
	Scalars scalars = {0, 0, 0};
	Roots roots = {0, 0, 0};
	scalars = parse_arguments(argc, argv);
	if (float_equals(scalars.a, 0, EPS))
	{
		if (float_equals(scalars.b, 0, EPS))
		{
			return roots;
		}
		else
		{
			return linear_solve(scalars);
		}
	}
	return quadratic_solve(scalars);
}

Roots linear_solve(const Scalars scalars)
{
	Roots roots = {0, 0, 0};
	if (!float_equals(scalars.c, 0, EPS))
	{
		roots.n = 1;
		roots.x = (-scalars.c) / (scalars.b);
	}
	return roots;
}

Roots quadratic_solve(const Scalars scalars)
{
	Roots roots = {0, 0, 0};
	float d = (scalars.b * scalars.b) - (4.0 * scalars.a * scalars.c);
	if (float_equals(d, 0.0, EPS))
	{
		roots.n = 1;
		if (!float_equals(scalars.a, 0.0, EPS))
			roots.x = (-scalars.b) / (2 * scalars.a);
		else
			roots.x = 0;
	}
	else if (d < 0)
	{
		roots.n = 0;
	}
	else
	{
		roots.n = 2;
		roots.x = (-scalars.b + sqrt(d)) / (2 * scalars.a);
		roots.y = (-scalars.b - sqrt(d)) / (2 * scalars.a);
	}
	return roots;
}

int is_argument_valid(const char* const arg)
{
	int comma_ind, sign_ind;
	int i;
	int c;
	int arg_size = strlen(arg);
	comma_ind = sign_ind = -1;
	for (i = 0; i < arg_size; i++)
	{
		c = arg[i];
		if (c == '.' || c == ',') 
		{
			if (comma_ind == -1)
				comma_ind = i;
			else
				return 0;
		}
		if (c == '-' || c == '+') 
		{
			if (sign_ind == -1)
				sign_ind = i;
			else
				return 0;
		}
		if (!isdigit(c) && c != '.' && c != ',' && c != '-' && c != '+') return 0;
	}

	return (comma_ind != 0 && comma_ind != arg_size -1 && (sign_ind == -1 || sign_ind == 0));
}

float almost_my_atof(const char s[])
{
	float val, power;
	int i, sign;
	for (i = 0; isspace(s[i]); i++)
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.' || s[i] == ',')								//just one little change for ',' case
		i++;
	for (power = 1.0; isdigit(s[i]); i++)
	{
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}
	return sign * val / power;
}

int float_equals(const float a, const float b, const float eps)
{
	return fabs(a - b) <= eps;
}

void print_doc()
{
	printf("Hi thanks for trying out my quadratic equation solver\n");
	printf("run this program with coefficients of the equation as arguments\n");
	printf("you can use floating point numbers with dot or comma\n");
	printf("\"equation.h\" header provides you with solve_equation() function, which will return Roots struct\n");
	printf("Roots.n is the number of roots, Roots.x and Roots.y are roots value, Roots.x > Roots.y\n");
	printf("If equation has only one root, it will be stored in Roots.x\n");
}