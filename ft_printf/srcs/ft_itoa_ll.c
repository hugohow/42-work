#include <string.h>
#include <stdlib.h>

size_t  ft_nblen_ll(unsigned long long nb);

size_t  ft_nblen_ll(unsigned long long nb)
{
    size_t nblen;

    nblen = 0;
    if (nb == 0)
        return (1);
    while (1 == 1)
    {
        nb /= 10;
        nblen++;
        if (nb == 0)
            break;
    }
    return (nblen);
}



char *ft_itoa_ll(unsigned long long nb)
{
    char *output;
    size_t nb_len;
    unsigned long long n;

    n = nb;
    nb_len = ft_nblen_ll(n);
    output = (char *)malloc((nb_len + 1) * sizeof(char));
    if (output == NULL)
        return (NULL);
    output[0] = '0';
    output[nb_len] = '\0';
    while (n != 0)
    {
        output[--nb_len] = (n % 10) + '0';
        n /= 10;
    }
    return (output);
}

char    *ft_itoa_u(unsigned int nb)
{
    return (ft_itoa_ll((unsigned long long)nb));
}

char    *ft_itoa_uhh(unsigned char nb)
{
    return (ft_itoa_ll((unsigned long long)nb));
}

char    *ft_itoa_uh(unsigned short nb)
{
    return (ft_itoa_ll((unsigned long long)nb));
}

char    *ft_itoa_ul(unsigned long nb)
{
    return (ft_itoa_ll((unsigned long long)nb));
}

char    *ft_itoa_ull(unsigned long long nb)
{
    return (ft_itoa_ll((unsigned long long)nb));
}

char    *ft_itoa_uj(uintmax_t nb)
{
    return (ft_itoa_ll((unsigned long long)nb));
}

char    *ft_itoa_uz(size_t nb)
{
    return (ft_itoa_ll((unsigned long long)nb));
}

char    *ft_itoa_hh(signed char nb)
{
    return (ft_itoa_ll((unsigned long long)nb));
}

char    *ft_itoa_h(short nb)
{
    return (ft_itoa_ll((unsigned long long)nb));
}

char    *ft_itoa_l(long nb)
{
    return (ft_itoa_ll((unsigned long long)nb));
}

char    *ft_itoa_j(intmax_t nb)
{
    return (ft_itoa_ll((unsigned long long)nb));
}

char    *ft_itoa_z(size_t nb)
{
    return (ft_itoa_ll((unsigned long long)nb));
}