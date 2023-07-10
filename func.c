/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuminov <nmuminov@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:56:40 by Probook           #+#    #+#             */
/*   Updated: 2023/07/10 15:27:30 by nmuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_philo)
	{
		pthread_mutex_unlock(&data->philo_tab[i].fork);
		pthread_join(data->philo_tab[i].thread, NULL);
		pthread_mutex_destroy(&data->philo_tab[i].fork);
		i ++;
	}
	free(data->philo_tab);
}

void	philo_start(t_philo *philo, t_data *data, char *str)
{
	static pthread_mutex_t	mutex = PTHREAD_MUTEX_INITIALIZER;
	unsigned long long		time;

	pthread_mutex_lock(&mutex);
	time = set_time() - data->start_time;
	if (mutex_alive(&data->alive, NULL) == 1)
		printf("%llu %d %s\n", time, philo->id, str);
	pthread_mutex_unlock(&mutex);
}

unsigned long long	set_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	init_philo(t_data *data)
{
	int			i;

	i = 0;
	data->philo_tab = malloc(data->nbr_philo * sizeof(t_philo));
	if (data->philo_tab == NULL)
		return (1);
	while (i < data->nbr_philo)
	{
		data->philo_tab[i].id = i;
		pthread_mutex_init(&data->philo_tab[i].fork, NULL);
		data->philo_tab[i].last_meal = set_time();
		data->philo_tab[i].data = data;
		data->philo_tab[i].nbr_eat = 0;
		if (pthread_create(&data->philo_tab[i].thread, NULL, &philo_day,
				&data->philo_tab[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}

void	check(t_data *data)
{
	int	value;

	value = 0;
	while (mutex_alive(&data->alive, NULL) == 1)
	{
		if (check_for_check(data) == 1)
		{
			mutex_alive(&data->alive, &value);
			free_philo(data);
			return ;
		}
	}
}
