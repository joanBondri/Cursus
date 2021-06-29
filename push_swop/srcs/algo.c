#include "push_swap.h"

bool	push_part(t_list **part, int nbr)
{
	if (!part)
		return (false);
	ft_lstadd_front(part, ft_lstnew(int_to_ptr(nbr)));
	return (true);
}

int		pop_part(t_list **part)
{
	int		res;

	if (!part || !(*part))
		return (-1);
	res = (*(*int))
}

void	initial_push(t_list **a, t_list **b, t_list **part)
{
	int		pivot;
	int		size;
	int		res;
	t_list	buff;

	size = ft_lstsize(a);
	pivot = size - 3;
	buff = *a;
	res = 0;
	while (size--)
	{
		if (*((int)buff->content) < pivot)
		{
			res++;
			moves(PB, a, b);
		}
		else
			moves(RA, a, b);
	}

}

//il faut faire une condition pour moins de 5 nombres dans la stack A
void	algo(t_list **a, t_list **b)
{
	t_list	*part;

	initial_push(a, b, &part);
}
