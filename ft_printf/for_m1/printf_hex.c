#include "ft_printf.h"
#include <stdio.h>

int convert_hex_lower(unsigned long arg)
{
	int len;
	char c;

	len = 0;
	while(arg > 0)
	{
		c = "0123456789abcdef"[arg % 16];
		write(1, &c, 1);
		arg /= 16;
		len++;
	}
	return len;
}

int convert_hex_upper(unsigned long arg)
{
	int len;
	char c;

	len = 0;
	while(arg > 0)
	{
		c = "0123456789ABCDEF"[arg % 16];
		write(1, &c, 1);
		arg /= 16;
		len++;
	}
	return len;
}

int printf_addr(va_list *ap)
{
	unsigned long arg;
	int len;

	len = 0;
	arg = va_arg(*ap, unsigned long);
	len += write(1, "0x", 2);
	len += convert_hex_lower(arg);
	return len;
}

int printf_hex_lower(va_list *ap)
{
	unsigned long arg;
	int len;

	arg = va_arg(*ap, unsigned long);
	len = convert_hex_lower(arg);
	return len;
}

int printf_hex_upper(va_list *ap)
{
	unsigned long arg;
	int len;

	arg = va_arg(*ap, unsigned long);
	len = convert_hex_upper(arg);
	return len;
}
