#include <stdio.h>
#include "libft.h"

void test_memset();
void test_bzero();
void test_memcpy();
void test_memccpy();
void test_memmove();
void test_strcpy();
void test_strlen();

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
    test_memmove();
    printf("--------------------------------------------  \n\n");
    test_strcpy();
    printf("--------------------------------------------  \n\n");
    test_strlen();
    printf("--------------------------------------------  \n\n");

    return (0);
}

void test_strcpy()
{
    char str[50];
    printf("Test ft_strcpy  \n\n");

    strcpy(str, "This is string.h library function");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %s \n", strcpy(str, "ok"));
    strcpy(str, "This is string.h library function");
    printf("result :\t\t %s \n", ft_strcpy(str, "ok"));

    strcpy(str, "This is string.h library function");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %s \n", strcpy(str, ""));
    strcpy(str, "This is string.h library function");
    printf("result :\t\t %s \n", ft_strcpy(str, ""));

    strcpy(str, "This is string.h library function");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %s \n", strcpy(str, "This is string.h library function1111"));
    strcpy(str, "This is string.h library function");
    printf("result :\t\t %s \n", ft_strcpy(str, "This is string.h library function1111"));

}

void test_strlen()
{
    char str[34];
    printf("Test ft_strlen  \n\n");

    strcpy(str, "This is string.h library function");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %zu \n", strlen(str));
    strcpy(str, "This is string.h library function");
    printf("result :\t\t %zu \n", ft_strlen(str));

    strcpy(str, "");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %zu \n", strlen(str));
    strcpy(str, "");
    printf("result :\t\t %zu \n", ft_strlen(str));

    strcpy(str, "a");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %zu \n", strlen(str));
    strcpy(str, "a");
    printf("result :\t\t %zu \n", ft_strlen(str));
}

void test_memmove()
{
    char str[34];
    printf("Test ft_memmove  \n\n");

    strcpy(str, "This is string.h library function");
    printf("original :\t\t %s \n", str);
    memmove(str,"Test",7);
    printf("result attendu :\t %s \n", str);
    strcpy(str, "This is string.h library function");
    ft_memmove(str,"Test",7);
    printf("result :\t\t %s \n", str);

    strcpy(str, "This is string.h");
    printf("original :\t\t %s \n", str);
    memmove(str,"Test",7);
    printf("result attendu :\t %s \n", str);
    strcpy(str, "This is string.h");
    ft_memmove(str,"Test",7);
    printf("result :\t\t %s \n", str);

    strcpy(str, "This is string.h");
    printf("original :\t\t %s \n", str);
    memmove(str,"Test",5);
    printf("result attendu :\t %s \n", str);
    strcpy(str, "This is string.h");
    ft_memmove(str,"Test",5);
    printf("result :\t\t %s \n", str);

    strcpy(str, "This is string.h");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %s \n", memmove(str,"Test",5));
    strcpy(str, "This is string.h");
    printf("result :\t\t %s \n", ft_memmove(str,"Test",5));

    strcpy(str, "This is string.h");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %s \n", memmove(str,"Test",5));
    strcpy(str, "This is string.h");
    printf("result :\t\t %s \n", ft_memmove(str,"Test",5));


    strcpy(str, "This is string.h");
    printf("original :\t\t %s \n", str);
    memmove(str+2, str, 5);
    printf("result attendu :\t %s \n", str);
    strcpy(str, "This is string.h");
    ft_memmove(str+2, str, 5);
    printf("result :\t\t %s \n", str);

    strcpy(str, "This is string.h");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %s \n", memmove(str+2, str, 5));
    strcpy(str, "This is string.h");
    printf("result :\t\t %s \n", ft_memmove(str+2, str, 5));
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

    strcpy(str, "This is string.h");
    printf("original :\t\t %s \n", str);
    printf("Undefined behaviour !! \n");
    printf("result attendu :\t %s \n", memcpy(str + 2, str,20));
    strcpy(str, "This is string.h");
    printf("result :\t\t %s \n", ft_memcpy(str + 2, str,20));
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