/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 20:23:08 by jbondri           #+#    #+#             */
/*   Updated: 2021/09/11 20:24:04 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(char *str)
{
	printf("%s\n", str);
	exit(0);
}

void	*ft_malloc(size_t i)
{
	void	*ptr;

	ptr = malloc(i);
	if (!ptr)
		ft_exit("MALLOC : "RED"failed"RESET);
	return (ptr);
}

int	ft_pre_atoi(char *s)
{
	if (!s)
		ft_exit("ERROR : "RED"null argument"RESET);
	if (ft_loop_strchr("0123456789", s)
		|| ft_loop_strchr("0123456789", (s + 1)))
		return (ft_atoi(s));
	ft_exit("ERROR : "RED"wrong argument"RESET);
	return (0);
}
