#include <string.h>
#include <stdlib.h>

typedef struct      s_list
{
    void            *content;
    size_t          content_size;
    struct s_list   *next;
}                   t_list;

void    ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
    if (*alst)
    {
        del((*alst)->content, (*alst)->content_size);
        ft_lstdel(&((*alst)->next), del);
    }
    else
        return ;
    free(*alst);
    *alst = NULL; 
}
