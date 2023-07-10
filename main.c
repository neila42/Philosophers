/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuminov <nmuminov@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:10:31 by nmuminov          #+#    #+#             */
/*   Updated: 2023/07/10 16:05:50 by nmuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_acav(t_data *data, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (fail("to many or not enough arg"));
	else if (ft_atoi(argv[1]) == 0)
		return (fail("no philo"));
	else if (only_digits(argc, argv))
		return (fail("not only digits"));
	else if (ft_strlen(argv[2]) > 10 && ft_atoull(argv[2]) > INT_MAX)
		return (fail("invalid arg"));
	data->nbr_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->nbr_must_eat = ft_atoi(argv[5]);
	else
		data->nbr_must_eat = -1;
	if (data->time_to_die <= 0 || data->time_to_eat <= 0
		|| data->time_to_sleep <= 0)
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
