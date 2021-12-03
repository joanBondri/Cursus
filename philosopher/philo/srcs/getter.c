/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <jbondri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:40:55 by jbondri           #+#    #+#             */
/*   Updated: 2021/12/03 14:17:48 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

long	get_last_eat(t_sophe *hobbes)
{
	long	yop;

	pthread_mutex_lock(&(hobbes->last_eat_mtx));
	yop = hobbes->last_eat;
	pthread_mutex_unlock(&(hobbes->last_eat_mtx));
	return (yop);
}

long	get_loop(t_sophe *pascal)
{
	int		response;

	pthread_mutex_lock(&(pascal->loop_mtx));
	response = pascal->loop;
	pthread_mutex_unlock(&(pascal->loop_mtx));
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

long	get_time_mili_prog(long time)
{
	long	get;

	get = get_time_mili();
	return ((get - time));
}

long	get_time_mili(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}
