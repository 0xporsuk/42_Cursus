#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	const char		*last;
	unsigned char	ch;

	last = NULL;
	ch = (unsigned char)c;
	while (*str != '\0')
	{
		if (*str == ch)
			last = str;
		str++;
	}
	if (ch == '\0')
		return ((char *)(str));
	return ((char *)last);
}
