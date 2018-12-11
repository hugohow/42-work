#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"
// permet de rechercher un char et de regénérer


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

int is_valid_par(char c)
{
    if (c == ' ' || c == '#' || c == '0' || c == '-' || c == '+' || c == '*' || c == '$' || c == '.')
        return (1);
    if (ft_isdigit(c) == 1)
        return (1);
    if (c == 'h' || c == 'l' || c == 'j' || c == 'z')
        return (1);
    return (0);
}

size_t count_par(const char *str)
{
    size_t  i;
    i = 1;
    // à voir après pour les cas moins basiques type ll, ...
    while (str[i] && is_valid_par(str[i]) == 1)
    {
        i++;
    }
    return (i);
}
void define_arg(va_list *ap, char *flag)
{
    char conv_char;

    // sS pdDioOuUxXcC
    // S ça n'existe pas ...
    conv_char = flag[ft_strlen(flag) - 1];
    printf("\nflag : %c\n", conv_char);
    if (conv_char == 's')
        printf("arg : %s", va_arg(*ap, char*));
    // else if (conv_char == 'S')
    //     printf("arg : %S", va_arg(*ap, char*));
    else if (conv_char == 'p')
        printf("arg : %p", va_arg(*ap, void*));
    else if (conv_char == 'd')
        printf("arg : %d", va_arg(*ap, int));
    else if (conv_char == 'D')
        printf("arg : %D", va_arg(*ap, int));
    else if (conv_char == 'i')
        printf("arg : %i", va_arg(*ap, int));
    else if (conv_char == 'o')
        printf("arg : %o", va_arg(*ap, unsigned int));
    else if (conv_char == 'O')
        printf("arg : %O", va_arg(*ap, unsigned int));
    else if (conv_char == 'u')
        printf("arg : %u", va_arg(*ap, unsigned int));
    else if (conv_char == 'U')
        printf("arg : %U", va_arg(*ap, unsigned int));
    else if (conv_char == 'x')
        printf("arg : %x", va_arg(*ap, unsigned int));
    else if (conv_char == 'X')
        printf("arg : %X", va_arg(*ap, unsigned int));
    else if (conv_char == 'c')
        printf("arg : %c", va_arg(*ap, unsigned int));
    else if (conv_char == 'C')
        printf("arg : %C", va_arg(*ap, unsigned int));
    else
    {
        
    }
    // arg = va_arg(ap, char*);
}

int ft_printf(const char* format, ...)
{
    va_list ap;
    size_t  n;
    size_t  i;
    size_t  j;
    size_t  format_len;
    char    *flag;

    format_len = ft_strlen(format);
    flag = malloc((format_len + 1) * sizeof(char));
    n = count_var(format);
    va_start(ap, format);
    i = 0;
    j = 0;
    // format = ft_strchr(format, '%');
    printf("All string : %s\n\n--------------------------\n\n", format);
    while (format[i])
    {
        if (format[i] == '%')
        {
            printf("\n");
            bzero((void *)flag, format_len + 1);
            flag = ft_strncpy(flag, format + i, (int)count_par(format + i) + 1);
            printf("\n-------------------------------\n");
            printf("\nstrncpy : %s", flag);
            define_arg(&ap, flag);

            // printf("\narg : %s", arg);
            i += (int)count_par(format + i);
            printf("\n\n");
        }
        else
        {
            ft_putchar(format[i]);
        }
        i++;
    }
    va_end(ap);
    return (0);
}