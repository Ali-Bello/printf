#include "main.h"

/**
 * _get_char - gets char argument.
 * @arg: argument source.
 * Return: characters printed.
*/

int	_get_char(va_list arg)
{
	char	c;

	c = va_arg(arg, int);
	return (_putchar(c));
}

/**
 * _get_str - gets string argument.
 * @arg: argument source.
 * Return: characters printed.
*/

int	_get_str(va_list arg)
{
	char	*str;

	str = va_arg(arg, char *);
	if (!str)
		return (_putstr("(null)"));

	return (_putstr(str));
}

/**
 * _get_percent - handles the % char.
 * @arg: argument source.
 * Return: characters printed.
*/

int	_get_percent(va_list arg)
{
	(void)arg;

	_putchar('%');
	return (1);
}

/**
 * _get_int - gets int argument.
 * @arg: argument source.
 * Return: characters printed.
*/

int	_get_int(va_list arg)
{
	long int	n;
	int		count;

	n = va_arg(arg, int);
	count = 0;
	_putnbr(n, &count);
	return (count);
}

/**
 * _get_uint - gets usnigned int argument.
 * @arg: argument source.
 * Return: characters printed.
*/

int	_get_uint(va_list arg)
{
	long int	n;
	int		count;

	n = va_arg(arg, unsigned int);
	count = 0;
	_putnbr(n, &count);
	return (count);
}
