#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "helper.h"
#include "equation.h"


#define TOK_DELIM " \n\t\a\r"

//**********************************DEFINITIONS**********************************

void get_scalars(char** tokens, int tokens_len, Scalars* scalars)
{
	switch (tokens_len)
	{
		case 1:
			if (strcmp(tokens[0], "help") == 0)
			{
				print_doc();
				exit(EXIT_FAILURE);
			}
			break;
		case 3:													//calling with 3 scalars of equation
			if (is_argument_valid(tokens[0]) 
				&& is_argument_valid(tokens[1])
				&& is_argument_valid(tokens[2]))
			{
				scalars->a = almost_my_atof(tokens[0]);
				scalars->b = almost_my_atof(tokens[1]);
				scalars->c = almost_my_atof(tokens[2]);
			}
			else
			{
				printf("Incorrect arguments, try running with \"help\" option\n");
				exit(EXIT_FAILURE);
			}
			break;
		default:												//calling with something else
			printf("Incorrect number of arguments, try running with \"help\" option\n");
			exit(EXIT_FAILURE);
	}
}

char** parse_line(char* line, int* len)
{
	int size = 120;
	int pos = 0;
	char** tokens = (char**)malloc(size * sizeof(char*));
	char* token;

	if (!tokens)
	{
		printf("tokens allocation failure\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, TOK_DELIM);
	while (token)
	{
		tokens[pos++] = token;
		if (pos >= size)
		{
			size *= 2;
			tokens = (char**)realloc(tokens, size * sizeof(char*));
			if (!tokens)
			{
				printf("tokens allocation failure\n");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, TOK_DELIM);
	}

	*len = pos;
	tokens[pos] = NULL;
	return tokens;
}

char *read_line(FILE* fd)
{
	char *line = NULL;
	size_t bufsize = 0;

	if (getline(&line, &bufsize, fd) == -1)
	{
		if (feof(fd))
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("readline");
			exit(EXIT_FAILURE);
		}
	}
	return line;
}

void linear_solve(const Scalars scalars, Roots* roots)
{
	roots->n = 1;
	roots->x = round_to_zero((-scalars.c) / (scalars.b));
}

void quadratic_solve(const Scalars scalars, Roots* roots)
{
	double d = (scalars.b * scalars.b) - (4.0 * scalars.a * scalars.c);
	if (float_equals(d, 0.0, EPS))
	{
		roots->n = 1;
		if (!float_equals(scalars.a, 0.0, EPS))
			roots->x = round_to_zero((-scalars.b) / (2 * scalars.a));
		else
			roots->x = 0;
	}
	else if (d < 0)
	{
		roots->n = 0;
	}
	else
	{
		roots->n = 2;
		roots->x = round_to_zero((-scalars.b + sqrt(d)) / (2 * scalars.a));
		roots->y = round_to_zero((-scalars.b - sqrt(d)) / (2 * scalars.a));
	}
}

int is_argument_valid(const char* const arg)
{
	int comma_ind = 0, sign_ind = 0;
	int i = 0;
	int c = 0;
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

double almost_my_atof(const char s[])
{
	double val = NAN, power = NAN;
	int i = 0, sign = 0;
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

int float_equals(const double a, const double b, const double eps)
{
	return fabs(a - b) <= eps;
}

double round_to_zero(const double a)
{
	if (float_equals(a, 0, EPS))
	{
		return 0;
	}
	return a;
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