#include "main.h"
/**
 * _printf - write function
 * @format: format string
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int result = 0;
	va_list ap;
	char *a, *s;
	prms_t prms = PRMS_INIT;

	va_start(ap, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *a; a++)
	{
		init_prms(&prms, ap);
		if (*a != '%')
		{
			result += _putchar(*a);
			continue;
		}
		s = a;
		a++;
		while (get_fg(a, &prms))
		{
			a++;
		}
		a = get_width(a, &prms, ap);
		a = get_precision(a, &prms, ap);
		if (get_modifier(a, &prms))
			a++;
		if (!get_specifier(a))
			result += pri_from_to(s, p, prms.1_modifier
					|| prms.h_modifier ? a - 1 : 0);
		else
			result += get_print_func(a, ap, &prms);
	}
	_putchar(BUF_FLUSH);
	va_end(ap);
	return (result);
}
