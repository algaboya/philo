/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:37:59 by algaboya          #+#    #+#             */
/*   Updated: 2025/02/02 14:36:35 by algaboya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
		i++;
	return (i);
}

long	ft_atol(char *str)
{
	int		sign;
	long	num;
	size_t	i;

	i = 0;
	sign = 1;
	num = 0;
	if (!str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * sign);
}

long	valid_num(char *str)
{
	int		i;
	long	res;

	i = 0;
	if (!str)
		return (EXIT_FAILURE);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	if (!str[i] || str[i] == '-')
		return (printf("Need a positive number\n"), EXIT_FAILURE);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (printf("Input a number\n"), EXIT_FAILURE);
		i++;
	}
	if (ft_strlen(str) > 10)
		return (printf("Need a number less than your input\n"),
			EXIT_FAILURE);
	res = ft_atol(str);
	return (res);
}

// void	ft_putstr_fd(char *s, int fd)
// {
// 	int	i;

// 	i = 0;
// 	if (!s)
// 		return ;
// 	while (s[i] != '\0')
// 	{
// 		write(fd, &s[i], 1);
// 		i++;
// 	}
// }

// void	clean_exit(char *msg)
// {
// 	ft_putstr_fd(msg, 2);
// 	exit(EXIT_FAILURE);
// }
