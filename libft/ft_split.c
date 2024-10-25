/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:43:19 by mdonmeze          #+#    #+#             */
/*   Updated: 2024/10/25 21:37:08 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

// static char	**ft_cleaner(char **d, int j)
// {
// 	int i;

// 	i = 0;
// 	while (i < j)
// 	{
// 		free(d[i]);
// 		i++;
// 	}
// 	free(d);
// 	return (NULL);
// }

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	int		j;
	int		start;

	arr = malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	if (!arr)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break ;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		arr[j++] = ft_substr(s, start, i - start);
		// // if (!arr[j])
		// 	return (ft_cleaner(arr, j));
	}
	arr[j] = NULL;
	return (arr);
}
// int main()
// {
// 	char **dest = ft_split("hello.world.merhaba.dunya", '.');

// 	int i = 0;
// 	while (i < 4)
// 	{
// 		printf("%s\n", dest[i++]);
// 	}

// }
