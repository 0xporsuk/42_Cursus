#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int i;

	if (i && f)
	{
		i = 0;
		while (s[i])
		{
			f(i, &s[i]);
			i++;
		}
	}
}
int main()
{
	char str[] = "merhaba";
	void *f;
	ft_striteri(str, f);
	printf("%s", str);
}
