/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 20:03:05 by jbondri           #+#    #+#             */
/*   Updated: 2021/09/11 20:04:30 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parser_str(t_list **a, char *argv)
{
	char	**s;
	char	**buff;

	if (!*argv)
		ft_exit("ERROR : "RED"null argument"RESET);
	s = ft_split(argv, " \n\t\f\v");
	buff = s;
	--s;
	while (*(++s))
	{
		if (!(*a))
			*a = ft_lstnew(int_to_ptr(ft_pre_atoi(*s)));
		else
			ft_lstadd_back(a, ft_lstnew(int_to_ptr(ft_pre_atoi(*s))));
	}
	free_second_deg(buff);
}

void	check_duplicate_number(t_list *a)
{
	t_list	*buff;
	t_list	*def;
	int		test;

	buff = a;
	if (ft_lstsize(a) < 1)
		ft_exit("ERROR : "RED"too few number"RESET);
	while (buff)
	{
		test = *((int *)buff->content);
		def = buff->next;
		while (def)
		{
			if (test == *((int *)def->content))
				ft_exit("PARSING : "RED"duplicate number"RESET);
			def = def->next;
		}
		buff = buff->next;
	}
}

int	parser_classic(t_list **a, char *argv)
{
	if (!*argv)
		ft_exit("ERROR : "RED"null argument");
	if (!(*a))
		*a = ft_lstnew(int_to_ptr(ft_pre_atoi(argv)));
	else
		ft_lstadd_back(a, ft_lstnew(int_to_ptr(ft_pre_atoi(argv))));
	return (0);
}

void	parser(t_list **a, char **argv, int argc)
{
	if (argc == 1)
		ft_exit("ERROR : "RED"too few arguments"RESET);
	while (*(++argv))
	{
		if (ft_loop_strchr("-0123456789", *argv))
			parser_classic(a, *argv);
		else if (ft_loop_strchr("-0123456789 \n\f\t\v", *argv))
			parser_str(a, *argv);
		else
			ft_exit("PARSING : "RED"failed"RESET);
	}
	check_duplicate_number(*a);
}