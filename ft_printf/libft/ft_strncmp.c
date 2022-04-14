/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkang <tkang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:33:01 by tkang             #+#    #+#             */
/*   Updated: 2022/03/15 20:22:07 by tkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] == s2[i] && s1[i] && s2[i])
	{
		i++;
	}
	if (n == i)
		return (0);
	else if ((unsigned char)s1[i] == '\0' && (unsigned char)s2[i] == '\0')
		return (0);
	else if ((unsigned char)s1[i] - (unsigned char)s2[i] < 0)
		return (-1);
	else
		return (1);
}
