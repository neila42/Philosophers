/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuminov <nmuminov@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:10:31 by nmuminov          #+#    #+#             */
/*   Updated: 2023/06/28 14:18:00 by nmuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/errno.h>
# include <pthread.h>

typedef struct s_data t_data;

typedef struct s_philo {

	int							id;
	pthread_mutex_t				fork;
	unsigned long long			last_meal;
	t_data						*data;
}			t_philo;

struct s_data {
	int						nbr_philo;
	t_philo					*philo_tab;
	int						time_to_eat;
	int						time_to_sleep;
	int						time_to_die;
	int						nbr_must_eat;
	int						alive;
	int						start_time;
}

#endif
