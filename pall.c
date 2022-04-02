#include "monty.h"
/**
 * pall - print all node's value
 * @stack: double p
 * @line_number: value
 * Return: nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void)line_number;

	if (!stack)
		fprintf(stderr, "esta vacia");

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
