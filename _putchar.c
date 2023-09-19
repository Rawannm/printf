#include "main.h"

/**
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
{
	int n;
	char buf[OUTPUT_BUF_SIZE];

	if (p == BUF_FLUSH || n >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, n);
		n = 0;
	}
	if (p != BUF_FLUSH)
		buf[n++] = p;
	return (1);
}
