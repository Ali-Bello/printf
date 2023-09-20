#include "main.h"

/**
 * _get_addr - gets pointer argument.
 * @arg: argument source.
 * Return: charcaters printed.
*/

int	_get_addr(va_list arg)
{
	unsigned long int	ptr;
	int			count;

	ptr = va_arg(arg, unsigned long int);
	if (!ptr)
		return (_putstr("(nil)"));

	count = 0;
	count += _putstr("0x");
	_recur(ptr, "0123456789abcdef", 16, &count);
	return (count);
}

/**
 * _recur - prints the addres using recursion.
 * @n: the address.
 * @base: the hexadecimal base.
 * @len: the length of the base.
 * @count: print counter.
*/
void	_recur(unsigned long int  n, char *base,
				unsigned long int len, int *count)
{
	if (n >= len)
		_recur(n / len, base, len, count);
	write(1, &base[n % len], 1);
	(*count)++;
}
/**
 * _get_rstr - gets reversed string argument.
 * @arg: argument source.
 * Return: charcaters printed.
*/

int	_get_rstr(va_list arg)
{
	int		i, count;
	char	*str;

	str = va_arg(arg, char *);
	if (!str)
		return (_putstr("(null)"));

	i = _strlen(str) - 1;
	count = 0;
	while (i >= 0)
	{
		write(1, &str[i--], 1);
		count++;
	}
	return (count);
}

/**
  * _get_rotstr - gets a rot13'ed string.
  * @arg: string source.
  * Return: characters printed.
  */

int	_get_rotstr(va_list arg)
{
	char	*str;

	str = va_arg(arg, char *);
	if (!str)
		return (_putstr("(null)"));
	return (_put_rotstr(str));
}
