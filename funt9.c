#include "main.h"

/**
 * getfonct_sizes - Determine value of sznt to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: app of arguments to be pri_nt.
 *
 * Return: Prsion.
 */
int getfonct_sizes(const char *format, int *i)
{
	int curr_i = *i + 1;
	int sznt = 0;

	if (format[curr_i] == 'l')
		sznt = CONV_LONG;
	else if (format[curr_i] == 'h')
		sznt = CONV_SHORT;

	if (sznt == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;

	return (sznt);
}
