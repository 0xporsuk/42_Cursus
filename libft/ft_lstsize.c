#include "libft.h"

int ft_lstsize(t_list *lst)
{
    int i;

    i = 0;
    while (lst)
    {
        lst = lst->next;
        i++;
    }
    return (i);
}
int main()
{
    t_list *node1 = ft_lstnew("Hello");
    t_list *node2 = ft_lstnew("World");
    node1->next = node2;

    int i = ft_lstsize(node1);
    printf("%d\n", i);
}