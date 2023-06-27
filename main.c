/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Probook <Probook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:10:31 by nmuminov          #+#    #+#             */
/*   Updated: 2023/06/27 13:07:54 by Probook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int init_philo(t_philo *philo)
{
    int i;
    int philo_tab[NBR_PHILO];
    
    i = 0;
    while (i < NBR_PHILO)
    {
        philo_tab[i] = ft_calloc(sizeof(int), NBR_PHILO);
        if (philo_tab)
            return (NULL);
        if (pthread_create(&thread, NULL, philo_tab, &philo_tab) != 0)
			return (1);
		i++; 
    }
    return (0);
}

int	ph_init(t_philo *philos, char **av, int ac, int *stop)
{
	int	i;
	int	goal;

	goal = -1;
	if (ac == 6)
		goal = ft_atoi(av[5]);
	i = 0;
	while (i < ft_atoi(av[1]))
	{
		philos[i].ph_id = i + 1;
		philos[i].ph_status = 2;
		philos[i].ph_goal = goal;
		philos[i].ph_total = ft_atoi(av[1]);
		philos[i].fork = 1;
		philos[i].forks = 0;
		philos[i].stop = stop;
		philos[i].fork_m = malloc(sizeof(pthread_mutex_t));
		if (!philos[i].fork_m)
			return (1);
		pthread_mutex_init(philos[i].fork_m, NULL);
		i++;
	}
	return (0);
}

int	mutex_init(t_philo *philo, int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		philo->fork= malloc(sizeof(pthread_mutex_t));
		if (philo->fork == NULL)
			return (NULL);
		pthread_mutex_init(philo->fork, NULL);
		i++;
	}
	return (0);
}

set_time()
{
    gettimeofday(//time, NULL);
    return (//time * 1000);
}

void    philo_eat(t_philo *philo)
{
    philo->nbr_must_eat --;
}

int fail(char *s)
{
    printf(s);
    return (1);
}
