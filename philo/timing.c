/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 23:44:28 by algaboya          #+#    #+#             */
/*   Updated: 2025/01/26 04:54:21 by algaboya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_time()
{
	struct timeval	time_value;

	if (gettimeofday(&time_value, NULL))
		return (printf("Gettime error\n"), EXIT_FAILURE);
	return (time_value.tv_sec * 1000 + time_value.tv_usec / 1000);
}

// void	usleep_helper(long usec, t_data *data)
// {
// 	long	start;
// 	long	processing;
// 	long	remaining;

// 	start = get_time(MICROSECOND);
// 	while (get_time(MICROSECOND) - start < usec)
// 	{
// 		if (sim_finished(data))
// 			break ;
// 		processing = get_time(MICROSECOND) - start;
// 		remaining = usec - processing;
// 		if (remaining > 1e4)
// 			usleep(remaining / 2);
// 		else
// 			while (get_time(MICROSECOND) - start < usec)
// 				;
// 	}
// }