#include ft_prot.h

#define BUF_SIZE 4096

void	ft_read_file(char *name)
{
	int	fd;
	int	ret;
	char	buf[BUF_SIZE + 1];

	fd = open(name, O_RDONLY);
	if (fd != -1)
	{
		while ((ret = read(fd, buf, BUF_SIZE)))
		{
			buf[ret] = '\0';
			ft_putstr(buf);
		}
	}
	if (close(fd) == -1)
	{
		ft_putstr("error when close");
	}
}
