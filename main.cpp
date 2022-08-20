#include <stdio.h>
#include <stdlib.h>

#include "equation.h"

//#define NDEBUG

int main()
{
	char* line = NULL;
	char** tokens = NULL;
	int tokens_len = 0;
	FILE* fd = stdin;
	FILE* outfd = stdout;
#ifdef NDEBUG
	fd = fopen("tests.txt", "r");
	outfd = fopen("output.txt", "w");
#endif
	while ((line = read_line(fd)))
	{
		tokens = parse_line(line, &tokens_len);
		Roots roots = {0, 0, 0};
		Scalars scalars = {0, 0, 0};
		get_scalars(tokens, tokens_len, &scalars);

		if (float_equals(scalars.a, 0, EPS) &&
			float_equals(scalars.b, 0, EPS) &&
			float_equals(scalars.c, 0, EPS))
		{
			roots.n = 3;
		}
		else if (float_equals(scalars.a, 0, EPS))
		{
			if (float_equals(scalars.b, 0, EPS))
			{
				roots.n = 0;
			}
			else
			{
				linear_solve(scalars, &roots);
			}
		}
		else
		{
			quadratic_solve(scalars, &roots);
		}
		switch(roots.n)
		{
			case 0:
				fprintf(outfd, "No roots\n");
				break;
			case 1:
				fprintf(outfd, "One root: %f\n", roots.x);
				break;
			case 2:
				fprintf(outfd, "Two roots: %f, %f\n", roots.x, roots.y);
				break;
			case 3:
				fprintf(outfd, "Infinite number of roots\n");
				break;
		}
	}
	free(line);
    free(tokens);
}