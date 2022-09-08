#include "monty.h"

/**
 * stack_len - Count the elements in the stack.
 * @h: head of the stack.
 * Return: Number of nodes.
 */
size_t stack_len(const stack_t *h)
{
	int counter = 0;

	while (h != NULL)
	{
		counter++;
		h = h->next;
	}
	return (counter);
}

/**
 * chkpint - check pint.
 * @line_buf: Buffer getline.
 * @fp: File descriptor.
 * @stack: Stack.
 * @line: Line number.
 * Return: void.
 */
void chkpint(char *line_buf, FILE *fp, stack_t *stack, unsigned int line)
{
	if (stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line);
		free(line_buf);
		free_stack(stack);
		fclose(fp);
		exit(EXIT_FAILURE);
	}
}

/**
 * chkpop - check pop.
 * @line_buf: Buffer getline.
 * @fp: File descriptor.
 * @stack: Stack.
 * @line: Line number.
 * Return: void.
 */
void chkpop(char *line_buf, FILE *fp, stack_t *stack, unsigned int line)
{
	if (stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		free(line_buf);
		free_stack(stack);
		fclose(fp);
		exit(EXIT_FAILURE);
	}
}

/**
 * chkswap - check swap.
 * @line_buf: Buffer getline.
 * @fp: File descriptor.
 * @stack: Stack.
 * @line: Line number.
 * Return: void.
 */
void chkswap(char *line_buf, FILE *fp, stack_t *stack, unsigned int line)
{
	int len;

	len = stack_len(stack);
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
		free(line_buf);
		free_stack(stack);
		fclose(fp);
		exit(EXIT_FAILURE);
	}
}

/**
 * chkadd - check add.
 * @line_buf: Buffer getline.
 * @fp: File descriptor.
 * @stack: Stack.
 * @line: Line number.
 * Return: void.
 */
void chkadd(char *line_buf, FILE *fp, stack_t *stack, unsigned int line)
{
	int len;

	len = stack_len(stack);
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		free(line_buf);
		free_stack(stack);
		fclose(fp);
		exit(EXIT_FAILURE);
	}
}
