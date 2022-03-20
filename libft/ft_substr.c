/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkang <tkang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:37:26 by tkang             #+#    #+#             */
/*   Updated: 2022/03/20 20:28:11 by tkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*buf;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	if (s_len < start)
		return (ft_strdup(""));
	buf = (char *)malloc(sizeof(char) * (len + 1));
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
