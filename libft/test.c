#include <stdio.h>
#include "libft.h"

void test_memset()
{
    char str[34];
    printf("Test ft_memset.c  \n\n");
    strcpy(str, "This is string.h library function");
    printf("original : %s \n", str);
    //original
    memset(str,'$',7);
    //expected result
    printf("result attendu : %s \n", str);
    strcpy(str, "This is string.h library function");
    ft_memset(str,'$',7);
    //result
    printf("result : %s \n", str);

    strcpy(str, "This is string.h");
    printf("original : %s \n", str);
    //original
    memset(str,'$',7);
    //expected result
    printf("result attendu : %s \n", str);
    strcpy(str, "This is string.h");
    ft_memset(str,'$',7);
    //result
    printf("result : %s \n", str);
    strcpy(str, "This is string.h");
    printf("original : %s \n", str);
    //original
    memset(str,'$',30);
    //expected result
    printf("result attendu : %s \n", str);
    strcpy(str, "This is string.h");
    ft_memset(str,'$',30);
    //result
    printf("result : %s \n", str);

}

int main(int argc, char **argv)
{

    printf("--------------------------------------------  \n\n");
    test_memset();
    printf("--------------------------------------------  \n\n");

    return (0);
}