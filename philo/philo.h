/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:29:44 by algaboya          #+#    #+#             */
/*   Updated: 2025/01/30 13:40:58 by algaboya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# define VALID_ERROR 2


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

// typedef struct s_fork
// {
// 	int				fork_id;
// 	pthread_mutex_t	fork;
// }				t_fork;


typedef struct s_philo
{
	int					philo_id;    		//id
	size_t				last_meal_time;		//last_meal
	long				meal_count;			//num_eaten
	pthread_t			thread;
	pthread_mutex_t		*first_fork;		//right
	pthread_mutex_t		*second_fork;		//left
	pthread_mutex_t		meal_count_mtx;
	pthread_mutex_t		print_mtx;
	pthread_mutex_t		last_meal_mtx;
	t_data				*data;
}						t_philo;

struct	s_data
{
	size_t				start;
	size_t				end;
	size_t				nbr_of_philos;		//philo_nmb
	size_t				time_to_die;
	size_t				time_to_eat;
	size_t				time_to_sleep;
	size_t				philo_is_dead;		//dead_flag
	size_t				threads_are_ready;	//all_ready
	size_t				must_eat;
	pthread_mutex_t		print_mtx;
	pthread_mutex_t		time_mtx;
	pthread_mutex_t		die_mtx;
	pthread_mutex_t		get_mtx;
	pthread_mutex_t		ready_mtx;
	pthread_mutex_t		*forks;
	t_philo				*philos;
};


int		val_args(t_data *data, int argc, char **argv);
int		philo_init(t_data *data);
int		fork_init(t_data *data);
long	valid_num(char *str);
int		init_data(t_data *t_data);
int		mutex_ident(pthread_mutex_t *mtx, t_mode mode);
int		mtx_error(int status, t_mode mode);
int		thread_ident(pthread_t *thread,
			t_data *data, void *(*abuba)(void *),
			t_mode mode);
int		thread_error(int status, t_mode mode);
size_t	get_time();
void    eat(t_philo *philo);
void	sleeping(t_philo *philo);
void	monitoring(t_philo *philo, t_print_status status, int end);

int		start_dinner(t_data *data);
int		ft_strlen(const char *str);
void	ft_putstr_fd(char *s, int fd);
void	clean_exit(char *msg);
long	ft_atol(char *str);
void	check_malloc(void *smth);
void	run_threads(t_data *data);
void	set_long(pthread_mutex_t *mtx, long *dest, long value);
size_t	get_val(pthread_mutex_t *mtx, size_t *value);
void	set_bool(pthread_mutex_t *mtx, bool *dest, bool value);
bool	get_bool(pthread_mutex_t *mtx, bool *value);
void    think(t_philo *philo);
// long	get_time(t_time_code time_code);
void	usleep_helper(size_t usec, t_philo *philo);
bool	if_threads_ready(pthread_mutex_t *mtx, bool *val);
bool	sim_finished(t_data *data);
#endif