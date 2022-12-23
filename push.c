#include "monty.h"

/**
* push - push a node onto the stack
* @stack: stack
* @line_number: line number in monty.m file
* Return: void
*/
void push(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *temp;
	temp = malloc(sizeof(stack_t));

	if (temp == NULL)
	{
		printf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	temp->n = data;
	temp->prev = NULL;
	temp->next = NULL;
	if (*stack != NULL)
	{
	temp->next = *stack;
	(*stack)->prev = temp;
	}
	*stack = temp;
}
/**
 * pall - print all data in stack
 * @stack: stack
 * @line_number: line number in monty .m file
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
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
 * pint - print top int
 * @stack: stack
 * @line_number: line number in monty .m file
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty", line_number);
		exit_free(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", tmp->n);
}
