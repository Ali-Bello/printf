#include "main.h"

/**
 * _putchar - prints a char.
 * @c: the char.
 * Return: characters printed.
*/

int	_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

/**
 * _putstr - prints a string.
 * @str: the string.
 * Return: characters printed.
*/

int	_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}

/**
 * _putnbr - prints a number.
 * @n: the number.
 * @count: print counter.
*/

void	_putnbr(long int n, int *count)
{
	if (n < 0)
	{
		(*count) += _putchar('-');
		n = -n;
	}
	if (n > 9)
		_putnbr(n / 10, count);
	(*count) += _putchar(n % 10 + '0');
}

/**
 * _base_convert - converts a number to a given base.
 * @n: the number.
 * @base: the base.
 * @len: the length of the base.
 * @count: print counter.
*/

void	_base_convert(long int n, char *base, int len, int *count)
{
	if (n < 0)
	{
		(*count) += _putchar('-');
		n = -n;
	}
	else if (n >= len)
		_base_convert(n / len, base, len, count);
	(*count) += _putchar(base[n % len]);
}

/**
 * _put_non_print - prints a string with non printable chars.
 * @str: the string.
 * Return: characters printed.
*/

int	_put_non_print(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			count += _putstr("\\x");
			count += _putchar("0123456789ABCDEF"[str[i] / 16]);
			count += _putchar("0123456789ABCDEF"[str[i] % 16]);
		}
		else
			count += _putchar(str[i]);
		i++;
	}
	return (count);
}
