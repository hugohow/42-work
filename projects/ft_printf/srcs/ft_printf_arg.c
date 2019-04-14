/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:20:38 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/14 19:30:45 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


char *ft_flag_replace(char *str, char *to_replace)
{
    str[ft_strlen(str) - 1] = '\0';
    return (ft_strcat(str, to_replace));
}

void ft_print_arg(va_list *ap, char *str, size_t *len)
{
	t_flag *flag;
    
	flag = ft_create_flag(str);
	// ft_print_flag(flag);
    if (flag->conv == 's')
    {
        char *output;
        output = va_arg(*ap, char*);
        if (flag->precision > 0 && (unsigned int)flag->precision < ft_strlen(output))
            output = ft_strsub(output, 0, flag->precision);
        if (flag->precision == 0)
            output = "";
        if (output == NULL)
            output = "(null)";
        output = ft_apply_padding(output, flag);
        ft_putstr(output);
        *len += ft_strlen(output);
    }
    else if (flag->conv == '%')
    {
        char *output;
        output = "%";
        output = ft_apply_padding_d(output, flag, 1);
        ft_putstr(output);
        *len += ft_strlen(output);
    }
    else if (flag->conv == 'c')
    {
        char *output;
        output = malloc(2 * sizeof(char));
        output[0] = (char)va_arg(*ap, int);
        output[1] = '\0';
        if (output[0] == '\0' || output[0] == 0)
            *len += 1;
        output = ft_apply_padding(output, flag);
        ft_putstr(output);
        *len += ft_strlen(output);
    }
    else if (flag->conv == 'd' || flag->conv == 'i')
    {
        char *output;
        if (flag->length == 0)
        {
            int tmp;
            int sign;
            tmp = va_arg(*ap, int);
            output = ft_ulltoa((unsigned long long)(tmp < 0 ? -tmp : tmp));
            sign = tmp < 0 ? -1 : 1;
            sign = tmp == 0 ? 0 : sign;
            output = ft_apply_padding_d(output, flag, sign);
            output = ft_apply_precision(output, flag, sign);
            ft_putstr(output);
            *len += ft_strlen(output);
        }
        else if (flag->length == 1)
        {
            int tmp;
            int sign;
            tmp = va_arg(*ap, int);
            output = ft_ulltoa((unsigned long long)(tmp < 0 ? -tmp : tmp));
            sign = tmp < 0 ? -1 : 1;
            sign = tmp == 0 ? 0 : sign;
            output = ft_apply_padding_d(output, flag, sign);
            output = ft_apply_precision(output, flag, sign);
            ft_putstr(output);
            *len += ft_strlen(output);
        }
        else if (flag->length == 2)
        {
            int tmp;
            int sign;
            tmp = va_arg(*ap, int);
            output = ft_ulltoa((unsigned long long)(tmp < 0 ? -tmp : tmp));
            sign = tmp < 0 ? -1 : 1;
            sign = tmp == 0 ? 0 : sign;
            output = ft_apply_padding_d(output, flag, sign);
            output = ft_apply_precision(output, flag, sign);
            ft_putstr(output);
            *len += ft_strlen(output);
        }
        else if (flag->length == 3)
        {
            long tmp;
            int sign;
            tmp = va_arg(*ap, long);
            output = ft_ulltoa((unsigned long long)(tmp < 0 ? -tmp : tmp));
            sign = tmp < 0 ? -1 : 1;
            sign = tmp == 0 ? 0 : sign;
            output = ft_apply_padding_d(output, flag, sign);
            output = ft_apply_precision(output, flag, sign);
            ft_putstr(output);
            *len += ft_strlen(output);
        }
        else if (flag->length == 4)
        {
            long long tmp;
            int sign;
            tmp = va_arg(*ap, long long);
            output = ft_ulltoa((unsigned long long)(tmp < 0 ? -tmp : tmp));
            sign = tmp < 0 ? -1 : 1;
            sign = tmp == 0 ? 0 : sign;
            output = ft_apply_padding_d(output, flag, sign);
            output = ft_apply_precision(output, flag, sign);
            ft_putstr(output);
            *len += ft_strlen(output);
        }
        else if (flag->length == 5)
        {
            intmax_t tmp;
            int sign;
            tmp = va_arg(*ap, intmax_t);
            output = ft_ulltoa((unsigned long long)(tmp < 0 ? -tmp : tmp));
            sign = tmp < 0 ? -1 : 1;
            sign = tmp == 0 ? 0 : sign;
            output = ft_apply_padding_d(output, flag, sign);
            output = ft_apply_precision(output, flag, sign);
            ft_putstr(output);
            *len += ft_strlen(output);
        }
        else if (flag->length == 6)
        {
            size_t tmp;
            int sign;
            tmp = va_arg(*ap, size_t);
            output = ft_ulltoa((unsigned long long)(tmp));
            sign = 1;
            sign = tmp == 0 ? 0 : sign;
            output = ft_apply_padding_d(output, flag, sign);
            output = ft_apply_precision(output, flag, sign);
            ft_putstr(output);
            *len += ft_strlen(output);
        }
    }
    else if (flag->conv == 'o' || flag->conv == 'x' || flag->conv == 'X' || flag->conv == 'u')
    {
        char *output;
        if (flag->length == 0)
        {
            unsigned int tmp;
            int sign;
            tmp = va_arg(*ap, unsigned int);
            output = ft_ulltoa((unsigned long long)(tmp));
            if (flag->conv == 'o')
                output = ft_convert_base(output, "01234567");
            if (flag->conv == 'x')
                output = ft_convert_base(output, "0123456789abcdef");
            if (flag->conv == 'X')
                output = ft_convert_base(output, "0123456789ABCDEF");
            sign = 1;
            sign = tmp == 0 ? 0 : sign;
            output = ft_apply_padding_d(output, flag, sign);
            output = ft_apply_precision(output, flag, sign);
            ft_putstr(output);
            *len += ft_strlen(output);
        }
        else if (flag->length == 1)
        {
            unsigned int tmp;
            int sign;
            tmp = va_arg(*ap, unsigned int);
            output = ft_ulltoa((unsigned long long)(tmp));
            if (flag->conv == 'o')
                output = ft_convert_base(output, "01234567");
            if (flag->conv == 'x')
                output = ft_convert_base(output, "0123456789abcdef");
            if (flag->conv == 'X')
                output = ft_convert_base(output, "0123456789ABCDEF");
            sign = 1;
            sign = tmp == 0 ? 0 : sign;
            output = ft_apply_padding_d(output, flag, sign);
            output = ft_apply_precision(output, flag, sign);
            ft_putstr(output);
            *len += ft_strlen(output);
        }
        else if (flag->length == 2)
        {
            unsigned int tmp;
            int sign;
            tmp = va_arg(*ap, unsigned int);
            output = ft_ulltoa((unsigned long long)(tmp));
            if (flag->conv == 'o')
                output = ft_convert_base(output, "01234567");
            if (flag->conv == 'x')
                output = ft_convert_base(output, "0123456789abcdef");
            if (flag->conv == 'X')
                output = ft_convert_base(output, "0123456789ABCDEF");
            sign = 1;
            sign = tmp == 0 ? 0 : sign;
            output = ft_apply_padding_d(output, flag, sign);
            output = ft_apply_precision(output, flag, sign);
            ft_putstr(output);
            *len += ft_strlen(output);
        }
        else if (flag->length == 3)
        {
            unsigned long tmp;
            int sign;
            tmp = va_arg(*ap, unsigned long);
            output = ft_ulltoa((unsigned long long)(tmp));
            if (flag->conv == 'o')
                output = ft_convert_base(output, "01234567");
            if (flag->conv == 'x')
                output = ft_convert_base(output, "0123456789abcdef");
            if (flag->conv == 'X')
                output = ft_convert_base(output, "0123456789ABCDEF");
            sign = 1;
            sign = tmp == 0 ? 0 : sign;
            output = ft_apply_padding_d(output, flag, sign);
            output = ft_apply_precision(output, flag, sign);
            ft_putstr(output);
            *len += ft_strlen(output);
        }
        else if (flag->length == 4)
        {
            unsigned long long tmp;
            int sign;
            tmp = va_arg(*ap, unsigned long long);
            output = ft_ulltoa((unsigned long long)(tmp));
            if (flag->conv == 'o')
                output = ft_convert_base(output, "01234567");
            if (flag->conv == 'x')
                output = ft_convert_base(output, "0123456789abcdef");
            if (flag->conv == 'X')
                output = ft_convert_base(output, "0123456789ABCDEF");
            sign = 1;
            sign = tmp == 0 ? 0 : sign;
            output = ft_apply_padding_d(output, flag, sign);
            output = ft_apply_precision(output, flag, sign);
            ft_putstr(output);
            *len += ft_strlen(output);
        }
        else if (flag->length == 5)
        {
            uintmax_t tmp;
            int sign;
            tmp = va_arg(*ap, uintmax_t);
            output = ft_ulltoa((unsigned long long)(tmp));
            if (flag->conv == 'o')
                output = ft_convert_base(output, "01234567");
            if (flag->conv == 'x')
                output = ft_convert_base(output, "0123456789abcdef");
            if (flag->conv == 'X')
                output = ft_convert_base(output, "0123456789ABCDEF");
            sign = 1;
            sign = tmp == 0 ? 0 : sign;
            output = ft_apply_padding_d(output, flag, sign);
            output = ft_apply_precision(output, flag, sign);
            ft_putstr(output);
            *len += ft_strlen(output);
        }
        else if (flag->length == 6)
        {
            size_t tmp;
            int sign;
            tmp = va_arg(*ap, size_t);
            output = ft_ulltoa((unsigned long long)(tmp));
            if (flag->conv == 'o')
                output = ft_convert_base(output, "01234567");
            if (flag->conv == 'x')
                output = ft_convert_base(output, "0123456789abcdef");
            if (flag->conv == 'X')
                output = ft_convert_base(output, "0123456789ABCDEF");
            sign = 1;
            sign = tmp == 0 ? 0 : sign;
            output = ft_apply_padding_d(output, flag, sign);
            output = ft_apply_precision(output, flag, sign);
            ft_putstr(output);
            *len += ft_strlen(output);
        }
    }
    else if (flag->conv == 'p')
    {     
        char *output;   
        va_arg(*ap, void *);
        unsigned char t[(sizeof ap) + 1];
        // char *tmp_str;
        size_t i;
        ft_memcpy(t, &ap, (sizeof ap) + 1);
        i = (sizeof ap) - 1;
        output = malloc(16 * sizeof(char));
        while (1)
        {
            printf("%x", t[i]);
            // tmp_str = ft_itoa_u(t[i]);
            // tmp_str = ft_convert_base(tmp_str, "0123456789abcdef");
            // output = ft_strjoin(output, tmp_str);
            if (i == 0)
                break;
            i--;
        }
        // output = offset_p(output, str, 1);
        // if (flag->precision > 0)
        // if (flag->precision <= 0)
        //     output = ft_strjoin("0x", output);
        // ft_putstr(output);
        *len += ft_strlen(output);
    }
    else if (flag->conv == 'C')
    {
        wchar_t *woutput;
        woutput = (wchar_t *)malloc(2 * sizeof(wchar_t));
        woutput[0] = (wchar_t)va_arg(*ap, int);
        woutput[1] = L'\0';
        woutput = ft_apply_padding_w(woutput, flag);
		ft_wputstr(woutput);
    	*len += ft_wcslen(woutput);
    }
    else if (flag->conv == 'S')
    {
        wchar_t *woutput;
        woutput = va_arg(*ap, wchar_t*);
        if (flag->precision > 0 && (unsigned int)flag->precision < ft_wcslen(woutput))
            woutput = ft_wstrsub(woutput, 0, flag->precision);
        woutput = ft_apply_padding_w(woutput, flag);
		ft_wputstr(woutput);
    	*len += ft_wcslen(woutput);
    }
    else if (flag->conv == 'D')
    {
        str = ft_flag_replace(str, "ld");
        ft_print_arg(ap, str, len);
    }
    else if (flag->conv == 'O')
    {
        str = ft_flag_replace(str, "lo");
        ft_print_arg(ap, str, len);
    }
    else if (flag->conv == 'U')
    {
        str = ft_flag_replace(str, "lu");
        ft_print_arg(ap, str, len);
    }
    else
    {
    }
    free(flag);
    flag = NULL;
}