#include "libft.h"

void	print_content(void *content)
{
	printf ("%s\n", (char *)content);
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}
