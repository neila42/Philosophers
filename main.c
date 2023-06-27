/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Probook <Probook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:10:31 by nmuminov          #+#    #+#             */
/*   Updated: 2023/06/27 15:11:12 by Probook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int philo_day()
{
    
}

int philo_die(t_philo *philo)
{
    if (philo->time_to_die < philo->last_meal)
        philo_status(set_time(), "the philo died", philo)
}

void    philo_eat(t_philo *philo)
{
    philo->nbr_must_eat --;
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

void    philo_status(t_philo *philo, int time, char *str)
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
