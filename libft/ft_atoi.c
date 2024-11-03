#include "libft.h"

int	ft_atoi(const char *str)
{
	int	count;
	int	i;
	int	sign;

	count = 0;
	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
	{
		i++;
	}
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		count = (count * 10) + (str[i] - 48);
		i++;
	}
	return (count * sign);
}
