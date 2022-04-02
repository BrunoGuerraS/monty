#include "monty.h"
/*
 * _pall - print all node's value
 * @stack: double p
 * @line_number:
 */
void pall(stack_node **stack, unsigned int line_number)
{
	stack_node *tmp = *stack;
	(void)line_number;

	if (!stack)
		fprintf(stderr, "esta vacia");

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
