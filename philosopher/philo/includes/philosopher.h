/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <jbondri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:39:30 by jbondri           #+#    #+#             */
/*   Updated: 2021/12/03 14:46:16 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H
# include "ansicode.h"
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdbool.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# define EAT 5
# define ONE 1
# define FULL 2

typedef struct s_mini_data
{
	long			sleep;
	long			eat;
	long			die;
	pthread_mutex_t	is_end_mtx;
	bool			is_end;
	long			start;
	pthread_mutex_t	speak_right;
}				t_mini_data;

typedef struct s_sophe
{
	int				id;
	pthread_mutex_t	loop_mtx;
	int				loop;
	pthread_mutex_t	last_eat_mtx;
	long			last_eat;
	pthread_t		*th;
	t_mini_data		*mini_data;
	pthread_mutex_t	*forch_left;
	pthread_mutex_t	*forch_right;
}				t_sophe;

typedef struct s_data_philo
{
	t_sophe			*one_death;
	int				size;	
	int				loop;
	t_mini_data		mini_data;
	t_sophe			*tb;
}				t_data_philo;

bool	assign_philo(t_sophe *derida, int i, int size, long now);
void	ft_usleep(int sleep);
void	print_txt(long time, int id, char *str, t_sophe *guy);
int		algo(t_data_philo *data);
long	get_last_eat(t_sophe *hobbes);
long	get_loop(t_sophe *pascal);
bool	get_is_end(t_mini_data *dt);
long	get_time_mili_prog(long time);
long	get_time_mili(void);
void	print_error(void);
long	ft_atoi_long(char *str);
bool	is_only_digit(char *str);
bool	init_lst_philos(t_sophe **weil, int size, t_mini_data *yp);
int		parser(char **argv, t_data_philo *data);
bool	more_and_more_philosopher(t_sophe *kant);
void	*routine_th(void *data);
void	*narrator(void *data);
void	unlock_all(t_sophe *freud);
int		sleep_and_check(int sleep, t_sophe *marx, char *str, int know);
void	condition_forch(t_sophe *socrate, int id, int msg);
bool	check_death(t_data_philo *data);
bool	take_forch(t_sophe *arendt, int id, int msg);
long	set_last_eat(t_sophe *smith, long yop);
long	set_loop(t_sophe *spinoza);
bool	set_is_end(t_mini_data *dt, bool yop);

#endif
