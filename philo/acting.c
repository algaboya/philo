/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acting.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 02:37:06 by algaboya          #+#    #+#             */
/*   Updated: 2025/02/02 14:12:32 by algaboya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    eat(t_philo *philo)
{
    mutex_ident(philo->second_fork, LOCK);
	monitoring(philo, TAKEN_1st_FORK, 0);
    if (philo->data->nbr_of_philos == 1)
	{
		usleep_helper(get_val(&(philo->data->get_mtx), &(philo->data->time_to_die)),
			philo);
        mutex_ident(&philo->data->die_mtx, LOCK);
		philo->data->philo_is_dead = 1;
        mutex_ident(&philo->data->die_mtx, UNLOCK);
        mutex_ident(philo->second_fork, UNLOCK);
		return ;
	}
    mutex_ident(philo->first_fork, LOCK);
	monitoring(philo, TAKEN_1st_FORK, 0);
    mutex_ident(&philo->last_meal_mtx, LOCK);
	philo->last_meal_time = get_time();
    mutex_ident(&philo->last_meal_mtx, UNLOCK);
    mutex_ident(&philo->meal_count_mtx, LOCK);
    monitoring(philo, EAT, 0);
	philo->meal_count++;
    mutex_ident(&philo->meal_count_mtx, UNLOCK);
	usleep_helper(philo->data->time_to_eat, philo);
    mutex_ident(philo->second_fork, UNLOCK);
    mutex_ident(philo->first_fork, UNLOCK);
}

void	sleeping(t_philo *philo)
{
	if (get_val(&(philo->data->die_mtx), &(philo->data->philo_is_dead)))
		return ;
	monitoring(philo, SLEEP, 0);
    usleep_helper(philo->data->time_to_sleep, philo);
}

void    think(t_philo *philo)
{
    if (get_val(&(philo->data->die_mtx), &(philo->data->philo_is_dead)))
		return ;
	monitoring(philo, THINK, 0);
}

void	monitoring(t_philo *philo, t_print_status status, int end)
{
	long	current_time;

	current_time = get_time() - philo->data->start;
	// if (philo->is_full == 1)
	// 	return ;
	mutex_ident(&philo->print_mtx, LOCK);
    if (!get_val(&(philo->data->die_mtx), &(philo->data->philo_is_dead))
		|| end == 1)
    {
        if ((status == TAKEN_1st_FORK || status == TAKEN_2nd_FORK))
        	printf("%ld %d has taken a fork\n", current_time, philo->philo_id);
        else if (status == EAT)
    	    printf("%ld %d is eating\n", current_time, philo->philo_id);
        else if (status == SLEEP)
	    	printf("%ld %d is sleeping\n", current_time, philo->philo_id);
        else if (status == THINK)
        	printf("%ld %d is thinking\n", current_time, philo->philo_id);
    	else if (status == DIED)
	        printf("%ld %d died\n", current_time, philo->philo_id);
    }
    mutex_ident(&philo->print_mtx, UNLOCK);
}

int	is_full(t_data *data)
{
	size_t	i;

	i = 0;
	if (data->must_eat <= 1)
		return (0);
	while (i < data->nbr_of_philos)
	{
		mutex_ident(&data->philos[i].meal_count_mtx, LOCK);
		if (data->philos[i].meal_count < data->must_eat)
		{
			mutex_ident(&data->philos[i].meal_count_mtx, UNLOCK);
			return (0);
		}
		mutex_ident(&data->philos[i].meal_count_mtx, UNLOCK);
		i++;
	}
	return (1);
}