#include <stdio.h>
#include <stdlib.h>

#include "equation.h"

//#define DEBUG

int main()
{
	printf("\e[0;36m");

	char* line 	      = NULL;
	size_t bufsize    = 0;

	char** tokens     = NULL;
	size_t tokens_len = 0;

	FILE* inputfd     = stdin;
	FILE* outfd       = stdout;

#ifdef DEBUG
	char input_filename[]  = "Tests/tests.txt";
	char output_filename[] = "Tests/output.txt";

	inputfd = fopen(input_filename, "rb");

	if (!inputfd)
	{
		printf("failed to open inputdf: %s", input_filename);
		exit(EXIT_FAILURE);
	}

	outfd = fopen(output_filename, "wb");
#endif

#ifndef DEBUG
	printf("Enter 3 coefficients of equation: ");
#endif

	while (getline(&line, &bufsize, inputfd) != -1)
	{
		Roots roots     = {0, 0, 0};
		Scalars scalars = {0, 0, 0};

		tokens = parse_line(line, &tokens_len);
		if (!tokens) continue;
		if (!get_scalars(tokens, tokens_len, &scalars)) continue;

		free(tokens);

		solve(scalars, &roots);

		switch(roots.n)
		{
			case NO_ROOTS:
				fprintf(outfd, "No roots\n");
				break;
			case ONE_ROOT:
				fprintf(outfd, "One root: %f\n", roots.x);
				break;
			case TWO_ROOTS:
				fprintf(outfd, "Two roots: %f, %f\n", roots.x, roots.y);
				break;
			case INFINITE:
				fprintf(outfd, "Infinite number of roots\n");
				break;
		}


	#ifndef DEBUG
		printf("Enter 3 coefficients of equation: ");
	#endif

	}

	free(line);
	fclose(inputfd);
	fclose(outfd);

#ifdef DEBUG
	char expected_filename[] = "Tests/expect.txt";

	FILE* expected_output = fopen(expected_filename, "rb");

	if (!expected_filename)
	{
		printf("failed to open expected fd: %s", expected_filename);
		exit(EXIT_FAILURE);
	}

	outfd = fopen(output_filename, "rb");
	
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