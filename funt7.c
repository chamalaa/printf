#include "main.h"

/*flag*/
/**
 * getfonct_flag - Determine the value of the var flg
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flg:
 */
int getfonct_flag(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, curr_i;
	int flg = 0;
	const char FLG_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLG_ARR[] = {FG_MIN, FG_PLUS, FG_ZERO, FG_HASH, FG_SPACE, 0};

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		for (j = 0; FLG_CH[j] != '\0'; j++)
			if (format[curr_i] == FLG_CH[j])
			{
				flg |= FLG_ARR[j];
				break;
			}

		if (FLG_CH[j] == 0)
			break;
	}

	*i = curr_i - 1;

	return (flg);
}
