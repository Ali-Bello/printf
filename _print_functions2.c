#include "main.h"

/**
 * _strlen - lengths of a string.
 * @str: the string.
 * Return: the length.
*/

int	_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/**
 * _is_alpha - determine if a char is alphabetical.
 * @c: the char.
 * Return: 0 on succes.
*/

int	_is_alpha(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (2);
	return (0);
}

/**
 * _put_rotstr - prints a rot13'ed string.
 * @str: the string.
 * Return: charcaters printed.
*/

int	_put_rotstr(char *str)
{
	int	i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (_is_alpha(str[i]))
		{
			if ((str[i] <= 'Z' - 13)
			|| (_is_alpha(str[i]) == 1 && str[i] <= 'z' - 13))
				count += _putchar(str[i] + 13);
			else
				count += _putchar(str[i] - 13);
		}
		else
		    count += _putchar(str[i]);
		i++;
	}
	return (count);
}
