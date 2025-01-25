/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:28:06 by algaboya          #+#    #+#             */
/*   Updated: 2025/01/25 03:56:58 by algaboya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

	t_data	data;

	if (argc == 5 || argc == 6) // what if 6, but without bonus
	{
		start_philo(&data, argc, argv);
		// clean(&data); //->philo is died || all are full  
	}
	clean_exit("Wrong input!!!\n");
}
