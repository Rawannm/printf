#include "main.h"

/**
 * _puts - prints a string with newline
 * @str_pnt: the string to print
 *
 * Return:( str_pnt-a)
 */
int _puts(char *str_pnt)
{
	char *a = str_pnt;/*declaration of variables*/

	while (*str_pnt)
		_putchar(*str_pnt++);
	return (str_pnt - a);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and error is set appropriately.
 */
int _putchar(int c)
{
	static int i;
	static char buf[OUTPUT_BUF_SIZE];

	if (c == BUF_FLUSH || i >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
