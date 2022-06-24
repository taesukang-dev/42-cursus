#include "push_swap.h"

int is_bigger(int a, int b, int temp_a, int temp_b)
{
	if (a + b > temp_a + temp_b)
		return (1);
	return (0);
}

void	rotate(t_DoublyList *a, t_DoublyList *b, int *a_idx, int *b_idx)
{
	while (*a_idx && *b_idx)
	{ // abs?
		command_rr(a, b);
		*a_idx = *a_idx - 1;
		*b_idx = *b_idx - 1;
	}
	while (*a_idx)
	{
		command_rab(a, RA);
		*a_idx = *a_idx - 1;
	}
	while (*b_idx)
	{
		command_rab(b, RB);
		*b_idx = *b_idx - 1;
	}
}

int	get_idx(t_DoublyList *a, int b_val)
{
	if (stack_max(a) < b_val)
		return stack_max_idx(a);
	else if (stack_min(a) > b_val)
		return stack_min_idx(a);
	else
		return stack_mid_idx(a, b_val);
}

void	swap(t_DoublyList *a, t_DoublyList *b, int *a_idx, int *b_idx)
{
	int					i;
	t_DoublyListNode	*buf;
	int					temp_a;
	int					temp_b;

	i = 0;
	buf = b->headerNode;
	while(i < b->currentElementCount)
	{
		temp_a = get_idx(a, buf->data);
		if (i == 0 || is_bigger(*a_idx, *b_idx, temp_a, temp_b))
		{
			*a_idx = temp_a;
			*b_idx = i;
		}
		buf = buf->next;
		i++;
	}
}