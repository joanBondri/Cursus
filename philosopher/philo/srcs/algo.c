/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <jbondri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:40:48 by jbondri           #+#    #+#             */
/*   Updated: 2021/12/03 14:48:04 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_usleep(int sleep)
{
	long	now;
	long	current;

	now = get_time_mili();
	current = now;
	while (now + sleep > current)
	{
		usleep(50);
		current = get_time_mili();
	}
}

void	print_txt(long time, int id, char *str, t_sophe *guy)
{
	pthread_mutex_lock(&(guy->mini_data->speak_right));
	if (get_is_end(guy->mini_data))
	{
		pthread_mutex_unlock(&(guy->mini_data->speak_right));
		return ;
	}
	printf("%li ms %i %s\n", time, id, str);
	pthread_mutex_unlock(&(guy->mini_data->speak_right));
}

int	algo(t_data_philo *data)
{
	int					i;
	static pthread_t	ah;
	t_sophe				*la_boetie;

	la_boetie = (data->tb);
	i = -1;
	data->mini_data.start = get_time_mili();
	while (++i < data->size)
		pthread_create(la_boetie[i].th, NULL, routine_th, la_boetie + i);
	pthread_create(&ah, NULL, narrator, data);
	pthread_join(ah, NULL);
	i = -1;
	while (++i < data->size)
		pthread_join(la_boetie[i].th[0], NULL);
	if (data->one_death)
	{
		printf(RED"%li ms %i died\n"RESET,
			get_time_mili_prog(data->mini_data.start), data->one_death->id);
	}
	else
		printf(GRN"All philosophers has eat %i times\n"RESET, data->loop);
	i = data->size;
	while (i--)
		pthread_mutex_destroy(la_boetie[i].forch_left);
	return (0);
}
