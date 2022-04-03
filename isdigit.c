#include "monty.h"
/**
 * sdig - know is digit
 * @s: stirng
 * Return: int
 */
int sdig(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (!(isdigit(s[i])))
		{
			fprintf(stderr, "L%d: usage: push integer\n", var_gb.nl);
			fclose(var_gb.fd);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (1);
}
