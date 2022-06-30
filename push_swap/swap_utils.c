/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkang <tkang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:22:55 by tkang             #+#    #+#             */
/*   Updated: 2022/06/30 15:22:55 by tkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_min(t_DoublyList *a)
{
	t_DoublyListNode	*buf;
	int					i;

	buf = a->head;
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

	buf = a->head;
	min_val = stack_min(a);
	i = 0;
	while (buf)
	{
		if (buf->data == min_val)
			break ;
		i++;
		buf = buf->next;
	}
	if (i > a->cnt / 2)
		i = (a->cnt - i) * -1;
	return (i);
}

int	stack_max(t_DoublyList *a)
{
	t_DoublyListNode	*buf;
	int					i;

	buf = a->head;
	i = -2147483648;
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

	buf = a->head;
	max_val = stack_max(a);
	i = 0;
	while (buf)
	{
		if (buf->data == max_val)
			break ;
		i++;
		buf = buf->next;
	}
	i += 1;
	if (i > a->cnt / 2)
		i = (a->cnt - i) * -1;
	return (i);
}

int	stack_mid_idx(t_DoublyList *a, int b_val)
{
	t_DoublyListNode	*buf;
	int					i;

	buf = a->head;
	i = 0;
	while (buf)
	{
		if ((buf->data < b_val && !buf->next) \
			|| (buf->data < b_val && b_val < buf->next->data))
			break ;
		i++;
		buf = buf->next;
	}
	i += 1;
	if (i > a->cnt / 2)
		i = (a->cnt - i) * -1;
	return (i);
}
