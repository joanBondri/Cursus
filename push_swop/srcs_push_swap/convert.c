/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 19:55:29 by jbondri           #+#    #+#             */
/*   Updated: 2021/09/11 19:56:57 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_min_in_tb(int *tb, t_list *a)
{
	static int	index = 1;
	t_list		*buff;
	int			i;
	int			min;

	min = INT_MAX;
	buff = a;
	i = -1;
	while (buff)
	{
		++i;
		if (*((int *)buff->content) < min && tb[i] == 0)
			min = *((int *)buff->content);
		buff = buff->next;
	}
	i = 0;
	buff = a;
	while (buff && ++i)
	{
		if (*((int *)buff->content) == min)
			break ;
		buff = buff->next;
	}
	tb[i - 1] = index;
	index++;
}

void	convert_to_index(t_list **a)
{
	int			i;
	t_list		*buff;
	int			*tb;
	int			size;

	size = ft_lstsize(*a);
	tb = (int *)ft_malloc(sizeof(int) * (size + 1));
	i = -1;
	while (++i <= size)
		tb[i] = 0;
	i = 0;
	while (++i <= size)
		put_min_in_tb(tb, *a);
	i = -1;
	buff = (*a);
	while (++i < size && buff)
	{
		*((int *)buff->content) = tb[i];
		buff = buff->next;
	}
	free(tb);
}
