#include <string.h>
#include <stdlib.h>

typedef struct      s_list
{
    void            *content;
    size_t          content_size;
    struct s_list   *next;
}                   t_list;

t_list  *ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
    t_list *new;
    t_list *element;

    if (lst == NULL)
        return (NULL);
    element = f(lst);
    new = element;
    while (lst->next)
    {
        lst = lst->next;
        if (f(lst) == NULL)
            return (NULL);
        element->next = f(lst);
        element = element->next;
    }
    return (new);
}
