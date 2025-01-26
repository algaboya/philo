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

void	check_malloc(void *smth)
{
	if (!smth)
		clean_exit("Malloc error!");
}

void	start_philo(t_data *data, char **argv)
{
	init_data(data, argv);
	start_dinner(data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 5 || argc == 6) // what if 6, but without bonus
	{
		printf("ok\n");
		start_philo(&data, argv);
		// clean(&data); //->philo is died || all are full  
	}
	// clean_exit("Wrong input!!!\n");
}
