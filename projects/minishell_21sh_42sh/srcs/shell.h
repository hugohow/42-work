#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <termios.h>

int     get_next_line(const int fd, char **line);
int     ft_printf(const char* format, ...);
int     ft_strcmp(const char *s1, const char *s2);
char    **ft_strsplit(char const *str, char c);
char    *ft_strjoin(char const *str1, char const *str2);
size_t  ft_strlen(const char *str);
char *get_line_env(char *str, char ***p_environ);
char    *ft_strtrim(char const *str);
char    *ft_strsub(char const *s, unsigned int start, size_t len);
void    ft_putstr(char const *str);
void    ft_putstr_fd(char const *str, int fd);
int     ft_atoi(const char *str);
int     ft_isdigit(int c);
void    print_bold_green(int fd);
void    print_normal(int fd);

void    ft_putnbr(int nb);
void    ft_putchar(char c);
int     ft_isalnum(int c);

void    ft_exit_terminal(struct termios *orig_termios);
int     ft_init_terminal(struct termios *orig_termios, struct termios *new_termios);
int     ft_read_key();
void print_cmd(char *cmd);
void add_to_stdout(char **p_cmd, int c, int *index);
void delete_n_lines(int n);
int count_nb_line(char *cmd);
int prepare_command(char *cmd, char ***copy_env, int prev_res, struct termios *p_orig_termios);
int ft_execute_path(char *path, char **argv, char ***p_environ, int fd0, int fd1, int fd2);
int ft_ask_command(int fd, char **command, struct termios *p_orig_termios);
void ft_exit(char *cmd, int success, struct termios *p_orig_termios);
int ft_list_size(char **list);
char **copy_environ(char **str);
char **get_paths(char **copy_env);
int execute_command(char *cmd, char **paths, char ***p_environ, struct termios *p_orig_termios, int fd0, int fd1, int fd2);
extern char **environ;