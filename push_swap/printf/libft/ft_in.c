/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_in.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 11:41:48 by jbondri           #+#    #+#             */
/*   Updated: 2021/03/21 11:42:02 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_in(char *str, char *set)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (ft_strchr(set, str[i]))
			return (ft_strchr(set, str[i]));
	}
	return (NULL);
}
