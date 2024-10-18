#include "libft.h"

t_list *ft_lstlast(t_list *lst){
	if (!lst)
		return (NULL);
	while (lst -> next)
		lst = lst -> next;
	return (lst);
}

// int main()
// {
// 	t_list *n1 = ft_lstnew("Hello");
// 	t_list *n2 = ft_lstnew("World");
// 	n1 -> next = n2;

// 	t_list *n3 = ft_lstlast(n1);
// 	printf("%s\n", (char*)n3 ->content);
// }