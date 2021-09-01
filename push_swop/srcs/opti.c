#include "push_swap.h"

bool	check_equality_one(t_list *b, int pivot, int hwmny)
{
	t_list	*buff;

	buff = b;
	while (hwmny-- && buff)
	{
		if (*((int*)buff->content) >= pivot)
			return (true);
		buff = buff->next;
	}
	return (false);
}

bool	check_equality_two(t_list *a, int pivot, int hwmny)
{
	t_list	*buff;

	buff = a;
	while (hwmny-- && buff)
	{
		if (*((int*)buff->content) <= pivot)
			return (true);
		buff = buff->next;
	}
	return (false);
}
