#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * struct monty_stack_s - doubly linked list representation of a stack or queue
 * @n: integer
 * @prev: points to the previous element of the stack or queue
 * @next: points to the next element of the stack or queue
 *
 * Description: Doubly linked list node structure
 *              for stack, queues, LIFO, FIFO
 */
typedef struct monty_stack_s
{
	int n;
	struct monty_stack_s *prev;
	struct monty_stack_s *next;
} monty_stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: Opcode and its function
 *              for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(monty_stack_t **stack, unsigned int line_number);
} instruction_t;

/* -------------- Prototypes of opcodes -------- */

void push(monty_stack_t **stack, int n, unsigned int line_number);
void pall(monty_stack_t **stack);
void pint(monty_stack_t **stack);
void pop(monty_stack_t **stack, unsigned int line_number);

/* ---------------- Functions -----------------*/

void handle_opcode(monty_stack_t **stack, char *opcode, unsigned int line_number);
int is_valid_integer(const char *str);
void free_stack(monty_stack_t *stack);

#endif
