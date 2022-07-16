#include "main.h"
/**
 * _strlen - Funnction to find the length of a string
 * @s: pointer to string
 * Return: length
 */
int _strlen(char *s)
{
	int length = 0;

	while (s[length])
		length++;
	return (length);
}

/**
 * rev_str - Fuction to reverse string
 * @arg: argument count
 * Return: rev
 */

int rev_str(va_list arg)
{
	int len;
	char *str;

	str = va_arg(arg, char *);
	len = _strlen(str);
	recursion_rev(str);

	return (len);
}

/**
 * recursion_rev - function to print string in reverse
 * @str: string to be reversed
 * Return: 0
 */

int recursion_rev(char *str)
{
	int i = 0;

	if (*str != '\0')
	{
		recursion_rev(str + 1);
		_putchar(str[i++]);
	}
	return (0);
}