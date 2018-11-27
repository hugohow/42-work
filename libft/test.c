#include <stdio.h>
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


#include <stdio.h>
#include <string.h>

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

    return (0);
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