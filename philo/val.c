/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:07:53 by algaboya          #+#    #+#             */
/*   Updated: 2025/02/02 14:08:58 by algaboya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_atos(const char *str)
{
	int		i;
	size_t	result;

	i = 0;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

int	all_numbers(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (argc < 5 || argc > 6)
		return (0);
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	correct_input(int argc, char **argv, t_data *philo)
{
	if (!all_numbers(argc, argv))
	{
		printf("Incorrect input\n");
		return (0);
	}
	philo->nbr_of_philos = ft_atos(argv[1]);
	philo->time_to_die = ft_atos(argv[2]);
	philo->time_to_eat = ft_atos(argv[3]);
	philo->time_to_sleep = ft_atos(argv[4]);
	if (argc == 6)
		philo->must_eat = ft_atos(argv[5]);
	else
		philo->must_eat = -1;
	if (philo->nbr_of_philos < 1 || philo->time_to_die < 60
		|| philo->time_to_die > INT_MAX || philo->time_to_eat < 60
		|| philo->time_to_eat > INT_MAX || philo->time_to_sleep < 60
		|| philo->time_to_sleep > INT_MAX || philo->must_eat > INT_MAX
		|| (philo->must_eat < 1 && philo->must_eat != -1))
	{
		printf("Incorrect input\n");
		return (0);
	}
	return (1);
}