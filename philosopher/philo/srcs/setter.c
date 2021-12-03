/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <jbondri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:41:50 by jbondri           #+#    #+#             */
/*   Updated: 2021/12/03 13:44:45 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

long	set_last_eat(t_sophe *smith, long yop)
{
	pthread_mutex_lock(&(smith->last_eat_mtx));
	smith->last_eat = yop;
	pthread_mutex_unlock(&(smith->last_eat_mtx));
	return (yop);
}

long	set_loop(t_sophe *spinoza)
{
	int		response;

	pthread_mutex_lock(&(spinoza->loop_mtx));
	spinoza->loop += 1;
	response = spinoza->loop;
	pthread_mutex_unlock(&(spinoza->loop_mtx));
	return (response);
}

bool	set_is_end(t_mini_data *dt, bool yop)
{
	pthread_mutex_lock(&(dt->is_end_mtx));
	dt->is_end = yop;
	pthread_mutex_unlock(&(dt->is_end_mtx));
	return (yop);
}
