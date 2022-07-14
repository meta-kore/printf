#include <stdio.h>
#include <stdarg.h>	


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