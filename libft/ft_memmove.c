#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n){

	unsigned char *d;
	unsigned char *s;

	d = (unsigned char*)dest;
	s = (unsigned char*)src;
	if (dest == src)
		return (dest);
	else if(dest < src)
		dest = ft_memcpy(d, s, n);
	else
	{
		while (n--)
			d[n] = s[n];
	}
	return (dest);
}
