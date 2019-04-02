void    trim_vertical(char *tetri)
{
    int i;
    int j;

    i = 0;
    while (i < 4)
    {
        if (tetri[i] != '.')
            break;
        i++;
    }
    if (i == 4)
    {
        j = 4;
        while (j != 4*4)
        {
            tetri[j - 4] = tetri[j];
            j++;
        }
        j = 4*4 - 4;
        while (j < 4*4)
            tetri[j++] = '.';
        trim_vertical(tetri);
    }
    return ;
}


void    trim_horizontal(char *tetri)
{
    int i;
    int j;

    i = 0;
    while (i < 4*4)
    {
        if (i % 4 == 0 && tetri[i] != '.')
            break;
        i++;
    }
    if (i == 4*4)
    {
        j = 0;
        while (j != 4*4)
        {
            tetri[j] = tetri[j + 1];
            tetri[j+1] = tetri[j + 2];
            tetri[j+2] = tetri[j + 3];
            tetri[j+3] = '.';
            j += 4;
        }
        trim_horizontal(tetri);
    }
    return ;
}