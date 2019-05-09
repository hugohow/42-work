/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_quote_closed.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 17:00:57 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/05/09 17:01:12 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_is_quote_closed(char *cmd)
{
    int i;
    int count_opened;
    int count_closed;

    count_opened = 0;
    count_closed = 0;
    i = 0;
    while (cmd[i])
    {
        if (cmd[i] == '"')
        {
            count_opened++;
        }
        i++;
    }
    return (count_opened % 2 != 0);
}