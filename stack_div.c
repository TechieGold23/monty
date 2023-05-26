#include "monty.h"

/**
 * dive - divides the second top element of the stack by the top element
 * @stack: pointer to the stack
 * @line_number: line number
 *
 * Return: void
 */

void dive(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	int divisor, dividend;

	if (top == NULL || top->next == NULL)
	{
		fprintf(stderr, "L%d:, can't divide, stack too short\n", line_number);
		exit(EXIT_FAILURE);

	}

	divisor = top->n;
	if (divisor == 0)
	{
		fprintf(stderr, "L%d: division by zero \n", line_number);
		exit(EXIT_FAILURE);

	}

	*stack = top->next;
	dividend = (*stack)->n;
	(*stack)->n = dividend / divisor;

	free(top);

}
