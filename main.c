/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuminov <nmuminov@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:10:31 by nmuminov          #+#    #+#             */
/*   Updated: 2023/06/29 11:40:32 by nmuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    take_forks(t_philo *philo) 
{
	int next_id;

	next_id = philo->id + 1;
	if (next_id >= philo->data->nbr_philo)
		next_id = 0;
	pthread_mutex_lock(&philo->data->philo_tab[philo->id].fork);
    philo_start(set_time(), &philo->data->philo_tab[philo->id], "The philo took a fork");
	pthread_mutex_lock(&philo->data->philo_tab[philo->id + 1].fork);
	philo_start(set_time(), &philo->data->philo_tab[philo->id + 1], "The philo took a second fork");
}

void    leave_forks(t_philo *philo)
{
	int next_id;

	next_id = philo->id + 1;
	if (next_id >= philo->data->nbr_philo)
      next_id = 0;
    pthread_mutex_unlock(&philo->data->philo_tab[philo->id].fork);
    philo_start(set_time(), &philo->data->philo_tab[philo->id], "The philo put the fork down");
	pthread_mutex_unlock(&philo->data->philo_tab[philo->id + 1].fork);
	philo_start(set_time(), &philo->data->philo_tab[philo->id + 1], "The philo put the fork down");
}

void    free_philo(t_philo *philo, t_data *data)
{
    int i;
    
    i = 0;
    while (i < data->nbr_philo)
    {
		pthread_mutex_destroy(&data->philo_tab[i].fork);
        free(&philo->data->philo_tab[philo->id]);
        i ++;
    }
	free(philo->data->philo_tab);
}

void	check_alive(t_philo *philo, t_data *data)
{
	while (&philo->data->philo_tab[philo->id] < data->nbr_philo)
	{
	if (set_time() - philo->last_meal <= data->time_to_die)
	{
		philo_start(set_time(), &philo->data->philo_tab[philo->id], "the philo died");
		free_philo(philo, data);
		data->alive = 0;
	}
	else
	data->alive = 1;
}

void    philo_eat(t_philo *philo, t_data *data)
{
	if (data->alive == 1)
	{
		philo_start(set_time(), "the philo is eating", philo);
	}
    philo->last_meal = set_time;
    leave_forks(philo);
    philo->nbr_must_eat --;
}

// void    philo_sleep(t_philo *philo)
// {
//     philo_start(set_time(), "the philo is sleeping", philo);   
// }

// void    philo_think(t_philo *philo)
// {
//     philo_start(set_time(), "the philo is thinking", philo);
// }

// int	philo_day(t_philo *philo)
// {
// 	while (philo->alive)
// 	{
		//eating
		//sleeping
		//thinking
// 	}
// }

void    philo_start(t_philo *philo, t_data *data, char *str)
{
	unsigned long long time;

	time = set_time() - data->start_time;
    printf("%llu %d %s\n", time, philo->id, str);
}

unsigned long long	set_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int fail(char *s)
{
    printf(s);
    return (1);
}

int	init_philo(t_data *data)
{
	pthread_t	thread;
	int			i;

	i = 0;
	data->philo_tab = malloc(data->nbr_philo * sizeof(t_philo));
	while (i < data->nbr_philo)
	{
		data->philo_tab[i].id ++;
		pthread_mutex_init(&data->philo_tab[i].fork, NULL);
		data->philo_tab[i].last_meal = set_time();
		if (pthread_create(&thread, NULL, philo_day, &data->philo_tab[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}

// int	main()
// {
// 	data->start_time = set_time();
//	data->alive = check_alive(philo, data);
// }