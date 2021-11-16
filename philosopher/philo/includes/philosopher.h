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
	long			last_sleep;
	pthread_t		*th;
	pthread_mutex_t	*forch_left;
	pthread_mutex_t	*forch_right;
}				t_sophe;

typedef struct	s_data_philo
{
	int				size;
	int				loop;
	int				sleep;
	int				eat;
	int				die;
	t_sophe			*tb;
}				t_data_philo;

int parser(int argc, char **argv, t_data_philo *data);
#endif
