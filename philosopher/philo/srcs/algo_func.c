#include "philosopher.h"

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
		if (hume[size].last_sleep - now > data->die)
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
			if (hume[size].loop < data.loop)
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

	print_txt(get_time_mili(), guy->id, str, guy->speak_right);
	time = sleep * 1000 / 200;
	rest = (sleep * 1000) % 200;

	while (time--)
	{
		ft_usleep(200);
		if (*(guy->is_end))
			return (1);
	}
	ft_usleep(rest);
	if (*(guy->is_end))
		return (1);
	return (0);
}

void	take_forch(t_sophe *guy, int id)
{
	if (id % 2)
		pthread_mutex_lock(guy->forch_left);
	else
		pthread_mutex_lock(guy->forch_right);
	print_txt(get_time_mili(), guy->id, "has taken a forch",
		   	&(guy->mini_data->speak_right));
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
	int	i = -1;

	guy = (t_sophe*)data;
	while (true)
	{
		printf("time %i\n", ++i);
		if (guy->mini_data->is_end)
			return (NULL);
		take_forch(guy, guy->id);
		if (guy->mini_data->is_end)
			return (NULL);
		take_forch(guy, guy->id + 1);
		if (sleep_and_check(guy->mini_data->eat, guy, "is eating"))
			return (NULL);
		pthread_mutex_unlock(guy->forch_left);
		pthread_mutex_unlock(guy->forch_right);
		if (sleep_and_check(guy->mini_data->sleep, guy, "is sleeping"))
			return (NULL);
		if (sleep_and_check(1, guy, "is thinking"))
			return (NULL);
	}
	return (NULL);
}

int		algo(t_data_philo *data)
{
	int					size;
	int					i;
	t_sophe				*la_boetie;

	size = data->size;
	la_boetie = data->tb;
	i = -1;
	while (++i < size)
	{
		pthread_create(la_boetie[i].th, NULL, routine_th, &one);
	}
	i = -1;
	while (++i < size)
		pthread_join(la_boetie[i].th[0], NULL);
	printf("%li %i died", get_time_mili(), data->one_death->id);
	while (size--)
		pthread_mutex_destroy(la_boetie[size].forch_left);
	return (0);
}
