/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:33:34 by algaboya          #+#    #+#             */
/*   Updated: 2025/01/25 18:18:41 by algaboya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *dinner()

void    start_dinner(t_data *data)
{
    int i;

    i = 0;
    if (data->nbr_of_philos == 1)
    ;//cewd
    else
    {
        while (i < data->nbr_of_philos)
        {
            thread_ident(&data->philos[i].philo_id, &data->philos[i],
                dinner, CREATE);
            i++;
        } 
    }
    mtx_lock_unlock(&data->mtx, data);
}

void    mtx_lock_unlock(pthread_mutex_t *mtx, t_data *data)
{
    mutex_ident(mtx, LOCK);
    data->theads_are_ready = true;
    mutex_ident(mtx, UNLOCK);
}