/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 23:56:43 by algaboya          #+#    #+#             */
/*   Updated: 2025/02/02 14:21:03 by algaboya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mutex_ident(pthread_mutex_t *mtx, t_mode mode)
{
	if (mode == UNLOCK)
		return (mtx_error(pthread_mutex_unlock(mtx), UNLOCK));
	else if (mode == LOCK)
		return (mtx_error(pthread_mutex_lock(mtx), LOCK));
	else if (mode == DESTROY)
		return (mtx_error(pthread_mutex_destroy(mtx), DESTROY));
	else if (mode == INIT)
		return (mtx_error(pthread_mutex_init(mtx, NULL), INIT));
	else if (mode == DESTROY)
		return (mtx_error(pthread_mutex_destroy(mtx), DESTROY));
	else
		return (printf("Mutex can't be handled\n"));
}

int	mtx_error(int status, t_mode mode)
{
	(void)status;
	(void)mode;
	if (status == EINVAL && (mode == LOCK || mode == UNLOCK
			|| mode == INIT))
		return (printf("The value for mutex is invalid\n"), EXIT_FAILURE);
	else if (status == EPERM)
		return (printf("Operation not permitted\n"), EXIT_FAILURE);
	else if (status == EDEADLK)
		return (printf("Resource deadlock would occur\n"), EXIT_FAILURE);
	else if (status == ENOMEM)
		return (printf("The procces can't allocate enough \
			memory for creating another mutex\n"), EXIT_FAILURE);
	else if (status == EBUSY)
		return (printf("Device or resource is busy\n"), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	thread_ident(pthread_t *thread, t_data *data,
			void *(*abuba)(void *), t_mode mode)
{
	if (mode == CREATE)
		return (thread_error(pthread_create(thread, NULL, abuba, data),
				CREATE));
	else if (mode == JOIN)
		return (thread_error(pthread_join(*thread, NULL), JOIN));
	else if (mode == DETACH)
		return (thread_error(pthread_detach(*thread), DETACH));
	else
		return (printf("Tread can't be handled\n"), EXIT_FAILURE);
}

int	thread_error(int status, t_mode mode)
{
	if (status == EINVAL && (mode == LOCK || mode == UNLOCK
			|| mode == INIT))
		return (printf("The value for mutex is invalid\n"), EXIT_FAILURE);
	else if (status == EPERM)
		return (printf("Operation not permitted\n"), EXIT_FAILURE);
	else if (status == EDEADLK)
		return (printf("Resource deadlock would occur\n"), EXIT_FAILURE);
	else if (status == ENOMEM)
		return (printf("The procces can't allocate enough \
		memory for creating another mutex\n"), EXIT_FAILURE);
	else if (status == EBUSY)
		return (printf("Device or resource is busy\n"), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
