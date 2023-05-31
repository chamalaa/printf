#ifndef _PRI_H
#define _PRI_H
#include <stdarg>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>


#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1
#define NULL_STRING "(null)"
#define PRMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define CONVERT_LOWERCASE  1
#define CONVERT_UNSIGNED  2
/**
* struct parameters - parameters struct
*
* @unsign: unsigned value
*
* @plus_fg: plus_fg specif
* @space_fg: hashtag_fg specif
* @hashtag_fg: hash fg specif
* @zero_fg: 0_fg specif
* @minus_fg: min_fg specif
*
* @width: field width specified
* @precision: field precision specified
*
* @h_modifier: hmodifier is specified
* @l_modifier: lmodifier is specified
*
*/

typedef struct parameters
{
unsigned int unsign : 1;
unsigned int plus_fg : 1;
unsigned int space_fg : 1;
unsigned int hashtag_fg : l;
unsigned int zero_fg : 1;
unsigned int minus_fg : l;
unsigned int width;
unsigned int precision;
unsigned int h_modifier : 1;
unsigned int l_modifier : 1;
} prms_t;

/**
* struct specifier - Struct token
*
* @specifier: type token
* @f: function relat
*/
typedef struct specifier
{
char *specifier;
int (*f)(va_list, prms_t *);
} specifier_t;

/* _put .c module */
int _puts(char *str);
int _putchar(int c);

/* pri_functions.c module */
int pri_char (va_list ap, prms_t *prms);
int pri_int(va_list ap, prms_t *prms);
int pri_string(va_list ap, prms_t *prms);
int pri_percent(va_list ap, prms_t *prms);
int pri_S(va_list ap, prms_t *prms);

/* number.c module */
char *convert(long int num, int base, int fg, prms_t *prms);
int pri_unsigned(va_list ap, prms_t *prms);
int pri_address(va_list ap, prms_t *prms);

/* specifier.c module */
int (*get_specifier(char *s))(va_list ap, prms_t *prms);
int get_pri_func(char *s, va_list ap, prms_t *prms);
int get_fg(char *s, prms_t *prms);
int get_modifier(char *s, prms_t *prms);
char *get_width(char *s, prms_t *prms, va_list ap);
/* convert_number.c module */
int pri_hex(va_list ap, prms_t *prms);
int pri_HEX(va_list ap, prms_t *prms);
int pri_binary(va_list ap, prms_t *prms);
int pri_octal(va_list ap, prms_t *prms);
/* simple_printers.c module */
int pri_from_to(char *start, char *stop, char *except);
int pri_rev(va_list ap, prms_t *prms);
int pri_rotl3(va_list ap, prms_t *prms);


/* pri_number.c module */
int _isdigit(int ca);
int _strlen(char *str);
int pri_number(char *b, prms_t *prms);
int pri_number_right_shift(char *b, prms_t *prms);
int pri_number_left_shift(char *b, prms_t *prms);
/* prms .c module */
void init_prms(prms_t *prms, va_list ap);
/* string_fields .c modoule */
char *get_precision(char *ps, prms_t *prms, va_list ap);
/* _prinf.c module */
int _printf(const char *format, ...);

#endif

