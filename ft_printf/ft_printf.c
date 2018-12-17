#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"
// permet de rechercher un char et de regénérer
char *ft_convert_base(char *decimal, char *base);
char    *ft_itoa_unsigned(unsigned int nb);

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

unsigned int get_width(char *str)
{
    unsigned int width;
    unsigned int i;

    i = 0;
    width = 0;
    while (str[i])
    {
        if (str[i] == '.')
            break;
        if (ft_isdigit(str[i]) == 1 && str[i] != '0')
        {
            while (str[i] && ft_isdigit(str[i]) == 1)
            {
                width = width * 10 + (str[i] - '0');
                i++;
            }
            return (width);
        }
        i++;
    }
    return (width);
}

int get_zero(char *str)
{
    unsigned int i;

    i = 0;
    while (str[i])
    {
        if (ft_isdigit(str[i]))
        {
            if (str[i] == '0')
                return (1);
            break;
        }
        i++;        
    }
    return (0);
}

int get_plus(char *flag)
{
    unsigned int i;

    i = 0;
    while (flag[i] && ft_isdigit(flag[i]) == 0)
    {
        if (flag[i] == '+')
            return (1);
        i++;
    }
    return (0);
}

int get_minus(char *flag)
{
    unsigned int i;

    i = 0;
    while (flag[i] && ft_isdigit(flag[i]) == 0)
    {
        if (flag[i] == '-')
            return (1);
        i++;
    }
    return (0);
}

int get_space(char *flag)
{
    unsigned int i;

    i = 0;
    while (flag[i] && ft_isdigit(flag[i]) == 0)
    {
        if (flag[i] == ' ')
            return (1);
        i++;
    }
    return (0);
}

int get_precision(char *flag)
{
    unsigned int i;
    unsigned int precision;

    i = 0;
    precision = 0;
    while (flag[i])
    {
        if (flag[i] == '.' && flag[i+1] && ft_isdigit(flag[i+1]))
        {
            i++;
            while (flag[i] && ft_isdigit(flag[i]))
            {
                precision = precision * 10 + (flag[i] - '0');
                i++;
            }
            return (precision);
        }
        i++;
    }
    return (0);
}


char *offset_d(char *str, char *flag, int nb)
{
    char *to_add;
    unsigned int str_len;
    unsigned int i;
    unsigned int width;
    int has_offset_zero;

    str_len = ft_strlen(str);
    if (get_plus(flag) == 1 && nb >= 0)
        str_len++;
    if (nb < 0)
        str_len++;
    if (get_plus(flag) == 0 && get_space(flag) == 1 && nb >= 0)
        str_len++;
    width = get_width(flag);
    has_offset_zero = get_zero(flag);
    // printf("width : %d\n", width);
    // printf("str_len : %d\n", str_len);
    to_add = malloc((width + 2) * sizeof(char));
    i = 0;
    if (width > str_len)
    {
        while (i < width - str_len)
        {
            if (has_offset_zero == 1 && get_minus(flag) == 0 && get_precision(flag) == 0)
                to_add[i++] = '0';
            else
                to_add[i++] = ' ';
        }
    }
    to_add[i] = '\0';
    // printf("to_add : %s\n", to_add);

    // si l'espace doit être collé -> if (has_offset_zero == 1 && get_minus(flag) == 0)
    if (has_offset_zero == 1 && get_minus(flag) == 0 && get_precision(flag) == 0)
    {
        str = ft_strjoin(to_add, str);
        if (get_plus(flag) == 1 && nb >= 0)
            str = ft_strjoin("+", str);
        if (nb < 0)
            str = ft_strjoin("-", str);
        if (get_plus(flag) == 0 && get_space(flag) == 1 && nb >= 0)
            str = ft_strjoin(" ", str);
        return (str);
    }

    // les autres cas l'espace ne doit pas être collé, du coup on join le sign pouis le add
    if (get_plus(flag) == 1 && nb >= 0)
        str = ft_strjoin("+", str);
    if (nb < 0)
        str = ft_strjoin("-", str);
    if (get_plus(flag) == 0 && get_space(flag) == 1 && nb >= 0)
        str = ft_strjoin(" ", str);
    if (get_minus(flag) == 1)
        str = ft_strjoin(str, to_add);
    else
        str = ft_strjoin(to_add, str);
    return (str);
}

char *offset(char *str, char *flag)
{
    char *to_add;
    unsigned int str_len;
    unsigned int i;
    unsigned int width;

    str_len = ft_strlen(str);
    width = get_width(flag);
    if (width > str_len)
    {
        to_add = malloc((width + 1) * sizeof(char));
        i = 0;
        while (i < width - str_len)
        {
            to_add[i++] = ' ';
        }
        to_add[i] = '\0';
        if (get_minus(flag) == 1)
            return (ft_strjoin(str, to_add));
        else
            return (ft_strjoin(to_add, str));
    }

    return (str);
}

