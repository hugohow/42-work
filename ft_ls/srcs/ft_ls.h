#ifndef FT_LS_H
# define FT_LS_H

#include <stdio.h>
#include <locale.h>
#include <stdio.h>
#include <wchar.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <time.h> 
#include <string.h>
#include <stdlib.h>
typedef struct s_file_info
{
    char *path;
    time_t modified;
}               t_file;

typedef struct s_flag
{
    char *flag;
    int has_l;
    int has_cap_r;
    int has_a;
    int has_r;
    int has_t;
}               t_flag;


typedef struct s_btree
{
    void           *content;
    struct s_btree  *left;
    struct s_btree  *right;
}               t_btree;


int ft_printf(const char* format, ...);
void ft_print_files(char *path, t_flag *flag);
void ft_print_file_info(char *path, t_flag *flag);
int ft_strcmp(char *str1, char *str2);
char **ft_strsplit(char const *s, char c);
char *ft_strjoin(char const *s1, char const *s2);
size_t  ft_strlen(const char *str);
t_flag *ft_get_flag_info(char *argv);
char    *ft_strrchr(const char *s, int c);
char *get_file_name(char *path);

t_btree		*btree_create_node(void *item);
// void ft_insert_btree(t_btree **root, void *content, int (*cmp)(void *, void *));
void	btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *));
void ft_traverse_tree(t_btree *root, void (*f)(t_btree *));

#endif