/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Probook <Probook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:56:40 by Probook           #+#    #+#             */
/*   Updated: 2023/07/04 10:56:04 by Probook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_philo)
	{
		pthread_join(data->philo_tab[i].thread, NULL);
		pthread_mutex_destroy(&data->philo_tab[i].fork);
		i ++;
	}
	free(data->philo_tab);
}

int 	get_value_int(int *var, const int *value)
{
	static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
	int res;

	pthread_mutex_lock(&mutex);
	if (value != NULL)
		*var = *value;
	res = *var;
	pthread_mutex_unlock(&mutex);
	return (res);
}


unsigned long long	get_value_ull(unsigned long long *var, const unsigned long long *value)
{
	static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
	unsigned long long res;

	pthread_mutex_lock(&mutex);
	if (value != NULL)
		*var = *value;
	res = *var;
	pthread_mutex_unlock(&mutex);
	return (res);
}


void	philo_start(t_philo *philo, t_data *data, char *str)
{
	unsigned long long	time;

	time = set_time() - data->start_time;
	if (get_value_int(&data->alive, NULL) == 1)
		printf("%llu %d %s\n", time, philo->id, str);
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
		if (pthread_create(&data->philo_tab[i].thread, NULL, &philo_day,
				&data->philo_tab[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}

void	check(t_data *data)
{
	int		i;
	int		philo_ate_enough;

	while (data->alive == 1)
	{
		i = 0;
		philo_ate_enough = 0;
		while (i < data->nbr_philo)
		{
			if (check_alive(&data->philo_tab[i], data) == 0)
			{
				philo_start(&data->philo_tab[i], data, "the philo died");
				data->alive = 0;
				free_philo(data);
				return ;
			}
			if (data->philo_tab[i].nbr_eat == data->nbr_must_eat
				&& data->nbr_must_eat != -1)
				philo_ate_enough++;
			i++;
		}
		if (philo_ate_enough == data->nbr_philo)
		{
			free_philo(data);
			data->alive = 0;
			return ;
		}
	}
}
