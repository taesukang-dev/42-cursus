#include "push_swap.h"

int	stack_min(t_DoublyList *a)
{
	t_DoublyListNode	*buf;
	int					i;

	buf = a->headerNode;
	i = 2147483647;
	while (buf)
	{
		if (i > buf->data)
			i = buf->data;
		buf = buf->next;
	}
	return (i);
}

int	stack_min_idx(t_DoublyList *a)
{
	t_DoublyListNode	*buf;
	int					i;
	int					min_val;

	buf = a->headerNode;
	min_val = stack_min(a);
	i = 0;
	while(buf)
	{
		if (buf->data == min_val)
			break ;
		i++;
		buf = buf->next;
	}
	return (i);
}

int stack_max(t_DoublyList *a)
{
	t_DoublyListNode	*buf;
	int					i;

	buf = a->headerNode;
	i = 0;
	while (buf)
	{
		if (i < buf->data)
			i = buf->data;
		buf = buf->next;
	}
	return (i);
}

int	stack_max_idx(t_DoublyList *a)
{
	t_DoublyListNode	*buf;
	int					i;
	int					max_val;

	buf = a->headerNode;
	max_val = stack_max(a);
	i = 0;
	while(buf)
	{
		if (buf->data == max_val)
			break ;
		i++;
		buf = buf->next;
	}
	i += 1;
	return (i);
}

int stack_mid_idx(t_DoublyList *a, int b_val)
{
	t_DoublyListNode	*buf;
	int					i;
	
	buf = a->headerNode;
	i = 0;
	while(buf)
	{
		if (buf->data < b_val && b_val < buf->next->data)
			break ;
		i++;
		buf = buf->next;
	}
	i += 1;
	return (i);
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