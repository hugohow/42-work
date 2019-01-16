#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "libft.h"

void test_memset();
void test_bzero();
void test_memcpy();
void test_memccpy();
void test_memmove();
void test_strcpy();
void test_strlen();
void test_memchr();
void test_memcmp();
void test_strdup();
void test_strncpy();
void test_strcat();
void test_strncat();
void test_strlcat();
void test_strchr();
void test_strrchr();
void test_strstr();
void test_strnstr();
void test_strcmp();
void test_strncmp();
void test_atoi();
void test_isalpha();
void test_isdigit();
void test_isalnum();
void test_isascii();
void test_isprint();
void test_tolower();
void test_toupper();


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
    test_memchr();
    printf("--------------------------------------------  \n\n");
    test_memcmp();
    printf("--------------------------------------------  \n\n");
    test_strdup();
    printf("--------------------------------------------  \n\n");
    test_strncpy();
    printf("--------------------------------------------  \n\n");
    test_strcat();
    printf("--------------------------------------------  \n\n");
    test_strncat();
    printf("--------------------------------------------  \n\n");
    test_strlcat();
    printf("--------------------------------------------  \n\n");
    test_strchr();
    printf("--------------------------------------------  \n\n");
    test_strrchr();
    printf("--------------------------------------------  \n\n");
    test_strstr();
    printf("--------------------------------------------  \n\n");
    test_strnstr();
    printf("--------------------------------------------  \n\n");
    test_strcmp();
    printf("--------------------------------------------  \n\n");
    test_strncmp();
    printf("--------------------------------------------  \n\n");
    test_atoi();
    printf("--------------------------------------------  \n\n");
    test_isalpha();
    printf("--------------------------------------------  \n\n");
    test_isdigit();
    printf("--------------------------------------------  \n\n");
    test_isalnum();
    printf("--------------------------------------------  \n\n");
    test_isascii();
    printf("--------------------------------------------  \n\n");
    test_isprint();
    printf("--------------------------------------------  \n\n");
    test_toupper();
    printf("--------------------------------------------  \n\n");
    test_tolower();
    printf("--------------------------------------------  \n\n");


    return (0);
}

void test_toupper()
{
    int c;
    printf("Test ft_toupper  \n\n");

    c = 'a';
    printf("original :\t\t %c \n", c);
    printf("result attendu :\t %c \n", toupper(c));
    c = 'a';
    printf("result :\t\t %c \n", ft_toupper(c));

    c = 'A';
    printf("original :\t\t %c \n", c);
    printf("result attendu :\t %c \n", toupper(c));
    c = 'A';
    printf("result :\t\t %c \n", ft_toupper(c));

    c = '1';
    printf("original :\t\t %c \n", c);
    printf("result attendu :\t %c \n", toupper(c));
    c = '1';
    printf("result :\t\t %c \n", ft_toupper(c));
}

void test_tolower()
{
    int c;
    printf("Test ft_tolower  \n\n");

    c = 'a';
    printf("original :\t\t %c \n", c);
    printf("result attendu :\t %c \n", tolower(c));
    c = 'a';
    printf("result :\t\t %c \n", ft_tolower(c));

    c = 'A';
    printf("original :\t\t %c \n", c);
    printf("result attendu :\t %c \n", tolower(c));
    c = 'A';
    printf("result :\t\t %c \n", ft_tolower(c));

    c = '1';
    printf("original :\t\t %c \n", c);
    printf("result attendu :\t %c \n", tolower(c));
    c = '1';
    printf("result :\t\t %c \n", ft_tolower(c));
}

