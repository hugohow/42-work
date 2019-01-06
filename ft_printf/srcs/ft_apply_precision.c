#include "ft_printf.h"

int count_zeros_possible_to_delete(char *str, char *flag)
{
    int count;
    int i;

    i = 0;
    count = 0;
    if (get_hash(flag) == 1)
    {
        while (str[i])
        {
            if (str[i] == '0')
            {
                i++;
                if (flag[ft_strlen(flag) - 1] == 'o')
                {
                    while (str[i] && str[i] == '0')
                    {
                        count++;
                        i++;
                    }
                    break;
                }
                else if (flag[ft_strlen(flag) - 1] == 'x')
                {
                    i++;
                    while (str[i] && str[i] == '0')
                    {
                        count++;
                        i++;
                    }
                    break;
                }
                else if (flag[ft_strlen(flag) - 1] == 'X')
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

int count_precision(char *str, char* flag)
{
    int count;
    int i;

    i = 0;
    count = 0;
    if (get_hash(flag) == 1)
    {
        while (str[i])
        {
            if (str[i] == '0')
            {
                i++;
                if (flag[ft_strlen(flag) - 1] == 'o')
                {
                    while (str[i] && str[i] != ' ')
                    {
                        count++;
                        i++;
                    }
                    break;
                }
                else if (flag[ft_strlen(flag) - 1] == 'x')
                {
                    i++;
                    while (str[i] && str[i] != ' ')
                    {
                        count++;
                        i++;
                    }
                    break;
                }
                else if (flag[ft_strlen(flag) - 1] == 'X')
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

char *delete_element(char *str, char *flag, int i)
{
    int j;


    if (get_minus(flag) == 1)
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

char *delete_one_zero(char *str, char *flag)
{
    // char *output;
    int i;

    i = 0;
    if (get_hash(flag) == 1)
    {
        while (str[i])
        {
            if (str[i] == '0')
            {
                i++;
                if (flag[ft_strlen(flag) - 1] == 'o')
                {
                    return (delete_element(str, flag, i));
                }
                else if (flag[ft_strlen(flag) - 1] == 'x')
                {
                    i++;
                    return (delete_element(str, flag, i));
                }
                else if (flag[ft_strlen(flag) - 1] == 'X')
                {
                    i++;
                    return (delete_element(str, flag, i));
                }
            }
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


char *add_element(char *str, char *flag, int i)
{
    if (get_minus(flag) == 1 && str[ft_strlen(str) - 1] == ' ')
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
    else if (get_minus(flag) == 0 && str[0] == ' ')
    {
        int j;
        j = 0;
        while (j < i)
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

char *add_one_zero(char *str, char *flag)
{
    // char *output;
    int i;

    i = 0;
    if (get_hash(flag) == 1)
    {
        while (str[i])
        {
            if (str[i] == '0')
            {
                i++;
                if (flag[ft_strlen(flag) - 1] == 'o')
                {
                    return (add_element(str, flag, i));
                }
                else if (flag[ft_strlen(flag) - 1] == 'x')
                {
                    i++;
                    return (add_element(str, flag, i));
                }
                else if (flag[ft_strlen(flag) - 1] == 'X')
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

char *delete_zeros(char *str, char* flag, int precision)
{

    // printf("\npour : %s, on peut supprimer : %d\n", str, count_zeros_possible_to_delete(str, flag));
    // printf("\npour : %s, la preicision est de  : %d\n", str, count_precision(str, flag));
    // printf("\npour : %s, la precision voulue est de  : %d\n", str, get_precision(flag));

    // plus de 0 à delete
    if (count_zeros_possible_to_delete(str, flag) == 0)
        return (str);
    // la precision voulue est bien
    if (count_precision(str, flag) == get_precision(flag))
        return (str);
    
    // il faut enlever du gras
    str = delete_one_zero(str, flag);
    return (delete_zeros(str, flag, precision));
}

char *add_zeros(char *str, char* flag, int precision)
{
    // printf("\npour : %s, la preicision est de  : %d\n", str, count_precision(str, flag));
    // printf("\npour : %s, la precision voulue est de  : %d\n", str, get_precision(flag));

    // la precision voulue est bien
    if (count_precision(str, flag) == get_precision(flag))
        return (str);
    
    // il faut ajouter du gras
    str = add_one_zero(str, flag);
    return (add_zeros(str, flag, precision));
}


char *apply_precision(char *str, char* flag)
{
    // unsigned int i;
    // unsigned int k;
    unsigned int str_len;
    // char *output;
    int precision;

    precision = get_precision(flag);
    str_len = ft_strlen(str);
    if (precision < 0)
        return (str);

    // si precision == 0

    // voir si l'element est 0 ou pas
    // si oui -> il faut 


    // si str_len == precision
    if (str_len == (unsigned int)precision)
        return (str);

    
    if (count_precision(str, flag) > get_precision(flag))
    {
        // alors on doit enlever du gras (du 0)
        return (delete_zeros(str, flag, precision));
    }

    
    if (count_precision(str, flag) < get_precision(flag))
    {
        // alors on doit rajouter du gras
        return (add_zeros(str, flag, precision));
        // return (str);
    }   

    return (str);
}