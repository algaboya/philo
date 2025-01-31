/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:33:34 by algaboya          #+#    #+#             */
/*   Updated: 2025/01/31 03:43:44 by algaboya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	run_threads(t_data *data)
// {
// 	while (!if_threads_ready(&data->mtx, &data->threads_are_ready))
// 	{
// 		usleep(1000);
// 	}
// }

// void	wait_for_all_philos(t_philo *philo)
// {
// 	while (!get_val(&(philo->data->ready_mtx), &philo->data->threads_are_ready))
// 		;
// }

void	*dinner_sim(void *ptr)
{
	t_philo	*philo;

    philo = (t_philo *)ptr;
	while (!get_val(&(philo->data->ready_mtx), &philo->data->threads_are_ready))
		;
		// wait_for_all_philos(philo);

    if (philo->philo_id % 2 == 0)
		usleep_helper(get_val(&(philo->data->get_mtx), &(philo->data->time_to_eat)),
			philo);
	// run_threads(philo->data);
	while(!get_val(&(philo->data->die_mtx), &(philo->data->philo_is_dead)))
	{
		// if (philo->is_full)
		// 	break ;
		eat(philo);
        sleeping(philo);
		think(philo);
	}
	return (ptr);
}

int	start_dinner(t_data *data)
{
	size_t i;

	i = 0;
	while (i < data->nbr_of_philos)
	{
		if (pthread_create(&data->philos[i].thread, NULL, &dinner_sim,
			&data->philos[i]) == -1)
            return (EXIT_FAILURE);
		i++;
	}
    mutex_ident(&data->ready_mtx, LOCK);
    data->threads_are_ready = 1;
	data->start = get_time();
	pthread_mutex_unlock(&data->ready_mtx);
    return (EXIT_SUCCESS);
}

int	check_philo(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->nbr_of_philos)
	{
		if (is_full(data))
		{
			if_dead(data);
			return (0);
		}
		mutex_ident(&data->time_mtx, LOCK);
		if (get_time() - get_val(&(data->philos[i].last_meal_mtx),
				&(data->philos[i].last_meal_time)) >= get_val(&(data->get_mtx),
				&(data->time_to_die)))
		{
			if_dead(data);
			monitoring(&data->philos[i], DIED, 1);
			mutex_ident(&data->time_mtx, UNLOCK);
			return (0);
		}
		mutex_ident(&data->time_mtx, UNLOCK);
		i++;
	}
	return (1);
}


void	if_dead(t_data *data)
{
	pthread_mutex_lock(&data->die_mtx);
	data->philo_is_dead = 1;
	pthread_mutex_unlock(&data->die_mtx);
}

int	joining(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->nbr_of_philos)
	{
		if (pthread_join(data->philos[i].thread, NULL) == -1)
			return (0);
		i++;
	}
	return (1);
}