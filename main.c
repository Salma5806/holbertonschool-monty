#include "monty.h"

unsigned int line_number = 0;

/**
 * main - control program flow
 * @argc: argument count
 * @argv: argument list
 * Return: Nothing
 */
int main(int argc, char *argv[])
{
	unsigned int  i = 0;
	char **tokens = NULL;
	stack_t *head = NULL;
	char *buffer = NULL;
	FILE *fp;
	size_t line_number;

	if (argc != 2)
	{
		printf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = open(argv[1], "r+");
	if (fp == NULL)
	{
		printf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((getline(&buffer, &line_number, fp)) != -1)
	{
		i++;
		tokens = tokenize(buffer);
		if (tokens)
		{
			call(tokens, &head);
			free(tokens);
		}
	}
	free(buffer);
	free_stack(&head);
	fclose(fp);

	return (0);
}