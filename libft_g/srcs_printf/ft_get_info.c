#include "ft_printf.h"

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
    if (c == 'h' || c == 'l' || c == 'j' || c == 'z' || c == 'L' || c == 't')
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
        if (str[i] == '%')
            break;
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
    if (flag[ft_strlen(flag) - 1] == '%')
        return (0);
    while (flag[i] && (ft_isdigit(flag[i]) == 0 || flag[i] == '0'))
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
    if (flag[ft_strlen(flag) - 1] == '%')
        return (0);
    while (flag[i] && ft_isdigit(flag[i]) == 0)
    {
        if (flag[i] == ' ')
            return (1);
        i++;
    }
    return (0);
}

int get_hash(char *flag)
{
    unsigned int i;

    i = 0;
    if (flag[ft_strlen(flag) - 1] == '%')
        return (0);
    while (flag[i] && (ft_isdigit(flag[i]) == 0 || flag[i] == '0'))
    {
        if (flag[i] == '#')
            return (1);
        i++;
    }
    return (0);
}

int get_precision(char *flag)
{
    unsigned int i;
    int precision;

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
        else if (flag[i] == '.')
        {
            return (0);
        }
        i++;
    }
    return (-1);
}

int is_valid_conversion(char c)
{
    // if (c == '\0')
    //     return (0);
    // sSpdDioOuUxXcC
    if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' || c == 'i'
        || c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x' || c == 'X'
        || c == 'c' || c == 'C')
        return (1);
    return (0);
}

int is_valid_length(char c)
{
    // if (c == '\0')
    //     return (0);
    // sSpdDioOuUxXcC
    if (c == 'h' || c == 'l' || c == 'j' || c == 'z' || c == 'L' || c == 't')
        return (1);
    return (0);
}

int get_length(char *flag)
{
    // invalid -> -1
    // no -> 0
    // hh -> 1
    // h -> 2
    // l -> 3
    // ll -> 4
    // j -> 5
    // z -> 6
    size_t i;

    i = 0;
    while (flag[i] && is_valid_conversion(flag[i]) == 0)
        i++;
    i--;
    if (i > 0)
    {
        while (i > 0 && is_valid_length(flag[i]) == 0)
        {
            i--;
        }
        if (flag[i] == 'j')
            return (5);
        if (flag[i] == 'z')
            return (6);
        if (flag[i] == 'h')
        {
            if (i > 1 && flag[i - 1] == 'h')
                return (1);
            return (2);
        }
        if (flag[i] == 'l')
        {
            if (i > 1 && flag[i - 1] == 'l')
                return (4);
            return (3);
        }
    }
    return (0);
}