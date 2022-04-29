/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_di.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkang <tkang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:47:20 by tkang             #+#    #+#             */
/*   Updated: 2022/04/14 12:47:43 by tkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_di(va_list ap)
{
	char	*temp;
	int		len;
	int		arg;

	arg = va_arg(ap, size_t);
	temp = ft_itoa(arg);
	len = ft_strlen(temp);
	write(1, temp, len);
	free(temp);
	return (len);
}
