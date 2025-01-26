/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:29:44 by algaboya          #+#    #+#             */
/*   Updated: 2025/01/26 04:36:25 by algaboya         ###   ########.fr       */
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
# include <errno.h>

typedef struct pthread_mutex_t	t_mtx;
typedef struct s_data			t_data;

//enum e_opcode

typedef enum s_mode
{
	LOCK,
	UNLOCK,
	CREATE,
	DESTROY,
	INIT,
	JOIN,
	DETACH,
}			t_mode;

typedef enum e_time_code
{
	SECOND,
	MILLISECOND,
	MICROSECOND,
}			t_time_code;

typedef enum e_print_status
{
	EAT,
	SLEEP,
	THINK,
	TAKEN_1st_FORK,
	TAKEN_2nd_FORK,
	DIED,
}	t_print_status;

typedef struct s_fork
{
	int				fork_id;
	pthread_mutex_t	fork;
}				t_fork;


typedef struct s_philo
{
	int				philo_id;
	bool			is_full;
	long			last_meal_time;
	t_fork			*first_fork;
	t_fork			*second_fork;
	pthread_t		thread_id;
	t_data			*data;
	pthread_mutex_t	philo_mtx;
}				t_philo;

struct	s_data
{
	int				start;
	bool				end;
	long			nbr_of_philos;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	bool			philo_is_dead;
	bool			theads_are_ready;
	t_fork			*forks;
	t_philo			*philos;
	pthread_mutex_t	mtx;
	pthread_mutex_t	print_mtx;

};

void	start_philo(t_data *data, char **argv);
int		ft_strlen(const char *str);
void	ft_putstr_fd(char *s, int fd);
void	clean_exit(char *msg);
long	ft_atol(char *str);
long	valid_num(char *str);
void	init_data(t_data *t_data, char **argv);
void	check_malloc(void *smth);
void	mutex_ident(pthread_mutex_t *mtx, t_mode mode);
void	mtx_error(int status, t_mode mode);
void	thread_ident(pthread_t *thread,
			t_data *data, void *(*abuba)(void *),
			t_mode mode);
void	thread_error(int status, t_mode mode);
void	philo_init(t_data *data);
void	fork_init(t_data *data);
void	start_dinner(t_data *data);
void	run_threads(t_data *data);
void	set_long(pthread_mutex_t *mtx, long *dest, long value);
long	get_long(pthread_mutex_t *mtx, long *value);
void	set_bool(pthread_mutex_t *mtx, bool *dest, bool value);
bool	get_bool(pthread_mutex_t *mtx, bool *value);
long	get_time(t_time_code time_code);
void	usleep_helper(long usec, t_data *data);
void	monitoring(t_philo *philo, t_print_status status);
void    eat(t_philo *philo);
void    think(t_philo *philo);
bool	if_threads_ready(pthread_mutex_t *mtx, bool *val);
bool	sim_finished(t_data *data);
#endif