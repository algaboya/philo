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

long	get_time(t_time_code time_code)
{
	struct timeval	time_value;

	if (gettimeofday(&time_value, NULL))
		clean_exit("Gettime error\n");
	printf("smth\n");
		
	if (time_code == SECOND)
		return (time_value.tv_sec + time_value.tv_usec / 1e6);
	else if (time_code == MICROSECOND)
		return (time_value.tv_sec * 1e6 + time_value.tv_usec);
	else if (time_code == MILLISECOND)
		return (time_value.tv_sec * 1e3 + time_value.tv_usec / 1e3);
	clean_exit("Wrong input for time\n");
	return (EXIT_FAILURE);
}

void	usleep_helper(long usec, t_data *data)
{
	long	start;
	long	processing;
	long	remaining;

	start = get_time(MICROSECOND);
	while (get_time(MICROSECOND) - start < usec)
	{
		if (sim_finished(data))
			break ;
		processing = get_time(MICROSECOND) - start;
		remaining = usec - processing;
		if (remaining > 1e4)
			usleep(remaining / 2);
		else
			while (get_time(MICROSECOND) - start < usec)
				;
	}
}