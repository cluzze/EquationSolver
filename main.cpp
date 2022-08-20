#include <stdio.h>
#include <stdlib.h>

#include "equation.h"

#define NDEBUG

int main()
{
	char* line = NULL;
	size_t bufsize = 0;
	char** tokens = NULL;
	int tokens_len = 0;
	FILE* inputfd = stdin;
	FILE* outfd = stdout;
#ifdef NDEBUG
	char input_filename[] = "Tests/tests.txt";
	char output_filename[] = "Tests/output.txt";
	inputfd = fopen(input_filename, "r");
	if (!inputfd)
	{
		printf("failed to open inputdf: %s", input_filename);
		exit(EXIT_FAILURE);
	}
	outfd = fopen(output_filename, "w");
#endif
	while (getline(&line, &bufsize, inputfd) != -1)
	{
		tokens = parse_line(line, &tokens_len);
		Roots roots = {0, 0, 0};
		Scalars scalars = {0, 0, 0};
		get_scalars(tokens, tokens_len, &scalars);

		free(tokens);

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
	fclose(inputfd);
	fclose(outfd);
#ifdef NDEBUG
	char expected_filename[] = "Tests/expect.txt";
	FILE* expected_output = fopen(expected_filename, "r");
	if (!expected_filename)
	{
		printf("failed to open expected fd: %s", expected_filename);
		exit(EXIT_FAILURE);
	}
	outfd = fopen(output_filename, "r");
	if (!outfd)
	{
		printf("failed to open outdf: %s", output_filename);
		exit(EXIT_FAILURE);
	}
	compare_two_files(outfd, expected_output);
	fclose(expected_output);
	fclose(outfd);
#endif	
	return 0;
}