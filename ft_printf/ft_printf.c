/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 23:01:53 by mdonmeze          #+#    #+#             */
/*   Updated: 2024/12/13 17:58:37 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdarg.h"

int	format(char c, va_list arg)
{
	int	i;
	unsigned long ptr;

	i = 0;
	if (c == 'c')
		i += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		i += ft_putstr(va_arg(arg, char *));
	else if (c == 'i')
		i += ft_putnbr(va_arg(arg, int));
	else if (c == 'd')
		i += ft_putnbr(va_arg(arg, int));
	else if (c == 'u')
		i += ft_unsint(va_arg(arg, unsigned int));
	else if (c == 'x')
		i += ft_hex(va_arg(arg, unsigned int), 0);
	else if (c == 'X')
		i += ft_hex(va_arg(arg, unsigned int), 1);
	else if (c == 'p')
	{
		ptr = va_arg(arg,unsigned int);
		if (ptr == 0)
			return (ft_putstr("(nil)"));
		i += ft_putstr("0x");
		i += ft_ptr(va_arg(arg, unsigned long), 0);
	}
	else
		i += ft_putchar('%');
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	arg;

	va_start(arg, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			while (str[i] == ' ' && str[i])
				i++;
			count += format(str[i], arg);
			i++;
		}
		else
		{
			count += ft_putchar(str[i]);
			i++;
		}
	}
	va_end(arg);
	return (count);
}