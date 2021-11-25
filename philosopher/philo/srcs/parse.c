#include "philosopher.h"

long	ft_atoi_long(char *str)
{
	long	res;
	int		sign;

	sign = 1;
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-')
			sign = -1;
		str++;
	}
	str--;
	res = 0;
	while (*(++str) >= '0' && *str <= '9')
		res = 10 * res + *str - '0';
	return (res * sign);
}

bool	is_only_digit(char *str)
{
	--str;
	while (*(++str))
	{
		if (*str < '0' || *str > '9')
			return (false);
	}
	return (true);
}

long	get_time_mili(void)
{
	struct timeval current_time;
	
	gettimeofday(&current_time, NULL);	
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

bool	init_lst_philos(t_sophe **weil, int size, t_mini_data *yp)
{
	int			i;
	t_sophe		*alain;
	long		now;
	
	alain = *weil;
	i = -1;
	now = get_time_mili();
	alain[0].forch_left = malloc(sizeof(pthread_mutex_t) * 1);
	if (!alain[0].forch_left)
		return (true);
	pthread_mutex_init(alain[0].forch_left, NULL);
	while (++i < size)
	{
		alain[i].loop = 0;
		alain[i].id = i + 1;
		alain[i].mini_data = yp;
		alain[i].th = malloc(sizeof(pthread_t) * 1);
		if (!alain[i].th)
			return (true);
		alain[i].last_eat = now;
		if (i != 0)
			alain[i].forch_left = alain[i - 1].forch_right;
		if (i != size - 1)
		{
			alain[i].forch_right = malloc(sizeof(pthread_mutex_t) * 1);
			if (!alain[i].forch_right)
				return (true);
			pthread_mutex_init(alain[i].forch_right, NULL);
		}
	pthread_mutex_init(&(alain[0].loop_mtx), NULL);
	pthread_mutex_init(&(alain[0].last_eat_mtx), NULL);
	}
	alain[size - 1].forch_right = alain[0].forch_left;
	return (false);
}

int parser(int argc, char **argv, t_data_philo *data)
{
	int				i;
	long			res;
	static long		tb[5] = {};
	t_sophe			*platons;

	if (argc != 5 && argc != 6)
		return (1);
	i = 0;
	tb[4] = -1;
	while (argv[++i])
	{
		res = ft_atoi_long(argv[i]);
		if (!is_only_digit(argv[i]) || res > INT_MAX || res < 1)
			return (1);
		tb[i - 1] = res;
	}
	*data = (t_data_philo){.size = tb[0], .mini_data = {.die = tb[1],
		.eat = tb[2], .sleep = tb[3], .is_end = false}, .loop = (int)tb[4]};
	platons = malloc(sizeof(t_sophe) * data->size);
	pthread_mutex_init(&(data->mini_data.is_end_mtx), NULL);
	pthread_mutex_init(&(data->mini_data.speak_right), NULL);
	if (!platons || init_lst_philos(&platons, data->size, &(data->mini_data)))
		return (1);
	(data->tb) = platons;
	data->one_death = NULL;
	return (0);
}
