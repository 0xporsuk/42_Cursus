#include "libft.h"


size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t	srcsize;
	size_t	index;

	srcsize = ft_strlen(src);
	index = 0;
	if (destsize != 0)
	{
		while (src[index] != '\0' && index < (destsize - 1))
		{
			dest[index] = src[index];
			index++;
		}
		dest[index] = '\0';
	}
	return (srcsize);
}
