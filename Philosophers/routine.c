#include "philo.h"

void *routine(void *arg)
{
	t_philo *philo = (t_philo *)arg;

	printf("Philosopher %d is alive ✅\n", philo->id);
	return (NULL);

	while (philo->rules->dead)
	{
		// 1. Çatal al
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork");

		pthread_mutex_lock(philo->right_fork);
		print_status(philo, "has taken a fork");

		//2. Yemek
		print_status(philo, "is eating");
		philo->last_meal = get_time();
		my_sleep(philo->rules->time_to_eat);
		philo->eat_count++;

		//3. Çatalları bırak
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);

		//4. Uyuma
		print_status(philo, "is sleeping");
		my_sleep(philo->rules->time_to_sleep);

		//5. Düşünme
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
