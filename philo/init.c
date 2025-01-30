/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 23:54:11 by algaboya          #+#    #+#             */
/*   Updated: 2025/01/30 13:50:41 by algaboya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_data(t_data *data)
{
    data->start = 0;
    data->threads_are_ready = false;
    data->philo_is_dead = false;
	data->philos = (t_philo *)malloc(sizeof(t_philo) * data->nbr_of_philos);
    data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data->nbr_of_philos);
    if (!data->philos || !data->forks)
        return (printf("Malloc Error\n"), EXIT_FAILURE);
    if (mutex_ident(&data->ready_mtx, INIT) != EXIT_SUCCESS
        || mutex_ident(&data->time_mtx, INIT) != EXIT_SUCCESS
        || mutex_ident(&data->die_mtx, INIT) != EXIT_SUCCESS
        || mutex_ident(&data->get_mtx, INIT) != EXIT_SUCCESS)
    {
        printf("Inited\n");
       return (EXIT_FAILURE);
    }
	if (fork_init(data) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    if (philo_init(data) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    data->philo_is_dead = 0;
	data->threads_are_ready = 0;
	data->start = get_time();
    printf("Inited\n");
    return (EXIT_SUCCESS);
}

int    fork_init(t_data *data)
{
    size_t i;
    
    i = 0;
    while (i < data->nbr_of_philos)
    {
        if (mutex_ident(&data->forks[i], INIT) != 0)
            return (EXIT_FAILURE);
        i++;
    }
    return (EXIT_SUCCESS);
}

int    philo_init(t_data *data)
{
    size_t     i;
    
    i = 0;
    while (i < data->nbr_of_philos)
    {
        data->philos[i].meal_count = 0;
        data->philos[i].philo_id = i + 1;
		data->philos[i].second_fork = &data->forks[i];
        data->philos[i].last_meal_time = get_time();
        data->philos[i].first_fork = &data->forks[(i + 1) % data->nbr_of_philos];
        if (i == 0)
			data->philos[i].first_fork = &data->forks[data->nbr_of_philos - 1];
		else
			data->philos[i].second_fork = &data->forks[i - 1];
        // if (philo->philo_id % 2 == 0)
        // {
        //     data->philos[i].first_fork = &data->forks[i];
        //     philo->second_fork = &data->forks[(i + 1) % data->nbr_of_philos];   
        // }
        // else
	    // {
	    // 	philo->first_fork = &data->forks[(i + 1) % data->nbr_of_philos];
	    // 	philo->second_fork = &data->forks[i];
	    // }
        if (mutex_ident(&data->philos[i].last_meal_mtx, INIT) != 0)
			return (0);
        if (mutex_ident(&data->philos[i].meal_count_mtx, INIT) != 0)
			return (0);
        if (mutex_ident(&data->philos[i].print_mtx, INIT) != 0)
			return (0);
		data->philos[i].data = data;
        i++;
    }
    printf("Philo Initialization complete.\n");
    return (EXIT_SUCCESS);
}
