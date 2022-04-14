#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#include <stdarg.h>
#include "./libft/libft.h"

int printf_di(va_list *ap);
int printf_u(va_list *ap);
int printf_addr(va_list *ap);
int printf_hex_lower(va_list *ap);
int printf_hex_upper(va_list *ap);
int	printf_c(va_list *ap);
int	printf_s(va_list *ap);
int	printf_per();

#endif
