#ifndef MONTY_H
#define MONTY_H

#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

extern int push_arg;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void check_token(char *token1,  unsigned int line_number, stack_t **stack);
void chkpush(char *token, char *line_buf, FILE *fp, stack_t *stack, int line);
void free_stack(stack_t *head);
size_t _len(const stack_t *stack);
void _add(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);
void _pchar(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
void cmp(char *tk, char *arg, char *buf, FILE *fp, stack_t **stack, int line);
void chkpint(char *line_buf, FILE *fp, stack_t *stack, unsigned int line);
void chkpop(char *line_buf, FILE *fp, stack_t *stack, unsigned int line);
void chkswap(char *line_buf, FILE *fp, stack_t *stack, unsigned int line);
void chkadd(char *line_buf, FILE *fp, stack_t *stack, unsigned int line);
void _pstr(stack_t **stack, unsigned int line_number);
void _rotl(stack_t **stack, unsigned int line_number);
void add_dnodeint_end(stack_t **head, unsigned int n);
void _rotr(stack_t **stack, unsigned int line_number);
void delete_dnodeint_at_index(stack_t **head, unsigned int index);

int push_arg;

#endif
