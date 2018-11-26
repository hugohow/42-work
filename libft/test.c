#include <stdio.h>
#include "libft.h"

void test_memset();
void test_bzero();
void test_memcpy();
void test_memccpy();

int main(int argc, char **argv)
{

    printf("--------------------------------------------  \n\n");
    test_memset();
    printf("--------------------------------------------  \n\n");
    test_bzero();
    printf("--------------------------------------------  \n\n");
    test_memcpy();
    printf("--------------------------------------------  \n\n");
    test_memccpy();
    printf("--------------------------------------------  \n\n");

    return (0);
}

void test_memccpy()
{
    char str[34];
    printf("Test ft_memccpy  \n\n");

    strcpy(str, "This is string.h library function");
    printf("original :\t\t %s \n", str);
    memccpy(str,"Test", 's',7);
    printf("result attendu :\t %s \n", str);
    strcpy(str, "This is string.h library function");
    ft_memccpy(str,"Test", 's',7);
    printf("result :\t\t %s \n", str);

    strcpy(str, "This is string.h");
    printf("original :\t\t %s \n", str);
    memccpy(str,"Test", 's',7);
    printf("result attendu :\t %s \n", str);
    strcpy(str, "This is string.h");
    ft_memccpy(str,"Test", 's',7);
    printf("result :\t\t %s \n", str);

    strcpy(str, "This is string.h");
    printf("original :\t\t %s \n", str);
    memccpy(str,"Test", 'l',5);
    printf("result attendu :\t %s \n", str);
    strcpy(str, "This is string.h");
    ft_memccpy(str,"Test", 'l',5);
    printf("result :\t\t %s \n", str);

    strcpy(str, "This is string.h");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %s \n", memccpy(str,"Test", 'l',5));
    strcpy(str, "This is string.h");
    printf("result :\t\t %s \n", ft_memccpy(str,"Test", 'l',5));

    strcpy(str, "This is string.h");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %s \n", memccpy(str,"Test", 's',5));
    strcpy(str, "This is string.h");
    printf("result :\t\t %s \n", ft_memccpy(str,"Test", 's',5));
}

void test_memcpy()
{
    char str[34];
    printf("Test ft_memcpy  \n\n");

    strcpy(str, "This is string.h library function");
    printf("original :\t\t %s \n", str);
    memcpy(str,"Test",7);
    printf("result attendu :\t %s \n", str);
    strcpy(str, "This is string.h library function");
    ft_memcpy(str,"Test",7);
    printf("result :\t\t %s \n", str);

    strcpy(str, "This is string.h");
    printf("original :\t\t %s \n", str);
    memcpy(str,"Test",7);
    printf("result attendu :\t %s \n", str);
    strcpy(str, "This is string.h");
    ft_memcpy(str,"Test",7);
    printf("result :\t\t %s \n", str);

    strcpy(str, "This is string.h");
    printf("original :\t\t %s \n", str);
    memcpy(str,"Test",2);
    printf("result attendu :\t %s \n", str);
    strcpy(str, "This is string.h");
    ft_memcpy(str,"Test",2);
    printf("result :\t\t %s \n", str);

    strcpy(str, "This is string.h");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %s \n", memcpy(str,"Test",10));
    strcpy(str, "This is string.h");
    printf("result :\t\t %s \n", ft_memcpy(str,"Test",10));
}

void test_memset()
{
    char str[34];
    printf("Test ft_memset  \n\n");

    strcpy(str, "This is string.h library function");
    printf("original :\t\t %s \n", str);
    memset(str,'$',7);
    printf("result attendu :\t %s \n", str);
    strcpy(str, "This is string.h library function");
    ft_memset(str,'$',7);
    printf("result :\t\t %s \n", str);

    strcpy(str, "This is string.h");
    printf("original :\t\t %s \n", str);
    memset(str,'$',7);
    printf("result attendu :\t %s \n", str);
    strcpy(str, "This is string.h");
    ft_memset(str,'$',7);
    printf("result :\t\t %s \n", str);

    strcpy(str, "This is string.h");
    printf("original :\t\t %s \n", str);
    memset(str,'$',30);
    printf("result attendu :\t %s \n", str);
    strcpy(str, "This is string.h");
    ft_memset(str,'$',30);
    printf("result :\t\t %s \n", str);

    strcpy(str, "This is string.h");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %s \n", memset(str,'$',30));
    strcpy(str, "This is string.h");
    printf("result :\t\t %s \n", ft_memset(str,'$',30));
}

void test_bzero()
{
    char str[34];
    printf("Test ft_bzero  \n\n");

    strcpy(str, "This is string.h library function");
    printf("original :\t\t %s \n", str);
    bzero(str ,7);
    printf("result attendu :\t %s \n", str);
    strcpy(str, "This is string.h library function");
    ft_bzero(str ,7);
    printf("result :\t\t %s \n", str);

    strcpy(str, "This is string.h");
    printf("original :\t\t %s \n", str);
    bzero(str ,7);
    printf("result attendu :\t %s \n", str);
    strcpy(str, "This is string.h");
    ft_bzero(str ,7);
    printf("result :\t\t %s \n", str);

    strcpy(str, "This is string.h");
    printf("original :\t\t %s \n", str);
    bzero(str ,30);
    printf("result attendu :\t %s \n", str);
    strcpy(str, "This is string.h");
    ft_bzero(str ,30);
    printf("result :\t\t %s \n", str);
}