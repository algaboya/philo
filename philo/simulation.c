/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:33:34 by algaboya          #+#    #+#             */
/*   Updated: 2025/01/26 04:53:19 by algaboya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	run_threads(t_data *data)
// {
// 	while (!if_threads_ready(&data->mtx, &data->theads_are_ready))
// 	{
// 		usleep(1000);
// 	}
// }

// void	*dinner_sim(void *data)
// {
// 	t_philo	*philo;

// 	philo = (t_philo *)data;
// 	// while (!if_threads_ready(&philo->data->mtx, &philo->data->theads_are_ready))
// 	// 	;
// 	printf("koko\n");
// 	run_threads(philo->data);
// 	while(!sim_finished(philo->data))
// 	{
// 		if (philo->is_full)
// 			break ;
// 		eat(philo);
// 		monitoring(philo, SLEEP);
// 		usleep_helper(philo->data->time_to_sleep, philo->data);
// 		think(philo);
// 	}
// 	return (0);
// }

// void	start_dinner(t_data *data)
// {
// 	int i;

// 	i = 0;
// 	// if (data->nbr_of_philos == 1)
// 	// 	thread_ident(&data->philo[0].thread_id, alone, &data->philo[0],
// 	// 		CREATE);
// 	// else
// 		while (i < data->nbr_of_philos)
// 		{
// 			thread_ident(&data->philos[i].thread_id, data,
// 			dinner_sim, CREATE);
// 			i++;
// 			printf("THREAD CREATED\n");
// 		}
// 	printf("olala\n");
// 	data->start = get_time(MILLISECOND);
// 	set_bool(&data->mtx, &data->theads_are_ready, 1);
// 	// thread_handle(&data->monitor, monitor_dinner, data, CREATE);

// 	i = 0;
// 	while (i < data->nbr_of_philos)
// 	{
// 		thread_ident(&data->philos[i].thread_id, NULL,
// 			NULL, JOIN);
// 		i++;
// 	}
// 	// thread_handle(&data-> , monitor_dinner, table, CREATE);

// }

// bool	if_threads_ready(pthread_mutex_t *mtx, bool *val)
// {
// 	bool	res;
// 	mutex_ident(mtx, LOCK);
// 	res = *val;
// 	mutex_ident(mtx, UNLOCK);
// 	printf("mutex_handled\n");
// 	return (res);
// }