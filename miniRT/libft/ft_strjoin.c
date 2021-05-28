/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <joan.bondri@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:52:59 by jbondri           #+#    #+#             */
/*   Updated: 2020/12/08 15:06:27 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	strl(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char		*ft_strjoin(char const *str1, char const *str2)
{
	long	i;
	char	*s1;
	char	*s2;
	char	*res;

	s1 = (char *)str1;
	s2 = (char *)str2;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(res = (char*)ft_malloc(sizeof(char) * (strl(s1) + strl(s2) + 1))))
		return (NULL);
	i = -1;
	while (++i < strl(s1))
		res[i] = s1[i];
	i = -1;
	while (++i < strl(s2))
		res[i + strl(s1)] = s2[i];
	res[strl(s1) + strl(s2)] = '\0';
	return (res);
}
