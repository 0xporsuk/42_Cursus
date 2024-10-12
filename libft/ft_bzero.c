#include "libft.h"

void	ft_bzero(void *c, size_t n)
{
	unsigned char *p = (unsigned char *) c;

	while (n--)
	{
		*p = 0;
		p++;
	}
}
