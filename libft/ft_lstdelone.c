#include "libft.h"
void del(void *a)
{
	free(a);
}
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return;
	del(lst->content);
	free(lst);
}
// int main()
// {
// 	t_list *a = ft_lstnew("merhaba");
// 	ft_lstdelone(a, del);
// 	printf("%s", a->content);
// }
