/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkang <tkang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 19:36:12 by tkang             #+#    #+#             */
/*   Updated: 2022/03/18 17:16:30 by tkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*temp;
	int		s1_len;
	int		s2_len;
	int		i;

	if (!s1 && !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	temp = malloc(sizeof(char) * (s1_len + s2_len) + 1);
	i = 0;
	while (s1[i])
	{
		temp[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		temp[s1_len] = s2[i];
		i++;
		s1_len++;
	}
	temp[s1_len] = '\0';
	return (temp);
}
