#include "main.h"

/**
 * is_safe - check if the format is safe to proceed.
 * @format: a string.
 * Return: 1 if safe, 0 if not.
*/
int	is_safe(const char *format)
{
	if (!format
	|| (_strlen((char *)format) == 1 && *format == '%'))
		return (0);
	if (*(format) == '%' && (*format + 1) == 'p'
	&& _strlen((char *)format) == 2)
		return (0);

	return (1);
}

/**
  * _printf - simulates the original printf function.
  * @format: the source of format specifiers.
  * @...: variable number of arguments.
  * Return:  number of characters printed.
  */

int	_printf(const char *format, ...)
{
	int	i, count;
	va_list ag;
	int (*p)(va_list);

	if (!is_safe(format))
		return (-1);

	va_start(ag, format);

	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			p = get_print_func(format + i + 1);
			if (p)
			{
				count += p(ag);
				i++;
			}
			else
				count += _putchar(format[i]);
		}
		else
			count += _putchar(format[i]);
		i++;
	}
	va_end(ag);
	return (count);
}
