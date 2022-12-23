#include "monty.h"

/**
* _push - push a node onto the stack
* @stack: stack
* @line_number: line number in monty.m file
* Return: void
*/
void _push(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *temp;
	temp = malloc(sizeof(stack_t));

	if (temp == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	temp->prev = temp->next = NULL;

	if (!(*stack))
		(*stack) = temp;
	else
	{
		(*stack)->prev = temp;
		temp->next = *stack;
		*stack = temp;
	}
}
/**
 * _pall - print all data in stack
 * @stack: stack
 * @line_number: line number in monty .m file
 * Return: void
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	(void) line_number;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
/**
 * _pint - print top int
 * @stack: stack
 * @line_number: line number in monty .m file
 * Return: void
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	fprintf(stdout, "%d\n", (*stack)->n);
}
