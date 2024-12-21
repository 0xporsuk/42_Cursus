/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fnc_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhammetdonmezer <muhammetdonmezer@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 02:59:48 by mdonmeze          #+#    #+#             */
/*   Updated: 2024/12/21 18:59:22 by muhammetdon      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstr(char *c)
{
	int	i;

	i = 0;
	if (!c)
	{
		i = ft_putstr("(null)");
		return (6);
	}
	while (c[i])
	{
		ft_putchar(c[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr(int c)
{
	int	i;

	i = 0;
	if (c == -2147483648)
		i += ft_putstr("-2147483648");
	else if (c < 0)
	{
		i += ft_putchar('-');
		i += ft_putnbr(c * (-1));
	}
	else if (c > 9)
	{
		i += ft_putnbr(c / 10);
		i += ft_putnbr(c % 10);
	}
	else if (c <= 9)
	{
		i += ft_putchar(c + 48);
	}
	return (i);
}
