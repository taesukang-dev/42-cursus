#include "ft_printf.h"
#include <stdlib.h>
#include <stdio.h>

int printf_di(va_list *ap)
{
	char	*temp;
	int		len;
	int		arg;

	arg = va_arg(*ap, int);
	temp = ft_itoa(arg);
	len = ft_strlen(temp);
	write(1, temp, len);
	free(temp);
	return len;
}
