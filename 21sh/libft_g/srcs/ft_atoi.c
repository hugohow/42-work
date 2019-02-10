#include <string.h>

int is_escapable(char c)
{
    if (c == '\t' || c == '\v'|| c == '\f' || c == '\r' || c == '\n' || c == ' ' || c == '+')
        return (1);
    return (0);
}

int is_digit(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

int is_valid(char c)
{
    if (c == '\t' || c == '\v'|| c == '\f' || c == '\r' || c == '\n' || c == ' ' || c == '+' || c == '-')
        return (1);
    if (is_digit(c) == 1)
        return (1);
    return (0);
}

int ft_atoi(const char *str)
{
    size_t i;
    int sign;
    long long result;

    i = 0;
    sign = 1;
    result = 0;
    while (str[i] && is_valid(str[i]) == 1)
    {
        if (str[i] == '-' || str[i] == '+')
        {
            if (str[i + 1] && is_digit(str[i + 1]) == 1)
                sign = str[i] == '-' ? -1 : 1;
            else
                break;
        }
        if (is_digit(str[i]) == 1)
        {
            while (str[i] && is_digit(str[i]) == 1)
            {
                if (result <= (9223372036854775807 - (str[i] - '0')) / 10)
                    result = result * 10 + (str[i] - '0');
                else
                    return (-1);
                i++;
            }
            return (int)(sign * result);
        }
        i++;
    }
    return (0);
}