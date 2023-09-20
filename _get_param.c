#include "main.h"

/**
  * get_print_func - gets the right function to print data.
  * @format: data specifier
  * Return: a int function with va_list argument.
  */

int	(*get_print_func(const char *format))(va_list)
{
	format_s array[] = {
		{"d", _get_int},
		{"i", _get_int},
		{"c", _get_char},
		{"s", _get_str},
		{"%", _get_percent},
		{"u", _get_uint},
		{"o", _get_octal},
		{"x", _get_hex},
		{"X", _get_HEX},
		{"b", _get_b},
		{"S", _get_non_print},
		{"p", _get_addr},
		{"r", _get_rstr},
		{"R", _get_rotstr},
		{NULL, NULL}
	};
	int	i;

	i = 0;
	while (array[i].c && *(array[i].c) != *format)
		i++;
	return (array[i].f);
}
