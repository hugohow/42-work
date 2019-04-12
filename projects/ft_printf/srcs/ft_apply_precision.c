#include "ft_printf.h"

int count_zeros_possible_to_delete(char *str, t_flag *flag, int sign)
{
    int count;
    int i;

    i = 0;
    count = 0;
    if (flag->hash == 1 && sign != 0)
    {
        while (str[i])
        {
            if (str[i] == '0')
            {
                i++;
                if (flag->conv == 'o')
                {
                    while (str[i] && str[i] == '0')
                    {
                        count++;
                        i++;
                    }
                    break;
                }
                else if (flag->conv == 'x')
                {
                    i++;
                    while (str[i] && str[i] == '0')
                    {
                        count++;
                        i++;
                    }
                    break;
                }
                else if (flag->conv == 'X')
                {
                    i++;
                    while (str[i] && str[i] == '0')
                    {
                        count++;
                        i++;
                    }
                    break;
                }
            }
            i++;
        }
        return (count);
    }
    else
    {
        while (str[i])
        {
            if (ft_isdigit(str[i]) || ft_isalpha(str[i]))
            {
                if (str[i] == '0')
                    count++;
                else
                    break;
            }
            i++;
        }
        return (count);
    }
    return (count);
}

int count_precision(char *str, t_flag *flag, int sign)
{
    int count;
    int i;

    i = 0;
    count = 0;
    if (flag->hash == 1 && sign != 0)
    {
        while (str[i])
        {
            if (str[i] == '0')
            {
                i++;
                if (flag->conv == 'o')
                {
                    count++;
                    while (str[i] && str[i] != ' ')
                    {
                        count++;
                        i++;
                    }
                    break;
                }
                else if (flag->conv == 'x')
                {
                    i++;
                    while (str[i] && str[i] != ' ')
                    {
                        count++;
                        i++;
                    }
                    break;
                }
                else if (flag->conv == 'X')
                {
                    i++;
                    while (str[i] && str[i] != ' ')
                    {
                        count++;
                        i++;
                    }
                    break;
                }
            }
            i++;
        }
        return (count);
    }
    else
    {
        while (str[i])
        {
            if (ft_isdigit(str[i]) || ft_isalpha(str[i]))
            {
                while (str[i] && (ft_isdigit(str[i]) || ft_isalpha(str[i])))
                {
                    count++;
                    i++;
                }
                if (str[i] == '\0')
                    break;
            }
            i++;
        }
        return (count);
    }
    return (count);
}

char *delete_element(char *str, t_flag *flag, int i)
{
    int j;

    if (flag->minus == 1)
    {
        // on décale vers la gauche
        j = i + 1;
        while (str[j])
        {
            str[j - 1] = str[j];
            j++;
        }
        str[j] = ' ';
    }
    else
    {
        j = i;
        while (j > 0)
        {
            str[j] = str[j - 1];
            j--;
        }
        str[0] = ' ';
        // on décale vers la droite
    }
    return (str);
}

char *delete_one_zero(char *str, t_flag *flag, int sign)
{
    // char *output;
    int i;

    i = 0;
    if (flag->hash == 1 && sign != 0)
    {
        while (str[i])
        {
            if (str[i] == '0')
            {
                i++;
                if (flag->conv == 'o')
                {
                    return (delete_element(str, flag, i));
                }
                else if (flag->conv == 'x')
                {
                    i++;
                    return (delete_element(str, flag, i));
                }
                else if (flag->conv == 'X')
                {
                    i++;
                    return (delete_element(str, flag, i));
                }
            }
            i++;
        }
    }
    else
    {
        while (str[i])
        {
            if (ft_isdigit(str[i]) || ft_isalpha(str[i]))
            {
                return (delete_element(str, flag, i));
            }
            i++;
        }
        // tu recherches le premier 0

    }
    return (str);
}


