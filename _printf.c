#include "main.h"

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

	while (*format)
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
				int num_digits = 0;
				int num_copy = num;
				if (num == 0)
				{
					write(1, "0", 1);
					chars_print++;
				}
				else if (num < 0)
				{
					write(1, "-", 1);
					chars_print++;
					num = -num;
					num_copy = num;
				}
				while (num_copy != 0)
				{
					num_copy /= 10;
					num_digits++;
				}
				while (num_digits > 0)
				{
					int divisor = 1;
					for (int i = 1; i < num_digits; i++)
						divisor *= 10;
					int digit = num / divisor;
					char digit_char = digit + '0';
					write(1, &digit_char, 1);
					chars_print++;
					num %= divisor;
					num_digits--;
				}
			}
		}
		format++;
	}

	va_end(list);
	return (chars_print);
}
