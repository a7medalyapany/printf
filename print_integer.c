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

	
	char buffer[20];
	int idx = 0;
	do
	{
		buffer[idx++] = (num % 10) + '0';
		num /= 10;
	} while (num > 0);

	
	for (int i = idx - 1; i >= 0; i--)
	{
		chars_print += write(1, &buffer[i], 1);
	}

  return (chars_print);
}
