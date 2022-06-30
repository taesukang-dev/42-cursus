/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkang <tkang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:24:06 by tkang             #+#    #+#             */
/*   Updated: 2022/06/30 15:24:07 by tkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_bigger(int a, int b, int temp_a, int temp_b)
{
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	if (temp_a < 0)
		temp_a *= -1;
	if (temp_b < 0)
		temp_b *= -1;
	if (a + b > temp_a + temp_b)
		return (1);
	return (0);
}

int	get_idx(t_DoublyList *a, int b_val)
{
	if (stack_max(a) < b_val)
		return (stack_max_idx(a));
	else if (stack_min(a) > b_val)
		return (stack_min_idx(a));
	else
		return (stack_mid_idx(a, b_val));
}

void	swap(t_DoublyList *a, t_DoublyList *b, int *a_idx, int *b_idx)
{
	int					i;
	t_DoublyListNode	*buf;
	int					temp_a;
	int					temp_b;

	i = 0;
	buf = b->head;
	while (i < b->cnt)
	{
		temp_a = get_idx(a, buf->data);
		if (i > b->cnt / 2)
			temp_b = (b->cnt - i) * -1;
		else
			temp_b = i;
		if (i == 0 || is_bigger(*a_idx, *b_idx, temp_a, temp_b))
		{
			*a_idx = temp_a;
			*b_idx = temp_b;
		}
		buf = buf->next;
		i++;
	}
}
