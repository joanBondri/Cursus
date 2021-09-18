/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 19:57:07 by jbondri           #+#    #+#             */
/*   Updated: 2021/09/11 19:57:28 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{	
	t_list	*a;
	t_list	*b;

	(void)argc;
	a = NULL;
	b = NULL;
	parser(&a, argv, argc);
	convert_to_index(&a);
	algo(&a, &b);
	return (0);
}
