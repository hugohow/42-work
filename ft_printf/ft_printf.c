#include "ft_printf.h"
// permet de rechercher un char et de regénérer


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




void define_arg(va_list *ap, char *flag)
{
    char conv_char;
    char *output;
    wchar_t *woutput;
    char *tmp_str;
    int tmp;
    unsigned int tmp_unsigned;
    unsigned char t[sizeof ap];
    size_t i;
    
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
        output = offset_d(output, flag, tmp, conv_char);
        ft_putstr(output);
    }
    else if (conv_char == 'i')
    {
        tmp = va_arg(*ap, int);
        output = ft_itoa(tmp < 0 ? -tmp : tmp);
        if (get_precision(flag) > 0)
            output = apply_precision(output, get_precision(flag));
        output = offset_d(output, flag, tmp, conv_char);
        ft_putstr(output);   
    }
    else if (conv_char == 'o')
    {
        tmp_unsigned = va_arg(*ap, unsigned int);
        output = ft_itoa_unsigned(tmp_unsigned);
        output = ft_convert_base(output, "01234567");
        if (get_precision(flag) > 0)
            output = apply_precision(output, get_precision(flag));
        output = offset_d(output, flag, 1, conv_char);
        ft_putstr(output);
    }
    else if (conv_char == 'x')
    {
        tmp_unsigned = va_arg(*ap, unsigned int);
        output = ft_itoa_unsigned(tmp_unsigned);
        output = ft_convert_base(output, "0123456789abcdef");
        if (get_precision(flag) > 0)
            output = apply_precision(output, get_precision(flag));
        output = offset_d(output, flag, 1, conv_char);
        ft_putstr(output);
    }
    else if (conv_char == 'X')
    {
        tmp_unsigned = va_arg(*ap, unsigned int);
        output = ft_itoa_unsigned(tmp_unsigned);
        output = ft_convert_base(output, "0123456789ABCDEF");
        if (get_precision(flag) > 0)
            output = apply_precision(output, get_precision(flag));
        output = offset_d(output, flag, 1, conv_char);
        ft_putstr(output);
    }
    else if (conv_char == 'u')
    {
        tmp_unsigned = va_arg(*ap, unsigned int);
        output = ft_itoa_unsigned(tmp_unsigned);
        if (get_precision(flag) > 0)
            output = apply_precision(output, get_precision(flag));
        output = offset_d(output, flag, 1, conv_char);
        ft_putstr(output);
    }
    else if (conv_char == 'p')
    {        
        va_arg(*ap, void *);
        ft_memcpy(t, &ap, sizeof ap);
        i = (sizeof ap) - 3;
        output = malloc(16 * sizeof(char));
        while (1)
        {
            tmp_str = ft_itoa_unsigned(t[i]);
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
        ft_putstr(output);
    }
    else if (conv_char == 'C')
    {
        woutput = (wchar_t *)malloc(2 * sizeof(wchar_t));
        woutput[0] = (wchar_t)va_arg(*ap, int);
        woutput[1] = L'\0';
        woutput = woffset(woutput, flag);
        ft_wputstr(woutput);
    }
    else if (conv_char == 'S')
    {
        woutput = va_arg(*ap, wchar_t*);
        if (get_precision(flag) > 0 && get_precision(flag) < ft_wcslen(woutput))
            woutput = ft_wstrsub(woutput, 0, get_precision(flag));
        woutput = woffset(woutput, flag);
        ft_wputstr(woutput);
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