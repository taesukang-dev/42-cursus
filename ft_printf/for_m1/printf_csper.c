#include "ft_printf.h"

int	printf_c(va_list *ap)
{
	int		len;
	char	arg;

	len = 0;
	arg = va_arg(*ap, int);
	len += write(1, &arg, 1);
	return (len);
}

int	printf_s(va_list *ap)
{
	int		len;
	char	*args;

	args = va_arg(*ap, char *);
	len = ft_strlen(args);
	write(1, args, len);
	return (len);
}

int	printf_per()
{
	write(1, "%", 1);
	return (1);
}