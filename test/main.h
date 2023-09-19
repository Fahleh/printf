#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFFER 1024

/* SIZES */
#define LONG 2
#define SHORT 1

/* FLAGS */
#define MINUS 1
#define PLUS 2
#define ZERO 4
#define HASH 8
#define SPACE 16

struct flags
{
	char flag;
	int (*fn)(va_list, char[], int, int, int, int);
};

typedef struct flags flag_t;

/* MAIN FUNCTION */
int _printf(const char *format, ...);

/* CHARACTER FUNCTIONS */
int _putchar(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int _printstring(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int _printreverse(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int _nonprintable(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int _printpointer(va_list types, char buffer[],
	int flags, int width, int precision, int size);


/* NUMBER FUNCTIONS */
int _printint(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int _printunsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int _printoctal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int _printhexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int _printhexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);


/* HANDLERS */
int _writechar(char c, char buffer[],
	int flags, int width, int precision, int size);
int _writenumber(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int _writenum(int ind, char bff[], int flags, int width, int precision,
	int length, char padding, char excess);
int _writepointer(char buffer[], int ind, int length,
	int width, int flags, char padding, char excess, int padd_start);
int _writeunsgnd(int is_negative, int ind,
char buffer[], int flags, int width, int precision, int size);


 /* GETTERS */
int _getflags(const char *format, int *i);
int _getwidth(const char *format, int *i, va_list list);
int _getprecision(const char *format, int *i, va_list list);
int _getsize(const char *format, int *i);


/* HELPERS */
int _printhexa(va_list types, char map_to[],
  char buffer[], int flags, char flag_ch, int width, int precision, int size);
int _printpercent(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int _printrot13(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int _printbinary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int _handleprint(const char *fmt, int *i,
  va_list list, char buffer[], int flags, int width, int precision, int size);


/* UTILITIES */
int is_printable(char);
int _addhexa(char, char[], int);
int is_digit(char);
long int _convertsize_num(long int num, int size);
long int _convert_unsgnd(unsigned long int num, int size);

#endif
