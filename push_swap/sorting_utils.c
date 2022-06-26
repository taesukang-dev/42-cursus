#include "push_swap.h"

void	split_stack(t_DoublyList *a, t_DoublyList *b, int *sorted_arr)
{
	int	pivot1;
	int	pivot2;
	int	i;

	pivot1 = sorted_arr[a->size / 3];
	pivot2 = sorted_arr[(a->size * 2) / 3];
	i = a->size;
	while(i)
	{
		if (a->headerNode->data >= pivot2)
			command_rab(a, RA);
		else
		{
			command_pab(a, b, PB);
			if (b->headerNode->data < pivot1)
				command_rab(b, RB);
		}
		i--;
	}
}

void	rotate_same(t_DoublyList *a, t_DoublyList *b, int *a_idx, int *b_idx)
{
	while (*a_idx && *b_idx && (0 < *a_idx && 0 < *b_idx))
	{
		command_rr(a, b);
		*a_idx = *a_idx - 1;
		*b_idx = *b_idx - 1;
	}
	while (*a_idx && *b_idx && (0 > *a_idx && 0 > *b_idx))
	{
		command_rrr(a, b);
		*a_idx = *a_idx + 1;
		*b_idx = *b_idx + 1;
	}
}

void	rotate_a(t_DoublyList *a, int a_idx)
{
	while (a_idx > 0)
	{
		command_rab(a, RA);
		a_idx -= 1;
	}
	while (a_idx < 0)
	{
		command_rrab(a, RRA);
		a_idx += 1;
	}
}

void	rotate_b(t_DoublyList *b, int b_idx)
{
	while (b_idx > 0)
	{
		command_rab(b, RB);
		b_idx -= 1;
	}
	while (b_idx < 0)
	{
		command_rrab(b, RRB);
		b_idx += 1;
	}
	
}

void	rotate(t_DoublyList *a, t_DoublyList *b, int *a_idx, int *b_idx)
{
	rotate_same(a, b, a_idx, b_idx);
	rotate_a(a, *a_idx);
	rotate_b(b, *b_idx);
}
