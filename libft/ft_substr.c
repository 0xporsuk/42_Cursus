#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	char	*dest;

	dest = malloc(sizeof(char) * (len + 1));
	j = 0;
	while (j < len)
	{
		dest[j] = s[start];
		j++;
		start++;
	}
	dest[j] = '\0';
	return (dest);
}
