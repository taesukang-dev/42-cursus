#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	s1_len;
	char	*buf;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	i = 0;
	s1_len = ft_strlen(s1) - 1;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (s1[s1_len] && ft_strchr(set, s1[s1_len]))
		s1_len--;
	buf = (char *)calloc(s1_len - i + 2, sizeof(char));
	if (buf)
		ft_strlcpy(buf, (s1 + i), s1_len - i + 2);
	return (buf);
}
