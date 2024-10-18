#include "libft.h"
void print_content(void *content)
{
    printf("%s\n", (char *)content);
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}
// int main()
// {
//     t_list *list = ft_lstnew("Hello");
//     ft_lstiter(list, print_content);  // Listedeki her elemanı yazdırır
// }