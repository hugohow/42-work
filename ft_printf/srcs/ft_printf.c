#include "ft_printf.h"
// permet de rechercher un char et de regénérer


char *apply_precision(char *str, int precision)
{
    unsigned int i;
    unsigned int k;
    unsigned int str_len;
    char *output;

    str_len = ft_strlen(str);
    if (precision < 0)
        return (str);
    if (str_len >= (unsigned int)precision)
        return (str);
    i = 0;
    output = malloc((precision + 2) * sizeof(char));
    if (str[0] == '0' && str[1] == 'x')
    {
        output[0] = str[0];
        output[1] = str[1];
        i = 2;
    }
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

void ft_wputstr_len(wchar_t *str, size_t *len)
{
    ft_wputstr(str);
    *len += ft_wcslen(str);
}

void ft_putstr_len(char *str, size_t *len)
{
    ft_putstr(str);
    *len += ft_strlen(str);
}

char *ft_flag_replace(char *flag, char *to_replace)
{
    flag[ft_strlen(flag) - 1] = '\0';
    return (ft_strjoin(flag, to_replace));
}


void define_arg(va_list *ap, char *flag, size_t *len)
{
    char conv_char;
    int length;
    
    length = get_length(flag);
    conv_char = flag[ft_strlen(flag) - 1];
    // printf("\nflag : %s\n", flag);
    if (conv_char == 's')
    {
        char *output;
        output = va_arg(*ap, char*);
        if (get_precision(flag) > 0 && (unsigned int)get_precision(flag) < ft_strlen(output))
            output = ft_strsub(output, 0, get_precision(flag));
        if (get_precision(flag) == 0)
            output = "";
        output = offset(output, flag);
        ft_putstr_len(output, len);
    }
    else if (conv_char == 'c')
    {
        char *output;
        output = malloc(2 * sizeof(char));
        output[0] = (char)va_arg(*ap, int);
        output[1] = '\0';
        output = offset(output, flag);
        ft_putstr_len(output, len);
    }
    else if (conv_char == 'd' || conv_char == 'i')
    {
        char *output;
        if (length == 0)
        {
            int tmp;
            int sign;
            tmp = va_arg(*ap, int);
            output = ft_itoa_ll((unsigned long long)(tmp < 0 ? -tmp : tmp));
            output = apply_precision(output, get_precision(flag));
            sign = tmp < 0 ? -1 : 1;
            sign = tmp == 0 ? 0 : sign;
            output = offset_d(output, flag, sign, conv_char);
            ft_putstr_len(output, len);
        }
        else if (length == 1)
        {
            int tmp;
            int sign;
            tmp = va_arg(*ap, int);
            output = ft_itoa_ll((unsigned long long)(tmp < 0 ? -tmp : tmp));
            output = apply_precision(output, get_precision(flag));
            sign = tmp < 0 ? -1 : 1;
            sign = tmp == 0 ? 0 : sign;
            output = offset_d(output, flag, sign, conv_char);
            ft_putstr_len(output, len);
        }
        else if (length == 2)
        {
            int tmp;
            int sign;
            tmp = va_arg(*ap, int);
            output = ft_itoa_ll((unsigned long long)(tmp < 0 ? -tmp : tmp));
            output = apply_precision(output, get_precision(flag));
            sign = tmp < 0 ? -1 : 1;
            sign = tmp == 0 ? 0 : sign;
            output = offset_d(output, flag, sign, conv_char);
            ft_putstr_len(output, len);
        }
        else if (length == 3)
        {
            long tmp;
            int sign;
            tmp = va_arg(*ap, long);
            output = ft_itoa_ll((unsigned long long)(tmp < 0 ? -tmp : tmp));
            output = apply_precision(output, get_precision(flag));
            sign = tmp < 0 ? -1 : 1;
            sign = tmp == 0 ? 0 : sign;
            output = offset_d(output, flag, sign, conv_char);
            ft_putstr_len(output, len);
        }
        else if (length == 4)
        {
            long long tmp;
            int sign;
            tmp = va_arg(*ap, long long);
            output = ft_itoa_ll((unsigned long long)(tmp < 0 ? -tmp : tmp));
            output = apply_precision(output, get_precision(flag));
            sign = tmp < 0 ? -1 : 1;
            sign = tmp == 0 ? 0 : sign;
            output = offset_d(output, flag, sign, conv_char);
            ft_putstr_len(output, len);
        }
        else if (length == 5)
        {
            intmax_t tmp;
            int sign;
            tmp = va_arg(*ap, intmax_t);
            output = ft_itoa_ll((unsigned long long)(tmp < 0 ? -tmp : tmp));
            output = apply_precision(output, get_precision(flag));
            sign = tmp < 0 ? -1 : 1;
            sign = tmp == 0 ? 0 : sign;
            output = offset_d(output, flag, sign, conv_char);
            ft_putstr_len(output, len);
        }
        else if (length == 6)
        {
            size_t tmp;
            int sign;
            tmp = va_arg(*ap, size_t);
            output = ft_itoa_ll((unsigned long long)(tmp));
            output = apply_precision(output, get_precision(flag));
            sign = 1;
            sign = tmp == 0 ? 0 : sign;
            output = offset_d(output, flag, sign, conv_char);
            ft_putstr_len(output, len);
        }
    }
    else if (conv_char == 'o' || conv_char == 'x' || conv_char == 'X' || conv_char == 'u')
    {
        char *output;
        if (length == 0)
        {
            unsigned int tmp;
            int sign;
            tmp = va_arg(*ap, unsigned int);
            output = ft_itoa_ll((unsigned long long)(tmp));
            if (conv_char == 'o')
                output = ft_convert_base(output, "01234567");
            if (conv_char == 'x')
                output = ft_convert_base(output, "0123456789abcdef");
            if (conv_char == 'X')
                output = ft_convert_base(output, "0123456789ABCDEF");
            output = apply_precision(output, get_precision(flag));
            sign = 1;
            sign = tmp == 0 ? 0 : sign;
            output = offset_d(output, flag, sign, conv_char);
            ft_putstr_len(output, len);
        }
        else if (length == 1)
        {
            unsigned int tmp;
            int sign;
            tmp = va_arg(*ap, unsigned int);
            output = ft_itoa_ll((unsigned long long)(tmp));
            if (conv_char == 'o')
                output = ft_convert_base(output, "01234567");
            if (conv_char == 'x')
                output = ft_convert_base(output, "0123456789abcdef");
            if (conv_char == 'X')
                output = ft_convert_base(output, "0123456789ABCDEF");
            output = apply_precision(output, get_precision(flag));
            sign = 1;
            sign = tmp == 0 ? 0 : sign;
            output = offset_d(output, flag, sign, conv_char);
            ft_putstr_len(output, len);
        }
        else if (length == 2)
        {
            unsigned int tmp;
            int sign;
            tmp = va_arg(*ap, unsigned int);
            output = ft_itoa_ll((unsigned long long)(tmp));
            if (conv_char == 'o')
                output = ft_convert_base(output, "01234567");
            if (conv_char == 'x')
                output = ft_convert_base(output, "0123456789abcdef");
            if (conv_char == 'X')
                output = ft_convert_base(output, "0123456789ABCDEF");
            output = apply_precision(output, get_precision(flag));
            sign = 1;
            sign = tmp == 0 ? 0 : sign;
            output = offset_d(output, flag, sign, conv_char);
            ft_putstr_len(output, len);
        }
        else if (length == 3)
        {
            unsigned long tmp;
            int sign;
            tmp = va_arg(*ap, unsigned long);
            output = ft_itoa_ll((unsigned long long)(tmp));
            if (conv_char == 'o')
                output = ft_convert_base(output, "01234567");
            if (conv_char == 'x')
                output = ft_convert_base(output, "0123456789abcdef");
            if (conv_char == 'X')
                output = ft_convert_base(output, "0123456789ABCDEF");
            output = apply_precision(output, get_precision(flag));
            sign = 1;
            sign = tmp == 0 ? 0 : sign;
            output = offset_d(output, flag, sign, conv_char);
            ft_putstr_len(output, len);
        }
        else if (length == 4)
        {
            unsigned long long tmp;
            int sign;
            tmp = va_arg(*ap, unsigned long long);
            output = ft_itoa_ll((unsigned long long)(tmp));
            if (conv_char == 'o')
                output = ft_convert_base(output, "01234567");
            if (conv_char == 'x')
                output = ft_convert_base(output, "0123456789abcdef");
            if (conv_char == 'X')
                output = ft_convert_base(output, "0123456789ABCDEF");
            output = apply_precision(output, get_precision(flag));
            sign = 1;
            sign = tmp == 0 ? 0 : sign;
            output = offset_d(output, flag, sign, conv_char);
            ft_putstr_len(output, len);
        }
        else if (length == 5)
        {
            uintmax_t tmp;
            int sign;
            tmp = va_arg(*ap, uintmax_t);
            output = ft_itoa_ll((unsigned long long)(tmp));
            if (conv_char == 'o')
                output = ft_convert_base(output, "01234567");
            if (conv_char == 'x')
                output = ft_convert_base(output, "0123456789abcdef");
            if (conv_char == 'X')
                output = ft_convert_base(output, "0123456789ABCDEF");
            output = apply_precision(output, get_precision(flag));
            sign = 1;
            sign = tmp == 0 ? 0 : sign;
            output = offset_d(output, flag, sign, conv_char);
            ft_putstr_len(output, len);
        }
        else if (length == 6)
        {
            size_t tmp;
            int sign;
            tmp = va_arg(*ap, size_t);
            output = ft_itoa_ll((unsigned long long)(tmp));
            if (conv_char == 'o')
                output = ft_convert_base(output, "01234567");
            if (conv_char == 'x')
                output = ft_convert_base(output, "0123456789abcdef");
            if (conv_char == 'X')
                output = ft_convert_base(output, "0123456789ABCDEF");
            output = apply_precision(output, get_precision(flag));
            sign = 1;
            sign = tmp == 0 ? 0 : sign;
            output = offset_d(output, flag, sign, conv_char);
            ft_putstr_len(output, len);
        }
    }
    else if (conv_char == 'p')
    {     
        char *output;   
        unsigned char t[sizeof ap];
        char *tmp_str;
        size_t i;

        va_arg(*ap, void *);
        ft_memcpy(t, &ap, sizeof ap);
        i = (sizeof ap) - 3;
        output = malloc(16 * sizeof(char));
        while (1)
        {
            tmp_str = ft_itoa_u(t[i]);
            tmp_str = ft_convert_base(tmp_str, "0123456789abcdef");
            output = ft_strjoin(output, tmp_str);
            if (i == 0)
                break;
            i--;
        }
        if (get_precision(flag) > 0)
            output = apply_precision_p(output, get_precision(flag));
        else
            output = ft_strjoin("0x", output);
        output = offset_p(output, flag, 1);
        ft_putstr_len(output, len);
    }
    else if (conv_char == 'C')
    {
        wchar_t *woutput;
        woutput = (wchar_t *)malloc(2 * sizeof(wchar_t));
        woutput[0] = (wchar_t)va_arg(*ap, int);
        woutput[1] = L'\0';
        woutput = woffset(woutput, flag);
        ft_wputstr_len(woutput, len);
    }
    else if (conv_char == 'S')
    {
        wchar_t *woutput;
        woutput = va_arg(*ap, wchar_t*);
        if (get_precision(flag) > 0 && (unsigned int)get_precision(flag) < ft_wcslen(woutput))
            woutput = ft_wstrsub(woutput, 0, get_precision(flag));
        woutput = woffset(woutput, flag);
        ft_wputstr_len(woutput, len);
    }
    else if (conv_char == 'D')
    {
        flag = ft_flag_replace(flag, "ld");
        define_arg(ap, flag, len);
    }
    else if (conv_char == 'O')
    {
        flag = ft_flag_replace(flag, "lo");
        define_arg(ap, flag, len);
    }
    else if (conv_char == 'U')
    {
        flag = ft_flag_replace(flag, "lu");
        define_arg(ap, flag, len);
    }
    else
    {
    }

}

int ft_printf(const char* format, ...)
{
    va_list ap;
    size_t  n;
    size_t  i;
    size_t  j;
    size_t  format_len;
    size_t  *len;
    char    *flag;

    format_len = ft_strlen(format);
    flag = malloc((format_len + 2) * sizeof(char));
    n = count_var(format);
    va_start(ap, format);
    i = 0;
    j = 0;
    len = malloc(sizeof(size_t));
    *len = 0;
    // format = ft_strchr(format, '%');
    // printf("All string : %s\n\n--------------------------\n\n", format);
    while (format[i])
    {
        if (format[i+1] && format[i] == '%' && format[i+1] == '%')
        {
            ft_putchar('%');
            i++;
            *len += 2;
        }
        else if (format[i] == '%')
        {
            // printf("\n");
            bzero((void *)flag, format_len + 1);
            flag = ft_strncpy(flag, format + i, (int)count_par(format + i) + 1);
            // printf("\n-------------------------------\n");
            // printf("\nstrncpy : %s", flag);
            define_arg(&ap, flag, len);

            // printf("\narg : %s", arg);
            i += (int)count_par(format + i);
            // printf("\n\n");
        }
        else
        {
            ft_putchar(format[i]);
            *len += 1;
        }
        i++;
    }
    va_end(ap);
    return (*len);
}