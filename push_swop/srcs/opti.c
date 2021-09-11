/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 19:57:43 by jbondri           #+#    #+#             */
/*   Updated: 2021/09/11 19:58:15 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_equality_one(t_list *b, int pivot, int hwmny)
{
	t_list	*buff;

	buff = b;
	while (hwmny-- && buff)
	{
		if (*((int *)buff->content) >= pivot)
			return (true);
		buff = buff->next;
	}
	return (false);
}

bool	check_equality_two(t_list *a, int pivot, int hwmny)
{
	t_list	*buff;

	buff = a;
	while (hwmny-- && buff)
	{
		if (*((int *)buff->content) <= pivot)
			return (true);
		buff = buff->next;
	}
	return (false);
}
