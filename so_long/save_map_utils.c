#include "so_long.h"

int ft_strlen_without_nl(char *str)
{
    size_t  i;

    i = 0;
    while(str[i] && str[i] != '\n')
        i++;
    return (i);
}

char	*ft_strdup_without_nl(char	*s1)
{
	char	*temp;
	size_t	s1_len;
	size_t	i;

	if (!s1)
		return (NULL);
	s1_len = ft_strlen_without_nl(s1);
	temp = (char *)malloc(sizeof(char) * (s1_len + 1));
	if (!temp)
		return (NULL);
	i = 0;
	while (s1[i] && s1[i] != '\n')
	{
		temp[i] = s1[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

void	ft_strlcpy_without_nl(char *dest, char *src, int read_len)
{
	int		i;
	size_t	src_len;

	src_len = ft_strlen_without_nl(src);
	i = 0;
	while (src[i] && src[i] != '\n' && i + 1 < read_len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char	*ft_strjoin_without_nl(char *s1, char *s2)
{
	char	*temp;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1)
		return (ft_strdup_without_nl(s2));
	s1_len = ft_strlen_without_nl(s1);
	s2_len = ft_strlen_without_nl(s2);
	temp = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!temp)
	{
		free(s1);
		return (NULL);
	}
	ft_strlcpy_without_nl(temp, s1, s1_len + 1);
	ft_strlcpy_without_nl(temp + s1_len, s2, s2_len + 1);
	free(s1);
	return (temp);
}
