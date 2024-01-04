#include "monty.h"

/**
 * handle_opcode - Handle Monty opcode.
 * @stack: A pointer to the top of the stack.
 * @opcode: The opcode to handle.
 * @line_number: The current line number in the Monty file.
 *
 * Description: This function compares the given opcode with known opcodes
 *              and calls the corresponding function. If an invalid opcode
 *              is found, it prints an error message and exits the program.
 *              The function also handles the 'push' opcode by ensuring the
 *              argument is a valid integer.
 */
void handle_opcode(
	monty_stack_t **stack, char *opcode, unsigned int line_number)

{
	if (strcmp(opcode, "push") == 0)
	{
		char *num_arg = strtok(NULL, " \n");

		if (!num_arg || !is_valid_integer(num_arg))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		push(stack, atoi(num_arg), line_number);
	}
	else if (strcmp(opcode, "pall") == 0)
		pall(stack);
	else if (strcmp(opcode, "pint") == 0)
		pint(stack);
	else if (strcmp(opcode, "pop") == 0)
		pop(stack, line_number);
	else if (strcmp(opcode, "swap") == 0)
		swap(stack);
	else if (strcmp(opcode, "add") == 0)
		add(stack, line_number);
	else if (strcmp(opcode, "nop") == 0)
		nop(stack);
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}
