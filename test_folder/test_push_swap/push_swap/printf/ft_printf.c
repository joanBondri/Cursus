/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <jbondri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 14:00:01 by jbondri           #+#    #+#             */
/*   Updated: 2020/11/26 14:00:04 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_printf(const char *str, ...)
{
	va_list		list;
	int			i;
	char		*prin;
	t_printf	*data;

	if (!str)
		return (0);
	prin = (char *)str;
	if (!(data = malloc(sizeof(t_printf) * (1))))
		return (-1);
	va_start(list, str);
	i = -1;
	while (prin[++i])
	{
		if (prin[i] == '%')
			i = special_case(prin, i, &list, data);
		else
			put_char(prin[i]);
	}
	free(data);
	return (get_number_char(0));
}

int		special_case(char *prin, int i, va_list *list, t_printf *data)
{
	int		j;

	set_null_struct(data);
	j = i + 1;
	while (ft_strchr("0123456789-*.", prin[j]))
		j++;
	if (!ft_strchr("cspdiuxX%", prin[j]))
	{
		put_char(prin[i]);
		return (i);
	}
	data->type_conversion = prin[j];
	data->start = prin + i + 1;
	get_flags_and_next_param(data, list);
	print(data->type_conversion, data);
	return (j);
}
