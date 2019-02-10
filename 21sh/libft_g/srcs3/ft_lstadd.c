#include <string.h>
#include <stdlib.h>

typedef struct      s_list
{
    void            *content;
    size_t          content_size;
    struct s_list   *next;
}                   t_list;

void    ft_lstadd(t_list **alst, t_list *new_el)
{
	if (alst != NULL && new_el != NULL)
	{
        new_el->next = *alst;
        *alst = new_el;
    }
}
