/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:28:06 by algaboya          #+#    #+#             */
/*   Updated: 2025/01/24 20:27:37 by algaboya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(t_data *t_data, int argc, char **argv)
{
	data->nbr_of_philos = valid_num(argv[1]);
	data->time_to_die = valid_num(argv[2]) * 1e3;
	data->time_to_eat = valid_num(argv[3]) * 1e3;
	data->time_to_sleep = valid_num(argv[4]) * 1e3;
	data->philos = malloc(sizeof(t_philo) data->nmb_of_philos);
	check_malloc(data->philos);
	if (data->time_to_eat < 6e4 || data->time_to_eat < 6e4
		|| data->time_to_sleep < 6e4)
		clean_exit("Parameter should be bigger than 60ms\n");
		
}

void	check_malloc(void *smth)
{
	if (!smth)
		clean_exit("Malloc error!");
}

void	start_philo(t_data *data, int argc, char **argv)
{
	init_data(data, argc, argv);
}

int	main(int argc, char **argv)
{

	t_data	*data;

	if (argc == 5 || argc == 6) // what if 6, but without bonus
	{
		start_philo(&data, argc, argv);
		clean(&data); //->philo is died || all are full  
	}
	clean_exit("Wrong input!!!\n");
}
