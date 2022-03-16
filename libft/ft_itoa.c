#include "libft.h"

size_t	check_len(int n)
{
	size_t	i;

	i = 0;
	if (n == -2147483648)
		return (10);
	else if (n < 0)
		n *= -1;
	while (n >= 0)
	{
		if (n == 0)
			break;
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	//char		*buf;
	size_t		len;
	
	len = check_len(n);
	printf("%zu\n", len);
	/*
	buf = malloc(sizeof(char) * len + 2);
	buf[len + 1] = '\0';
	if (!buf)
		return (NULL);
	if (n < 0)
	{
		buf[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		buf[len] = "0123456789"[n % 10];
		n = n / 10;
		len--;
	}
	*/
	return NULL;
}


int main()
{
	char *temp;
	temp = ft_itoa(-21); 
	printf("%s", temp);
	return 0;
}