void test_isprint()
{
    int c;
    printf("Test ft_isprint  \n\n");

    c = 'a';
    printf("original :\t\t %c \n", c);
    printf("result attendu :\t %d \n", isprint(c));
    c = 'a';
    printf("result :\t\t %d \n", ft_isprint(c));

    c = '&';
    printf("original :\t\t %c \n", c);
    printf("result attendu :\t %d \n", isprint(c));
    c = '&';
    printf("result :\t\t %d \n", ft_isprint(c));

    c = 'Z';
    printf("original :\t\t %c \n", c);
    printf("result attendu :\t %d \n", isprint(c));
    c = 'Z';
    printf("result :\t\t %d \n", ft_isprint(c));

    c = '2';
    printf("original :\t\t %c \n", c);
    printf("result attendu :\t %d \n", isprint(c));
    c = '2';
    printf("result :\t\t %d \n", ft_isprint(c));

    c = 127;
    printf("original :\t\t %c \n", c);
    printf("result attendu :\t %d \n", isprint(c));
    c = 127;
    printf("result :\t\t %d \n", ft_isprint(c));

    c = 200;
    printf("original :\t\t %c \n", c);
    printf("result attendu :\t %d \n", isprint(c));
    c = 200;
    printf("result :\t\t %d \n", ft_isprint(c));
}

void test_isascii()
{
    int c;
    printf("Test ft_isascii  \n\n");

    c = 'a';
    printf("original :\t\t %c \n", c);
    printf("result attendu :\t %d \n", isascii(c));
    c = 'a';
    printf("result :\t\t %d \n", ft_isascii(c));

    c = '&';
    printf("original :\t\t %c \n", c);
    printf("result attendu :\t %d \n", isascii(c));
    c = '&';
    printf("result :\t\t %d \n", ft_isascii(c));

    c = 'Z';
    printf("original :\t\t %c \n", c);
    printf("result attendu :\t %d \n", isascii(c));
    c = 'Z';
    printf("result :\t\t %d \n", ft_isascii(c));

    c = '2';
    printf("original :\t\t %c \n", c);
    printf("result attendu :\t %d \n", isascii(c));
    c = '2';
    printf("result :\t\t %d \n", ft_isascii(c));

    c = 127;
    printf("original :\t\t %c \n", c);
    printf("result attendu :\t %d \n", isascii(c));
    c = 127;
    printf("result :\t\t %d \n", ft_isascii(c));

    c = 200;
    printf("original :\t\t %c \n", c);
    printf("result attendu :\t %d \n", isascii(c));
    c = 200;
    printf("result :\t\t %d \n", ft_isascii(c));
}

void test_isalnum()
{
    int c;
    printf("Test ft_isalnum  \n\n");

    c = 'a';
    printf("original :\t\t %c \n", c);
    printf("result attendu :\t %d \n", isalnum(c));
    c = 'a';
    printf("result :\t\t %d \n", ft_isalnum(c));

    c = '&';
    printf("original :\t\t %c \n", c);
    printf("result attendu :\t %d \n", isalnum(c));
    c = '&';
    printf("result :\t\t %d \n", ft_isalnum(c));

    c = 'Z';
    printf("original :\t\t %c \n", c);
    printf("result attendu :\t %d \n", isalnum(c));
    c = 'Z';
    printf("result :\t\t %d \n", ft_isalnum(c));

    c = '2';
    printf("original :\t\t %c \n", c);
    printf("result attendu :\t %d \n", isalnum(c));
    c = '2';
    printf("result :\t\t %d \n", ft_isalnum(c));
}

void test_isdigit()
{
    int c;
    printf("Test ft_isdigit  \n\n");

    c = 'a';
    printf("original :\t\t %c \n", c);
    printf("result attendu :\t %d \n", isdigit(c));
    c = 'a';
    printf("result :\t\t %d \n", ft_isdigit(c));

    c = '&';
    printf("original :\t\t %c \n", c);
    printf("result attendu :\t %d \n", isdigit(c));
    c = '&';
    printf("result :\t\t %d \n", ft_isdigit(c));

    c = 'Z';
    printf("original :\t\t %c \n", c);
    printf("result attendu :\t %d \n", isdigit(c));
    c = 'Z';
    printf("result :\t\t %d \n", ft_isdigit(c));

    c = '2';
    printf("original :\t\t %c \n", c);
    printf("result attendu :\t %d \n", isdigit(c));
    c = '2';
    printf("result :\t\t %d \n", ft_isdigit(c));
}

