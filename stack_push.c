#include "monty.h"
#include <stdlib.h>


/**
 * push - push to stack
 * @stack: pointer to stack
 * @value: value
 * @line_number: line number
 *
 * Return: void
 */
void push(stack_t **stack, int value, unsigned int line_number)
{
	stack_t *new_node = (stack_t *)malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (value != (int)value)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free(new_node);
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}
