#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>

/**
* struct format - print function depending on format.
* @c: character.
* @f: function pointer.
*/
typedef struct format
{
	char *c;
	int (*f)(va_list);
} format_s;

int		_printf(const char *format, ...);
int		_get_char(va_list arg);
int		_get_str(va_list arg);
int		_get_percent(va_list arg);
int		_get_int(va_list arg);
int		_get_uint(va_list arg);
int		_get_octal(va_list arg);
int		_get_hex(va_list arg);
int		_get_HEX(va_list arg);
int		_get_b(va_list arg);
int		_get_non_print(va_list arg);
int		_get_addr(va_list arg);
int		_get_rstr(va_list arg);
int		_get_rotstr(va_list arg);
int		(*get_print_func(const char *format))(va_list);
int		 _putchar(char c);
int		_putstr(char *str);
void	_putnbr(long int n, int *count);
void	_base_convert(long int n, char *base, int len, int *count);
void	_recur(unsigned long int  n, char *base,
				unsigned long int len, int *count);
int		_put_non_print(char *str);
int		_strlen(char *str);
int		_put_rotstr(char *str);


#endif
