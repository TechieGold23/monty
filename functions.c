#include "monty.h"

/**
 * execute_opcode - execute op code
 * @opcode: opcode
 * @argument: argument
 * @stack: stack
 * @line_number: line_number
 *
 * Return: void
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
		push(stack, arg, line_number);
	}
	else if (strcmp(opcode, "pall") == 0)
		pall(stack);
	else if (strcmp(opcode, "pint") == 0)
		pint(stack, line_number);
	else if (strcmp(opcode, "pop") == 0)
		pop(stack, line_number);
	else if (strcmp(opcode, "swap") == 0)
		swap(stack, line_number);
	else if (strcmp(opcode, "add") == 0)
		add(stack, line_number);
	else if (strcmp(opcode, "nop") == 0)
		nop(stack, line_number);
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}

/**
 * process_line - process line
 * @stack: stack
 * @line: line
 * @line_number: line number
 *
 * Return: void
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
 * process_file - process file
 * @file: file
 *
 * Return: void
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
