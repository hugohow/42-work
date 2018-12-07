#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
char *ft_strchr(const char *s, int c);

size_t count_var(const char *format)
{
    size_t count;
    size_t i;

    count = 0;
    i = 0;
    while (format[i])
    {
        if (format[i] == '%')
            count++;
        i++;
    }
    return (count);
}

int ft_printf(const char* format, ...)
{
    va_list ap;
    size_t  n;
    size_t  i;
    char    *str;

    n = count_var(format);
    va_start(ap, format);
    i = 0;
    format = ft_strchr(format, '%');
    while (i < n)
    {
        str = va_arg(ap, char*);
        printf("format : %s\n", format);
        printf("params : %s\n", str);
        format = ft_strchr(format + 1, '%');
        i++;
    }
    va_end(ap);
    return (0);
}