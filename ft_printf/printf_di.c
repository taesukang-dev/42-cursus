#include "ft_printf.h"

/*
char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	s1_len;
	size_t	i;

	s1_len = ft_strlen(s1);
	ptr = (char *)malloc(sizeof(char) * s1_len + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
*/

/*
static size_t	ft_check_len(int n)
{
	size_t	i;

	i = 0;
	if (n < 0)
		i = 1;
	if (n == -2147483648)
		return (10);
	else if (n < 0)
		n *= -1;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*buf;
	size_t		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (n == 0 || n == -0)
		return (ft_strdup("0"));
	len = ft_check_len(n);
	buf = malloc(sizeof(char) * (len + 1));
	if (!buf)
		return (NULL);
	if (n < 0)
	{
		buf[0] = '-';
		n *= -1;
	}
	buf[len] = '\0';
	len -= 1;
	while (n > 0)
	{
		buf[len] = "0123456789"[n % 10];
		n /= 10;
		len--;
	}
	return (buf);
}
*/

int printf_di(va_list ap)
{
	char	*temp;
	int		len;
	int		arg;

	arg = va_arg(ap, int);
	temp = ft_itoa(arg);
	len = ft_strlen(temp);
	write(1, temp, len);
	free(temp);
	return len;
}
