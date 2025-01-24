/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:29:44 by algaboya          #+#    #+#             */
/*   Updated: 2025/01/24 20:29:03 by algaboya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct pthread_mutex_t	t_mtx;
typedef struct s_data			t_data;

typedef enum s_mode
{
	LOCK,
	UNLOCK,
	CREATE,
	JOIN,
	CREATE,
}			t_mode;

typedef struct s_fork
{
	int		fork_id;
	t_mtx	fork;
}				t_fork;


typedef struct s_philo
{
	int		philo_id;
	bool	is_full;
	long	last_meal_time;
	t_fork	*first_fork;
	t_fork	*second_fork;
	int		tread_id;
	t_data	*data;
}				t_philo;

struct	s_data
{
	long	nmb_of_philos;
	long	philos;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	bool	philo_is_dead;
	t_fork	*forks;
	t_philo	*philos;
	int		start;
};

int		ft_strlen(const char *str);
void	ft_putstr_fd(char *s, int fd);
void	clean_exit(char *msg);
long	ft_atol(char *str);
long	valid_num(char *str);
void	init_data(t_data *t_data, int argc, char **argv);
void	check_malloc(void *smth);



#endif