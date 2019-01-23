
void    ft_memdel(void **ap);

void    ft_strdel(char **as)
{
    ft_memdel((void **)as);
}
