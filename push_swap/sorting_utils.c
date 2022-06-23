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
