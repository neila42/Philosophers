/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Probook <Probook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:10:31 by nmuminov          #+#    #+#             */
/*   Updated: 2023/06/28 10:41:55 by Probook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    take_forks(t_philo *philo) //probleme je dois prendre la fourchtte suivante 
{
    pthread_mutex_lock(philo->fork);
    while (philo->fork < 2)
    {
        philo_start(set_time(), "The philo took a fork", philo);
        philo->fork++;
    }
}

void    leave_forks(t_philo *philo)
{
    while (philo->fork > 0)
    {
        pthread_mutex_unlock(philo->fork);
        philo_start(set_time(), "The philo put the fork down", philo);
        philo->fork--;
    }
}

int philo_day()
{
    
}

void    free()
{
    free les philo et les mutexes
}

void    philo_die(t_philo *philo)
{
    if (philo->time_to_die < philo->last_meal)
        philo_start(set_time(), "the philo died", philo);
}

void    philo_eat(t_philo *philo)
{
    philo_start(set_time(), "the philo is eating", philo);
    philo->last_meal = set_time;
    leave_forks(philo);
    philo->nbr_must_eat --;
}

void    philo_sleep(t_philo *philo)
{
    philo_start(set_time(), "the philo is sleeping", philo);   
}

void    philo_think(t_philo *philo)
{
    philo_start(set_time(), "the philo is thinking", philo);
}

int init_philo(t_philo *philo)
{
    pthread_t thread;
    int i;
    int philo_tab[philo->nbr_philo];
    
    i = 0;
    while (philo->nbr_philo >= 2)
    {
        philo_tab[i] = malloc(sizeof(t_philo));
        if (philo_tab[i] = NULL)
            return (NULL);
        if (pthread_create(&thread, NULL, philo_day, &philo_tab) != 0)
			return (1);
        philo->fork= malloc(sizeof(pthread_mutex_t));
		if (philo->fork == NULL)
			return (NULL);
		pthread_mutex_init(philo->fork, NULL);
		i++; 
    }
    return (0);
}

void    philo_start(t_philo *philo, int time, char *str)
{
    printf("%d %d %s\n", time, philo->id, str);
}

set_time()
{
    gettimeofday(//time, NULL);
    return (//time * 1000);
}

int fail(char *s)
{
    printf(s);
    return (1);
}
