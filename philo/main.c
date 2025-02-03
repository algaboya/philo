/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:28:06 by algaboya          #+#    #+#             */
/*   Updated: 2025/02/03 16:35:40 by algaboya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (!valid_input(argc, argv, &data))
		return (1);
	if (init_data(&data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (start_dinner(&data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	while (check_philo(&data))
		;
	if (!joining(&data))
		return (cleaning(&data));
	return (0);
}
