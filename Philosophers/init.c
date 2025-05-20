#include "philo.h"

int init_all(t_rules *rules, t_philo **philos, int ac, char **av)
{
	if (ac != 5 && ac != 6)
	{
		printf("Error: Invalid number of arguments\n");
		return (1);
	}
	int i = 0;
	rules->number_of_philosophers = ft_atoi(av[1]);
	rules->time_to_die = ft_atoi(av[2]);
	rules->time_to_eat = ft_atoi(av[3]);
	rules->time_to_sleep = ft_atoi(av[4]);
	rules->must_eat_count = -1;
	if (ac == 6)
		rules->must_eat_count = ft_atoi(av[5]);
	if (rules->number_of_philosophers <= 0 || rules->time_to_die < 0 ||
		rules->time_to_eat < 0 || rules->time_to_sleep < 0 ||
		(ac == 6 && rules->must_eat_count <=0))
	{
		printf("Error: Invalid argument values\n");
		return (1);
	}

	rules->forks = malloc(sizeof(pthread_mutex_t) * rules->number_of_philosophers);
	if (!rules->forks)
		return (1);
	while (i < rules->number_of_philosophers)
	{
		if (pthread_mutex_init(&rules->forks[i], NULL) != 0)
			return (1);
		i++;
	}

	*philos = malloc(sizeof(t_philo) * rules->number_of_philosophers);
	if (!*philos)
		return (1);

	i = 0;
	while (i < rules->number_of_philosophers)
	{
		(*philos)[i].id = i + 1;
		(*philos)[i].eat_count = 0;
		(*philos)[i].last_meal = 0;
		(*philos)[i].rules = rules;
		(*philos)[i].left_fork = &rules->forks[i];
		(*philos)[i].right_fork = &rules->forks[(i + 1) % rules->number_of_philosophers];
		i++;
	}

	rules->start_time = get_time();
	rules->dead= 0;
	pthread_mutex_init(&rules->print_mutex, NULL);

	return (0);
}
