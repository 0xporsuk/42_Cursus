#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		i;
	int		len;
	char	*dest;

	i = 0;
	len = ft_strlen(str);
	dest = (char *)malloc((len + 1) * sizeof(char));
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
