/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_csper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkang <tkang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:46:46 by tkang             #+#    #+#             */
/*   Updated: 2022/04/14 12:47:09 by tkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_c(va_list ap)
{
	int		len;
	char	arg;

	len = 0;
	arg = va_arg(ap, size_t);
	len += write(1, &arg, 1);
	return (len);
}

int	printf_s(va_list ap)
{
	int		len;
	char	*args;

	args = va_arg(ap, char *);
	if (!args)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = ft_strlen(args);
	write(1, args, len);
	return (len);
}

int	printf_per(void)
{
	write(1, "%", 1);
	return (1);
}
