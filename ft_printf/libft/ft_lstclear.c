/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkang <tkang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 19:26:18 by tkang             #+#    #+#             */
/*   Updated: 2022/03/20 19:26:19 by tkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*buf;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		buf = (*lst)->next;
		ft_lstdelone((*lst), del);
		*lst = buf;
	}
	*lst = NULL;
}
