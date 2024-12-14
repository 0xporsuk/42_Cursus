/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 23:02:03 by mdonmeze          #+#    #+#             */
/*   Updated: 2024/12/14 21:24:48 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int	ft_putchar(char c);
int	ft_putstr(char *c);
int	ft_putnbr(int c);
int	ft_unsint(unsigned int a);
int	ft_printf(const char *str, ...);
int	ft_hex(unsigned int h, int b);
int	ft_ptr(unsigned long h, int b);

#endif