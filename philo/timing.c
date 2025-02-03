/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 23:44:28 by algaboya          #+#    #+#             */
/*   Updated: 2025/02/03 18:38:58 by algaboya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_time(void)
{
	struct timeval	time_value;

	if (gettimeofday(&time_value, NULL))
		return (printf("Gettime error\n"), 0);
	return (time_value.tv_sec * 1000 + time_value.tv_usec / 1000);
}

void	usleep_helper(size_t usec, t_philo *philo)
{
	size_t	start;

	start = get_time();
	while (get_time() - start < usec
		&& !get_val(&(philo->data->die_mtx), &(philo->data->philo_is_dead)))
		usleep(500);
}
