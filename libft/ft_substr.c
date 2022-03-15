/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkang <tkang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:37:26 by tkang             #+#    #+#             */
/*   Updated: 2022/03/15 20:38:11 by tkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*buf;

	buf = ft_calloc(len + 1, sizeof(char));
	i = 0;
	while (s[start] && i < len)
	{
		buf[i] = s[start];
		start++;
		i++;
	}
	return (buf);
}
