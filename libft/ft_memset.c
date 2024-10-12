#include "libft.h"

void	*ft_memset(void *dest, int c, size_t count)
{
	unsigned char *ptr = (unsigned char *) dest;

	while (count--)
	{
		*ptr = (unsigned char) c;
		ptr++;
	}
	return dest;
}
