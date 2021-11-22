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

typedef struct	s_sophe
{
	int				id;
	int				loop;
	bool			*is_end;
	long			last_sleep;
	pthread_t		*th;
	pthread_mutex_t	*speak_right;
	pthread_mutex_t	*forch_left;
	pthread_mutex_t	*forch_right;
}				t_sophe;

typedef struct	s_data_philo
{
	t_sophe			*one_death;
	int				size;
	int				loop;
	int				sleep;
	int				eat;
	int				die;
	t_sophe			*tb;
	bool			is_end;
	pthread_mutex_t	speak_right;
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
