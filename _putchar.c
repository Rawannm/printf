#include "main.h"

/**
<<<<<<< HEAD
* _puts - to printf
* @string: the string
*
* Return: void
*/
int _puts(char *string)
{
	char *i = string;

	while (*string)
		_putchar(*string++);
	return (string - i);
}

/**
* _putchar - writes the char
* @p: the char
*
* Return: 1 or 0
*/
int _putchar(int p)
=======
 * _puts - prints a string with newline
 * @str: the string to print
 *
 * Return:( str-a)
 */
int _puts(char *str)
>>>>>>> 22178e8ff44aa6915c9fde5bc910302133399763
{
	char *a = str;/*declaration of variables*/

	while (*str)
		_putchar(*str++);
	return (str - a);
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
