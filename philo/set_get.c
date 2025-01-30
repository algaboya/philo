/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 23:25:44 by algaboya          #+#    #+#             */
/*   Updated: 2025/01/30 12:45:14 by algaboya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	set_long(pthread_mutex_t *mtx, long *dest, long value)
// {
// 	mutex_ident(mtx, LOCK);
// 	*dest = value;
// 	mutex_ident(mtx, UNLOCK);
// }

size_t	get_val(pthread_mutex_t *mtx, size_t *value)
{
	size_t	res;

	mutex_ident(mtx, LOCK);
	res = *value;
	mutex_ident(mtx, UNLOCK);
	return (res);
}

// void	set_bool(pthread_mutex_t *mtx, bool *dest, bool value)
// {
// 	mutex_ident(mtx, LOCK);
// 	*dest = value;
// 	mutex_ident(mtx, UNLOCK);
// }

// bool	get_bool(pthread_mutex_t *mtx, bool *value)
// {
// 	bool	res;

// 	mutex_ident(mtx, LOCK);
// 	res = *value;
// 	mutex_ident(mtx, UNLOCK);
// 	return (res);
// }


// bool	sim_finished(t_data *data)
// {
// 	return (get_bool(&data->mtx, &data->end));
// }