void test_isalpha()
{
    int c;
    printf("Test ft_isalpha  \n\n");

    c = 'a';
    printf("original :\t\t %c \n", c);
    printf("result attendu :\t %d \n", isalpha(c));
    c = 'a';
    printf("result :\t\t %d \n", ft_isalpha(c));

    c = '&';
    printf("original :\t\t %c \n", c);
    printf("result attendu :\t %d \n", isalpha(c));
    c = '&';
    printf("result :\t\t %d \n", ft_isalpha(c));

    c = 'Z';
    printf("original :\t\t %c \n", c);
    printf("result attendu :\t %d \n", isalpha(c));
    c = 'Z';
    printf("result :\t\t %d \n", ft_isalpha(c));
}

void test_atoi()
{
    char str[50];
    printf("Test ft_atoi  \n\n");

    strcpy(str, "10");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %d \n", atoi(str));
    strcpy(str, "10");
    printf("result :\t\t %d \n", ft_atoi(str));


    strcpy(str, "-10");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %d \n", atoi(str));
    strcpy(str, "-10");
    printf("result :\t\t %d \n", ft_atoi(str));

    strcpy(str, "- 10");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %d \n", atoi(str));
    strcpy(str, "- 10");
    printf("result :\t\t %d \n", ft_atoi(str));

    strcpy(str, "\t\v 10");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %d \n", atoi(str));
    strcpy(str, "\t\v 10");
    printf("result :\t\t %d \n", ft_atoi(str));

    strcpy(str, "+ 10");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %d \n", atoi(str));
    strcpy(str, "+ 10");
    printf("result :\t\t %d \n", ft_atoi(str));

    strcpy(str, "+10");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %d \n", atoi(str));
    strcpy(str, "+10");
    printf("result :\t\t %d \n", ft_atoi(str));

    strcpy(str, "* 10");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %d \n", atoi(str));
    strcpy(str, "* 10");
    printf("result :\t\t %d \n", ft_atoi(str));

    strcpy(str, "999910");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %d \n", atoi(str));
    strcpy(str, "999910");
    printf("result :\t\t %d \n", ft_atoi(str));


    strcpy(str, "999910");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %d \n", atoi(str));
    strcpy(str, "999910");
    printf("result :\t\t %d \n", ft_atoi(str));


    strcpy(str, "2147483647");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %d \n", atoi(str));
    strcpy(str, "2147483647");
    printf("result :\t\t %d \n", ft_atoi(str));


    strcpy(str, "-2147483648");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %d \n", atoi(str));
    strcpy(str, "-2147483648");
    printf("result :\t\t %d \n", ft_atoi(str));

    strcpy(str, "2147483650");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %d \n", atoi(str));
    strcpy(str, "2147483650");
    printf("result :\t\t %d \n", ft_atoi(str));
    // strcpy(str, "- 10");
    // printf("original :\t\t %s \n", str);
    // printf("result attendu :\t %d \n", atoi(str));
    // strcpy(str, "- 10");
    // printf("result :\t\t %d \n", ft_atoi(str));


}

void test_strncmp()
{
    char str[50];
    printf("Test ft_strncmp  \n\n");

    strcpy(str, "This is");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %d \n", strncmp(str, "This is", 10));
    strcpy(str, "This is");
    printf("result :\t\t %d \n", ft_strncmp(str, "This is", 10));

    strcpy(str, "This is");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %d \n", strncmp(str, "This isÏ", 10));
    strcpy(str, "This is");
    printf("result :\t\t %d \n", ft_strncmp(str, "This isÏ", 10));

    strcpy(str, "This isÏ");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %d \n", strncmp(str, "This is", 10));
    strcpy(str, "This isÏ");
    printf("result :\t\t %d \n", ft_strncmp(str, "This is", 10));

    strcpy(str, "This isÏ");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %d \n", strncmp(str, "This", 10));
    strcpy(str, "This isÏ");
    printf("result :\t\t %d \n", ft_strncmp(str, "This", 10));

    strcpy(str, "This isÏ");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %d \n", strncmp(str, "This", 3));
    strcpy(str, "This isÏ");
    printf("result :\t\t %d \n", ft_strncmp(str, "This", 3));

    strcpy(str, "This isÏ");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %d \n", strncmp(str, "This", 4));
    strcpy(str, "This isÏ");
    printf("result :\t\t %d \n", ft_strncmp(str, "This", 4));

    strcpy(str, "This isÏ");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %d \n", strncmp(str, "This", 5));
    strcpy(str, "This isÏ");
    printf("result :\t\t %d \n", ft_strncmp(str, "This", 5));
}


