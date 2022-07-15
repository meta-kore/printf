#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdarg.h>

int _putchar(char c);
int _printf(char *,...);
int _printf(char* format,...);
int loop_format(va_list arg, const char *string)
int call_function_manager(char aux, va_list arg);
int check_percent(int *flag, char aux);
int function_manager(char c, va_list arg);
int _switch(char c, va_list arg)

#endif
