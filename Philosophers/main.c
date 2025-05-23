/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:01:57 by mdonmeze          #+#    #+#             */
/*   Updated: 2025/05/23 17:59:09 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int clear_all(t_rules rules, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < rules.number_of_philosophers)
	{
		pthread_mutex_destroy(&rules.forks[i]);
		i++;
	}
	pthread_mutex_destroy(&rules.print_mutex);
	free(rules.forks);
	free(philos);
	return (0);
}

int main(int ac, char **av)
{
	t_rules	rules;
	t_philo	*philos;
	pthread_t monitor;
	int		i;

	if (init_all(&rules, &philos, ac, av) != 0)
		return (1);

	i = 0;
	while (i < rules.number_of_philosophers)
	{
		if (pthread_create(&philos[i].thread_id, NULL, routine, &philos[i]) != 0)
		{
			printf("Error: Failed to create thread for philosopher %d\n", i + 1);
			return (1);
		}
		i++;
	}
	if (pthread_create(&monitor, NULL, monitor_routine, philos) != 0)
	{
		printf("Error: Failed to create monitor thread\n");
		return (1);
	}
	pthread_join(monitor, NULL);

	i = 0;
	while (i < rules.number_of_philosophers)
	{
		pthread_join(philos[i].thread_id, NULL);
		i++;
	}

	clear_all(rules, philos);
	return (0);
}
