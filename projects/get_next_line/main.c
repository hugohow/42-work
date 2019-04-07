
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int get_next_line(const int fd, char **line);

/*
** 2 lines with 8 chars with Line Feed
*/

int				main(void)
{
	char 	*line;
	int		out;
	int		p[2];
	int		fd;

	fd = 1;
	out = dup(fd);
	pipe(p);

	dup2(p[1], fd);
	write(fd, "aaa\nbbb\nccc\nddd\n", 16);
	dup2(out, fd);
	close(p[1]);
	get_next_line(p[0], &line);
	printf("%d\n", strcmp(line, "aaa") == 0);
	printf("%s\n", line);
	get_next_line(p[0], &line);
	printf("%d\n", strcmp(line, "bbb") == 0);
	printf("%s\n", line);
	get_next_line(p[0], &line);
	printf("%d\n", strcmp(line, "ccc") == 0);
	printf("%s\n", line);
	get_next_line(p[0], &line);
	printf("%d\n", strcmp(line, "ddd") == 0);
	printf("%s\n", line);
	return (0);
}