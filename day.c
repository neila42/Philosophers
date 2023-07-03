/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuminov <nmuminov@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:10:31 by nmuminov          #+#    #+#             */
/*   Updated: 2023/07/03 16:07:09 by nmuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_alive(t_philo *philo, t_data *data)
{
	data->alive = 1;
	if (set_time() - philo->last_meal <= data->time_to_die)
	{
		philo_start( philo, data, "the philo died");
		data->alive = 0;
	}
	return (data->alive);
}

void    philo_eat(t_philo *philo, t_data *data)
{
	if (data->alive == 1)
	{
		take_forks(philo);
		philo_start(&data->philo_tab[philo->id], data, "the philo is eating");
		usleep(data->time_to_eat);
		philo->last_meal = set_time();
		leave_forks(philo);
	}
    data->nbr_must_eat --;
}

void    philo_sleep(t_philo *philo, t_data *data)
{
	if (data->alive == 1)
        philo_start(&data->philo_tab[philo->id], data, "the philo is sleeping");
		usleep(data->time_to_sleep);
}

void    philo_think(t_philo *philo, t_data *data)
{
    if (data->alive == 1)
        philo_start(&data->philo_tab[philo->id], data, "the philo is thinking");
		usleep(data->time_to_eat);
}

void	*philo_day(void *raw)
{
	t_philo *philo;
	t_data	*data;

	philo = (t_philo *)raw;
	data = philo->data;
	while (data->alive == 1)
	{
		philo_eat(philo, data);
		philo_sleep(philo, data);
		philo_think(philo, data);
	}
	return (0);
}
