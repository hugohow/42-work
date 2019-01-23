#include <string.h>
#include <stdlib.h>

typedef struct      s_list
{
    void            *content;
    size_t          content_size;
    struct s_list   *next;
}                   t_list;

void    *ft_memcpy(void *dst, const void *src, size_t n);

t_list *ft_lstnew(void const *content, size_t content_size)
{
    t_list *new;
    void *new_content;

    new = (t_list *)malloc(sizeof(t_list));
    new_content = (void *)malloc(content_size);
    if (new == NULL)
        return (NULL);
    if (content == NULL)
    {
        new->content = NULL;
        new->content_size = 0;
    }
    else
    {
        ft_memcpy(new_content, content, content_size);
        new->content = new_content;
        new->content_size = content_size;
    }
    new->next = NULL;
    return (new);
}