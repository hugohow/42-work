#include <stdio.h>
#include <stdlib.h>

int ft_printf(const char* format, ...);

int main(int argc, char **argv)
{
    // ft_printf("coco et %-#-#--24x titi%#012o", 12, -874);
    // printf("coco et %-#-#--24x titi%#012o", 12, -874);
    // ft_printf("\n\n");

    // ft_printf("t%04.2o%#2oet %#-8.3o titi", 0, 0, 0);
    // printf("t%04.2o%#2oet %#-8.3o titi", 0, 0, 0);
    // ft_printf("\n\n");

    ft_printf("test%#.4o et %02o %0#14.0o!!", 012, 036, 12587499);
    printf("test%#.4o et %02o %0#14.0o!!", 012, 036, 12587499);
    ft_printf("\n\n");


    // ft_printf("\n%024hho et%#1.2o %0012.O", (unsigned char)12, 0, 123654789);
    // printf("\n%024hho et%#1.2o %0012.O", (unsigned char)12, 0, 123654789);
    // ft_printf("\n\n");
    // ft_printf("%test%#.4o et %02o %0#14.0o!!", 012, 036, 12587499);
    // printf("%test%#.4o et %02o %0#14.0o!!", 012, 036, 12587499);
    // ft_printf("\n\n");
    // ft_printf("%toto %###.0o%#.O et %#.1o !", 0, 0, 0);
    // printf("%toto %###.0o%#.O et %#.1o !", 0, 0, 0);
    // ft_printf("\n\n");
    // ft_printf("%x", 0);
    // printf("%x", 0);
    // ft_printf("\n\n");

    // ft_printf("%toto et %02u coco %-5lu mimi", 19, (unsigned long)-20);
    // printf("%toto et %02u coco %-5lu mimi", 19, (unsigned long)-20);
    // ft_printf("\n\n");
    return (0);
}
