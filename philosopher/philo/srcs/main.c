/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <jbondri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:41:02 by jbondri           #+#    #+#             */
/*   Updated: 2021/12/03 14:26:49 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	print_error(void)
{
	printf("Error\n");
}

int	main(int argc, char **argv)
{
	t_data_philo	*data;

	data = malloc(sizeof(t_data_philo) * 1);
	if (!data || (argc != 5 && argc != 6))
	{
		print_error();
		return (0);
	}
	if (parser(argv, data))
	{
		free(data);
		print_error();
		return (1);
	}
	algo(data);
	while (data->size--)
	{
		free(data->tb[data->size].th);
		free(data->tb[data->size].forch_right);
	}
	free(data->tb);
	free(data);
	return (0);
}
