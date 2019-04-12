#include <stdio.h>
#include <locale.h>
#include <stdio.h>
#include <wchar.h>      /* wint_t */

int ft_printf(const char* format, ...);

int main(void)
{
    printf("%d", -2147483647);
    ft_printf("%d", -2147483647);
    ft_printf("\n\n");
    return 0;
}