void test_strcmp()
{
    char str[50];
    printf("Test ft_strcmp  \n\n");

    strcpy(str, "This is");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %d \n", strcmp(str, "This is"));
    strcpy(str, "This is");
    printf("result :\t\t %d \n", ft_strcmp(str, "This is"));

    strcpy(str, "This is");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %d \n", strcmp(str, "This isÏ"));
    strcpy(str, "This is");
    printf("result :\t\t %d \n", ft_strcmp(str, "This isÏ"));

    strcpy(str, "This isÏ");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %d \n", strcmp(str, "This is"));
    strcpy(str, "This isÏ");
    printf("result :\t\t %d \n", ft_strcmp(str, "This is"));

    strcpy(str, "This isÏ");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %d \n", strcmp(str, "This"));
    strcpy(str, "This isÏ");
    printf("result :\t\t %d \n", ft_strcmp(str, "This"));
}

void test_strnstr()
{
    char str[50];
    printf("Test ft_strnstr  \n\n");

    strcpy(str, "This is");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %s \n", strnstr(str, "i", 10));
    strcpy(str, "This is");
    printf("result :\t\t %s \n", ft_strnstr(str, "i", 10));

    strcpy(str, "This is");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %s \n", strnstr(str, "is", 10));
    strcpy(str, "This is");
    printf("result :\t\t %s \n", ft_strnstr(str, "is", 10));


    strcpy(str, "This is");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %s \n", strnstr(str, "", 10));
    strcpy(str, "This is");
    printf("result :\t\t %s \n", ft_strnstr(str, "", 10));

    strcpy(str, "This is");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %s \n", strnstr(str, "isa", 10));
    strcpy(str, "This is");
    printf("result :\t\t %s \n", ft_strnstr(str, "isa", 10));

    strcpy(str, "This is");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %s \n", strnstr(str, "q", 10));
    strcpy(str, "This is");
    printf("result :\t\t %s \n", ft_strnstr(str, "q", 10));

    strcpy(str, "This isa");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %s \n", strnstr(str, "a", 8));
    strcpy(str, "This isa");
    printf("result :\t\t %s \n", ft_strnstr(str, "a", 8));
}

void test_strstr()
{
    char str[50];
    printf("Test ft_strstr  \n\n");

    strcpy(str, "This is");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %s \n", strstr(str, "i"));
    strcpy(str, "This is");
    printf("result :\t\t %s \n", ft_strstr(str, "i"));

    strcpy(str, "This is");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %s \n", strstr(str, "is"));
    strcpy(str, "This is");
    printf("result :\t\t %s \n", ft_strstr(str, "is"));


    strcpy(str, "This is");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %s \n", strstr(str, ""));
    strcpy(str, "This is");
    printf("result :\t\t %s \n", ft_strstr(str, ""));

    strcpy(str, "This is");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %s \n", strstr(str, "isa"));
    strcpy(str, "This is");
    printf("result :\t\t %s \n", ft_strstr(str, "isa"));

    strcpy(str, "This is");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %s \n", strstr(str, "q"));
    strcpy(str, "This is");
    printf("result :\t\t %s \n", ft_strstr(str, "q"));
}

