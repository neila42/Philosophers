/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuminov <nmuminov@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:10:31 by nmuminov          #+#    #+#             */
/*   Updated: 2023/07/10 16:04:48 by nmuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <string.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/errno.h>
# include <pthread.h>
# include <limits.h>

typedef struct s_data	t_data;

typedef struct s_philo {
	int							id;
	pthread_mutex_t				fork;
	unsigned long long			last_meal;
	int							nbr_eat;
	t_data						*data;
	pthread_t					thread;
}			t_philo;

struct s_data {
	int						nbr_philo;
	t_philo					*philo_tab;
	int						time_to_eat;
	int						time_to_sleep;
	unsigned long long		time_to_die;
	int						nbr_must_eat;
	int						alive;
	unsigned long long		start_time;
};

void				take_forks(t_philo *philo);
void				leave_forks(t_philo *philo);
void				free_philo(t_data *data);
int					check_alive(t_philo *philo, t_data *data);
void				philo_eat(t_philo *philo, t_data *data);
void				philo_sleep(t_philo *philo, t_data *data);
void				philo_think(t_philo *philo, t_data *data);
void				*philo_day(void *philo);
void				philo_start(t_philo *philo, t_data *data, char *str);
unsigned long long	set_time(void);
int					fail(char *s);
int					init_philo(t_data *data);
void				check(t_data *data);
int					only_digits(int argc, char **argv);
int					ft_atoi(const char *str);
int					check_acav(t_data *data, int argc, char **argv);
void				check_usleep(t_data *data, unsigned long long time);
unsigned long long	get_value_ull(unsigned long long *var,
						const unsigned long long *value);
int					get_value_int(int *var, const int *value);
int					mutex_alive(int *var, const int *value);
int					check_for_check(t_data *data);
size_t				ft_strlen(const char *s);
unsigned long long	ft_atoull(const char *str);

#endif
