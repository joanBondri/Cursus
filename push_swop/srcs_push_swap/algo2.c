#include "push_swap.h"

int	find_idx_max(t_list *lst)
{
	int		max;
	int		max_idx;
	int		cmpt;
	t_list	*swp;

	swp = lst;
	cmpt = -1;
	max = INT_MIN;
	max_idx = -1;
	while (swp)
	{
		cmpt++;
		if (*(int *)(swp)->content > max)
		{
			max = *(int *)(swp)->content;
			max_idx = cmpt;
		}
		swp = swp->next;
	}
	return (max_idx);
}

int	find_max(t_list *lst)
{
	int		max;
	t_list	*swp;

	swp = lst;
	max = INT_MIN;
	while (swp)
	{
		if (*(int *)(swp)->content > max)
			max = *(int *)(swp)->content;
		swp = swp->next;
	}
	return (max);
}
