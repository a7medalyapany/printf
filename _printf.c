#include "main.h"

#include "main.h"

/**
 * print_integer - Prints a signed integer
 * @num: The integer to be printed
 * Return: Number of characters printed
 */
int print_integer(int num)
{
	int chars_print = 0;
	int is_negative = 0;

	if (num < 0)
	{
		is_negative = 1;
		num = -num;
		chars_print += write(1, "-", 1);
	}

	// Convert integer to string for printing
	char buffer[20]; // Assuming a maximum of 20 digits for the integer
	int idx = 0;
	do
	{
		buffer[idx++] = (num % 10) + '0';
		num /= 10;
	} while (num > 0);

	// Reverse the digits in the buffer
	for (int i = idx - 1; i >= 0; i--)
	{
		chars_print += write(1, &buffer[i], 1);
	}

	return (chars_print);
}


/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int chars_print = 0;
	va_list list;

	if (format == NULL)
		return (-1);

	va_start(list, format);

	while(*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			chars_print++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == '%')
			{
				write(1, format, 1);
				chars_print++;
			}
			else if (*format == 'c')
			{
				char c = va_arg(list, int);
				write(1, &c, 1);
				chars_print++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(list, char*);
				int str_len = 0;

				while (str[str_len] != '\0')
					str_len++;
				write(1, str, str_len);
				chars_print += str_len;
			}
			else if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(list, int);
				chars_print += print_integer(num);
			}
		}
		format++;
	}

	va_end(list);
	return (chars_print);
}
