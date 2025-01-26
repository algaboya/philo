/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acting.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 02:37:06 by algaboya          #+#    #+#             */
/*   Updated: 2025/01/26 03:46:37 by algaboya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    eat(t_philo *philo)
{
    mutex_ident(&philo->first_fork->fork, LOCK);
	monitoring(philo, TAKEN_1st_FORK);
    mutex_ident(&philo->first_fork->fork, UNLOCK);
	monitoring(philo, TAKEN_2nd_FORK);
	set_long(&philo->philo_mtx, &philo->last_meal_time, get_time(MILLISECOND));
	monitoring(philo, EAT);
	usleep_helper(philo->data->time_to_eat, philo->data);
    mutex_ident(&philo->first_fork->fork, UNLOCK);
    mutex_ident(&philo->second_fork->fork, UNLOCK);
}

void    think(t_philo *philo)
{
	monitoring(philo, THINK);
}

void	monitoring(t_philo *philo, t_print_status status)
{
	long	current_time;

	current_time = get_time(MILLISECOND) - philo->data->start;
	if (philo->is_full == 1)
		return ;
	mutex_ident(&philo->data->print_mtx, LOCK);
    if ((status == TAKEN_1st_FORK || status == TAKEN_2nd_FORK)
        && !sim_finished(philo->data))
    	printf("%ld %d has taken a fork\n", current_time, philo->philo_id);
    else if (status == EAT && !sim_finished(philo->data))
    	printf("%ld %d is eating\n", current_time, philo->philo_id);
    else if (status == SLEEP && !sim_finished(philo->data))
		printf("%ld %d is sleeping\n", current_time, philo->philo_id);
    else if (status == THINK && !sim_finished(philo->data))
    	printf("%ld %d is thinking\n", current_time, philo->philo_id);
	else if (status == DIED)
	    printf("%ld %d died\n", current_time, philo->philo_id);
	mutex_ident(&philo->data->print_mtx, UNLOCK);
}

// void    print_debug(int status, t_philo, int current_time)
// {
    
    
// }

