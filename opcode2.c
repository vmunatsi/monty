#include "monty.h"

/**
* _swap - swaps the top two elements of the stack
* @stack: head of the list
* @line_number: element of the node
*/

void _swap(stack_t **stack, unsigned int line_number)
{
	int tmp;
	(void)line_number;
	tmp = (*stack)->next->n;
	(*stack)->next->n = (*stack)->n;
	(*stack)->n = tmp;
}

/**
* _len - function that returns number of elements
* @stack: header of stack
* Return: number of elements in the stack
*/

size_t _len(const stack_t *stack)
{
	int count = 0;

	while (stack != NULL)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

/**
* _add - adds the top two elements
* @stack: header
* @line_number: elements
*/

void _add(stack_t **stack, unsigned int line_number)
{
	int lenght;
	int tmp, sum;

	lenght = _len(*stack);
	if (lenght < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n;
	sum = tmp + (*stack)->next->n;
	(*stack)->next->n = sum;
	_pop(stack, line_number);
}

/**
* _nop - doesn't do anything
* @stack: header
* @line_number: line number
*/

void _nop(stack_t **stack, unsigned int line_number)
{
	(void)(*stack);
	(void)line_number;
}
