#include "monty.h"

/**
 * add - adds the top two elements of the stack.
 * @stack: double pointer to the top of the stack.
 * @line_number: script line number.
 *
 * Description: If the stack contains fewer than two elements,
 *              the program exits with a failure status.
 */

void add(monty_stack_t **stack, unsigned int line_number)
{
	int sum;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	sum = (*stack)->n + (*stack)->next->n;
	pop(stack, line_number); /* Add line_number as the second argument */
	(*stack)->n = sum;
}

/**
 * nop - A function that does nothing.
 * @stack: Double pointer to the top of the stack.
 *
 * Description: This function is a no-operation function. It serves
 *              to avoid unused variable warnings when an opcode
 *              requires no action.
 */

void nop(monty_stack_t **stack)
{
	/* To avoid unused variable warnings */
	(void)stack;
}
