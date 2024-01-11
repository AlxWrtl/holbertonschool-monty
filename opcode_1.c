#include "monty.h"

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

/**
 * pint - prints the value at the top of the stack, followed by a new line.
 * @stack: double pointer to the top of the stack.
 * @line_number: line number
 * Description: If the stack is empty, the function prints an error message
 *              and exits with a failure status. The error message should
 *              include the line number, which should be passed to the function
 *              if available.
 */

void pint(monty_stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack.
 * @stack: double pointer to the top of the stack.
 * @line_number: the current line number in the script.
 *
 * Description: If the stack is empty, it prints an error message with
 *              the line number and exits with a failure status.
 */

void pop(monty_stack_t **stack, unsigned int line_number)
{
	monty_stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	free(temp);
	/* To avoid unused variable warnings */
	(void)line_number;
}

/**
 * swap - swaps the top two elements of the stack.
 * @stack: double pointer to the top of the stack.
 * @line_number: the line number
 * Description: If the stack contains fewer than two elements,
 *              the function prints an error message and exits
 *              with a failure status. The error message should
 *              include the line number, which should be passed
 *              to the function if available.
 */

void swap(monty_stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
