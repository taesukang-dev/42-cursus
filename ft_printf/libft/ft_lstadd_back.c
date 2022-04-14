/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkang <tkang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 21:30:16 by tkang             #+#    #+#             */
/*   Updated: 2022/03/20 22:07:42 by tkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_one)
{
	t_list	*last_one;

	if (!new_one)
		return ;
	if (!*lst)
	{
		*lst = new_one;
		return ;
	}
	last_one = ft_lstlast(*lst);
	if (!last_one)
		*lst = new_one;
	else
		last_one->next = new_one;
}
