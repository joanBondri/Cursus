/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <joan.bondri@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:20:53 by jbondri           #+#    #+#             */
/*   Updated: 2020/11/19 14:56:16 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t nitems, size_t size)
{
	void		**v;
	char		*s;
	size_t		i;

	if (!(v = (void *)malloc(nitems * size)))
		return (NULL);
	s = (char *)v;
	i = 0;
	while (i < nitems * size)
	{
		s[i] = 0;
		i++;
	}
	return (v);
}
