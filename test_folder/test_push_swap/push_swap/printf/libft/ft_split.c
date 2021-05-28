/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <joan.bondri@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:36:02 by jbondri           #+#    #+#             */
/*   Updated: 2020/11/18 16:36:05 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

static char	**first_alloc(char *s, unsigned char c)
{
	int		i;
	int		count;
	char	**tab;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (!s[i])
			break ;
		while (s[i] != c && s[i])
			i++;
		count++;
	}
	if (!(tab = malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	tab[count] = NULL;
	return (tab);
}

static char	**second_alloc(char **tab, char *s, unsigned char c)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	j = -1;
	while (s[i])
	{
		count = 0;
		while (s[i] == c && s[i])
			i++;
		if (!s[i])
			break ;
		while (s[i] != c && s[i])
		{
			i++;
			count++;
		}
		if (!(tab[++j] = malloc(sizeof(char) * (count + 1))))
			return (NULL);
	}
	return (tab);
}

static char	**fill_tab(char **tab, char *s, unsigned char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = -1;
	while (s[i])
	{
		j++;
		k = -1;
		while (s[i] == c && s[i])
			i++;
		if (!s[i])
			break ;
		while (s[i] != c && s[i])
			tab[j][++k] = s[i++];
		tab[j][++k] = '\0';
	}
	return (tab);
}

char		**ft_split(char const *s, char c)
{
	char	*str;
	char	**tab;

	if (s == NULL)
		return (NULL);
	str = (char *)s;
	if (!(tab = first_alloc(str, (unsigned char)c)))
		return (NULL);
	if (!(second_alloc(tab, str, (unsigned char)c)))
		return (NULL);
	fill_tab(tab, str, (unsigned char)c);
	return (tab);
}
