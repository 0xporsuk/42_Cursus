/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:02:08 by mdonmeze          #+#    #+#             */
/*   Updated: 2025/05/23 18:29:57 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void take_forks(t_philo *philo)
{
	if (philo->id % 2 == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork");
	}
}

void drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void *routine(void *arg)
{
	t_philo *philo = (t_philo *)arg;

	if (philo->id % 2 == 0)
		my_sleep(1000);

	while (!philo->rules->dead)
	{
		// 1. Çatal al
		take_forks(philo);

		//2. Yemek
		print_status(philo, "is eating");
		philo->last_meal = get_time();
		my_sleep(philo->rules->time_to_eat);
		philo->eat_count++;

		//3. Çatalları bırak
		drop_forks(philo);

		//4. Eğer yeterince yemek yediyse kontrol et
		if (philo->rules->must_eat_count != -1 &&
			philo->eat_count >= philo->rules->must_eat_count)
			break;

		//5. Uyuma
		print_status(philo, "is sleeping");
		my_sleep(philo->rules->time_to_sleep);

		//6. Düşünme
		print_status(philo, "is thinking");
	}
	return (NULL);
}

void	print_status(t_philo *philo, char *msg)
{
	long	time;

	pthread_mutex_lock(&philo->rules->print_mutex);
	time = get_time() - philo->rules->start_time;

	if (!philo->rules->dead)
		printf("%ld %d %s\n", time, philo->id, msg);
	pthread_mutex_unlock(&philo->rules->print_mutex);
}
