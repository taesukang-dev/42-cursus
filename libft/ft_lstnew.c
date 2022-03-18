/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkang <tkang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 21:07:38 by tkang             #+#    #+#             */
/*   Updated: 2022/03/18 21:07:39 by tkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*buf;

	buf = (t_list *)malloc(sizeof(t_list));
	if (!buf)
		return (NULL);
	buf->content = content;
	buf->next = NULL;
	return (buf);
}
