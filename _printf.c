#include "main.h"
<<<<<<< HEAD
	

int _printf(char *,...); 			
char* convert(unsigned int, int); 


int _printf(char* format,...)
{
	char *traverse;
	unsigned int i;
	char *s;
	int stringCount = 0;
	
	va_list arg;
	va_start(arg, format);
	
	for(traverse = format; *traverse != '\0'; traverse++)
	{
		while( *traverse != '%' && *traverse != '\0')
		{
			putchar(*traverse);
			traverse++;
			stringCount++;
		}
		
		if(*traverse == '\0'){
		    break;
		}
		
		traverse++;
		
		switch(*traverse)
		{
			case 'c' : i = va_arg(arg,int);	
						putchar(i);
						stringCount++;
						break;
						
			case 'd':
            case 'i': i = va_arg(arg,int); 	
						if(i < 0)
						{
							i = -i;
							putchar('-');
						}
						puts(convert(i,10));
						stringCount++;
						break;
						
			case 's': s = va_arg(arg,char *); 	
						puts(s);
						stringCount++;
						break;
						
		}	
	}
	
	va_end(arg);
	
	return (stringCount);
=======
#include <stdarg.h>
#include <stdlib.h>
/**
 * _printf - entry point
 * @format: arg
 * Return: len
 */

int _printf(const char *format, ...)
{
	va_list arg;
	int i, j, flag, len = 0;

	print_t print[] = {
		{"c", print_char}, {"s", print_string}, {"d", print_int}, {"i", print_int},
		{"R", print_rot13}, {"b", dec_binary}, {"o", print_octal}, {"x", print_hex},
		{"X", print_Upper_hex}, {"u", print_u}, {"r", rev_str}, {NULL, NULL}
	};
	va_start(arg, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '%')
		{
			j = 0, flag = 0;
			while (print[j].symbol != NULL)
			{
				if (format[i + 1] == *print[j].symbol)
					len = len + print[j].f(arg), i++, flag = 1;
				j++;
			}
			if (flag == 0)
				_putchar(format[i]), len += 1;
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			_putchar('%');
			len += 1;
			i++;
		}
		else
			_putchar(format[i]), len += 1;
		i++;
	}
	va_end(arg);
	return (len);
>>>>>>> 84ec6676c5ef2f0082bea4eec4b676fec144431e
}
char *convert(unsigned int num, int base)
{
	static char Representation[]= "0123456789ABCDEF";
	static char buffer[50];
	char *ptr;
	
	ptr = &buffer[49];
	*ptr = '\0';
	
	do
	{
		*--ptr = Representation[num%base];
		num /= base;
	}while(num != 0);
	
	return(ptr);
}