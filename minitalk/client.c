/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:31:16 by mdonmeze          #+#    #+#             */
/*   Updated: 2025/03/09 00:10:43 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_flag = 0;

void	flag_handler(int sig)
{
	(void)sig;
	if (sig == SIGUSR1)
		g_flag = 1;
}

void	send_signal(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (!g_flag)
			;
		g_flag = 0;
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*message;

	if (argc != 3)
	{
		ft_putstr("Error: wrong format.\n");
		ft_putstr("Try: ./client <PID> <message>\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (kill(pid, 0) == -1 || pid <= 0)
	{
		ft_putstr("Error: invalid PID.\n");
		return (1);
	}
	signal(SIGUSR1, flag_handler);
	message = argv[2];
	while (*message)
		send_signal(pid, *message++);
	send_signal(pid, '\0');
	return (0);
}
