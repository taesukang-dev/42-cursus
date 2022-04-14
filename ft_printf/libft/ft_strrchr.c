/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkang <tkang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:04:20 by tkang             #+#    #+#             */
/*   Updated: 2022/03/20 22:00:21 by tkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	s_len;
	char	*temp;
	char	target;

	s_len = ft_strlen(s);
	temp = (char *)s;
	target = (char)c;
	while (s_len > 0 && temp[s_len] != c)
		s_len--;
	if (temp[s_len] == target)
		return ((char *)(temp + s_len));
	return (NULL);
}
