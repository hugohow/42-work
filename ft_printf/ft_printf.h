#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

char *ft_convert_base(char *decimal, char *base);
char    *ft_itoa_unsigned(unsigned int nb);
size_t count_var(const char *format);
int is_valid_par(char c);
size_t count_par(const char *str);
unsigned int get_width(char *str);
int get_zero(char *str);
int get_plus(char *flag);
int get_minus(char *flag);
int get_space(char *flag);
int get_precision(char *flag);
int get_hash(char *flag);
char *offset_p(char *str, char *flag, int sign);
char *apply_precision_p(char *str, int precision);
size_t  ft_wcslen(const wchar_t *str);
char *offset(char *str, char *flag);
char *offset_d(char *str, char *flag, int sign, char conv_char);
void ft_wputstr(wchar_t const *str);
wchar_t *ft_wstrjoin(wchar_t const *str1, wchar_t const *str2);
wchar_t *ft_wstrsub(wchar_t const *str, unsigned int start, size_t len);
wchar_t *woffset(wchar_t *str, char *flag);