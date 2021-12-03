/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <jbondri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:41:36 by jbondri           #+#    #+#             */
/*   Updated: 2021/12/03 14:48:58 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

bool	more_and_more_philosopher(t_sophe *kant)
{
	if (get_is_end(kant->mini_data))
		return (true);
	if (take_forch(kant, kant->id, ONE))
		return (true);
	if (take_forch(kant, kant->id + 1, FULL))
		return (true);
	if (get_is_end(kant->mini_data))
	{
		unlock_all(kant);
		return (true);
	}
	if (sleep_and_check(kant->mini_data->eat, kant,
			RED"is eating"RESET, EAT))
	{
		unlock_all(kant);
		return (true);
	}
	pthread_mutex_unlock(kant->forch_left);
	pthread_mutex_unlock(kant->forch_right);
	if (sleep_and_check(kant->mini_data->sleep,
			kant, BLU"is sleeping"RESET, 0))
		return (true);
	print_txt(get_time_mili_prog(kant->mini_data->start),
		kant->id, "is thinking", kant);
	return (false);
}

void	*routine_th(void *data)
{
	t_sophe		*montaigne;

	montaigne = (t_sophe *)data;
	while (true)
	{
		if (more_and_more_philosopher(montaigne))
			return (NULL);
	}
	return (NULL);
}

void	*narrator(void *data)
{
	t_data_philo	*camus;
	bool			yop;

	camus = (t_data_philo *)data;
	while (true)
	{
		yop = check_death(camus);
		if (yop)
		{
			set_is_end(&(camus->mini_data), yop);
			pthread_mutex_lock(&(camus->mini_data.speak_right));
			pthread_mutex_unlock(&(camus->mini_data.speak_right));
			return (NULL);
		}
	}
}
