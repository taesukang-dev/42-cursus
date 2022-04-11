/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkang <tkang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 17:20:07 by tkang             #+#    #+#             */
/*   Updated: 2022/04/09 17:20:09 by tkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char	*s1)
{
	char	*temp;
	size_t	s1_len;
	size_t	i;

	if (!s1)
		return (NULL);
	s1_len = ft_strlen(s1);
	temp = (char *)malloc(sizeof(char) * (s1_len + 1));
	if (!temp)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		temp[i] = s1[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*temp;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1)
		return (ft_strdup(s2));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	temp = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!temp)
	{
		free(s1);
		return (NULL);
	}
	ft_strlcpy(temp, s1, s1_len + 1);
	ft_strlcpy(temp + s1_len, s2, s2_len + 1);
	free(s1);
	return (temp);
}

void	ft_strlcpy(char *dest, char *src, int read_len)
{
	int		i;
	size_t	src_len;

	src_len = ft_strlen(src);
	i = 0;
	while (src[i] && i + 1 < read_len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}
