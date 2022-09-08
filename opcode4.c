#include "monty.h"

/**
 * _pstr - Print all the elements with ASCII in the stack.
 * @stack: Stack.
 * @line_number: Line number.
 * Return: void.
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;
	while (current != NULL)
	{
		/*printf("%d\n", current->n);*/
		if (current->n < 32 || current->n > 126)
		{
			putchar('\n');
			return;
		}
		else
			putchar(current->n);
		current = current->next;
	}
	putchar('\n');
}

/**
* add_dnodeint_end - function that adds a new node at the end
* @head: doubly linked list
* @n: data of the node
* Return: the address of the new element
*/

void add_dnodeint_end(stack_t **head, unsigned int n)
{
	stack_t *last = (*head);
	stack_t *new_node = (stack_t *)malloc(sizeof(stack_t));

	new_node->n = n;
	new_node->next = NULL;
	if ((*head) == NULL)
	{
		new_node->prev = NULL;
		(*head) = new_node;
	}
	while (last->next != NULL)
		last = last->next;

	last->next = new_node;
	new_node->prev = last;
}

/**
* _rotl - rotates the stack to the top.
* @stack: header
* @line_number: elements
*/

void _rotl(stack_t **stack, unsigned int line_number)
{
	unsigned int tmp;
	stack_t *current = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
		return;
	tmp = current->n;
	_pop(stack, line_number);
	add_dnodeint_end(stack, tmp);
}

/**
* _rotr - rotates the stack to the bottom.
* @stack: header
* @line_number: elements
*/

void _rotr(stack_t **stack, unsigned int line_number)
{
	unsigned int tmp;
	stack_t *current = *stack, *new_node;

	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
		return;
	while (current->next != NULL)
	{
		current = current->next;
	}
	tmp = current->n;
	delete_dnodeint_at_index(stack, _len(*stack) - 1);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = tmp;
	new_node->prev = NULL;
	new_node->next = *stack;
	*stack = new_node;
}

/**
 * delete_dnodeint_at_index - Insert a node in a index of the list.
 * @head: Head of the list.
 * @index: Index.
 * Return: 1 if works, -1 if doesn't.
 */
void delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	stack_t *current;
	unsigned int i;

	current = *head;
	if (index == 0)
	{
		if (current->next != NULL)
		{ (current->next)->prev = NULL;
			*head = current->next;
			free(current);
		}
		else
		{ *head = NULL;
			free(current);
		}
	}
	for (i = 0; i < index && current != NULL; i++, current = current->next)
	{
		;
	}
	if (current->next == NULL)
	{ (current->prev)->next = NULL;
		free(current);
	}
	else
	{ (current->prev)->next = current->next;
		(current->next)->prev = current->prev;
		free(current);
	}
}
