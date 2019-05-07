# Bigint

```C
char			*ft_bigint_add(char *dst, const char *to_add, size_t limit);
char			*ft_bigint_divide_by_two(char *output, size_t limit);
char			*ft_bigint_multiply_by_two(char *output);
char			*ft_bigint_shift_right(char *str, size_t nb, size_t limit);
char			*ft_bigint_trim(char *str);
char			*ft_bigint_round(char *dst, int precision, size_t limit);
```

# Data structure

## Hash table

```C
typedef struct	s_node_ht
{
	const char			*key;
	void				*datum;
	struct s_node_ht	*next;
}				t_node_ht;

typedef struct	s_ht
{
	size_t		size;
	t_node_ht	**table;
}				t_ht;
```

```C
t_ht			*ft_ht_create(size_t size);
t_node_ht		*ft_ht_add(t_ht *hash_table, const char *key, void *datum);
t_node_ht		*ft_ht_get(t_ht *hash_table, const char *key);
void			ft_ht_free(t_ht **p_hash_table);
```

## Linked list

```C
typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;
```
```C
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstadd(t_list **alst, t_list *new_el);
void			ft_lstfree(t_list *head);
t_list			*ft_lstpop(t_list **p_head, void (*del)(void *, size_t));
t_list			*ft_lstpeek(t_list *head, int (*cmp)(t_list *n1, t_list *n2));
t_list			*ft_lstpush(t_list **head, void const *data, size_t data_size);
size_t			ft_lstlen(t_list *head);
```
## Binary tree

```C
typedef struct s_node_bt 
{
	void 					*content;
	size_t					content_size;
	struct s_node_bt		*left;
	struct s_node_bt		*right;
}				t_node_bt;
```
```C
t_node_bt	*ft_bt_add(t_node_bt **p_root, void *content, size_t content_size, int (*cmp)(t_node_bt *, t_node_bt *));
void		ft_bt_apply_inorder(t_node_bt *root, void (*f)(t_node_bt *));
void		ft_bt_apply_postorder(t_node_bt *root, void (*f)(t_node_bt *));
t_node_bt	*ft_bt_create(void *content, size_t content_size);
void		ft_bt_free(t_node_bt **p_root);
t_node_bt	*ft_bt_insert(t_node_bt **p_root, t_node_bt *node, int (*cmp)(t_node_bt *, t_node_bt *));
int			ft_bt_is_valid(t_node_bt *root);
```

## AVL

## Red black tree


# Terminal interaction

```C
void		ft_terminal_init()
void		ft_terminal_prompt(char *str)
int		*ft_terminal_ask(char **response, t_choice **choices) -> return response
t_choice	**ft_terminal_question(t_choice **choices)
void		ft_terminal_exit()
```
