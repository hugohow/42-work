#ifndef PRINTF_H
# define PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

typedef struct	s_flag
{
	int length;
	char conv;
	int precision;
	unsigned int width;
	int zero;
	int plus;
	int minus;
	int space;
	int hash;
}				t_flag;

char *ft_convert_base(char *decimal, char *base);
// char    *ft_itoa_u(unsigned int nb);
// char    *ft_itoa_uhh(signed char nb);
// char    *ft_itoa_uh(short nb);
// char    *ft_itoa_ul(long nb);
// char    *ft_itoa_ull(long nb);
// char    *ft_itoa_uj(intmax_t nb);
// char    *ft_itoa_uz(size_t nb);

// char    *ft_itoa_hh(signed char nb);
// char    *ft_itoa_h(short nb);
// char    *ft_itoa_l(long nb);
char    *ft_itoa_ll(long long nb);
// char    *ft_itoa_j(intmax_t nb);
// char    *ft_itoa_z(size_t nb);

size_t ft_count_variable(const char *format);
size_t ft_flaglen(const char *str);
char *ft_apply_padding(char *str, t_flag *flag);
char *ft_apply_padding_p(char *str, t_flag *flag, int sign);

char *ft_apply_precision(char *str, t_flag *flag, int sign);
char *ft_apply_precision_p(char *str, int precision);
char *ft_apply_padding_d(char *str, t_flag *flag, int sign);
wchar_t *ft_apply_padding_w(wchar_t *str, t_flag *flag);

size_t  ft_wcslen(const wchar_t *str);

void ft_wputstr(wchar_t const *str);
wchar_t *ft_wstrjoin(wchar_t const *str1, wchar_t const *str2);
wchar_t *ft_wstrsub(wchar_t const *str, unsigned int start, size_t len);
int     get_length(char *flag);
void ft_print_arg(va_list *ap, char *flag, size_t *len);
t_flag *ft_create_flag(char *str);

int ft_flag_get_space(char *flag);
int ft_flag_get_hash(char *flag);
int ft_flag_get_length(char *flag);
int ft_flag_get_minus(char *flag);
int ft_flag_get_plus(char *flag);
int ft_flag_get_precision(char *flag);
int ft_flag_get_width(char *flag);
int ft_flag_get_zero(char *flag);
void ft_print_flag(t_flag *flag);
int ft_printf(const char* format, ...);
int	ft_count_current_precision(char *str, t_flag *flag, int sign);

int ft_count_zeros_possible_to_delete(char *str, t_flag *flag, int sign);
char *ft_add_element(char *str, t_flag *flag, int i);
char *ft_add_zeros(char *str, t_flag *flag, int sign);
int	ft_count_current_precision(char *str, t_flag *flag, int sign);
char *ft_delete_element(char *str, t_flag *flag, int i);
char *ft_delete_zeros(char *str, t_flag *flag, int sign);
#endif