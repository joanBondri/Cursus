/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <joan.bondri@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:16:44 by jbondri           #+#    #+#             */
/*   Updated: 2021/06/11 10:48:00 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_white_space(char c)
{
	if (c == '\n' || c == '\t' || c == '\v'
		|| c == '\r' || c == '\f' || c == ' ')
		return (1);
	return (0);
}

int	*int_to_ptr(int i)
{
	int	*ptr;

	ptr = malloc(sizeof(int));
	if (ptr)
		*ptr = i;
	return (ptr);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		res;
	int		sign;
	char	*s;

	s = (char *)str;
	res = 0;
	i = 0;
	sign = 1;
	while (is_white_space(s[i]))
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + s[i] - '0';
		i++;
	}
	return (sign * res);
}
