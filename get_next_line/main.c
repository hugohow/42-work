#include "libft.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int get_next_line(const int fd, char **line);


/*
**  1 line with 8 chars with Line Feed
*/

int				main(void)
{
	char		*line;
	int			ret;

		line = NULL;
		while ((ret = get_next_line(1, &line)) > 0)
		{
			printf("command : %s\n", line);
		}
	return (0);
}