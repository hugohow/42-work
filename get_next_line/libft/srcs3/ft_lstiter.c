#include <string.h>
#include <stdlib.h>

typedef struct      s_list
{
    void            *content;
    size_t          content_size;
    struct s_list   *next;
}                   t_list;

void    ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
    if (lst == NULL)
        return ;
    else
    {
        f(lst);
        ft_lstiter(lst->next, f);
    }
}
