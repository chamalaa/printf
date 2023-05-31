#include "main.h"

/**
 * get_prsion - Determine value of prsion for printing
 * @format: Formatted string in which to print the arguments
 * @i: app of arguments to be pri_nt.
 * @app: app of arguments.
 *
 * Return: Prsion.
 */
int get_prsion(const char *format, int *i, va_list app)
{
	int curr_i = *i + 1;
	int prsion = -1;

	if (format[curr_i] != '.')
		return (prsion);

	prsion = 0;

	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			prsion *= 10;
			prsion += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			prsion = va_arg(app, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (prsion);
}
