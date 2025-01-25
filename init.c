/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 23:54:11 by algaboya          #+#    #+#             */
/*   Updated: 2025/01/25 18:13:17 by algaboya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(t_data *data, char **argv)
{
    data->start = false;
    data->theads_are_ready = false;
	data->nbr_of_philos = valid_num(argv[1]);
	data->time_to_die = valid_num(argv[2]) * 1e3;
	data->time_to_eat = valid_num(argv[3]) * 1e3;
	data->time_to_sleep = valid_num(argv[4]) * 1e3;
	data->philos = malloc(sizeof(t_philo) * data->nbr_of_philos);
	check_malloc(data->philos);
    data->forks = malloc(sizeof(t_fork) * data->nbr_of_philos);
	check_malloc(data->forks);
	if (data->time_to_eat < 6e4 || data->time_to_eat < 6e4
		|| data->time_to_sleep < 6e4)
		clean_exit("Parameter should be bigger than 60ms\n");
    mutex_ident(data->mtx, INIT);
	fork_init(data);
    philo_init(data);
    printf("Data Initialization complete.\n");
}

void    fork_init(t_data *data)
{
    int i;
    
    i = 0;
    while (i < data->nbr_of_philos)
    {
        mutex_ident(&data->forks[i].fork, INIT);
        data->forks[i].fork_id = i;
        i++;
    }
}

void    philo_init(t_data *data)
{
    int     i;
    // int     philo_count;
    t_philo *philo;
    
    i = 0;
    // philo_count = data->nbr_of_philos;
    while (i < data->nbr_of_philos)
    {
        philo = data->philos;
        philo->philo_id = i + 1;
        philo->is_full = false;
        data->philos = philo;
        philo->first_fork = &data->forks[(i + 1) % data->nbr_of_philos];
        philo->second_fork = &data->forks[i];
        if (philo->philo_id % 2 == 0)
        {
            philo->first_fork = &data->forks[i];
            philo->second_fork = &data->forks[(i + 1) % data->nbr_of_philos];   
        }
        i++;
    }
    printf("Philo Initialization complete.\n");
    

    // while (i < data->nbr_of_philos)
    // {
    //     data->philos[i].philo_id = i + 1;
    //     data->philos[i].is_full = false;
    //     data->philos[i].data = data; // Link philosopher back to `data`
        
    //     // Assign forks
    //     data->philos[i].first_fork = &data->forks[i];
    //     data->philos[i].second_fork = &data->forks[(i + 1) % data->nbr_of_philos];

    //     // Alternate fork order for even philosophers to prevent deadlocks
    //     if (data->philos[i].philo_id % 2 == 0)
    //     {
    //         data->philos[i].first_fork = &data->forks[(i + 1) % data->nbr_of_philos];
    //         data->philos[i].second_fork = &data->forks[i];
    //     }
    //     i++;
    // }
}
