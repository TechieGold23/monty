#include "monty.h"

/**
 * main - Entry Point
 * @argc: arguments
 * @argv: array of args
 *
 * Return: Always success 0
 */
int main(int argc, char *argv[])
{
	FILE *file = fopen(argv[1], "r");

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	process_file(file);

	fclose(file);
	return (0);
}
