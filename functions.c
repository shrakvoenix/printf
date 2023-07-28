#include "main.h"

/*************************This for print char****************/

/**
 * print_char - Print a character to a buffer to the format options.
 * @types: A va_list containing the argument to '%c' format specifier.
 * @buffer: The buffer to store the formatted output.
 * @flags: Flags to modify the behavior (e.g., left-align, zero-padding, etc.).
 * @width: The minimum width of the field.
 * @precision: The number of characters to be printed from the argument.
 * @size: The current size of the buffer.
 * Return: The number of characters written to the buffer.
 * Description: This function handles the '%c' format specifier in printf
 *      resulting string to the buffer according to the provided options.
 */
	int print_char(int flags, int width,
	int precision, va_list types, char buffer[], int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer,
	flags, width, precision, size));
}
/*************************string*************************/
/**
 * print_string - Print a string to a buffer according to the format options.
 * @types: A va_list contains corresponding to the '%s' format specifier.
 * @buffer: The buffer to store the formatted output.
 * @flags: Flags to modify the behavior (e.g., left-align, zero-padding, etc.).
 * @width: The minimum width of the field.
 * @precision: The maximum number of characters to be printed.
 * @size: The current size of the buffer.
 * Return: The number of characters written to the buffer.
 * Description: This function handles the '%s' format specifier in a
 *     implementation. It formats a string argument and writes the
 *     resulting to the buffer according to the provided options.
 */
	int print_string(va_list types, char buffer[],
	int flags, int precision, int size, int width)
{
	int length = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
	str = "(null)";
	if (precision >= 6)
	str = "      ";
	}

	while (str[length] != '\0')
	length++;

	if (precision >= 0 && precision < length)
	length = precision;

	if (width > length)
	{
	if (flags & F_MINUS)
	{
	write(1, &str[0], length);
	for (i = width - length; i > 0; i--)
	write(1, " ", 1);
	return (width);
	}
	else
	{
	for (i = width - length; i > 0; i--)
	write(1, " ", 1);
	write(1, &str[0], length);
	return (width);
	}
	}

	return (write(1, str, length));
}
/*************************percentage signs *************************/

/**
 * print_percent - Print a percent symbol to a buffer.
 * @types: A va_list the argument corresponding to the '%%' format specifier.
 * @buffer: The buffer to store the formatted output.
 * @flags: Flags to modify the behavior (e.g., left-align, zero-padding, etc.).
 * @width: The minimum width of the field.
 * @precision: The maximum number of characters to be printed.
 * @size: The current size of the buffer.
 * Return: The number of characters written to the buffer (always 1 for '%%').
 * Description: This function handles the '%%' format specifier in printf
 *          implementation. It prints a percent symbol to the buffer according
 *        to the provided options. There are no actual arguments for '%%'.
 */
	int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/*************************print int *************************/
/**
* print_int - Print int
* @types: Lista of arguments
* @buffer: Buffer array to handle print
* @flags:  Calculates active flags
* @width: get width.
* @precision: Precision specification
* @size: Size specifier
* Return: Number of chars printed
*/
	int print_int(int width, int precision, int size,
	va_list types, char buffer[],
	int flags)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
	buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
	num = (unsigned long int)((-1) * n);
	is_negative = 1;
	}

	while (num > 0)
	{
	buffer[i--] = (num % 10) + '0';
	num /= 10;
	}

	i++;

	return (write_number(is_negative, i, buffer, flags, width, precision, size));
}

/*************************binary*************************/
/**
* print_binary - Prints an unsigned number
* @types: Lista of arguments
* @buffer: Buffer array to handle print
* @flags:  Calculates active flags
* @width: get width.
* @precision: Precision specification
* @size: Size specifier
* Return: Numbers of char printed.
*/
	int print_binary(va_list types, char buffer[],
	int flags, int width, int size, int precision)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
	m /= 2;
	a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
	sum += a[i];
	if (sum || i == 31)
	{
	char z = '0' + a[i];

	write(1, &z, 1);
	count++;
	}
	}
	return (count);
}
