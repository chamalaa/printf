#ifndef PRI_H
#define PRI_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define INITV(x) (void)(x)
#define BUF_SIZ 1024

/* FLG */
#define FG_MIN 1
#define FG_PLUS 2
#define FG_ZERO 4
#define FG_HASH 8
#define FG_SPACE 16

/* szntS */
#define CONV_LONG 2
#define CONV_SHORT 1

/**
 * struct ferrmt - Struct op
 *
 * @ferrmt: The format.
 * @fn: The function associated.
 */
struct ferrmt
{
	char ferrmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct ferrmt ferrmt_t - Struct op
 *
 * @ferrmt: The format.
 * @fm_t: The function associated.
 */
typedef struct ferrmt ferrmt_t;

int _printf(const char *format, ...);
int handle_print(const char *ferrmt, int *i,
va_list app, char bfr[], int flg, int wdt, int prsion, int sznt);


/* Funtions to print chars and strings */
int prri_char(va_list types, char bfr[],
	int flg, int wdt, int prsion, int sznt);
int prri_string(va_list types, char bfr[],
	int flg, int wdt, int prsion, int sznt);
int prri_percent(va_list types, char bfr[],
	int flg, int wdt, int prsion, int sznt);

/* Functions to print numbers */
int prri_int(va_list types, char bfr[],
	int flg, int wdt, int prsion, int sznt);
int prri_binary(va_list types, char bfr[],
	int flg, int wdt, int prsion, int sznt);
int prri_unsigned(va_list types, char bfr[],
	int flg, int wdt, int prsion, int sznt);
int pri_octal(va_list types, char bfr[],
	int flg, int wdt, int prsion, int sznt);
int prri_hexadecimal(va_list types, char bfr[],
	int flg, int wdt, int prsion, int sznt);
int prri_hexa_upper(va_list types, char bfr[],
	int flg, int wdt, int prsion, int sznt);

int prri_hexa(va_list types, char map_to[],
char bfr[], int flg, char flag_ch, int wdt, int prsion, int sznt);

/* Function to print non printable characters */
int prri_non_printable(va_list types, char bfr[],
	int flg, int wdt, int prsion, int sznt);

/* Funcion to print memory address */
int prri_pointer(va_list types, char bfr[],
	int flg, int wdt, int prsion, int sznt);

/* Funciotns to handle other specifiers */
int getfonct_flag(const char *format, int *i);
int getfonct_wdts(const char *format, int *i, va_list app);
int get_prsion(const char *format, int *i, va_list app);
int getfonct_sizes(const char *format, int *i);

/*Function to print string in reverse*/
int prri_reverse(va_list types, char bfr[],
	int flg, int wdt, int prsion, int sznt);

/*Function to print a string in rot 13*/
int prri_rot13string(va_list types, char bfr[],
	int flg, int wdt, int prsion, int sznt);

/* wdt handler */
int handle_write_char(char c, char bfr[],
	int flg, int wdt, int prsion, int sznt);
int write_number(int is_positive, int ind, char bfr[],
	int flg, int wdt, int prsion, int sznt);
int write_num(int ind, char bff[], int flg, int wdt, int prsion,
	int length, char padd_ing, char extra_c);
int write_pointer(char bfr[], int ind, int length,
	int wdt, int flg, char padd_ing, char extra_c, int padd_ing_start);

int write_unsgnd(int is_negative, int ind,
char bfr[],
	int flg, int wdt, int prsion, int sznt);

int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int sznt);
long int convert_size_unsgnd(unsigned long int num, int sznt);

#endif /* PRI_H */
