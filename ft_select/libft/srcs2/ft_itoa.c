#include <string.h>
#include <stdlib.h>

size_t  ft_nblen(long nb)
{
    size_t nblen;

    nblen = 0;
    if (nb == 0)
        return (1);
    if (nb < 0)
    {
        nb = -nb;
        nblen++;
    }
    while (nb != 0)
    {
        nb /= 10;
        nblen++;
    }
    return (nblen);
}

char    *ft_itoa(int nb)
{
    char *output;
    size_t nb_len;
    long n;

    n = nb;
    nb_len = ft_nblen(n);
    output = (char *)malloc((nb_len + 1) * sizeof(char));
    if (output == NULL)
        return (NULL);
    output[0] = '0';
    if (n < 0)
    {
        n = -n;
        output[0] = '-';
    }
    output[nb_len] = '\0';
    while (n != 0)
    {
        output[--nb_len] = (n % 10) + '0';
        n /= 10;
    }
    return (output);
}