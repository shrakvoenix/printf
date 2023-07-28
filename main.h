#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#ifndef MAIN_H
#define MAIN_H


#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* flags */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* size */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - This is structure to represent a format specifier.
 *
 * @type: The type of the format specifier (e.g., 'd', 's', 'c').
 * @handler: A function pointer to the handler function for this type.
 * Description: This struct is used to store info about format
 *     specifiers used in a custom printf implementation
 *     handler function that process the argument for that type.
 */
struct fmt
{
	char fmt;
	int (*fn)(char[],va_list, int, int, int, int);
};


/**
 * struct fmt - This structure to represent a format specifier.
 *
 * @type: The type of the format specifier ( 'd', 's', 'c').
 * @handler: This is function pointer to the handler function.
 *
 * Description: This struct is used to store information
 *       specifiers used in a custom printf implementation.
 *       handler function that process the argument.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
int width, int precision, va_list list, char buffer[], int flags, int size);

/******************Dose Functions ******************/

/* print chars and strings */
int print_char(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* to print numbers */
int print_int(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
int flags, int width, int precision, int size);

int print_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* print non the printable */
int print_non_printable(va_list types, char buffer[],
int flags, int width, int precision, int size);

/* print memory address */
int print_pointer(va_list types, char buffer[],
int flags, int width, int precision, int size);

/* handle other specifiers */
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

/*print string in reverse*/
int print_reverse(va_list types, char buffer[],
int flags, int width, int precision, int size);

/*to print a string in rot 13*/
int print_rot13string(va_list types, char buffer[],
int flags, int width, int precision, int size);

/* handles the width */
int handle_write_char(char c, char buffer[],
int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
int width, int flags, char padd, char extra_c, int padd_start);
int write_unsgnd(int is_negative, int ind, char buffer[],
int flags, int width, int precision, int size);

/******************utilis ******************/
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);
long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif /* MAIN_H */
