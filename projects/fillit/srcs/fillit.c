/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:48:02 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/04 17:34:05 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int main(int argc, char **argv)
{
    int fd;
    char *buf;
    char *result;
    t_tetri **list_tetri;

    if (argc != 2)
    {
        printf("usage");
        return (0);
    }
    fd = open(argv[1], O_RDONLY);
    if (fd != -1)
    {
        buf = malloc((LIMIT_TETRIS * SIZE_BUFFER_TETRIS) * sizeof(char));
        if (buf == NULL)
            return (0);
        read(fd, buf, LIMIT_TETRIS * SIZE_BUFFER_TETRIS);
        if (is_valid_input(buf) == 1)
        {
            list_tetri = tokenize(buf);
            if (list_tetri == NULL)
                printf("error\n");
            else
            {
                result = solve(list_tetri);
                if (result)
			        free(result);
            }
        }
        else
        {
            printf("error\n");
        }
		free(buf);
        close(fd);
    }

    return (0);
}