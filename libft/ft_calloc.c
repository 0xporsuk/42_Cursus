#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*d;

	d = malloc(nitems * size);
	if (!d)
		return (NULL);
	d = ft_memset(d, 0, nitems * size);
	return (d);
}
