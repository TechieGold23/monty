#include "monty.h"

/**
 *
 *
 *
 */
void execute_opcode(char *opcode, char *argument,
		stack_t **stack, unsigned int line_number)
{
	int arg;

	if (strcmp(opcode, "push") == 0)
	{
		if (argument == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}

		if (!isdigit((unsigned char)argument[0]) && argument[0] != '-')
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}

		arg = atoi(argument);
		push(stack, arg);
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(stack);
	}
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}

/**
 *
 *
 *
 *
 */
void process_line(char *line, stack_t **stack, unsigned int line_number)
{
	char *token;
	char *opcode;
	char *argument = NULL;

	/* Tokenize the line */
	token = strtok(line, " ");
	opcode = token;

	if (opcode != NULL && opcode[0] != '#')
	{
		token = strtok(NULL, " ");
		if (token != NULL)
			argument = token;

	execute_opcode(opcode, argument, stack, line_number);
	}
}

/**
 *
 *
 */
void process_file(FILE *file)
{
	stack_t *stack = NULL;
	char line[MAX_LINE_LENGTH];
	int line_number = 1;

	while (fgets(line, sizeof(line), file) != NULL)

	{
		/* Remove trailing newline character */
		line[strcspn(line, "\n")] = '\0';

		process_line(line, &stack, line_number);
		line_number++;
	}
}
