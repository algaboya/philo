/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 23:56:43 by algaboya          #+#    #+#             */
/*   Updated: 2025/01/25 21:11:40 by algaboya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutex_ident(pthread_mutex_t *mtx, t_mode mode)
{
	if (mode == UNLOCK)
		mtx_error(pthread_mutex_unlock(mtx), UNLOCK);
	else if (mode == LOCK)
		mtx_error(pthread_mutex_lock(mtx), LOCK);
	else if (mode == DESTROY)
		mtx_error(pthread_mutex_destroy(mtx), DESTROY);
	else if (mode == INIT)
		mtx_error(pthread_mutex_init(mtx, NULL), INIT);
	else if (mode == DESTROY)
		mtx_error(pthread_mutex_destroy(mtx), DESTROY);
	else
		clean_exit("Mutex can't be handled\n");
}

void	mtx_error(int status, t_mode mode)
{
	if (status == 0)
		return ;
	if (status == EINVAL && (mode == LOCK || mode == UNLOCK
			|| mode == INIT))
		clean_exit("The value for mutex is invalid\n");
	else if (status == EPERM)
		clean_exit("Operation not permitted\n");
	else if (status == EDEADLK)
		clean_exit("Resource deadlock would occur\n");
	else if (status == ENOMEM)
		clean_exit("The procces can't allocate enough \
			memory for creating another mutex\n");
	else if (status == EBUSY)
		clean_exit("Device or resource is busy\n");
}

void	thread_ident(pthread_t *thread, t_data *data,
			void *(*abuba)(void *), t_mode mode)
{
	if (mode == CREATE)
		thread_error(pthread_create(thread, NULL, abuba, data), CREATE);
	else if (mode == JOIN)
		thread_error(pthread_join(*thread, NULL), JOIN);
	else if (mode == DETACH)
		thread_error(pthread_detach(*thread), DETACH);
	else
		clean_exit("Tread can't be handled\n");
}

void	thread_error(int status, t_mode mode)
{
	if (status == 0)
		return ;
	if (status == EINVAL && (mode == LOCK || mode == UNLOCK
			|| mode == INIT))
		clean_exit("The value for mutex is invalid\n");
	else if (status == EPERM)
		clean_exit("Operation not permitted\n");
	else if (status == EDEADLK)
		clean_exit("Resource deadlock would occur\n");
	else if (status == ENOMEM)
		clean_exit("The procces can't allocate enough \
		memory for creating another mutex\n");
	else if (status == EBUSY)
		clean_exit("Device or resource is busy\n");
}