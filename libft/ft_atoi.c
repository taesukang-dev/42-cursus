/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkang <tkang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 21:17:59 by tkang             #+#    #+#             */
/*   Updated: 2022/03/15 20:29:38 by tkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t	i;
	long	result;
	long	op;

	i = 0;
	result = 0;
	op = 1;
	if (!str)
		return (0);
	while ((9 <= str[i] && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		op = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while ('0' <= str[i] && str[i] <= '9')
	{
		if (result > 2147483647 && op == 1)
			return (-1);
		if (result > 2147483648 && op == -1)
			return (0);
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result * op);
}