
#ifndef FT_PROT_H
# define FT_PROT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

int	ft_check_param_num(int argc);
void	ft_read_file(char *name);
void	ft_putchar(char c);
void	ft_putstr(char *str);
#endif
