#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "libft.h"
#include <unistd.h>

void test_memalloc();
void test_memdel();
void test_strnew();
void test_strdel();
void test_strclr();
void test_striter();
void test_striteri();
void test_strmap();
void test_strmapi();
void test_strequ();
void test_strnequ();
void test_strsub();
void test_strjoin();
void test_strtrim();
void test_strsplit();
void test_itoa();
void test_putchar();
void test_putstr();
void test_putendl();
void test_putnbr();
void test_putchar_fd();
void test_putstr_fd();
void test_putendl_fd();
void test_putnbr_fd();

int main(int argc, char **argv)
{

    printf("--------------------------------------------  \n\n");
    test_memalloc();
    printf("--------------------------------------------  \n\n");
    test_memdel();
    printf("--------------------------------------------  \n\n");
    test_strnew();
    printf("--------------------------------------------  \n\n");
    test_strdel();
    printf("--------------------------------------------  \n\n");
    test_strclr();
    printf("--------------------------------------------  \n\n");
    test_striter();
    printf("--------------------------------------------  \n\n");
    test_striteri();
    printf("--------------------------------------------  \n\n");
    test_strmap();
    printf("--------------------------------------------  \n\n");
    test_strmapi();
    printf("--------------------------------------------  \n\n");
    test_strequ();
    printf("--------------------------------------------  \n\n");
    test_strnequ();
    printf("--------------------------------------------  \n\n");
    test_strsub();
    printf("--------------------------------------------  \n\n");
    test_strjoin();
    printf("--------------------------------------------  \n\n");
    test_strtrim();
    printf("--------------------------------------------  \n\n");
    test_strsplit();
    printf("--------------------------------------------  \n\n");
    test_itoa();
    printf("--------------------------------------------  \n\n");
    test_putchar();
    printf("--------------------------------------------  \n\n");
    test_putstr();
    printf("--------------------------------------------  \n\n");
    test_putendl();
    printf("--------------------------------------------  \n\n");
    test_putnbr();
    printf("--------------------------------------------  \n\n");
    test_putchar_fd();
    printf("--------------------------------------------  \n\n");
    test_putstr_fd();
    printf("--------------------------------------------  \n\n");
    test_putendl_fd();
    printf("--------------------------------------------  \n\n");
    test_putnbr_fd();
    return (0);
}

void test_putnbr_fd()
{
    printf("Test ft_putnbr_fd  \n\n");
    printf("result :\t \n14\n");
    ft_putnbr_fd(14, 1);
    printf("\nresult :\t \n-12345\n");
    ft_putnbr_fd(-12345, 1);
    printf(" \n");
}

void test_putendl_fd()
{
    printf("Test ft_putendl_fd  \n\n");
    char str[99];
    strcpy(str, "abcdef");
    printf("result :\t \nabcdef\n\n");
    ft_putendl_fd(str, 1);
    printf(" \n");
    strcpy(str, "123456 b");
    printf("result :\t \n123456 b\n\n");
    ft_putendl_fd(str, 1);
    printf(" \n"); 
}

void test_putstr_fd()
{
    printf("Test ft_putstr_fd  \n\n");
    char str[99];
    strcpy(str, "abcdef");
    printf("result :\t \nabcdef\n");
    ft_putstr_fd(str, 1);
    printf(" \n");
    strcpy(str, "123456 b");
    printf("result :\t \n123456 b\n");
    ft_putstr_fd(str, 1);
    printf(" \n");
}

void test_putchar_fd()
{
    printf("Test ft_putchar_fd  \n\n");
    char c;
    c = 'a';
    printf("result :\t \na\n");
    ft_putchar_fd(c, 1);
    c = 'Z';
    printf("\nresult :\t \nZ\n");
    ft_putchar_fd(c, 1);
    printf(" \n");
}



void test_putnbr()
{
    printf("Test ft_putnbr  \n\n");
    printf("result :\t \n14\n");
    ft_putnbr(14);
    printf("\nresult :\t \n-12345\n");
    ft_putnbr(-12345);
    printf(" \n");
}

void test_putendl()
{
    printf("Test ft_putendl  \n\n");
    char str[99];
    strcpy(str, "abcdef");
    printf("result :\t \nabcdef\n\n");
    ft_putendl(str);
    printf(" \n");
    strcpy(str, "123456 b");
    printf("result :\t \n123456 b\n\n");
    ft_putendl(str);
    printf(" \n"); 
}

void test_putstr()
{
    printf("Test ft_putstr  \n\n");
    char str[99];
    strcpy(str, "abcdef");
    printf("result :\t \nabcdef\n");
    ft_putstr(str);
    printf(" \n");
    strcpy(str, "123456 b");
    printf("result :\t \n123456 b\n");
    ft_putstr(str);
    printf(" \n");
}

