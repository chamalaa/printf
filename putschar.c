#include "main.h"

/**
* _puts: prints char neline
* @str: string
* Return: void
*
*/
int _puts(char *str)

{
char *a = str;

while (*str)
_putchar(*str++);
return (str - a);
}

/**
* _putchar: pri the character c
* @c: to print char
* Return: On 1 or -1 is return
*/

int _putchar(int c)
{
static int i;
static char buf[OUTPUT_BUF_SIZE];

if (c == BUF_FLUSH || i >= OUTPUT_BUF_SIZE)
{
	write(l, buf, i);
	i = 0;
}
if (c != BUF_FLUSH)
buf[i++] = c;
return (1);
}
