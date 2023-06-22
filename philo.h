/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuminov <nmuminov@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:10:31 by nmuminov          #+#    #+#             */
/*   Updated: 2023/06/22 14:06:04 by nmuminov         ###   ########.fr       */
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
#include <pthread.h>

typedef struct s_philo {
	pthread_t	*thread;
	int			s;
	int			nbr_philo;
	int			time_to_eat;
	int			time_to_sleep;
	int			time_to_die; 
}			t_philo;

typedef struct s_mutex {
	
}			t_mutex

#endif

int gettimeofday()
void pthread_exit(void *retval);