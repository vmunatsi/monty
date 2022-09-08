#include "monty.h"

/**
 * main - Main of the function.
 * @argc: Number of arguments.
 * @argv: Arguments.
 * Return: Exit success.
 */
int main(int argc, char *argv[])
{
	char *line_buf = NULL;
	size_t line_buf_size = 0;
	unsigned int line_count = 0;
	FILE *fp;
	char *token1, *token2;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line_buf, &line_buf_size, fp) != EOF)
	{
		line_count++;
		token1 = strtok(line_buf, " \t\r\n\a");
		if (token1 == NULL)
			continue;
		if (*token1 == '#')
			continue;
		token2 = strtok(NULL, " \t\r\n\a");
		cmp(token1, token2, line_buf, fp, &stack, (int)line_count);
		check_token(token1, line_count, &stack);
	}
	free(line_buf);
	line_buf = NULL;
	free_stack(stack);
	fclose(fp);
	exit(EXIT_SUCCESS);
	return (0);
}
