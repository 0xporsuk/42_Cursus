#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void *d;

	d = malloc(nitems * size);
	if (!d)
		return (NULL);
	d = ft_memset(d, 0, nitems * size);

	return (d);
}
int main()
{
	char dest[] = {0, 0, 0, 0, 5};
	char *src;

	src = ft_calloc(2, 2);

	int sonuc = ft_memcmp(dest, src, 10);

	printf("%d\n", sonuc);
}
