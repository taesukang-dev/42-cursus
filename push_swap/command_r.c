/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkang <tkang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:12:20 by tkang             #+#    #+#             */
/*   Updated: 2022/06/30 15:12:21 by tkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	command_rab(t_DoublyList *dList, int flag)
{
	t_DoublyListNode	*temp;

	if (dList->cnt < 2)
		return ;
	temp = pop_dl(dList);
	if (!add_right_dl_element(dList, temp->data))
		exit_trap(0);
	free(temp);
	if (flag == RA)
		write(1, "ra\n", 3);
	else if (flag == RB)
		write(1, "rb\n", 3);
}

void	command_rr(t_DoublyList *a, t_DoublyList *b)
{
	command_rab(a, RR);
	command_rab(b, RR);
	write(1, "rr\n", 3);
}

void	command_rrab(t_DoublyList *dList, int flag)
{
	t_DoublyListNode	*temp;

	if (dList->cnt < 2)
		return ;
	temp = pop_right_dl(dList);
	if (!add_dl_element(dList, temp->data))
		exit_trap(0);
	free(temp);
	if (flag == RRA)
		write(1, "rra\n", 4);
	if (flag == RRB)
		write(1, "rrb\n", 4);
}

void	command_rrr(t_DoublyList *a, t_DoublyList *b)
{
	command_rrab(a, RRR);
	command_rrab(b, RRR);
	write(1, "rrr\n", 4);
}
