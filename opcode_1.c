#include "main.h"

/**
 * push - pushes an element onto the stack.
 * @stack: double pointer to the top of the stack.
 * @n: the integer to be pushed onto the stack.
 * @line_number: the current line number in the script.
 *
 * Description: Creates a new node with the given value and
 *              pushes it onto the top of the stack. If memory
 *              allocation fails, it prints an error message with
 *              the line number and exits with a failure status.
 */
void push(monty_stack_t **stack, int n, unsigned int line_number)
{
	monty_stack_t *new_node = malloc(sizeof(monty_stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "L%d: Error: malloc failed\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}

/**
 * pall - prints all the values on the stack, starting from the top.
 * @stack: double pointer to the top of the stack.
 *
 * Description: Iterates through the stack and prints each value.
 *              The format is one integer per line.
 */
void pall(monty_stack_t **stack)
{
	monty_stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
