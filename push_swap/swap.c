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
	while(buf)
	{
		if (buf->data == min_val)
			break ;
		i++;
		buf = buf->next;
	}
	i += 1;
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

void	swap(t_DoublyList *a, t_DoublyList *b, int *a_idx, int *b_idx)
{
	int					i;
	t_DoublyListNode	*buf;

	i = 0;
	buf = b->headerNode;
	while(i < b->currentElementCount)
	{
		// need to add min swap
		get_idx(a, buf->data);
		buf = buf->next;
		i++;
	}
}