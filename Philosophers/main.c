#include "philo.h"

int main(int ac, char **av)
{
	t_rules	rules;
	t_philo	*philos;
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
	pause();
}
