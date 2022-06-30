/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_sp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkang <tkang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:12:38 by tkang             #+#    #+#             */
/*   Updated: 2022/06/30 15:12:39 by tkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	command_sab(t_DoublyList *dList, int flag)
{
	t_DoublyListNode	*temp;
	t_DoublyListNode	*next;

	if (dList->cnt < 2)
		return ;
	temp = pop_dl(dList);
	next = pop_dl(dList);
	if (!add_dl_element(dList, temp->data))
		exit_trap(0);
	if (!add_dl_element(dList, next->data))
		exit_trap(0);
	free(temp);
	free(next);
	if (flag == SA)
		write(1, "sa\n", 3);
	else if (flag == SB)
		write(1, "sb\n", 3);
}

void	command_ss(t_DoublyList *a, t_DoublyList *b)
{
	command_sab(a, SS);
	command_sab(b, SS);
	write(1, "ss\n", 3);
}

void	command_pab(t_DoublyList *a, t_DoublyList *b, int flag)
{
	t_DoublyListNode	*buf;

	if (flag == PA && b->cnt != 0)
	{
		buf = pop_dl(b);
		if (!add_dl_element(a, buf->data))
			exit_trap(0);
		free(buf);
		write(1, "pa\n", 3);
	}
	else if (flag == PB && a->cnt != 0)
	{
		buf = pop_dl(a);
		if (!add_dl_element(b, buf->data))
			exit_trap(0);
		free(buf);
		write(1, "pb\n", 3);
	}
}
