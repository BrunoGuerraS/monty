#include "monty.h"
/**
 * matcher - generate match
 * @s: token
 * @ln: line number
 * Return: Nothing
 */
void (*matcher(variable_t *gb_var))(stack_t **stack, unsigned int line_number)
{
	int i = 0;

	instruction_t order[]= {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	while (order[i].opcode != NULL )
	{
		if (strcmp(gb_var->tokens[0], order[i].opcode) == 0)
		{
			return (order[i].f);
		}
		i++;
	}
	
	fprintf(stderr, "L%u: unknown instruction %s\n", gb_var->nl, gb_var->tokens[0]);
	fclose(gb_var->fd);
	exit(EXIT_FAILURE);
}
