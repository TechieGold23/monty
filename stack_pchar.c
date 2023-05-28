#include <stdio.h>
#include <stdlib.h>
#include "monty.h"


/**
 * pchar - prints the char at the top of the stack
 * @stack: pointer to stack
 * @line_number: line number
 *
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_number)
{
    int value;

    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    value = (*stack)->n;

    if (value < 0 || value > 127)
    {
        fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
        exit(EXIT_FAILURE);
    }

    putchar(value);
    putchar('\n');
}