char *add_element(char *str, t_flag *flag, int i)
{
    if (flag->minus == 1 && flag->conv == ' ')
    {
        int j;
        j = ft_strlen(str) - 1;
        while (j > i)
        {
            str[j] = str[j - 1];
            j--;
        }
        str[i] = '0';
        return (str);
    }
    else if (flag->minus == 0 && str[0] == ' ')
    {
        int j;
        j = 0;
        while (j < i - 1)
        {
            str[j] = str[j + 1];
            j++;
        }
        str[j] = '0';
        return (str); 
    }
    else
    {
        char *tmp;
        int j;
        j = 0;
        tmp = malloc((i + 2) * sizeof(char));
        while (j < i)
        {
            tmp[j] = str[j];
            j++;
        }
        tmp[j] = '0';
        j++;
        tmp[j] = '\0';
        return (ft_strjoin(tmp, str + i));
    }
}

char *add_one_zero(char *str, t_flag *flag, int sign)
{
    // char *output;
    int i;

    i = 0;
    if (flag->hash == 1 && sign != 0)
    {
        while (str[i])
        {
            if (str[i] == '0')
            {
                i++;
                if (flag->conv == 'o')
                {
                    return (add_element(str, flag, i));
                }
                else if (flag->conv == 'x')
                {
                    i++;
                    return (add_element(str, flag, i));
                }
                else if (flag->conv == 'X')
                {
                    i++;
                    return (add_element(str, flag, i));
                }
            }
            i++;
        }
    }
    else
    {
        while (str[i])
        {
            if (ft_isdigit(str[i]) || ft_isalpha(str[i]))
            {
                return (add_element(str, flag, i));
            }
            i++;
        }
        // tu recherches le premier 0

    }
    return (str);
}

char *delete_zeros(char *str, t_flag *flag, int sign)
{

    // printf("\npour : %s, on peut supprimer : %d\n", str, count_zeros_possible_to_delete(str, flag, sign));
    // printf("\npour : %s, la preicision est de  : %d\n", str, count_precision(str, flag, sign));
    // printf("\npour : %s, la precision voulue est de  : %d\n", str, flag->precision);

    // plus de 0 à delete
    if (count_zeros_possible_to_delete(str, flag, sign) == 0)
        return (str);
    // la precision voulue est bien
    if (count_precision(str, flag, sign) == flag->precision)
        return (str);
    
    // il faut enlever du gras
    
    str = delete_one_zero(str, flag, sign);
    return (delete_zeros(str, flag, sign));
}

char *add_zeros(char *str, t_flag *flag, int sign)
{
    // printf("\npour : %s, la preicision est de  : %d\n", str, count_precision(str, flag, sign));
    // printf("\npour : %s, la precision voulue est de  : %d\n", str, flag->precision);

    // la precision voulue est bien
    if (count_precision(str, flag, sign) == flag->precision)
        return (str);
    
    // il faut ajouter du gras
    str = add_one_zero(str, flag, sign);
    return (add_zeros(str, flag, sign));
}


char *apply_precision(char *str, t_flag *flag, int sign)
{
    unsigned int str_len;
    str_len = ft_strlen(str);


    if (sign == 0)
    {
        if (flag->width == 0 && flag->precision == 0)
        {
            // very special case
            if (flag->conv == 'o')
                return ("0");
            if (flag->plus)
                return ("+");
            if (flag->space)
                return (" ");
            return ("");
        }
        // on enleve un 0 (et il ne doit y avoir qu'un seul)
    }
    if (flag->precision < 0)
        return (str);

    // si flag->precision == 0

    // voir si l'element est 0 ou pas
    // si oui -> il faut 


    // si str_len == flag->precision
    if (str_len == (unsigned int)flag->precision)
        return (str);

    
    if (count_precision(str, flag, sign) > flag->precision)
    {
        // alors on doit enlever du gras (du 0)
        return (delete_zeros(str, flag, sign));
    }

    
    if (count_precision(str, flag, sign) < flag->precision)
    {
        // alors on doit rajouter du gras
        return (add_zeros(str, flag, sign));
        // return (str);
    }   

    return (str);
}