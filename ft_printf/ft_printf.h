/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkang <tkang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:44:44 by tkang             #+#    #+#             */
/*   Updated: 2022/04/14 12:45:25 by tkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "./libft/libft.h"
#include <stdio.h>
#include <limits.h>
int	ft_printf(char const *s, ...);
int	printf_di(va_list ap);
int	printf_u(va_list ap);
int	printf_addr(va_list ap);
int	printf_hex_lower(va_list ap);
int	printf_hex_upper(va_list ap);
int	printf_c(va_list ap);
int	printf_s(va_list ap);
int	printf_per(void);

#endif
