#include "monty.h"

/**
* _mul - multiple the top two elements
* @stack: header
* @line_number: elements
*/

void _mul(stack_t **stack, unsigned int line_number)
{
	int lenght;
	int tmp, mul;

	lenght = _len(*stack);
	if (lenght < 2)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n;
	mul = tmp * (*stack)->next->n;
	(*stack)->next->n = mul;
	_pop(stack, line_number);
}

/**
* _sub - subtracts the top element of the stack
* @stack: header
* @line_number: elements
*/

void _sub(stack_t **stack, unsigned int line_number)
{
	int lenght;
	int tmp, sub;

	lenght = _len(*stack);
	if (lenght < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n;
	sub = (*stack)->next->n - tmp;
	(*stack)->next->n = sub;
	_pop(stack, line_number);
}

/**
* _div - divides the second top element of the stack
* @stack: header
* @line_number: elements
*/

void _div(stack_t **stack, unsigned int line_number)
{
	int lenght;
	int tmp, div;

	lenght = _len(*stack);
	if (lenght < 2)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n;
	div = (*stack)->next->n / tmp;
	(*stack)->next->n = div;
	_pop(stack, line_number);
}


/**
* _mod - computes the rest of the division of the second top element
* @stack: header
* @line_number: elements
*/

void _mod(stack_t **stack, unsigned int line_number)
{
	int lenght;
	int tmp, mod;

	lenght = _len(*stack);
	if (lenght < 2)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n;
	mod = (*stack)->next->n % tmp;
	(*stack)->next->n = mod;
	_pop(stack, line_number);
}

/**
* _pchar - prints the char at the top of the stack
* @stack: header
* @line_number: elements
*/
void _pchar(stack_t **stack, unsigned int line_number)
{

	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 32 || (*stack)->n > 126)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	putchar(push_arg);
	putchar('\n');
}
