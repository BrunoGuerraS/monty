#include "monty.h"
/*
 * _push - if is the first node create it or add
 * @opcode: option
 * @value: int value
 * Return: nothing 
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	if (!stack)
		fprintf(stderr, "el head esta vacio");

	node = malloc(sizeof(stack_t));

	if (*stack)
		(*stack)->prev = node;

	node->n = line_number;
	node->next = *stack;
	node->prev = NULL;
	
	*stack = node;

}
