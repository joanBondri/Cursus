/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <joan.bondri@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:42:19 by jbondri           #+#    #+#             */
/*   Updated: 2020/11/18 16:42:21 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stddef.h>

static char		*return_empty(void)
{
	char		*s;

	if (!(s = malloc(sizeof(char) * (1))))
		return (NULL);
	s[0] = '\0';
	return (s);
}

char			*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	size_t		len_str;
	char		*str;
	char		*res;

	len_str = 0;
	if (s == NULL)
		return (NULL);
	str = (char *)s;
	len_str = ft_strlen(str);
	if (len_str <= start || len == 0)
		return (return_empty());
	len_str = 0;
	len_str = ft_strlen(str + start);
	if (!(res = malloc(sizeof(char) * (((len > len_str) ? len_str : len) + 1))))
		return (NULL);
	i = 0;
	while (str[start + i] && i < len)
	{
		res[i] = str[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