void test_strrchr()
{
    char str[50];
    printf("Test ft_strrchr  \n\n");

    strcpy(str, "This is");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %s-%p \n", strrchr(str, 'i'), strrchr(str, 'i'));
    strcpy(str, "This is");
    printf("result :\t\t %s-%p \n", ft_strrchr(str, 'i'), ft_strrchr(str, 'i'));

    strcpy(str, "This is T");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %s-%p \n", strrchr(str, 'T'), strrchr(str, 'T'));
    strcpy(str, "This is T");
    printf("result :\t\t %s-%p \n", ft_strrchr(str, 'T'), ft_strrchr(str, 'T'));

    strcpy(str, "This is");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %s-%p \n", strrchr(str, '\0'), strrchr(str, '\0'));
    strcpy(str, "This is");
    printf("result :\t\t %s-%p \n", ft_strrchr(str, '\0'), ft_strrchr(str, '\0'));

    strcpy(str, "This is");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %s-%p \n", strrchr(str, '1'), strrchr(str, '1'));
    strcpy(str, "This is");
    printf("result :\t\t %s-%p \n", ft_strrchr(str, '1'), ft_strrchr(str, '1'));
}

void test_strchr()
{
    char str[50];
    printf("Test ft_strchr  \n\n");

    strcpy(str, "This is");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %s-%p \n", strchr(str, 'i'), strchr(str, 'i'));
    strcpy(str, "This is");
    printf("result :\t\t %s-%p \n", ft_strchr(str, 'i'), ft_strchr(str, 'i'));

    strcpy(str, "This is");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %s-%p \n", strchr(str, 'T'), strchr(str, 'T'));
    strcpy(str, "This is");
    printf("result :\t\t %s-%p \n", ft_strchr(str, 'T'), ft_strchr(str, 'T'));

    strcpy(str, "This is");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %s-%p \n", strchr(str, '\0'), strchr(str, '\0'));
    strcpy(str, "This is");
    printf("result :\t\t %s-%p \n", ft_strchr(str, '\0'), ft_strchr(str, '\0'));

    strcpy(str, "This is");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %s-%p \n", strchr(str, '1'), strchr(str, '1'));
    strcpy(str, "This is");
    printf("result :\t\t %s-%p \n", ft_strchr(str, '1'), ft_strchr(str, '1'));
}

void test_strlcat()
{
    char str[50];
    char test[256] = "\0zxcvzxcvzxcvxzcvzxcv";

    printf("Test ft_strlcat  \n\n");

    strcpy(str, "This is");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %zu, %s \n", strlcat(str, "string.h library function", sizeof(str)), str);
    strcpy(str, "This is");
    printf("result :\t\t %zu, %s \n", ft_strlcat(str, "string.h library function", sizeof(str)), str);

    strcpy(str, "This is");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %zu, %s \n", strlcat(str, "string.h library function", sizeof(str)), str);
    strcpy(str, "This is");
    printf("result :\t\t %zu, %s \n", ft_strlcat(str, "string.h library function", sizeof(str)), str);

    strcpy(str, "This is");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %zu, %s \n", strlcat(str, "string.h library function", 20), str);
    strcpy(str, "This is");
    printf("result :\t\t %zu, %s \n", ft_strlcat(str, "string.h library function", 20), str);

    strcpy(str, "This is");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %zu, %s \n", strlcat(str, "string.h library function", 5), str);
    strcpy(str, "This is");
    printf("result :\t\t %zu, %s \n", ft_strlcat(str, "string.h library function", 5), str);

    strcpy(str, "This is");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %zu, %s \n", strlcat(str, "string.h library function", 0), str);
    strcpy(str, "This is");
    printf("result :\t\t %zu, %s \n", ft_strlcat(str, "string.h library function", 0), str);

    strcpy(str, "This is");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %zu, %s \n", strlcat(str, "string.h library function", 0), str);
    strcpy(str, "This is");
    printf("result :\t\t %zu, %s \n", ft_strlcat(str, "string.h library function", 0), str);

    printf("original :\t\t %s \n", test);
    printf("result attendu :\t %zu, %s \n", strlcat(test, "asdf", 16), test);
    strcpy(test, "\0zxcvzxcvzxcvxzcvzxcv");
    printf("result :\t\t %zu, %s \n", ft_strlcat(test, "asdf", 16), test);


    printf("original :\t\t %s \n", test);
    printf("result attendu :\t %zu, %s \n", strlcat(test, "asdf", 6), test);
    strcpy(test, "asdf\0");
    printf("result :\t\t %zu, %s \n", ft_strlcat(test, "asdf", 6), test);


    printf("original :\t\t %s \n", test);
    printf("result attendu :\t %zu, %s \n", strlcat(test, "asdf", 4), test);
    strcpy(test, "asdfa\0");
    printf("result :\t\t %zu, %s \n", ft_strlcat(test, "asdf", 4), test);


    printf("original :\t\t %s \n", test);
    printf("result attendu :\t %zu, %s \n", strlcat(test, "", 16), test);
    strcpy(test, "asdfa\0");
    printf("result :\t\t %zu, %s \n", ft_strlcat(test, "", 16), test);


    printf("original :\t\t %s \n", test);
    printf("result attendu :\t %zu, %s \n", strlcat(test, "asdf", 0), test);
    strcpy(test, "asdfa\0");
    printf("result :\t\t %zu, %s \n", ft_strlcat(test, "asdf", 0), test);

}

