/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkang <tkang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:40:58 by tkang             #+#    #+#             */
/*   Updated: 2022/03/20 20:49:25 by tkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	check_len(int n)
{
	size_t	i;

	i = 0;
	if (n < 0)
		i = 1;
	if (n == -2147483648)
		return (10);
	else if (n < 0)
		n *= -1;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*buf;
	size_t		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (n == 0 || n == -0)
		return (ft_strdup("0"));
	len = check_len(n);
	buf = malloc(sizeof(char) * (len + 1));
	if (!buf)
		return (NULL);
	if (n < 0)
	{
		buf[0] = '-';
		n *= -1;
	}
	buf[len] = '\0';
	len -= 1;
	while (n > 0)
	{
		buf[len] = "0123456789"[n % 10];
		n /= 10;
		len--;
	}
	return (buf);
}
