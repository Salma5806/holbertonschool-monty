#include "monty.h"
static instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", NULL},
		{"pint", pint},
		{NULL, NULL}
	};

/**
 * call - call appropriate function
 * @tokens: pointer to array of tokens
 * @stack: pointer to a stack
 *
 * Return: nothing
 */
void call(char **tokens, stack_t **stack)
{
	int idx = 0;

	while (ops[idx].opcode)
	{
		if (tokens[0][0] == '#')
			return;
		if (strcmp(tokens[0], ops[idx].opcode) == 0)
		{
			if (ops[idx].f)
				ops[idx].f(stack, i);
			break;
		}
		idx++;
	}

	if (strcmp(tokens[0], "push") == 0)
	{
		valid(tokens, stack);
		(*stack)->n = atoi(tokens[1]);
	}
	else if (!(ops[idx].opcode))
	{
		printf(stderr, "L%u: unknown instruction %s\n",
				line_number,
				tokens[0]);
		exit(EXIT_FAILURE);
	}
}
/**
 * valid - check if second spot of a token array is valid
 * @token: tokens value to check
 * @stack: pointer to a stack
 */
void valid(char **token, stack_t **stack)
{
	int idx = 0;

	if (!token[1])
	{
		printf(stderr, "L%u: usage: push integer\n", i);
		if (*stack)
			free_stack(stack);
		free(token);
		exit(EXIT_FAILURE);
	}

	while (token[1][idx])
	{
		if (token[1][idx] == '-' && idx == 0)
			idx++;
		if (isdigit(token[1][idx]) == 0)
		{
			printf(stderr, "L%u: usage: push integer\n", line_number);
			if (*stack)
				free_stack(stack);
			free(token);
			exit(EXIT_FAILURE);
		}
		idx++;
	}
}

