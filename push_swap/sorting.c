#include "push_swap.h"

void	sort_two_elements(t_DoublyList *a)
{
	if (a->headerNode->data > a->headerNode->next->data)
		command_sab(a, SA);
}

void	sort_three_elements(t_DoublyList *a)
{
	int		head;
	int		bottom;
	int		middle;

	head = a->headerNode->data;
	bottom = a->tailNode->data;
	middle = a->headerNode->next->data;
	if (head > middle && bottom > head && middle < bottom)
		command_sab(a, SA);
	if (head > middle && bottom < head && bottom > middle)
		command_rab(a, RA);
	if (head < middle && head > bottom)
		command_rrab(a, RRA);
	if (head > middle && middle > bottom)
	{
		command_sab(a, SA);
		command_rrab(a, RRA);
	}
	if (head < middle && head < bottom && bottom < middle)
	{
		command_sab(a, SA);
		command_rab(a, RA);
	}
}

void	end_sort_up(t_DoublyList *a)
{
	int					i;
	int					min;
	t_DoublyListNode	*buf;

	min = stack_min(a);
	buf = a->headerNode;
	i = 0;
	while(buf)
	{
		if (buf->data == min)
			break ;
		buf = buf->next;
	}
	while (buf)
	{
		i += 1;
		buf = buf->next;
	}
	if (i == a->size)
		return ;
	while(i)
	{
		command_rrab(a, RRA);
		i -= 1;
	}
}

void	sort_push_swap(t_DoublyList *a, t_DoublyList *b, int *sorted_arr)
{
	int	a_idx;
	int	b_idx;

	split_stack(a, b, sorted_arr);
	while(a->currentElementCount > 3)
		command_pab(a, b, PB);
	if (a->currentElementCount == 2)
		sort_two_elements(a);
	else if (a->currentElementCount == 3)
		sort_three_elements(a);
	while(b->currentElementCount)
	{
		a_idx = 0;
		b_idx = 0;
		swap(a, b, &a_idx, &b_idx);
		rotate(a, b, &a_idx, &b_idx);
		command_pab(a, b, PA);
	}
	end_sort_up(a);
}

void	sorting(t_DoublyList *a, t_DoublyList *b, int *sorted_arr)
{
	if (a->currentElementCount == 2)
		sort_two_elements(a);
	else if (a->currentElementCount == 3)
		sort_three_elements(a);
	else if (a->currentElementCount > 3)
		sort_push_swap(a, b, sorted_arr);
}