char *apply_precision(char *str, int precision)
{
    unsigned int i;
    unsigned int k;
    unsigned int str_len;
    char *output;

    str_len = ft_strlen(str);
    if (str_len >= precision)
        return (str);
    i = 0;
    output = malloc((precision + 2) * sizeof(char));
    while (i < precision - str_len)
    {
        output[i] = '0';
        i++;
    }
    k = 0;
    while (k < str_len)
    {
        output[i] = str[k];
        i++;
        k++;
    }
    output[i] = '\0';
    // printf("apply precision : %s\n", output);
    return (output);
}



void define_arg(va_list *ap, char *flag)
{
    char conv_char;
    char *output;
    int tmp;

    conv_char = flag[ft_strlen(flag) - 1];
    if (conv_char == 's')
    {
        output = va_arg(*ap, char*);
        if (get_precision(flag) > 0 && get_precision(flag) < ft_strlen(output))
            output = ft_strsub(output, 0, get_precision(flag));
        output = offset(output, flag);
        ft_putstr(output);
    }
    else if (conv_char == 'c')
    {
        output = malloc(2 * sizeof(char));
        output[0] = (char)va_arg(*ap, int);
        output[1] = '\0';
        output = offset(output, flag);
        ft_putstr(output);
    }
    else if (conv_char == 'd')
    {
        tmp = va_arg(*ap, int);
        output = ft_itoa(tmp < 0 ? -tmp : tmp);
        if (get_precision(flag) > 0)
            output = apply_precision(output, get_precision(flag));
        output = offset_d(output, flag, tmp);
        ft_putstr(output);
    }
    else if (conv_char == 'i')
    {
        tmp = va_arg(*ap, int);
        output = ft_itoa(tmp < 0 ? -tmp : tmp);
        if (get_precision(flag) > 0)
            output = apply_precision(output, get_precision(flag));
        output = offset_d(output, flag, tmp);
        ft_putstr(output);   
    }
    else if (conv_char == 'o')
    {
        output = ft_itoa_unsigned(va_arg(*ap, unsigned int));
        output = ft_convert_base(output, "01234567");
        if (get_precision(flag) > 0)
            output = apply_precision(output, get_precision(flag));
        output = offset_d(output, flag, tmp);
        ft_putstr(output);
    }
    else if (conv_char == 'x')
    {
        output = ft_itoa_unsigned(va_arg(*ap, unsigned int));
        output = ft_convert_base(output, "0123456789abcdef");
        if (get_precision(flag) > 0)
            output = apply_precision(output, get_precision(flag));
        output = offset_d(output, flag, tmp);
        ft_putstr(output);
    }
    else if (conv_char == 'X')
    {
        output = ft_itoa_unsigned(va_arg(*ap, unsigned int));
        output = ft_convert_base(output, "0123456789ABCDEF");
        if (get_precision(flag) > 0)
            output = apply_precision(output, get_precision(flag));
        output = offset_d(output, flag, tmp);
        ft_putstr(output);
    }
    else if (conv_char == 'u')
    {
        output = ft_itoa_unsigned(va_arg(*ap, unsigned int));
        if (get_precision(flag) > 0)
            output = apply_precision(output, get_precision(flag));
        output = offset_d(output, flag, tmp);
        ft_putstr(output);
    }
    else if (conv_char == 'C')
    {
        // C == lc : je dois utiliser wc ha r_t pour l'unicde et changer ft_puchar ...
        printf("arg : %C", va_arg(*ap, wchar_t));
    }
    else if (conv_char == 'S')
    {
        // même que pour C pour toute la string
        printf("arg : %S", va_arg(*ap, wchar_t*));
    }
    else if (conv_char == 'p')
    {
        printf("arg : %p", va_arg(*ap, void*));
    }
    else if (conv_char == 'D')
        printf("arg : %D", va_arg(*ap, int));
    else if (conv_char == 'O')
        printf("arg : %O", va_arg(*ap, unsigned int));
    else if (conv_char == 'U')
        printf("arg : %U", va_arg(*ap, unsigned int));
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
        if (format[i+1] && format[i] == '%' && format[i+1] == '%')
        {
            ft_putchar('%');
            i++;
        }
        else if (format[i] == '%')
        {
            // printf("\n");
            bzero((void *)flag, format_len + 1);
            flag = ft_strncpy(flag, format + i, (int)count_par(format + i) + 1);
            // printf("\n-------------------------------\n");
            // printf("\nstrncpy : %s", flag);
            define_arg(&ap, flag);

            // printf("\narg : %s", arg);
            i += (int)count_par(format + i);
            // printf("\n\n");
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