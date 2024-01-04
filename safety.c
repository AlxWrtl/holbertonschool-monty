#include "monty.h"

/**
 * is_valid_integer - Check if a string is a valid integer.
 * @str: The string to check.
 * Return: 1 if valid, 0 otherwise.
 *
 * Description: Iterates through each character of the string to determine
 *              if it is a valid integer. Returns 1 (true) if all characters
 *              are digits, otherwise returns 0 (false).
 */

int is_valid_integer(const char *str)
{
	int i = 0;

	if (!str || !*str)
		return (0);

	if (str[0] == '-')
	{
		if (!str[1])
			return (0);
		i = 1;
	}

	for (; str[i]; i++)
		if (!isdigit(str[i]))
			return (0);
	return (1);
}

/**
 * free_stack - frees a stack.
 * @stack: pointer to the first node (top) of the stack.
 *
 * Description: Iterates through each node of the stack and
 *              frees each node to prevent memory leaks.
 */
void free_stack(monty_stack_t *stack)
{
	monty_stack_t *temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
