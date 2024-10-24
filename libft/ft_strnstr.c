/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:43:47 by mdonmeze          #+#    #+#             */
/*   Updated: 2024/10/22 21:32:43 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	old_i;

	if (s2[0] == '\0')
		return ((char *)s1);
	i = 0;
	while (s1[i] != '\0' && i < len)
	{
		j = 0;
		if (s1[i] == s2[j])
		{
			old_i = i;
			while (s1[old_i] == s2[j] && s2[j] != '\0' && s1[old_i] != '\0'
				&& old_i < len)
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
