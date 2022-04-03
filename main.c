#include "monty.h"
/**
 * main_monty - initialize value
 * Return: Nothing
 */
variable_t var_gb;

int main_monty(void)
{
	long int line;
	size_t n;
	stack_t *head = NULL;
	void (*f)(stack_t **stack, unsigned int line_number);

	var_gb.tokens = malloc(sizeof(char *) * 5);

	if (var_gb.tokens == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		fclose(var_gb.fd);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		var_gb.nl++;
		line = getline(&(var_gb.buffer), &n, var_gb.fd);

		if (line == EOF)
			break;

		var_gb.tokens[0] = strtok(var_gb.buffer, " \n");
		var_gb.tokens[1] = strtok(NULL, " \n");

		if (!var_gb.tokens[0])
			break;

		if (var_gb.tokens[1])
		{
			if (sdig(var_gb.tokens[1]))
				var_gb.value = atoi(var_gb.tokens[1]);
		}

		f = matcher(&var_gb);

		if (f != NULL)
			f(&head, (unsigned int)var_gb.value);
	}

	return (0);
}

/**
 * main - main function
 * @argc: number of elements
 * @argv: array of elements
 * Return: int
 */
int main(int argc, char **argv)
{
	var_gb.nl = 0;
	var_gb.buffer = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	var_gb.fd = fopen(argv[1], "r");
	if (var_gb.fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	main_monty();

	return (0);
}
