/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:28:06 by algaboya          #+#    #+#             */
/*   Updated: 2025/01/26 04:41:37 by algaboya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	check_malloc(void *smth)
// {
// 	if (!smth)
// 		clean_exit("Malloc error!");
// }

// void	start_philo(t_data *data, char **argv)
// {
	// init_data(data, argv);
	// start_dinner(data);
// }

int	val_args(t_data *data, int argc, char **argv)
{
	if (argc == 5 || argc == 6)
	{
		data->nbr_of_philos = valid_num(argv[1]);
		data->time_to_die = valid_num(argv[2]);
		data->time_to_eat = valid_num(argv[3]);
		data->time_to_sleep = valid_num(argv[4]);
		if ((data->nbr_of_philos == 0 || data->nbr_of_philos > INT_MAX)
			|| (data->time_to_die < 60 || data->time_to_die > INT_MAX)
			|| (data->time_to_eat < 60 || data->time_to_eat > INT_MAX)
			|| (data->time_to_sleep < 60 || data->time_to_sleep > INT_MAX))
			return (printf("Parameter should be bigger than 60ms and less than INT_MAX.\n"), EXIT_FAILURE);
	}
	else
		return (printf("Input right args\n"), EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_data	data;
		
	if (val_args(&data, argc, argv) == EXIT_FAILURE)
	{
		return (VALID_ERROR);
	}
	if (init_data(&data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	// start_philo(&data, argv);
		// clean(&data); //->philo is died || all are full  
	// clean_exit("Wrong input!!!\n");
	return (0);
}
 