#include <stdio.h>
#include <stdlib.h>

#include "equation.h"

#define DEBUG

int main()
{
	printf("\e[0;36m");

	char* line = NULL;
	size_t bufsize = 0;
	char** tokens = NULL;
	int tokens_len = 0;
	FILE* inputfd = stdin;
	FILE* outfd = stdout;

#ifdef DEBUG
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
		if (!tokens) continue;
		Roots roots = {0, 0, 0};
		Scalars scalars = {0, 0, 0};
		if(!get_scalars(tokens, tokens_len, &scalars)) continue;

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
	}

	free(line);
	fclose(inputfd);
	fclose(outfd);

#ifdef DEBUG
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