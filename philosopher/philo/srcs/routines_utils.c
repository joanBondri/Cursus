/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <jbondri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:41:45 by jbondri           #+#    #+#             */
/*   Updated: 2021/12/03 14:30:51 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	unlock_all(t_sophe *freud)
{
	pthread_mutex_unlock(freud->forch_left);
	pthread_mutex_unlock(freud->forch_right);
}

int	sleep_and_check(int sleep, t_sophe *marx, char *str, int know)
{
	long	rest;
	long	time;

	print_txt(get_time_mili_prog(marx->mini_data->start), marx->id, str, marx);
	if (get_is_end(marx->mini_data))
		return (1);
	if (know == EAT)
	{
		set_last_eat(marx, get_time_mili());
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

void	condition_forch(t_sophe *socrate, int id, int msg)
{
	if (msg == ONE && id % 2)
		pthread_mutex_unlock(socrate->forch_left);
	else if (msg == ONE && id % 2 == 0)
		pthread_mutex_unlock(socrate->forch_right);
	else
	{
		pthread_mutex_unlock(socrate->forch_right);
		pthread_mutex_unlock(socrate->forch_left);
	}
}

bool	check_death(t_data_philo *data)
{
	t_sophe		*hume;
	int			size;
	long		now;

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
	if (data->loop < 1)
		return (false);
	size = data->size;
	while (size--)
	{
		if (get_loop(hume + size) < data->loop)
			return (false);
	}
	return (true);
}

bool	take_forch(t_sophe *arendt, int id, int msg)
{
	if (get_is_end(arendt->mini_data))
		return (false);
	while (arendt->forch_left == arendt->forch_right)
	{
		if (get_is_end(arendt->mini_data))
			return (true);
		usleep(10);
	}
	if (id % 2)
		pthread_mutex_lock(arendt->forch_left);
	else
		pthread_mutex_lock(arendt->forch_right);
	if (get_is_end(arendt->mini_data))
	{
		condition_forch(arendt, id, msg);
		return (true);
	}
	print_txt(get_time_mili_prog(arendt->mini_data->start), arendt->id,
		CYN"has taken a forck"RESET, arendt);
	return (false);
}
