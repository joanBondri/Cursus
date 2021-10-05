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
	(void)str;
	ft_putendl_fd("Error\n", STDERR_FILENO);
	exit(0);
}

void	*ft_malloc(size_t i)
{
	void	*ptr;

	ptr = malloc(i);
	if (!ptr)
		ft_exit("MALLOC : "RED"Error"RESET);
	return (ptr);
}

int	ft_pre_atoi(char *s)
{
	if (!s)
		ft_exit("ERROR : "RED"Error"RESET);
	if (ft_loop_strchr("0123456789", s)
		|| ft_loop_strchr("0123456789", (s + 1)))
		return (ft_atoi(s));
	ft_exit("ERROR : "RED"wrong argument"RESET);
	return (0);
}
