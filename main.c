/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Probook <Probook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:10:31 by nmuminov          #+#    #+#             */
/*   Updated: 2023/07/04 10:55:09 by Probook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_acav(t_data *data, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (fail("to many or not enough arg"));
	else if (argv[1] == 0)
		return (fail("no philo"));
	else if (only_digits(argc, argv))
		return (fail("not only digits"));
	data->nbr_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->nbr_must_eat = ft_atoi(argv[5]);
	else
		data->nbr_must_eat = -1;
	if (data->time_to_die <= 0 || data->time_to_eat <= 0 || data->time_to_sleep <= 0)
		return (fail("arg equal to zero"));
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (check_acav(&data, argc, argv))
		return (1);
	data.start_time = set_time();
	data.alive = 1;
	if (init_philo(&data) != 0)
		return (fail("failed init philo tab"));
	check(&data);
	return (0);
}
