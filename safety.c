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
	if (!str)
		return (0);
	for (int i = 0; str[i]; i++)
		if (!isdigit(str[i]))
			return (0);
	return (1);
}
