#include "ft_printf.h"
#include <stdio.h>

int printf_c(va_list *ap)
{
	int len;
	char arg;

	len = 0;
	arg = va_arg(*ap, int);
	len += write(1, &arg, 1);
	return len;
}

int printf_s(va_list *ap)
{
	int		len;
	char	*args;

	args = va_arg(*ap, char *);
	len = ft_strlen(args);
	write(1, args, len);
	return len;
}

int printf_per()
{
	write(1, "%", 1);
	return 1;
}

int find_format(char const *s, va_list *ap)
{
	int	len;

	len = 0;
	if (*s == 'c')
		len += printf_c(ap);
	else if (*s == 's')
		len += printf_s(ap);
	else if (*s == 'd')
		len += printf_di(ap);
	else if (*s == '%')
		len += printf_per();
	else if(*s == 'u')
		len += printf_u(ap);
	else if(*s == 'p')
		len += printf_addr(ap);
	else if(*s == 'x')
		len += printf_hex_lower(ap);
	else if(*s == 'X')
		len += printf_hex_upper(ap);
	return len;
}

int map_str(char const *s, va_list *ap)
{
	int len;

	len = 0;
	while(*s)
	{
		if (*s == '%')
		{
			s++;
			len += find_format(s, ap);
			s++;
		}
		else
		{
			len += write(1, s, 1);
			s++;
		}
	}
	return len;
}

int ft_printf(char const *s, ...)
{
	va_list ap;
	int	len;

	va_start(ap, s);
	len = map_str(s, &ap);
	va_end(ap);
	return len;
}


int main()
{
	int test = 1;
	int temp = ft_printf("asdasdasd %c %d %% %u %p %X %x \n", 'c', 33522, -1, &test, 10, 10);
	printf("%d\n", temp);
	int tmp = ft_printf("asdasdasd %c %d %% %u %p %X %x \n", 'c', 33522, -1, &test, 10, 10);
	printf("%d\n", tmp);
	// ft_printf("%d %d", 2, 3);

	return 0;
}

