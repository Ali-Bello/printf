#include "main.h"

/**
 * _get_octal - gets octal argument.
 * *@arg: argument source.
 * Return: characters printed.
*/

int	_get_octal(va_list arg)
{
	long int	n;
	int		count;

	count = 0;
	n = va_arg(arg, unsigned int);
	_base_convert(n, "01234567", 8, &count);
	return (count);
}

/**
 * _get_hex - gets hexa argument.
 * *@arg: argument source.
 * Return: characters printed.
*/

int	_get_hex(va_list arg)
{
	long int	n;
	int	count;

	n = va_arg(arg, unsigned int);
	count = 0;
	_base_convert(n, "0123456789abcdef", 16, &count);
	return (count);
}

/**
 * _get_HEX - gets HEXA argument.
 * *@arg: argument source.
 * Return: characters printed.
*/

int	_get_HEX(va_list arg)
{
	long int	n;
	int		count;

	n = va_arg(arg, unsigned int);
	count = 0;
	_base_convert(n, "0123456789ABCDEF", 16, &count);
	return (count);
}

/**
 * _get_b - gets binary argument.
 * *@arg: argument source.
 * Return: characters printed.
*/

int	_get_b(va_list arg)
{
	long int	n;
	int		count;

	n = va_arg(arg, unsigned int);
	count = 0;
	_base_convert(n, "01", 2, &count);
	return (count);
}

/**
 * _get_non_print - gets nonprintable argument.
 * *@arg: argument source.
 * Return: characters printed.
*/

int	_get_non_print(va_list arg)
{
	char	*str;

	str = va_arg(arg, char *);
	if (!str)
		return (_putstr("(null)"));

	return (_put_non_print(str));
}
