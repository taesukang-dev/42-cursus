/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkang <tkang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:14:22 by tkang             #+#    #+#             */
/*   Updated: 2022/06/30 15:14:23 by tkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int				*sorted_arr;
	t_DoublyList	*temp;
	t_DoublyList	*temp2;

	temp2 = create_doubly_list();
	init_doubly(&temp, argv, argc);
	sorted_arr = init_sorted_arr(temp);
	sorting(temp, temp2, sorted_arr);
	return (0);
}
