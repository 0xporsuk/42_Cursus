#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t i;
	size_t j;
	char *s1_d;
	size_t size;

	size = ft_strlen(s1);

	i = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		while(s1[i] != set[j] && set[j] != '\0')
		{
			j++;
		}
		if (s1[i] != set[j])
			break;
		i++;
	}
	while (size > 0)
	{
		j = 0;
		while(s1[size] != set[j] && set[j] != '\0')
		{
			j++;
		}
		if (s1[size] != set[j])
			break;
		size --;
	}
	int t_size = ft_strlen(s1) - (ft_strlen(s1) - size + i);
	s1_d = malloc(sizeof(char) * t_size);
	s1_d = (char *)(s1 + i);
	s1_d[t_size + 1] = '\0';
	return (s1_d);
}

