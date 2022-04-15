/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkang <tkang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:48:23 by tkang             #+#    #+#             */
/*   Updated: 2022/04/14 12:49:53 by tkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_check_len(unsigned long n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

char	*convert_hex_lower(unsigned long long arg, int flag)
{
	int		len;
	char	*temp;

	if (arg == 0)
		return (ft_strdup("0"));
	if (flag == 8 && arg > 4294967295)
		len = 8;
	else
		len = hex_check_len(arg);
	temp = malloc(sizeof(char) * len + 1);
	temp[len] = '\0';
	len -= 1;
	while (len >= 0)
	{
		temp[len] = "0123456789abcdef"[arg % 16];
		arg /= 16;
		len--;
	}
	return (temp);
}

int	printf_addr(va_list ap)
{
	unsigned long long	arg;
	int					len;
	char				*temp;

	len = 0;
	arg = va_arg(ap, unsigned long long);
	len += write(1, "0x", 2);
	temp = convert_hex_lower(arg, 12);
	len += ft_strlen(temp);
	write(1, temp, len - 2);
	free(temp);
	return (len);
}

int	printf_hex_lower(va_list ap)
{
	unsigned int	arg;
	int				len;
	char			*temp;

	arg = va_arg(ap, unsigned int);
	temp = convert_hex_lower(arg, 8);
	len = ft_strlen(temp);
	write(1, temp, len);
	free(temp);
	return (len);
}

int	printf_hex_upper(va_list ap)
{
	unsigned int	arg;
	int				len;
	char			*temp;

	arg = va_arg(ap, unsigned int);
	temp = convert_hex_lower(arg, 8);
	len = 0;
	while (temp[len])
	{
		temp[len] = ft_toupper(temp[len]);
		len++;
	}
	len = ft_strlen(temp);
	write(1, temp, len);
	free(temp);
	return (len);
}
