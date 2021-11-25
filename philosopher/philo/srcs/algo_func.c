#include "philosopher.h"

long	get_time_mili_prog(long time)
{
	long	get;

	get = get_time_mili();
	//printf("time = %li and get = %li\n", time, get);
	return ((get - time));
}

bool	check_death(t_data_philo *data)
{
	t_sophe		*hume;
	int			size;
	long		now;

	if (data->one_death)
		return (true);
	now = get_time_mili();
	hume = (data->tb);
	size = data->size;
	while (size--)
	{
		if (now - hume[size].last_eat > data->mini_data.die)
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
		usleep(25);
		current = get_time_mili();
	}
}

int		sleep_and_check(int sleep, t_sophe *marx, char *str, int know)
{
	long	rest;
	long	time;

	print_txt(get_time_mili_prog(marx->mini_data->start), marx->id, str, marx);
	if (marx->mini_data->is_end)
		return (1);
	if (know == EAT)
	{
		marx->last_eat = get_time_mili();
		marx->loop += 1;
	}
	time = sleep / 5;
	rest = sleep % 5;

	while (time--)
	{
		ft_usleep(5);
		if (marx->mini_data->is_end)
			return (1);
	}
	ft_usleep(rest);
		if (marx->mini_data->is_end)
			return (1);
	return (0);
}

void	take_forch(t_sophe *arendt, int id)
{
	if (arendt->mini_data->is_end)
		return ;
	if (id % 2)
		pthread_mutex_lock(arendt->forch_left);
	else
		pthread_mutex_lock(arendt->forch_right);
	if (arendt->mini_data->is_end)
	{
		pthread_mutex_unlock(arendt->forch_right);
		pthread_mutex_unlock(arendt->forch_left);
		return ;
	}
	print_txt(get_time_mili_prog(arendt->mini_data->start), arendt->id,
			CYN"has taken a forck"RESET, &(arendt->mini_data->speak_right));
}

void	print_txt(long time, int id, char *str, t_sophe *guy)
{
	pthread_mutex_lock(guy->mini_data->mtx);
	if (guy->mini_data->is_end)
		return ;
	printf("%li ms %i %s\n", time, id, str);
	pthread_mutex_unlock(guy->mini_data->mtx);
}

void	*routine_th(void *data)
{
	t_sophe		*kant;
	long		now;

	kant = (t_sophe*)data;
	while (true)
	{
		if (kant->mini_data->is_end)
			return (NULL);
		take_forch(kant, kant->id);
		take_forch(kant, kant->id + 1);
		if (kant->mini_data->is_end)
			return (NULL);
		now = get_time_mili();
		if (sleep_and_check(kant->mini_data->eat, kant, RED"is eating"RESET, EAT))
			return (NULL);
		kant->last_eat = now;
		pthread_mutex_unlock(kant->forch_left);
		pthread_mutex_unlock(kant->forch_right);
		if (sleep_and_check(kant->mini_data->sleep, kant, BLU"is sleeping"RESET, 0))
			return (NULL);
		if (sleep_and_check(0, kant, MAG"is thinking"RESET, 0))
			return (NULL);
	}
	return (NULL);
}

void	unlock_all_forch(int size, t_sophe *descartes)
{
	while (size--)
		pthread_mutex_unlock(descartes[size].forch_left);
}

void	*narrator(void *data)
{
	t_data_philo	*camus;

	camus = (t_data_philo*)data;
	while (true)
	{
		camus->mini_data.is_end = check_death(camus);
		if (camus->mini_data.is_end)
		{
			pthread_mutex_lock(&(camus->mini_data.speak_right));
			pthread_mutex_unlock(&(camus->mini_data.speak_right));
			unlock_all_forch(camus->size, (camus->tb));
			return (NULL);
		}
	}
}

int		algo(t_data_philo *data)
{
	int					size;
	int					i;
	static pthread_t	ah;
	t_sophe				*la_boetie;

	size = data->size;
	la_boetie = (data->tb);
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
		printf(GRN"All philosophers has eat %i times\n"RESET, data->loop);
	while (size--)
		pthread_mutex_destroy(la_boetie[size].forch_left);
	return (0);
}
