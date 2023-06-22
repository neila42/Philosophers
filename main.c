/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuminov <nmuminov@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:10:31 by nmuminov          #+#    #+#             */
/*   Updated: 2023/06/22 14:40:37 by nmuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

create_philo(t_philo *philo)
{
    while (philo->nbr_philo > 0)
    {
    philo->s = pthread_create(philo->thread, NULL, func, &arg);
    if (philo->s != 0)
        return (0);
    philo->nbr_philo --;
}

while (philo_nbr)

mutex_init()
{
    pthread_mutex_t mtx;
    
    mtx = PTHREAD_MUTEX_INITIALIZER;
    while (philo_nbr)
    {
        
    }

int main(int argc, char **argv)
{
    
}