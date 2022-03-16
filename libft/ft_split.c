/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkang <tkang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:23:43 by tkang             #+#    #+#             */
/*   Updated: 2022/03/16 18:24:35 by tkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	check_size(char const *s, char c)
{
	size_t	i;
	size_t	res;

	i = 0;
	res = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			res++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**buf;
	size_t	idx;
	char	*temp;

	buf = (char **)malloc(sizeof(char *) * check_size(s, c) + 1);
	if (!buf)
		return (NULL);
	idx = 0;
	while (*s)
	{
		if (*s != c)
		{
			temp = (char *)s;
			while (*s && *s != c)
				++s;
			buf[idx] = (char *)malloc(sizeof(char) * (s - temp) + 1);
			ft_strlcpy(buf[idx], temp, (size_t)(s - temp) + 1);
			idx++;
		}
		else
			++s;
	}
	buf[idx] = 0;
	return (buf);
}
