/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkang <tkang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:37:26 by tkang             #+#    #+#             */
/*   Updated: 2022/03/16 17:30:49 by tkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*buf;

	if (!s)
		return (NULL);
	buf = (char *)ft_calloc(len + 1, sizeof(char));
	if (!buf)
		return (NULL);
	i = 0;
	while (s[start] && i < len)
	{
		buf[i] = s[start];
		start++;
		i++;
	}
	buf[i] = '\0';
	return (buf);
}
