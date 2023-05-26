#include "monty.h"

/**
 * sub - subtracts the top element from the second top element
 * @stack: pointer to the stack
 * @line_number: Line number
 *
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L:%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}


	(*stack)->next->n -= (*stack)->n;
	pop(stack, line_number);
}

