#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Cstom printf func.
 *
 * @format: For format string containing the specifiers.
 * Just like "%d", "%s", "%c", etc.
 * It can include escape sequences as "\n".
 *
 * Return: The number of characters printed (excluding the null byte
 *  to end output to strings).
 */
int _printf(const char *format...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size
	int buff_ind = 0;
	char buffer[BUFF_SIZE];
	va_list list;


	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
	if (format[i] != '%')
	{
	buffer[buff_ind++] = format[i];
	if (buff_ind == BUFF_SIZE)
	print_buffer(buffer, &buff_ind);
	printed_chars++;
	}
	else
	{
	print_buffer(buffer, &buff_ind);
	flags = get_flags(format, &i);
	width = get_width(format, &i, list);
	precision = get_precision(format, &i, list);
	size = get_size(format, &i);
	++i;
	printed = handle_print(format, &i, list, buffer,
	flags, width, precision, size);
	if (printed == -1)
	return (-1);
	printed_chars += printed;
	}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Print the contents of a buffer.
 *
 * @buffer: The buffer containing characters to print.
 * @buff_ind: A pointer to the index of the buffer
 *
 * Description: This function prints the contents of the buffer up to the
 *      current index (buff_ind). It prints 10 characters per line,
 *      hexadecimal.
 */

void print_buffer(int *buff_ind, char buffer[])
{
	if (*buff_ind > 0)
	write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