void test_strncat()
{
    char str[50];
    printf("Test ft_strncat  \n\n");

    strcpy(str, "This is");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %s \n", strncat(str, "string.h library function", 10));
    strcpy(str, "This is");
    printf("result :\t\t %s \n", ft_strncat(str, "string.h library function", 10));

    strcpy(str, "");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %s \n", strncat(str, "string.h library function", 10));
    strcpy(str, "");
    printf("result :\t\t %s \n", ft_strncat(str, "string.h library function", 10));

    strcpy(str, "This");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %s \n", strncat(str, "string.h", 3));
    strcpy(str, "This");
    printf("result :\t\t %s \n", ft_strncat(str, "string.h", 3));
}

void test_strcat()
{
    char str[50];
    printf("Test ft_strcat  \n\n");

    strcpy(str, "This is");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %s \n", strcat(str, "string.h library function"));
    strcpy(str, "This is");
    printf("result :\t\t %s \n", ft_strcat(str, "string.h library function"));

    strcpy(str, "");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %s \n", strcat(str, "string.h library function"));
    strcpy(str, "");
    printf("result :\t\t %s \n", ft_strcat(str, "string.h library function"));

    strcpy(str, "This");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %s \n", strcat(str, ""));
    strcpy(str, "This");
    printf("result :\t\t %s \n", ft_strcat(str, ""));
}

void test_strncpy()
{
    char str[50];
    printf("Test ft_strncpy  \n\n");

    strcpy(str, "This is string.h library function");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %s \n", strncpy(str, "okoko", 5));
    strcpy(str, "This is string.h library function");
    printf("result :\t\t %s \n", ft_strncpy(str, "okoko", 5));

    strcpy(str, "This is string.h library function");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %s \n", strncpy(str, "okok", 5));
    strcpy(str, "This is string.h library function");
    printf("result :\t\t %s \n", ft_strncpy(str, "okok", 5));

    strcpy(str, "This is string.h library function");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %s \n", strncpy(str, "", 5));
    strcpy(str, "This is string.h library function");
    printf("result :\t\t %s \n", ft_strncpy(str, "", 5));

    strcpy(str, "This is string.h library function");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %s \n", strncpy(str, "This is string.h library function1111", 5));
    strcpy(str, "This is string.h library function");
    printf("result :\t\t %s \n", ft_strncpy(str, "This is string.h library function1111", 5));
}

