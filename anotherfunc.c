#include "monty.h"
/**
 * _pop - removes top item from stack
 * @stack: stack
 * @line_number: monty file line number
 * Return: void
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);

		exit(EXIT_FAILURE);
	}
	if (tmp->next == NULL)
	{
		free(*stack);
		*stack = NULL;
	}
	else
	{
		(*stack) = (*stack)->next;
		(*stack)->prev = NULL;
		free(tmp);
	}
}
/**
 * _nop - do nothing
 * @stack: unused
 * @line_number: unused
 * Return: void
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
/**
 * _swap - swaps data from top two nodes in stack
 * @stack: stack
 * @line_number: monty file line number
 * Return: void
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
/**
 * _add - swaps the data in two nodes
 * @stack: pointer to a stack_t
 * @line_number: line number
 */
void _add(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || (*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		if (*stack)
			free_stack(stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = ((*stack)->next->n) + ((*stack)->n);
	_pop(stack, line_number);
}
