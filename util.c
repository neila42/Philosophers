/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Probook <Probook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:10:31 by nmuminov          #+#    #+#             */
/*   Updated: 2023/07/10 13:44:13 by Probook          ###   ########.fr       */
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

// unsigned long long	ft_atoull(const char *str)
// {
// 	unsigned long long	result;
// 	int					sign;

// 	result = 0;
// 	sign = 1;
// 	while (*str == ' ' || (*str >= 9 && *str <= 13))
// 		str++;
// 	if (*str == '+' || *str == '-')
// 	{
// 		if (*str == '-')
// 			sign *= -1;
// 		str++;
// 	}
// 	while (*str >= '0' && *str <= '9')
// 	{
// 		result = result * 10 + (*str - '0');
// 		str++;
// 	}
// 	return (result * sign);
// }

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
