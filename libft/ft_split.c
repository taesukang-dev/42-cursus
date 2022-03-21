/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkang <tkang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:23:43 by tkang             #+#    #+#             */
/*   Updated: 2022/03/18 19:40:33 by tkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_check_size(char const *s, char c)
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

static size_t	ft_map_strs(char const *s, char c, char **buf)
{
	size_t	idx;
	char	*temp;

	idx = 0;
	while (*s)
	{
		if (*s != c)
		{
			temp = (char *)s;
			while (*s && *s != c)
				s++;
			buf[idx] = (char *)malloc(sizeof(char) * ((s - temp) + 1));
			if (!(buf[idx]))
				return 0;
			ft_strlcpy(buf[idx], temp, (size_t)((s - temp) + 1));
			idx++;
		}
		else
			s++;
	}
	buf[idx] = NULL;
	return (1);
}

static char	**ft_all_free(char **buf)
{
	size_t	i;

	i = 0;
	while (buf[i])
	{
		free(buf[i]);
		i++;
	}
	free(buf);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**buf;

	buf = (char **)malloc(sizeof(char *) * (ft_check_size(s, c) + 1));
	if (!buf)
		return (NULL);
	if(!ft_map_strs(s, c, buf))
		return ft_all_free(buf);
	return (buf);
}