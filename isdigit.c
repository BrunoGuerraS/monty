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
			return (0);
		}
		i++;
	}
	return (1);
}
