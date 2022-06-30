/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_arr_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkang <tkang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:21:12 by tkang             #+#    #+#             */
/*   Updated: 2022/06/30 15:21:12 by tkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*init_sorted_arr(t_DoublyList *dList)
{
	int					*temp;
	t_DoublyListNode	*buf;
	int					i;

	temp = ft_calloc(dList->cnt, sizeof(int));
	if (!temp)
		exit_trap(0);
	buf = dList->head;
	i = 0;
	while (i < dList->cnt)
	{
		temp[i] = buf->data;
		buf = buf->next;
		i++;
	}
	if (!sort_arr(temp, dList->cnt))
		exit_trap(0);
	return (temp);
}

int	sort_arr(int *sorted_arr, int size)
{
	int		i;
	int		j;
	int		cnt;
	int		temp;

	i = -1;
	cnt = 0;
	while (++i < size)
	{
		j = -1;
		while (++j < size - 1)
		{
			if (sorted_arr[j] > sorted_arr[j + 1])
			{
				temp = sorted_arr[j];
				sorted_arr[j] = sorted_arr[j + 1];
				sorted_arr[j + 1] = temp;
				cnt += 1;
			}
			if (sorted_arr[j] == sorted_arr[j + 1])
				exit_trap(1);
		}
	}
	return (cnt);
}