void test_strdup()
{
    char str[50];
    char *cpy;
    printf("Test ft_strdup  \n\n");

    strcpy(str, "This is string.h library function");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %s \n", strdup("Thi"));
    strcpy(str, "This is string.h library function");
    printf("result :\t\t %s \n", ft_strdup("Thi"));  

    
    strcpy(str, "This is string.h library function");
    printf("original :\t\t %s \n", str);
    cpy = strdup("Thi");
    printf("result attendu :\t %s and %p != %p \n", cpy, str, cpy);
    strcpy(str, "This is string.h library function");
    cpy = ft_strdup("Thi");
    printf("result attendu :\t %s and %p != %p \n", cpy, str, cpy);
}

void test_memcmp()
{
    char str[50];
    printf("Test ft_memcmp  \n\n");

    strcpy(str, "This is string.h library function");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %d \n", memcmp(str, "Thi", 3));
    strcpy(str, "This is string.h library function");
    printf("result :\t\t %d \n", ft_memcmp(str, "Thi", 3));  

    strcpy(str, "This is string.h library function");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %d \n", memcmp(str, "Thi", 4));
    strcpy(str, "This is string.h library function");
    printf("result :\t\t %d \n", ft_memcmp(str, "Thi", 4));  

    strcpy(str, "This is string.h library function");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %d \n", memcmp(str, "Thi", 10));
    strcpy(str, "This is string.h library function");
    printf("result :\t\t %d \n", ft_memcmp(str, "Thi", 10)); 

    strcpy(str, "This is string.h library function");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %d \n", memcmp(str, "This is string.h library function", 10));
    strcpy(str, "This is string.h library function");
    printf("result :\t\t %d \n", ft_memcmp(str, "This is string.h library function", 10));    

    strcpy(str, "This is string.h library function");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %d \n", memcmp(str, "This as string.h library function", 10));
    strcpy(str, "This is string.h library function");
    printf("result :\t\t %d \n", ft_memcmp(str, "This as string.h library function", 10)); 

    strcpy(str, "This is string.h library function");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %d \n", memcmp(str, "This 2s string.h library function", 7));
    strcpy(str, "This is string.h library function");
    printf("result :\t\t %d \n", ft_memcmp(str, "This 2s string.h library function", 7));    


    strcpy(str, "┌");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %d \n", memcmp(str, "Ê", 10));
    strcpy(str, "┌");
    printf("result :\t\t %d \n", ft_memcmp(str, "Ê", 10)); 

    strcpy(str, "Ê┌");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %d \n", memcmp(str, "Ê", 1));
    strcpy(str, "Ê┌");
    printf("result :\t\t %d \n", ft_memcmp(str, "Ê", 1));    

    strcpy(str, "Ê┌");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %d \n", memcmp(str, "Êa", 3));
    strcpy(str, "Ê┌");
    printf("result :\t\t %d \n", ft_memcmp(str, "Êa", 3));   

    strcpy(str, "▄");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %d \n", memcmp(str, "", 3));
    strcpy(str, "▄");
    printf("result :\t\t %d \n", ft_memcmp(str, "", 3));    
}

void test_memchr()
{
    char str[50];
    printf("Test ft_memchr  \n\n");

    strcpy(str, "This is string.h library function");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %s \n", memchr(str, 's', 3));
    strcpy(str, "This is string.h library function");
    printf("result :\t\t %s \n", ft_memchr(str, 's', 3));


    strcpy(str, "This is string.h library function");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %s \n", memchr(str, 's', 4));
    strcpy(str, "This is string.h library function");
    printf("result :\t\t %s \n", ft_memchr(str, 's', 4));



    strcpy(str, "This is string.h library function");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %s \n", memchr(str, 's', 10));
    strcpy(str, "This is string.h library function");
    printf("result :\t\t %s \n", ft_memchr(str, 's', 10));


    strcpy(str, "This is string.h library function");
    printf("original :\t\t %s \n", str);
    printf("result attendu :\t %s \n", memchr(str, '9', 10));
    strcpy(str, "This is string.h library function");
    printf("result :\t\t %s \n", ft_memchr(str, '9', 10));
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