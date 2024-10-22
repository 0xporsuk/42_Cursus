#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	old_i;

	i = 0;
	j = 0;
	while (s1[i] != '\0' && i < len)
	{
		j = 0;
		if (s1[i] == s2[j])
		{
			old_i = i;
			while (s1[old_i] == s2[j] && s2[j] != '\0' && s1[old_i] != '\0')
			{
				j++;
				old_i++;
			}
			if (s2[j] == '\0')
				return ((char *)(&s1[old_i - j]));
		}
		i++;
	}
	return (NULL);
}
