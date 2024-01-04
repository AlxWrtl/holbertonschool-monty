#include "monty.h"

/**
 * main - Entry point for the Monty bytecodes interpreter.
 * @argc: Argument count.
 * @argv: Argument vector.
 *
 * Description: Opens a Monty bytecode file, reads its instructions,
 *              and executes them. If the file cannot be opened or
 *              the number of arguments is incorrect, the program
 *              exits with an error.
 *
 * Return: Exit status.
 */
int main(int argc, char **argv)
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char *opcode;
	int line_number = 0;
	monty_stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		opcode = strtok(line, " \n");
		if (opcode)
		{
			handle_opcode(&stack, opcode, line_number); /* Update the type */
		}
	}

	free(line);
	fclose(file);
	free_stack(stack);
	return (0);
}
