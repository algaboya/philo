/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:33:34 by algaboya          #+#    #+#             */
/*   Updated: 2025/01/30 13:54:55 by algaboya         ###   ########.fr       */
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

void	*dinner_sim(void *ptr)
{
	t_philo	*philo;

    philo = (t_philo *)ptr;
	while (!get_val(&(philo->data->ready_mtx), &philo->data->threads_are_ready))
		;
    if (philo->philo_id % 2 == 0)
		usleep_helper(get_val(&(philo->data->get_mtx), &(philo->data->time_to_eat)),
			philo);
	// run_threads(philo->data);
	while(!get_val(&(philo->data->die_mtx), &(philo->data->philo_is_dead)))
	{
		// if (philo->is_full)
		// 	break ;
		eat(philo);
	printf("koko\n");
        sleeping(philo);
		think(philo);
	}
	return (0);
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
		printf("THREAD CREATED\n");
	}
    printf("olala\n");
    mutex_ident(&data->ready_mtx, LOCK);
	data->start = get_time();
    data->threads_are_ready = true;
	pthread_mutex_unlock(&data->ready_mtx);
    return (EXIT_SUCCESS);
}

// bool	if_threads_ready(pthread_mutex_t *mtx, bool *val)
// {
// 	bool	res;
// 	mutex_ident(mtx, LOCK);
// 	res = *val;
// 	mutex_ident(mtx, UNLOCK);
// 	printf("mutex_handled\n");
// 	return (res);
// }