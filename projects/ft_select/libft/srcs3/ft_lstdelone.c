#include <string.h>
#include <stdlib.h>

typedef struct      s_list
{
    void            *content;
    size_t          content_size;
    struct s_list   *next;
}                   t_list;

void    ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
    if (*alst)
    {
        del((*alst)->content, (*alst)->content_size);
    }
    free(*alst);
    *alst = NULL; 
}
