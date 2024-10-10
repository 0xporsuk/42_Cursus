#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	i;
	size_t	d_len;
	size_t	s_len;

	d_len = ft_strlen(dest);
	s_len = ft_strlen(src);

	if (destsize <= d_len)
		return (destsize + s_len);

	i = 0;
	while (src[i] && d_len + i + 1 < destsize)
	{
		dest[d_len + i] = src[i];
		i++;
	}
	dest[d_len + i] = '\0';

	return (d_len + s_len);
}
