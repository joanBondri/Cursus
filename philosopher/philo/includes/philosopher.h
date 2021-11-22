#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdbool.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef struct	s_mini_data
{
	int				sleep;
	int				eat;
	int				die;
	bool			is_end;
	pthread_mutex_t	speak_right;
}				t_mini_data;

typedef struct	s_sophe
{
	int				id;
	int				loop;
	long			last_sleep;
	pthread_t		*th;
	t_mini_data		*mini_data;
	pthread_mutex_t	*forch_left;
	pthread_mutex_t	*forch_right;
}				t_sophe;

typedef struct	s_data_philo
{
	t_sophe			*one_death;
	int				size;
	int				loop;
	t_mini_data		mini_data;
	t_sophe			*tb;
}				t_data_philo;

typedef struct	s_data_and_philo
{
	t_sophe			*guy;
	t_data_philo	*data;
}				t_data_and_philo;

int parser(int argc, char **argv, t_data_philo *data);
void	print_txt(long time, int id, char *str, pthread_mutex_t *mtx);
long	get_time_mili(void);
int		algo(t_data_philo *data);

#endif
