/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuminov <nmuminov@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:10:31 by nmuminov          #+#    #+#             */
/*   Updated: 2023/07/10 16:03:01 by nmuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	only_digits(int argc, char **argv)
{
	int	i;
	int	k;

	i = 1;
	k = 0;
	while (i < argc)
	{
		while (argv[i][k])
		{
			if (argv[i][k] <= '9' && argv[i][k] >= '0')
				k++;
			else
				return (1);
		}
		k = 0;
		i++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

int	fail(char *s)
{
	printf("%s\n", s);
	return (1);
}

void	check_usleep(t_data *data, unsigned long long time)
{
	unsigned long long	start_time;

	start_time = set_time();
	while (mutex_alive(&data->alive, NULL) == 1)
	{
		if (start_time + time <= set_time())
			return ;
		usleep(10);
	}
}

int	check_for_check(t_data *data)
{
	int	i;
	int	philo_ate_enough;

	i = 0;
	philo_ate_enough = 0;
	while (i < data->nbr_philo)
	{
		if (check_alive(&data->philo_tab[i], data) == 0)
		{
			free_philo(data);
			return (1);
		}
		if (get_value_int(&data->philo_tab[i].nbr_eat, NULL) 
			>= get_value_int(&data->nbr_must_eat, NULL)
			&& get_value_int(&data->nbr_must_eat, NULL) != -1)
			philo_ate_enough++;
		i++;
	}
	if (philo_ate_enough == data->nbr_philo)
		return (1);
	return (0);
}
