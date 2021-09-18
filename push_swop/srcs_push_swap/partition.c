/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 20:04:44 by jbondri           #+#    #+#             */
/*   Updated: 2021/09/11 20:09:35 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_med(t_list **s, int loop)
{
	int		min;
	int		max;
	t_list	*buff;

	if (loop < 1 || !s || !(*s))
		return (-1);
	min = INT_MAX;
	max = -1;
	buff = *s;
	while (buff && loop--)
	{
		if (*((int *)buff->content) < min)
			min = *((int *)buff->content);
		if (*((int *)buff->content) > max)
			max = *((int *)buff->content);
		buff = buff->next;
	}
	return ((max + min) / 2);
}

bool	push_part(t_list **part, int nbr)
{
	if (!part)
		return (false);
	ft_lstadd_front(part, ft_lstnew(int_to_ptr(nbr)));
	return (true);
}

int	pop_part(t_list **part)
{
	int		res;
	t_list	*buff;

	if (!part || !(*part))
		return (INT_MIN);
	res = *((int *)(*part)->content);
	buff = *part;
	*part = (*part)->next;
	ft_lstdelone(buff, free);
	return (res);
}
