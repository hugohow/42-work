int	ft_count_if(char **tab, int (*f)(char*))
{
	int i;
	int y;

	i = 0;
	y = 0;
	while (tab[i] != 0)
	{
		if (f(tab[i]) == 1)
			y += f(tab[i]);
	i++;
	}
	return (y);
}
