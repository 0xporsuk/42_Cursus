#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return;
	if (!lst)
	{
		*lst = new;
		return;
	}
	else
		ft_lstlast(*lst)->next = new;
}

// int main()
// {
// 	t_list *a = ft_lstnew("hello");
// 	t_list *b = ft_lstnew("merhaba");
// 	a->next = b;
// 	t_list *new = ft_lstnew("yeni");
// 	ft_lstadd_back(&a, new);

// 	t_list *current = a;
// 	while(current){
// 		printf("%s\n", current->content);
// 		current = current->next;
// 	}
// }