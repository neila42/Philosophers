/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuminov <nmuminov@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:10:31 by nmuminov          #+#    #+#             */
/*   Updated: 2023/07/03 16:11:13 by nmuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_acav(t_data *data, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		fail("to many or not enough arg");
	else if (argv[1] == 0)
		fail("no philo");
	else if (only_digits(argc, argv))
		fail("not only digits");
	data->nbr_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->nbr_must_eat = ft_atoi(argv[5]);
	else
		data->nbr_must_eat = -1;
}

int	main(int argc, char **argv)
{
    t_data data;
    t_data philo;

	check_acav(&data, argc, argv);
	init_philo(&data);
    data.start_time = set_time();
	data.alive = 1;
	check(&data);
    philo_day(&philo);
    return (0);
}
