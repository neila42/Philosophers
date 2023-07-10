/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Probook <Probook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:10:31 by nmuminov          #+#    #+#             */
/*   Updated: 2023/07/10 12:52:54 by Probook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_alive(t_philo *philo, t_data *data)
{
	int	value;

	value = 1;
	mutex_alive(&data->alive, &value);
	if (set_time() - get_value_ull(&philo->last_meal, NULL)
		>= data->time_to_die)
	{
		philo_start(philo, data, "the philo died");
		value = 0;
		mutex_alive(&data->alive, &value);
	}
	return (mutex_alive(&data->alive, NULL));
}

void	philo_eat(t_philo *philo, t_data *data)
{
	int					nbr_eat;
	unsigned long long	value;

	if (mutex_alive(&data->alive, NULL) == 1)
	{
		take_forks(philo);
		philo_start(&data->philo_tab[philo->id], data, "The philo is eating");
		check_usleep(data, data->time_to_eat);
		leave_forks(philo);
		nbr_eat = get_value_int(&philo->nbr_eat, NULL) + 1;
		get_value_int(&philo->nbr_eat, &nbr_eat);
		value = set_time();
		get_value_ull(&philo->last_meal, &value);
	}
}

void	philo_sleep(t_philo *philo, t_data *data)
{
	if (mutex_alive(&data->alive, NULL) == 1)
	{
		philo_start(&data->philo_tab[philo->id], data, "The philo is sleeping");
		check_usleep(data, data->time_to_sleep);
	}
}

void	philo_think(t_philo *philo, t_data *data)
{
	if (mutex_alive(&data->alive, NULL) == 1)
		philo_start(&data->philo_tab[philo->id], data, "The philo is thinking");
}

void	*philo_day(void *raw)
{
	t_data	*data;
	t_philo	*philo;

	philo = (t_philo *)raw;
	data = philo->data;
	if (philo->id % 2)
		usleep(200);
	while (mutex_alive(&data->alive, NULL) == 1)
	{
		philo_eat(philo, data);
		philo_sleep(philo, data);
		philo_think(philo, data);
	}
	return (NULL);
}
