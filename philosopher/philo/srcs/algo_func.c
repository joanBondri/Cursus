#include "philosopher.h"

bool	get_last_eat(t_sophe *dt)
{
	long	yop;

	pthread_mutex_lock(&(dt->last_eat_mtx));
	yop = dt->last_eat;
	pthread_mutex_unlock(&(dt->last_eat_mtx));
	return (yop);
}

bool	set_last_eat(t_sophe *dt, long yop)
{
	pthread_mutex_lock(&(dt->last_eat_mtx));
	dt->last_eat = yop;
	pthread_mutex_unlock(&(dt->last_eat_mtx));
	return (yop);
}

bool	get_loop(t_sophe *dt)
{
	int		response;

	pthread_mutex_lock(&(dt->loop_mtx));
	response = dt->loop;
	pthread_mutex_unlock(&(dt->loop_mtx));
	return (response);
}

bool	set_loop(t_sophe *dt)
{
	int		response;

	pthread_mutex_lock(&(dt->loop_mtx));
	dt->loop += 1;
	response = dt->loop;
	pthread_mutex_unlock(&(dt->loop_mtx));
	return (response);
}

bool	get_is_end(t_mini_data *dt)
{
	bool	yop;

	pthread_mutex_lock(&(dt->is_end_mtx));
	yop = dt->is_end;
	pthread_mutex_unlock(&(dt->is_end_mtx));
	return (yop);
}

bool	set_is_end(t_mini_data *dt, bool yop)
{
	pthread_mutex_lock(&(dt->is_end_mtx));
	dt->is_end = yop;
	pthread_mutex_unlock(&(dt->is_end_mtx));
	return (yop);
}

long	get_time_mili_prog(long time)
{
	long	get;

	get = get_time_mili();
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
		if (now - get_last_eat(hume + size) > data->mini_data.die)
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
			if (get_loop(hume + size) < data->loop)
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
		usleep(100);
		current = get_time_mili();
	}
}

int		sleep_and_check(int sleep, t_sophe *marx, char *str, int know)
{
	long	rest;
	long	time;

	print_txt(get_time_mili_prog(marx->mini_data->start), marx->id, str, marx);
	if (get_is_end(marx->mini_data))
		return (1);
	if (know == EAT)
	{
		marx->last_eat = get_time_mili();
		set_loop(marx);
	}
	time = sleep / 5;
	rest = sleep % 5;

	while (time--)
	{
		ft_usleep(5);
	if (get_is_end(marx->mini_data))
		return (1);
	}
	ft_usleep(rest);
	if (get_is_end(marx->mini_data))
		return (1);
	return (0);
}

void	take_forch(t_sophe *arendt, int id)
{
	if (get_is_end(arendt->mini_data))
		return ;
	if (id % 2)
		pthread_mutex_lock(arendt->forch_left);
	else
		pthread_mutex_lock(arendt->forch_right);
	if (get_is_end(arendt->mini_data))
	{
		pthread_mutex_unlock(arendt->forch_right);
		pthread_mutex_unlock(arendt->forch_left);
		return ;
	}
	print_txt(get_time_mili_prog(arendt->mini_data->start), arendt->id,
			CYN"has taken a forck"RESET, arendt);
}

void	print_txt(long time, int id, char *str, t_sophe *guy)
{
	pthread_mutex_lock(&(guy->mini_data->speak_right));
	if (get_is_end(guy->mini_data))
		return ;
	printf("%li ms %i %s\n", time, id, str);
	pthread_mutex_unlock(&(guy->mini_data->speak_right));
}

void	*routine_th(void *data)
{
	t_sophe		*kant;
	long		now;

	kant = (t_sophe*)data;
	while (true)
	{
		if (get_is_end(kant->mini_data))
			return (NULL);
		take_forch(kant, kant->id);
		take_forch(kant, kant->id + 1);
		if (get_is_end(kant->mini_data))
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
	bool			yop;

	camus = (t_data_philo*)data;
	while (true)
	{
		yop = set_is_end(&(camus->mini_data), check_death(camus));
		if (yop)
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
