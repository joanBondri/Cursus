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
	return (false);
}

int		sleep_and_check(int sleep, t_data_philo *data, t_sophe *guy, char *str)
{
	int		rest;
	int		time;

	print_txt(get_time_mili(), guy->id, str, &(data->speak_right));
	time = sleep / 10;
	rest = sleep % 10;

	while (time--)
	{
		usleep(10);
		if (check_death(data))
			return (1);
	}
	usleep(rest);
	if (check_death(data))
		return (1);
	return (0);
}

void	take_forch(t_sophe *guy, t_data_philo *data, int id)
{
	if (id % 2)
		pthread_mutex_lock(guy->forch_left);
	else
		pthread_mutex_lock(guy->forch_right);
	print_txt(get_time_mili(), guy->id, "has taken a forch",
		   	&(data->speak_right));
}

void	print_txt(long time, int id, char *str, pthread_mutex_t *mtx)
{
	pthread_mutex_lock(mtx);
	printf("%li ms %i %s\n", time, id, str);
	pthread_mutex_unlock(mtx);
}

void	*routine_th(void *data)
{
	t_data_and_philo	*one;
	int	i = -1;

	one = (t_data_and_philo*)data;
	while (true)
	{
		printf("time %i\n", ++i);
		if (check_death(one->data))
			return (NULL);
		take_forch(one->guy, one->data, one->guy->id);
		if (check_death(one->data))
			return (NULL);
		take_forch(one->guy, one->data, one->guy->id + 1);
		if (sleep_and_check(one->data->eat, one->data, one->guy, "is eating"))
			return (NULL);
		pthread_mutex_unlock(one->guy->forch_left);
		pthread_mutex_unlock(one->guy->forch_right);
		if (sleep_and_check(one->data->sleep, one->data, one->guy, "is sleeping"))
			return (NULL);
		if (sleep_and_check(1, one->data, one->guy, "is thinking"))
			return (NULL);
	}
	return (NULL);
}

int		algo(t_data_philo *data)
{
	int					size;
	int					i;
	t_sophe				*la_boetie;
	t_data_and_philo	one;

	size = data->size;
	la_boetie = data->tb;
	i = -1;
	while (++i < size)
	{
		one.data = data;
		one.guy = la_boetie + i;
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
