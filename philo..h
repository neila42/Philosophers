/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo..h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Probook <Probook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:10:31 by nmuminov          #+#    #+#             */
/*   Updated: 2023/06/21 16:44:05 by Probook          ###   ########.fr       */
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

typedef struct s_data {
	int nbr_philo; //meme nombre de baguettes
	int time_to_die; //en milisecondes (1000) fin du dernier repas + time to die = mort
	int time_to_eat;
	int time_to_sleep;
	//specifier le nombre de fois qu'il doit manger ? sinon fin de prog a la 1e mort
}			t_data;

#endif
