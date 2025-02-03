/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 23:25:44 by algaboya          #+#    #+#             */
/*   Updated: 2025/02/03 16:44:35 by algaboya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_val(pthread_mutex_t *mtx, size_t *value)
{
	size_t	res;

	mutex_ident(mtx, LOCK);
	res = *value;
	mutex_ident(mtx, UNLOCK);
	return (res);
}

int	cleaning(t_data *data)
{
	if (!clean_philos(data))
		return (0);
	if (!clean_forks(data))
		return (0);
	if (mutex_ident(&data->ready_mtx, DESTROY) != EXIT_SUCCESS)
		return (0);
	if (mutex_ident(&data->time_mtx, DESTROY) != EXIT_SUCCESS)
		return (0);
	if (mutex_ident(&data->die_mtx, DESTROY) != EXIT_SUCCESS)
		return (0);
	if (mutex_ident(&data->get_mtx, DESTROY) != EXIT_SUCCESS)
		return (0);
	free(data->forks);
	free(data->philos);
	return (1);
}

int	clean_philos(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->nbr_of_philos)
	{
		if (mutex_ident(&data->philos[i].last_meal_mtx, DESTROY) != 0)
			return (0);
		if (mutex_ident(&data->philos[i].meal_count_mtx, DESTROY) != 0)
			return (0);
		if (mutex_ident(&data->philos[i].print_mtx, DESTROY) != 0)
			return (0);
		i++;
	}
	return (1);
}

int	clean_forks(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->nbr_of_philos)
	{
		if (mutex_ident(&data->forks[i], DESTROY) != EXIT_SUCCESS)
			return (0);
		i++;
	}
	return (1);
}

int	is_full(t_data *data)
{
	size_t	i;

	i = 0;
	if (data->must_eat <= 1)
		return (0);
	while (i < data->nbr_of_philos)
	{
		mutex_ident(&data->philos[i].meal_count_mtx, LOCK);
		if (data->philos[i].meal_count < data->must_eat)
		{
			mutex_ident(&data->philos[i].meal_count_mtx, UNLOCK);
			return (0);
		}
		mutex_ident(&data->philos[i].meal_count_mtx, UNLOCK);
		i++;
	}
	return (1);
}
