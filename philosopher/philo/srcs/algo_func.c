#include "philosopher.h"

long	get_time_mili_prog(long time)
{
	return ((get_time_mili() - time) / 10);
}

bool	check_death(t_data_philo *data)
{
	t_sophe		*hume;
	int			size;
	long		now;

	if (data->one_death)
		return (true);
	now = get_time_mili();
	hume = data->tb;
	size = data->size;
	while (size--)
	{
		printf("");
		if (hume[size].last_sleep - now > data->mini_data.die)
		{
			data->one_death = hume + size;
			return (true);
		}
	}
	if (data->loop > 0)
	{
		size = data->size;
		while (size--)
		{
			if (hume[size].loop < data->loop)
				return (false);
		}
		return (true);
	}
	return (false);
}

void	ft_usleep(int sleep)
{
	long	now;
	long	current;

	now = get_time_mili();
	current = now;
	while (now + sleep > current)
	{
		usleep(10);
		current = get_time_mili();
	}
}

int		sleep_and_check(int sleep, t_sophe *guy, char *str)
{
	int		rest;
	int		time;

	print_txt(get_time_mili_prog(guy->mini_data->start), guy->id, str, &(guy->mini_data->speak_right));
	time = sleep * 1000 / 200;
	rest = (sleep * 1000) % 200;

	while (time--)
	{
		ft_usleep(200);
		if (guy->mini_data->is_end)
			return (1);
	}
	ft_usleep(rest);
		if (guy->mini_data->is_end)
			return (1);
	return (0);
}

void	take_forch(t_sophe *guy, int id)
{
	if (guy->mini_data->is_end)
		return ;
	if (id % 2)
		pthread_mutex_lock(guy->forch_left);
	else
		pthread_mutex_lock(guy->forch_right);
	if (guy->mini_data->is_end)
	{
		pthread_mutex_unlock(guy->forch_right);
		pthread_mutex_unlock(guy->forch_left);
		return ;
	}
	print_txt(get_time_mili_prog(guy->mini_data->start), guy->id,
			CYN"has taken a forch"RESET, &(guy->mini_data->speak_right));
}

void	print_txt(long time, int id, char *str, pthread_mutex_t *mtx)
{
	pthread_mutex_lock(mtx);
	printf("%li ms %i %s\n", time, id, str);
	pthread_mutex_unlock(mtx);
}

void	*routine_th(void *data)
{
	t_sophe		*guy;

	guy = (t_sophe*)data;
	while (true)
	{
		if (guy->mini_data->is_end)
			return (NULL);
		take_forch(guy, guy->id);
		take_forch(guy, guy->id + 1);
		if (guy->mini_data->is_end)
			return (NULL);
		if (sleep_and_check(guy->mini_data->eat, guy, RED"is eating"RESET))
			return (NULL);
		pthread_mutex_unlock(guy->forch_left);
		pthread_mutex_unlock(guy->forch_right);
		if (sleep_and_check(guy->mini_data->sleep, guy, BLU"is sleeping"RESET))
			return (NULL);
		if (sleep_and_check(0, guy, MAG"is thinking"RESET))
			return (NULL);
	}
	return (NULL);
}

void	unlock_all_forch(int size, t_sophe *tb)
{
	while (size--)
		pthread_mutex_unlock(tb[size].forch_left);
}

void	*narrator(void *data)
{
	t_data_philo	*yop;

	yop = (t_data_philo*)data;
	while (true)
	{
		yop->mini_data.is_end = check_death(yop);
		if (yop->mini_data.is_end)
		{
			unlock_all_forch(yop->size, yop->tb);
			return (NULL);
		}
	}
}

void	free_all_stuffs(t_data_philo **data)
{
	//free(*(data)->tb);
	free(*data);
}

int		algo(t_data_philo *data)
{
	int					size;
	int					i;
	static pthread_t	ah;
	t_sophe				*la_boetie;

	size = data->size;
	la_boetie = data->tb;
	i = -1;
	data->mini_data.start = get_time_mili();
	while (++i < size)
		pthread_create(la_boetie[i].th, NULL, routine_th, la_boetie + i);
	pthread_create(&ah, NULL, narrator, data);
	pthread_join(ah, NULL);
	i = -1;
	while (++i < size)
		pthread_join(la_boetie[i].th[0], NULL);
	if (data->one_death)
		printf(RED"%li ms %i died\n"RESET, get_time_mili_prog(data->mini_data.start), data->one_death->id);
	else
		printf(GRN"All philosophers eats enought\n"RESET);
	while (size--)
		pthread_mutex_destroy(la_boetie[size].forch_left);
	free_all_stuffs(&data);
	return (0);
}
