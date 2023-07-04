/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Probook <Probook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:10:31 by nmuminov          #+#    #+#             */
/*   Updated: 2023/07/04 10:30:46 by Probook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo)
{
	int	next_id;

	next_id = philo->id + 1;
	if (next_id >= philo->data->nbr_philo)
		next_id = 0;
	pthread_mutex_lock(&philo->fork);
	philo_start(philo, philo->data,
		"The philo took a fork");
	pthread_mutex_lock(&philo->data->philo_tab[next_id].fork);
	philo_start(philo, philo->data,
		"The philo took a second fork");
}

void	leave_forks(t_philo *philo)
{
	int	next_id;

	next_id = philo->id + 1;
	if (next_id >= philo->data->nbr_philo)
		next_id = 0;
	pthread_mutex_unlock(&philo->fork);
	philo_start(philo, philo->data,
		"The philo put the fork down");
	pthread_mutex_unlock(&philo->data->philo_tab[next_id].fork);
	philo_start(philo, philo->data,
		"The philo put the fork down");
}
