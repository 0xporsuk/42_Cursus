/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:43:31 by mdonmeze          #+#    #+#             */
/*   Updated: 2024/10/24 20:08:58 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s_son;
	int		i;
	int		j;

	s_son = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s_son)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
		s_son[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		s_son[j++] = s2[i++];
	s_son[j] = '\0';
	return (s_son);
}
