#include "ft_color.h"

void print_red(int fd)
{
    ft_putstr_fd("\033[0;31m", fd);
}

void print_bold_red(int fd)
{
    ft_putstr_fd("\033[1;31m", fd);
}

void print_green(int fd)
{
    ft_putstr_fd("\033[0;32m", fd);
}

void print_bold_green(int fd)
{
    ft_putstr_fd("\033[1;32m", fd);
}

void print_yellow(int fd)
{
    ft_putstr_fd("\033[0;33m", fd);
}

void print_bold_yellow(int fd)
{
    ft_putstr_fd("\033[1;33m", fd);
}

void print_blue(int fd)
{
    ft_putstr_fd("\033[0;34m", fd);
}

void print_bold_blue(int fd)
{
    ft_putstr_fd("\033[1;34m", fd);
}

void print_magenta(int fd)
{
    ft_putstr_fd("\033[0;35m", fd);
}

void print_bold_magenta(int fd)
{
    ft_putstr_fd("\033[1;35m", fd);
}

void print_cyan(int fd)
{
    ft_putstr_fd("\033[0;36m", fd);
}

void print_bold_cyan(int fd)
{
    ft_putstr_fd("\033[1;36m", fd);
}

void print_normal(int fd)
{
    ft_putstr_fd("\033[0m", fd);
}