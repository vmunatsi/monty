#include "monty.h"

/**
 * check_token - check if the token exist.
 * @token1: First token.
 * @line_number: Line number.
 * @stack: Stack.
 * Return: void.
 */
void check_token(char *token1, unsigned int line_number, stack_t **stack)
{
	instruction_t array[] = {
			{"push", _push},
			{"pall", _pall},
			{"pint", _pint},
			{"pop", _pop},
			{"swap", _swap},
			{"add", _add},
			{"nop", _nop},
			{"sub", _sub},
			{"div", _div},
			{"mul", _mul},
			{"mod", _mod},
			{"pchar", _pchar},
			{"pstr", _pstr},
			{"rotl", _rotl},
			{"rotr", _rotr},
			{NULL, NULL}
			};
	int i = 0;

	while (array[i].opcode != NULL)
	{
		if (strcmp(array[i].opcode, token1) == 0)
		{
			array[i].f(&(*stack), line_number);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token1);
	exit(EXIT_FAILURE);
}

/**
 * chkpush - check push.
 * @token: First token.
 * @line_buf: Buffer getline.
 * @fp: File descriptor.
 * @stack: Stack.
 * @line: Line number.
 * Return: void.
 */
void chkpush(char *token, char *line_buf, FILE *fp, stack_t *stack, int line)
{
	int i = 0;

	if (token != NULL)
	{
		while (token[i] != '\0')
		{
			if (token[i] >= '0' && token[i] <= '9')
			{
				i++;
				continue;
			}
			else if (token[i] == '-')
			{
				i++;
				continue;
			}
			else
			{
				fprintf(stderr, "L%d: usage: push integer\n", line);
				free(line_buf);
				free_stack(stack);
				fclose(fp);
				exit(EXIT_FAILURE);
			}
			i++;
		}
		if (strcmp(token, "0") == 0)
			push_arg = 0;
		else
			push_arg = atoi(token);
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line);
		free(line_buf);
		free_stack(stack);
		fclose(fp);
		exit(EXIT_FAILURE);
	}
}

/**
 * cmp - check if the token is a command.
 * @tk: First token.
 * @arg: Argument.
 * @buf: Buffer getline.
 * @fp: File descriptor.
 * @stack: Stack.
 * @line: Line number.
 * Return: void.
 */
void cmp(char *tk, char *arg, char *buf, FILE *fp, stack_t **stack, int line)
{
	if (strcmp(tk, "push") == 0)
		chkpush(arg, buf, fp, *stack, line);
	else if (strcmp(tk, "pint") == 0)
		chkpint(buf, fp, *stack, line);
	else if (strcmp(tk, "pop") == 0)
		chkpop(buf, fp, *stack, line);
	else if (strcmp(tk, "swap") == 0)
		chkswap(buf, fp, *stack, line);
	else if (strcmp(tk, "add") == 0)
		chkadd(buf, fp, *stack, line);
}
