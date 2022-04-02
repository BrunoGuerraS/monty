#include "monty.h"
/**
 * main - main function
 * @argc: number of elements
 * @argv: array of elements
 * Return: int
 */
int main(int argc, char **argv)
{
	stack_t *head = NULL;
	variable_t var_important;
	size_t n;
	long int line;
	void (*f)(stack_t **stack, unsigned int line_number);

	var_important.nl = 0;
	var_important.buffer = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	var_important.fd = fopen(argv[1], "r");
	if (var_important.fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	var_important.tokens = malloc(sizeof(char *) * 5);

	if (var_important.tokens == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		fclose(var_important.fd);
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		var_important.nl++;
		line = getline(&(var_important.buffer), &n, var_important.fd);
		if (line == EOF)
			break;
		var_important.tokens[0] = strtok(var_important.buffer, " \n");
		var_important.tokens[1] = strtok(NULL, " \n");

		if (!var_important.tokens[0])
			break;

		if (var_important.tokens[1])
		{
			if (sdig(var_important.tokens[1]))
				var_important.value = atoi(var_important.tokens[1]);
			else
			{
				fprintf(stderr, "L%d: usage: push integer\n", var_important.nl);
				fclose(var_important.fd);
				exit(EXIT_FAILURE);
			}
		}

		f = matcher(&var_important);

		if (f != NULL)
			f(&head, (unsigned int)var_important.value);
	}

	return (0);
}