void test_putchar()
{
    printf("Test ft_putchar  \n\n");
    char c;
    c = 'a';
    printf("result :\t \na\n");
    ft_putchar(c);
    c = 'Z';
    printf("\nresult :\t \nZ\n");
    ft_putchar(c);
    printf(" \n");
}


void test_itoa()
{
    printf("Test ft_itoa  \n\n");

    printf("original :\t\t 13 \n");
    printf("result attendu :\t 13 \n");
    printf("result :\t\t %s \n", ft_itoa(13));

    printf("original :\t\t -13 \n");
    printf("result attendu :\t -13 \n");
    printf("result :\t\t %s \n", ft_itoa(-13));

    printf("original :\t\t +13 \n");
    printf("result attendu :\t 13 \n");
    printf("result :\t\t %s \n", ft_itoa(+13));

    printf("original :\t\t -123456789 \n");
    printf("result attendu :\t -123456789 \n");
    printf("result :\t\t %s \n", ft_itoa(-123456789));
}

void test_strsplit()
{
    char str[200];
    char **list;
    size_t i;


    printf("Test ft_strsplit  \n\n");
    strcpy(str, "This is a string");
    printf("original :\t\t This is a string - s  \n");
    list = ft_strsplit(str, 's');
    i = 0;
    while (list[i])
    {
        printf("word :\t\t\t %s \n", list[i++]);
    }

    strcpy(str, "*salut*les***etudiants*");
    printf("original :\t\t *salut*les***etudiants* - *  \n");
    i = 0;
    list = ft_strsplit(str, '*');
    while (list[i])
    {
        printf("word :\t\t\t %s \n", list[i++]);
    }

    strcpy(str, "");
    printf("original :\t\t  - *  \n");
    i = 0;
    list = ft_strsplit(str, '*');
    while (list[i])
    {
        printf("word :\t\t\t %s \n", list[i++]);
    }
}

void test_strtrim()
{
    char str[200];

    printf("Test ft_strtrim  \n\n");
    strcpy(str, "\tThis  isa \nstring");
    printf("original :\t\t This is a string \n");
    printf("result attendu :\t Thisisastring \n");
    printf("result :\t\t %s \n", ft_strtrim(str));

    strcpy(str, "nospace");
    printf("original :\t\t nospace \n");
    printf("result attendu :\t nospace \n");
    printf("result :\t\t %s \n", ft_strtrim(str));

    strcpy(str, "nospace");
    printf("original :\t\t nospace \n");
    printf("result attendu :\t %p \n", ft_strtrim(str));
    printf("result :\t\t %p \n", ft_strtrim(str));
}

void test_strjoin()
{
    printf("Test ft_strjoin  \n\n");
    printf("original :\t\t OKAAAAA OKAAAAA \n");
    printf("result attendu :\t OKAAAAAOKAAAAA \n");
    printf("result :\t\t %s \n", ft_strjoin("OKAAAAA", "OKAAAAA"));

    printf("original :\t\t A OKAAAAA \n");
    printf("result attendu :\t AOKAAAAA \n");
    printf("result :\t\t %s \n", ft_strjoin("A", "OKAAAAA"));

    printf("original :\t\t A  \n");
    printf("result attendu :\t A \n");
    printf("result :\t\t %s \n", ft_strjoin("A", ""));
}

void test_strsub()
{
    printf("Test ft_strsub  \n\n");
    printf("original :\t\t OKAAAAA 1 6 \n");
    printf("result attendu :\t KAAAAA \n");
    printf("result :\t\t %s \n", ft_strsub("OKAAAAA", 1, 6));

    printf("original :\t\t OKAAAAA 1 7 \n");
    printf("result attendu :\t (null) \n");
    printf("result :\t\t %s \n", ft_strsub("OKAAAAA", 1, 7));

    printf("original :\t\t OKAAAAA 0 1 \n");
    printf("result attendu :\t O \n");
    printf("result :\t\t %s \n", ft_strsub("OKAAAAA", 0, 1));
}

void test_strnequ()
{
    printf("Test ft_strnequ  \n\n");
    printf("original :\t\t OK1 OK2 \n");
    printf("result attendu :\t 1 \n");
    printf("result :\t\t %d \n", ft_strnequ("OK1", "OK2", 2));

    printf("original :\t\t OK1 OK1 \n");
    printf("result attendu :\t 1 \n");
    printf("result :\t\t %d \n", ft_strnequ("OK1", "OK1", 2));

    printf("original :\t\t  OK1 \n");
    printf("result attendu :\t 1 \n");
    printf("result :\t\t %d \n", ft_strnequ("", "OK1", 0));

    printf("original :\t\t OKa OK1 \n");
    printf("result attendu :\t 0 \n");
    printf("result :\t\t %d \n", ft_strnequ("OKa", "OK1", 3));
}

