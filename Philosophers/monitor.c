/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:06:50 by mdonmeze          #+#    #+#             */
/*   Updated: 2025/05/23 18:36:22 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_all_finished(t_philo *philos, t_rules *rules)
{
	int	i;
	int finished_count;

	if (rules->must_eat_count == -1)
		return (0);

	finished_count = 0;
	i = 0;
	while (i < rules->number_of_philosophers)
	{
		if (philos[i].eat_count >= rules->must_eat_count)
			finished_count++;
		i++;
	}
	return (finished_count == rules->number_of_philosophers);
}

void	*monitor_routine(void *arg)
{
	t_philo	*philos = (t_philo *)arg;
	t_rules	*rules = philos[0].rules;
	int		i;

	while (!rules->dead)
	{
		i = 0;
		while (i < rules->number_of_philosophers)
		{
			long	time_since_last_meal = get_time() - philos[i].last_meal;
			if (time_since_last_meal > rules->time_to_die)
			{
				pthread_mutex_lock(&rules->print_mutex);
				rules->dead = 1;
				printf("%ld %d died\n", get_time(), philos->id);
				pthread_mutex_unlock(&rules->print_mutex);
				return (NULL);
			}
			i++;
		}
	if (check_all_finished(philos, rules))
	{
		pthread_mutex_lock(&rules->print_mutex);
		rules->dead = 1;
		pthread_mutex_unlock(&rules->print_mutex);
		return (NULL);
	}
	my_sleep(1000);
	}
	return (NULL);
}

