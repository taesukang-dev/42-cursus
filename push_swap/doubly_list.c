/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkang <tkang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:12:51 by tkang             #+#    #+#             */
/*   Updated: 2022/06/30 15:12:52 by tkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_DoublyList	*create_doubly_list(void)
{
	t_DoublyList	*temp;

	temp = (t_DoublyList *)ft_calloc(1, sizeof(t_DoublyList));
	return (temp);
}

int	add_right_dl_element(t_DoublyList *dList, int data)
{
	t_DoublyListNode	*buf;
	t_DoublyListNode	*new;

	new = ft_calloc(1, sizeof(t_DoublyListNode));
	if (!new)
		return (0);
	new->data = data;
	if (dList->cnt == 0)
	{
		dList->head = new;
		dList->tail = new;
		dList->cnt += 1;
		return (1);
	}
	buf = dList->tail;
	buf->next = new;
	new->prev = buf;
	dList->tail = new;
	dList->cnt += 1;
	return (1);
}

int	add_dl_element(t_DoublyList *dList, int data)
{
	t_DoublyListNode	*buf;
	t_DoublyListNode	*new;

	new = ft_calloc(1, sizeof(t_DoublyListNode));
	if (!new)
		return (0);
	new->data = data;
	if (dList->cnt == 0)
	{
		dList->head = new;
		dList->tail = new;
		dList->cnt += 1;
		return (1);
	}
	buf = dList->head;
	buf->prev = new;
	new->next = buf;
	dList->head = new;
	dList->cnt += 1;
	return (1);
}

t_DoublyListNode	*pop_dl(t_DoublyList *dList)
{
	t_DoublyListNode	*buf;

	if (dList->cnt == 0)
		return (NULL);
	buf = dList->head;
	dList->head = dList->head->next;
	if (dList->cnt == 1)
		dList->tail = NULL;
	else
		dList->head->prev = NULL;
	buf->prev = NULL;
	buf->next = NULL;
	dList->cnt -= 1;
	return (buf);
}

t_DoublyListNode	*pop_right_dl(t_DoublyList *dList)
{
	t_DoublyListNode	*buf;

	if (dList->cnt == 0)
		return (NULL);
	buf = dList->tail;
	dList->tail = dList->tail->prev;
	if (dList->cnt == 1)
		dList->head = NULL;
	else
		dList->tail->next = NULL;
	buf->prev = NULL;
	buf->next = NULL;
	dList->cnt -= 1;
	return (buf);
}
