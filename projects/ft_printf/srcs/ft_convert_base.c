#include "ft_printf.h"

size_t size_to_malloc(long long nb, size_t base_len)
{
    size_t size;
    long long nb_tmp;

    size = 0;
    nb_tmp = nb;
    while (nb_tmp != 0)
    {
        nb_tmp /= base_len;
        size++;
    }
    return (size);
}

char *ft_convert_base(char *decimal, char *base)
{
    char *output;
    long long result;
    size_t i;
    size_t base_len;
    size_t len;

    i = 0;
    result = 0;
    base_len = ft_strlen(base);
    while (decimal[i])
    {
        result = result * 10 + (decimal[i] - '0');
        i++;
    }
    len = size_to_malloc(result, base_len);
    output = malloc((len + 2) * sizeof(char));
    output[len--] = '\0';
    if (result == 0)
        output[0] = base[0];
    while (result != 0)
    {
        output[len] = base[result % base_len];
        result /= base_len;
        len--;
    }
    return (output);
}