/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 18:24:38 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/01 18:54:31 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

int ft_strcmp(char *s1, char *s2)
{
  	if (s1 == 0 || s2 == 0)
   	    return (0);
  	 while (*s1 && *s2 && *s1 == *s2)
   	{
   	    s1++;
   	    s2++;
  	 }
   	if (*s1 == 0 && *s2 == 0)
   	    return (0);
   	return ((int)(*s1 - *s2));
}

int		main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*tmp;

	if (argc == 1)
		return (0);
	i = 1;
	
	while (i < argc)
	{
		j = i;
		while (j < argc)
		{
			if (ft_strcmp(argv[i],argv[j]) > 0)
			{
				tmp = argv[j];
				argv[j] = argv[i];
				argv[i] = tmp;
			}
			j++;
		}
		i++;
	}
	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i]);
	}
}
