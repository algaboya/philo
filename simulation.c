/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:33:34 by algaboya          #+#    #+#             */
/*   Updated: 2025/01/25 21:35:26 by algaboya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	run_threads(t_data *data)
{
	while (!if_threads_ready(data->mtx, &data->theads_are_ready))
		;
}

void	*dinner_sim(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	run_threads(philo->data);
	
}

void	start_dinner(t_data *data)
{
	int i;

	i = 0;
	if (data->nbr_of_philos == 1)
	;//cewd
	else
	{
		while (i < data->nbr_of_philos)
		{
			thread_ident(&data->philos[i].philo_id, dinner_sim,
				&data->philos[i], CREATE);
			i++;
		}
	}
	mtx_lock_unlock(&data->mtx, data);
}

// void	mtx_lock_unlock(pthread_mutex_t *mtx, t_data *data)
// {
// 	mutex_ident(mtx, LOCK);
// 	data->theads_are_ready = true;
// 	mutex_ident(mtx, UNLOCK);
// }


bool	if_threads_ready(pthread_mutex_t *mtx, bool *val)
{
	bool	res;
	mutex_ident(mtx, LOCK);
	res = *val;
	mutex_ident(mtx, UNLOCK);
	return (res);
}