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

int get_hash(char *flag)
{
    unsigned int i;

    i = 0;
    while (flag[i] && ft_isdigit(flag[i]) == 0)
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