void test_strequ()
{
    printf("Test ft_strequ  \n\n");
    printf("original :\t\t OK1 OK2 \n");
    printf("result attendu :\t 0 \n");
    printf("result :\t\t %d \n", ft_strequ("OK1", "OK2"));

    printf("Test ft_strequ  \n\n");
    printf("original :\t\t OK1 OK1 \n");
    printf("result attendu :\t 1 \n");
    printf("result :\t\t %d \n", ft_strequ("OK1", "OK1"));

    printf("Test ft_strequ  \n\n");
    printf("original :\t\t  OK1 \n");
    printf("result attendu :\t 0 \n");
    printf("result :\t\t %d \n", ft_strequ("", "OK1"));
}

char ft_rot1_n(unsigned int i, char c)
{
    if (i % 2 == 0)
        return (c + 1);
    return (c);
}

void test_strmapi()
{
    char str[99];

    printf("Test ft_strmapi  \n\n");

    strcpy(str, "This is");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t Uhjs!it \n");
    printf("result :\t\t %s \n", ft_strmapi(str, ft_rot1_n));


    strcpy(str, "");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t  \n");
    printf("result :\t\t %s \n", ft_strmapi(str, ft_rot1_n));
}

char ft_rot1(char c)
{
    return (c + 1);
}

void test_strmap()
{
    char str[99];

    printf("Test ft_strmap  \n\n");

    strcpy(str, "This is");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t Uijt!jt \n");
    printf("result :\t\t %s \n", ft_strmap(str, ft_rot1));


    strcpy(str, "");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t  \n");
    printf("result :\t\t %s \n", ft_strmap(str, ft_rot1));
}

void ft_putchar_mod_n(unsigned int i, char *c)
{
    if (i % 2 == 0)
        write(1, c, 1);
}


void test_striteri()
{
    printf("Test ft_striteri  \n\n");
    char str[999];

    strcpy(str, "OK c'est ok");
    printf("result attendu :\t\nO 's k \n");
    ft_striteri(str, ft_putchar_mod_n);
    printf(" \n");
    strcpy(str, "");
    printf("result attendu :\t\n \n");
    ft_striteri(str, ft_putchar_mod_n);
    printf(" \n");
}


void ft_putchar_mod(char *c)
{
    write(1, c, 1);
}


void test_striter()
{
    printf("Test ft_striter  \n\n");
    char str[999];

    strcpy(str, "OK c'est ok");
    printf("result attendu :\t\nOK c'est ok \n");
    ft_striter(str, ft_putchar_mod);
    printf(" \n");
    strcpy(str, "");
    printf("result attendu :\t\n \n");
    ft_striter(str, ft_putchar_mod);
    printf(" \n");
}

void test_strclr()
{
    char *str;

    printf("Test ft_strclr  \n\n");
    str = (char *)malloc(10 * sizeof(char));
    str[0] = 'a';
    str[9] = 'a';
    ft_strclr(str);
    printf("result attendu :\t \n");
    printf("result :\t\t %c \n", *str);
    printf("result attendu :\t \n");
    printf("result :\t\t %c \n", *(str + 1));
    printf("Attention comportement à revoir ... \n");
    printf("result attendu :\t a \n");
    printf("result :\t\t %c \n", *(str + 9));
}

void test_strdel()
{
    char *str;

    printf("Test ft_strdel  \n\n");
    str = (char *)malloc(10 * sizeof(char));
    str[0] = 'a';
    str[9] = 'a';
    ft_strdel(&str);
    printf("result attendu :\t 0x0 \n");
    printf("result :\t\t %p \n", str);
    printf("result attendu :\t 0x9 \n");
    printf("result :\t\t %p \n", str + 9);
}

void test_strnew()
{
    char *str;

    printf("Test ft_strnew  \n\n");
    str = ft_strnew(5);
    str[0] = 'a';
    str[1] = 'b';
    str[4] = 'a';
    printf("result attendu :\t ab \n");
    printf("result :\t\t %s \n", str);
    str[2] = 'a';
    str[3] = 'a';
    printf("result attendu :\t abaaa \n");
    printf("result :\t\t %s \n", str);
}

void test_memdel()
{
    char *str;

    printf("Test ft_memdel  \n\n");
    str = (char *)malloc(10 * sizeof(char));
    str[0] = 'a';
    str[9] = 'a';
    ft_memdel((void **)&str);
    printf("result attendu :\t 0x0 \n");
    printf("result :\t\t %p \n", str);
    printf("result attendu :\t 0x9 \n");
    printf("result :\t\t %p \n", str + 9);
}

void test_memalloc()
{
    void *p;

    printf("Test ft_memalloc  \n\n");
    p = ft_memalloc(20);
    *(int *)p = 10;
    *(int *)(p + 1) = 10;
    free(p);
    p = ft_memalloc(20);
    printf("result attendu :\t %d \n", 0);
    printf("result :\t\t %d \n", *(int *)p);
    printf("result attendu :\t %d \n", 0);
    printf("result :\t\t %d \n", *(int *)(p + 1));
}
