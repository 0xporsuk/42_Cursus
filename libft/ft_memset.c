#include "libft.h"

void	*ft_memset(void *dest, int c, size_t count)
{
	size_t i;
	unsigned char *ptr = (unsigned char *) dest;

	i = 0;
	while (i < count)
	{
		ptr[i] = (unsigned char) c;
		i++;
	}
	return dest;
}

int main()
{
	char dest[10] = "Merhaba";
	ft_memset(dest, '3', 10);
	printf("%s", dest);
}
