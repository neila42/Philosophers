/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Probook <Probook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:10:31 by nmuminov          #+#    #+#             */
/*   Updated: 2023/06/27 15:09:09 by Probook          ###   ########.fr       */
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

typedef struct s_philo {
	int			nbr_philo;
	int			id;
	int			fork;
	int			time_to_eat;
	int			last_meal;
	int			time_to_sleep;
	int			time_to_die; 
	int			status;
	int			nbr_must_eat;
	
}			t_philo;


#endif

void pthread_exit(void *);