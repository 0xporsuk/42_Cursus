#include "libft.h"

void del(void *a)
{
	free(a);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *next_node;
	t_list *temp;

	if (!lst || !del)
		return;
	temp = *lst;
	while (temp != NULL)
	{
		next_node = temp->next;
		del(temp->content);
		free(temp);
		temp = next_node;

	}
	*lst = NULL;
}

// int main()
// {
// 	t_list *a = ft_lstnew("merhaba");
// 	t_list *b = ft_lstnew("hello");
// 	a->next = b;
// 	ft_lstclear(&a, del);
// 	printf("%s", b->content);
// }