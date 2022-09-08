#include "monty.h"

/**
 * _push - Add a new elemtn to the stack.
 * @stack: Stack.
 * @line_number: Line number.
 * Return: void.
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	(void)line_number;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = push_arg;
	new_node->next = (*stack);
	new_node->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * _pall - Print all the elements in the stack.
 * @stack: Stack.
 * @line_number: Line number.
 * Return: void.
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * free_stack - Free the stack.
 * @head: Head of the stack.
 * Return: void.
 */
void free_stack(stack_t *head)
{
	stack_t *next;

	if (head == NULL)
		return;
	next = head->next;
	while (head != NULL)
	{
		free(head);
		head = next;
		if (head != NULL)
			next = next->next;
	}
}

/**
* _pint - print the value at the top of the stack
* @stack: head of the list.
* @line_number: element of the node
*/

void _pint(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if ((*stack) != NULL)
		printf("%d\n", (*stack)->n);
}

/**
* _pop - removes the top element of the stack
* @stack: head of the list
* @line_number: element of the node
*/

void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;
	if (current->next != NULL)
	{
		(current->next)->prev = NULL;
		*stack = current->next;
		free(current);
	}
	else
	{
		*stack = NULL;
		free(current);
	}
}
